;----------------------------------------------------------------------------------------
; SendFax Masm32 Library
;
; Copyright 2007 Veria Kalantary
; veria.kalantary@gmail.com
; https://github.com/veriak
;
;----------------------------------------------------------------------------------------

.386
.MODEL FLAT, STDCALL
OPTION CASEMAP: NONE

include sendfax.Inc

StartFaxService PROTO :LPCTSTR, :DWORD 
SendFax PROTO :DWORD, :LPCSTR, :LPCTSTR

.const

.data

.data?
	hDll			DWORD	?	
	
.code

DLLEntryPoint PROC hInst: HINSTANCE, dwReason: DWORD, dwReserved: DWORD
    mov eax, hInst
    mov hDll, eax
    
    mov eax, TRUE
    ret
DLLEntryPoint ENDP

StartFaxService proc lpFaxServerName: LPCTSTR, pFaxHandle: DWORD
	invoke FaxConnectFaxServer, lpFaxServerName, pFaxHandle  
	.if eax == 0 		
		invoke ShowErrorMessage
		mov eax, 0
		ret
	.endif
	ret
StartFaxService endp

SendFax proc uses ebx edx FaxHandle: DWORD, lpFileName: LPCTSTR, lpFaxNumber: LPCTSTR
	LOCAL pJobParams: PFAX_JOB_PARAM
	LOCAL pCoverPageInfo: PFAX_COVERPAGE_INFO
	LOCAL ppJobParams: PPFAX_JOB_PARAM
	LOCAL ppCoverPageInfo: PPFAX_COVERPAGE_INFO
	LOCAL JobID: DWORD
	
	lea ebx, pJobParams
	mov ppJobParams, ebx
	lea ebx, pCoverPageInfo
	mov ppCoverPageInfo, ebx
	invoke FaxCompleteJobParams, ppJobParams, ppCoverPageInfo
	.if eax == 0
		invoke ShowErrorMessage 
	.endif	
	mov edx, pJobParams
	assume edx:ptr FAX_JOB_PARAM
	push lpFaxNumber 
	pop [edx].RecipientNumber
	mov [edx].ScheduleAction, 0
	mov [edx].DeliveryReportType, 0
	push lpFileName
	pop [edx].DocumentName
	mov JobID, 0	
	invoke FaxSendDocument, FaxHandle, lpFileName, pJobParams, 0, addr JobID
	.if eax == 0
		invoke ShowErrorMessage 
	.endif 	
	invoke FaxFreeBuffer, pJobParams
	invoke FaxFreeBuffer, pCoverPageInfo
	ret
SendFax endp

END DLLEntryPoint
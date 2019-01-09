include c:\masm32\include\windows.inc
include c:\masm32\include\kernel32.inc
include c:\masm32\include\user32.inc
include c:\masm32\include\masm32.inc
include c:\masm32\include\winfax.inc

includelib c:\masm32\lib\kernel32.lib
includelib c:\masm32\lib\user32.lib
includelib c:\masm32\lib\masm32.lib
includelib c:\masm32\lib\winfax.lib

include WinFaxService.inc 

ShowErrorMessage PROTO 
memset PROTO :DWORD, :BYTE, :DWORD
memcpy PROTO :DWORD, :DWORD, :DWORD

StrM macro data: vararg
	LOCAL buff
.data
	buff db data, 0
	
.code
 	exitm <addr buff> 	
endm

MAKELANGID MACRO p, s
  xor eax, eax
  mov eax, s
  shl eax, 10
  xor ebx, ebx
  mov ebx, p
  or  eax, ebx
ENDM

.data
	DLLName			db	"sendfax", 0
	
.data?
	ErrorMessage	db 	512	 dup (?)

.code
	
ShowErrorMessage PROC 
	invoke GetLastError	
	push eax
	MAKELANGID LANG_NEUTRAL, SUBLANG_DEFAULT
	pop ebx
	invoke FormatMessage, FORMAT_MESSAGE_FROM_SYSTEM, NULL, ebx, eax, OFFSET ErrorMessage, 512, NULL
	invoke MessageBox, NULL, OFFSET ErrorMessage, OFFSET DLLName, MB_OK
	ret
ShowErrorMessage ENDP

memset PROC pMem:DWORD, dwVal:byte, dwSize:DWORD
    mov edi, pMem
    mov al, dwVal
    mov ecx, dwSize
    cld
    rep stosb 
    ret

memset ENDP


memcpy PROC ptrSrc:DWORD, ptrDest:DWORD, dwSize:DWORD     
	 mov  ecx, dwSize 
     mov  esi, ptrSrc       
     mov  edi, ptrDest
     cld
     rep  movsb
     ret
memcpy ENDP

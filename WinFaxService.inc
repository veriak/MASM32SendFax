;----------------------------------------------------------------------------------------
; SendFax Masm32 Library
;
; Copyright 2007 Veria Kalantary
; veria.kalantary@gmail.com
; https://github.com/veriak
;
;----------------------------------------------------------------------------------------

FAX_TIME struct
  Hour					WORD		?
  Minute				WORD		?
FAX_TIME ends	

FAX_CONFIGURATION struct
  SizeOfStruct			DWORD		?
  Retries				DWORD		?
  RetryDelay			DWORD		?                               
  Branding				DWORD		?
  DirtyDays				DWORD		?
  UseDeviceTsid			DWORD		?
  ServerCp				DWORD		?
  PauseServerQueue		DWORD		?
  StartCheapTime		FAX_TIME	<>
  StopCheapTime			FAX_TIME	<>
  ArchiveOutgoingFaxes	DWORD		?                                
  ArchiveDirectory		LPCTSTR  	?
  InboundProfile		LPCSTR		?
FAX_CONFIGURATION ends

FAX_CONTEXT_INFO struct
  SizeOfStruct			DWORD		?
  hDC					HDC			?
  ServerName			db			MAX_COMPUTERNAME_LENGTH + 1 dup (?)                        
FAX_CONTEXT_INFO ends

FAX_COVERPAGE_INFO struct
  SizeOfStruct			DWORD		?  
  CoverPageName			LPCTSTR		?
  UseServerCoverPage	DWORD		?
  RecName				LPCTSTR		?
  RecFaxNumber			LPCTSTR		?
  RecCompany			LPCTSTR		?
  RecStreetAddress		LPCTSTR		?
  RecCity				LPCTSTR		?
  RecState				LPCTSTR		?
  RecZip				LPCTSTR		?
  RecCountry			LPCTSTR		?
  RecTitle				LPCTSTR		?
  RecDepartment			LPCTSTR		?
  RecOfficeLocation		LPCTSTR		?
  RecHomePhone			LPCTSTR		?
  RecOfficePhone		LPCTSTR		?
  SdrName				LPCTSTR		?
  SdrFaxNumber			LPCTSTR		?
  SdrCompany			LPCTSTR		?
  SdrAddress			LPCTSTR		?
  SdrTitle				LPCTSTR		?
  SdrDepartment			LPCTSTR		?
  SdrOfficeLocation		LPCTSTR		?
  SdrHomePhone			LPCTSTR		?
  SdrOfficePhone		LPCTSTR		?
  Note					LPCTSTR		?
  Subject				LPCTSTR		?
  TimeSent				SYSTEMTIME	<>
  PageCount				DWORD		?
FAX_COVERPAGE_INFO ends

FAX_DEVICE_STATUS struct
  SizeOfStruct 			DWORD		?
  CallerId				LPCTSTR		?
  Csid					LPCTSTR		?
  CurrentPage 			DWORD		?
  DeviceId				DWORD		?
  DeviceName			LPCTSTR		?
  DocumentName			LPCTSTR		?
  JobType				DWORD		?
  PhoneNumber			LPCTSTR		?
  RoutingString			LPCTSTR		?
  SenderName			LPCTSTR		?	
  RecipientName			LPCTSTR		?
  _Size					DWORD		?
  StartTime				FILETIME	<>
  Status				DWORD		?
  StatusString			LPCTSTR		?
  SubmittedTime			FILETIME	<>
  TotalPages			DWORD		?
  Tsid					LPCTSTR		?
  UserName				LPCTSTR		?
FAX_DEVICE_STATUS ends

FAX_EVENT struct
  SizeOfStruct			DWORD		?
  TimeStamp				FILETIME	<>
  DeviceId				DWORD		?
  EventId				DWORD		?
  JobId					DWORD		?
FAX_EVENT ends

FAX_GLOBAL_ROUTING_INFO struct
  SizeOfStruct			DWORD		?
  Priority				DWORD		?
  Guid					LPCTSTR		?                          
  FriendlyName			LPCTSTR		?
  FunctionName			LPCTSTR		?
  ExtensionImageName	LPCTSTR		?
  ExtensionFriendlyName LPCTSTR		?                          
FAX_GLOBAL_ROUTING_INFO ends

FAX_JOB_ENTRY struct
  SizeOfStruct			DWORD		?
  JobId					DWORD		?
  UserName				LPCTSTR		?
  JobType				DWORD		?
  QueueStatus			DWORD		?
  Status				DWORD		?
  _Size					DWORD		?
  PageCount				DWORD		?
  RecipientNumber		LPCTSTR		?
  RecipientName			LPCTSTR		?
  Tsid					LPCTSTR		?
  SenderName			LPCTSTR		?
  SenderCompany			LPCTSTR		?
  SenderDept			LPCTSTR		?
  BillingCode			LPCTSTR		?
  ScheduleAction		DWORD		?
  ScheduleTime			SYSTEMTIME	<>
  DeliveryReportType	DWORD		?
  DeliveryReportAddress LPCTSTR		?                              
  DocumentName			LPCTSTR		?
FAX_JOB_ENTRY ends

FAX_JOB_PARAM struct
  SizeOfStruct			DWORD		?
  RecipientNumber		LPCTSTR		?
  RecipientName			LPCTSTR		?
  Tsid					LPCTSTR		?
  SenderName			LPCTSTR		?
  SenderCompany			LPCTSTR		?
  SenderDept			LPCTSTR		?
  BillingCode			LPCTSTR		?
  ScheduleAction		DWORD		?
  ScheduleTime			SYSTEMTIME	<>
  DeliveryReportType	DWORD		?
  DeliveryReportAddress	LPCTSTR		?                                   
  DocumentName			LPCTSTR		?
  CallHandle			DWORD		?
  Reserved				db			3 dup (?)
FAX_JOB_PARAM ends

FAX_LOG_CATEGORY struct
  _Name					LPCTSTR		?
  Category				DWORD		?
  Level					DWORD		?
FAX_LOG_CATEGORY ends

FAX_PORT_INFO struct
  SizeOfStruct			DWORD		?	
  DeviceId				DWORD		?
  State					DWORD		?
  Flags					DWORD		?
  Rings					DWORD		?
  Priority				DWORD		?
  DeviceName			LPCTSTR		?
  Tsid					LPCTSTR		?                      
  Csid					LPCTSTR		?
FAX_PORT_INFO ends

FAX_PRINT_INFO struct
  SizeOfStruct			DWORD		?
  DocName				LPCTSTR		?
  RecipientName			LPCTSTR		?
  RecipientNumber		LPCTSTR		?
  SenderName			LPCTSTR		?
  SenderCompany			LPCTSTR		?
  SenderDept			LPCTSTR		?
  SenderBillingCode		LPCTSTR		?
  Reserved				LPCTSTR		?
  DrEmailAddress		LPCTSTR		?
  OutputFileName		LPCTSTR		?
FAX_PRINT_INFO ends

FAX_ROUTING_METHOD struct
  SizeOfStruct			DWORD		?
  DeviceId				DWORD		?
  Enabled				DWORD		?
  DeviceName			LPCTSTR		?
  Guid					LPCTSTR		?                          
  FriendlyName			LPCTSTR		?
  FunctionName			LPCTSTR		?
  ExtensionImageName	LPCTSTR		?
  ExtensionFriendlyName LPCTSTR		?
FAX_ROUTING_METHOD ends

PFAX_CONFIGURATION			typedef		ptr		FAX_CONFIGURATION
PFAX_CONTEXT_INFO 			typedef		ptr		FAX_CONTEXT_INFO
PFAX_COVERPAGE_INFO 		typedef		ptr		FAX_COVERPAGE_INFO
PFAX_DEVICE_STATUS			typedef		ptr		FAX_DEVICE_STATUS
PFAX_EVENT					typedef		ptr		FAX_EVENT
PFAX_GLOBAL_ROUTING_INFO	typedef		ptr		FAX_GLOBAL_ROUTING_INFO
PFAX_JOB_ENTRY				typedef		ptr		FAX_JOB_ENTRY
PFAX_JOB_PARAM				typedef		ptr		FAX_JOB_PARAM	
PFAX_LOG_CATEGORY			typedef		ptr		FAX_LOG_CATEGORY
PFAX_PORT_INFO				typedef		ptr		FAX_PORT_INFO
PFAX_PRINT_INFO				typedef		ptr		FAX_PRINT_INFO
PFAX_ROUTING_METHOD			typedef		ptr		FAX_ROUTING_METHOD
PFAX_TIME					typedef		ptr		FAX_TIME

PPFAX_CONFIGURATION			typedef		ptr		PFAX_CONFIGURATION
PPFAX_CONTEXT_INFO 			typedef		ptr		PFAX_CONTEXT_INFO
PPFAX_COVERPAGE_INFO 		typedef		ptr		PFAX_COVERPAGE_INFO
PPFAX_DEVICE_STATUS			typedef		ptr		PFAX_DEVICE_STATUS
PPFAX_EVENT					typedef		ptr		PFAX_EVENT
PPFAX_GLOBAL_ROUTING_INFO	typedef		ptr		PFAX_GLOBAL_ROUTING_INFO
PPFAX_JOB_ENTRY				typedef		ptr		PFAX_JOB_ENTRY
PPFAX_JOB_PARAM				typedef		ptr		PFAX_JOB_PARAM	
PPFAX_LOG_CATEGORY			typedef		ptr		PFAX_LOG_CATEGORY
PPFAX_PORT_INFO				typedef		ptr		PFAX_PORT_INFO
PPFAX_PRINT_INFO			typedef		ptr		PFAX_PRINT_INFO
PPFAX_ROUTING_METHOD		typedef		ptr		PFAX_ROUTING_METHOD
PPFAX_TIME					typedef		ptr		PFAX_TIME

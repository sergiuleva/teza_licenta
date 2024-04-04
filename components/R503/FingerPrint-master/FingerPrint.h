#ifndef	_FINGERPRINT_H_
#define	_FINGERPRINT_H_

#include "cmsis_os.h"
#include <stdint.h>
#include <stdbool.h>
//#########################################################################################################################


typedef struct
{
	uint8_t		TxBuffer[32];
	uint8_t		RxBuffer[32];
	uint8_t		AnswerBuffer[32];
	uint8_t		GotAnswer;
	uint8_t		RxIndex;	
	uint8_t		RxTmp;	
	uint32_t	RxLastTime;
	uint8_t		TouchIndex;
	int16_t		LastDetectedLocation;
	int16_t		Template;
	
	uint8_t		Lock;
	
}FingerPrint_t;

//#########################################################################################################################
void			FingerPrint_RxCallback(void);
void			FingerPrint_Init(osPriority Priority);

bool			Fingerprint_VerifyPassword(uint32_t pass);
bool			Fingerprint_SaveNewFinger(uint16_t	Location,uint8_t	WaitForFingerInSecond);
int16_t		FingerPrint_Scan(void);
int16_t		FingerPrint_ReadTemplateNumber(void);
bool			FingerPrint_DeleteAll(void);
bool			FingerPrint_DeleteByLocation(uint16_t	Location);
int16_t		FingerPrint_DeleteByFinger(uint8_t	TimoutInSecond);


//				in FingerPrintUser.c	Run Automaticaly after detect Saved Finger
void			FingerPrint_Detect(uint16_t	Location);
//#########################################################################################################################







#endif

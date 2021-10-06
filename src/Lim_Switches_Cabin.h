#ifndef LIM_SWITCHES_CABIN_H
#define LIM_SWITCHES_CABIN_H
#include "stdbool.h"

typedef bool(*CABIN_STATE)( void );

bool Cabin_Switch_Max(void);
bool Cabin_Switch_FloorHight(void);
bool Cabin_Switch_Floor(void);
bool Cabin_Switch_FloorLow(void);
bool Cabin_Switch_Min(void);

bool Door_Switch_Opened(void);
bool Door_Switch_Closed(void);

#endif // SWITCHES_CABIN_H
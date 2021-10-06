#ifndef KEYS_H
#define KEYS_H

void Lift_Init(void);

void Cabin_Start(void);
void Cabin_Stop_Floor(void);
void Cabin_Stop_Edge(void);

void Move_ToDest(int);

void ReInit_OnMax(void);
void Move_UP(void);
void ReInit_OnMin(void);
void Move_Down(void);

void KIC_Floor1(void);
void KIC_Floor2(void);
void KIC_Floor3(void);
void KIC_Stop(void);
void KOC_Floor1(void);
void KOC_Floor2(void);
void KOC_Floor3(void);

void Check_Sensor(CABIN_STATE sensor);

#endif // KEYS_H
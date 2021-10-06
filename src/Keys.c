#include "Lim_Switches_Cabin.h"
#include "Cabin_Brakes.h"
#include "Keys.h"
#include "Motor.h"
#include "Door_Actuators.h"
#include "string.h"
#include "stdbool.h"

static int Num_floor = 0;
static bool Stop_Flag = false;
static bool Edge_Flag = false;

const int Floor1 = 1;
const int Floor2 = 2;
const int Floor3 = 3;

// Response on push of Keys In Cabin - KIC
void KIC_Floor1()
{
    Move_ToDest(Floor1);
}

void KIC_Floor2()
{
    Move_ToDest(Floor2);
}

void KIC_Floor3()
{
    Move_ToDest(Floor3);
}

void KIC_Stop(){ // Key STOP in cabin

    Stop_Flag = true;
}
//------------------------------------------

//Response on push of Keys Out Cabin - KOC
void KOC_Floor1()
{
    Move_ToDest(Floor1);
}

void KOC_Floor2()
{
    Move_ToDest(Floor2);
}

void KOC_Floor3()
{
    Move_ToDest(Floor3);
}

//------------------------------------------

void Cabin_Stop_Floor(){
    Speed_Off();
    Brakes_On();
    Actuator_Opening();    
    Check_Sensor(&Door_Switch_Opened);     
    Actuator_Off();
}

void Cabin_Stop_Edge(){
    Speed_Off();
    Brakes_On();
}

void Cabin_Start() { // Prepare to start cabin moving
    Actuator_Closing();
    Check_Sensor(&Door_Switch_Closed);            

    Actuator_Off();
    Brakes_Off();
}

void Check_Sensor(CABIN_STATE sensor)
{
    while( !sensor )
    {
        if ( Cabin_Switch_Max || Cabin_Switch_Min ) 
        {
            Edge_Flag = true;
        }
    }
}

void Lift_Init (void) 
{
    Speed_Off();
    Brakes_On();

    Cabin_Start();
    Low_Speed_Down();
    Check_Sensor(&Cabin_Switch_Min);
    Cabin_Stop_Edge();
    Low_Speed_Up();
    Check_Sensor(&Cabin_Switch_Floor);
    Cabin_Stop_Floor();

    Num_floor = 1;
}

// -----------------------------------------
void Move_ToDest(int Dest_Floor)
{
    // if "Dest_Floor == Num_floor" then doing nothing 
    
    if (Dest_Floor != Num_floor){
        Cabin_Start();
    }                                       
    
    while( Dest_Floor != Num_floor )
    {
        if ( Dest_Floor < Num_floor )
        {
        // Moving down
            Move_Down();

            if (  Num_floor - Dest_Floor == 0 || Stop_Flag == true ){
                Cabin_Stop_Floor();  
                Stop_Flag = false;  
                break;
            }                 
        }  
        else if ( Dest_Floor > Num_floor )
        {
            // Moving up
            Move_UP();

            if (  Dest_Floor - Num_floor == 0 || Stop_Flag == true ){
                Cabin_Stop_Floor();
                Stop_Flag = false;
                break;
            }       
        }   
    }                                           
}

// -----------------------------------------
// Moving Up
void ReInit_OnMax(){
    Cabin_Stop_Edge();
    Low_Speed_Down();
    Check_Sensor(&Cabin_Switch_Floor);

    Num_floor = Floor3;

    Cabin_Stop_Floor();
}

void Move_UP(){

    Low_Speed_Up();
    Check_Sensor(&Cabin_Switch_FloorHight); 

    High_Speed_Up(); 
    Check_Sensor(&Cabin_Switch_FloorLow);
    
    if (Edge_Flag == true){
        ReInit_OnMax();
    } else 
    {
        Low_Speed_Up(); 
        Check_Sensor(&Cabin_Switch_Floor);

        Num_floor++; 
    } 
}

// Moving Down
void ReInit_OnMin(){
    Cabin_Stop_Edge();
    Low_Speed_Up();
    Check_Sensor(&Cabin_Switch_Floor);

    Num_floor = Floor1;

    Cabin_Stop_Floor();
}

void Move_Down(){

    Low_Speed_Down();
    Check_Sensor(&Cabin_Switch_FloorLow); 

    High_Speed_Down();
    Check_Sensor(&Cabin_Switch_FloorHight);
    
    if (Edge_Flag == true){
        ReInit_OnMin();
    } else 
    {
        Low_Speed_Down (); 
        Check_Sensor(&Cabin_Switch_Floor);
    
        Num_floor--;
    }
}

#include "unity.h"
#include "Lim_Switches_Cabin.h"
#include "Cabin_Brakes.h"
#include "Keys.h"
#include "Motor.h"
#include "Door_Actuators.h"

#include "mock_Lim_Switches_Cabin.h"
#include "mock_Cabin_Brakes.h"
#include "mock_Door_Actuators.h"
#include "mock_Motor.h"

void setUp(void) {

}

void tearDown(void) {
	// clean stuff up here
}

/**
 * Given LIFT is not initialized
 * When LIFT initialization occurs
 * Then we explicitly stop cabin to ensure that cabin is not moving
 * And Start Cabin
 * And move slowly down to min switch and stop
 * And move slowly Up to the nearest floor and save position to Floor 1
 */

void test_Initialization(void) 
{
    Speed_Off_Expect();
    Brakes_On_Expect();

    // Cabin_Start()
    Actuator_Closing_Expect();            
    Actuator_Off_Expect();
    Brakes_Off_Expect();
    // }

    Low_Speed_Down_Expect();

    // Cabin_Stop_Edge(){
    Speed_Off_Expect();
    Brakes_On_Expect();
    // }
    
    Low_Speed_Up_Expect();
    
    // Cabin_Stop_Floor (){
    Speed_Off_Expect();
    Brakes_On_Expect();   
    Actuator_Opening_Expect();    
    Actuator_Off_Expect();
    // }

    Lift_Init();
}

/**
 * Given LIFT is on the floor 1 
 * When Floor2 Key in cabin pushed 
 * Then we need to start cabin    
 * And move 1 floor up 
 * And Stop cabin and open the door
 */
void test_Move_FL1_FL2(){  // FL - Floor 1,2

    // Cabin_Start()
    Actuator_Closing_Expect();            
    Actuator_Off_Expect();
    Brakes_Off_Expect();
    // }

    // Move_UP() {

    Low_Speed_Up_Expect ();
    High_Speed_Up_Expect (); 
    Low_Speed_Up_Expect (); 

    // }
 
    // Cabin_Stop_Floor (){
    Speed_Off_Expect();
    Brakes_On_Expect();   
    Actuator_Opening_Expect();    
    Actuator_Off_Expect();
    // }

    KIC_Floor2();
}

/**
 * Given LIFT is on the floor 2 
 * When Floor3 Key in cabin pushed 
 * Then we need to start cabin    
 * And move 1 floor up 
 * And Stop cabin and open the door
 */
void test_Move_FL2_FL3(){  // FL - Floor 2,3

    // Cabin_Start()
    Actuator_Closing_Expect();            
    Actuator_Off_Expect();
    Brakes_Off_Expect();
    // }

    // Move_UP() {
    Low_Speed_Up_Expect ();
    High_Speed_Up_Expect (); 
    Low_Speed_Up_Expect (); 
    // }
 
    // Cabin_Stop_Floor (){
    Speed_Off_Expect();
    Brakes_On_Expect();   
    Actuator_Opening_Expect();    
    Actuator_Off_Expect();
    // }

    KIC_Floor3();
}

/**
 * Given LIFT is on the floor 3 
 * When Floor1 Key in cabin pushed 
 * Then we need to start cabin    
 * And move 1 floor down two times 
 * And Stop cabin and open the door
 */
void test_Move_FL3_FL1(){  // FL - Floor 3,1

    // Cabin_Start()
    Actuator_Closing_Expect();            
    Actuator_Off_Expect();
    Brakes_Off_Expect();
    // }

    // Move_Down() {
    Low_Speed_Down_Expect ();
    High_Speed_Down_Expect (); 
    Low_Speed_Down_Expect (); 
    // }
    // Move_Down() {
    Low_Speed_Down_Expect ();
    High_Speed_Down_Expect (); 
    Low_Speed_Down_Expect (); 

    // }
 
    // Cabin_Stop_Floor (){
    Speed_Off_Expect();
    Brakes_On_Expect();   
    Actuator_Opening_Expect();    
    Actuator_Off_Expect();
    // }

    KIC_Floor1();
}

/**
 * Given LIFT is on the floor 1 
 * When Floor3 Key out of cabin pushed 
 * Then we need to start cabin    
 * And move 1 floor up two times  
 * And Stop cabin and open the door
 */
void test_Move_FL1_FL3(){  // FL - Floor 1,3 KOC

    // Cabin_Start()
    Actuator_Closing_Expect();            
    Actuator_Off_Expect();
    Brakes_Off_Expect();
    // }

    // Move_UP() {
    Low_Speed_Up_Expect ();
    High_Speed_Up_Expect (); 
    Low_Speed_Up_Expect (); 
    // }
    // Move_UP() {
    Low_Speed_Up_Expect ();
    High_Speed_Up_Expect (); 
    Low_Speed_Up_Expect (); 
    // }
 
    // Cabin_Stop_Floor (){
    Speed_Off_Expect();
    Brakes_On_Expect();   
    Actuator_Opening_Expect();    
    Actuator_Off_Expect();
    // }

    KOC_Floor3();
}

/**
 * Given LIFT is on the floor 3 
 * When Floor2 Key out of cabin pushed 
 * Then we need to start cabin    
 * And move 1 floor down  
 * And Stop cabin and open the door
 */
void test_Move_FL3_FL2(){  // FL - Floor 3,2 KOC

    // Cabin_Start()
    Actuator_Closing_Expect();            
    Actuator_Off_Expect();
    Brakes_Off_Expect();
    // }

    // Move_UP() {
    Low_Speed_Down_Expect ();
    High_Speed_Down_Expect (); 
    Low_Speed_Down_Expect (); 
    // }
 
    // Cabin_Stop_Floor (){
    Speed_Off_Expect();
    Brakes_On_Expect();   
    Actuator_Opening_Expect();    
    Actuator_Off_Expect();
    // }

    KOC_Floor2();
}

/**
 * Given LIFT is on the floor 2 
 * When Floor1 Key out of cabin pushed 
 * Then we need to start cabin    
 * And move 1 floor down  
 * And Stop cabin and open the door
 */
void test_Move_FL2_FL1(){  // FL - Floor 2,1 KOC

    // Cabin_Start()
    Actuator_Closing_Expect();            
    Actuator_Off_Expect();
    Brakes_Off_Expect();
    // }

    // Move_UP() {
    Low_Speed_Down_Expect ();
    High_Speed_Down_Expect (); 
    Low_Speed_Down_Expect (); 
    // }
 
    // Cabin_Stop_Floor (){
    Speed_Off_Expect();
    Brakes_On_Expect();   
    Actuator_Opening_Expect();    
    Actuator_Off_Expect();
    // }

    KOC_Floor1();
}

/**
 * Given LIFT activated Max Switch while moving
 * When Max switched activated
 * Then we need to stop immediately whithout opening the door
 * And move slowly down to the nearest floor
 * And Stop cabin and open the door
 */
void test_ReInit_OnMax(){
    // Cabin_Stop_Edge(){
    Speed_Off_Expect();
    Brakes_On_Expect();
    // }

    Low_Speed_Down_Expect();

    // Cabin_Stop_Floor (){
    Speed_Off_Expect();
    Brakes_On_Expect();   
    Actuator_Opening_Expect();    
    Actuator_Off_Expect();
    // }
    ReInit_OnMax();
}

/**
 * Given LIFT activated Min Switch while moving
 * When Min switched activated
 * Then we need to stop immediately whithout opening the door
 * And move slowly up to the nearest floor
 * And Stop cabin and open the door
 */
void test_ReInit_OnMin(){
    // Cabin_Stop_Edge(){
    Speed_Off_Expect();
    Brakes_On_Expect();
    // }

    Low_Speed_Up_Expect();

    // Cabin_Stop_Floor (){
    Speed_Off_Expect();
    Brakes_On_Expect();   
    Actuator_Opening_Expect();    
    Actuator_Off_Expect();
    // }
    ReInit_OnMin();
}
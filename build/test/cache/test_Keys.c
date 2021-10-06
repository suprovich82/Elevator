#include "build/test/mocks/mock_Motor.h"
#include "build/test/mocks/mock_Door_Actuators.h"
#include "build/test/mocks/mock_Cabin_Brakes.h"
#include "build/test/mocks/mock_Lim_Switches_Cabin.h"
#include "src/Keys.h"
#include "c:/Ruby30-x64/lib/ruby/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"




void setUp(void) {



}



void tearDown(void) {



}

void test_Initialization(void)

{

    Speed_Off_CMockExpect(32);

    Brakes_On_CMockExpect(33);





    Actuator_Closing_CMockExpect(36);

    Actuator_Off_CMockExpect(37);

    Brakes_Off_CMockExpect(38);





    Low_Speed_Down_CMockExpect(41);





    Speed_Off_CMockExpect(44);

    Brakes_On_CMockExpect(45);





    Low_Speed_Up_CMockExpect(48);





    Speed_Off_CMockExpect(51);

    Brakes_On_CMockExpect(52);

    Actuator_Opening_CMockExpect(53);

    Actuator_Off_CMockExpect(54);





    Lift_Init();

}

void test_Move_FL1_FL2(){





    Actuator_Closing_CMockExpect(70);

    Actuator_Off_CMockExpect(71);

    Brakes_Off_CMockExpect(72);









    Low_Speed_Up_CMockExpect(77);

    High_Speed_Up_CMockExpect(78);

    Low_Speed_Up_CMockExpect(79);









    Speed_Off_CMockExpect(84);

    Brakes_On_CMockExpect(85);

    Actuator_Opening_CMockExpect(86);

    Actuator_Off_CMockExpect(87);





    KIC_Floor2();

}

void test_Move_FL2_FL3(){





    Actuator_Closing_CMockExpect(103);

    Actuator_Off_CMockExpect(104);

    Brakes_Off_CMockExpect(105);







    Low_Speed_Up_CMockExpect(109);

    High_Speed_Up_CMockExpect(110);

    Low_Speed_Up_CMockExpect(111);







    Speed_Off_CMockExpect(115);

    Brakes_On_CMockExpect(116);

    Actuator_Opening_CMockExpect(117);

    Actuator_Off_CMockExpect(118);





    KIC_Floor3();

}

void test_Move_FL3_FL1(){





    Actuator_Closing_CMockExpect(134);

    Actuator_Off_CMockExpect(135);

    Brakes_Off_CMockExpect(136);







    Low_Speed_Down_CMockExpect(140);

    High_Speed_Down_CMockExpect(141);

    Low_Speed_Down_CMockExpect(142);





    Low_Speed_Down_CMockExpect(145);

    High_Speed_Down_CMockExpect(146);

    Low_Speed_Down_CMockExpect(147);









    Speed_Off_CMockExpect(152);

    Brakes_On_CMockExpect(153);

    Actuator_Opening_CMockExpect(154);

    Actuator_Off_CMockExpect(155);





    KIC_Floor1();

}

void test_Move_FL1_FL3(){





    Actuator_Closing_CMockExpect(171);

    Actuator_Off_CMockExpect(172);

    Brakes_Off_CMockExpect(173);







    Low_Speed_Up_CMockExpect(177);

    High_Speed_Up_CMockExpect(178);

    Low_Speed_Up_CMockExpect(179);





    Low_Speed_Up_CMockExpect(182);

    High_Speed_Up_CMockExpect(183);

    Low_Speed_Up_CMockExpect(184);







    Speed_Off_CMockExpect(188);

    Brakes_On_CMockExpect(189);

    Actuator_Opening_CMockExpect(190);

    Actuator_Off_CMockExpect(191);





    KOC_Floor3();

}

void test_Move_FL3_FL2(){





    Actuator_Closing_CMockExpect(207);

    Actuator_Off_CMockExpect(208);

    Brakes_Off_CMockExpect(209);







    Low_Speed_Down_CMockExpect(213);

    High_Speed_Down_CMockExpect(214);

    Low_Speed_Down_CMockExpect(215);







    Speed_Off_CMockExpect(219);

    Brakes_On_CMockExpect(220);

    Actuator_Opening_CMockExpect(221);

    Actuator_Off_CMockExpect(222);





    KOC_Floor2();

}

void test_Move_FL2_FL1(){





    Actuator_Closing_CMockExpect(238);

    Actuator_Off_CMockExpect(239);

    Brakes_Off_CMockExpect(240);







    Low_Speed_Down_CMockExpect(244);

    High_Speed_Down_CMockExpect(245);

    Low_Speed_Down_CMockExpect(246);







    Speed_Off_CMockExpect(250);

    Brakes_On_CMockExpect(251);

    Actuator_Opening_CMockExpect(252);

    Actuator_Off_CMockExpect(253);





    KOC_Floor1();

}

void test_ReInit_OnMax(){



    Speed_Off_CMockExpect(268);

    Brakes_On_CMockExpect(269);





    Low_Speed_Down_CMockExpect(272);





    Speed_Off_CMockExpect(275);

    Brakes_On_CMockExpect(276);

    Actuator_Opening_CMockExpect(277);

    Actuator_Off_CMockExpect(278);



    ReInit_OnMax();

}

void test_ReInit_OnMin(){



    Speed_Off_CMockExpect(292);

    Brakes_On_CMockExpect(293);





    Low_Speed_Up_CMockExpect(296);





    Speed_Off_CMockExpect(299);

    Brakes_On_CMockExpect(300);

    Actuator_Opening_CMockExpect(301);

    Actuator_Off_CMockExpect(302);



    ReInit_OnMin();

}

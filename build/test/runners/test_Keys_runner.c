/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"
#include "cmock.h"
#include "mock_Lim_Switches_Cabin.h"
#include "mock_Cabin_Brakes.h"
#include "mock_Door_Actuators.h"
#include "mock_Motor.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_Initialization(void);
extern void test_Move_FL1_FL2();
extern void test_Move_FL2_FL3();
extern void test_Move_FL3_FL1();
extern void test_Move_FL1_FL3();
extern void test_Move_FL3_FL2();
extern void test_Move_FL2_FL1();
extern void test_ReInit_OnMax();
extern void test_ReInit_OnMin();


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
  mock_Lim_Switches_Cabin_Init();
  mock_Cabin_Brakes_Init();
  mock_Door_Actuators_Init();
  mock_Motor_Init();
}
static void CMock_Verify(void)
{
  mock_Lim_Switches_Cabin_Verify();
  mock_Cabin_Brakes_Verify();
  mock_Door_Actuators_Verify();
  mock_Motor_Verify();
}
static void CMock_Destroy(void)
{
  mock_Lim_Switches_Cabin_Destroy();
  mock_Cabin_Brakes_Destroy();
  mock_Door_Actuators_Destroy();
  mock_Motor_Destroy();
}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}

/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, UNITY_LINE_TYPE line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {
        setUp();
        func();
    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_Keys.c");
  run_test(test_Initialization, "test_Initialization", 30);
  run_test(test_Move_FL1_FL2, "test_Move_FL1_FL2", 67);
  run_test(test_Move_FL2_FL3, "test_Move_FL2_FL3", 100);
  run_test(test_Move_FL3_FL1, "test_Move_FL3_FL1", 131);
  run_test(test_Move_FL1_FL3, "test_Move_FL1_FL3", 168);
  run_test(test_Move_FL3_FL2, "test_Move_FL3_FL2", 204);
  run_test(test_Move_FL2_FL1, "test_Move_FL2_FL1", 235);
  run_test(test_ReInit_OnMax, "test_ReInit_OnMax", 266);
  run_test(test_ReInit_OnMin, "test_ReInit_OnMin", 290);

  CMock_Guts_MemFreeFinal();
  return UnityEnd();
}
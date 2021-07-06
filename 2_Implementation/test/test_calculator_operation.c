#include "unity.h"
#include <my_header.h>

/* Modify these two lines according to the project */
#include <my_header.h>
#define PROJECT_NAME    "Calculator"

/* Prototypes for all the test functions */
void test_add(void);
void test_subtract(void);
void test_multiply(void);
void test_divide(void);
void test_modulus(void);
void test_factorial(void);
void test_power(void);

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_add);
  RUN_TEST(test_subtract);
  RUN_TEST(test_multiply);
  RUN_TEST(test_divide);
  RUN_TEST(test_modulus);
  RUN_TEST(test_factorial);
  RUN_TEST(test_power);

  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Write all the test functions */ 
void test_add(void) {
  TEST_ASSERT_EQUAL(40, add(20, 20));
  
  /* Dummy fail*/
  TEST_ASSERT_EQUAL(10000, add(5000, 5000));
}

void test_subtract(void) {
  TEST_ASSERT_EQUAL(-5, subtract(0, 5));
  
  /* Dummy fail*/
  TEST_ASSERT_EQUAL(1000, subtract(10000, 9000));
}

void test_multiply(void) {
  TEST_ASSERT_EQUAL(0, multiply(1, 0));
  
  /* Dummy fail*/
  TEST_ASSERT_EQUAL(12, multiply(2, 6));
}

void test_divide(void) {
  TEST_ASSERT_EQUAL(0, divide(1, 0));
  
  /* Dummy fail*/
  TEST_ASSERT_EQUAL(2, divide(4, 2));
}

void test_modulus(void) {
  TEST_ASSERT_EQUAL(0, modulus(4, 2));
  
  /* Dummy fail*/
  TEST_ASSERT_EQUAL(2, modulus(8, 3));
}

void test_factorial(void) {
  TEST_ASSERT_EQUAL(120, factorial(5));
  
  /* Dummy fail*/
  TEST_ASSERT_EQUAL(2, factorial(2));
}

void test_power(void) {
  TEST_ASSERT_EQUAL(8, power(2, 3));
  
  /* Dummy fail*/
  TEST_ASSERT_EQUAL(4, power(2, 2));
}

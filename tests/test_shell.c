#include "config.h"
#include "shell.h"
#include "unity.h"
#include <stdlib.h>
#include <string.h>

void setUp(void) {
  // set up
}

void tearDown(void) {
  // cleanup
}

void test_shell_split_line(void) {
  char input[] = "ls -l /home";
  char **tokens = shell_split_line(input);

  TEST_ASSERT_NOT_NULL(tokens);
  TEST_ASSERT_EQUAL_STRING("ls", tokens[0]);
  TEST_ASSERT_EQUAL_STRING("-l", tokens[1]);
  TEST_ASSERT_EQUAL_STRING("/home", tokens[2]);
  TEST_ASSERT_NULL(tokens[3]);
  free(tokens);
}

void test_shell_split_line_empty(void) {
  char input[] = "";
  char **tokens = shell_split_line(input);

  TEST_ASSERT_NOT_NULL(tokens);
  TEST_ASSERT_NULL(tokens[0]);

  free(tokens);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_shell_split_line);
  RUN_TEST(test_shell_split_line_empty);
  return UNITY_END();
}

#include "builtins/builtin.h"
#include "builtins/exit.h"
#include "unity.h"
#include <string.h>

void setUp(void) {
  // set up
}

void tearDown(void) {
  // cleanup
}

void test_shell_num_builtins(void) {
  TEST_ASSERT_EQUAL(2, shell_num_builtins());
}

void test_builtin_commands_exist(void) {
  TEST_ASSERT_EQUAL_STRING("cd", builtin_str[0]);
  TEST_ASSERT_EQUAL_STRING("exit", builtin_str[1]);
}

void test_shell_exit(void) {
  char *args[] = {"exit", NULL};
  TEST_ASSERT_EQUAL(0, exit_shell(args));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_shell_num_builtins);
  RUN_TEST(test_builtin_commands_exist);
  RUN_TEST(test_shell_exit);
  return UNITY_END();
}

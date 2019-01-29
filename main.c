#include <stdio.h>
#include "calc.h"

/*
 * Story 1: When you start the program you see the message: Calculator
 * (enter 'x' to exit).
 *
 */

int main(int argc, char *argv[]) {
  /* Put code here */
printf("Calculator /n(enter 'x' to exit)");
  while (execute_operator(get_operator()));
}

#include "utils.h"
#include <stdio.h>

unsigned dec2bin(unsigned num) {
  if (num == 0) {
    return 0;
  } else if (num == 1) {
    return 1;
  }
  return (num % 2) + 10 * dec2bin(num / 2);
}

unsigned bin2dec(unsigned num) {
  if (num == 0) {
    return 0;
  } else if (num == 1) {
    return 1;
  }
  return (num % 10) + 2 * dec2bin(num / 10);
}

void formula_relation(int a, int b) {
  printf("%u -> %u\n", dec2bin((unsigned)a), dec2bin((unsigned)b));
}

#include "utils.h"
#include <stdio.h>

#define bin2dec_p(...) _bin2dec_p(PP_NARG(__VA_ARGS__), __VA_ARGS__)
#define dec2bin_p(...) _dec2bin_p(PP_NARG(__VA_ARGS__), __VA_ARGS__)

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
  return (num % 10) + 2 * bin2dec(num / 10);
}

void _dec2bin_p(size_t argc, ...) {
  va_list ap;
  va_start(ap, argc);
  for (int i = 0; i < argc; i++) {
    printf("%08u\n", dec2bin(va_arg(ap, unsigned)));
  }
  va_end(ap);
}

void _bin2dec_p(size_t argc, ...) {
  va_list ap;
  va_start(ap, argc);
  for (int i = 0; i < argc; i++) {
    printf("%08u\n", bin2dec(va_arg(ap, unsigned)));
  }
  va_end(ap);
}

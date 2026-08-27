#include "joltage_calc.h"
#include <ctype.h>
#include <string.h>

int get_joltage_from_gate(char *gate) {

  size_t len = strlen(gate);

  for (size_t i = 0; i < strlen(gate); ++i) {
    unsigned char char_num = gate[i];
    if (!isdigit(char_num)) {
      int digit = char_num - '0';
    }
  }

  return 1;
}

#include "bank_processor.h"
#include "joltage_calc.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uintmax_t process_banks_from_file(FILE *file) {
  char *line = NULL;
  size_t capacity = 0;
  uintmax_t result = 0;
  ssize_t line_length;

  while ((line_length = getline(&line, &capacity, file)) != -1) {
    if (line[strspn(line, " \t\r\n")] == '\0')
      continue;
    while (line_length > 0 &&
           (line[line_length - 1] == '\n' || line[line_length - 1] == '\r')) {
      line[--line_length] = '\0';
    }
    result += get_joltage_from_gate(line);
  }

  if (line != NULL) {
    free(line);
  }

  return result;
}

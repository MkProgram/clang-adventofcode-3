#include "bank_processor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int process_banks_from_file(FILE *file) {
  char *line = NULL;
  size_t len = 0;

  while (getline(&line, &len, file) != -1) {
    if (line[strspn(line, " \t\r\n")] == '\0')
      continue;

    printf("The line is: %s\n", line);
  }

  if (line != NULL) {
    free(line);
  }

  return 1;
}

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int int_from_string(const char *);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return EXIT_SUCCESS;
  }

  return int_from_string(argv[1]);
}

int int_from_string(const char *string) {
  if (!string)
    return 0;

  size_t string_size = strlen(string);
  char number = 0;
  char current;

  for (int i = 0; i < string_size; i++) {
    current = string[i];

    if (current == '-' && i == 0)
      continue;

    if (current < 48 || current > 57)
      return 0;

    number += (current - 48) * (pow(10, (string_size - i - 1)));
  }

  if (string[0] == '-')
    number = -number;

  // printf("Number is: %d\n", number);

  return number;
}

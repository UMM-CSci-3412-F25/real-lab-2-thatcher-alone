#include <stdlib.h>
#include <string.h>

#include "disemvowel.h"

void addChar(char *str, char c, int *length) {
  str[(*length)++] = c; // Add character at the end
  str[*length] = '\0'; // Replace null pointer
}

char *disemvowel(char *str) {
  char *tmp = (char*)malloc(strlen(str) + 1);  // Temporary buffer (I use malloc because the test file checks long strings, and this ensure we won't have issues with that)
  int length = 0; // Track length of tmp
  tmp[0] = '\0'; // Initialize as empty string

  for(int i = 0; str[i] != '\0'; i++) { // Go until null pointer
    if (!(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
       str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')) { // Check input for vowels, one index at a time
      // If char is NOT a vowel, then:
      addChar(tmp, str[i], &length); // Add char to tmp
    }
  }

  char *result = (char*)malloc(length + 1); // Allocate space for result
  for(int j = 0; tmp[j] != '\0'; j++){ // Copy tmp to result
    result[j] = tmp[j];
  }
  result[length] = '\0'; // Add null pointer
  
  free(tmp); // Free tmp
  tmp = NULL;

  return result;
}
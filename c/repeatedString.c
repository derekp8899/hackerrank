#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

// Complete the repeatedString function below.
long repeatedString(char* s, long n) {
  long j =0;
  int i =0;
  long c = 0;
  for(;;){
    if(s[i]=='\0')
      break;
    if(s[i]=='a')
      c++;
    i++;
  }
  printf("init count: %ld\n",c);
  printf("n is : %ld\n",n);
  j = n/i;
  c = (j*c);
  j = n%i;
  for(j-1;j>=0;j--)
    if(s[j]=='a')
      c++;

  return c;  
}

int main()
{
  FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

  char* s = readline();

  char* n_endptr;
  char* n_str = readline();
  long n = strtol(n_str, &n_endptr, 10);

  if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

  long result = repeatedString(s, n);

  fprintf(fptr, "%ld\n", result);

  fclose(fptr);

  return 0;
}

char* readline() {
  size_t alloc_length = 1024;
  size_t data_length = 0;
  char* data = malloc(alloc_length);

  while (true) {
    char* cursor = data + data_length;
    char* line = fgets(cursor, alloc_length - data_length, stdin);

    if (!line) { break; }

    data_length += strlen(cursor);

    if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

    size_t new_length = alloc_length << 1;
    data = realloc(data, new_length);

    if (!data) { break; }

    alloc_length = new_length;
  }

  if (data[data_length - 1] == '\n') {
    data[data_length - 1] = '\0';
  }

  data = realloc(data, data_length);

  return data;
}

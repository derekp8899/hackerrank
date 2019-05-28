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
char** split_string(char*);

// Complete the hourglassSum function below.
int hourglassSum(int arr_rows, int arr_columns, int** arr) {
  int num;//the total number of hourglasses that we must calculate

  //set the number of hour glasses that exist in the array
  //this is not really needed but nice short circuiting if the input array is not large enough for an hourglass
  
  if(arr_rows >= 3)
    num = arr_rows - 2;
  else
    num = 0;
  if(arr_columns >= 3)
    num *= arr_columns - 2;
  else
    num = 0;
  /* for 6x6 matrix should == 16 */

  if ( num > 0 ){

    int x,y; //the starting x,y for the current hourglass
    x=0;//start at the beginning(obviously)
    y=0;
    int MAX = -2147483648;//set to sentinel value smallest int value since nagative number are allowed
    while(x <= arr_rows-3){//continue the summing of hour glasses while we are not at the end
      int maxSum = 0;//the sum of current
      for ( int i = y; i < (y+3) ;++i){
	maxSum += arr[x][i];
	maxSum += arr[x+2][i];
	if((i - y) == 1)
	  maxSum +=arr[x+1][i];

      }
      if (maxSum > MAX)
	MAX = maxSum;
      y++;
      if(y > arr_columns-3){
	y = 0;
	++x;
      }

    }
    return MAX;
  }
  else // if there is no hourglass in the matrix return zero
    return 0;

}

int main()
{
  FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

  int** arr = malloc(6 * sizeof(int*));

  for (int i = 0; i < 6; i++) {
    *(arr + i) = malloc(6 * (sizeof(int)));

    char** arr_item_temp = split_string(readline());

    for (int j = 0; j < 6; j++) {
      char* arr_item_endptr;
      char* arr_item_str = *(arr_item_temp + j);
      int arr_item = strtol(arr_item_str, &arr_item_endptr, 10);

      if (arr_item_endptr == arr_item_str || *arr_item_endptr != '\0') { exit(EXIT_FAILURE); }

      *(*(arr + i) + j) = arr_item;
    }
  }

  int arr_rows = 6;
  int arr_columns = 6;

  int result = hourglassSum(arr_rows, arr_columns, arr);

  fprintf(fptr, "%d\n", result);

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

char** split_string(char* str) {
  char** splits = NULL;
  char* token = strtok(str, " ");

  int spaces = 0;

  while (token) {
    splits = realloc(splits, sizeof(char*) * ++spaces);
    if (!splits) {
      return splits;
    }

    splits[spaces - 1] = token;

    token = strtok(NULL, " ");
  }

  return splits;
}

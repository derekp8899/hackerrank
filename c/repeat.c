#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
  c = (j*c)-c;
  j = n%i;
  for(j-1;j>=0;j--)
    if(s[j]=='a')
      c++;
  
  return c;
}

int main(){

  char *buffer = malloc(2);
  buffer[0]='a';
  buffer[1]='\0';
  long n = 1000000000000;
  printf("%ld\n",repeatedString(buffer, n));
    

}

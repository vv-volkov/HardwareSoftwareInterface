#include <stdio.h>
#include <stdlib.h>

unsigned long long glob_var = 0;

void bang(){
  printf("Hello, world!\n");
}

void setGlobVar(void){
   glob_var = 100;
   bang();
}

int main(){
  setGlobVar();
  return 0;
}

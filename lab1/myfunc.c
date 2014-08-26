#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int bitAnd(int x, int y) {
    return ~(~x|~y);
}

int bitXor(int x, int y) {
  return ~( ~( x & ~y ) & ~( ~x & y ) );
}

int thirdBits(void) {
  unsigned int msk = 0x49;
  return msk + ( msk << 9 ) + ( msk << 18 ) + ( msk << 27 );
}

void getBits(int x){
  int i;
  for(i = 0; i < sizeof(int) * 8; i++){    
    printf("%d   %d\n", i, x >> i & 1);
  }
}


int getByte(int x, int n){
  int msk = 0xFF;
  int step = n * 8;
  return ((x & (msk << step))>>step)&msk;
}



void logicShift(int x, int n){
  int step = 32 - n;
  int q = ~( ( ~( ~0 << n ) ) << step );
  int res = ( x >> n ) & q;
  printf("%x", res);

}

int sign(int x) {
  int xorXand = x >> 31;
  return ( ( xorXand ^ (~0)) + 1 ) + ( ( ( !x ) ^ xorXand ) ^ 1 );
}

int bang(int x){
  int a = 1 << 30;
  int b = a & ( x >> 1);
  int c = ~( ( x & ( ~a ) ) | b );
  return ( ( c ^ ( c + 1 ) ) >> 31 ) & 1;
}

int conditional(int x, int y, int z){
  int a = 1 << 30;
  int b = a & ( x >> 1);
  int c = ~( ( x & ( ~a ) ) | b );
  int d = ( c ^ ( c + 1 ) ) >> 31;
  return ( ( d & z ) + ( ~d & y ) );
}

void isPower2(int x) {

  int a = !x;
  int b = a << 31;
  int c = x ^ b;
  int d = c >> 31;
  int e = ~d; // для положительных все 1, для 0 и отрицательных все 0
  
  int f = x >> 1;
  int g = f << 1;
  int h = ( ~g ) + 1;
  int i = x + h; // либо 0, либо что-то другое

  int j = e & ( !i ); // для 0 и отрицательных всегда 0, для положительных,
  // если остаток ноль, то 1, иначе 0
  
  
}

void fitsBits(int x, int n){
 
  int a = ~1 + 1;
  int b = 1 << ( n + a );
  int max = b + a;
  int min = ~b + 1; 
  
}

void intSize(){
  int intArray[10];
  int * intPtr1;
  int * intPtr2;  
  intPtr1 = intArray;
  intPtr2 = ( intPtr1 + 1 );  
  int x = (int) ( (long int) intPtr2 - (long int) intPtr1 );
  printf("%ld %ld\n", (long int) intPtr1, (long int) intPtr2);
}

int doubleSize() {
  double doubArray[10];
  double * doubPtr1;
  double * doubPtr2;
  // TODO: Write code to compute size of a double.
  doubPtr1 = doubArray;
  doubPtr2 = doubPtr1 + 1;
  int x = (int) ( (long int) doubPtr2 - (long int) doubPtr1 );
  printf("%d\n", x);
  

}

void tst(int p){
  long int x = (long int) &p;
  printf("%ld", sizeof(long int));
}

void getLongBits(long int x){
  int i;
  for(i = 0; i < 64; i++){    
    printf("%d   %ld\n", i, x >> i & 1);
  }
}

void withinSameBlock(){
  long int arr[200];
  long int * ptr1, * ptr2;
  long int ones = ( ~0  ) << 6;
  getLongBits( ones );
}

void withinArray(){
  int * arr = (int *) 0x14;
  long int start = (long int) arr;
  long int end = (long int) ( arr + 3 );
  long int cur = (long int) 0xd;
  long int res = ( ( ~( cur - start ) ) >> 63 ) & ( ( ~( end - cur ) ) >> 63 ) & 1;
  printf("%ld\n", res);
  // withinArray(0x1, 4, 0xd) = 0	[ fail ] (expected 1)
  // withinArray(0x1, 4, 0x11) = 0	[ OK ]
  // withinArray(0x14, 4, 0xd) = 1	[ fail ] (expected 0)
}

void invert() {
  // TODO
  int x = 1334458;

  int p = 3;

  int n = 3;

  int msk = ( -1 << p ) & ( ~(-1 << ( p + n ) ) );

  int inv = ( ~(x & msk) & msk ) | ( x & ( ~msk ));

  getBits( msk );

}

void isPowerTwo(){
  int x = 8;
  
  int a = !x;
  int b = a << 31;
  int c = x ^ b;
  int d = c >> 31;
  int e = ~d; // для положительных все 1, для 0 и отрицательных все 0
  
  int pos = ~x >> 31 ;
  int notX = ~x;
  int n = x + ~1 + 1;
  int l = n & notX;
  int r = e & !( n + ~l + 1 );
  
  getBits( r );
}

void addOK(){
  int aSign = a >> 31;
  int bSign = b >> 31;
  int signXor = aSign ^ bSign;
  int ifDif = signXor & 1;
  int notXor = ~signXor;
  int sum = a + b;
  int ifNegative = aSign & ( ( ( notXor & sum ) >> 31 ) & 1 );
  int ifPositive = ( ~aSign ) & ( ( notXor & ( ~sum ) ) >> 31 ) & 1;
  int r = ifNegative + ifPositive + ifDif;
  

  
}


int main(){
  int bAnd = bitAnd(6, 5);
  int bXor = bitXor(4, 5);
  unsigned int msk = 0x49; // 01001001
  int ms = 0xFF;
  int w = getByte(0x80000000,3);
  int i, j;
  int c = conditional(0, 4, 5);

  long int p1 = (long int) 0x12345678;
  long int p2 = (long int) 0x12345658;

  addOK();
 
  return 0;
}

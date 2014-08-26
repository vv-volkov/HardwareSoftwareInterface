/*
Coursera HW/SW Interface
Lab 4 - Mystery Caches

Mystery Cache Geometries (for you to keep notes):
mystery0:
    block size =
    cache size =
    associativity =
mystery1:
    block size =
    cache size =
    associativity =
mystery2:
    block size =
    cache size =
    associativity =
mystery3:
    block size =
    cache size =
    associativity =
*/

#include <stdlib.h>
#include <stdio.h>

#include "mystery-cache.h"

/*
 * NOTE: When using access_cache() you do not need to provide a "real"
 * memory addresses. You can use any convenient integer value as a
 * memory address, you should not be able to cause a segmentation
 * fault by providing a memory address out of your programs address
 * space as the argument to access_cache.
 */

/*
   Returns the size (in B) of each block in the cache.
*/
int get_block_size(void) {
  /* YOUR CODE GOES HERE */
  int i = 0;
  do {
    access_cache(i++);
  }
  while(access_cache(i));
  return i;
}

/*
   Returns the size (in B) of the cache.
*/
int get_cache_size(int size) {
  int cache_size_bytes = 1024,
    cache_size_kbytes = 1,
    num_of_lines = 0,
    i = 0;
  unsigned char el = 0;
  
  while(cache_size_kbytes < 32768){ // Предполагаем, что размер кэша меньше
    // Вычисляем предполагаемое количество строк в кэше
    num_of_lines = cache_size_bytes / size;
    i = 0;
    while(i < num_of_lines){
      // Заполняем полностью предполагаемый кэш
      access_cache(i * size);
      i++;
    }
    access_cache(cache_size_bytes);
    el = access_cache(0);
    if(el == 0) break;
    // Предполагаем, что размер кэша - степень двойки
    cache_size_kbytes *= 2;
    cache_size_bytes = 1024 * cache_size_kbytes;
    // Чистим кэш, чтобы не было конфликтов в цикле выше
    flush_cache();
  }  
  return cache_size_bytes;
}

/*
   Returns the associativity of the cache.
*/
int get_cache_assoc(int size) {
  int way = 1, i = 0;
  unsigned char el = 0;
  int max_assoc = size / get_block_size();  
  while(way <= max_assoc){    
    i = 0;
    while(i <= way){
     access_cache(i * size);
     i++;
    }
    el = access_cache(0);
    if(el == 0) break;
    way *= 2;
    flush_cache();
  }  
  return way;
}

//// DO NOT CHANGE ANYTHING BELOW THIS POINT
int main(void) {
  int size;
  int assoc;
  int block_size;

  /* The cache needs to be initialized, but the parameters will be
     ignored by the mystery caches, as they are hard coded.  You can
     test your geometry paramter discovery routines by calling
     cache_init() w/ your own size and block size values. */
  cache_init(0,0);

  block_size=get_block_size();
  size=get_cache_size(block_size);
  assoc=get_cache_assoc(size);

  printf("Cache block size: %d bytes\n", block_size);
  printf("Cache size: %d bytes\n", size);
  printf("Cache associativity: %d\n", assoc);

  return EXIT_SUCCESS;
}

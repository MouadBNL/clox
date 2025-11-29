#include "memory.h"
#include <stdlib.h>

void *mem_reallocate(void *pointer, size_t old_size, size_t new_size) {
  if (new_size == 0) {
    free(pointer);
    return NULL;
  }
  void *result = realloc(pointer, new_size);
  if (result == NULL)
    exit(1);
  return result;
}

void *mem_grow(void *ptr, size_t old_size, size_t new_size) {
  return mem_reallocate(ptr, old_size, new_size);
}

void *mem_free(void *ptr, size_t old_size) {
  return mem_reallocate(ptr, old_size, 0);
}

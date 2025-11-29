#ifndef __CLOX_MEMORY_H
#define __CLOX_MEMORY_H

#include <stddef.h>

void *mem_reallocate(void *pointer, size_t old_size, size_t new_size);
void *mem_grow(void *ptr, size_t old_size, size_t new_size);
void *mem_free(void *ptr, size_t old_size);

#endif

#ifndef __CLOX_CHUNK_H
#define __CLOX_CHUNK_H

#define CHUNK_DEFAULT_SIZE 8
#include "common.h"

typedef enum {
  OP_RETURN,
} OpCpde;

typedef struct {
  int size;
  int capacity;
  uint8_t *code;
} Chunk;

void chunk_init(Chunk *chunk);
void chunk_push_back(Chunk *chunk, uint8_t byte);
void chunk_free(Chunk *chunk);

#endif

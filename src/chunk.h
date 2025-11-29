#ifndef __CLOX_CHUNK_H
#define __CLOX_CHUNK_H

#define CHUNK_DEFAULT_SIZE 8

#include "common.h"
#include "value.h"

typedef enum {
  OP_CONSTANT,
  OP_RETURN,
} OpCpde;

typedef struct {
  int size;
  int capacity;
  uint8_t *code;
  int *lines;
  ValueArray constants;
} Chunk;

void chunk_init(Chunk *chunk);
void chunk_push_back(Chunk *chunk, uint8_t byte, int line);
void chunk_free(Chunk *chunk);

int chunk_add_constant(Chunk *chunk, Value value);

#endif

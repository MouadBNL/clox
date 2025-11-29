#include "chunk.h"

#include <stdint.h>
#include <stdlib.h>

#include "memory.h"
#include "value.h"

void chunk_resize(Chunk *chunk, int capacity) {
  chunk->code = (uint8_t *)mem_grow(chunk->code, chunk->capacity, capacity);
  chunk->lines = (int *)mem_grow(chunk->lines, chunk->capacity, capacity);
  chunk->capacity = capacity;
}

void chunk_init(Chunk *chunk) {
  chunk->size = 0;
  chunk->capacity = 0;
  chunk->code = NULL;
  chunk->lines = NULL;
  value_array_init(&chunk->constants);
}

void chunk_push_back(Chunk *chunk, uint8_t byte, int line) {
  if (chunk->capacity == 0) {
    chunk_resize(chunk, CHUNK_DEFAULT_SIZE);
  }
  if (chunk->size >= chunk->capacity) {
    chunk_resize(chunk, chunk->capacity * 2);
  }
  chunk->code[chunk->size] = byte;
  chunk->lines[chunk->size] = line;
  chunk->size++;
}

void chunk_free(Chunk *chunk) {
  mem_free(chunk->code, chunk->capacity);
  mem_free(chunk->lines, chunk->capacity);
  value_array_free(&chunk->constants);
  chunk_init(chunk);
}

int chunk_add_constant(Chunk *chunk, Value value) {
  value_array_push_back(&chunk->constants, value);
  return chunk->constants.size - 1;
}

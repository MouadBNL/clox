#include "chunk.h"
#include "memory.h"
#include <stdint.h>
#include <stdlib.h>

void chunk_resize(Chunk *chunk, int capacity) {
  chunk->code =
      (uint8_t *)mem_reallocate(chunk->code, chunk->capacity, capacity);
  chunk->capacity = capacity;
}

void chunk_init(Chunk *chunk) {
  chunk->size = 0;
  chunk->capacity = 0;
  chunk->code = NULL;
}

void chunk_push_back(Chunk *chunk, uint8_t byte) {
  if (chunk->capacity == 0) {
    chunk_resize(chunk, CHUNK_DEFAULT_SIZE);
  }
  if (chunk->size >= chunk->capacity) {
    chunk_resize(chunk, chunk->capacity * 2);
  }
  chunk->code[chunk->size] = byte;
  chunk->size++;
}

void chunk_free(Chunk *chunk) {
  mem_free(chunk->code, chunk->capacity);
  chunk_init(chunk);
}

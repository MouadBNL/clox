#include <stdlib.h>

#include "chunk.h"
#include "debug.h"

int main(int argc, const char *argv[]) {
  Chunk chunk;
  chunk_init(&chunk);

  int constant = chunk_add_constant(&chunk, 1.285f);
  chunk_push_back(&chunk, OP_CONSTANT, 1);
  chunk_push_back(&chunk, constant, 1);

  chunk_push_back(&chunk, OP_RETURN, 1);

  debug_chunk(&chunk, "Test");

  chunk_free(&chunk);
  exit(0);
}

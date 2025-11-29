#include <stdlib.h>

#include "chunk.h"
#include "debug.h"

int main(int argc, const char *argv[]) {
  Chunk chunk;
  chunk_init(&chunk);
  chunk_push_back(&chunk, OP_RETURN);

  debug_chunk(&chunk, "Test");

  chunk_free(&chunk);
  exit(0);
}

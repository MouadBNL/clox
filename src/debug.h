#ifndef __CLOX_DEBUG_H
#define __CLOX_DEBUG_H

#include "chunk.h"

void debug_chunk(Chunk *chunk, const char *name);
int debug_instruction(Chunk *chunk, int offset);

#endif

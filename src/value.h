#ifndef __CLOX_VALUE_H
#define __CLOX_VALUE_H
#define VALUE_ARRAY_DEFAULT_SIZE 8
typedef double Value;

typedef struct {
  int size;
  int capacity;
  Value* values;
} ValueArray;

void value_array_init(ValueArray* array);
void value_array_push_back(ValueArray* array, Value val);
void value_array_free(ValueArray* array);

void value_print(Value value);

#endif

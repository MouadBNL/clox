#include "value.h"

#include <stdio.h>

#include "memory.h"

void value_array_resize(ValueArray *array, int capacity) {
  array->values =
      (Value *)mem_reallocate(array->values, array->capacity, capacity);
  array->capacity = capacity;
}

void value_array_init(ValueArray *array) {
  array->size = 0;
  array->capacity = 0;
  array->values = NULL;
}

void value_array_push_back(ValueArray *array, Value value) {
  if (array->capacity == 0) {
    value_array_resize(array, VALUE_ARRAY_DEFAULT_SIZE);
  }
  if (array->size >= array->capacity) {
    value_array_resize(array, array->capacity * 2);
  }
  array->values[array->size] = value;
  array->size++;
}

void value_array_free(ValueArray *array) {
  mem_free(array->values, array->capacity);
  value_array_init(array);
}

void value_print(Value value) { printf("%g", value); }

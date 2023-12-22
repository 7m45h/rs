#pragma once

#include <stdbool.h>

#define DEFAULT_LENGTH 50
#define DEFAULT_COUNT  4

struct rs_config {
  bool lowercase;
  bool uppercase;
  bool digits;
  bool punctuation;
  bool whitespace;
  int count;
  int length;
};

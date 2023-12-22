#pragma once

#include "rs_config.h"

struct rand_strings
{
  int count;
  char** strings;
};

struct rand_strings* rs_getRandStrings(struct rs_config* config);
void rs_printRandStrings(struct rand_strings* r_strings);
void rs_freeRandStrings(struct rand_strings* r_strings);

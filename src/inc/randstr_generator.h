#pragma once

#include "arg_handler.h"

char** get_randstr(struct config* config);
void clean_randstr(char** rand_str_arr, int count);

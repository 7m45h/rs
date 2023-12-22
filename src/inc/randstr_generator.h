#pragma once

#include "arg_handler.h"

char** get_randstrs(struct rs_config* config);
void clean_randstrs(char** rand_str_arr, int count);

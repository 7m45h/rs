#pragma once

#include "arg_handler.h"

char** get_randstrs(struct Config* config);
void clean_randstrs(char** rand_str_arr, int count);

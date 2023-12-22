#pragma once

#include "rs_config.h"

struct rs_config* ah_getconfig(int argc, char** argv);
void ah_freeconfig(struct rs_config* config);

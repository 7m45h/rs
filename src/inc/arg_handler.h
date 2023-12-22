#pragma once

#include "rs_config.h"

struct rs_config* ah_getConfig(int argc, char** argv);
void ah_freeConfig(struct rs_config* config);

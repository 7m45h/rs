#include <stdio.h>
#include <stdlib.h>

#include "inc/arg_handler.h"
#include "inc/randstr_generator.h"

int main(int argc, char** argv) {
  struct Config* config = get_config(argc, argv);

  char** rand_strs = get_randstrs(config);

  for (int i = 0; i < config->count; i++) {
    printf("%s\n", rand_strs[i]);
  }

  clean_randstrs(rand_strs, config->count);
  free(config);
  return 0;
}

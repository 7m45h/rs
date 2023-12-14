#include <stdio.h>
#include <stdlib.h>

#include "inc/arg_handler.h"

int main(int argc, char** argv) {
  struct config* config = get_config(argc, argv);

  printf(
    "lowercase: %d\nuppercase: %d\nnumbers: %d\nspecial: %d\nspace: %d\nlength: %d\n",
    config->lowercase,
    config->uppercase,
    config->numbers,
    config->special_chars,
    config->white_space,
    config->str_length
  );

  free(config);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

#include "inc/arg_handler.h"
#include "inc/randstr_generator.h"

int main(int argc, char** argv) {
  struct config* config = get_config(argc, argv);

  char* rand_str = get_randstr(config);

  printf("[!] %s\n", rand_str);

  free(rand_str);
  free(config);
  return 0;
}

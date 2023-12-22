#include "inc/arg_handler.h"
#include "inc/rand_strings.h"
#include "inc/rs_config.h"

int main(int argc, char** argv)
{
  struct rs_config* config       = ah_getConfig(argc, argv);
  struct rand_strings* r_strings = rs_getRandStrings(config);

  rs_printRandStrings(r_strings);

  rs_freeRandStrings(r_strings);
  ah_freeConfig(config);

  return 0;
}

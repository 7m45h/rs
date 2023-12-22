
#include "inc/arg_handler.h"
#include "inc/rs_config.h"

int main(int argc, char** argv)
{
  struct rs_config* config = ah_getconfig(argc, argv);

  ah_freeconfig(config);

  return 0;
}

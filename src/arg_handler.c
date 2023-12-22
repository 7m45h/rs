#include <argp.h>
#include <stdlib.h>

#include "inc/arg_handler.h"

#define DEFAULT_STR_LENGTH 32
#define DEFAULT_STR_COUNT  4

const char* argp_program_version = "rs 1.0.0";
static char doc[] = "generate random strings";

static struct argp_option options[] = {
  {"lowercase",     'l', 0,        0, "include lowercase chars"},
  {"uppercase",     'u', 0,        0, "include uppercase chars"},
  {"numbers",       'n', 0,        0, "include numbers 0-9"},
  {"special_chars", 's', 0,        0, "incluse special chars"},
  {"space",         'w', 0,        0, "include white space"},
  {"length",        'L', "LENGTH", 0, "length of the random string"},
  {"count",         'C', "COUNT",  0, "number of strings to return"},
  {0}
};

static error_t parse_opt(int key, char* arg, struct argp_state* state) {
  struct rs_config* config = state->input;
  
  switch (key) {
    case 'l':
      config->lowercase = 1;
      break;
    case 'u':
      config->uppercase = 1;
      break;
    case 'n':
      config->numbers = 1;
      break;
    case 's':
      config->special_chars = 1;
      break;
    case 'w':
      config->white_space = 1;
      break;
    case 'L':
      config->str_length = atoi(arg) ? atoi(arg) : DEFAULT_STR_LENGTH;
      break;
    case 'C':
      config->count = atoi(arg) ? atoi(arg) : DEFAULT_STR_COUNT;
      break;
    default:
      return ARGP_ERR_UNKNOWN;
  }

  return 0;
}

static struct argp argp = {options, parse_opt, NULL, doc};

struct rs_config* get_config(int argc, char** argv) {
  struct rs_config* config = calloc(1, sizeof(struct rs_config));

  config->str_length    = DEFAULT_STR_LENGTH;
  config->count         = DEFAULT_STR_COUNT;

  argp_parse(&argp, argc, argv, 0, 0, config);

  if (!(config->lowercase + config->uppercase + config->numbers + config->special_chars + config->white_space)) {
    config->lowercase     = 1;
    config->uppercase     = 1;
    config->numbers       = 1;
    config->special_chars = 1;
    config->white_space   = 1;
  }

  return config;
}

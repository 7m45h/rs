#include <argp.h>
#include <stdbool.h>
#include <stdlib.h>

#include "inc/arg_handler.h"
#include "inc/rs_config.h"

const char* argp_program_version = "rs 1.0.0";
static char doc[] = "generate random strings";

static struct argp_option options[] = {
  {"lowercase",   'l', 0,        0, "include lowercase characters"},
  {"uppercase",   'u', 0,        0, "include uppercase characters"},
  {"digits",      'd', 0,        0, "include digits"},
  {"punctuation", 'p', 0,        0, "include punctuation"},
  {"whitespace",  'w', 0,        0, "include whitespace"},
  {"count",       'C', "COUNT",  0, "number of strings to generate"},
  {"length",      'L', "LENGTH", 0, "length of one string"},
  {0}
};

static error_t parse_opt(int key, char* arg, struct argp_state* state)
{
  struct rs_config* config = state->input;

  switch (key)
  {
    case 'l':
    config->lowercase = true;
    break;

    case 'u':
    config->uppercase = true;
    break;

    case 'd':
    config->digits = true;
    break;

    case 'p':
    config->punctuation = true;
    break;

    case 'w':
    config->whitespace = true;
    break;

    case 'C':
    config->count = atoi(arg) ? atoi(arg) : DEFAULT_LENGTH;
    break;

    case 'L':
    config->length = atoi(arg) ? atoi(arg) : DEFAULT_COUNT;
    break;

    default:
    return ARGP_ERR_UNKNOWN;
  }

  return 0;
}

static struct argp argp = {options, parse_opt, NULL, doc};

struct rs_config* ah_getconfig(int argc, char** argv)
{
  struct rs_config* config = calloc(1, sizeof(struct rs_config));

  config->count  = DEFAULT_COUNT;
  config->length = DEFAULT_LENGTH;

  argp_parse(&argp, argc, argv, 0, 0, config);

  if (config->lowercase && config->uppercase && config->digits && config->punctuation && config->whitespace)
  {
    config->lowercase   = true;
    config->uppercase   = true;
    config->digits      = true;
    config->punctuation = true;
    config->whitespace  = true;
  }

  return config;
}

void ah_freeconfig(struct rs_config* config)
{
  free(config);
}

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "inc/rand_strings.h"

#define ASCII_LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define ASCII_UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DIGITS          "0123456789"
#define PUNCTUATIONS    "!\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~"
#define WHITESPACE      " "

#define DEFAULT_CHAR_POOL_SIZE 128

struct rand_strings* rs_getRandStrings(struct rs_config* config)
{
  srand(time(NULL));

  int char_pool_size = 0;
  char* char_pool = calloc(DEFAULT_CHAR_POOL_SIZE, sizeof(char));
  struct rand_strings* r_strings = calloc(1, sizeof(struct rand_strings));

  r_strings->count = config->count;
  r_strings->strings = calloc(config->count, sizeof(char*));
  for (int i = 0; i < config->count; i++)
  {
    r_strings->strings[i] = calloc(config->length, sizeof(char));
  }

  if (config->lowercase)   char_pool = strcat(char_pool, ASCII_LOWERCASE);
  if (config->uppercase)   char_pool = strcat(char_pool, ASCII_UPPERCASE);
  if (config->digits)      char_pool = strcat(char_pool, DIGITS);
  if (config->punctuation) char_pool = strcat(char_pool, PUNCTUATIONS);
  if (config->whitespace)  char_pool = strcat(char_pool, WHITESPACE);

  char_pool_size = strlen(char_pool);

  for (int i = 0; i < r_strings->count; i++)
  {
    for (int j = 0; j < config->length; j++)
    {
      r_strings->strings[i][j] = char_pool[rand() % char_pool_size];
    }
  }

  free(char_pool);

  return r_strings;
}

void rs_printRandStrings(struct rand_strings* r_strings)
{
  for (int i = 0; i < r_strings->count; i++)
  {
    printf("%s\n", r_strings->strings[i]);
  }
}

void rs_freeRandStrings(struct rand_strings* r_strings)
{
  for (int i = 0; i < r_strings->count; i++)
  {
    free(r_strings->strings[i]);
  }

  free(r_strings->strings);
  free(r_strings);
}

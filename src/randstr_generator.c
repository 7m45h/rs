#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "inc/arg_handler.h"
#include "inc/randstr_generator.h"

#define LOWERCASE     "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE     "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMBERS       "0123456789"
#define SPECIAL_CHARS "!\"#$%&\\'()*+,-./:;<=>?@[]^_`{|}~"
#define WHITE_SPACE   " "

#define TOTAL_CHAR_NUM 128

char** get_randstrs(struct rs_config* config) {
  srandom(time(NULL));

  int char_pool_size = 0;
  char* char_pool = calloc(TOTAL_CHAR_NUM, sizeof(char));
  char** rand_strs = calloc(config->count, sizeof(char*));

  if (config->lowercase)     char_pool = strcat(char_pool, LOWERCASE);
  if (config->uppercase)     char_pool = strcat(char_pool, UPPERCASE);
  if (config->numbers)       char_pool = strcat(char_pool, NUMBERS);
  if (config->special_chars) char_pool = strcat(char_pool, SPECIAL_CHARS);
  if (config->white_space)   char_pool = strcat(char_pool, WHITE_SPACE);

  char_pool_size = strlen(char_pool);

  for (int i = 0; i < config->count; i++) {
    rand_strs[i] = calloc(config->str_length, sizeof(char));

    for (int j = 0; j < config->str_length; j++) {
      rand_strs[i][j] = char_pool[random() % char_pool_size];
    }
  }

  free(char_pool);

  return rand_strs;
}

void clean_randstrs(char** rand_strs, int count) {
  for (int i = 0; i < count; i++) {
    free(rand_strs[i]);
  }
  free(rand_strs);
}

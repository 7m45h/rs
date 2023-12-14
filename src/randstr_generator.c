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

#define TOTAL_CHAR_NUM 93

char* get_randstr(struct config* config) {
  srandom(time(NULL));

  int len_str_src = 0;
  char* str_src = calloc(TOTAL_CHAR_NUM, sizeof(char));
  char* str_out = calloc(config->str_length, sizeof(char));

  if (config->lowercase)     str_src = strcat(str_src, LOWERCASE);
  if (config->uppercase)     str_src = strcat(str_src, UPPERCASE);
  if (config->numbers)       str_src = strcat(str_src, NUMBERS);
  if (config->special_chars) str_src = strcat(str_src, SPECIAL_CHARS);
  if (config->white_space)   str_src = strcat(str_src, WHITE_SPACE);

  len_str_src = strlen(str_src);

  for (int i = 0; i < config->str_length; i++) {
    str_out[i] = str_src[random() % len_str_src];
  }

  free(str_src);

  return str_out;
}

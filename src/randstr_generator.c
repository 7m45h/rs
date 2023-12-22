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

char** get_randstrs(struct Config* config) {
  srandom(time(NULL));

  int len_str_src = 0;
  char* str_src = calloc(TOTAL_CHAR_NUM, sizeof(char));
  char** str_out_arr = calloc(config->count, sizeof(char*));

  if (config->lowercase)     str_src = strcat(str_src, LOWERCASE);
  if (config->uppercase)     str_src = strcat(str_src, UPPERCASE);
  if (config->numbers)       str_src = strcat(str_src, NUMBERS);
  if (config->special_chars) str_src = strcat(str_src, SPECIAL_CHARS);
  if (config->white_space)   str_src = strcat(str_src, WHITE_SPACE);

  len_str_src = strlen(str_src);

  for (int i = 0; i < config->count; i++) {
    str_out_arr[i] = calloc(config->str_length, sizeof(char));

    for (int j = 0; j < config->str_length; j++) {
      str_out_arr[i][j] = str_src[random() % len_str_src];
    }
  }

  free(str_src);

  return str_out_arr;
}

void clean_randstrs(char** rand_str_arr, int count) {
  for (int i = 0; i < count; i++) {
    free(rand_str_arr[i]);
  }
  free(rand_str_arr);
}

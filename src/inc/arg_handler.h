#pragma once

struct Config {
  int lowercase;
  int uppercase;
  int numbers;
  int special_chars;
  int white_space;
  int str_length;
  int count;
};

struct Config* get_config(int argc, char** argv);

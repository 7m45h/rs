#pragma once

struct rs_config {
  int lowercase;
  int uppercase;
  int numbers;
  int special_chars;
  int white_space;
  int str_length;
  int count;
};

struct rs_config* get_config(int argc, char** argv);

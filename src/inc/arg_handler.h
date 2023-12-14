struct config {
  int lowercase;
  int uppercase;
  int numbers;
  int special_chars;
  int white_space;
  int str_length;
};

struct config* get_config(int argc, char** argv);

#ifndef SRC_MY_SPRINTF_H_
#define SRC_MY_SPRINTF_H_

#include "my_string.h"
#include "math.h"

struct flag_type {
  int plus;
  int minus;
  int space;
  int is_short;
  int is_long;
  int precision;
  int width;
};

typedef struct flag_type flag_t;

void reset_flags(flag_t* flags);
char* print_char(char* str, flag_t* flags, char type, va_list* input);
char* print_string(char* str, flag_t* flags, va_list* input);
char* print_wide_string(char* str, flag_t* flags, va_list* input);
char* print_number(char* str, flag_t* flags, char type, va_list* input);
void my_itos(char *str, long long int num, flag_t* flags);
void my_ftos(char *str, double num, flag_t* flags);
void my_uitos(char *str, unsigned long num, flag_t* flags);

#endif  // SRC_MY_SPRINTF_H_

#include "my_string.h"

void *my_memchr(const void *str, int c, my_size_t n) {
  void *result = my_NULL;
  if (n != 0) {
    const char *p = str;
    do {
      if (*p++ == (char)c) {
        result = ((void *)(p - 1));
        break;
      }
    } while (--n != 0);
  }
  return result;
}

int my_memcmp(const void *s1, const void *s2, my_size_t n) {
  const unsigned char *p1 = s1, *p2 = s2;
  int result = 0;
  while (n--)
    if (*p1 != *p2) {
      result = *p1 - *p2;
    } else {
      p1++;
      p2++;
    }
  return result;
}

void *my_memcpy(void *dest, const void *src, my_size_t n) {
  char *d = dest;
  const char *s = src;
  while (n-- > 0) {
    *d++ = *s++;
  }
  return dest;
}

void *my_memmove(void *dest, const void *src, my_size_t n) {
  char *d = dest;
  char *s = (char *)src;
  if (d < s) {
    while (n--) {
      *d++ = *s++;
    }
  } else {
    char *ends = s + (n - 1);
    char *endd = d + (n - 1);
    while (n--) {
      *endd-- = *ends--;
    }
  }
  return dest;
}

void *my_memset(void *str, int c, my_size_t n) {
  char *p = (char *)str;
  for (my_size_t i = 0; i != n; ++i) {
    p[i] = c;
  }
  return str;
}

char *my_strcat(char *dest, const char *src) {
  char *tmp = dest;
  while (*dest) {
    dest++;
  }
  while ((*dest++ = *src++) != '\0') {
  }
  return tmp;
}

char *my_strncat(char *dest, const char *src, my_size_t n) {
  my_size_t dest_len = my_strlen(dest);
  my_size_t i;
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[dest_len + i] = src[i];
  }
  dest[dest_len + i] = '\0';
  return dest;
}

char *my_strchr(const char *str, int c) {
  int is_null = 0;
  for (; *str != (char)c; ++str) {
    if (*str == '\0') {
      is_null = 1;
      break;
    }
  }
  char *result = my_NULL;
  if (is_null == 0) {
    result = (char *)str;
  }
  return result;
}

int my_strcmp(const char *str1, const char *str2) {
  while (*str1 && *str1 == *str2) {
    ++str1;
    ++str2;
  }
  return (*str1 - *str2);
}

int my_strncmp(const char *str1, const char *str2, my_size_t n) {
  int resultcmp = 0;
  for (my_size_t i = 0; i < n; i++) {
    if (str1[i] > str2[i] || str2[i] > str1[i]) {
      resultcmp = str1[i] - str2[i];
      break;
    } else if (str1[i] == '\0' || str2[i] == '\0') {
      break;
    }
  }
  return resultcmp;
}

char *my_strcpy(char *dest, const char *src) {
  int i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return dest;
}

char *my_strncpy(char *dest, const char *src, my_size_t n) {
  my_size_t stringlen = my_strnlen(src, n);
  if (stringlen != n) {
    my_memset(dest + stringlen, '\0', n - stringlen);
  }
  return my_memcpy(dest, src, stringlen);
}

my_size_t my_strcspn(const char *str1, const char *str2) {
  int i = 0;
  while (str1[i] != '\0') {
    if (my_strchr(str2, str1[i]) != my_NULL) {
      break;
    }
    i++;
  }
  my_size_t lenght = i * sizeof(char);
  return lenght;
}

my_size_t my_strlen(const char *str) {
  my_size_t size = 0;
  while (str[size]) {
    size++;
  }
  return size;
}

my_size_t my_strnlen(const char *src, my_size_t n) {
  my_size_t i = 0;
  for (i = 0; i < n; i++) {
    if (src[i] == '\0') break;
  }
  return i;
}

char *my_strpbrk(const char *str1, const char *str2) {
  char *result = my_NULL;
  for (; *str1 != '\0'; ++str1) {
    if (my_strchr(str2, *str1) != my_NULL) {
      result = (char *)str1;
      break;
    }
  }
  return result;
}

char *my_strrchr(const char *str, int c) {
  const char *result = my_NULL;
  if (str != my_NULL) {
    do {
      if (*str == (char)c) {
        result = str;
      }
    } while (*str++);
  }
  return (char *)result;
}

my_size_t my_strspn(const char *str1, const char *str2) {
  const char *symstr1;
  const char *symstr2;
  int count = 0;

  for (symstr1 = str1; *symstr1 != '\0'; symstr1++) {
    for (symstr2 = str2; *symstr2 != '\0'; symstr2++) {
      if (*symstr1 == *symstr2) {
        count++;
        break;
      }
    }
    if (*symstr1 != *symstr2) {
      break;
    }
  }
  return (count);
}

char *my_strstr(const char *str1, const char *str2) {
  const char *symstr2;
  const char *p;
  const char *flag = my_NULL;
  if (*str2 != '\0') {
    for (; *str1 != '\0'; str1++) {
      if (*str1 == *str2) {
        for (p = str1, symstr2 = str2; *symstr2 != '\0'; symstr2++, p++) {
          if (*p != *symstr2) {
            break;
          }
        }
        if (*symstr2 == '\0') {
          flag = str1;
          break;
        }
      }
    }
  } else {
    flag = str1;
  }
  return (char *)flag;
}

char *my_strtok(char *str, const char *delim) {
  static char *copy_base;
  char *str1;
  static char *last;
  char *ch;
  char *tonull;
  int is_null = 0;

  if (str) {
    copy_base = str;
    str1 = copy_base;
  }
  if (!str && *last == '\0') {
    is_null = 1;
  }
  if (!str) {
    str1 = last;
  }

  while (*str1 != 0) {
    ch = str1;
    if (!my_strchr(delim, *ch)) {
      copy_base = str1;
      break;
    }
    str1++;
  }

  while (*str1 != 0) {
    tonull = str1;
    if (my_strchr(delim, *tonull)) {
      break;
    }
    str1++;
  }
  if (*str1 == '\0') {
    tonull = str1;
  }

  while (*str1 != 0) {
    ch = str1;
    if (!my_strchr(delim, *ch)) {
      last = str1;
      break;
    }
    str1++;
  }
  if (*str1 == '\0') {
    last = str1;
  }
  *tonull = '\0';

  char *result = my_NULL;
  if (is_null == 0) {
    result = copy_base;
  }
  return result;
}

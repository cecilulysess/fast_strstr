#include <stdio.h>
#include <stdlib.h>
#include "rk_strstr.h"

int main() {
  char *a = "abcadcidkeidjknerl";
  char *b = "abcabcabccba";
  char *c = "kkkkkk";
  char *d = "IULI CA";
  char* res = rk_strstr(d, "partem");
  
  printf("%s\n", rk_strstr(a, "idk"));
  printf("%s\n", rk_strstr(b, "cab"));
  printf("%s\n", rk_strstr(c, "kkk"));
}

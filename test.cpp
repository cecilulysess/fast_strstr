#include <stdio.h>
#include <stdlib.h>
#include "rk_strstr.h"

int main() {
  char *a = "abcadcidkeidjknerl";
  char *b = "abcabcabccba";
  char *c = "kkkkkk";
  
  printf("%s\n", rk_strstr(a, "idk"));
  printf("%s\n", rk_strstr(b, "cab"));
  printf("%s\n", rk_strstr(c, "kkk"));
  printf("%s\n", rk_strstr(a, "nnn")); 
}

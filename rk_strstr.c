#include "rk_strstr.h"
#include <stdlib.h>
#include <string.h>

#define PRIME 73
#define MOD 19999999

char *rk_strstr(const char *haystack, const char *needle) {
  if (!haystack || !needle) return NULL;
  if (!*needle) return NULL;
  
  char* p = (char*) strchr(haystack, *needle);
  char* q = (char*) needle;
  int len = strlen(needle);
  int hash = 0;
  int roll = 0;
  while(*p && *q) {
    roll = ((roll + *p++) * PRIME) % MOD;
    hash = ((hash + *q++) * PRIME) % MOD;
  }
  if (*q) return NULL;
  while(*p) {
    if (hash == roll && memcmp(p - len,  needle, len) == 0 ) return p - len;
    hash = (hash - *(p - len ) * PRIME) % MOD;
    hash = (hash + *p) * PRIME % MOD;
    p++;
  }

  return NULL;
}

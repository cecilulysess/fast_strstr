#include "rk_strstr.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define PRIME 2
#define MOD 19999999
#define MASK 0x7FFFF  // 2^19 is prime

char *rk_strstr(const char *haystack, const char *needle) {
//  printf("IPT: %s\n\t%s\n", haystack, needle);
  if (!haystack || !needle) return NULL;
  if (!*needle) return (char*) haystack;
  
  haystack = strchr(haystack, *needle);
  if(!haystack) return NULL;
  register const char* p = haystack + 1;
  register const char* q =  needle + 1;
  register int hash = *haystack << 1;
  register int roll = *haystack << 1;
  while(*p && *q) {
    roll = ((roll + *p++) << 1) & MASK;
    hash = ((hash + *q++) << 1) & MASK;
  }
  if (*q) return NULL;
  int len = q - needle;
  const char *head;
  for(head = haystack; *p; p++) {
    if (hash == roll && memcmp(head, needle, len) == 0 ) return (char*) head;
    hash = (hash - (*head++<<1) ) & MASK;
    hash = ((hash + *p) << 1) & MASK;
  }

  return NULL;
}

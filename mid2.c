#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    char* p = "hello";
    char* q = "world";
    int l1 = strlen(p);
    int l2 = strlen(q);
    char* l = (char*)malloc(sizeof(l1+l2)+1);
    while (*p) *l++ = *p++;
    while (*q) *l++ = *q++;
    *l = '\0';

}
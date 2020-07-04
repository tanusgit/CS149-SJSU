/*
Enter input names:
Jill Allen
Error: No comma in names.

Enter input names:
Jill, Allen


Enter input names:
Jill, Allen
First word: Jill
Second word: Allen
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void copy_name(char* dest, char* src, int name_begin, int name_end) {
    int num = name_end-name_begin+1;
    strncpy(dest, src+name_begin, num);
    dest[num] = '\0';
    printf("word:%s\n",dest);
}

int main(){
    while(1) {
        char names[100];
        char first_name[100];
        char second_name[100];
        char *name_ptr = names;
        size_t sz;
        printf("Enter input string:\n");
        getline(&name_ptr, &sz, stdin);
        bool comma_found = false;
        size_t len = strlen(names);
        int name_begin=0;
        int name_end=0;
        char* cur_name = first_name;
        for(int i = 0; i < len; i++){
            char c = names[i];
            switch(c) {
                case ' ': {
                    printf("pos:%d,%d\n", name_begin, name_end);
                    if (name_begin >= name_end) {
                        name_begin = i+1;
                    }
                    else {
                        name_end = i-1;
                    }
                    break;
                }
                case ',': {// Second name starts
                    printf("copy pos:%d,%d\n", name_begin, name_end);
                    copy_name(cur_name, names, name_begin, name_end);
                    cur_name = second_name;
                    name_begin = i+1;
                    name_end = i+1;
                    comma_found = true;
                    break;
                }
                default:
                    name_end = i;
                    break;
            }
        }
        if (names[0] == 'q') {
            break;
        }
        if (!comma_found) {
            printf("Error: No comma in string.\n\n");
            continue;
        } else {
            copy_name(cur_name, names, name_begin, name_end-1);
        }
        // Parse the names.
        printf("First word:%s\n", first_name);
        printf("Second word:%s\n", second_name);
    }
    return 0;
}
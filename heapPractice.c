#include <stdio.h>
#include <stdlib.h>

int *heap_practice() {
    printf("calling from heap_practice\n");
    int sz = 10;
    // malloc returns the pointer to allocated memory.
    int *p = (int*)malloc(sz*sizeof(int));
    for (int i = 0; i < sz; ++i)
        p[i] = i+10;
    /*for (int i = 0; i < sz; ++i)
        printf("p[%d]=%d\n", i, p[i]);
    for (int i = 0; i < sz; ++i)
        printf("p[%d]=%d\n", i, *(p+i));*/
    return p;
}

int fork() {
    printf("calling from fork...\n");
    return 0;
}

struct pair {
    int i;
    int j;
};

/** 'struct pair' is the return type */
struct pair pair_practice() {
    struct pair p; // pair p = new pair();
    p.i = 10;
    p.j = 20;
    printf("struct p values:(%d, %d)\n", p.i, p.j);
    return p;
}

void uses_pair(struct pair r) {
    printf("struct r values:(%d, %d)\n", r.i, r.j);
}

// Extern variable
struct pair extern_pair;

int main() {
    int *l = heap_practice();
    for (int i = 0; i < 10; ++i)
        printf("l[%d]=%d\n", i, *(l+i));

    free(l);

    /*/ Automatic variable
    int i = 10;
    struct pair q = pair_practice();
    printf("struct q values:(%d, %d)\n", q.i, q.j);
    uses_pair(q);
    int f = fork();
    if (f != 0) {
        printf("from parent process\n");
    } else {
        printf("from child process\n");
    }*/
    return 0;
}
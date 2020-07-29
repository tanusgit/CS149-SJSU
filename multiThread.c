#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t id[2];
void *func(void *args)
{
    printf("multi-threading\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d \n", i);
       
    }
   

    return NULL;
}
int main()
{
    int a;
    int b;
    int i;
    for (i = 0; i < 2; i++)
    {
        a = pthread_create(&(id[i]), NULL, &func, NULL);
        if (a != 1)
        {
            printf("thread creation is successfull\n");
        }
    }
    pthread_join(id[0], NULL);
    pthread_join(id[1], NULL);
    return 0;
}
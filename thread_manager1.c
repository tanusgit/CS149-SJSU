#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>

int c = 0;
int logi = 0;
char temp[20][20];
struct node
{
    char *st;
    struct node *next;
};
struct node *insert_at_b(struct node *head, char k[100])
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->st = (char *)malloc(15 * (sizeof(char)));
    if (head == NULL)
    {
        strcpy(temp->st, k);
        temp->next = NULL;
        head = temp;
    }
    else
    {
        strcpy(temp->st, k);
        temp->next = head;
        head = temp;
    }
    return head;
}

void deletelist(struct node *head)
{
    struct node *temp = head;
    struct node *temp2 = head;
    while (temp2 != NULL)
    {
        free(temp2->st);
        temp2 = temp2->next;
        //free(temp2->index);
    }
    while (head != NULL)
    {
        head = head->next;
        free(temp);
        temp = head;
    }
}

struct node *head = NULL;
struct node *nhead = NULL;

// read in stdin and store into the head of linked list.
//thread mutex lock for access to the log index.
// sample output: "Logindex 1, thread 2, PID 5435, DATE TIME: Head of the linked list contains line foo."
pthread_mutex_t tlock1 = PTHREAD_MUTEX_INITIALIZER;
//thread mutex lock for critical sections of allocating THREADDATA
pthread_mutex_t tlock2 = PTHREAD_MUTEX_INITIALIZER;

void *thread_runner(void *);
void print_current_time(void);
pthread_t tid1, tid2;
struct THREADDATA_STRUCT
{
    pthread_t creator;
};
typedef struct THREADDATA_STRUCT THREADDATA;

THREADDATA *p = NULL;

//variable for indexing of messages by the logging function
int logindex = 0;
int *logip = &logindex;

//A flag to indicate if the reading of input is complete,
//so the other thread knows when to stop
bool is_reading_complete = false;

/*********************************************************
// function main -------------------------------------------------
*********************************************************/
int main()
{
    int i = 1;
    printf("create first thread\n");
    pthread_create(&tid1, NULL, thread_runner, (void *)i);

    printf("create second thread\n");
    pthread_create(&tid2, NULL, thread_runner, (void *)(i + 1));

    printf("wait for first thread to exit\n");
    pthread_join(tid2, NULL);
    pthread_join(tid1, NULL);
    printf("first thread exited\n");

    printf("wait for second thread to exit\n");

    printf("second thread exited\n");

    deletelist(nhead);
    free(p);

    exit(0);

} //end main

/**********************************************************************
// function thread_runner runs inside each thread --------------------------------------------------
**********************************************************************/
void *thread_runner(void *x)
{

    pthread_t me;
    char input[100];
    char *result;
    me = pthread_self();
    //printf("This is thread %ld (p=%p)\n",me,p);

    pthread_mutex_lock(&tlock2);
    // critical section starts

    if (p == NULL)
    {
        p = (THREADDATA *)malloc(sizeof(THREADDATA));
        p->creator = me;
    }
    //printf("Memory allocation to thread data successfull\n");
    pthread_mutex_unlock(&tlock2); // critical section ends
    pthread_mutex_lock(&tlock2);
    if (p != NULL && p->creator == me)
    {   // this is thread 1 right here
        // this code block here should read user input and store it in variable result.
        //printf("enter the string\n");
        while ((result = fgets(input, 100, stdin)) != NULL)
        {
            //printf("reading is being done by:%d",x);

            strcpy(temp[c], result);
            if (head == NULL)
            {
                head = insert_at_b(head, temp[c]);
            }
            else
            {
                head = insert_at_b(head, temp[c]);
            }
            c = c + 1;

            //printf("%s",result);
        }

        printf("This is thread %ld and I created the THREADDATA %p\n", me, p);
        pthread_mutex_unlock(&tlock2);
    }

    else
    {

        // before printing any log messages, mutex_lock(locklogindex) so it does not mess up the counting.
        // before updating the head from thread 1 use mutex_lock(lockhead) and then mutex_unlock(lockhead).
        // something like while (!is_read_complete) { sleep(2);
        // check if head is different from last time, if yes then print the head.
        // print out if different from head?
        pthread_mutex_lock(&tlock1);

        int k;
        struct node *tt = head;
        nhead = head;
        //printf("here hehe");
        while (tt != NULL)
        {
            /*
       "Logindex 1, thread 2, PID 5435, 21/04/2020 09:23:25 pm: Head of
linked list contains line foo".
       */
            logi = logi + 1;
            printf("Logindex %d,", logi);
            printf(" ");
            printf("Thread %d,", x);
            printf(" ");
            pid_t tid = gettid();
            printf("PID is %d,", tid);
            printf(" ");
            print_current_time();
            printf(" Head of linked list contains line: %s", tt->st);

            tt = tt->next;
        }
       

        pthread_mutex_unlock(&tlock1);
    }
    //fclose(ptr);
    // use mutex to make this a start of a critical section
    pthread_mutex_lock(&tlock1);
    if (p != NULL && p->creator == me)
    {
        printf("This is thread %ld and I didnot touch THREADDATA\n", me);
    }

    // critical section ends
    pthread_mutex_unlock(&tlock1);
    //print_current_time();
    pthread_exit(NULL);
    return NULL;
}
//end thread_runner

void print_current_time(void)
{
    // variables to store data and time components
    int hours, minutes, seconds, day, month, year;
    // time_t is an arithmetic time type
    time_t now;
    // obtain the current time
    // time() returns the current time of the system as a time_t value
    time(&now);
    // localtime converts a time_t value to calender time and
    // returns a pointer to a tm structure with its members
    // filled with a corresponding values
    struct tm *local = localtime(&now);

    hours = local->tm_hour;
    minutes = local->tm_min;
    seconds = local->tm_sec;

    day = local->tm_mday;
    month = local->tm_mon + 1;
    year = local->tm_year + 1900;

    printf("Date: %02d/%02d/%d ", month, day, year);
    if (hours < 12)
        printf("Time: %02d:%02d:%02d am: ", hours, minutes, seconds);
    else
        printf("Time: %02d:%02d:%02d pm: ", hours - 12, minutes, seconds);
}
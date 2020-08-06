#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>

#define MAX_LINE 1024
#define MAX_LENGTH 200
char* PRINT_TRACE();
void *REALLOC(void *p, int t, char *file, int line, const char *function)
{
    printf("File %s, line %d, function %s reallocated the memory at address %p to a new size %d\n", file, line, function, p, t);
    p = realloc(p, t);

    printf("FUNCTION STACK TRACE: %s\n", PRINT_TRACE());
    return p;
}
void *MALLOC(int t, char *file, int line, const char *function)
{
    void *p;
    p = malloc(t);
    printf("File %s, line %d, function %s allocated new memory segment at address %p to size %d\n", file, line, function, p, t);
    printf("FUNCTION STACK TRACE: %s\n", PRINT_TRACE());
    return p;
}
void FREE(void *p, char *file, int line, const char *function)
{
    printf("File %s, line %d, function %s deallocated the memory segment at address %p\n", file, line, function, p);
    free(p);
    printf("FUNCTION STACK TRACE: %s\n", PRINT_TRACE());
}
struct TRACE_NODE_STRUCT
{
    char *functionid;               // ptr to function identifier
    struct TRACE_NODE_STRUCT *next; // ptr to next frama
};
typedef struct TRACE_NODE_STRUCT TRACE_NODE;
static TRACE_NODE *TRACE_TOP = NULL;
void PUSH_TRACE(char *p) // push p on the stack
{
    TRACE_NODE *tnode;
    static char glob[] = "global";

    if (TRACE_TOP == NULL)
    {
        // initialize the stack with "global" identifier
        TRACE_TOP = (TRACE_NODE *)malloc(sizeof(TRACE_NODE));
        // no recovery needed if allocation failed, this is only
        // used in debugging, not in production

        if (TRACE_TOP == NULL)
        {
            printf("PUSH_TRACE: memory allocation error\n");
            exit(1);
        }

        TRACE_TOP->functionid = glob;
        TRACE_TOP->next = NULL;
    }

    // create the node for p
    tnode = (TRACE_NODE *)malloc(sizeof(TRACE_NODE));
    // no recovery needed if allocation failed, this is only
    // used in debugging, not in production

    if (tnode == NULL)
    {
        printf("PUSH_TRACE: memory allocation error\n");
        exit(1);
    }

    tnode->functionid = p;
    tnode->next = TRACE_TOP; // insert fnode as the first in the list

    TRACE_TOP = tnode; // point TRACE_TOP to the first node
}

void POP_TRACE() // remove the op of the stack
{
    TRACE_NODE *tnode;
    tnode = TRACE_TOP;
    TRACE_TOP = tnode->next;
    free(tnode);
} /*end POP_TRACE*/

/* ---------------------------------------------- */
/* function PRINT_TRACE prints out the sequence of function calls that are on the stack at this instance */
/* For example, it returns a string that looks like: funcA:funcB:funcC.  */
char* PRINT_TRACE()
{
  int depth = 50; //A max of 50 levels in the stack will be combined in a string for printing out.
  int i, length, j;
  TRACE_NODE* tnode;
  static char buf[100];

  if (TRACE_TOP==NULL) {     // stack not initialized yet, so we are
    strcpy(buf,"global");   // still in the `global' area
    return buf;
  }

  /* peek at the depth top entries on the stack, but do not
     go over 100 chars and do not go over the bottom of the
     stack */

  sprintf(buf,"%s",TRACE_TOP->functionid);
  length = strlen(buf);                  // length of the string so far
  for(i=1, tnode=TRACE_TOP->next;
                        tnode!=NULL && i < depth;
                                  i++,tnode=tnode->next) {
    j = strlen(tnode->functionid);             // length of what we want to add
    if (length+j+1 < 100) {              // total length is ok
      sprintf(buf+length,":%s",tnode->functionid);
      length += j+1;
    }else                                // it would be too long
      break;
  }
  return buf;
}

#define realloc(a, b) REALLOC(a, b, __FILE__, __LINE__, __FUNCTION__)
#define malloc(a) MALLOC(a, __FILE__, __LINE__, __FUNCTION__)
#define free(a) FREE(a, __FILE__, __LINE__, __FUNCTION__)
struct node
{
    char *functid;
    int index;
    struct node *next;
};
struct node *insert_at_b(struct node *head, char *p, int u)
{
    //printf("inserting at beginning\n");
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->functid = (char *)malloc(MAX_LENGTH * (sizeof(char)));
    int ll = strlen(p);
    if (ll >= MAX_LENGTH)
    {
        temp->functid = realloc(temp->functid, MAX_LENGTH + ll);
    }
    if (head == NULL)
    {
        temp->functid = strcpy(temp->functid, p);
        temp->index = u;
    }
    temp->next = NULL;
    head = temp;
    return head;
}

struct node *insert_at_e(struct node *head, char *p, int u)
{
    //printf("inserting at end\n");
    struct node *temp = head;
    struct node *temp2 = (struct node *)malloc(sizeof(struct node));
    temp2->functid = (char *)malloc(MAX_LENGTH * (sizeof(char)));
    int ll = strlen(p);
    if (ll >= MAX_LENGTH)
    {
        temp2->functid = realloc(temp2->functid, MAX_LENGTH + ll);
    }
    temp2->functid = strcpy(temp2->functid, p);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = temp2;
    temp2->next = NULL;
    return head;
}
void deletelist(struct node *head)
{
    struct node *temp = head;
    struct node *temp2 = head;
    while (temp2 != NULL)
    {
        free(temp2->functid);
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
void PrintNodes(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%s", temp->functid);
        temp = temp->next;
    }
}

int main(int argc, char *argv[])
{
    FILE *ptr;
    ptr = fopen(argv[1], "r");
    FILE *nptr;
    // Clear the contents of file.
    nptr = fopen("memtrace.out", "w");
    fclose(nptr);
    int fDesc = open("memtrace.out", O_WRONLY | O_APPEND);
    dup2(fDesc, 1);

    int a = fork();
    if (a > 0)
    {
        //Part 1
        //char* array===string
        //This will initialize 1024 input strings that the user can take
        char **array = malloc(MAX_LINE * (sizeof(char *)));
        int i;
        for (i = 0; i < MAX_LINE; i++)
        {
            array[i] = (char *)malloc(MAX_LENGTH * (sizeof(char)));
            assert(array[i] && "malloc of subarray failed");
        }
        char *line_buff = NULL;
        size_t line_buff_size;
        int linesize;
        int index = 0;
        struct node *head = NULL;
        int capacity = MAX_LINE;

        //don't know what to write in dup2

        while ((linesize = (getline(&line_buff, &line_buff_size, ptr))) >= 0)
        {
            printf("%s", line_buff);
            int l = strlen(line_buff);
            // Remove the ending newline from getline.
            if (line_buff[l-1] == '\n')
                line_buff[l-1] = '\0';
            PUSH_TRACE(line_buff);
            if (index >= capacity)
            {
                //REALLOCATE MEMORY SPACE
                capacity = 1+index;
                char **new_array = (char**)realloc(array, capacity);
                if (new_array) {
                    array = new_array;
                } else {
                    printf("\nrealloc failed\n");
                }
                printf("reallocing: %d, %p\n", index, array);
                for (int c = index; c < capacity; c++) {
                    array[c] = (char *)malloc(MAX_LENGTH * sizeof(char));
                    assert(array[c]);
                }
            }
            if (l >= MAX_LENGTH)
            {
                //REALLOCATE MEMORY SPACE
                array[index] = (char*)realloc(array[index], 2*l);
                assert(array[index] && "realloc failed");
                strcpy(array[index], line_buff);
            }
            else
            {
                strcpy(array[index], line_buff);
            }

            if (head == NULL)
            {
                head = insert_at_b(head, line_buff, index);
            }
            else //if (head != NULL)
            {
                insert_at_e(head, line_buff, index);
            }

            index = index + 1;
        }
        free(line_buff);

        for (i = 0; i < index; i++)
        {
            printf("\narray[");
            printf("%d", i);
            printf("]=");
            printf("%s", array[i]);
        }

        //free-ing the array
        for (i = 0; i < capacity; i++)
        {
            free(array[i]);
        }
        free(array);
        deletelist(head);
        for (i = 0; i < index; i++)
        {
            POP_TRACE();
        }
        free(TRACE_TOP);
        fclose(ptr);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct linkedNode{
    char* name;
    int index;
    linkedNode* next;
}linkedNode;

pushfront(char* name){
 linkedNode* node = (linkedNode*)malloc(sizeof(char));
}

popfront(){

}

key topfront(){

}

pushback(){

}
popback(){

}
key topback(){

}
delete(){

}
addbefore(node, key){

}
addafter(node, key){

}
boolean isempty(){

}
linkedNode add(linkedNode head, char* name, int indexnum){
    linkedNode* head = (linkedNode*)malloc(sizeof(char));
    if(head == NULL){
        head = head;
    }
    linkedNode* temp = head;
}


int main(int argc, char *argv[])
{
    FILE *ptr = fopen(argv[1], "r");
    char array[100][100];
    int i = 0;
    char *buffer;




    buffer = (char *)malloc(sizeof(char));
    size_t bufsize = 0;
    //size_t is always greater than 0
    int c;
    while ((c = getline(&buffer, &bufsize, ptr)) >= 0)
    {
        printf("printing c %d\n", c);
        strcpy(&array[i++], buffer);
    }

    printf("%s", &array[1]);
    free(buffer);

    return 0;
}

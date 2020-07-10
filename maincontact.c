#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ContactNode.h"

int main(){
ContactNode* head = NULL;

for(int i = 1; i < 4; i++){
    char name[100];
    char phone[100];
    printf("Person %d\n", i);
    printf("Enter name:\n");
    gets(name);
    printf("Enter phone number:\n");
    gets(phone);
    printf("You entered: %s, %s\n", name , phone);
    printf("\n");
    if(head == NULL){
        head = CreateContactNode(name, phone);
    }
    else{
        ContactNode* end = CreateContactNode(name, phone);
        InsertContactAfter(head, end);
    }
}
    PrintContactNode(head);

}
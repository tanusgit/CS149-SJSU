#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ContactNode.h"

int main(){
ContactNode* head = NULL;

for(int i = 0; i < 3; i++){
    char name[100];
    char phone[100];
    printf("enter name");
    gets(name);
    printf("enter phone number");
    gets(phone);
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
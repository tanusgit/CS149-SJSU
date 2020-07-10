#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ContactNode.h"

ContactNode* CreateContactNode(char name[], char phone[])
{
     ContactNode* temp = (ContactNode*)malloc(sizeof(ContactNode));
       strcpy(temp->contactName,  name);
       strcpy(temp->contactPhoneNum,  phone);
       temp->nextNodePtr = NULL;
       return temp;
    
}
//Insert a new node after node
ContactNode* InsertContactAfter(ContactNode* head, ContactNode* temp){
    ContactNode* temp2 = head;
        if(temp2->nextNodePtr != NULL){
            temp2 = temp2->nextNodePtr;
        }
        temp2->nextNodePtr = temp;
        temp->nextNodePtr = NULL;
        return head;
};
//Return location pointed by nextNodePtr
ContactNode *GetNextContact(){


};
//Name: Roxanne Hughes
//Phone number: 443-555-2864
void PrintContactNode(ContactNode* head)
{
    ContactNode* temp2 = head;

    while(temp2 != NULL){
        printf("Name: %s\n phone: %s\n", temp2->contactName, temp2->contactPhoneNum);
        temp2 = temp2->nextNodePtr;
    }
  
};
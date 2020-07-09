#include <stdio.h>
#include <stdlib.h>
#include "ContactNode.h"

void CreateCommandNode(ContactNode* thisNode, char name[20][20], char phone[20][20], ContactNode *nextCmd)
{
    //this is useful if you store a string (char *): strcpy(thisNode->command, cmd);
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++){
            thisNode->contactName[i][j]= name[i][j];
            strcpy(thisNode->contactName[i][j], name);
            thisNode->contactPhoneNum[i][j] = phone[i][j];
            thisNode->nextNodePtr = nextCmd;
        }
    }
    return;
}

void CreateContactNode()
{
    ContactNode head = (ContactNode*)malloc(sizeof(ContactNode));
};
//Insert a new node after node
void InsertContactAfter(){

};
//Return location pointed by nextNodePtr
ContactNode *GetNextContact(){

};
//Name: Roxanne Hughes
//Phone number: 443-555-2864
void PrintContactNode(ContactNode n)
{
    printf("Name: %s\n Phone number: %s\n", n.contactName, n.contactPhoneNum);
};
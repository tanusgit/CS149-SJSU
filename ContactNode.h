typedef struct ContactNode
{
    char contactName[50];
    char contactPhoneNum[50];
    struct ContactNode *nextNodePtr;
} ContactNode;
ContactNode* CreateContactNode(char name[], char phone[]);
ContactNode* InsertContactAfter(ContactNode* head, ContactNode* temp);
ContactNode* GetNextContact();
void PrintContactNode();

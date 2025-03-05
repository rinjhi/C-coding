//linked list deletion
#include<stdio.h>
#include<stdlib.h>

typedef struct std
{
	struct std *next;
	int data;
}Node;

Node *start=NULL;
Node* createNode(int data) {
    Node* newptr = (Node*)malloc(sizeof(Node));
    if (!newptr) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newptr->data = data;
    newptr->next = NULL;
    return newptr;
}

// Function to insert a node at the end of the list
void insertAtEnd(int data) {
    Node* newptr = createNode(data);
    if (start == NULL) {
        start = newptr;
        return;
    }
    Node* ptr = start;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newptr;
}

void deleteAtEnd()
{
	Node *ptr,*tptr;
	ptr=start;
	tptr=start;
	ptr=ptr->next;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
		tptr=tptr->next;
	}
	//printf("ptr->data   %d\n",ptr->data);
	//printf("tptr->data  %d\n",tptr->data);
	free(ptr);
	tptr->next=NULL;
}

void deleteAtBegin()
{
	Node *ptr=start;
	start=ptr->next;
	free(ptr);
}

void deleteAtPos(int pos)
{
	Node *ptr,*tptr;
	ptr=start;
	tptr=start;
	int x=1;
	ptr=ptr->next;
	while(x<pos-1)
	{
		ptr=ptr->next;
		tptr=tptr->next;
		x++;
	}
	tptr->next=ptr->next;
	free(ptr);
}

void deleteByKey(int key)
{
	Node *ptr,*tptr;
	ptr=start;
	tptr=start;
	ptr=ptr->next;
	while(ptr->data!=key)
	{
		ptr=ptr->next;
		tptr=tptr->next;
	}
	tptr->next=ptr->next;
	free(ptr);
}

void displayList() {
    if (start == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Singly Linked List: ");
    Node* ptr = start;
    while (ptr) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
int main() {
    int choice, data,pos,key;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at end\n");
        printf("2. Display list\n");
        printf("3. Delete at End\n");
        printf("4. Delete at Begining\n");
        printf("5. Delete at any Pos\n");
        printf("6. Delete by key\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;

            case 2:
                displayList();
                break;

            case 3:
            	deleteAtEnd();
                break;
            
			case 4:
                deleteAtBegin();
                break;
            case 5:
            	printf("Enter the position of data to be deleted: ");
            	scanf("%d",&pos);
                deleteAtPos(pos);
                break;
            
            case 6:
                printf("Enter the key to be deleted: ");
            	scanf("%d",&key);
                deleteByKey(key);
                break;
                
            case 7:
                printf("Exiting program.\n");
                break;    
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}


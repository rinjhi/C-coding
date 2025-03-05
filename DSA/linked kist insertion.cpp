//linked list insertion
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
// Function to insert a node at the begining
void insertAtBegin(int data) {
    Node* newptr = createNode(data);
    if (start == NULL) {
        start = newptr;
        return;
    }
    else{
	
    newptr->next=start;
    start=newptr;
        }
}

void insertAtPos(int pos,int data)
{
	Node* newptr = createNode(data);
	printf("I am at isertAtPos function");
	int x=1;
	Node *ptr=start;
	while(x<pos-1)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->next;
		
		x++;
	}
	newptr->next=ptr->next;
	ptr->next=newptr;
	//printf("%d\n",ptr->data);
}

void insertAtAfterNode(int key,int data)
{
	Node *newptr=createNode(data);
	Node *ptr=start;
	while(key!=ptr->data)
	{
		ptr=ptr->next;
	}
	newptr->next=ptr->next;
	ptr->next=newptr;
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
        printf("3. Insert at Begining\n");
        printf("4. Insert at any Pos\n");
        printf("5. Insert At after a Node\n");
        printf("6. Exit\n");
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
            	printf("Enter data to insert at begin: ");
            	scanf("%d", &data);
            	insertAtBegin(data);
                //deleteList();
                break;
            
			case 4:
                printf("Enter the position :");
                scanf("%d",&pos);
                printf("Enter the data to insert ant any pos: ");
                scanf("%d",&data);
                insertAtPos(pos,data);
                break;
            case 5:
                printf("Enter the key element to be searched: ");
                scanf("%d",&key);
                printf("Enter the data:");
                scanf("%d",&data);
                insertAtAfterNode(key,data);
                break;
            
            case 6:
                printf("Exiting program.\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}


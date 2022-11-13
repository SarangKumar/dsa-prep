#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node* prev;
    int data;
    struct node* next;
}NODE;


//function declaration
NODE* add_to_empty(NODE*, int);
NODE* insert_at_beg(NODE* head, int data);
NODE* insert_at_end(NODE* head, int data);
NODE* insert_pos(NODE* head, int data, int pos);
NODE* init_node(int data);

NODE* del_first_m1(NODE* head);
NODE* del_first_m2(NODE* head);
NODE* del_last(NODE* head);
NODE* del_post(NODE* head, int pos);

NODE* create_list(NODE*);
void display(NODE*);


int main()
{
	NODE *head=NULL;
	
	printf("\n-------------------------------------------------------\n");
	head=add_to_empty(head,45);
	printf("Display after adding to empty list \n%d",head->data);
	
	printf("\n-------------------------------------------------------\n");
	printf("Inserting at the beginning\n");
	head=insert_at_beg(head,34);
	display(head);
	
	printf("\n-------------------------------------------------------\n");
	printf("Inserting at the ending\n");
	head=insert_at_end(head,9);
	display(head);

	printf("\n-------------------------------------------------------\n");
	printf("Inserting IN Between\n");
	int pos=2;
	head=add_after_pos(head,25,pos);
	display(head);
	
	printf("\n-------------------------------------------------------\n");
	printf("creating the list\n");
	head=create_list(head);
	display(head);
	
	printf("\n-------------------------------------------------------\n");
	printf("deleted the first node from the list method 1\n");
	head=del_first_m1(head);
	display(head);
	
	printf("\n-------------------------------------------------------\n");
	printf("deleted the first node from the list using method 2\n");
	head=del_first_m2(head);
	display(head);
	
	printf("\n-------------------------------------------------------\n");
	printf("deleted the last node from the list\n");
	head=del_last(head);
	display(head);
	
	int pos1=2;
	printf("\n-------------------------------------------------------\n");
	printf("deleted the intermediate node from the list\n");
	head=del_pos(head,pos1);
	display(head);
	return 0;
	
}


//function definition
NODE* init_node(int data){
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->data=data;
    temp->next=temp->prev=NULL;
    return temp;
}

NODE* add_to_empty(NODE* head, int data){
    NODE* temp = init_node(data);
    head = temp;
    return head;
}

NODE* insert_at_beg(NODE* head, int data){
    NODE* temp = init_node(data);
    temp->next = head;
    head->prev = temp;

    return head;
}

NODE* insert_at_end(NODE* head, int data){
    NODE* temp = init_node(data);
    NODE* tp = head;

    while(tp->next!=NULL)
        tp=tp->next;
    
    tp->next=temp;
    temp->prev=tp;

    return head;
}

NODE* del_first_m1(NODE* head){
    head = head->next;
    free(head->prev);
    head->prev=NULL;
    return head;
}

NODE* insert_pos(NODE* head, int data, int pos){
    NODE* temp = init_node(data);
    NODE* temp3, *temp2 = head;

    if(pos==1)
        insert_at_beg(head, data);
    
    while(pos>1){
        pos--;
        temp2=temp2->next;
    }

    temp3 = temp2->prev;
    temp->prev = temp3;
    temp->next = temp2;
    temp3->next = temp;
    temp2->prev=temp;
}

NODE* del_first_m2(NODE* head){
    //by creating temp variable
    NODE* temp = head;
    head = head->next;
    free(temp);
    temp=NULL;
    head->prev=NULL;
    return head;
}

NODE* del_last(NODE* head){
    NODE* temp = head;
    NODE* temp2;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp2 = temp->prev;
    temp2->next = NULL;
    free(temp);
    temp=NULL;

    return head;
}

NODE* del_post(NODE* head, int pos){
    NODE* temp=head;
    NODE* temp2;
    while(pos>1){
        pos--;
        temp=temp->next;
    }

    temp2=temp->prev;
    temp2->next=temp->next;
    temp->next->prev=temp2;

    return head;
}

NODE* create_list(NODE* head)
{
	int n,data,i;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	
	if(n==0)
		return head;
	
	//creating complete list at a time 
	for(i=1;i<=n;i++)
	{
		printf("Enter the element for the node %d:",i);
		scanf("%d",&data);
		head=insert_at_end(head,data);
	}
	return head;
}

void display(NODE* head)
{
	if(head!=NULL)
	{
		NODE *ptr=head;
		while(ptr != NULL)
		{
			printf("%d\t",ptr->data);
			ptr = ptr->next;
		}
	}
}

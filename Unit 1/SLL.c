#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} node;

node *front_add(int, node *);
node *end_add(int, node *);
node *front_del(node *);
node *end_del(node *);
node *pos_add(int, int, node *);
node *pos_del(int, node *);
void display(node *);

int main()
{
    node *list = NULL;
    int data;
    int choice;
    while (1)
    {
        printf("\n\nMain Menu\n\n");
        printf("1. Insert element to the front\n");
        printf("2. Insert element to the end\n");
        printf("3. Delete element at front\n");
        printf("4. Delete element from the end\n");
        printf("5. Insert at any position\n");
        printf("6. Delete element from any position\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter number: ");
            scanf("%d", &data);
            list = front_add(data, list);
            // display(list);
            break;
        }
        case 2:
        {
            printf("Enter number: ");
            scanf("%d", &data);
            list = end_add(data, list);
            // display(list);
            break;
        }
        case 7:
        {
            display(list);
            break;
        }
        case 8:
        {
            return 0;
        }
        default:
        {
            printf("Invalid input\n");
            continue;
        }
        }
    }

    return 0;
}

node *front_add(int x, node *list)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->info = x;
    temp->next = list;
    return temp;
}

node *end_add(int x, node *list)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->info = x;
    temp->next = NULL;

    if (temp == NULL)
    {
        temp->next = NULL;
    }
    else
    {
        node *tp = list;
        while (tp->next != NULL)
            tp = tp->next;
        tp->next = temp;
    }
    return temp;
}

void display(node *list)
{
    node *tp = list;
    if (tp->next == NULL)
    {
        printf("List is empty");
    }
    else
    {
        while (tp->next != NULL)
        {
            printf("%d -> ", tp->info);
            tp = tp->next;
        }
    }
    return;
}

node *pos_add(int pos, int data, node *list)
{
    node *temp = malloc(sizeof(node));
    temp->info = data;
    temp->next = NULL;

    if (list == NULL)
    {
        list = temp;
        return list;
    }

    node* tp = list;

    for(int count=1; count<=pos; count++){
        tp = tp->next;
    }

    node* tp2 = tp->next;
    temp->next = tp2;
    tp->next=temp;

    return list;
}
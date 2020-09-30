// #include<stdio.h>
// #include<stdlib.h>

// struct Node
// {
//    int data;
//    struct Node *next;
// }*front = NULL,*rear = NULL;

// void insert(int);
// void delete();
// void display();

// void main()
// {
//    int choice, value;

//    while(1)
//    {
//       printf("\nMENU \n");
//       printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
//       printf("Enter your choice: ");
//       scanf("%d",&choice);
//       switch(choice)
//       {
//         case 1: printf("Enter the value to be insert: ");
//                 scanf("%d", &value);
//                 insert(value);
//                 break;
//         case 2: delete();
//                 break;
//         case 3: display();
//                 break;
//         case 4: exit(0);

//         default: printf("\nWrong selection!!! Please try again!!!\n");
//       }
//    }
// }
// void insert(int value)
// {
//    struct Node *newNode;
//    newNode = (struct Node*)malloc(sizeof(struct Node));
//    newNode->data = value;
//    newNode -> next = NULL;
//    if(front == NULL)
//       front = rear = newNode;
//    else
//    {
//       rear -> next = newNode;
//       rear = newNode;
//    }

// }
// void delete()
// {
//    if(front == NULL)
//       printf("\nQueue is Empty!!!\n");
//    else
//    {
//       struct Node *temp = front;
//       front = front -> next;
//       printf("\nDeleted element: %d\n", temp->data);
//       free(temp);
//    }
// }
// void display()
// {
//    if(front == NULL)
//       printf("\nQueue is Empty!!!\n");
//    else{
//       struct Node *temp = front;
//       while(temp->next != NULL)
//       {
//         printf("%d ",temp->data);
//         temp = temp -> next;
//       }
//       printf("%d \n",temp->data);
//    }
// }

#include <stdio.h>
#include <stdlib.h>

struct QNode
{
   int key;
   struct QNode *next;
};

struct Queue
{
   struct QNode *front, *rear;
};

struct QNode *newNode(int k)
{
   struct QNode *temp = (struct QNode *)malloc(sizeof(struct QNode));
   temp->key = k;
   temp->next = NULL;
   return temp;
}

struct Queue *createQueue()
{
   struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
   q->front = q->rear = NULL;
   return q;
}

void enQueue(struct Queue *q, int k)
{

   struct QNode *temp = newNode(k);

   if (q->rear == NULL)
   {
      q->front = q->rear = temp;
      return;
   }

   q->rear->next = temp;
   q->rear = temp;
}

void deQueue(struct Queue *q)
{

   if (q->front == NULL)
      return;

   struct QNode *temp = q->front;

   q->front = q->front->next;

   if (q->front == NULL)
      q->rear = NULL;

   free(temp);
}

int main()
{
   struct Queue *q = createQueue();
   enQueue(q, 10);
   enQueue(q, 20);
   deQueue(q);
   deQueue(q);
   enQueue(q, 30);
   enQueue(q, 40);
   enQueue(q, 50);
   deQueue(q);
   printf("Queue Front : %d \n", q->front->key);
   printf("Queue Rear : %d", q->rear->key);
   return 0;
}

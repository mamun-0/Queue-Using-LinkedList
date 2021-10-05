#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*front=NULL, *rear=NULL;


void enque(int element){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp == NULL)
        return;
    temp->data = element;
    temp->next = NULL;
    if(front == NULL){
        front=rear=temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

int dequeue(){
    struct Node *temp;
    if(front == NULL)
        return -1;
    temp = front;
    front = front->next;
    int x = temp->data;
    free(temp);
    return x;
}
void Display(){
    struct Node *temp;
    temp = front;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    for(int i=0;i<10;i++)
        enque(i*10+1);

    Display();
    dequeue();
    dequeue();
    dequeue();
    Display();

    return 0;
}

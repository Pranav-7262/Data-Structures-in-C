#include<stdio.h>
#include<stdlib.h>
struct Queue {
    int f;
    int r;
    int size;
    int *a;
};
int s = 0;
typedef struct Queue Queue;
Queue *q;
int isfull() {
    return (q->r+1)%q->size==q->f;
}
int isEmpty() {
    return q->r==-1;
}
void enqueue() {
    if(isfull()){
       printf("Queue is full\n");
        return ;
    }
    else {
        s++;
        int num;
        printf("\n enter a num to insert");
        scanf("%d",&num);
        if(q->r==-1) {
            q->f=q->r=0;
            q->a[q->r] = num;
        }
        else {
            q->r = (q->r+1)%q->size;
            q->a[q->r]=num;
        }
        printf("\n  %d is enqueued",num);
    }
}
void dequeue() {
    if(isEmpty()) {
        printf("\n Queue underflow");
        return;
    }
    else {
        s--;
        int num;
        if(q->r==q->f) {
            num =q->a[q->f];
            q->f=q->r=-1;
        }
        else {
            num =q->a[q->f];
            q->f = (q->f+1)%q->size;
        }
        printf("\n %d is dequeued",num);
    }
}
void front() {
    if(isEmpty()) {
        printf("\nqueue is Empty");
        return;
    }
    printf("\n%d is front!!\n",q->a[q->f]);
}
void rear() {
    if(isEmpty()) {
        printf("\nqueue is Empty");
        return;
    }
    printf("\n%d is rear!!\n",q->a[q->r]);
}
void display() {
    if(isEmpty()) {
        printf("\n queue is empty");
        return;
    }
    int i = q->f;
    while(i!=q->size) {
        printf("%d\n",q->a[i]);
        if(i==q->r) {

            break;
        }

        i= (i+1)%q->size;

    }
    printf("\n");

}
void size() {
    printf("\n the size is %d",s);
}
int main() {

    q = (Queue*)malloc(sizeof(Queue));
    q->r=q->f=-1;
    printf("\n enter size of queue:");
    scanf("%d",&q->size);
    q->a =(int*)malloc(q->size*sizeof(int));
    int ch;
    while(1) {
        printf("\n Enter operations 1.enqueue 2.dequeue 3.Front 4.Rear 5.display 6.size 7.exit \n");
        scanf("%d",&ch);
        switch(ch) {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            front();
            break;
        case 4:
            rear();
            break;
        case 5:
            display();
            break;
        case 6:
            size();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("\nEnter a valid choice ");

        }
    }
    return 0;

} 
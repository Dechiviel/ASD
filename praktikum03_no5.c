#include <stdio.h>
#include <string.h>
#define MAXQ 20

typedef struct{
  int nrp;
  char name[50];
  int grade;
} Mhs;
typedef struct{
  Mhs item[MAXQ];
  int front;
  int rear;
  int count;
} PQueue;

void init(PQueue *q) { q->front = q->rear = q->count = 0; }
int full(PQueue q) { return q.count == MAXQ; }
int empty(PQueue q) { return q.count == 0; }
void swap (Mhs *a, Mhs *b) {
  Mhs temp = *a;
  *a = *b;
  *b = temp;
}
void sort(PQueue *q, int index) {
  if (index == q->front) return;
  else if (q->item[index].grade > q->item[(index-1) % MAXQ].grade) {
    swap(&q->item[index], &q->item[(index-1) % MAXQ]);
    sort(q, (index-1) % MAXQ);
  }
}
void enqueue(PQueue *q, Mhs x) {
  if (!full(*q)) {
    q->item[q->rear] = x;
    sort(q, q->rear);
    q->rear = ++q->rear % MAXQ;
    q->count++;
  }
  else printf("\nQUEUE IS FULL!\n");
}
Mhs dequeue(PQueue *q) {
  Mhs temp;
  if (!empty(*q)) {
    q->count--;
    temp = q->item[q->front];
    q->front = ++q->front % MAXQ;
    return temp;
  }
  else printf("\nQUEUE IS EMPTY!\n");
}

void main()
{
  PQueue q; init(&q);
  Mhs x;
  char cmd[6];
  printf("PRIORITY QUEUE\n");
  do
  {
    printf("\nType 'enq' to enqueue, '*' to dequeue, or 'exit' to exit\n > ");
    scanf("%s", cmd); fflush(stdin);

    if(strcmp(cmd, "enq") == 0) {
      printf("Insert NRP: \n > ");
      scanf("%d", &x.nrp); fflush(stdin);
      printf("Insert Name: \n > ");
      gets(x.name); fflush(stdin);
      printf("Insert Mark: \n > ");
      scanf("%d", &x.grade); fflush(stdin);
      enqueue(&q, x);
    }
    else if(strcmp(cmd, "*") == 0) {
      x = dequeue(&q);
      printf("NRP  : %d\n", x.nrp);
      printf("Name : %s\n", x.name);
      printf("Mark : %d\n", x.grade);
    }
    else if(strcmp(cmd, "exit") == 0) { break; }
    else printf("UNKNOWN STATEMENT\n");
  }
  while (strcmp(cmd, "exit") != 0);
}
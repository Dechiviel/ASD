#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXQ 5

typedef char ItemType;
typedef struct{
  ItemType item[MAXQ];
  int front;
  int rear;
  int count;
} Queue;

void init(Queue *q) { q->front = q->rear = q->count = 0; }
int full(Queue q) { return q.count == MAXQ; }
int empty(Queue q) { return q.count == 0; }
void enqueue(Queue *q, ItemType x)
{
  if (!full(*q)) {
    q->item[q->rear] = x;
    q->rear = ++q->rear % MAXQ;
    q->count++;
  }
  else printf("\nQUEUE PENUH!\n"); 
}
ItemType dequeue(Queue *q)
{
  ItemType temp;
  if (!empty(*q)) {
    q->count--;
    temp = q->item[q->front];
    q->front = ++q->front % MAXQ;
    return temp;
  }
  else printf("\nQUEUE KOSONG\n");
}
int operasi(char cmd[], Queue *q)
{
  if (strcmp(cmd, "enq") == 0) {
    ItemType x;
    printf("Masukkan karakter: \n > ");
    scanf("%c", &x);
    fflush(stdin);
    enqueue(q, x);
    return 0;
  }
  else if (strcmp(cmd, "deq") == 0) {
    dequeue(q);
    return 0;
  }
  else {
    printf("Perintah tidak dikenal\n");
    return 1;
  }
}
void fillBlank(Queue *q)
{
  char tempCount = q->count;
  int tempFront = q->front;
  for (int i = 0; i < MAXQ; i++)
  {
    if(tempCount > 0)
    {
      tempFront = ++tempFront % MAXQ;
      tempCount--;
    }
    else
    {
      q->item[tempFront] = '-';
      tempFront = ++tempFront % MAXQ;
    }
  }
}
void UI(Queue *q)
{
  fillBlank(q);

  printf("\nfront     : ");
  switch(q->front)
  {
    case 0 : printf("  f  \n"); break;
    case 1 : printf("      f  \n"); break;
    case 2 : printf("          f  \n"); break;
    case 3 : printf("              f  \n"); break;
    case 4 : printf("                  f  \n"); break;
  }
  printf("isi Queue : ");
  printf("| %c | %c | %c | %c | %c |\n", q->item[0], q->item[1], q->item[2], q->item[3], q->item[4]);
  printf("rear      : ");
  switch(q->rear)
  {
    case 0 : printf("  r  \n"); break;
    case 1 : printf("      r  \n"); break;
    case 2 : printf("          r  \n"); break;
    case 3 : printf("              r  \n"); break;
    case 4 : printf("                  r  \n"); break;
  }
}

void main()
{
  printf("VISUALISASI CIRCULAR QUEUE\n");
  char cmd[6];
  Queue q; init(&q);
  do
  {
    printf("\nKetik enq untuk enqueue, deq untuk dequeue, dan exit untuk keluar\n > ");
    scanf("%s", cmd);

    if(strcmp(cmd, "exit") == 0) exit(0);

    fflush(stdin);
    if(operasi(cmd, &q) == 1) { continue; }
    else UI(&q);

  } while (strcmp(cmd, "exit") != 0);
}
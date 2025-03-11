#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXQ 10

typedef char ItemType;
typedef struct{
  ItemType item[MAXQ];
  int front;
  int rear;
  int count;
} Queue;

typedef struct{
  ItemType item[MAXQ];
  int count;
} Stack;

void initQ(Queue *q) { q->front = q->rear = q->count = 0; }
void initS(Stack *s) { s->count = 0; }
int fullQ(Queue q) { return q.count == MAXQ; }
int fullS(Stack s) { return s.count == MAXQ; }
int emptyQ(Queue q) { return q.count == 0; }
int emptyS(Stack s) { return s.count == 0; }
void enqueue(Queue *q, ItemType x)
{
  if (!fullQ(*q)) {
    q->item[q->rear] = x;
    q->rear = ++q->rear % MAXQ;
    q->count++;
  }
  else printf("\nQUEUE PENUH!\n"); 
}
void push(Stack *s, ItemType x)
{
  if (!fullS(*s)) {
    s->item[s->count++] = x;
  }
  else printf("\nSTACK PENUH!\n");
}
ItemType dequeue(Queue *q)
{
  ItemType temp;
  if (!emptyQ(*q)) {
    q->count--;
    temp = q->item[q->front];
    q->front = ++q->front % MAXQ;
    return temp;
  }
  else printf("\nQUEUE KOSONG!\n");
}
ItemType pop(Stack *s)
{
  if (!emptyS(*s)) {
    return s->item[--s->count];
  }
  else printf("\nSTACK KOSONG!\n");
}
void UI(Queue q) {
  int tempRear = q.rear-1;
  for(int i = 0; i < q.count; i++) {
    printf("%d ", q.item[tempRear]);
    tempRear == --tempRear % MAXQ;
  }
}

void main()
{
  Queue q;
  Stack s;
  char repeat;
  initQ(&q); initS(&s);
  printf("===================\nPROGRAM PARKIR");

  do{
    int choice, no_parkir, temp;
    printf("\n1. Masukkan mobil\n");
    printf("2. Keluarkan mobil\n");
    printf("Pilih: "); scanf("%d", &choice);
    fflush(stdin);

    if(choice == 1) {
      printf("\nMasukkan Nomor Parkir : "); scanf("%d", &no_parkir);
      fflush(stdin);
      enqueue(&q, no_parkir);
    }
    else if(choice == 2) {
      printf("\nNomor Parkir yang Keluar : "); scanf("%d", &no_parkir);
      fflush(stdin);
      while((temp = dequeue(&q)) != no_parkir) {
        push(&s, temp);
      }
      while(!emptyS(s)) {
        q.front = --q.front % MAXQ;
        q.item[q.front] = pop(&s);
        q.count++;
      }
    }
    else {
      printf("INVALID SYNTAX");
      repeat = 'y';
      continue;
    }
    printf("\nTAMPILAN PARKIR : "); UI(q);

    printf("\nUlangi? y/t : "); repeat = getchar();
  }
  while(repeat == 'y' || repeat == 'Y');
}
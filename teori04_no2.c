#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct simpul Node;
struct simpul {
  int data;
  Node *next;
};
typedef struct {
  Node *head;
  Node *tail;
} LinkedList;

void init(LinkedList *list) {
  list->head = NULL;
  list->tail = NULL;
}
void simpulAwal(LinkedList *list, int x)
{
  Node *baru;
  baru = (Node *)malloc(sizeof(Node));
  if (baru == NULL){
    printf("Alokasi gagal\n");
    return;
  }
  baru->data = x;
  baru->next = NULL;
  list->head = baru;
  list->tail = baru;
}
void sisipAwal(LinkedList *list, int x)
{
  Node *baru;
  baru = (Node *)malloc(sizeof(Node));
  if (baru == NULL){
    printf("Alokasi gagal\n");
    return;
  }
  baru->data = x;
  baru->next = list->head;
  list->head = baru;
}
int hapusAwal (LinkedList *list)
{
  int temp = list->head->data;
  Node *hapus = list->head;
  list->head = list->head->next;
  free(hapus);
  if (list->head == NULL) {
    list->tail = NULL;
  }
  return temp;
}

void push(LinkedList *list, int x) {
  if (list->head == NULL) {
    simpulAwal(list, x);
  } else {
    sisipAwal(list, x);
  }
}

int pop(LinkedList *list) {
  if (list->head == NULL) {
    printf("STACK KOSONG\n");
    return 0;
  }
  return hapusAwal(list);
}

void tampil(LinkedList *list) {
  if (list->head == NULL) {
    printf("STACK KOSONG\n");
    return;
  }
  Node *p = list->head;
  while (p != NULL) {
    printf("%d", p->data);
    if (p->next != NULL) printf(", ");
    p = p->next;
  }
  printf("\n");
}

void operasi(char cmd[10], LinkedList *list){
  if(strcasecmp(cmd, "exit") == 0) exit(0);
  else if(strcasecmp(cmd, "push") == 0) {
    printf("Masukkan angka yang ingin di-push\n> ");
    int pushItem;
    fflush(stdin);
    scanf("%d", &pushItem);
    push(list, pushItem);
    puts("");
  }
  else if(strcasecmp(cmd, "pop") == 0) {
    printf("Angka yang di-pop adalah: %d\n\n", pop(list));
  }
  else if(strcasecmp(cmd, "tampil") == 0) {
    tampil(list);
  }
  else {
    printf("PERINTAH TIDAK DIKENAL!\n\n");
  }
}

void main()
{
  LinkedList list; init(&list);
  char cmd[10];
  printf("STACK DENGAN LINKED LIST\n\n");
  do
  {
    printf("Cmd : push, pop, tampil, exit\n> ");
    fflush(stdin);
    scanf("%s", cmd);

    operasi(cmd, &list);
  } while(1);
}
#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul
{
  int data;
  Node *next;
};
typedef struct
{
  Node *head;
  Node *tail;
} LinkedList;

void simpulAwal(LinkedList *list, int x)
{
  Node *baru;
  baru = (Node *)malloc(sizeof(Node));
  baru->data = x;
  baru->next = NULL;
  list->head = baru;
  list->tail = baru;
}
void cetak(LinkedList list)
{
  Node *p = list.head;
  while (p != NULL)
  {
    printf("%d, ", p->data);
    p = p->next;
  }
  printf("\n");
}
void sisipAwal(LinkedList *list, int x)
{
  Node *baru;
  baru = (Node *)malloc(sizeof(Node));
  baru->data = x;
  baru->next = list->head;
  list->head = baru;
}
void sisipAkhir(LinkedList *list, int x)
{
  Node *baru;
  baru = (Node *)malloc(sizeof(Node));
  baru->data = x;
  baru->next = NULL;
  if (list->head == NULL)
  {
    list->head = baru;
    list->tail = baru;
  }
  else
  {
    list->tail->next = baru;
    list->tail = baru;
  }
}
void sisipSebelum(LinkedList *list, int sebelum, int x)
{
  Node *baru;
  baru = (Node *)malloc(sizeof(Node));
  baru->data = x;
  baru->next = NULL;
  if (list->head == NULL) return;
  else if (list->head->data == sebelum)
  {
    sisipAwal(list, x);
  }
  else 
  {
    Node *before = list->head;
    while (before->next->data != sebelum && before->next != NULL)
    before = before->next;
    if(before->next == NULL) return;
    baru->next = before->next;
    before->next = baru;
  }
}
void sisipSetelah(LinkedList *list, int setelah, int x)
{
  Node *baru;
  Node *after = list->head;
  baru = (Node *)malloc(sizeof(Node));
  baru->data = x;
  baru->next = NULL;
  if (list->head == NULL) return;
  else
  {
    while (after->data != setelah && after != NULL)
      after = after->next;
    if(after == NULL) return;
    baru->next = after->next;
    after->next = baru;
  }
}
void hapusAwal(LinkedList *list)
{
  if (list->head == NULL)
    return;
  Node *hapus = list->head;
  list->head = list->head->next;
  free(hapus);
  if (list->head == NULL)
  {
    list->tail = NULL;
  }
}
void hapusAkhir(LinkedList *list)
{
  if (list->head == NULL)
    return;
  if (list->head == list->tail)
  {
    free(list->tail);
    list->head = NULL;
    list->tail = NULL;
  }
  else
  {
    Node *p = list->head;
    while (p->next != list->tail)
    {
      p = p->next;
    }
    free(list->tail);
    list->tail = p;
    list->tail->next = NULL;
  }
}
void hapusNode(LinkedList *list, int x)
{
  if (list->head == NULL) return;
  Node *p = list->head;
  while (p->next->data != x && p->next != NULL)
  {
    p = p->next;
  }
  if (p->next == NULL) return;
  Node *hapus = p->next;
  p->next = p->next->next;
  free(hapus);
}
void main()
{
  LinkedList list;
  int choose, dt, nodeDt;
  char repeat;
  simpulAwal(&list, 10);
  do
  {
    printf("1. Sisip Awal\n2. Sisip Akhir\n3. Sisip Sebelum\n4. Sisip Setelah\n5. Hapus Awal\n6. Hapus Akhir\n7. Hapus Node\n");
    printf("Pilih: ");
    fflush(stdin);
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
      printf("Data: ");
      fflush(stdin);
      scanf("%d", &dt);
      sisipAwal(&list, dt);
      break;
    case 2:
      printf("Data: ");
      fflush(stdin);
      scanf("%d", &dt);
      sisipAkhir(&list, dt);
      break;
    case 3:
      printf("Sebelum: ");
      fflush(stdin);
      scanf("%d", &nodeDt);
      printf("Data: ");
      fflush(stdin);
      scanf("%d", &dt);
      sisipSebelum(&list, nodeDt, dt);
      break;
    case 4:
      printf("Setelah: ");
      fflush(stdin);
      scanf("%d", &nodeDt);
      printf("Data: ");
      fflush(stdin);
      scanf("%d", &dt);
      sisipSetelah(&list, nodeDt, dt);
      break;
    case 5:
      hapusAwal(&list);
      break;
    case 6:
      hapusAkhir(&list);
      break;
    case 7:
      printf("Node: ");
      fflush(stdin);
      scanf("%d", &nodeDt);
      hapusNode(&list, nodeDt);
      break;
    default:
      printf("Pilihan tidak tersedia\n");
      break;
    }
    cetak(list);
    printf("Ulangi? (y/n) ");
    fflush(stdin);
    repeat = getchar();
  } while (repeat == 'y');

  // sisipAwal(&list, 100);
  // sisipAwal(&list, 20);
  // sisipAkhir(&list, 40);
  // cetak(list);
}
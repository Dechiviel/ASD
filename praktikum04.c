#include <stdio.h>
#include <stdlib.h>

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
void sisip(LinkedList *list, int x) {
  Node *baru;
  baru = (Node *)malloc(sizeof(Node));
  baru->data = x;
  baru->next = NULL;
  if (list->head == NULL) {
    list->head = baru;
    list->tail = baru;
  } 
  else 
  {
    Node *before = list->head;
    Node *after = list->head;
    while(after != NULL && after->data < x && after->data != x) {
      before = after;
      after = after->next;
    }
    if(after == NULL) {
      list->tail->next = baru;
      list->tail = baru;
    }
    else if(after->data == x) {
      free(baru);
      printf("\nData Sudah Tersedia\n");
      return;
    }
    else if(after == list->head) {
      baru->next = list->head;
      list->head = baru;
    }
    else {
      before->next = baru;
      baru->next = after;
    }
  }
}
void hapus(LinkedList *list, int x) 
{
  Node *node, *hapus;
  if (list->head == NULL) return;
  else {
    node = list->head;
    hapus = node;
  }
  if (node->data == x && node->next != NULL) {
    hapus = node;
    list->head = node->next;
    free(hapus);
    return;
  }
  else if(node->data == x && node->next == NULL) {
    free(node);
    list->head = NULL;
    list->tail = NULL;
    return;
  }
  while(hapus != NULL && hapus->data != x) {
    node = hapus;
    hapus = hapus->next;
  }
  if(hapus == NULL) {
    printf("\nNode tidak ditemukan\n");
    return;
  }
  else if(hapus->next == NULL) {
    list->tail = node;
    list->tail->next = NULL;
    free(hapus);
  }
  else {
    node->next = hapus->next;
    free(hapus);
  }
}
void cetak(LinkedList *list) 
{
  puts("");
  if(list->head == NULL) {
    printf("LINKED LIST KOSONG\n");
    return;
  }
  Node *node = list->head;
  while(node->next != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("%d\n", node->data);
}

void main() 
{
  LinkedList list; init(&list);
  int choose, dt;
  char repeat;
  printf("SORTED LINKED LIST");
  do
  {
    printf("\n1. Sisip\n2. Hapus\nPilih : ");
    fflush(stdin);
    scanf("%d", &choose);
    switch(choose) {
      case 1:
        printf("Masukkan data: ");
        fflush(stdin);
        scanf("%d", &dt);
        sisip(&list, dt);
        break;
      case 2:
        printf("\nNode yang ingin dihapus: ");
        fflush(stdin);
        scanf("%d", &dt);
        hapus(&list, dt);
        break;
      default:
        printf("Invalid input\n");
        break;
    }
    cetak(&list);
    printf("\nUlangi? (y/n): ");
    fflush(stdin);
    repeat = getchar();
  }
  while(repeat == 'y' || repeat == 'Y');
}
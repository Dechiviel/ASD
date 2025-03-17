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
    while(after != NULL && after->data < x && after->next != x) {
      before = after;
      after = after->next;
    }
    if(after == NULL) {
      list->tail->next = baru;
      list->tail = baru;
    }
    else if(after == list->head) {
      baru->next = list->head;
      list->head = baru;
    }
    else if(after->data == x) {
      free(baru);
    }
    else {
      before->next = baru;
      baru->next = after;
    }
  }
}
void hapus(LinkedList *list, int x) 
{
  Node *node;
  if (list->head == NULL) return;
  else {
    node = list->head;
  }
  if (node->data == x) {
    Node *hapus = node;
    list->head = node->next;
    free(hapus);
  }

  while(node->next != NULL && node->next->data != x) {
    node = node->next;
  }
  if(node->next == NULL) {
    list->head = NULL;
    list->tail = NULL;
    free(node);
  }
  else {
    Node *hapus = node->next;
    node->next = hapus->next;
    free(hapus);
  }
}
void cetak(LinkedList *list) 
{
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
        printf("\nMasukkan data: ");
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
    printf("Ulangi? (y/n): ");
    fflush(stdin);
    repeat = getchar();
  }
  while(repeat == 'y' || repeat == 'Y');
}
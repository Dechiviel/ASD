#include <stdio.h>
#define MAXSTACK 50

typedef int ItemType;
typedef struct{
  ItemType item[MAXSTACK];
  int count;
} Stack;

void init(Stack *stack){
  stack->count = 0;
}
void push(Stack *stack, ItemType x){
  stack->item[stack->count++] = x;
}
ItemType pop(Stack *stack){
  return stack->item[--stack->count];
}

void desToBin(int desimal){
  Stack stack;
  init(&stack);
  while(desimal > 0){
    push(&stack, desimal % 2);
    desimal /= 2;
  }
  while(stack.count > 0)
    printf("%d", pop(&stack));
}

void desToOct(int desimal){
  Stack stack;
  init(&stack);
  while(desimal > 0){
    push(&stack, desimal % 8);
    desimal /= 8;
  }
  while(stack.count > 0)
    printf("%d", pop(&stack));
}

void desToHex(int desimal){
  Stack stack;
  init(&stack);
  while(desimal > 0){
    push(&stack, desimal % 16);
    desimal /= 16;
  }
  while(stack.count > 0){
    int temp = pop(&stack);
    temp < 10 ? printf("%d", temp) : printf("%c", temp - 10 + 'A');
  }
}

void main(){
  int desimal;
  printf("KONVERSI BILANGAN DESIMAL\n\n");
  
  printf("Masukkan bilangan desimal: "); scanf("%d", &desimal);

  printf("\nDesimal ke Biner: "); desToBin(desimal);
  printf("\nDesimal ke Oktal: "); desToOct(desimal);
  printf("\nDesimal ke Heksadesimal: "); desToHex(desimal);
}
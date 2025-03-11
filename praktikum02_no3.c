#include <stdio.h>
#include <string.h>
#define MAXSTACK 50

typedef char ItemType;
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

void reverse(char input[]){
  Stack stack;
  init(&stack);

  for(int i = 0; input[i] != '\0'; i++)
    push(&stack, input[i]);

  for(int i = 0; input[i] != '\0'; i++)
    printf("%c", pop(&stack));
}

void main(){
  char input[30];
  printf("Masukkan karakter: "); gets(input);
  printf("Hasil pembalikkan: "); reverse(input);
}
#include <stdio.h>
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

void printResult(ItemType input[]){
  Stack stack;
  init(&stack);

  for(int i = 0; input[i] != '\0'; i++)
    input[i] == '*' ? printf("%c", pop(&stack)) : push (&stack, input[i]);
}

void main(){
  char input[] = "EAS*Y*QUE***ST***IO*N***";
  printResult(input);
}
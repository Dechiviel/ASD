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

void cekPalindrom(char input[]){
  Stack stack;
  init(&stack);

  for(int i = 0; input[i] != '\0'; i++)
    push(&stack, input[i]);

  for(int i = 0; input[i] != '\0'; i++)
  {
    int temp = pop(&stack);
    if(input[i] >= 'A' && input[i] <= 'Z' && temp >= 'a' && temp <= 'z')
      temp -= 32;
    if(input[i] >= 'a' && input[i] <= 'z' && temp >= 'A' && temp <= 'Z')
      temp += 32;
    if(input[i] != temp)
    {
      printf("bukan palindrom\n");
      return;
    }
  }
  printf("palindrom\n");
}

void main(){
  char input[30];
  printf("Masukkan karakter: "); gets(input);
  printf("Kalimat adalah: "); cekPalindrom(input);
}
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

char *cekError(char str[]){
  int operand = 0, operator = 0, kurung = 0;

  if(str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/' || str[0] == '^')
    return "Notasi infix salah: tidak boleh diawali operator\n";

  for(int i = 0; str[i] != '\0'; i++){
    if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^'){
      if(str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '*' || str[i + 1] == '/' || str[i + 1] == '^')
        return "Notasi infix salah: operator tidak boleh bersebelahan\n";
      operator++;
    }
    else if(str[i] >= '0' && str[i] <= '9'){
      if(str[i + 1] >= '0' && str[i + 1] <= '9')
        return "Notasi infix salah: operand tidak boleh bersebelahan\n";
      operand++;
    }
    else if(str[i] == '(')
      kurung++;
    else if(str[i] == ')')
      kurung--;
    else if(str[i] == ' ' || str[i] == '\n')
      continue;
    else
      return "Notasi infix salah: pernyataan invalid\n";
  }
  if(kurung)
    return "Notasi infix salah: kurung tidak lengkap\n";
  else if(operand - operator < 1)
    return "Notasi infix salah: operand tidak lengkap\n";
  else if(operand - operator > 1)
    return "Notasi infix salah: operator tidak lengkap\n";
  return 0;
}

int derajat(char operator){
  if(operator == '^') return 3;
  if(operator == '*' || operator == '/') return 2;
  if(operator == '+' || operator == '-') return 1;
}

void infixToPostfix(ItemType str[]){
  Stack stack;
  init(&stack);

  for(int i = 0; str[i] != '\0'; i++){
    if(str[i] >= '0' && str[i] <= '9')
      printf("%c", str[i]);

    else if(str[i] == ' ' || str[i] == '\n')
      continue;

    else if(str[i] == '(')
      push(&stack, str[i]);
  
    else if(str[i] == ')'){
      while(stack.item[stack.count - 1] != '(')
        printf("%c", pop(&stack));
      pop(&stack);
    }
      
    else{
      while(stack.count > 0 && derajat(str[i]) <= derajat(stack.item[stack.count - 1]))
        printf("%c", pop(&stack));
      push(&stack, str[i]);
    }
  }
  while(stack.count > 0)
    printf("%c", pop(&stack));
}

void main(){
  char input[30];
  printf("Masukkan operasi infix: "); gets(input);

  char *errorCode = cekError(input);
  if(!errorCode){
    printf("\nHasil perubahan ke postfix: "); infixToPostfix(input);
  }
  else
    printf("%s", errorCode);
}
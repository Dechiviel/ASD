#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAXSTACK 30
#define MAXCHAR 30

typedef char ItemTypeInfixToPostfix;
typedef struct{
  ItemTypeInfixToPostfix item[MAXSTACK];
  int count;
} StackInfixToPostfix;

typedef int ItemTypePostfixToResult;
typedef struct{
  ItemTypePostfixToResult item[MAXSTACK];
  int count;
} StackPostfixToResult;


void initInfixToPostfix(StackInfixToPostfix *stack){
  stack->count = 0;
}
void initPostfixToResult(StackPostfixToResult *stack){
  stack->count = 0;
}
void pushInfixToPostfix(StackInfixToPostfix *stack, ItemTypeInfixToPostfix x){
  stack->item[stack->count++] = x;
}
void pushPostfixToResult(StackPostfixToResult *stack, ItemTypePostfixToResult x){
  stack->item[stack->count++] = x;
}
ItemTypeInfixToPostfix popInfixToPostfix(StackInfixToPostfix *stack){
  return stack->item[--stack->count];
}
ItemTypePostfixToResult popPostfixToResult(StackPostfixToResult *stack){
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
  if(operator == '+' || operator == '-') return 1;
  if(operator == '*' || operator == '/') return 2;
  if(operator == '^') return 3;
  return 0;
}

void infixToPostfix(char str[], char result[]){
  StackInfixToPostfix stack;
  initInfixToPostfix(&stack);
  char temp;
  int j = 0;

  for(int i = 0; str[i] != '\0'; i++){
    if(str[i] >= '0' && str[i] <= '9'){
      printf("%c", str[i]);
      result[j++] = str[i];
    }

    else if(str[i] == ' ' || str[i] == '\n')
        continue;

    else if(str[i] == '(')
        pushInfixToPostfix(&stack, str[i]);
  
    else if(str[i] == ')'){
      while(stack.item[stack.count - 1] != '('){
        temp = popInfixToPostfix(&stack);
        printf("%c", temp);
        result[j++] = temp;
      }
      popInfixToPostfix(&stack);
    }
      
    else{
      while(stack.count > 0 && derajat(str[i]) <= derajat(stack.item[stack.count - 1])){
        temp = popInfixToPostfix(&stack);
        printf("%c", temp);
        result[j++] = temp;
      }
      pushInfixToPostfix(&stack, str[i]);
    }
  }
  while(stack.count > 0){
    temp = popInfixToPostfix(&stack);
    printf("%c", temp);
    result[j++] = temp;
  }
  result[j] = '\0';
}

void postfixToResult(char str[]){
  StackPostfixToResult stack;
  initPostfixToResult(&stack);
  int opr1, opr2, temp;

  for(int i = 0; str[i] != '\0'; i++){
    if(str[i] >= '0' && str[i] <= '9')
      pushPostfixToResult(&stack, str[i] - '0');
    else{
      opr2 = popPostfixToResult(&stack);
      opr1 = popPostfixToResult(&stack);

      if(str[i] == '^')
        temp = pow(opr1, opr2);
      else if(str[i] == '*')
        temp = opr1 * opr2;
      else if(str[i] == '/')
        temp = opr1 / opr2;
      else if(str[i] == '+')
        temp = opr1 + opr2;
      else if(str[i] == '-')
        temp = opr1 - opr2;

      pushPostfixToResult(&stack, temp);
    }
  }
  while(stack.count != 0)
    printf("%d", popPostfixToResult(&stack));
}

void main(){
  char input[MAXCHAR], postfix[MAXCHAR];
  printf("Masukkan operasi infix: "); gets(input);

  char *errorCode = cekError(input);
  if(!errorCode){
    printf("\nHasil perubahan infix ke postfix: "); infixToPostfix(input, postfix);
    printf("\nHasil perhitungan notasi postfix: "); postfixToResult(postfix);
  }
  else 
    printf("%s", errorCode);
}
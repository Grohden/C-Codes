#include "stack.h"
#include "../utils.h"

void executeStackTests(int maxStackSize) {
  Stack* stack = initStack(maxStackSize);
  const int size = getMaxStackSize(stack);

  int i = 0;

  printf("\n====== Preenchendo Pilha =======\n");
  for (i = 0; i < size;i++) {
    push(stack, (int*) i);
    println("Topo : %d", (int) peek(stack));
  }

  printf("\n====== Esvaziando Pilha =======\n");
  for (i = 0; i < size; i++) {
    println("Topo : %d", (int) pop(stack));
  }

  printf("\n====== Preenchendo Pilha =======\n");
  for (i = 0; i < size; i++) {
    push(stack, (int*) i);
    println("Topo : %d", (int) peek(stack));
  }
}

// TODO escrever os testes
int main(int argc, char* argv[]) {
  executeStackTests(15);
  return 0;
}

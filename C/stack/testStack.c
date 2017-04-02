#include "stack.h"

void executeStackTests(int size) {
	Stack * stack = initStack(size);

	printf("\n====== Preenchendo Pilha =======\n");
	repeat(size + 1) {
		push(stack, i);
		println("Topo : %d", getTopValue(stack));
	}

	printf("\n====== Esvaziando Pilha =======\n");
	repeat(size + 1) {
		pop(stack);
		println("Topo : %d", getTopValue(stack));
	}

	printf("\n====== Preenchendo Pilha =======\n");
	repeat(size + 1) {
		push(stack, i);
		println("Topo : %d", getTopValue(stack));
	}

}

//TODO escrever os testes
int main(int argc, char * argv[]) {
	executeStackTests(15);
	return 0;
}

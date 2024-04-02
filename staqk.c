#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, int value) {
    stack->data[++stack->top] = value;
}

int pop(Stack *stack) {
    return stack->data[stack->top--];
}

int peek(Stack *stack) {
    return stack->data[stack->top];
}

int isStackEmpty(Stack *stack) {
    return stack->top == -1;
}

int isStackFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

int processTwoStacks(int maxSum, int stackA[], int stackB[], int n, int m) {
    Stack sA, sB;
    initializeStack(&sA);
    initializeStack(&sB);
    
    // Push elements to stacks
    for (int i = n - 1; i >= 0; i--) {
        push(&sA, stackA[i]);
    }
    for (int i = m - 1; i >= 0; i--) {
        push(&sB, stackB[i]);
    }

    int total = 0, count = 0;
    int length = n >= m ? m : n;

    for (int i = 0; i < length; i++) {
        if (total + peek(&sA) <= maxSum) {
            total += pop(&sA);
            count++;
        }
        if (total + peek(&sB) <= maxSum) {
            total += pop(&sB);
            count++;
        }
    }
    return count;
}

int main() {
    int numGames;
    scanf("%d", &numGames);

    while (numGames--) {
        int n, m, maxSum;
        scanf("%d %d %d", &n, &m, &maxSum);

        int stackA[n], stackB[m];
        for (int i = 0; i < n; i++) {
            scanf("%d", &stackA[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &stackB[i]);
        }

        int result = processTwoStacks(maxSum, stackA, stackB, n, m);
        printf("%d\n", result);
    }

    return 0;
}
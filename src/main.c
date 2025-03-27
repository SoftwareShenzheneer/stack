#include <stdlib.h>
#include "main.h"

struct Node {
  int id;
  struct Node* next;
};

struct Stack {
  struct Node* head;
};

static struct Stack* createStack(void);
static void push(struct Stack* stack, int id);
static void pop(struct Stack* stack);
static struct Node* search(struct Stack* stack, int target);
static void printStack(struct Stack* stack);
static struct Node* reverseStack(struct Stack* stack);

int main(void) {
  struct Stack* stack = createStack();
  if (stack) {
    printf("Stack created!\r\n");
  }

  printStack(stack);
  /*getchar();*/
  push(stack, 1);
  /*printStack(stack);*/
  /*getchar();*/
  push(stack, 2);
  /*printStack(stack);*/
  /*getchar();*/
  push(stack, 3);
  /*printStack(stack);*/
  /*getchar();*/
  push(stack, 4);
  /*printStack(stack);*/
  /*getchar();*/

  pop(stack);
  printStack(stack);
  getchar();
  pop(stack);
  printStack(stack);
  getchar();
  pop(stack);
  printStack(stack);
  getchar();
  pop(stack);
  printStack(stack);
  getchar();
  pop(stack);
  printStack(stack);
  getchar();
  pop(stack);
  printStack(stack);
  getchar();

  /*printStack(stack);*/
  /*push(stack, 1);*/
  /*push(stack, 2);*/
  /*push(stack, 3);*/
  /**/
  /*getchar();*/

  /*****************************************************************************************/
  /* Print the stack based on the current head - too lazy for checks this is just exercise */
  /*printf("Current stack:\r\n");*/
  /*struct Node* current = stack->head;*/
  /*while (current) {*/
  /*  printf("%d\r\n", current->id);*/
  /*  current = current->next;*/
  /*}*/
  /**/
  /*printf("\r\n");*/

  /* Print the stack based on the current NEW head - too lazy for checks this is just exercise */
  /*printf("Inversed stack:\r\n");*/
  /*struct Node* newHead = reverseStack(stack);*/
  /*while (newHead) {*/
  /*  printf("%d\r\n", newHead->id);*/
  /*  newHead = newHead->next;*/
  /*}*/
  /*****************************************************************************************/

  /*printStack(stack);*/
  /*search(stack, 3);*/
  /*search(stack, 4);*/
  /*pop(stack);*/
  /*pop(stack);*/
  /*pop(stack);*/
  /*pop(stack);*/
  /*pop(stack);*/
  /*printStack(stack);*/
  /*getchar();*/
  return 0;
}

static struct Stack* createStack(void) {
  struct Stack* new = (struct Stack*)malloc(sizeof(struct Stack));
  if (!new) {
    printf("Error allocating memory for stack, aborting..\r\n");
    exit(1);
  }
  new->head = NULL;
  return new;
}

static void push(struct Stack* stack, int id) {
  if (stack) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->id = id;
    if (!new) {
      printf("Error allocating memory for new node, aborting..\r\n");
      exit(1);
    }

    if (stack->head) {
      new->next = stack->head;
    } else {
      new->next = NULL;
    }
    stack->head = new;
    printf("Pushing %d on to stack!\r\n", new->id);
  } else {
    printf("No stack to push to..\r\n");
  }
}

static void pop(struct Stack* stack) {
  if (stack) {
    if (stack->head) {
      struct Node* temp = stack->head;
      if (temp->next) {
        printf("ID: %d\r\n", temp->id);
      } else {
        printf("Popping last: ID: %d\r\n", temp->id);
      }
      stack->head = stack->head->next;
      free(temp);
      temp = NULL;
    }
  }
}

static struct Node* search(struct Stack* stack, int target) {
  bool found = false;
  if (stack->head) {
    struct Node* current = stack->head;
    while (current) {
      if (target == current->id) {
        found = true;
        break;
      }
      current = current->next;
    }
    if (!found) {
      printf("Target %d not found!\r\n", target);
    } else {
      printf("Target %d found!\r\n", target);
    }
  }
}

static void printStack(struct Stack* stack) {
  if (stack) {
    if (stack->head) {
      struct Node* current = stack->head;
      while (current) {
        printf("ID: %d\r\n", current->id);
        current = current->next;
      }
    } else {
      printf("Stack empty, nothing to print..\r\n");
    }
  }
}

static struct Node* reverseStack(struct Stack* stack) {
  struct Node* current = NULL;
  struct Node* prev = NULL;
  struct Node* next = NULL;

  if (stack->head) {
    current = stack->head;

    while (current) {
      next = current->next;
      current->next = prev; 
      prev = current;
      current = next;
    }
  }

  return prev;
}


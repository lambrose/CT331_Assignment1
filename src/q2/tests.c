#include <stdio.h>
#include "tests.h"
#include "linkedList.h"

void runTests(){
  printf("Tests running...\n");
  listElement* l = createEl("Test String (1).", 30);
  //printf("%s\n%p\n", l->data, l->next);
  //Test create and traverse
  traverse(l);
  printf("\n");

  //Test insert after
  listElement* l2 = insertAfter(l, "another string (2)", 30);
  insertAfter(l2, "a final string (3)", 30);
  traverse(l);
  printf("\n");

  // Test delete after
  deleteAfter(l);
  traverse(l);
  printf("\n");
    
  printf("String length: %d\n", length(l));     //printing out list size
  printf("\nTests push and pop method.\n");    
  push(&l, "Push string1", 30); //checking push method
  push(&l, "Push string2", 30);    
  traverse(l); //printing ut elements
  printf("\n");
  printf("String length after push: %d\n", length(l));    
  pop(&l);//checking the pop method
  traverse(l);
  printf("String length after pop: %d\n", length(l));
  printf("\n");
    
  printf("String length: %d\n", length(l));      //printing size
  printf("\nTests enqueue and deque method.\n");    
  enqueue(&l, "enqueue string1", 30);
  enqueue(&l, "enqueue string2", 30);    //checking enqueue method
  traverse(l);
  printf("\n");
  printf("String length after enqueue: %d\n", length(l));    
  dequeue(l);   //checking dequeue method
  traverse(l);
  printf("String length after dequeue: %d\n", length(l));
  printf("\n");    
    
  printf("\nTests complete.\n");
}

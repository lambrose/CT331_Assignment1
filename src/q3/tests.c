#include <stdio.h>
#include "genericLinkedList.h"

void runTests(){
  printf("Tests running...\n");
  
  printf("\nGeneric linked list\n");
  
  char ch = 'z'; //declaring a variable of type character to be parsed into create element function
  genericListElement* l = createEl(&ch, sizeof(ch), &printChar);
  
  int in = 2;   //declaring a variable of type integer to be parsed into push method
  push(&l, &in, sizeof(in), &printInt);
  
  long lon = 10;    
  push(&l, &lon, sizeof(lon), &printLong);
  
  float flo = 1.5;  //declaring a variable of type float to be parsed into insertAfter method
  insertAfter(l, &flo, sizeof(flo), &printFloat);
    
  double doub = 52.2;   //declaring a variable of type double to be parsed into the queue
  enqueue(&l, &doub, sizeof(doub), &printDouble);
    
  char str[] = "str";
  enqueue(&l, &str, sizeof(str), &printString);

  traverse(l);
    
  printf("Size: %d\n", length(l)); //printing out the size of the list
    
  deleteAfter(l); //deleting an element
    
  traverse(l);
    
  printf("Size: %d\n", length(l)); //printing the lize afterwards
    
  pop(&l); // checking the pop method
    
  traverse(l);

  printf("Size: %d\n", length(l));    
    
  dequeue(l); //checking the dequeue method
  
  traverse(l);
    
  printf("Size: %d\n", length(l));    
  printf("\nTests complete.\n");
}

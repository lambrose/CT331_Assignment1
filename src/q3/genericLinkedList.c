#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

//Creates a new linked list element with given content of size
//Returns a pointer to the element
genericListElement* createEl(void* data, size_t size, printFunction printFN){ //added a parameter for printing
  genericListElement* e = malloc(sizeof(genericListElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  char* dataPointer = malloc(sizeof(char)*size);
  if(dataPointer == NULL){
    //malloc has had an error
    free(e); //release the previously allocated memory
    return NULL; //return NULL to indicate an error.
  }
  memmove(dataPointer,data,size);
  e->data = dataPointer;
  e->size = size;
  e->printFN = printFN;
  e->next = NULL;
  return e;
}

//Prints out each element in the list
void traverse(genericListElement* start){
  genericListElement* current = start;
  while(current != NULL){
    current->printFN(current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
genericListElement* insertAfter(genericListElement* el, void* data, size_t size, printFunction printFN){
  genericListElement* newEl = createEl(data, size, printFN);
  genericListElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}


//Delete the element after the given el
void deleteAfter(genericListElement* after){
  genericListElement* delete = after->next;
  genericListElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}

int length(genericListElement* list) 
{ 
    int count = 0;  // Initialize count 
    struct genericListElementStruct* current = list;  // Initialize current 
    while (current != NULL) 
    { 
        count++; 
        current = current->next; 
    } 
    return count; //returns the amount of elements in the list
} 

//this method adds an element to a stack
void push(genericListElement** list, void* data, size_t size, printFunction printFN) 
{
    if(sizeof(size) != 'NULL') //checks to ensure thats its not empty
    {
        genericListElement *newElement = createEl(data, size, printFN); //creating a new element with its prams
        newElement-> next = *list; //assigning the value at which it points at in the list
        *list = newElement; //setting the value
    }
    
    else
    {
        printf("Empty");
    }
    
}

//removing the element from the list
genericListElement* pop(genericListElement** list)
{
    if(sizeof(*list) != 'NULL') //check
    {
        genericListElement* hold = *list; //set the pointer at the head of the list
        *list = hold->next; //points to next
        return hold; 
    }
    else
    {
	   return *list;
    }
}

void enqueue(genericListElement** list, void* data, size_t size, printFunction printFN)
{   
    if(sizeof(size) != 'NULL') //check
    {
        genericListElement* newElement = createEl(data, size, printFN);
        newElement->next = *list;
        *list = newElement;
    }
    
    else
    {
        printf("Empty");
    }    
}

//removing an element from a queue
genericListElement* dequeue(genericListElement* list)
{
    if(sizeof(*list) != 'NULL') //check
    {
        genericListElement* current = list; //setting the pointer to the current value at which it pints to
        
        while(current->next->next != NULL) //checking its not empty
        {
          current = current -> next; //if not empty the pointer will point to the next
        }  
        
        genericListElement* last = current -> next; //finding the last element
        
        current -> next = NULL;
        
        return last;
    }
    
    else
    {
        return list;
    }
}

//These functions are used to print out specific data types
print out a specific data type 
void printChar(void* data){
  printf("%c\n", *(char*)data);
}

void printInt(void* data){
  printf("%d\n", *(int*) data);
}

void printLong(void* data){
  printf("%ld\n", *(long*)data);
}

void printFloat(void* data){
  printf("%f\n", *(float*) data);
}

void printDouble(void* data){
  printf("%lf\n", *(double*)data);
}

void printString(void* data){
  printf("%s\n", (char*)data);
}

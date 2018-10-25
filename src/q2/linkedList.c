#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

typedef struct listElementStruct{
  char* data;
  size_t size;
  struct listElementStruct* next;
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(char* data, size_t size){
  listElement* e = malloc(sizeof(listElement));
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
  strcpy(dataPointer, data);
  e->data = dataPointer;
  e->size = size;
  e->next = NULL;
  return e;
}

//Prints out each element in the list
void traverse(listElement* start){
  listElement* current = start;
  while(current != NULL){
    printf("%s\n", current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, char* data, size_t size){
  listElement* newEl = createEl(data, size);
  listElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after){
  listElement* delete = after->next;
  listElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}

int length(listElement* list) 
{ 
    int count = 0;  // Initialize count 
    struct listElementStruct* current = list;  // Initialize current elements that it points at
    while (current != NULL) 
    { 
        count++; 
        current = current->next; 
    } 
    return count; //returns the size of the list
} 


void push(listElement** list, char* data, size_t size) 
{
    if(sizeof(size) != 'NULL') //checking if the list is not empty
    {
        listElement *newElement = createEl(data, size); //since its not empty an new element will be created
        newElement-> next = *list; //then pointed to the nect place in the list
        *list = newElement; //then the element will be assigned a location
    }
    
    else
    {
        printf("Empty");
    }
    
}

listElement* pop(listElement** list)
{
    if(sizeof(*list) != 'NULL') //check
    {
        listElement* hold = *list; //set the postion in the list
        *list = hold->next; //pointing to the next element postion
        return hold;
    }
    else
    {
	   return *list;
    }
}

void enqueue(listElement** list, char* data, size_t size)
{   
    if(sizeof(size) != 'NULL') //check
    {
        listElement* newElement = createEl(data, size);
        newElement->next = *list;
        *list = newElement;
    }
    
    else
    {
        printf("Empty");
    }    
}

listElement* dequeue(listElement* list)
{
    if(sizeof(*list) != 'NULL') //check
    {
        listElement* current = list; //assigning the current postion in the list
        
        while(current->next->next != NULL) //checking for the last postion
        {
          current = current -> next; // if not the last postion then it keeps pointing
        }  
        
        listElement* last = current -> next; //finding the last element
        
        current -> next = NULL;// then setting the pointer to null
        
        return last;
    }
    
    else
    {
        return list;
    }
}

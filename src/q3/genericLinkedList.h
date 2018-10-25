#ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST

typedef void (*printFunction)(void* data);
//created a new struct with new params
typedef struct genericListElementStruct{
  void* data;
  size_t size;
  printFunction printFN;
  struct genericListElementStruct* next;
} genericListElement;

//creating the first element
genericListElement* createEl(void* data, size_t size, printFunction printFN);

//prints out elements in the list
void traverse(genericListElement* start);

//inserts an element after a given element
genericListElement* insertAfter(genericListElement* el, void* data, size_t size, printFunction printFN);

//deletes an element after a given element
void deleteAfter(genericListElement* after);

//find the size of the list
int length(genericListElement* list);

//adds an element into a stack
void push(genericListElement** list, void* data, size_t size, printFunction printFN);

//removes an element from a stack
genericListElement* pop(genericListElement** list);

//add elements into the queue
void enqueue(genericListElement** list, void* data, size_t size, printFunction printFN);

//removes elements from a queue
genericListElement* dequeue(genericListElement* list);

void printChar(void* data);
void printString(void* data);
void printInt(void* data);
void printFloat(void* data);
void printDouble(void* data);
void printLong(void* data);

#endif
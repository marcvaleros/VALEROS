#include<stdio.h>
#include<stdlib.h>
#include "CircularArrayQ.h"

/** \fn CircularArrayQueue create_array_queue();
 *  \brief Create an empty circular array queue.
*/
CircularArrayQueue create_array_queue(){
    CircularArrayQueue new;
    return new;
}


/** \fn void init_array_queue(CircularArrayQueue *list);
 *  \brief Initialize as an empty circular array queue.
 *  \param list The queue that needs to be initialize.
*/
void init_array_queue(CircularArrayQueue *list){
  list->front = 0;
  list->rear = MAX-1;
}

/** \fn bool enqueue(CircularArrayQueue *list, Type p);
 *  \brief Adds a new person element into the last element available in the current queue. Returns true for a successful operation otherwise false.
 *  \param list The current queue.
 *  \param p The person to be added in the queue.
*/
bool enqueue(CircularArrayQueue *list, Person p){
    int retval = 0;
    if(!is_full(*list)){
        list->rear = (list->rear + 1) % MAX;
        list->data[list->rear] = p;
        retval = 1;
    }
    return retval;
}

/** \fn bool dequeue(CircularArrayQueue *list);
 *  \brief Remove the first inserted element from the current queue. Returns true for a successful operation otherwise false.
 *  \param list The current queue.
*/
bool dequeue(CircularArrayQueue *list){
  int retval = 0;

  if(!is_empty(*list)){
    list->front = (list->front+1)%MAX; 
    retval = 1;
  }

  return retval;
}

/** \fn bool is_empty(CircularArrayQueue list);
 *  \brief Return true if the current list is empty otherwise false.
 *  \param list The current queue.
*/
bool is_empty(CircularArrayQueue list){
  return (list.rear + 1) % MAX == list.front;
}

/** \fn bool is_full(CircularArrayQueue list);
 *  \brief Return true if the current list is full otherwise false.
 *  \param list The current queue.
*/
bool is_full(CircularArrayQueue list){
  return (list.rear + 2) % MAX == list.front;
}

/** \fn Type front(CircularArrayQueue list);
 *  \brief Return the person in the front without removing them.
 *  \param list The current queue.
*/
Type front(CircularArrayQueue list){
  return list.data[list.front];
}



void displayQueue(CircularArrayQueue myList){
    int x;
    for(; myList.front != (myList.rear+1)%MAX; myList.front = (myList.front+1)%MAX){
        printf(" %-15s | %-15c | %-15s \n",myList.data[myList.front].name,myList.data[myList.front].sex,myList.data[myList.front].city);
    }
}

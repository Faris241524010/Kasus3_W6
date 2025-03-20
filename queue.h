/* File        : queue.h */
/* Deskripsi   : header file untuk menangani queue */
/* Dibuat oleh : Faris Ichsan Alyawa */

#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"
#include "linked.h"     

typedef struct {
	address front;
	address rear;
 } Queue;

void create_Queue (Queue **Q);
boolean is_Empty (Queue Q);
boolean is_Full (Queue Q);
void enqueue (Queue *Q, infotype X);
void dequeue (Queue *Q, infotype *X);

#endif

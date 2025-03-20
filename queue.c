/* File        : queue.c */
/* Deskripsi   : body file untuk menangani queue*/
/* Dibuat oleh :  faris ichsan alyawa */

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void create_Queue (Queue **Q)
{
    *Q = (Queue*)malloc(sizeof(Queue)); // Use *Q to allocate memory for the queue
    (*Q)->front = NULL;  // Initialize front pointer to NULL
    (*Q)->rear = NULL;   // Initialize rear pointer to NULL
}

boolean is_Empty(Queue* Q)
{
    return Q->front == NULL;  
}

boolean is_Full (Queue *Q) {
	return Q->front == Q->rear && (!isEmpty(Q->front));
}

void enqueue(Queue *Q, infotype X) {
    address PNew;
    Create_Node(&PNew);
    Isi_Node(&PNew, X);
    if (isEmpty(Q->front)) {
        Q->front = PNew;  // Jika antrian kosong, elemen pertama adalah PNew
        Q->rear = PNew;   // Rear juga menunjuk ke elemen pertama
    } else {
        Q->rear->next = PNew;  // Menyambungkan elemen baru ke belakang
        Q->rear = PNew;        // Rear berpindah ke elemen baru
    }
}

void dequeue (Queue *Q, infotype *X)
{
    if (!is_Empty(Q)) 
	{  
        Del_Awal(&Q->front, X);  
        if (isEmpty(Q->front))
       	{
			Q->rear = NULL;
		}
	} 
	else 
	{
        printf("Queue Kosong.\n");
    }
}


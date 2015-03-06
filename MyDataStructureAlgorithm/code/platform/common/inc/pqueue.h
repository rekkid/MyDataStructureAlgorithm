/*
 * pqueue.h
 *
 *  Created on: Mar 6, 2015
 *      Author: root
 */

#ifndef CODE_PLATFORM_COMMON_INC_PQUEUE_H_
#define CODE_PLATFORM_COMMON_INC_PQUEUE_H_

#include "heap.h"

/* Implement priority queues as heaps. */
#define Heap PQueue;

/* Public Interface */
#define pqueue_init heap_init

#define pqueue_destroy heap_destroy

#define pqueue_insert heap_insert

#define pqueue_extract heap_extract

#define pqueue_peek(pqueue) ((pqueue)->tree == NULL ? NULL : (pqueue)->tree[0])

#define pqueue_size heap_size

#endif /* CODE_PLATFORM_COMMON_INC_PQUEUE_H_ */

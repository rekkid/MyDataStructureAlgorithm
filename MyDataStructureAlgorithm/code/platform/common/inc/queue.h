/*
 * queue.h
 *
 *  Created on: 2015Äê2ÔÂ26ÈÕ
 *      Author: ZJ
 */

#ifndef CODE_PLATFORM_COMMON_INC_QUEUE_H_
#define CODE_PLATFORM_COMMON_INC_QUEUE_H_

#include <stdlib.h>

#include "list.h"

/* Implement quenes as linked lists. */
typedef List Queue;

/* Public Interface */
#define queue_init list_init

#define queue_destroy list_destroy

int queue_enqueue(Queue *queue, const void *data);

int queue_dequeue(Queue *queue, void **data);

#define queue_peek(queue) ((queue)->head == NULL ? NULL : (queue)->head->data)

#define queue_size list_size

#endif /* CODE_PLATFORM_COMMON_INC_QUEUE_H_ */

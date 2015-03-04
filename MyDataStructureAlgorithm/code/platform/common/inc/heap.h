/*
 * heap.h
 *
 *  Created on: Mar 5, 2015
 *      Author: ZJ
 */

#ifndef CODE_PLATFORM_COMMON_INC_HEAP_H_
#define CODE_PLATFORM_COMMON_INC_HEAP_H_

/* Define a structure for heaps. */
typedef struct Heap_ {
	int size;

	int (*compare)(const void *key1, const void *key2);
	void (*destroy)(void *data);

	void **tree;
} Heap;

/* Public Interface */
void heap_init(Heap *heap, int (*compare)(const void *key1, const void *key2),
		void (*destroy)(void *data));

void heap_destroy(Heap *heap);

int heap_insert(Heap *heap, const void *data);

int heap_extract(Heap *heap, void **data);

#define heap_size(heap) ((heap)->size)


#endif /* CODE_PLATFORM_COMMON_INC_HEAP_H_ */

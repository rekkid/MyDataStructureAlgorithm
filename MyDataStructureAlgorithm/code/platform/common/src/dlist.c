/*
 * dlist.c
 *
 *  Created on: 2014年11月26日
 *      Author: ZJ
 */

#include <stdlib.h>
#include <string.h>

#include "dlist.h"

/* dlist_init */
void dlist_init(DList *list, void (*destroy)(void *data)) {
	/* Initializee the list. */

	list->size = 0;
	list->destroy = destroy;
	list->head = NULL;
	list->tail = NULL;
}

/* dlist_destroy */
void dlist_destroy(DList *list) {
	void *data;

	/* Remove each element. */
	while (dlist_size(list) > 0) {
		if (dlist_remove(list, dlist_tail(list), (void **)&data) == 0
			&& list->destroy != NULL) {
			list->destroy(data);
		}
	}

	/* No operations are allowed now, but clear the structure as a precaution. */
	memset(list, 0, sizeof(list));
}

/* dlist_ins_next */
int dlist_ins_next(DList *list, DListElmt *element, const void *data) {

	return 0;
}

/* dlist_ins_prev */
int dlist_ins_prev(DList *list, DListElmt *element, const void *data) {

	return 0;
}

/* dlist_remove */
int dlist_remove(DList *list, DListElmt *element, void **data) {

}

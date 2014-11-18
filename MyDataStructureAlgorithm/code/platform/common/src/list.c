/*
 * list.c
 *
 *  Created on: 2014��10��26��
 *      Author: ZJ
 */

#include <stdlib.h>
#include <string.h>

#include "list.h"

/* list_init */
void list_int(List *list, void (*destroy)(void *data)) {
	/* Initialize the list. */

	list->size = 0;
	list->destroy = destroy;
	list->head = NULL;
	list->tail = NULL;
}


/*
 * chtbl.h
 *
 *  Created on: 2015Äê2ÔÂ27ÈÕ
 *      Author: ZJ
 */

#ifndef CODE_PLATFORM_COMMON_INC_CHTBL_H_
#define CODE_PLATFORM_COMMON_INC_CHTBL_H_

#include <stdlib.h>

#include "list.h"

/* Define a structure for chaned hash tables. */
typedef struct CHTbl_ {
	int buckets;
	int (*h)(const void *key);
	int (*match)(const void *key1, const void *key2);
	void (*destroy)(void *data);
	int size;
	List *table;
} CHTbl;

/* Public Interface */
int chtbl_init(CHTbl *htbl, int buckets, int (*h)(const void *key),
		int (*match)(const void *key1, const void *key2), void (*destroy)(void *data));

void chtbl_destroy(CHTbl *htbl);

int chtbl_insert(CHTbl *htbl, const void *data);

int chtbl_remove(CHTbl *htbl, void **data);

int chtbl_lookup(const CHTbl *htbl, void **data);

#define chtbl_size(htbl) ((htbl)->size)

#endif /* CODE_PLATFORM_COMMON_INC_CHTBL_H_ */

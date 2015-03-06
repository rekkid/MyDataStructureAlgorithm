/*
 * sort.h
 *
 *  Created on: 2015Äê3ÔÂ6ÈÕ
 *      Author: ZJ
 */

#ifndef CODE_PLATFORM_COMMON_INC_SORT_H_
#define CODE_PLATFORM_COMMON_INC_SORT_H_

int issort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2));

int qsort(void *data, int size, int esize, int i, int k, int(*compare)
		(const void *key1, const void *key2));




#endif /* CODE_PLATFORM_COMMON_INC_SORT_H_ */

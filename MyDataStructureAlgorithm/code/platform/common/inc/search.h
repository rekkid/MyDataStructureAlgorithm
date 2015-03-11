/*
 * search.h
 *
 *  Created on: Mar 6, 2015
 *      Author: root
 */

#ifndef CODE_PLATFORM_COMMON_INC_SEARCH_H_
#define CODE_PLATFORM_COMMON_INC_SEARCH_H_

int bisearch(void *sorted, const void *target, int size, int esize,
		int (*compare)(const void *key1, const void *key2));





#endif /* CODE_PLATFORM_COMMON_INC_SEARCH_H_ */

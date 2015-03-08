/*
 * bfs.h
 *
 *  Created on: Mar 9, 2015
 *      Author: root
 */

#ifndef CODE_PLATFORM_COMMON_INC_BFS_H_
#define CODE_PLATFORM_COMMON_INC_BFS_H_

#include "graph.h"
#include "list.h"

/* Define a structure for vertices in a breadth-first search. */
typedef struct BfsVertex_ {
	void *data;
	VertexColor color;
	int hops;
} BfsVertex;

/* Public Interface */
int bfs(Graph *graph, BfsVertex *start, List *hops);

#endif /* CODE_PLATFORM_COMMON_INC_BFS_H_ */

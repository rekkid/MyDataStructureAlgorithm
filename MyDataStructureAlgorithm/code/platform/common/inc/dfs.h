/*
 * dfs.h
 *
 *  Created on: Mar 9, 2015
 *      Author: root
 */

#ifndef CODE_PLATFORM_COMMON_INC_DFS_H_
#define CODE_PLATFORM_COMMON_INC_DFS_H_

#include "graph.h"
#include "list.h"

/* Define a structure for vertices in a depth-first search. */
typedef struct DfsVertex_ {
	void *data;
	VertexColor color;
} DfsVertex;

/* Public Interface */
int dfs(Graph *graph, List *ordered);

#endif /* CODE_PLATFORM_COMMON_INC_DFS_H_ */

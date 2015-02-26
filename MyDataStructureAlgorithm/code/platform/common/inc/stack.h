/*
 * stack.h
 *
 *  Created on: 2015Äê2ÔÂ26ÈÕ
 *      Author: ZJ
 */

#ifndef CODE_PLATFORM_COMMON_INC_STACK_H_
#define CODE_PLATFORM_COMMON_INC_STACK_H_

#include <stdlib.h>

#include "list.h"

/* Implement stacks as linked lists. */
typedef List Stack;

/* Public Interface */
#define stack_init list_init

#define stack_destroy list_destroy

int stack_push(Stack *stack, const void *data);

int stack_pop(Stack *stack, void **data);

#define stack_peek(stack) ((stack)->head == NULL ? NULL : (stack)->head->data)

#define stack_size list_size

#endif /* CODE_PLATFORM_COMMON_INC_STACK_H_ */

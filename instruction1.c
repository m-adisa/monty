#include "monty.h"

/**
 * _push - pushes an element to the stack
 * @stack: double pointer to the first node
 * @line_number: value of the new node
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *element = malloc(sizeof(stack_t));
	char *op;
	int num;

	if (element == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	op = strtok(NULL, DELIMS);
	if (op == NULL || stack == NULL)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = _strtol(op, line_number);
	element->n = num;
	element->prev = NULL;
	element->next = *stack;
	if (element->next != NULL)
		(element->next)->prev = element;
	*stack = element;
}

/**
 * _pall - prints all values on the stack, starting from top
 * @stack: double pointer to the firdt node
 * @line_number: value of the new node
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *element = *stack;

	UNUSED(line_number);
	while (element != NULL)
	{
		printf("%d\n", element->n);
		element = element->next;
	}
}

/**
 * _pint - prints value at top of the stack
 * @stack: double pointer to the first node
 * @line_number: value of the new node
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * _pop - removes top element of the stack
 * @stack: double pointer to the first node
 * @line_number: value of the node
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = *stack;
	(*stack) = (*stack)->next;
	free(node);
}

/**
 * _swap - swaps two elements of the stack
 * @stack: double pointer to the first node
 * @line_number: value of the node
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	UNUSED(line_number);
	if (!(*stack) || ((*stack)->next))
	{
		printf("L%u: can't sawp, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	if (tmp->next)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack) = (*stack)->prev;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktortr <viktortr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:41:29 by viktortr          #+#    #+#             */
/*   Updated: 2023/06/03 15:29:50 by viktortr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_twostacks *indexStacks)
{
	t_node	*first;
	t_node	*current;

	write(1, "rb\n", 3);
	if (is_empty2(indexStacks) || indexStacks->top2->next == NULL)
		return ;
	first = indexStacks->top2;
	current = first;
	while (current->next != NULL)
		current = current->next;
	indexStacks->top2 = first->next;
	first->next = NULL;
	current->next = first;
}

void	rr(t_twostacks *indexStacks)
{
	ra(indexStacks);
	rb(indexStacks);
	write(1, "rr\n", 3);
}

void	rra(t_twostacks *indexStacks)
{
	t_node	*prev;
	t_node	*current;

	write(1, "rra\n", 4);
	if (is_empty1(indexStacks) || indexStacks->top1->next == NULL)
		return ;
	prev = NULL;
	current = indexStacks->top1;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = indexStacks->top1;
	indexStacks->top1 = current;
}

void	rrb(t_twostacks *indexStacks)
{
	t_node	*prev;
	t_node	*current;

	write(1, "rrb\n", 4);
	if (is_empty2(indexStacks) || indexStacks->top2->next == NULL)
		return ;
	prev = NULL;
	current = indexStacks->top2;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = indexStacks->top2;
	indexStacks->top2 = current;
}

void	rrr(t_twostacks *indexStacks)
{
	rrb(indexStacks);
	rra(indexStacks);
	write(1, "rrr\n", 4);
}

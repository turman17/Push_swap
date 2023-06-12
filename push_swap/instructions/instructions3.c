/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtryason <vtryason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:43:49 by viktortr          #+#    #+#             */
/*   Updated: 2023/06/05 13:53:13 by vtryason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

t_twostacks	create_two_stacks(t_twostacks *indexStacks)
{
	t_twostacks	i;

	(void)indexStacks;
	i.top1 = NULL;
	i.top2 = NULL;
	return (i);
}

void	push1(t_twostacks *indexStacks, int data)
{
	t_node	*new_node;

	new_node = create_node(data);
	new_node->next = indexStacks->top1;
	indexStacks->top1 = new_node;
}

void	push2(t_twostacks *indexStacks, int data)
{
	t_node	*new_node;

	new_node = create_node(data);
	new_node->next = indexStacks->top2;
	indexStacks->top2 = new_node;
}

int	pop1(t_twostacks *indexStacks)
{
	int		data;
	t_node	*temp;

	if (is_empty1(indexStacks))
		return (-1);
	data = indexStacks->top1->data;
	temp = indexStacks->top1;
	indexStacks->top1 = indexStacks->top1->next;
	free(temp);
	return (data);
}

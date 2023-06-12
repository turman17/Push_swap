/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktortr <viktortr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:46:18 by viktortr          #+#    #+#             */
/*   Updated: 2023/06/03 15:29:53 by viktortr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pop2(t_twostacks *indexStacks)
{
	int		data;
	t_node	*temp;

	if (is_empty2(indexStacks))
	{
		return (-1);
	}
	data = indexStacks->top2->data;
	temp = indexStacks->top2;
	indexStacks->top2 = indexStacks->top2->next;
	free(temp);
	return (data);
}

int	is_empty1(t_twostacks *indexStacks)
{
	return (indexStacks->top1 == NULL);
}

int	is_empty2(t_twostacks *indexStacks)
{
	return (indexStacks->top2 == NULL);
}

void	sa(t_twostacks *indexStacks)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	write(1, "sa\n", 3);
	if (indexStacks->top1 == NULL || indexStacks->top1->next == NULL)
		return ;
	first = indexStacks->top1;
	second = first->next;
	third = second->next;
	indexStacks->top1 = second;
	second->next = first;
	first->next = third;
}

void	sb(t_twostacks *indexStacks)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	write(1, "sb\n", 3);
	if (indexStacks->top2 == NULL || indexStacks->top2->next == NULL)
		return ;
	first = indexStacks->top2;
	second = first->next;
	third = second->next;
	indexStacks->top2 = second;
	second->next = first;
	first->next = third;
}

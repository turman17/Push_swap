/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktortr <viktortr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:47:24 by viktortr          #+#    #+#             */
/*   Updated: 2023/06/03 15:29:45 by viktortr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_twostacks *indexStacks)
{
	write(1, "ss\n", 3);
	if (indexStacks->top1 == NULL || indexStacks->top1->next == NULL
		|| indexStacks->top2 == NULL || indexStacks->top2->next == NULL)
		return ;
	sa(indexStacks);
	sb(indexStacks);
}

void	pb(t_twostacks *indexStacks)
{
	int	data;

	write(1, "pb\n", 3);
	if (is_empty1(indexStacks))
		return ;
	data = pop1(indexStacks);
	push2(indexStacks, data);
}

void	pa(t_twostacks *indexStacks)
{
	int	data;

	write(1, "pa\n", 3);
	if (is_empty2(indexStacks))
		return ;
	data = pop2(indexStacks);
	push1(indexStacks, data);
}

void	ra(t_twostacks *indexStacks)
{
	t_node	*first;
	t_node	*current;

	write(1, "ra\n", 3);
	if (is_empty1(indexStacks) || indexStacks->top1->next == NULL)
		return ;
	first = indexStacks->top1;
	current = first;
	while (current->next != NULL)
		current = current->next;
	indexStacks->top1 = first->next;
	first->next = NULL;
	current->next = first;
}

int	ft_lstsize(t_twostacks *indexStacks, int flag)
{
	int		counter;
	t_node	*current;

	counter = 0;
	if (flag == 1)
	{
		current = indexStacks->top1;
		while (current != NULL)
		{
			current = current->next;
			counter++;
		}
	}
	if (flag == 0)
	{
		current = indexStacks->top2;
		while (current != NULL)
		{
			current = current->next;
			counter++;
		}
	}
	return (counter);
}

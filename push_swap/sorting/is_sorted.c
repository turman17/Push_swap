/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtryason <vtryason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:25:54 by viktortr          #+#    #+#             */
/*   Updated: 2023/06/05 19:52:59 by vtryason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_twostacks *indexStacks)
{
	t_node	*current;

	current = indexStacks->top1;
	while (current && current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_sorted2(t_twostacks *indexStacks)
{
	t_node	*current;

	current = indexStacks->top2;
	while (current != NULL && current->next != NULL)
	{
		if (current->data < current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

void	ft_lstclear(t_twostacks *indexStacks)
{
	t_node	*current;
	t_node	*temp;

	if (indexStacks->top1 == NULL)
		return ;
	current = indexStacks->top1;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}

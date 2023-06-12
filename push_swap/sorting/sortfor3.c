/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfor3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtryason <vtryason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:01:25 by viktortr          #+#    #+#             */
/*   Updated: 2023/06/12 16:47:43 by vtryason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_sorting_actions(t_twostacks *indexStacks, t_node *first,
		t_node *second, t_node *third)
{
	if (third->data > first->data && second->data > third->data)
	{
		rra(indexStacks);
		sa(indexStacks);
	}
	else if (first->data > second->data && third->data > first->data)
		sa(indexStacks);
	else if (second->data > third->data && first->data > second->data)
	{
		sa(indexStacks);
		rra(indexStacks);
	}
	else if (first->data > third->data && second->data > first->data)
		rra(indexStacks);
	else if (third->data > second->data && first->data > third->data)
		ra(indexStacks);
}
// 1 2 3
// 3 1 2
// 1 3 2
// 2 1 3
// 3 2 1
// 2 3 1

void	sortfor3(t_twostacks *indexStacks)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (indexStacks->top1 == NULL)
		return ;
	if (indexStacks->top1->next->next == NULL)
	{
		if (is_sorted(indexStacks) == 0)
			sa(indexStacks);
		return ;
	}
	first = indexStacks->top1;
	second = first->next;
	third = second->next;
	perform_sorting_actions(indexStacks, first, second, third);
}

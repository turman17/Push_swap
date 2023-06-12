/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfor5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtryason <vtryason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:57:03 by viktortr          #+#    #+#             */
/*   Updated: 2023/06/05 19:46:11 by vtryason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest_in_stac(t_twostacks *indexStacks)
{
	int		smallest;
	t_node	*tmp1;

	smallest = INT_MAX;
	tmp1 = indexStacks->top1;
	while (tmp1)
	{
		if (tmp1->data < smallest)
		{
			smallest = tmp1->data;
		}
		tmp1 = tmp1->next;
	}
	return (smallest);
}

void	sortfor5(t_twostacks *indexStacks)
{
	if (is_sorted(indexStacks))
		return ;
	while (ft_lstsize(indexStacks, 1) > 3)
	{
		if (indexStacks->top1->data == smallest_in_stac(indexStacks)
			|| indexStacks->top1->data == (smallest_in_stac(indexStacks) - 1))
			pb(indexStacks);
		else
			rra(indexStacks);
	}
	sortfor3(indexStacks);
	if (indexStacks->top2->data < indexStacks->top2->next->data)
		rrb(indexStacks);
	pa(indexStacks);
	pa(indexStacks);
}

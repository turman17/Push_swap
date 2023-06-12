/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfor4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktortr <viktortr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:58:06 by viktortr          #+#    #+#             */
/*   Updated: 2023/06/03 15:29:33 by viktortr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortfor4(t_twostacks *indexStacks)
{
	if (is_sorted(indexStacks))
		return ;
	while (indexStacks->top2 == NULL)
	{
		if (indexStacks->top1->data == 1)
			pb(indexStacks);
		else
			ra(indexStacks);
	}
	sortfor3(indexStacks);
	pa(indexStacks);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktortr <viktortr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 09:56:20 by viktortr          #+#    #+#             */
/*   Updated: 2023/06/06 10:07:03 by viktortr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*char_dest;
	char	*char_src;

	i = -1;
	if (!dest && !src)
		return (NULL);
	char_dest = (char *)dest;
	char_src = (char *)src;
	while (++i < n)
		char_dest[i] = char_src[i];
	return (dest);
}

void	ft_swap(void *a, void *b, size_t size)
{
	char	*temp;

	temp = malloc(size);
	if (temp == NULL)
		exit(1);
	ft_memcpy(temp, a, size);
	ft_memcpy(a, b, size);
	ft_memcpy(b, temp, size);
	free(temp);
}

int	partition(void *arr, int low, int high, size_t size)
{
	char	*arr_ptr;
	void	*pivot;
	int		i;
	void	*element;
	int		j;

	arr_ptr = (char *)arr;
	pivot = arr_ptr + high * size;
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		element = arr_ptr + j * size;
		if (compare(element, pivot) < 0)
		{
			i++;
			ft_swap(arr_ptr + i * size, element, size);
		}
		j++;
	}
	ft_swap(arr_ptr + (i + 1) * size, pivot, size);
	return (i + 1);
}

void	ft_qsort_helper(void *arr, int low, int high, size_t size)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high, size);
		ft_qsort_helper(arr, low, pi - 1, size);
		ft_qsort_helper(arr, pi + 1, high, size);
	}
}

void	ft_qsort(void *arr, int n, size_t size)
{
	ft_qsort_helper(arr, 0, n - 1, size);
}

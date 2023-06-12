/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerargc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtryason <vtryason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:28:57 by viktortr          #+#    #+#             */
/*   Updated: 2023/06/12 16:29:47 by vtryason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	skip_whitespace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	return (i);
}

int	charecters(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-'
				&& argv[i][j] != '+')
			{
				error();
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;

	i = skip_whitespace(str);
	res = 0;
	sign = 1;
	if (str[i] == '-')
		sign = sign * -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] < '0' || str[i] > '9')
		error();
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		if (res > 2147483647 || res < -2147483647)
			error();
		res = res * 10;
		res = res + (str[i] - 48);
		i++;
	}
	if (res > 2147483647 || res < -2147483647)
		error();
	return (res * sign);
}

void	duplicates(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	charecters(argc, argv);
	while (j < argc)
	{
		if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			error();
		j++;
		if (j == argc && i < argc - 2)
		{
			i++;
			j = i + 1;
		}
	}
}

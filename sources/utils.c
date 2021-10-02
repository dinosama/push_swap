/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:52:57 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/07 20:03:23 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_isnum(int nb)
{
	if (nb >= '0' && nb <= '9')
		return (1);
	return (0);
}

long long	ft_longatoi(const char *str)
{
	long long	i;
	int			neg;
	long long	stock;

	i = 0;
	neg = 1;
	stock = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (neg == -1)
			stock = (stock * 10) - (str[i] - 48);
		else
			stock = (stock * 10) + (str[i] - 48);
		i++;
	}
	return (stock);
}

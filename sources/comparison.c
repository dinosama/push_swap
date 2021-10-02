/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 04:53:50 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/12 06:55:39 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_smallest(long long *tab, int len)
{
	int			i;
	long long	temp;

	i = 1;
	temp = tab[0];
	while (i < len)
	{
		if (tab[i] < temp)
			temp = tab[i];
		i++;
	}
	return (temp);
}

int	ft_smallest_i(long long *tab, int len)
{
	int			i;
	long long	temp;
	int			save;

	i = 1;
	temp = tab[0];
	save = 0;
	while (i < len)
	{
		if (tab[i] < temp)
		{
			save = i;
			temp = tab[i];
		}
		i++;
	}
	return (save);
}

int	ft_biggest(long long *tab, int len)
{
	int			i;
	long long	temp;

	i = 0;
	temp = tab[0];
	while (i < len)
	{
		if (tab[i] > temp)
			temp = tab[i];
		i++;
	}
	return (temp);
}

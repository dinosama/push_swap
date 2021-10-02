/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:27:23 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/10 03:04:58 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_checksort(long long *tab, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (tab[i] < tab[i - 1] && i != 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_advanced_checksort(t_tab *a, int b)
{
	int			i;
	long long	*temp;
	int			len;

	if (b == 1 && a->top != 1)
		return (0);
	temp = a->tab + (a->top - 1);
	len = a->argnum - a->top + 1;
	i = 1;
	if (ft_checksort(temp, len))
		return (1);
	while (temp[i] > temp[i - 1] && i <= len)
		i++;
	if (i == len)
		return (1);
	if (i == 0 && temp[0] == ft_biggest(temp, len)
		&& ft_checksort(temp + 1, len - 1))
		return (1);
	if (ft_checksort(temp, i) && ft_checksort(temp + i, len - i)
		&& temp[len - 1] < temp[0])
		return (1);
	return (0);
}

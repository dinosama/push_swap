/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_function_chunk.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 05:33:33 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/12 07:12:46 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_search_park(t_tab *b, int value)
{
	int		previous;
	int		i;
	int		small;

	i = b->top - 1;
	previous = b->argnum - 1;
	small = ft_smallest(b->tab + b->top - 1, b->argnum - b->top + 1);
	while (i < b->argnum)
	{
		if (i != b->top - 1)
			previous = i - 1;
		if (b->tab[i] < value && b->tab[previous] > value)
			return (i);
		if (b->tab[i] < value && b->tab[previous] < b->tab[i])
			return (i);
		if (value < small && small == b->tab[previous])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_wich_chunk(int value, t_chunkinf *chunk)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (chunk->tab[i] != value && i < chunk->argnum)
		i++;
	while (i >= 0 && i < chunk->argnum)
	{
		i = i - chunk->length;
		count++;
	}
	if (count > chunk->nbr)
		count = chunk->nbr;
	return (count);
}

int	ft_check(t_tab *a, t_chunkinf *chunk)
{
	int		i;

	i = a->top - 1;
	while (i < a->argnum)
	{
		if (ft_wich_chunk(a->tab[i], chunk) == chunk->act)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_check_rev(t_tab *a, t_chunkinf *chunk)
{
	int		i;

	i = a->argnum - 1;
	while (i >= a->top - 1)
	{
		if (ft_wich_chunk(a->tab[i], chunk) == chunk->act)
			return (i);
		i--;
	}
	return (-1);
}

int	ft_compare_chunk(t_tab *a, t_chunkinf *chunk)
{
	int		up;
	int		down;

	up = ft_check(a, chunk) - (a->top - 1);
	down = (a->argnum) - ft_check_rev(a, chunk);
	if (up == 0)
		return (0);
	if (up < down)
		return (up);
	return (down * -1);
}

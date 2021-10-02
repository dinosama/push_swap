/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 04:51:24 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/12 05:22:39 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init_values(t_tab *a, int *i, int *previous, int *next)
{
	if (*i == a->top - 1)
		*previous = a->argnum - 1;
	else
		*previous = *i - 1;
	if (*i == a->argnum - 1)
		*next = a->top - 1;
	else
		*next = *i + 1;
}

int	ft_find_unsort(t_tab *a)
{
	int			i;
	int			previous;
	int			next;

	i = a->top - 1;
	while (i < a->argnum)
	{
		ft_init_values(a, &i, &previous, &next);
		if (a->tab[i] == a->small && ft_biggest_than(a, a->tab[next]))
			return (i);
		if (a->tab[i] > a->tab[next])
		{
			if (ft_care_minus(a, i))
				return (i);
		}
		if (ft_advanced_checksort(a, 0) && (((a->tab[previous] > a->tab[i]
						&& a->tab[i] < a->tab[next]))
				|| (a->tab[previous] < a->tab[i] && a->tab[i] > a->tab[next])))
			return (i);
		i++;
	}
	return (-1);
}

int	ft_find_unsort_rev(t_tab *a)
{
	int			i;
	int			previous;
	int			next;

	i = a->argnum - 1;
	while (i >= a->top - 1)
	{
		ft_init_values(a, &i, &previous, &next);
		if (a->tab[i] == a->small && a->tab[next] == a->big)
			return (i);
		if (a->tab[i] > a->tab[next])
		{
			if (ft_care_minus(a, i))
				return (i);
		}
		if (ft_advanced_checksort(a, 0) && (((a->tab[previous] > a->tab[i]
						&& a->tab[i] < a->tab[next]))
				|| (a->tab[previous] < a->tab[i] && a->tab[i] > a->tab[next])))
			return (i);
		i--;
	}
	return (-1);
}

int	ft_down(t_tab *a)
{
	int	rev;

	rev = ft_find_unsort_rev(a);
	return (rev);
}

int	ft_up(t_tab *a)
{
	int	norm;

	norm = ft_find_unsort(a);
	return (norm);
}

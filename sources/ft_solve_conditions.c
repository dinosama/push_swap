/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_conditions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 05:45:12 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/12 05:49:37 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_can_swap(t_tab *a)
{
	if (!(a->tab[a->top - 1] > a->tab[a->top]
			|| (a->tab[a->top - 1] == a->small
				&& ft_biggest_than(a, a->tab[a->top]))))
		return (0);
	if (ft_advanced_checksort(a, 0))
		return (0);
	if (a->tab[a->top] == a->small)
		return (0);
	if (ft_up(a) != 0 && ft_down(a) != 0)
		return (0);
	if (a->tab[ft_find_unsort(a)] == a->small
		&& a->tab[a->top - 1] != a->small)
		return (0);
	if (a->tab[ft_find_unsort_rev(a)] == a->small
		&& a->tab[a->top - 1] != a->small)
		return (0);
	return (1);
}

int	ft_can_up(t_tab *a)
{
	if (ft_checksort(a->tab + (a->top - 1), a->argnum - a->top + 1))
		return (0);
	if (ft_compare(a))
		return (0);
	if (ft_advanced_checksort(a, 0))
		return (0);
	return (1);
}

int	ft_can_down(t_tab *a)
{
	if (ft_checksort(a->tab + (a->top - 1), a->argnum - a->top + 1))
		return (0);
	if (!ft_compare(a))
		return (0);
	if (ft_advanced_checksort(a, 0))
		return (0);
	return (1);
}

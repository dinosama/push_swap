/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 00:56:22 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/12 06:02:57 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rearrange(t_tab *a)
{
	int	sens;

	sens = 0;
	if (ft_smallest_i(a->tab, a->argnum) > a->argnum / 2)
		sens = 1;
	while (!ft_checksort(a->tab, a->argnum))
	{
		if (sens == 0)
		{
			ft_shift_up(a, a->top - 1);
			ft_putstr("ra\n");
		}
		else
		{
			ft_shift_down(a);
			ft_putstr("rra\n");
		}
	}
}

int	ft_care_minus(t_tab *a, int updown)
{
	int	next;

	next = updown + 1;
	if (updown == a->argnum - 1)
		next = a->top - 1;
	if (a->tab[updown] == a->small || a->tab[next] == a->small)
		return (0);
	return (1);
}

int	ft_compare(t_tab *a)
{
	int	up;
	int	down;

	up = ft_up(a) - (a->top - 1);
	down = (a->argnum) - ft_down(a);
	if (down > a->argnum)
		down = -1;
	if (ft_down(a) <= (a->argnum - 1) / 2)
		down = -1;
	if (ft_up(a) > (a->argnum - 1) / 2)
		up = -1;
	if ((down == -1 || up < down) && up != -1 && ft_up(a) != 0)
		return (0);
	else if ((up == -1 || down < up) && down != -1 && ft_down(a) != 0)
		return (1);
	if (up == -1 && down == -1)
		return (-1);
	if (up == down)
		return (0);
	return (-1);
}

void	ft_solve_minus_eight(t_tab *a)
{
	a->top = 1;
	ft_find_smallbig(a);
	while (!ft_checksort(a->tab + (a->top - 1), a->argnum - a->top + 1))
	{
		if (ft_can_swap(a))
			ft_putstr("sa\n");
		if (ft_can_swap(a))
			ft_swap(a);
		if (ft_advanced_checksort(a, 0))
		{
			ft_rearrange(a);
			return ;
		}
		if (ft_can_up(a))
			ft_putstr("ra\n");
		else if (ft_can_down(a))
			ft_putstr("rra\n");
		if (ft_can_up(a))
			ft_shift_up(a, a->top - 1);
		else if (ft_can_down(a))
			ft_shift_down(a);
	}
}

void	ft_find_smallbig(t_tab *a)
{
	a->small = ft_smallest(a->tab + a->top - 1, a->argnum - (a->top - 1));
	a->big = ft_biggest(a->tab + a->top - 1, a->argnum - (a->top - 1));
}

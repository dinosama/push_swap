/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_chunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:52:24 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/12 06:42:08 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_prepare_b(t_tab *a, t_tab *b)
{
	int		up;
	int		down;

	up = ft_search_park(b, a->tab[a->top - 1]) - (b->top - 1);
	down = (b->argnum) - ft_search_park(b, a->tab[a->top - 1]);
	if (up < down || up == down)
	{
		while (ft_search_park(b, a->tab[a->top - 1]) != b->top - 1
			&& !(b->top >= b->argnum))
		{
			ft_shift_up(b, b->top - 1);
			ft_putstr("rb\n");
		}
	}
	else if (down < up)
	{
		while (ft_search_park(b, a->tab[a->top - 1]) != b->top - 1
			&& !(b->top >= b->argnum))
		{
			ft_shift_down(b);
			ft_putstr("rrb\n");
		}
	}
	ft_push(b, a);
}

void	ft_rearrange_chunk(t_tab *b)
{
	int	sens;

	sens = 0;
	if (ft_smallest_i(b->tab, b->argnum) > b->argnum / 2)
		sens = 1;
	while (b->tab[b->argnum - 1] != ft_smallest(b->tab, b->argnum))
	{
		if (sens == 1)
		{
			ft_shift_down(b);
			ft_putstr("rrb\n");
		}
		else
		{
			ft_shift_up(b, b->top - 1);
			ft_putstr("rb\n");
		}
	}
}

void	ft_rrr(t_tab *a, t_tab *b, int up, int down)
{
	if (down < up)
	{
		ft_putstr("rrr\n");
		ft_shift_down(a);
		ft_shift_down(b);
	}
	else
	{
		ft_putstr("rra\n");
		ft_shift_down(a);
	}
}

void	ft_updown_chunk(t_tab *a, t_tab *b, t_chunkinf *chunk)
{
	int		up;
	int		down;

	up = ft_search_park(b, a->tab[ft_check_rev(a, chunk)]) - (b->top - 1);
	down = (b->argnum) - ft_search_park(b, a->tab[ft_check_rev(a, chunk)]);
	if (ft_compare_chunk(a, chunk) < 0)
	{
		ft_rrr(a, b, up, down);
	}
	else if (ft_compare_chunk(a, chunk) > 0)
	{
		if (up <= down && b->top != b->argnum)
		{
			ft_putstr("rr\n");
			ft_shift_up(a, a->top - 1);
			ft_shift_up(b, b->top - 1);
		}
		else
		{
			ft_shift_up(a, a->top - 1);
			ft_putstr("ra\n");
		}
	}
}

void	ft_solve_chunk(t_tab *a, t_tab *b, t_chunkinf *chunk)
{
	a->top = 1;
	b->top = b->argnum + 1;
	while (b->top != 1)
	{
		ft_updown_chunk(a, b, chunk);
		if (chunk->act == ft_wich_chunk(a->tab[a->top - 1], chunk))
		{
			ft_prepare_b(a, b);
			ft_putstr("pb\n");
			ft_calcul_chunk(a, b, chunk);
		}
	}
	ft_rearrange_chunk(b);
	while (a->top != 1)
	{
		ft_push(a, b);
		ft_putstr("pa\n");
	}
}

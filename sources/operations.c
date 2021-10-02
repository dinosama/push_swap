/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:48:45 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/12 04:54:21 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_tab *a)
{
	int	c;

	if ((a->argnum - a->top) < 1)
		return ;
	c = a->tab[a->top - 1];
	a->tab[a->top - 1] = a->tab[a->top];
	a->tab[a->top] = c;
	a->solve = 0;
}

void	ft_push(t_tab *a, t_tab *b)
{
	if ((a->argnum - b->top) < 0)
		return ;
	a->tab[a->top - 2] = b->tab[b->top - 1];
	b->top = b->top + 1;
	a->top = a->top - 1;
}

void	ft_shift_up(t_tab *a, int top)
{
	int			i;
	long long	temp;
	int			c;

	i = a->argnum;
	temp = a->tab[a->argnum - 1];
	while (i > top + 1)
	{
		c = a->tab[i - 2];
		a->tab[i - 2] = temp;
		temp = c;
		i--;
	}
	a->tab[a->argnum - 1] = temp;
	a->solve = 1;
}

void	ft_shift_down(t_tab *a)
{
	int			i;
	long long	temp;
	int			c;

	i = a->top;
	temp = a->tab[a->top - 1];
	while (i < a->argnum)
	{
		c = a->tab[i];
		a->tab[i] = temp;
		temp = c;
		i++;
	}
	a->tab[a->top - 1] = temp;
	a->solve = 2;
}

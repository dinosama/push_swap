/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:33:56 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/12 04:52:13 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_checkerror(int ac)
{
	if (ac < 2)
		return (0);
	return (1);
}

int	ft_check_argument(int ac, char **av)
{
	int		arg;
	int		i;
	int		argnum;

	arg = 1;
	argnum = 0;
	while (arg < ac)
	{
		i = 0;
		while (av[arg][i] != 0)
		{
			if (ft_isnum(av[arg][i]))
				argnum++;
			while (ft_isnum(av[arg][i]) && av[arg][i] != 0)
				i++;
			while (av[arg][i] == ' ' && av[arg][i] != 0)
				i++;
			if (av[arg][i] == '-' && av[arg][i] != 0)
				i++;
			if (!(ft_isnum(av[arg][i])) && av[arg][i] != 0)
				return (-1);
		}
		arg++;
	}
	return (argnum);
}

int	ft_error(t_tab *a, t_tab *b, int i)
{
	ft_putstr("Error\n");
	if (i == 1)
		free(a->tab);
	if (i == 2)
	{
		free(a->tab);
		free(b->tab);
	}
	return (0);
}

void	ft_afficher(t_tab *a, t_tab *b)
{
	int	i;

	i = 0;
	ft_putstr("\nb: ");
	while (i < b->argnum)
	{
		ft_putstr(ft_itoa(b->tab[i]));
		ft_putstr(" ");
		i++;
	}
	i = 0;
	ft_putstr("\n");
	ft_putstr("\na: ");
	while (i < a->argnum)
	{
		ft_putstr(ft_itoa(a->tab[i]));
		ft_putstr(" ");
		i++;
	}
}

int	ft_biggest_than(t_tab *a, int value)
{
	int		i;
	int		big;

	i = a->top - 1;
	big = 0;
	while (i < a->argnum)
	{
		if (a->tab[i] < value && a->tab[i] != value)
			big++;
		i++;
	}
	if (big > (a->argnum - a->top) / 2)
		return (1);
	return (0);
}

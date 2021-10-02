/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:33:13 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/15 12:49:54 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long	*ft_allocate(int argnum, long long *a)
{
	a = malloc(sizeof(long) * (argnum + 1));
	if (!a)
		return (0);
	return (a);
}

int	ft_checkdup(t_tab *a)
{
	int		i;
	int		c;
	int		tmp;
	int		same;

	c = 0;
	while (c < a->argnum)
	{
		tmp = a->tab[c];
		i = 0;
		same = 0;
		while (i < a->argnum)
		{
			if (tmp == a->tab[i] && same == 1)
				return (0);
			else if (tmp == a->tab[i] && same == 0)
				same++;
			i++;
		}
		c++;
	}
	return (1);
}

int	ft_checkvalues(t_tab *a)
{
	int		i;

	i = 0;
	while (i < a->argnum)
	{
		if (a->tab[i] > 2147483647 || a->tab[i] < -2147483647 - 1)
			return (0);
		i++;
	}
	if (!ft_checkdup(a))
		return (0);
	return (1);
}

int	ft_solve(t_tab *a, t_tab *b, t_chunkinf *chunk)
{
	if (a->argnum < 8)
		ft_solve_minus_eight(a);
	else if (a->argnum >= 8 && !ft_checksort(a->tab, a->argnum))
	{
		if (!ft_init_chunk(a, chunk))
			return (ft_error(a, b, 2));
		ft_solve_chunk(a, b, chunk);
		free(chunk->tab);
	}
	free(a->tab);
	free(b->tab);
	return (0);
}

int	main(int ac, char **av)
{
	struct s_tab		a;
	struct s_tab		b;
	t_chunkinf			c;

	if (ac == 1)
		return (0);
	if (!ft_checkerror(ac))
		return (ft_error(&a, &b, 0));
	a.argnum = ft_check_argument(ac, av);
	if (a.argnum == -1)
		return (ft_error(&a, &b, 0));
	b.argnum = a.argnum;
	a.tab = ft_allocate(a.argnum, a.tab);
	if (!a.tab)
		return (ft_error(&a, &b, 0));
	b.tab = ft_allocate(a.argnum, b.tab);
	if (!b.tab)
	{
		free(a.tab);
		return (ft_error(&a, &b, 1));
	}
	ft_read_argument(ac, av, a.tab);
	if (!ft_checkvalues(&a))
		return (ft_error(&a, &b, 2));
	return (ft_solve(&a, &b, &c));
}

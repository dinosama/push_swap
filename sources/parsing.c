/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 05:24:57 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/12 05:25:58 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_read_argument(int ac, char **av, long long *tab)
{
	int		arg;
	int		i;
	int		tabincr;

	arg = 1;
	tabincr = 0;
	while (arg < ac)
	{
		i = 0;
		while (av[arg][i] != 0)
		{
			while ((av[arg][i] == ' ' || av[arg][i] == '-') && av[arg][i] != 0)
				i++;
			if (ft_isnum(av[arg][i]))
			{
				tab[tabincr] = ft_longatoi(av[arg] + i);
				if (av[arg][i - 1] == '-')
					tab[tabincr] = tab[tabincr] * -1;
				tabincr++;
			}
			while (ft_isnum(av[arg][i]) && av[arg][i] != 0)
				i++;
		}
		arg++;
	}
}

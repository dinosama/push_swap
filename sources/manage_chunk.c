/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 05:35:57 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/12 07:15:49 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_recup_chunk(t_tab *a, t_chunkinf *chunk)
{
	int			i;
	int			c;
	int			value;

	c = 1;
	chunk->tab = malloc(sizeof(long long) * (a->argnum + 1));
	if (!chunk->tab)
		return (0);
	chunk->tab[a->argnum] = 0;
	chunk->tab[0] = ft_smallest(a->tab, a->argnum);
	value = a->tab[0];
	while (c < a->argnum)
	{
		i = 0;
		value = ft_biggest(a->tab, a->argnum);
		while (i < a->argnum)
		{
			if (a->tab[i] < value && a->tab[i] > chunk->tab[c - 1])
				value = a->tab[i];
			i++;
		}
		chunk->tab[c] = value;
		c++;
	}
	return (1);
}

int	ft_init_chunk(t_tab *a, t_chunkinf *chunk)
{
	if (!ft_recup_chunk(a, chunk))
		return (0);
	chunk->nbr = 11;
	if (a->argnum <= 100)
		chunk->nbr = 5;
	chunk->argnum = a->argnum;
	chunk->act = 1;
	chunk->length = a->argnum / chunk->nbr;
	return (1);
}

void	ft_calcul_chunk(t_tab *a, t_tab *b, t_chunkinf *chunk)
{
	int		i;

	i = 0;
	while (ft_biggest(b->tab + b->top - 1, b->argnum - b->top + 1)
		 != chunk->tab[i] && i < chunk->argnum)
		i++;
	if (ft_check(a, chunk) == -1)
		chunk->act = ft_wich_chunk(chunk->tab[i + 1], chunk);
}

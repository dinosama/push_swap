/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:35:50 by aaapatou          #+#    #+#             */
/*   Updated: 2021/09/12 05:55:40 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_tab
{
	long long		*tab;
	int				top;
	int				argnum;
	int				small;
	int				big;
	int				solve;
}					t_tab;

typedef struct s_chunkinf
{
	long long		*tab;
	int				argnum;
	int				nbr;
	int				length;
	int				act;
}					t_chunkinf;

int				ft_isnum(int nb);
long long		ft_longatoi(const char *str);
int				ft_checksort(long long *tab, int len);
int				ft_check_argument(int ac, char **av);
int				ft_checkerror(int ac);
void			ft_putstr(char *str);
void			ft_putchar(char c);
int				ft_error(t_tab *a, t_tab *b, int i);
void			ft_swap(t_tab *a);
void			ft_push(t_tab *a, t_tab *b);
void			ft_shift_up(t_tab *a, int top);
int				ft_advanced_checksort(t_tab *a, int b);
void			ft_afficher(t_tab *a, t_tab *b);
int				ft_smallest(long long *tab, int len);
int				ft_biggest(long long *tab, int len);
void			ft_shift_down(t_tab *a);
int				ft_smallest_i(long long *tab, int len);
void			ft_find_smallbig(t_tab *a);
int				ft_up(t_tab *a);
int				ft_down(t_tab *a);
int				ft_care_minus(t_tab *a, int updown);
int				ft_find_unsort(t_tab *a);
int				ft_find_unsort_rev(t_tab *a);
int				ft_biggest_than(t_tab *a, int value);
int				ft_recup_chunk(t_tab *a, t_chunkinf *chunk);
int				ft_wich_chunk(int value, t_chunkinf *chunk);
int				ft_init_chunk(t_tab *a, t_chunkinf *chunk);
void			ft_solve_chunk(t_tab *a, t_tab *b, t_chunkinf *chunk);
void			ft_rearrange(t_tab *a);
void			ft_solve_minus_eight(t_tab *a);
void			ft_read_argument(int ac, char **av, long long *tab);
int				ft_search_park(t_tab *b, int value);
int				ft_check_rev(t_tab *a, t_chunkinf *chunk);
int				ft_compare_chunk(t_tab *a, t_chunkinf *chunk);
void			ft_init_values(t_tab *a, int *i, int *previous, int *next);
void			ft_calcul_chunk(t_tab *a, t_tab *b, t_chunkinf *chunk);
int				ft_can_swap(t_tab *a);
int				ft_can_up(t_tab *a);
int				ft_can_down(t_tab *a);
int				ft_compare(t_tab *a);
int				ft_check(t_tab *a, t_chunkinf *chunk);

#endif

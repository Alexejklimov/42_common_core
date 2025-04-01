/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:01:50 by oklimov           #+#    #+#             */
/*   Updated: 2025/01/21 16:13:38 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <limits.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
}	t_stack;

typedef struct s_cmove
{
	int		bestmove;
	int		tab[4];
	int		booll[4];
	int		tabmouv[4];
}	t_cmove;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_cmove	*move;
	int		counter_a;
	int		counter_b;
	int		lis_count;
}	t_data;

void	ft_free_split(char **split);
void	ft_free(t_stack *stack_a);
void	ft_free_error(t_data *stack, char **temp);
void	ft_free_error2(t_data *stack, int *array_lis, int *array_lis2);
void	ft_free_error_3(t_data *stack);
int		ft_already_sort(t_stack *lst);
int		ft_checkdouble(t_stack *lst);
int		ft_atoi2(const char *nptr, t_data *stack, char **temp);
void	ft_error(int nb);
int		ft_parsing(char *str);
t_stack	*ft_addstack(int nb, t_data *stack, char **temp);
int		ft_already_sort(t_stack *lst);
void	ft_sa_sb(t_data *stack, char c);
void	ft_push_stack(t_data *stack, char c);
void	ft_ra_rb(t_data *stack, char c);
void	ft_rotate_ra_rb(t_data *stack, t_stack *last, t_stack *head, char c);
void	ft_rra_rrb(t_data *stack, char c);
void	ft_rotate_rrb_rra(t_data *stack, t_stack *last, char c);
t_stack	*find_small_nb(t_data *stack);
void	ft_three_nb_algo_movement(t_data *stack, t_stack *small);
void	ft_big_nb_algo(t_data *stack);
t_stack	*ft_lstlaste(t_stack *lst);
void	ft_lstaddback(t_stack **lst, t_stack *new);
int		ft_find_nb_list_index(t_stack *stack, t_data *info, int nb, char c);
int		ft_verif(int nb, int *lis_tab, int sizelis);
void	ft_increase_decrease_counter(t_data *stack, char c);
int		ft_findsmalltab(int *tab);
void	ft_init_lis(t_data *stack);
void	ft_pushmin(t_data *stack);
long	ft_nb_superior_bound(t_stack *node, t_data *stack);
void	ft_countdatamove(t_data *stack, int *tab);
void	ft_best_is_rr_or_rrr(t_data *stack, int choice, int i, int j);
void	ft_best_is_ra_or_rb(t_data *stack);
void	ft_best_is_rra_or_rrb(t_data *stack);
void	ft_three_nb_algo(t_data *stack, int i);
#endif

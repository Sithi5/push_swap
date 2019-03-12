/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:16:27 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/07 16:54:09 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "miniprintf.h"

typedef struct				s_struct
{
	void					(*tab[11])(struct s_struct *stru);

	int						i;
	int						j;
	int						k;
	int						ret;
	int						ac;
	int						pile_size;
	int						flag_visu;
	int						flag_count_instru;
	int						flag_light;

	long long				lli;

	char					**av;
	char					**split;
	char					*line;

	char					*db[11];
	t_list					*pile_a;
	t_list					*pile_b;
	t_list					*tmp;
	t_list					*tmp2;
	t_list					*freelist;
	t_list					*input;

}							t_struct;

int							ft_read_input(t_struct *stru);
void						ft_set_struct(t_struct *stru);
void						ft_is_sort(t_struct *stru);

void						ft_apply_instru(t_struct *stru);

void						ft_print_piles(t_struct *stru);

int							ft_check_line(t_struct *stru);
void						ft_set_db(t_struct *stru);
int							ft_check_av_and_fill(t_struct *stru);
int							ft_check_flags(char *str, t_struct *stru);

void						ft_sa(t_struct *stru);
void						ft_sb(t_struct *stru);
void						ft_ss(t_struct *stru);
void						ft_pa(t_struct *stru);
void						ft_pb(t_struct *stru);
void						ft_ra(t_struct *stru);
void						ft_rb(t_struct *stru);
void						ft_rr(t_struct *stru);
void						ft_rra(t_struct *stru);
void						ft_rrb(t_struct *stru);
void						ft_rrr(t_struct *stru);

void						ft_error(t_struct *stru, int error);
void						ft_check_double(t_struct *stru, long long lli);
void						ft_set_struct(t_struct *stru);
void						ft_clear_struct(t_struct *stru);

void						ft_check_av_and_fill_push_swap(t_struct *stru);

int							ft_is_sort_pill_a(t_struct *stru, int size);
int							ft_is_sort_pill_b(t_struct *stru, int size);

void						ft_quick_sort(t_struct *stru);
void						ft_first_sort(t_struct *stru);
int							ft_quick_sort_push_or_rotate_first(t_struct *stru
							, int median);

void						ft_quick_sort_size_b(t_struct *stru,
							int sizetosort);
void						ft_quick_sort_refill_b(t_struct *stru
							, t_list *sizepile);
void						ft_quick_sort_push_to_a(t_struct *stru,
							int sizetosort, t_list **sizepile);
int							ft_quick_sort_push_to_a_or_rotate_b(t_struct *stru
							, int median);

void						ft_quick_sort_size_a(t_struct *stru,
							int sizetosort);
void						ft_quick_sort_refill_a(t_struct *stru
							, t_list *sizepile);
void						ft_quick_sort_push_to_b(t_struct *stru,
							int sizetosort, t_list **sizepile);
int							ft_quick_sort_push_to_b_or_rotate_a(t_struct *stru
							, int median);

void						ft_sort_pile_size_three_a(t_struct *stru);
void						ft_sort_pile_size_three_b(t_struct *stru);
void						ft_sort_three_top_elements_pile_a(t_struct *stru);
void						ft_sort_three_top_elements_pile_b(t_struct *stru);

int							ft_list_max_value(t_list *list, int size);
int							ft_list_min_value(t_list *list, int size);
int							ft_median_of_pile(t_list *list, int size);
int							ft_median_of_pile_three(t_list *list, int size);

void						ft_sort_two_first_elem_pile_a(t_struct *stru);
void						ft_sort_two_first_elem_pile_b(t_struct *stru);

void						ft_rrb_print(t_struct *stru);
void						ft_rra_print(t_struct *stru);
void						ft_rb_print(t_struct *stru);
void						ft_ra_print(t_struct *stru);
void						ft_sa_print(t_struct *stru);
void						ft_sb_print(t_struct *stru);
void						ft_pa_print(t_struct *stru);
void						ft_pb_print(t_struct *stru);
void						ft_ss_print(t_struct *stru);
void						ft_rr_print(t_struct *stru);
void						ft_rrr_print(t_struct *stru);

#endif

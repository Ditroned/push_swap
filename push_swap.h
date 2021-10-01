/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:55:25 by ppizzo            #+#    #+#             */
/*   Updated: 2021/10/01 00:10:44 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		count_sep(char *s, char c);

char	*next_word(char *s, char c);

char	*ft_word(char const *s, char c);

char	*ft_splitfct(char const *s, char c);

char	**ft_split(char const *s, char c);

int		*action_sa(int *list);

void	ft_sort_int_tab(int *tab, int size);

void	sb(int *list, int lenb);

void	sa(int *list, int lena);

void	ss(int *lista, int *listb, int lena, int lenb);

int		*list_add_elem_top(int *lista, int *lena);

int		*list_rm_elem_top(int *lista, int *lena);

void	pa(int **lista, int **listb, int *lena, int *lenb);

void	pb(int **lista, int **listb, int *lena, int *lenb);	

int		*copy_list(int *lista, int lena);

void	rra(int *lista, int *lena);

void	rrb(int *lista, int *lena);

int		*ra(int *lista, int lena);

int		*rb(int *lista, int lena);

void	printlist(int *lista, int lena);

void	last_fill(
			int **lista, int **listb, int *listacp, int *len);

void	move(int **lista, int **listb, int *len, int pos);

void	ft_rev_int_tab(int *tab, int size);

int		ft_pos_elem(int a, int *list);

int		ft_list_unique(int *tab, int len);

int		ft_isatoi(char *str);

void	chunker500(int *lista, int *listacp, int arg, int *len);
void	chunker100(int *lista, int *listacp, int arg, int *len);
void	chunker5(int *lista, int *listcp, int arg, int *len);
void	chunker5_2(int *lista, int *listcp, int *listb, int *len);
int		min_list(int *lista, int lena);
int		max_list(int *lista, int lena);
void	two_chunk_move(int **lista, int **listb, int **len, int *listacp);
void	two_chunk_move_last(int **lista, int **listb, int **len, int *listacp);
int		ft_atoi(const char *str);
void	two_chunk_move_last_500(
			int **lista, int **listb, int **len, int *listacp);
void	two_chunk_move_500(int **lista, int **listb, int **len, int *listacp);
int		check_sort(int *lista, int *listb, int len, int lena);
void	chunker3(int *lista, int *listacp, int arg, int *len);
void	two_chunk_move_inf(int **lista, int **listb, int **len, int *listacp);
void	ft_sort_integer_table(int *tab, int size);
void	two_chunk_move_500_sup(
			int **lista, int **listb, int **len, int *listacp);
void	chunker500_sup(int *lista, int *listacp, int arg, int *len);
void	ft_dispatch(int	*lista, int *listacp, int arg, int *len);
void	chunkerinf100(int *lista, int *listacp, int arg, int *len);
void	two_chunk_move_last_500_sup(
			int **lista, int **listb, int **len, int *listacp);
void	two_chunk_move_last_inf(
			int **lista, int **listb, int **len, int *listacp);

int		ft_error(int **lista);

void	ft_free(int *len, int *listacp, int **lista);

int		b(int a);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:48:06 by sroggens          #+#    #+#             */
/*   Updated: 2022/10/26 16:57:18 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}				t_node;

typedef struct s_parsing
{
	char	*fulline;
	char	**tab;
	int		*tabint;
	int		totaltab;
}				t_parsing;

typedef struct s_opti
{
	int		totalcommand;
	int		ra;
	int		rb;
	int		sa;
	int		sb;
	int		rra;
	int		rrb;
	int		pa;
	int		pb;
	int		totalarg;
}				t_opti;

typedef struct s_calcul
{
	int		justafter;
	int		testnode;
	int		actualnumber;
	int		totalmove;
	int		nextnode;
	int		nextnodeb;
	int		truehightnb;
	int		truelownb;
	int		totalmoveopti;
	int		actualtest;
	int		optimove;
	int		falserra;
	int		falserrb;
	int		truerrb;
	int		truerra;
	int		totalcountb;
	int		totalcounta;
	int		divlista;
	int		divlistb;
	int		countmoveb;
	int		moveb;
	int		countmovea;
	int		movea;
	int		doit;
}			t_calcul;

typedef struct s_setuplist
{
	int		setlistb;
	int		hightnb;
	int		lowlistnb;
	int		justafter;
}				t_setuplist;

typedef struct s_final
{
	int		bybot;
}				t_final;

typedef struct s_base
{
	t_parsing	parsing;
	t_setuplist	setuplist;
	t_opti		opti;
	t_calcul	calcul;
	t_final		finals;
}				t_base;

//**************************************************
//******************Algo_by3.c**********************
//**************************************************
void		algo3(t_node **head, t_base *base);
//**************************************************
//**************Error_management.c******************
//**************************************************
void		printtheerror(char *str);
void		exiteror(void);
//**************************************************
//******************Fill_list.c*********************
//**************************************************
void		prepalist(t_node **lista, t_base *base);
//**************************************************
//*******************Move_pa.c**********************
//**************************************************
void		optipa(t_base *base);
void		optipb(t_base *base);
void		pb(t_node **heada, t_node **headb, t_base *base);
void		pa(t_node **heada, t_node **headb, t_base *base);
//**************************************************
//*******************Move_ra.c**********************
//**************************************************
void		optira(t_base *base);
void		optirb(t_base *base);
void		ra(t_node **head, t_base *base, int nb);
void		rb(t_node **head, t_base *base, int nb);
//**************************************************
//******************Move_rra.c**********************
//**************************************************
void		optirra(t_base *base);
void		optirrb(t_base *base);
void		rra(t_node **list, t_base *base, int nb);
void		rrb(t_node **list, t_base *base, int nb);
//**************************************************
//*******************Move_sa.c**********************
//**************************************************
void		sa(t_node **head, t_base *base, int nb);
void		sb(t_node **head, t_base *base, int nb);
//**************************************************
//****************Parsing_check.c*******************
//**************************************************
void		checknodouble(t_base *base);
void		checknumber(char *str);
char		*addspace(char *argv);
void		preptab(t_base *base);
void		parsing(t_base *base, int argc, char **argv);
//**************************************************
//*************Parsing_check2.c*********************
//**************************************************
int			checkcasetab(char *test);
void		checknbontab(t_base *base);
void		checkvalid(char **argv);
long int	atoimod(const char *str);
//**************************************************
//*************Parsing_checkorder.c*****************
//**************************************************
void		checkorder(t_node **heada);
//**************************************************
//******************Tool_list.c*********************
//**************************************************
void		addnode(t_node **head, int nb);
void		addnextnode(t_node **head, t_node *new_node);
void		printthelist(t_node **head);
void		malloclistb(t_node **headb);
int			countlist(t_node **head);
//**************************************************
//*****************Tool_printf.c********************
//**************************************************
void		ft_putcharprintf(char c, int *counter);
int			ft_printf(const char *txt, ...);
//**************************************************
//****************Tool_printf2.c********************
//**************************************************

void		ft_selectnextwords(va_list params, char txt, int *count);
//**************************************************
//****************Tool_split.c**********************
//**************************************************
char		**ft_split(char const *s, char c);
//**************************************************
//***************Tool_utils.c***********************
//**************************************************
int			ft_strlen(const char *str);
int			ft_atoi(const char *str);
char		*ft_strdup(char *src);
char		*ft_strjoin(char *s1, char *s2);
//**************************************************
//*****************Write_opti.c*********************
//**************************************************
void		setvalueopti(t_base *base);
void		printnoopti(t_base *base);
void		printoptibis(t_base *base);
void		printopti(t_base *base);
void		writeopti(t_base *base);
//**************************************************
//****************Write_opti2.c*********************
//**************************************************
void		seekopti(t_base *base);
void		printfirstbis(t_base *base);
void		printfirstbis2(t_base *base);
void		printfirstbis1(t_base *base);
void		printfirst(t_base *base);
//**************************************************
//***************Final_placement.c******************
//**************************************************
void		countbybot(t_node **heada, t_base *base);
void		finalplacement(t_node **heada, t_base *base);
//**************************************************
//******************Algo_otherbis.c*****************
//**************************************************
void		bigandlownb(t_node **heada, t_base *base);
int			searchfrombotom(t_node **heada, t_base *base);
int			searchfromtop(t_node **heada, t_base *base);
void		searchafter(t_node **heada, t_base *base);
void		nextnodetopush(t_node **heada, t_node **headb, t_base *base);
//**************************************************
//********************Algo_other1.c*****************
//**************************************************
void		algoother1(t_node **heada, t_node **headb, t_base *base);
void		algootherpart1(t_node **heada, t_node **headb, t_base *base);
void		algootherpart2(t_node **heada, t_node **headb, t_base *base);
void		algootherpart3(t_node **heada, t_node **headb, t_base *base);
//**************************************************
//********************Algo_other2.c*****************
//**************************************************
void		divlist(t_node **heada, t_node **headb, t_base *base);
void		nextnodetopushbis(t_node **heada, t_node **headb, t_base *base);
int			calculmovelista(t_node **heada, t_base *base);
int			setjalgo(t_node **headb, t_base *base, int j, int i);
void		setvalueforalgo(t_base *base, int j);
//**************************************************
//*******************parsingpushswap.c**************
//**************************************************
void		parsing1(t_base *base, char **argv, int argc);
void		checknotnull(char **argv);
void		parsing2(t_base *base, char **argv, int argc);
char		*deletelastspace(char *str);
#endif

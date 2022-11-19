/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing_pushswap1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:08:14 by sroggens          #+#    #+#             */
/*   Updated: 2022/10/23 15:44:12 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing1(t_base *base, char **argv, int argc)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 0)
			exiteror();
		tmp = addspace(argv[i]);
		if (!base->parsing.fulline)
			base->parsing.fulline = ft_strdup(tmp);
		else
			base->parsing.fulline = ft_strjoin(base->parsing.fulline, tmp);
		i++;
	}
	base->parsing.tab = ft_split(base->parsing.fulline, ' ');
}

void	parsing2(t_base *base, char **argv, int argc)
{
	parsing1(base, argv, argc);
	preptab(base);
	checknodouble(base);
	checkvalid(argv);
	checknbontab(base);
	setvalueopti(base);
}

void	checknotnull(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 0)
			j++;
		i++;
	}
	if (j == 0)
		exit(0);
}

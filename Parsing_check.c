/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 08:26:16 by sroggens          #+#    #+#             */
/*   Updated: 2022/10/23 15:43:13 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checknodouble(t_base *base)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (i < base->parsing.totaltab)
	{
		while (j < base->parsing.totaltab)
		{
			if (base->parsing.tabint[i] == base->parsing.tabint[j])
				exiteror();
			j++;
		}
		i++;
		j = i + 1;
	}
}

void	checknumber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 48 && str[i] <= 57) || str[i] == 45)
			i++;
		else if (str[i] == 32)
			i++;
		else
			exiteror();
	}
}

char	*addspace(char *argv)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (argv[i])
		i++;
	str = malloc(sizeof(char) * i + 2);
	while (argv[j] != '\0')
	{
		str[j] = argv[j];
		j++;
	}
	str[j] = ' ';
	str[j + 1] = '\0';
	return (str);
}

void	preptab(t_base *base)
{
	int	i;

	i = 0;
	base->parsing.totaltab = 0;
	while (base->parsing.tab[base->parsing.totaltab])
		base->parsing.totaltab++;
	base->parsing.tabint = malloc(sizeof(int *) * base->parsing.totaltab);
	while (i < base->parsing.totaltab)
	{
		base->parsing.tabint[i] = ft_atoi(base->parsing.tab[i]);
		i++;
	}
	base->opti.totalarg = base->parsing.totaltab;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing_check2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:59:09 by sroggens          #+#    #+#             */
/*   Updated: 2022/10/23 15:43:50 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checkvalid(char **argv)
{
	int			i;
	long int	tmp;

	i = 0;
	while (argv[i])
	{
		tmp = atoimod(argv[i]);
		if (tmp < INT_MIN || tmp > INT_MAX)
			exiteror();
		i++;
	}
}

void	checknbontab(t_base *base)
{
	int	i;

	i = 0;
	while (base->parsing.tab[i])
	{
		if (checkcasetab(base->parsing.tab[i]) == 0)
			exiteror();
		i++;
	}
}

int	checkcasetab(char *test)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (test[i] == '-')
		i++;
	while (test[i] >= 48 && test[i] <= 57)
	{
		nb = 1;
		i++;
	}
	if (test[i])
		exiteror();
	return (nb);
}

long int	atoimod(const char *str)
{
	long int	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (!str)
		exiteror();
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (sign * result);
}

char	*deletelastspace(char *change)
{
	int		i;
	int		j;
	char	*str;

	str = NULL;
	i = 0;
	j = 0;
	while (change[i])
	{
		if (change[i + 1] == '\0' && change[i] == ' ')
		{
			str = malloc(sizeof(char) * i);
			while (j < i)
			{
				str[j] = change[j];
				j++;
			}
			str[j] = '\0';
			free(change);
			return (str);
		}
		i++;
	}
	return (change);
}

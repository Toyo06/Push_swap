/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tools_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 09:51:02 by sroggens          #+#    #+#             */
/*   Updated: 2022/10/23 14:01:40 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

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
	if (str[i] == '+' || str[i] == '-')
		exiteror();
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (sign * result);
}

char	*ft_strdup(char *src)
{
	char	*dst;
	int		i;

	i = 0;
	if (!src)
		return (0);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	free(src);
	dst[i] = 0;
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		lenword1;
	int		lenword2;
	char	*str;

	i = -1;
	if (s1 && s2)
	{
		lenword1 = ft_strlen(s1);
		lenword2 = ft_strlen(s2);
		str = (char *)malloc(sizeof(char) * (lenword1 + lenword2 + 1));
		if (str == 0)
			return (0);
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
			str[lenword1 + i] = s2[i];
		str[lenword1 + i] = 0;
		free(s1);
		free(s2);
		return (str);
	}
	return (NULL);
}

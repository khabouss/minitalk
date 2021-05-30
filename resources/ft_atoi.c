/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:28:03 by tkhabous          #+#    #+#             */
/*   Updated: 2021/05/30 13:11:36 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minitalk.h"

static int	ft_isspace(char c)
{
	if (c == '\n' || c == '\f' || c == ' '
		|| c == '\r' || c == '\v' || c == '\t')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				n;
	int				signe;

	n = 0;
	i = 0;
	signe = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			signe = -1;
	while (str[i] >= '0' && (str[i] <= '9') && str[i] != '\0')
	{
		if ((unsigned long)n > 9223372036854775807)
		{
			if (signe > 0)
				return (-1);
			else
				return (0);
		}
		n = n * 10 + (*(str + (i++)) - '0');
	}
	return (n * signe);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:45:09 by tkhabous          #+#    #+#             */
/*   Updated: 2021/05/30 14:16:27 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minitalk.h"

static int	taille(unsigned int nb)
{
	unsigned int	size;

	size = 0;
	while (nb >= 10)
	{
		nb /= 10;
		++size;
	}
	return ((int)(size + 1));
}

char	*ft_itoa(int n)
{
	char			*tab;
	unsigned int	nb;
	unsigned int	i;
	unsigned int	size;

	if (n < 0)
		nb = n * -1;
	else
		nb = n;
	size = taille(nb);
	i = 0;
	tab = malloc(size + 1 + (n < 0));
	if (tab == 0)
		return (0);
	tab[i] = '-';
	if (n < 0)
		size++;
	i = size - 1;
	while (nb > 0)
	{
		tab[i--] = (nb % 10 + 48);
		nb /= 10;
	}
	tab[size] = '\0';
	return (tab);
}

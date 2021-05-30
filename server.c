/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:48:44 by tkhabous          #+#    #+#             */
/*   Updated: 2021/05/30 12:53:11 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	fun1(int signum)
{
	static unsigned char	c = 0;
	static int				bits = 0;

	signum = signum % 3;
	c = c << 1;
	c |= signum;
	bits++;
	if (bits == 8)
	{
		bits = 0;
		write(1, &c, 1);
		c = 0;
	}
}

int	main(void)
{
	char	*pid;

	write(1, "SERVER PID > ", 13);
	pid = ft_itoa(getpid());
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	signal(SIGUSR1, fun1);
	signal(SIGUSR2, fun1);
	while (1)
	{
		pause();
	}
	return (0);
}

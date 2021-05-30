/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:43:03 by tkhabous          #+#    #+#             */
/*   Updated: 2021/05/30 12:45:39 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

int	send_message(char *message, int pid)
{
	int	i;
	int	j;
	int	r;

	i = -1;
	while (message[++i] != '\0')
	{
		j = 8;
		while (--j >= 0)
		{
			if (message[i] & (1 << j))
				r = kill(pid, SIGUSR2);
			else
				r = kill(pid, SIGUSR1);
			if (r == -1)
				return (write(2, "Error\nPID does not exist\n", 25));
			usleep(400);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (write(1, "Error\nWrong number of arguments\n", 32));
	pid = ft_atoi(argv[1]);
	if (pid <= -1)
		return (write(2, "Error\nPID cannot be a negative number\n", 38));
	send_message(argv[2], pid);
	return (1);
}

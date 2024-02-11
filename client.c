/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:01:18 by obelhami          #+#    #+#             */
/*   Updated: 2024/02/11 19:56:17 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	send_string(char *str, int pid)
{
	int	i;
	int	j;
	int	killl;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 8)
		{
			if (str[i] & (1 << (7 - j)))
				killl = kill(pid, SIGUSR1);
			else
				killl = kill(pid, SIGUSR2);
			if (killl == -1)
			{
				exit(1);
			}
			usleep(100);
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		write(1, "Error you must to execute: ./client [PID] [MSG]\"", 48);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(1, "the PID invalide", 16);
		return (0);
	}
	send_string(argv[2], pid);
	send_string("\n", pid);
	return (0);
}

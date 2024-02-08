/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:01:18 by obelhami          #+#    #+#             */
/*   Updated: 2024/02/08 09:53:00 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	factorial;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	factorial = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		factorial = (10 * factorial) + str[i] - '0';
		i++;
	}
	return (factorial * sign);
}

void	send_string(char *str, int pid)
{
	int	i;
	int	j;
	int killl;

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
	send_string(argv[2], pid);
	send_string("\n", pid);
	return (0);
}

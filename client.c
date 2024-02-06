/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:01:18 by obelhami          #+#    #+#             */
/*   Updated: 2024/02/03 16:30:17 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <signal.h>

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
	int	ascii;
	int	bit;

	i = 0;
	while (str[i])
	{
		j = 7;
		bit = 0;
		ascii = str[i];
		while (j >= 0)
		{
			bit = ascii >> j;
			if (bit & 1)
			{
				kill(pid, SIGUSR1);
			}
			else
				kill(pid, SIGUSR2);
			j--;
			usleep(250);
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

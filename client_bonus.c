/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:07:26 by obelhami          #+#    #+#             */
/*   Updated: 2024/02/10 09:07:29 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

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
void	handler(int getnum)
{
	if (getnum == SIGUSR1)
	{
		write(1, "Message received by the server\n", 32);
	}
	return;
}
int	main(int argc, char *argv[])
{
	int	pid; 
	int	c_pid;
	char	*str_pid;

	if (argc != 3)
	{
		write(1, "Error you must to execute: ./client [PID] [MSG]\"", 48);
		return (1);
	}
	c_pid = getpid();
	str_pid = ft_itoa(c_pid);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(1, "the PID invalide", 16);
		return(0);
	}
	signal(SIGUSR1, handler);
	send_string(str_pid, pid);
	send_string("\n", pid);
	send_string(argv[2], pid);
	send_string("\n", pid);
	free(str_pid);
	usleep(150);
	return (0);
}
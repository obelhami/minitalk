/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:06:23 by obelhami          #+#    #+#             */
/*   Updated: 2024/02/11 23:34:07 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"
#include <stdio.h>

t_data	g_data = (t_data){.index = 0, .count = 0, .number = 0, .character = 0};

void	s_handler(void)
{
	g_data.index++;
	if (g_data.index == 8)
	{
		if (g_data.character == '\n')
			g_data.count++;
		if (g_data.count == 1)
			write(1, &g_data.character, 1);
		if (g_data.count == 0)
			g_data.number = (g_data.number * 10) + g_data.character - '0';
		g_data.character = 0;
		g_data.index = 0;
	}
	if (g_data.count == 2)
	{
		kill (g_data.number, SIGUSR1);
		g_data.number = 0;
		g_data.count = 0;
	}
}

void	handler(int getnum)
{
	int			tmp;

	tmp = 0;
	if (getnum == SIGUSR1)
	{
		tmp = g_data.character << 1;
		g_data.character = tmp | 1;
	}
	else if (getnum == SIGUSR2)
		g_data.character = g_data.character << 1;
	s_handler();
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "WELCOME TO MINITALK\n", 20);
	write(1, "the PID is : ", 13);
	ft_putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
	}
	return (0);
}

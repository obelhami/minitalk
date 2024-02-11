/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:29:11 by obelhami          #+#    #+#             */
/*   Updated: 2024/02/11 23:32:10 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

t_data	g_data = (t_data){.index = 0, .character = 0};

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
	{
		g_data.character = g_data.character << 1;
	}
	g_data.index++;
	if (g_data.index == 8)
	{
		write(1, &g_data.character, 1);
		g_data.character = 0;
		g_data.index = 0;
	}
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

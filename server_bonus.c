/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:06:23 by obelhami          #+#    #+#             */
/*   Updated: 2024/02/10 09:06:54 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"
#include <stdio.h>

int inde;
void	handler(int getnum)
{
	int			tmp;
	static	char	g_str;
	static	int	count;
	static	int fact;

	tmp = 0;
	if (getnum == SIGUSR1)
	{
		tmp = g_str << 1;
		g_str = tmp | 1;
	}
	else if (getnum == SIGUSR2)
		g_str = g_str << 1;
	inde++;
	if (inde == 8)
	{

		if (g_str == '\n')
			count++;
		if (count == 1)
			write(1, &g_str, 1);
		if (count == 0)
			fact = (fact * 10) + g_str - '0';
		g_str = 0;
		inde = 0;
	}
	if (count == 2)
	{
		kill (fact, SIGUSR1);
		write(1, "\n", 1);
		fact = 0;
		count = 0;
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


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:29:11 by obelhami          #+#    #+#             */
/*   Updated: 2024/02/03 16:12:50 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <signal.h>

int	g_str;

void	ft_putnbr(int n)
{
	long	nb;
	int		i;
	char	a;

	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	i = 1;
	while (nb / i >= 10)
		i = i * 10;
	while (i > 0)
	{
		a = nb / i + '0';
		write(1, &a, 1);
		nb = nb % i;
		i = i / 10;
	}
}

void	handler(int getnum)
{
	int			tmp;
	static int	index = 0;	

	tmp = 0;
	if (getnum == SIGUSR1)
	{
		tmp = g_str << 1;
		g_str = tmp | 1;
	}
	else if (getnum == SIGUSR2)
	{
		g_str = g_str << 1;
	}
	if (index == 7)
	{
		write(1, &g_str, 1);
		g_str = 0;
		index = 0;
		return ;
	}
	index++;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "WELCOME TO MINITALK\n", 20);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	write(1, "the PID is : ", 13);
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
	{
		pause();
	}
	return (0);
}

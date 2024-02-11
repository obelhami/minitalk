/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:27:36 by obelhami          #+#    #+#             */
/*   Updated: 2024/02/11 23:25:32 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>
# include <limits.h>

typedef struct s_data
{
	int		index;
	int		count;
	int		number;
	char	character;
}	t_data;

void	ft_putnbr(int n);
int		ft_atoi(char *str);
char	*ft_itoa(int n);

#endif

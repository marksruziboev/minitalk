/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:01:04 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/28 14:52:51 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <signal.h>
#include <string.h>
#include <unistd.h>

void	coder(int ch, int pid)
{
	int	i;

	i = 0;
	if (kill(pid, 0) == -1)
	{
		write(1, "Eror", 1);
		exit(1);
	}
	while (i <= 7)
	{
	
		if (((ch >> i) & 1) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	main(int a, char **v)
{
	int	pid;
	size_t	j;
	
	j = 0;
	while(v[1][j] && v[1][j] >= '0' && v[1][j] <= '9')
		j++;
	if (j != ft_strlen(v[1]) || ft_strlen(v[2]) == 0)
	{
		write(2, "Error", 6);
		exit(1);
	}
	pid = ft_atoi(v[1]);
	j = 0;
	if (a == 3 && pid > 0)
	{		
		while (v[2][j] && pid)
		{
			coder(v[2][j], pid);
			j++;
		}
		coder('\n', pid);
	}
	else
		ft_putstr_fd("Enter only 3 arguments", 1);
	return (0);
}

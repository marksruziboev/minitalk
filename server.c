/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:01:14 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/28 14:48:12 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>

void	ft_msg(int signal)
{
	static int	p;
	static int	ch;

	if (signal == SIGUSR2)
		ch += 1 << (p);
	p++;
	if (p == 8)
	{
		write(1, &ch, 1);
		p = 0;
		ch = 0;
	}
}

int	main(void)
{
	ft_putstr_fd("Server pid =", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR2, ft_msg);
	
	while (1)
	{
		sleep(1);
	}
	return (0);
}

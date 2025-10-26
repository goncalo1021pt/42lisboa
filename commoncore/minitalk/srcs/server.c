/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:45:18 by gfontao-          #+#    #+#             */
/*   Updated: 2025/04/14 20:37:18 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	i = 0;
	static char	c = 0;
	pid_t		client_pid;

	(void)context;
	client_pid = info->si_pid;
	if (signal == SIGUSR1)
		c = c | (1 << i);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	if (kill(client_pid, SIGUSR1) == -1)
	{
		ft_putendl_fd("Error: kill", 2);
		exit(1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_putendl_fd("Error: sigaction", 2);
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putendl_fd("Error: sigaction", 2);
		return (1);
	}
	while (1)
		pause();
	return (0);
}

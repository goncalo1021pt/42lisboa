/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:49:58 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/21 08:59:45 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	error_message(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

void	signal_handler(int signal)
{
	static int	i = 0;
	if (signal == SIGUSR1 && i == 0)
	{
		ft_putendl_fd("Message received by server", 1);
		i = 1;
	}
}

void	convert_to_binary(char *str, pid_t pid, int delay)
{
	int	ctd;

	ctd = 0;
	while (ctd < 8)
	{
		if ((*str >> ctd) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				error_message("Error: Invalid PID");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error_message("Error: Invalid PID");
		}
		ctd++;
		usleep(delay);
	}
}

void	send_signal(char *str, pid_t pid)
{
	const int	delay = 500;

	while (*str)
		convert_to_binary(str++, pid, delay);
	convert_to_binary("\n", pid, delay);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					i;

	if (argc != 3)
		error_message("Error: Invalid number of arguments");
	i = 0;
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
			error_message("Error: PID must be a number");
		i++;
	}
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		error_message("Error: sigaction");
	if (ft_atoi(argv[1]) == 0)
		error_message("Error: PID cannot be 0");
	send_signal(argv[2], ft_atoi(argv[1]));
	return (0);
}

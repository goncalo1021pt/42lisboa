/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:49:58 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/20 16:19:02 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	error_message(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

void	check_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
			error_message("Error: PID must be a number");
		i++;
	}
	if (ft_atoi(pid) == 0)
		error_message("Error: PID cannot be 0");
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
	const int	delay = 100;

	while (*str)
		convert_to_binary(str++, pid, delay);
	convert_to_binary("\n", pid, delay);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		error_message("Error: Invalid number of arguments");
	check_pid(argv[1]);
	send_signal(argv[2], ft_atoi(argv[1]));
	return (0);
}

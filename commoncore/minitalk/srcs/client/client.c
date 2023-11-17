/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:49:58 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/17 13:22:14 by gfontao-         ###   ########.fr       */
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
}

void	convert_to_binary(char *str, pid_t pid, int delay)
{
	int	ctd;
	int	ctd2;

	ctd = 0;
	while (str[ctd])
	{
		ctd2 = 0;
		while (ctd2 < 8)
		{
			if ((str[ctd] >> ctd2) & 1)
			{
				if (kill(pid, SIGUSR1) == -1)
					error_message("Error: Invalid PID");
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					error_message("Error: Invalid PID");
			}
			ctd2++;
			usleep(delay);
		}
		ctd++;
	}
}

void	send_signal(char *str, pid_t pid)
{
	int	delay;

	delay = 1000; //(ft_strlen(str) / 2) * 100;
	convert_to_binary(str, pid, delay);
	convert_to_binary("\n", pid, delay);
	//usleep(500000);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		error_message("Error: Invalid number of arguments");
	check_pid(argv[1]);
	send_signal(argv[2], ft_atoi(argv[1]));
	return (0);
}

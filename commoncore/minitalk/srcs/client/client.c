/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:49:58 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/16 17:44:48 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	exit_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	check_input(char *input, int *pid)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (!ft_isdigit(input[i]))
			exit_msg("Invalid PID\n");
		i++;
	}
	if (ft_strlen(input) > 6)
		exit_msg("Invalid PID\n");
	*pid = ft_atoi(input);
	if (*pid < 0)
		exit_msg("Invalid PID\n");
}

void	signal_handler(char c, pid_t pid)
{
	int			ctd;
	int			error;
	const int	sleep_time = 100;

	ctd = 0;
	ft_printf("PID: %d\n", pid);
	while (ctd < 8)
	{
		if (c & 1)
		{
			ft_printf("Sending: 1\n");
			error = kill(pid, SIGUSR1);
			if (error == -1)
				exit_msg("Invalid PID\n");
		}
		else
		{
			ft_printf("Sending: 0\n");
			error = kill(pid, SIGUSR2);
			ft_printf("Error: %d\n", error);
			if (error == -1)
				exit_msg("Invalid PID\n");
		}
		c = c >> 1;
		ft_printf("Sleeping for %d microseconds\n", sleep_time);
		usleep(sleep_time);
		ctd++;
	}
}

void	send_signal(pid_t pid, char *str)
{
	int	ctd;

	ctd = 0;
	while (1)
	{
		ft_printf("Sending: %c\n", str[ctd]);
		signal_handler(str[ctd], pid);
		ctd++;
		if (str[ctd] == '\0')
			break ;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		return (0);
	check_input(argv[1], &pid);
	send_signal(pid, argv[2]);
	return (0);
}

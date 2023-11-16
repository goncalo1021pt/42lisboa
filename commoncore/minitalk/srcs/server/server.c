/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:45:18 by gfontao-          #+#    #+#             */
/*   Updated: 2023/11/16 13:49:03 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

#define MESSAGE_SIZE 1000

typedef struct s_message
{
	char buffer[MESSAGE_SIZE];
	int index;
} t_message;

void handle_signal(int signal, siginfo_t *info, void *context)
{
	static t_message message = {{0}, 0};

	(void)context;
	if (signal == SIGUSR1)
		message.buffer[message.index++] = '0';
	else if (signal == SIGUSR2)
		message.buffer[message.index++] = '1';
	if (message.index == 8 * sizeof(message.buffer))
	{
		message.buffer[message.index] = '\0';
		ft_printf("%s\n", message.buffer);
		message.index = 0;
		ft_memset(message.buffer, 0, sizeof(message.buffer));
	}
	kill(info->si_pid, SIGUSR1);
}

int main(void)
{
	pid_t pid;
	struct sigaction action = {0};

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	action.sa_sigaction = handle_signal;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}

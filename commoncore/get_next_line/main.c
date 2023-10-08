/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:39:49 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/08 13:39:51 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

/* int main() {
	const char *filePath = "/home/goncalo1021pt/42/commoncore/get_next_line/main.c";
	int fileFd = open(filePath, O_RDONLY);
	char *line;

	if (fileFd == -1) {
		perror("Unable to open file");
		return 1;
	}
	while ((line = get_next_line(fileFd)) != NULL) {
		printf("%s\n", line);
		free(line); 
	}
	close(fileFd);
return 0;
} */
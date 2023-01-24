/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:17:56 by naal-jen          #+#    #+#             */
/*   Updated: 2022/10/21 21:18:49 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_ptr(char **pointer)
{
	int	i;

	i = 0;
	while (pointer[i])
	{
		free(pointer[i]);
		i++;
	}
	free(pointer);
}

int	open_files(char *file, int type)
{
	int	fd;

	fd = 0;
	if (type == 1)
	{
		fd = open(file, O_RDONLY, 0777);
		if (access(file, F_OK | R_OK) != 0)
			error_file(file);
	}
	if (type == 2)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (access(file, F_OK | W_OK) != 0)
			error_file(file);
	}
	if (fd == -1)
		exit(EXIT_FAILURE);
	return (fd);
}

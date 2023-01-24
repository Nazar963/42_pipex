/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:21:27 by naal-jen          #+#    #+#             */
/*   Updated: 2023/01/24 16:07:57 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handler(int case_num)
{
	if (case_num == 1)
	{
		perror("Fork Failed");
		exit(EXIT_FAILURE);
	}
	if (case_num == 2)
	{
		perror("Pipe Failed");
		exit(EXIT_FAILURE);
	}
	if (case_num == 3)
	{
		ft_putstr_fd("Check How Many Arguments You Have", 2);
		exit(EXIT_FAILURE);
	}
	return ;
}

void	error_file(char *file)
{
	perror(file);
	exit(EXIT_FAILURE);
}

void	error_cmd(char *cmd)
{
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(": command not found", 2);
	exit(EXIT_FAILURE);
}

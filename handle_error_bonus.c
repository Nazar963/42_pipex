/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:21:27 by naal-jen          #+#    #+#             */
/*   Updated: 2022/10/21 21:16:52 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	handler(int case_num)
{
	if (case_num == 1)
	{
		perror("Fork Failed");
		exit(0);
	}
	if (case_num == 2)
	{
		perror("Pipe Failed");
		exit(0);
	}
	if (case_num == 3)
	{
		ft_putstr_fd("Check How Many Arguments You Have", 2);
		exit(1);
	}
	return ;
}

void	error_file(char *file)
{
	perror(file);
	exit(0);
}

void	error_cmd(char *cmd)
{
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(": command not found", 2);
	exit(0);
}

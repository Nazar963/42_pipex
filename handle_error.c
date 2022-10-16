/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:21:27 by naal-jen          #+#    #+#             */
/*   Updated: 2022/10/15 21:09:37 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handler(int case_num)
{
	if (case_num == 1)
	{
		perror("Fork Failed");
		exit(1);
	}
	if (case_num == 2)
	{
		perror("Pipe Failed");
		exit(1);
	}
	if (case_num == 3)
	{
		perror("Check How Many Arguments You Have");
		exit(1);
	}
	
	return ;
}
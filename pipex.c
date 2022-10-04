/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:30:44 by naal-jen          #+#    #+#             */
/*   Updated: 2022/10/04 15:38:25 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int	pipex(int argc, char **argv, char **envp)
{
	int	pfd[2];
	int	fd;
	int	pid;

	fd = open(argv[1], O_RDONLY);
	dup2(fd, 0);
	if (argc > 5)
		return (0);
	if (pipe(pfd) == -1)
	{
		perror("pipe faild");
		exit(1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Fork faild");
		return (0);
	}
	if (pid == 0)
	{
		execve(argv[1], argv[2], envp);
	}
	waitpid(pid, NULL, 0);
	return (0);
}
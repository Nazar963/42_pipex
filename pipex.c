/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:30:44 by naal-jen          #+#    #+#             */
/*   Updated: 2022/10/11 18:06:49 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "libft.h"

char	**parsing_arguments(char **envp)
{
	char	*envp_path;
	char	**my_path;
	char	**args;

	envp_path = ft_strdup(envp);
	my_path = ft_split(envp, ":");
	args = ft_split(argv[2], " ");
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;
	int	infd;
	int	oufd;

	if (argc > 5 || argc < 5)
		return (NULL);
	infd = open(argv[1], O_RDONLY);
	oufd = open(argv[4], O_RDWR, O_CREAT, 0777);
	if (pipe(fd) == -1)
		perror("Unable to pipe the situation!");
	pid1 = fork();
	if (pid1 < 0)
		perror("Fork faild");
	if (pid1 == 0)
	{
		int	i;
		char	*cmd;

		if (dup2(infd, 0) < 0)
			return (0);
		if (dup2(fd[1], 1) < 0)
			return (0);
		close(fd[0]);
		// close(fd[1]);
		close(infd);
		// close(oufd);
		i = -1;
		while (mypaths[++i])
		{
    		cmd = ft_join(mypaths[i], ag[2]);
    		execve(cmd, mycmdargs, envp);
    		free(cmd);
		}
		exit(/*EXIT_FAILURE*/0);
	}
	pid2 = fork();
	if (pid2 < 0)
		perror("second child faild!");
	if (pid2 == 0)
	{
		if (dup2(oufd, 1) < 0)
			return (0);
		if (dup2(fd[0], 0) < 0)
			return (0);
			// close(fd[0]);
			close(fd[1]);
			// close(infd);
			close(oufd);
			execve();
			exit(/*EXIT_FAILURE*/0);
	}
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
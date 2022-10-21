/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:49:22 by naal-jen          #+#    #+#             */
/*   Updated: 2022/10/21 21:18:17 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(char *exec_path, char **cmd, char **envp)
{
	if (execve(exec_path, cmd, envp) == -1)
	{
		free_ptr(cmd);
		exit(EXIT_FAILURE);
	}
}

void	add_slash(char **new_path, char **cmd, char **envp)
{
	int		i;
	char	*exec_path;
	char	*with_slash;

	i = -1;
	with_slash = ft_strrchr(cmd[0], '/');
	while (new_path[++i])
	{
		if (with_slash)
		{
			exec_path = ft_strjoin(new_path[i], with_slash);
			if (access(exec_path, F_OK | X_OK) == 0)
				execute_cmd(exec_path, cmd, envp);
		}
		if (new_path[i][ft_strlen(new_path[i] + 1)] != '/')
			new_path[i] = ft_strjoin(new_path[i], "/");
		exec_path = ft_strjoin(new_path[i], cmd[0]);
		if (access(exec_path, F_OK | X_OK) == 0)
			execute_cmd(exec_path, cmd, envp);
		else
			free(exec_path);
	}
	error_cmd(cmd[0]);
}

void	handle_path(char **argv, char **envp, int kind)
{
	int		i;
	char	**new_path;
	char	**cmd;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	new_path = ft_split(envp[i] + 5, ':');
	cmd = ft_split(argv[kind], ' ');
	add_slash(new_path, cmd, envp);
}

void	child(int input_file, int output_file, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;

	if (pipe(fd) == -1)
		handler(2);
	pid1 = fork();
	if (pid1 < 0)
		handler(1);
	if (pid1 == 0)
	{
		dup2(input_file, 0);
		dup2(fd[1], 1);
		close(fd[0]);
		close(output_file);
		handle_path(argv, envp, 2);
	}
	waitpid(pid1, NULL, 0);
	dup2(fd[0], 0);
	dup2(output_file, 1);
	close(fd[1]);
	close(input_file);
	handle_path(argv, envp, 3);
}

int	main(int argc, char **argv, char **envp)
{
	int	input_file;
	int	output_file;

	if (argc != 5)
		handler(3);
	input_file = open_files(argv[1], 1);
	output_file = open_files(argv[4], 2);
	child(input_file, output_file, argv, envp);
}

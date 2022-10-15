/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:49:22 by naal-jen          #+#    #+#             */
/*   Updated: 2022/10/14 17:44:49 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *exec_path, char **cmd, char **envp)
{
	execve(exec_path, cmd, envp)
	perror("command not valid");
}

void	add_slash(char **new_path, char **cmd, char **envp, char **argv)
{
	int		i;
	char	*exec_path;

	i = 0;
	while (new_path[i])
	{
		if (new_path[i][ft_strlen(new_path[i] + 1)] != '/')
			new_path[i] = ft_strjoin(new_path[i], "/");
		if (access(new_path[i], X_OK) == 0)
		{
			exec_path = ft_strjoin(new_path[i], cmd[0]);
			execute(exec_path, cmd, envp);
			free(exec_path);
		}
		i++;
	}
}

void	something_1(char **argv, char **envp, int kind)
{
	int		i;
	char	**new_path;
	char	**cmd;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	new_path = ft_split(envp[i], ':');
	cmd = ft_split(argv[kind], ' ');
	add_slash(new_path, cmd, envp, argv);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;
	int	input_file;
	int	output_file;

	input_file = open(argv[1], O_RDONLY);
	output_file = open (argv[4], O_RDWR, O_CREAT, 0777);
	if (argc != 5)
		handler(3);
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
		something_1(argv, envp, 2);
	}
	waitpid(pid1, NULL, 0);
	dup2(fd[0], 0);
	dup2(output_file, 1);
	close(fd[1]);
	close(input_file);
	something_1(argv, envp, 3);
	close(fd[0]);
	close(output_file);
	return (0);
}
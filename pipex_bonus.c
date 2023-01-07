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

#include "pipex_bonus.h"

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

void	handle_path(char *cmdd, char **envp)
{
	int		i;
	char	**new_path;
	char	**cmd;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	new_path = ft_split(envp[i] + 5, ':');
	cmd = ft_split(cmdd, ' ');
	add_slash(new_path, cmd, envp);
}

void	child(int input_file, int output_file, char *cmd, char **envp)
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
		close(fd[0]);
		dup2(fd[1], 1);
		handle_path(cmd, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid1, NULL, 0);
	}
}

void	execute_heredoc(char **argv, int *pfd)
{
	char	*line;
	close(pfd[0]);
	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
		{
			free(line);
			exit(0);
		}
		ft_putstr_fd(line, pfd[1]);
		free(line);
	}
}

void	handle_heredoc(int argc, char **argv)
{
	pid_t	pid;
	int		pfd[2];

	if (argc < 6)
		exit(EXIT_FAILURE);
	if (pipe(pfd) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (!pid)
		execute_heredoc(argv, pfd);
	else
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
		wait(NULL);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	input_file;
	int	output_file;
	int	i;

	if (argc < 5)
		handler(3);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		i = 3;
		output_file = open_files(argv[argc - 1], 2);
		handle_heredoc(argc, argv);
	}
	else
	{
		i = 2;
		input_file = open_files(argv[1], 1);
		output_file = open_files(argv[argc - 1], 2);
		dup2(input_file, 0);
	}
	while (i < argc - 2)
		child(input_file, output_file, argv[i++], envp);
	dup2(output_file, 1);
	handle_path(argv[argc - 2], envp);	
}

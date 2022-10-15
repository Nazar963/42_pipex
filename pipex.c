/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:30:44 by naal-jen          #+#    #+#             */
/*   Updated: 2022/10/12 19:50:19 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "libft/libft.h"

char	*parser(char *cmd, char *paths)
{
	char	*with_slash;
	char	*l_path;
	char	*path;
	
	with_slash = ft_strrchr(cmd, '/');
	if (with_slash)
	{
		path = ft_strjoin(paths, with_slash);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
	}
	else
	{
		l_path = ft_strjoin(paths, "/");
		path = ft_strjoin(l_path, cmd);
		free(l_path);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
	}
	free(path);
	return (0);
}

char	**add_slash(char **my_path)
{
	int		i;

	i = 0;
	while (my_path[i])
	{
		if (my_path[i][ft_strlen(my_path[i] + 1)] != '/')
			my_path[i] = ft_strjoin(my_path[i], "/");
		i++;
	}
	return (my_path);
}

char	*execute(char **envp, char **argv)
{
	char	**my_path;
	char	**args;
	char	*path;
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	args = ft_split(argv[2], ' ');
	while (ft_strnstr(envp[j], "PATH=", 5) == 0)
		j++;
	my_path = ft_split(envp[j] + 5, ':');
	j = 0;
	while (my_path[j])
	{
		path = parser(args[0], my_path[j]);
		go_cmd(path, args, envp);
		i++;
	}
	// my_path = add_slash(my_path);
	// i = -1;
	// while (my_path[++i])
	// {
	// 	cmd = ft_strjoin(my_path[i], argv[2]);
	// 	execve(cmd, args, envp);
	// 	perror("no me 1");
	// 	free (cmd);
	// }
	return (0);
}
void	go_cmd(char *path, char **args, char **envp)
{
	if (execve(path, args, envp) == -1)
	{
		perror("me to execute!");
		free(args);
		exit(EXIT_FAILURE);
	}
	return (0);
}

// void	execute(char **envp, char **argv)
// {
// 	char	**my_path;
// 	char	**args;
// 	char	*cmd;
// 	int		i;
// 	int		j;
// 	int		k;

// 	j = 0;
// 	k = 0;
// 	while (ft_strnstr(envp[j], "PATH=", 5) == 0)
// 		j++;
// 	my_path = ft_split(envp[j] + 5, ':');
// 	j = 0;
// 	while (my_path[j])
// 	{

// 	}
// 	// my_path = add_slash(my_path);
// 	// args = ft_split(argv[2], ' ');
// 	// i = -1;
// 	// while (my_path[++i])
// 	// {
// 	// 	cmd = ft_strjoin(my_path[i], argv[2]);
// 	// 	execve(cmd, args, envp);
// 	// 	perror("no me 1");
// 	// 	free (cmd);
// 	// }
// }

void	execute_2(char **envp, char **argv)
{
	char	**my_path;
	char	**args;
	char	*cmd;
	int		i;
	int		j;

	j = 0;
	while (ft_strnstr(envp[j], "PATH=", 5) == 0)
		j++;
	my_path = ft_split(envp[j] + 5, ':');
	add_slash(my_path);
	args = ft_split(argv[3], ' ');
	i = -1;
	while (my_path[++i])
	{
		cmd = ft_strjoin(my_path[i], argv[2]);
		execve(cmd, args, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;
	int	infd;
	int	oufd;

	if (argc != 5)
		return (0);

	infd = open(argv[1], O_RDONLY);

	oufd = open(argv[4], O_RDWR, O_CREAT, 0777);

	if (pipe(fd) == -1)
		perror("Unable to pipe the situation!");

	pid1 = fork();

	if (pid1 < 0)
		perror("Fork faild");

	if (pid1 == 0)
	{
		if (dup2(infd, 0) < 0)
			return (0);
		if (dup2(fd[1], 1) < 0)
			return (0);
		close(fd[0]);
		close(fd[1]);
		close(infd);
		close(oufd);
		execute(envp, argv);
		perror("no good baby boy!");
		exit(0);
	}
	pid2 = fork();
	if (pid2 < 0)
		perror("second child faild!");
	if (pid2 == 0)
	{
		if (dup2(fd[0], 0) < 0)
			return (0);
		if (dup2(oufd, 1) < 0)
			return (0);
			close(fd[0]);
			close(fd[1]);
			close(infd);
			close(oufd);
			execute_2(envp, argv);
			perror("2-no good baby boy!");
			exit(0);
	}
	close(fd[0]);
	close(fd[1]);
	close(infd);
	close(oufd);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

/* ---------------------------------------------------------------------------------------------- */
/*                                           prova envp                                           */
/* ---------------------------------------------------------------------------------------------- */
// int	main(int argc, char **argv, char **envp)
// {
// 	int		i;
// 	int		j;
// 	char	**loco;

// 	i = 0;
// 	j = 0;
// 	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
// 		i++;
// 	loco = ft_split(envp[i], ':');
// 	while (*loco)
// 	{
// 		// printf("%ld\n", ft_strlen(*loco));
// 		printf("%s\n", *loco);
// 		loco++;
// 	}
// 	return (0);
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	int		i;
// 	int		j;
// 	char	**loco;

// 	i = 0;
// 	j = 0;
// 	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
// 		i++;
// 	loco = ft_split(envp[i], ':');
// 	int	k;

// 	k = 0;
// 	while (loco[k])
// 	{
// 		if (loco[k][ft_strlen(loco[k] + 1)] != '/')
// 			loco[k] = ft_strjoin(loco[k], "/");
		
// 		//? to print the hole string
// 		printf("%s\n", loco[k]);
		
// 		//! to show each letter
// 		// printf("%c\n", loco[k][ft_strlen(loco[k] + 1)]);
		
// 		k++;
// 	}
// 	return (0);
// }
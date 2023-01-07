/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:26:19 by naal-jen          #+#    #+#             */
/*   Updated: 2022/10/21 21:16:05 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft/libft.h"
# include "42_get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

void	handler(int case_num);
int		main(int argc, char **argv, char **envp);
void	add_slash(char **new_path, char **cmd, char **envp);
void	handle_path(char *cmdd, char **envp);
void	free_ptr(char **pointer);
void	error_cmd(char *cmd);
int		open_files(char *file, int type);
void	error_file(char *file);
void	execute_cmd(char *exec_path, char **cmd, char **envp);
void	child(int input_file, int output_file, char *cmd, char **envp);
void	execute_heredoc(char **argv, int *pfd);
void	handle_heredoc(int argc, char **argv);

#endif
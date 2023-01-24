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

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
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
void	handle_path(char **argv, char **envp, int kind);
void	free_ptr(char **pointer);
void	error_cmd(char *cmd);
int		open_files(char *file, int type);
void	error_file(char *file);
void	execute_cmd(char *exec_path, char **cmd, char **envp);
void	child(int input_file, int output_file, char **argv, char **envp);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:53:01 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/19 17:39:42 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "./ft_printf/libft.h"

typedef struct s_data
{
	char	**res;
	char	*result;
	char	**res1;
	int		fd[2];
	int		id;
	int		id1;
	int		x;
	int		file1;
	int		file2;
}	t_data;

void	free_func(char **args);
void	terminate(char *m);
void	cmd_not_found(char **cmd);
int		search(char **envp);

#endif
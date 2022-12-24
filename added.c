/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   added.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 07:03:17 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/19 18:36:41 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_func(char **args)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (args[size])
		size++;
	while (i < size)
		free(args[i++]);
	free(args);
}

void	terminate(char *m)
{
	perror(m);
	exit(1);
}

void	cmd_not_found(char **res)
{
	write(2, res[0], ft_strlen(res[0]));
	write(2, ": command not found\n", 20);
	free_func(res);
	exit(1);
}

int	search(char **envp)
{
	int	x;

	x = -1;
	while (envp[++x])
		if (ft_strnstr(envp[x], "PATH", 4) == NULL)
			return (1);
	return (0);
}

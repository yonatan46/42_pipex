/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:48:57 by yonamog2          #+#    #+#             */
/*   Updated: 2022/12/24 19:23:02 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_short(char *path, char **path_split)
{
	free(path);
	free_func(path_split);
}

char	*parsing(t_data *proc, char **envp, char *s)
{
	char	*path;
	char	**path_split;

	proc->x = 0;
	if (search(envp) == 0)
		return (NULL);
	if (ft_strnstr(s, "/", ft_strlen(s)))
		return (s);
	while (!ft_strnstr(envp[proc->x], "PATH", 4))
		proc->x++;
	path_split = ft_split(envp[proc->x] + 5, ':');
	proc->x = -1;
	while (path_split[++proc->x] && (search(envp) == 1))
	{
		path = ft_strjoin(path_split[proc->x], "/");
		proc->result = ft_strjoin(path, s);
		if (access(proc->result, 0) == 0)
		{
			free_short(path, path_split);
			return (proc->result);
		}
		if (path)
			free(path);
		free(proc->result);
	}
	free_short(NULL, path_split);
	return (NULL);
}

void	child_process(t_data *proc, char **av, char **envp)
{
	proc->id = fork();
	if (proc->id < 0)
		terminate("fork");
	if (proc->id == 0)
	{
		proc->file1 = open(av[1], O_RDONLY);
		if (proc->file1 < 0)
			terminate(av[1]);
		proc->res = ft_split(av[2], ' ');
		close(proc->fd[0]);
		dup2(proc->fd[1], STDOUT_FILENO);
		dup2(proc->file1, STDIN_FILENO);
		close(proc->file1);
		if (proc->res[0] && parsing(proc, envp, proc->res[0]))
		{
			execve(parsing(proc, envp, proc->res[0]), proc->res, envp);
			free_func(proc->res);
		}
		else
			cmd_not_found(proc->res);
	}
}

void	paren_process(t_data *proc, char **av, char **envp)
{
	proc->id1 = fork();
	if (proc->id1 < 0)
		terminate("fork");
	if (proc->id1 == 0)
	{
		proc->file2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (proc->file2 < 0)
			terminate(av[4]);
		proc->res1 = ft_split(av[3], ' ');
		close(proc->fd[1]);
		dup2(proc->file2, STDOUT_FILENO);
		dup2(proc->fd[0], STDIN_FILENO);
		close(proc->file2);
		if (proc->res1[0] && parsing(proc, envp, proc->res1[0]))
		{
			execve(parsing(proc, envp, proc->res1[0]), proc->res1, envp);
			free_func(proc->res1);
		}
		else
			cmd_not_found(proc->res1);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data	proc;

	if (ac != 5)
	{
		ft_printf("\n\nNumber of args incorrect\n");
		ft_printf("\tUsage   ./pipex infile <cmd> <cmd> outfile\n\n");
		exit(1);
	}
	pipe(proc.fd);
	child_process(&proc, av, envp);
	paren_process(&proc, av, envp);
	close(proc.fd[0]);
	close(proc.fd[1]);
	waitpid(-1, 0, 0);
	waitpid(-1, 0, 0);
	return (0);
}

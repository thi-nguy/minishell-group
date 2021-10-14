/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <idamouttou@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:30:16 by idamouttou        #+#    #+#             */
/*   Updated: 2021/10/14 16:17:29 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//check etat du fichier

int	is_executable(char *path)
{
	struct stat	f;

	if (lstat(path, &f) != -1)
		if (f.st_mode & S_IXUSR)
			return (1);
	return (1);
}	

//consulte le repertoire
//check letat et ferme

int	found_binary(char *folder, char *filename, DIR *cur_dir)
{
	char			*full_path;
	int				res;
	struct dirent	*reader;

	res = 0;
	reader = readdir(cur_dir);
	while (reader != NULL)
	{	
		if (0 == ft_strncmp(reader->d_name, filename, ft_strlen(filename) + 1))
		{
			full_path = ft_strjoin(folder, reader->d_name);
			if (is_executable(full_path))
				res = 1;
			free(full_path);
		}
		reader = readdir(cur_dir);
	}
	if (res)
		closedir(cur_dir);
	return (res);
}

//ouvre le reprtoire et check si il existe avce found binary et
//ferme le repertoire

char	*check_path(char *path, char *filename)
{
	char			**folders;
	DIR				*cur_dir;

	folders = ft_split(path, ':');
	while (*folders != NULL)
	{
		cur_dir = opendir(*folders);
		if (cur_dir == NULL)
		{
			folders++;
			continue ;
		}
		if (found_binary(*folders, filename, cur_dir))
			break ;
		closedir(cur_dir);
		folders++;
	}
	return (*folders);
}

//cherche le nom du file si il existe ou pas
//si presence de / code 127 "command not found"
//cherche le repertory

char	*find_exec(t_list *env, char *filename)
{
	char			*foundpath;
	char			*path_copy;

	foundpath = NULL;
	while (env != NULL && ft_strncmp(env->content, "PATH", 4) != 0)
		env = env->next;
	if (env == NULL)
	{
		printf("minishell : %s: No such file or directory:\n", filename);
		return (NULL);
	}
	path_copy = ft_strdup(env->content);
	path_copy += 5;
	foundpath = (check_path(path_copy, filename));
	if (foundpath)
		return (ft_strjoin(ft_strjoin(foundpath, "/"), filename));
	g_excd_sig.excode = 127;
	return (NULL);
}

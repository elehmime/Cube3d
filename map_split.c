/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellehmim <ellehmim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:03:02 by ellehmim          #+#    #+#             */
/*   Updated: 2024/09/30 17:50:59 by ellehmim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*map_infos_line(char *str)
{
	int		j;
	int		k;
	char	*dest;

	j = 0;
	k = 0;
	dest = (char *)ft_calloc(ft_strlen_cub(str) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (str[k])
	{
		while (str[k] == ' ')
			k++;
		dest[j] = str[k];
		j++;
		k++;
	}
	dest[j] = '\0';
	return (dest);
}

char	**copy_only_map_infos(t_map_cube *cube, int i)
{
	int		j;
	char	**map_infos;

	j = 0;
	map_infos = (char **)ft_calloc(i + 1, sizeof(char *));
	if (!map_infos)
		return (0);
	while (j < i)
	{
		map_infos[j] = map_infos_line(cube->map[j]);
		if (!map_infos[j])
		{
			free_map2(map_infos);
			return (NULL);
		}
		j++;
	}
	map_infos[j] = 0;
	return (map_infos);
}

char	**copy_only_map(t_map_cube *cube, int i)
{
	int		j;
	int		k;
	char	**map;

	j = 0;
	k = 0;
	map = (char **)ft_calloc(count_size_map(cube) - i + 1, sizeof(char *));
	if (!map)
		return (0);
	while (cube->map[i])
	{
		map[j] = (char *)ft_calloc(ft_strlen(cube->map[i]) + 1, sizeof(char));
		if (!map[j])
			return (0);
		while (cube->map[i][k])
		{
			map[j][k] = cube->map[i][k];
			k++;
		}
		map[j++][k] = '\0';
		k = 0;
		i++;
	}
	map[j] = 0;
	return (map);
}

int	start_map(t_map_cube *cube)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	if (!cube->map || !cube->map[i])
		return (0);
	while (cube->map[i][j] != '\0')
	{
		if (cube->map[i][j] != '1' && cube->map[i][j] != ' ')
		{
			i++;
			j = -1;
			k = 1;
		}
		j++;
	}
	if (i == count_size_map(cube) - 1 && k == 1)
		return (0);
	return (i);
}

int	split_map_info(t_map_cube *cube)
{
	int		i;
	char	**map;
	char	**map_infos;

	i = start_map(cube);
	if (i == 0)
		return (1);
	map = copy_only_map(cube, i);
	if (!map)
	{
		free_map2(map);
		return (1);
	}
	map_infos = copy_only_map_infos(cube, i);
	if (!map_infos)
	{
		free_map2(map);
		return (1);
	}
	free_map2(cube->map);
	cube->map = map;
	cube->map_infos = map_infos;
	/*A retiré*/
	// printf("\n");
	// print_map(cube);
	// printf("\n");
	// print_map_infos(map_infos);
	/*********/
	return (0);
}

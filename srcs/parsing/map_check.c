/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellehmim <ellehmim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:46:31 by ellehmim          #+#    #+#             */
/*   Updated: 2024/10/01 19:16:53 by ellehmim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strchr_cub(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

int	valide_map(t_map *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cub->map[i])
	{
		while (cub->map[i][j])
		{
			if (!ft_strchr_cub("10NSEW ", cub->map[i][j]))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	valide_map_infos2(t_map *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = strlen(cub->map_infos[i]);
		if (!(cub->map_infos[i][j - 1] == 'm' && cub->map_infos[i][j
			- 2] == 'p' && cub->map_infos[i][j - 3] == 'x'
			&& cub->map_infos[i][j - 4] == '.'))
			return (1);
		i++;
	}
	return (0);
}

int	valide_map_infos(t_map *cub)
{
	if (cub->map_infos[0][0] != 'N' || cub->map_infos[0][1] != 'O')
		return (1);
	if (cub->map_infos[1][0] != 'S' || cub->map_infos[1][1] != 'O')
		return (2);
	if (cub->map_infos[2][0] != 'W' || cub->map_infos[2][1] != 'E')
		return (3);
	if (cub->map_infos[3][0] != 'E' || cub->map_infos[3][1] != 'A')
		return (4);
	if (cub->map_infos[4][0] != 'F')
		return (5);
	if (cub->map_infos[5][0] != 'C')
		return (6);
	if (valide_map_infos2(cub))
		return (7);
	return (0);
}

char    *ft_strdup_road(char *str)
{
    size_t    i;
    int     j;
    char    *res;

    i = 2;
    j = 0;
    res = malloc(sizeof(char) * ft_strlen(str) - 1);
    if (!res)
        return (NULL);
    while (str[i])
    {
        if (str[i] < 0)
            str[i] *= -1;
        res[j] = str[i];
        i++;
        j++;
    }
    res[j] = '\0';
    return (res);
}

void init_valide_road(t_map *cub)
{
    cub->no = ft_strdup_road(cub->map_infos[0]);
    cub->so = ft_strdup_road(cub->map_infos[1]);
    cub->we = ft_strdup_road(cub->map_infos[2]);
    cub->ea = ft_strdup_road(cub->map_infos[3]);
}

int    check_map(t_map *cub)
{
    if (valide_map(cub))
        return (1);
    if (valide_map_infos(cub))
        return (1);
    init_valide_road(cub);
    if (valide_rgb(cub))
        return (1);
    return (0);
}

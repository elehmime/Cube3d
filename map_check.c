/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellehmim <ellehmim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:46:31 by ellehmim          #+#    #+#             */
/*   Updated: 2024/09/29 13:05:46 by ellehmim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_strchr_cube(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char) c)
			return (1);
		i++;
	}
	return (0);
}

int	valide_map(t_map_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cube->map[i])
	{
		while (cube->map[i][j])
		{
			if (!ft_strchr_cube("10NSEW ", cube->map[i][j]))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	valide_map_infos2(t_map_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = strlen(cube->map_infos[i]);
		if (!(cube->map_infos[i][j - 1] == 'm' &&
            cube->map_infos[i][j - 2] == 'p' &&
                cube->map_infos[i][j - 3] == 'x' &&
                    cube->map_infos[i][j - 4] == '.'))
			return (1);
		i++;
	}
    return (0);
}

int	valide_map_infos(t_map_cube *cube)
{
	if (cube->map_infos[0][0] != 'N' || cube->map_infos[0][1] != 'O')
		return (1);
	if (cube->map_infos[1][0] != 'S' || cube->map_infos[1][1] != 'O')
		return (2);
	if (cube->map_infos[2][0] != 'W' || cube->map_infos[2][1] != 'E')
		return (3);
	if (cube->map_infos[3][0] != 'E' || cube->map_infos[3][1] != 'A')
		return (4);
	if (cube->map_infos[4][0] != 'F')
		return (5);
	if (cube->map_infos[5][0] != 'C')
		return (6);
	if (valide_map_infos2(cube))
		return (7);
	return (0);
}

int	check_map(t_map_cube *cube)
{
	if  (valide_map(cube))
        return (1);
    if (valide_map_infos(cube))
        return (1);
    if (valide_rgb(cube))
    {
        return (1);
    }
	return (0);
}
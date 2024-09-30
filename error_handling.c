/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellehmim <ellehmim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:13:24 by ellehmim          #+#    #+#             */
/*   Updated: 2024/09/30 17:54:36 by ellehmim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void msg_error(t_map_cube *cube)
{
	free(cube);
    printf("error\n");
    exit (1);
}
void	print_map_infos(char **map_infos)
{
    int i = 0;
    while (map_infos[i])
        printf("%s\n", map_infos[i++]);
}

void	print_map(t_map_cube *cube)
{
	int i = 0;
	while (cube->map[i])
		printf("%s\n", cube->map[i++]);
}

void	free_map(t_map_cube *cube)
{
	free_map2(cube->map);
	free_map2(cube->map_infos);
    free(cube);
}

void free_map2(char **map)
{
    int i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

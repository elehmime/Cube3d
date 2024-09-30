/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellehmim <ellehmim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:33:57 by ellehmim          #+#    #+#             */
/*   Updated: 2024/09/30 18:02:41 by ellehmim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	count_size_map(t_map_cube *cube)
{
	int	i;

	i = 0;
	if (!cube->map)
		return (0);
	while (cube->map[i])
		i++;
	return (i);
}

int	ft_strlen_cub(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == ' ')
			c++;
		i++;
	}
	return (i - c);
}

void	final_map(t_map_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cube->map[i])
	{
		j = 0;
		while (cube->map[i][j])
		{
			if (cube->map[i][j] == 'X')
				cube->map[i][j] = '1';
			j++;
		}
		i++;
	}
}

// int	*map_int(t_map_cube *cube)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (cube->map[i])
// 	{
// 		j = 0;
// 		while (cube->map[i][j])
// 		{
// 			if (cube->map[i][j] == 'X')
// 				cube->map[i][j] = '1';
// 			j++;
// 		}
// 		i++;
// 	}	
// }

int	parsing(int ac, char **av, t_map_cube *cube)
{
	creat_map(ac, av, cube);
	print_map(cube);
	if (split_map_info(cube))
		return (1);
	if (check_map(cube))
		return (1);
	if (map_playable(cube))
		return (1);
	printf("map valide\n");
	return (0);
}

int	main(int ac, char **av)
{
	t_map_cube	*cube;

	cube = (t_map_cube *)ft_calloc(1, sizeof(t_map_cube));
	if (!cube)
		return (printf("error\n"));
	if (parsing(ac, av, cube))
		return (printf("invalide map\n"));
	final_map(cube);
	print_map(cube);
	free_map(cube);
	return (0);
}
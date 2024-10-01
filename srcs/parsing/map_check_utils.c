/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellehmim <ellehmim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:36:23 by ellehmim          #+#    #+#             */
/*   Updated: 2024/10/01 19:17:13 by ellehmim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_map_rgb(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*new_line(char *str)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = strlen(str);
	dest = (char *)malloc(sizeof(char) * j);
	if (!dest)
		return (NULL);
	j = 0;
	i++;
	while (str[i])
	{
		dest[j] = str[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int	value_rgb(char **rgb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		j = 0;
		while (rgb[i][j])
		{
			if (!ft_strchr_cub("0123456789", rgb[i][j]))
				return (1);
			j++;
		}
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
			return (1);
		i++;
	}
	return (0);
}

int init_valide_rgb(char **str, int i)
{
    int        j;
    char    *tmp;
    char    **rgb;

    tmp = new_line(str[i]);
    rgb = ft_split(tmp, ',');
    if (value_rgb(rgb))
    {
        free(tmp);
        free_map2(rgb);
        return (-1);
    }
    j = ft_atoi(rgb[0]) * 65536 + ft_atoi(rgb[1]) * 256 + ft_atoi(rgb[2]);
    free(tmp);
    free_map2(rgb);
    return (j);
}

int    valide_rgb(t_map *cub)
{
    int        i;

    i = count_map_rgb(cub->map_infos);
    if (i != 6)
        return (1);
    cub->c_rgb = init_valide_rgb(cub->map_infos, 5);
    if (cub->c_rgb == -1)
        return (1);
    cub->f_rgb = init_valide_rgb(cub->map_infos, 4);
    if (cub->f_rgb == -1)
    {
        printf("Error\n");
        return (1);
    }
    printf("cub->c_rgb = %d\n", cub->c_rgb);
    printf("cub->f_rgb = %d\n", cub->f_rgb);
    return (0);
}

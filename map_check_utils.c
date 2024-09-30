/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellehmim <ellehmim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:36:23 by ellehmim          #+#    #+#             */
/*   Updated: 2024/09/29 15:24:34 by ellehmim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int count_map_rgb(char **str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *new_line(char *str)
{
    int i;
    int j;
    char *dest;

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

int     value_rgb(char **rgb)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < 3)
    {
        j = 0;
        while (rgb[i][j])
        {
            if (!ft_strchr_cube("0123456789" ,rgb[i][j]))
                return (1);
            j++;
        }
        if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
            return (1);  
        i++;
    }
    return (0);
}

int    valide_rgb(t_map_cube *cube)
{
    int     i;
    int     j;
    char    *tmp;
    char    **rgb;

    i = count_map_rgb(cube->map_infos);
    j = i;
    if (i != 6)
        return (1);
    while (i > (j - 2))
    {
        tmp = new_line(cube->map_infos[i - 1]);
        rgb = ft_split(tmp, ',');
        int j = value_rgb(rgb);
        if (j)
        {
            free(tmp);
            free_map2(rgb);
            return (1);           
        }
        free(tmp);
        free_map2(rgb);
        i--;
    }
    return (0);
}

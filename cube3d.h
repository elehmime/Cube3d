/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellehmim <ellehmim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:37:33 by ellehmim          #+#    #+#             */
/*   Updated: 2024/09/30 17:57:06 by ellehmim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H 

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

typedef struct map_cube
{
	char	**map;
	char	**map_infos;
}			t_map_cube;

/*parsing*/
int		parsing(int ac, char **av, t_map_cube  *cube);
int		ft_strlen_cub(char *str);
int		count_size_map(t_map_cube *cube);

/*map_creat*/
int	    line_map(t_map_cube *cube, char *av, char **chain);
char	*so_join(char *s1, char *s2);
char	*so_dup(char *str, char *s1, char *s2);
void	creat_map(int ac, char **av, t_map_cube *cube);
void	valide_file(t_map_cube *cube, char *str);

/*map_split*/
int  	split_map_info(t_map_cube *cube);
int		start_map(t_map_cube *cube);
char	*map_infos_line(char *str);
char	**copy_only_map(t_map_cube *cube, int i);
char	**copy_only_map_infos(t_map_cube *cube, int i);

/*map_check*/
int		check_map(t_map_cube *cube);
int		valide_map_infos(t_map_cube *cube);
int		valide_map_infos2(t_map_cube *cube);
int		valide_map(t_map_cube *cube);
int		ft_strchr_cube(const char *str, char c);

/*map_check_utils*/
int		valide_rgb(t_map_cube *cube);
int		value_rgb(char **rgb);
int		count_map_rgb(char **str);
char	*new_line(char *str);

/*map_playable*/
int		map_playable(t_map_cube *cube);
char	**copy_map_playable(char **map);
char	**overlay_the_map(char **map, char **map_cpy);
char	*copy_map_line(char *str, int f);
char	*first_and_last_line(char **map);

/*map_playable_utils*/
int		map_close(char **map_cpy);
int		position_player(char **map, char c, int i, int j);

/*provisoir*/
void	free_map(t_map_cube *cube);
void	print_map(t_map_cube * cube);
void    msg_error(t_map_cube *cube);
void	print_map_infos(char **map_infos);
void	free_map2(char **map);

#endif
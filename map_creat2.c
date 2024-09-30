/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creat2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellehmim <ellehmim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:14:59 by ellehmim          #+#    #+#             */
/*   Updated: 2024/09/30 17:55:46 by ellehmim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int ft_strlen_cub(char *str)
{
	int i;
	int c;

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

char	*so_dup(char *str, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[j])
	{
		while (s1[j] == ' ' && s1[j])
			j++;
		if (s1[j] == '\0')
			break ;		
		str[i++] = s1[j++];
	}
	j = 0;
	while (s2[j])
	{
		while (s2[j] == ' ' && s2[j])
			j++;
		if (s2[j] == '\0')
			break ;
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}

char	*so_join(char *s1, char *s2)
{
	char	*str;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
	{
		if (s1)
			free(s1);
		return (0);
	}
	str = malloc (sizeof(char) * (ft_strlen_cub(s1) + ft_strlen_cub(s2) + 1));
	if (!str)
	{
		if (s1)
			free(s1);
		return (0);
	}
	str = so_dup(str, s1, s2);
	free(s1);
	return (str);
}

int	line_map(char *av, char **chain)
{
	char	*buffer;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		msg_error(cube);
	*chain = 0;
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break ;
		*chain = so_join(*chain, buffer);
		if (*chain == 0)
		{
			free(chain);
			return (0);
		}
		if (buffer)
			free(buffer);
	}
	close(fd);
	return (1);
}
void	valide_file(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (!(str[i - 1] == 'b') || !(str[i - 2] == 'u')
		|| !(str[i - 3] == 'c') || !(str[i - 4] == '.'))
		msg_error(cube);
}

void	creat_map(int ac, char **av, t_map_cube *cube)
{
	char	*chain;

	if (ac != 2)
		exit (EXIT_FAILURE);
	valide_file(av[1]);
	if (line_map(av[1], &chain) == 0)
		exit (EXIT_FAILURE);
    cube->map = 0;
	cube->map = ft_split(chain, '\n');
	if (!cube->map)
	{
		free(chain);
		msg_error(cube);
	}
	free(chain);
}

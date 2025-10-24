/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproust <cproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:30:16 by cproust           #+#    #+#             */
/*   Updated: 2025/10/24 15:51:08 by cproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	parse_map_line(char *line, t_map *map)
{
	int		i;

	i = 0;
	while (line[i] == ' ' || line[i] == '1' || line[i] == '0' || line[i] == 'N'\
		|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W' || line[i] == '2')
		i++;
	if (line[i] != '\0')
		return (ft_printf("Error\nInvalid character in map line\n"), -1);
	if (!ft_realloc_map(line, map))
		return (ft_printf("Error\nMemory allocation failed for map\n"), -1);
	return (1);
}

int	col_check_invalid_char(char *line)
{
	int	i;

	if (line[0] == ',' || line[0] == '\0')
		return (1);

	i = 0;
	while (line[i])
	{
		if (!(ft_isdigit(line[i]) || line[i] == ' ' || line[i] == ','))
			return (1);
		if (line[i] == ',' && line[i + 1] == ',')
			return (1);
		i++;
	}

	if (i > 0 && line[i - 1] == ',')
		return (1);

	return (0);
}

static int	parse_color(char *line, t_color *color)
{
	char	**colors;
	int		r;
	int		g;
	int		b;

	line = remove_whitespace(line);
	if (col_check_invalid_char(line))
		return (ft_printf("Error\nInvalid character in color line\n"), -1);
	if (*color != 0x00000000)
		return (ft_printf("Error\nMultiple color definition\n"), -1);
	if (ft_str_is_empty(line))
		return (ft_printf("Error\nColor definition is empty\n"), -1);
	colors = ft_split(line, ',');
	if (!colors || !colors[0] || !colors[1] || !colors[2] || colors[3])
		return (ft_printf("Error\nInvalid color format\n"), -1);
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	free_arr((void ***)&colors);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (ft_printf("Error\nInvalid color values\n"), -1);
	*color = (0xFF << 24) | (r << 16) | (g << 8) | b;
	return (1);
}

static int	parse_wall(char *line, char **text)
{
	int	fd;

	if (ft_str_is_empty(line))
		return (ft_printf("Error\nWall text path is empty\n"), -1);
	if (!ft_strendwith(line, ".xpm"))
		return (ft_printf("Error\nWrong file extension\n"), -1);
	fd = open(line, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nUnable to open map file : %s \n", line), -1);
	close(fd);
	if (*text)
		return (ft_printf("Error\nDuplicate wall text definition\n"), -1);
	*text = ft_strdup(line);
	if (!*text)
		return (ft_printf("Error\nMemory allocation failed for text\n"), -1);
	return (1);
}

int	parse_line(char *line, t_map *map, int *line_c)
{
	if (ft_str_is_empty(line) && map->map == NULL)
		return (0);
	if (ft_str_is_empty(line) && map->map != NULL)
		return (ft_printf("Error\nInvalid map"), 1);
	else if (ft_strstartwith(line, "NO ") && *line_c < OPT_NB)
		return ((*line_c)++, parse_wall(line + 3, &map->wall_text_path[NORTH]));
	else if (ft_strstartwith(line, "SO ") && *line_c < OPT_NB)
		return ((*line_c)++, parse_wall(line + 3, &map->wall_text_path[SOUTH]));
	else if (ft_strstartwith(line, "EA ") && *line_c < OPT_NB)
		return ((*line_c)++, parse_wall(line + 3, &map->wall_text_path[EAST]));
	else if (ft_strstartwith(line, "WE ") && *line_c < OPT_NB)
		return ((*line_c)++, parse_wall(line + 3, &map->wall_text_path[WEST]));
	else if (ft_strstartwith(line, "C ") && *line_c < OPT_NB)
		return ((*line_c)++, parse_color(line + 2, &map->ceiling_col));
	else if (ft_strstartwith(line, "F ") && *line_c < OPT_NB)
		return ((*line_c)++, parse_color(line + 2, &map->floor_col));
	else if (*line_c >= OPT_NB)
	{
		if (*line_c == OPT_NB)
			ft_printf("Map options processed... Parsing map matrice\n");
		return ((*line_c)++, parse_map_line(line, map));
	}
	return (ft_printf("Error\nUnexpected non-option token\n"), -1);
}

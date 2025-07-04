/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproust <cproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:30:16 by cproust           #+#    #+#             */
/*   Updated: 2025/07/04 16:21:26 by cproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	parse_map_line(char *line, t_map *map)
{
	int		i;

	i = 0;
	while (line[i] == ' ' || line[i] == '1' || line[i] == '0' || line[i] == 'N'\
		|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W' || line[i] == 'D' \
		|| line[i] == 'B')
		i++;
	if (line[i] != '\0')
		return (ft_printf("Error: Invalid character in map line\n"), -1);
	if (!ft_realloc_map(line, map))
		return (ft_printf("Error: Memory allocation failed for map\n"), -1);
	return (1);
}

static int	parse_color(char *line, t_color *color)
{
	char	**colors;
	int		r;
	int		g;
	int		b;

	if (ft_str_is_empty(line))
		return (ft_printf("Error: Color definition is empty\n"), -1);
	colors = ft_split(line, ',');
	if (!colors || !colors[0] || !colors[1] || !colors[2] || colors[3])
		return (ft_printf("Error: Invalid color format\n"), -1);
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	free_arr((void **)colors);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (ft_printf("Error: Invalid color values\n"), -1);
	*color = (0xFF << 24) | (r << 16) | (g << 8) | b;
	return (1);
}

static int	parse_w_text(char *line, char **text)
{
	int	fd;

	if (ft_str_is_empty(line))
		return (ft_printf("Error: texture path is empty\n"), -1);
	if (*text)
		return (ft_printf("Error: Duplicate texture definition\n"), -1);
	if (ft_strcmp(line + ft_strlen(line) - 4, ".xpm") != 0)
		return (ft_printf("Error: texture must end with '.xpm'\n"), -1);
	fd = open(line, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error: Texture file not found '%s'\n", line), -1);
	close(fd);
	*text = ft_strdup(line);
	if (!*text)
		return (ft_printf("Error: Memory allocation failed for text\n"), -1);
	return (1);
}

static int	parse_sprite_text(char *line, char **text)
{
	if (ft_str_is_empty(line))
		return (ft_printf("Error: Sprite path is empty\n"), -1);
	line = ft_strtrim(line, " \t");
	if (*text)
		return (ft_printf("Error: Duplicate sprite definition\n"), -1);
	*text = ft_strdup(line);
	if (!*text)
		return (ft_printf("Error: Memory allocation failed for sprite\n"), -1);
	return (1);
}

int	parse_line(char *line, t_map *map, int *line_c)
{
	if (ft_str_is_empty(line) && map->map == NULL)
		return (0);
	if (ft_str_is_empty(line) && map->map != NULL)
		return (ft_printf("Error: Invalid map\n"), -1);
	else if (ft_strstartwith(line, "D ") && map->map == NULL)
		return (parse_sprite_text(line + 2, &map->door_text));
	else if (ft_strstartwith(line, "SP ") && map->map == NULL)
		return (parse_sprite_text(line + 3, &map->sprite_text));
	else if (ft_strstartwith(line, "NO "))
		return ((*line_c)++, parse_w_text(line + 3, &map->wall_text[NORTH]));
	else if (ft_strstartwith(line, "SO "))
		return ((*line_c)++, parse_w_text(line + 3, &map->wall_text[SOUTH]));
	else if (ft_strstartwith(line, "EA "))
		return ((*line_c)++, parse_w_text(line + 3, &map->wall_text[EAST]));
	else if (ft_strstartwith(line, "WE "))
		return ((*line_c)++, parse_w_text(line + 3, &map->wall_text[WEST]));
	else if (ft_strstartwith(line, "C "))
		return ((*line_c)++, parse_color(line + 2, &map->ceiling_col));
	else if (ft_strstartwith(line, "F "))
		return ((*line_c)++, parse_color(line + 2, &map->floor_col));
	else if (*line_c == OPT_NB)
		return (parse_map_line(line, map));
	return (ft_printf("Error: Invalid line format\n"), -1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:35:37 by mmasstou          #+#    #+#             */
/*   Updated: 2022/08/30 18:35:38 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(int x, int y, t_data *data, int color)
{
	char	*dst;

	if ((x >= 0 && x < W) && (y >= 0 && y < H))
	{
		dst = data->mlx_vars->buffer + (y * data->mlx_vars->line_lenght + x * (data->mlx_vars->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void    draw_rect(float x, float y, t_data *data, int color, int type)
{
	int index;
	int jndex;
	int old__y;
	
	// y += H  - (data->map_size.x * data->unit);
	index = (x + data->unit);
	jndex = (y + data->unit); 
	old__y = y;
	while (x <= index - type)
	{
		y = old__y;
		while (y <= jndex - type)
			my_mlx_pixel_put(x, y++, data, color);
		x++;
	}
}

void    draw_ceilling_floor(t_data *data)
{
    int index;
    int jndex;
    int color;

    index = 0;
    color = ft_rgb(0, data->c.r,data->c.g, data->c.b);
    while (index <= H)
    {
        if (index == H / 2)
            color = ft_rgb(0, data->f.r,data->f.g, data->f.b);
        jndex = 0;
        while (jndex <= W)
        {
            my_mlx_pixel_put(jndex, index, data, color);
            jndex++;
        }
        index++;
    }
}

int	draw__map(t_data *data){
	
	int index = 0;
	int jndex = 0;
	int rect_color;
	int i;
	data->unit = 20;
	// data->map_size.x = H  - (data->map_size.x * data->unit);
	while (data->map[index])
	{
		jndex = 0;
		while (data->map[index][jndex] && data->map[index][jndex] != '\n')
		{
			i = 0;
			if (data->map[index][jndex] == '1')
			{
				rect_color = WALL;
				i = 0;
			}
			else if (data->map[index][jndex] == '0' || ft_strchr("SNWE", data->map[index][jndex]) != NULL)
				rect_color = EMPTY_SPACE;
			else if (data->map[index][jndex++] == ' ')
				continue;
			draw_rect(jndex * data->unit, index * data->unit, data, rect_color, i);
			jndex ++;
		}
		index ++;
	}
	return (0);
}
int	arraylen(char **array){
	int index;

	index = -1;
	while (array[++index])
		;
	return (index);
}
int	wall_collaction(float index, float jndex, t_data *data){
	
	int x;
	int y;
	int	array_len;
	int str_len;

	array_len = arraylen(data->map);
	x = floor(index);
	y = floor(jndex);

	if(y > array_len || y < 0)
		return (1);
	if (y >= 0 && data->map[y] != NULL)
	{
		str_len = ft_strlen(data->map[y]);
		if (x > str_len || x < 0)
			return (1);
		if (data->map[y][x] == '1' || data->map[y][x] == ' ')
			return (1);
		else if (data->map[y][x] == '0' || ft_strchr("SWNE", data->map[y][x]) != NULL)
			return (0);
	}
	return (1);
	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:24:12 by mmasstou          #+#    #+#             */
/*   Updated: 2022/08/26 15:34:26 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
void	get_player_pos(int x, int y, t_data **data)
{
	(*data)->ply->x_pos = x;
	(*data)->ply->y_pos = y;
	// (*data)->ply->spawning_orientation = (*data)->map[x][y];
	// printf("--+> %c\n", (*data)->ply->spawning_orientation);
}

void	check_minimap(char **minimap, t_data *data)
{
	int	index;
	int	jndex;

	index = -1;
	while (minimap[++index])
	{
		jndex = -1;
		while (minimap[index][++jndex] != '\0' && minimap[index][jndex] != '\n')
		{
			if (minimap[index][jndex] == SPACE || minimap[index][jndex] == ONE)
				continue ;
			else if ( minimap[index][jndex] == ZERO || \
				is_player(minimap[index][jndex], data) == true)
			{
				
				chech_direction(minimap, index - 1, jndex);
				chech_direction(minimap, index + 1, jndex);
				chech_direction(minimap, index, jndex - 1);
				chech_direction(minimap, index, jndex + 1);
			}
			else
				_error("Stranger Element");
		}
	}
	if (data->p == 0)
		_error("No player in Map");
	stock_minimap(minimap, &data, index + 1);
}
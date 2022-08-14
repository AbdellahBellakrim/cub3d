/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:20:48 by mmasstou          #+#    #+#             */
/*   Updated: 2022/08/12 15:55:07 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	checkleaks(void)
{
	printf("\033[0;31m----------------------------\n");
	system("leaks cub3D");
	printf("\n----------------------------\n\033[0m");
}

int	init_data(t_data *data)
{
	data->map = NULL;
	data->start_map = 0;
	data->p = 0;
	data->exit.no = 0;
	data->params = 0;
	return (0);
}

void	starting_windows(void)
{
	void	*mlx;
	void	*win;
	char	*str;
	// void	*img;

	// int x = 500;
	// int y =  500;
	str = ft_strdup("Hello i'm mmasstou");
	mlx = mlx_init();
	win = mlx_new_window(mlx, W, H , "-&- Cub3D -&-");
	mlx_string_put(mlx, win, (W / 2) - (W * 0.06) , 10, 0x219ebc, str);
	// img = mlx_png_file_to_image(mlx, "utils/3d.png", &x, &y);
	// mlx_put_image_to_window(mlx, win, img, x, y);
	mlx_loop(mlx);
}

void	free_data(t_data *data)
{
	free(data->ea);
	free(data->we);
	free(data->so);
	free_2d(data->map);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	(void)argc;
	atexit(checkleaks);
	checkargs(argc, argv);
	init_data(&data);
	parsing(argv, &data);
	// starting_windows();
	free_data(&data);
	return (0);
}

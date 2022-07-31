#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "utils/libft/libft.h"

# define COLOR_SUCCESS "\033[38;5;42m"
# define COLOR_FAILURE "\x1b[31m"
# define COLOR_END "\x1b[0m"

typedef struct color
{
    int r;
    int g;
    int b;
}   t_color;

typedef struct data
{
    char    *no;
    char    *so;
    char    *we;
    char    *ea;
    t_color f;
    t_color c;
    char  **map;
}   t_data;
//----------------------------- Parsing
void    parsing(char *argv[], t_data *data);

#endif
#include "cub3d.h"


void    checkLeaks()
{
    printf("\033[0;31m----------------------------\n");
    system("leaks cub3D");
    printf("\n----------------------------\n\033[0m");
}


int main(int argc, char *argv[])
{
    t_data  data;

    atexit(checkLeaks);
    parsing(argv, &data);
    printf("Cub3d\n");
    return (0);
}
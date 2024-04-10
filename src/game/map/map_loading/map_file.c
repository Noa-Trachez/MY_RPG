/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Load .txt map file
*/

#include "my_rpg.h"

int error_on_file(FILE *fd)
{
    return (!fd ? 1 : 0);
}

long long int get_bytes(char const *file, int line_or_char)
{
    FILE *fd = fopen(file, "r");
    size_t bufsize = 0;
    char *buffer = NULL;
    int len = 0;
    long long int bytes = 0;
    long long int lines = 1;

    if (error_on_file(fd))
        return (-1);
    while (lines > 0) {
        lines = getline(&buffer, &bufsize, fd);
        bytes += lines;
        len++;
    }
    fclose(fd);
    return (line_or_char == 0 ? len - 1 : bytes + 1);
}

char *read_map_file(char const *path)
{
    int size = (int)get_bytes(path, 1);
    char *buffer = malloc(size + 1);
    int fd = open(path, O_RDONLY);

    memset(buffer, 0, size + 1);
    read(fd, buffer, size);
    close(fd);
    return (buffer);
}

void load_map(map_t *map, char const *path)
{
    char *map_file = read_map_file(path);

    for (long long i = 0; map_file[i]; i++) {
        if (!my_strncmp("mapWidth = ", map_file + i, 11))
            map->mapsize.x = my_getnbr(map_file + i + 11);
        if (!my_strncmp("mapHeight = ", map_file + i, 12))
            map->mapsize.y = my_getnbr(map_file + i + 12);
        if (!my_strncmp("tileWidth = ", map_file + i, 12))
            map->tilesize.x = (float)my_getnbr(map_file + i + 12);
        if (!my_strncmp("tileHeight = ", map_file + i, 13)) {
            map->tilesize.y = (float)my_getnbr(map_file + i + 13);
            break;
        }
    }
    for (long long i = 0; map_file[i]; i++)
        if (!my_strncmp("data = {", map_file + i, 8))
            return (load_obstacles(&map->obstacles, map_file + i + 8, map));
}

#include "so_long.h"

int ft_count_lines(char **map)
{
    int lines;
    int i;

    i = 0;
    lines = 0;
    while (map[i])
    {
        ++lines;
        ++i;
    }
    return (lines);
}
char    **get_map1(int fd)
{
    char    **map;
    char    *buff;
    char    *tmp;

    buff = NULL;
    tmp = get_next_line(fd);
    while (tmp)
    {
        buff = ft_strjoin(buff, tmp);
        free (tmp);
        tmp = get_next_line(fd);
    }
    close(fd);
    buff = ft_strjoin(buff, "\n");
    map = ft_split(buff, '\n');
    return (free(buff), map);
}

char    **copy_map1(char **map)
{
    int     map_len;
    char    **copy;
    int     lines;
    int     i;
    int     j;

    i = -1;
    map_len = ft_strlen(map[0]);
    lines = ft_count_lines(map);
    copy = malloc(sizeof(char *) * (lines + 1));
    while (map[++i])
        copy[i] = malloc(map_len + 1);
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            copy[i][j] = map[i][j];
            ++j;
        }
        copy[i][j + 1] = '\0';
        ++i;
    }
    return (copy);
}

int main(void)
{
    char  **map;

    map = get_map1(open("v_map01.ber", O_RDONLY));
    char **copy = copy_map1(map);
    int i = 0;
    while (copy[i])
    {
        printf("%s\n", copy[i]);
        ++i;
    }
}
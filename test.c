#include "so_long.h"

void    ft_fill_buff(char **buff, int fd, int lines)
{
    int i;

    // lseek(fd, );
    i = 0;
    while (i < lines)
    {
        buff[i] = get_next_line(fd);
        ++i;
    }
    buff[i] = NULL;
}

char    **get_map(char *file_name)
{
    char    **buff;
    char    *tmp;
    int     len;
    int     fd;
    int     i;

    i = 1;
    len = 0;
    fd = open(file_name, O_WRONLY);
    tmp = get_next_line(fd);
    if (!tmp)
        return (NULL);
    free (tmp);
    while (tmp)
    {
        tmp = get_next_line(fd);
        free (tmp);
        ++i;
    }
    if (len > 0)
        buff = (char **)malloc(sizeof(char) * i + 1);
    if (!buff)
        return (NULL);
    ft_fill_buff(buff, fd, i);
    return (buff);
}

int main()
{
    char **map = get_map("v_map01.ber");
    int i = 0;
    while (map[i])
    {
        printf("%s\n", map[i]);
        ++i;
    }
}
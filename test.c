#include "so_long.h"

int main(void)
{
    char **map = get_map("aba.ber");
    printf ("%s\n", map[0]);
    // printf("%d\n", is_valid_map(map, ft_count_lines(map), ft_strlen(map[0])));
}
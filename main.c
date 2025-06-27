#include <stdio.h>
#include <stdlib.h>
#include "cub3d.h"
#include "parsing.h"


void increment(int *j)
{
	(*j)++;
}

int main()
{
	int fd = 0;
	int j = 0;
	char *line = NULL;
	fd = open("delete_this/test.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("Line %d: %s\n", j, line);
		free(line);
		increment(&j);
	}
}	
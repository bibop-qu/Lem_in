
#include "lem-in.h"

int		size_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		verif_line_room(char *line)
{
	char **tab;

	tab = ft_strsplit(line, ' ');
	if (size_tab(tab) != 3)
		return (0);
	return (1);
}

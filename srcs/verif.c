
#include "lem-in.h"

int		ft_strform(char *str, int id)
{
	int		i;

	i = 0;
	while (id == 0 && str[i] && ft_isalnum(str[i]))
	{
		i++;
		if (!str[i])
			return (1);
	}
	while (id == 1 && str[i] && ft_isdigit(str[i]))
	{
		i++;
		if (!str[i])
			return (1);
	}
	return (0);
}

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
	if (tab[0][0] == '#' || tab[0][0] == 'L')
		return (0);
	if (ft_strform(tab[0], 0) && ft_strform(tab[1], 1) && ft_strform(tab[2], 1))
		return (1);
	else
		return (0);
}

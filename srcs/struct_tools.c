
#include "lem-in.h"

t_room		*ft_add_room(t_room *room, char *line)
{
	t_room	*new;
	t_room	*tmp;
	char	**tab;

	new = (t_room *)malloc(sizeof(t_room));
	tab = ft_strsplit(line, ' ');
	new->name = ft_strdup(tab[0]);
	new->pos_x = ft_atoi(tab[1]);
	new->pos_y = ft_atoi(tab[2]);
	new->next = NULL;
	tmp = room;
	free_tab(tab);
	if (room == NULL)
		return (new);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		return (room);
	}
}

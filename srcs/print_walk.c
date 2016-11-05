
#include "lem-in.h"

t_ant	*create_ant(int id)
{
	t_ant	*ant;

	ant = (t_ant*)malloc(sizeof(t_ant));
	ant->nb = id;
	ant->map = NULL;
	ant->road = NULL;
	ant->next = NULL;
	return (ant);
}

int		get_nb_ant_handled_in_n_turn(t_map *map, t_map *cur)
{
	int		n;
	int		ret;

	n = cur->size - 2;
	ret = 0;
	while (map != cur)
	{
		ret += (n - (map->size - 2));
		map = map->next;
	}
	return (ret);
}

int		chose_path(t_ant *ant, t_data *data)
{
	t_map	*path_it;
	int		nb_ant_left;

	nb_ant_left = data->nbr_ant - ant->nb + 2;
	path_it = data->map;
	while (path_it && path_it->used)
		path_it = path_it->next;
	if (path_it == NULL)
		return (0);
	if (nb_ant_left <= get_nb_ant_handled_in_n_turn(data->map, path_it))
		return (0);
	ant->map = path_it;
	ant->road = path_it->road->next;
	path_it->used = 1;
	path_it->road->usd = 1;
	ft_putstr("L");
	ft_putnbr(ant->nb);
	ft_putstr("-");
	ft_putstr(ant->road->room->name);
	ft_putstr(" ");
	return (1);
}

int		ants_step_foreward(t_ant *ants_save, t_ant *ant, t_data *data)
{
	t_ant	*tmp;
	int		ret;

	ret = 0;
	tmp = ants_save;
	ft_putchar('\n');
	while (tmp && tmp != ant)
	{
		tmp->map->used = 0;
		if (tmp->road->next && tmp->road->next->usd == 0)
		{
			tmp->road->usd = 0;
			tmp->road = tmp->road->next;
			ret = 1;
			ft_putstr("L");
			ft_putnbr(tmp->nb);
			ft_putstr("-");
			ft_putstr(tmp->road->room->name);
			ft_putstr(" ");
		}
		tmp = tmp->next;
	}
	data->nbr_turn = data->nbr_turn + 1;
	return (ret);
}

void	print_walk(t_data *data)
{
	int		idx_ant;
	t_ant	*ant;
	t_ant	*ants_save;

	idx_ant = 0;
	while (++idx_ant <= data->nbr_ant)
	{
		if (idx_ant == 1)
		{
			ant = create_ant(idx_ant);
			ants_save = ant;
		}
		else
		{
			ant->next = create_ant(idx_ant);
			ant = ant->next;
		}
		if (chose_path(ant, data) == 0)
		{
			ants_step_foreward(ants_save, ant, data);
			chose_path(ant, data);
		}
	}
	while (ants_step_foreward(ants_save, NULL, data))
		;
}

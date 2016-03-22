/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:48:53 by basle-qu          #+#    #+#             */
/*   Updated: 2016/03/22 15:20:58 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		best_neighbors(t_room *start, t_room *end)
{
	t_neigh		*tmp_start;
	t_neigh		*tmp_end;
	int			a;
	int			b;

	a = 0;
	b = 0;
	tmp_start = start->neighbors;
	tmp_end = end->neighbors;
	while (tmp_start && ++a > 0)
		tmp_start = tmp_start->next;
	while (tmp_end && ++b > 0)
		tmp_end = tmp_end->next;
	if (a < b)
		return (a);
	return (b);
}

int		size_pipe(t_pipe *pipe)
{
	int		i;
	t_pipe	*tmp;

	i = 0;
	tmp = pipe;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_error(char *error)
{
	char	*tmp;
	char	*final;

	tmp = ft_strjoin("\033[1;31m", error);
	final = ft_strjoin(tmp, "\033[00m");
	free(tmp);
	write(2, final, ft_strlen(final));
	write(2, "\n", 1);
	free(final);
	exit(1);
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

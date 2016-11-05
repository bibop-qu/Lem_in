/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:50:00 by basle-qu          #+#    #+#             */
/*   Updated: 2016/03/22 15:19:59 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

void	ft_error(char *error, t_data *anthill);
void	free_tab(char **tab);
int		best_neighbors(t_room *start, t_room *end);

#endif

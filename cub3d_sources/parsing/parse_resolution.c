/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:52:12 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/04 16:19:25 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

/*
** Convertit une partie d'une chaîne de caractères
** afin de récupèrer un nbr de pixels.
** =========
** #1 : une chaîne de caractères
**		(correspond à la ligne lue par GNL).
** #2 : un pointeur sur une position dans cette chaîne.
** =========
** Retourne un entier positif.
*/

size_t	ft_axis(char *line, size_t *pos)
{
	size_t axis;

	axis = 0;
	if (ft_isspace(line[*pos]) == 1)
		ft_skip_spaces(line, pos);
	else
		return (0);
	if (ft_isdigit(line[*pos]) == 1)
	{
		while (ft_isdigit(line[*pos]) == 1)
		{
			axis = (axis * 10) + line[*pos] - 48;
			(*pos)++;
		}
	}
	return (axis);
}

/*
** Récupère, à l'aide de ft_axis(2) les tailles de rendu en pixels
** des axes x et y, et affecte ces valeurs aux champs correspondant
** d'une stucture r de type t_resolution.
** =========
** #1 : une chaîne de caractères
**		(correspond à la ligne lue par GNL).
** #2 : un pointeur sur une position dans cette chaîne.
** #3 : un pointeur sur une t_resolution.
** =========
** Retourne 0 en cas d'erreur, 1 si tout est OK.
*/

int		ft_xy(char *line, size_t *pos, t_resolution *r)
{
	t_resolution	r_2;
	int				ret;

	r_2 = *r;
	ret = 0;
	if ((r_2.x = ft_axis(line, pos)) != 0)
	{
		if ((r_2.y = ft_axis(line, pos)) != 0)
		{
			*r = r_2;
			ret = 1;
		}
	}
	return (ret);
}

/*
** Récupère les informations de résolution
** puis vérifie leur validité ainsi que celle
** du check correspondant et actualise ce dernier
** en "YES" si tout est OK.
** =========
** #1 : une chaîne de caractères
**		(correspond à la ligne lue par GNL).
** #2 : un pointeur sur une position dans cette chaîne.
** #3 : un pointeur sur une t_resolution.
** #4 : un pointeur sur un t_bool.
** =========
** Retourne 0 en cas d'erreur, 1 si tout est OK.
*/

int		ft_r(char *line, size_t *pos, t_resolution *r, t_bool *check)
{
	size_t			pos_2;
	t_resolution	r_2;
	t_bool			check_2;

	pos_2 = *pos;
	r_2 = *r;
	check_2 = *check;
	if ((ft_xy(line, &pos_2, &r_2) == 1) && (check_2 == NO))
	{
		check_2 = YES;
		*pos = pos_2;
		*r = r_2;
		*check = check_2;
		return (1);
	}
	return (0);
}

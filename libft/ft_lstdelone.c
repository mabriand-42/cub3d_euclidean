/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:13:20 by mabriand          #+#    #+#             */
/*   Updated: 2019/11/28 11:51:51 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Libère la mémoire de l’élément passé en argument
 * en utilisant la fonction del puis avec free(3). La
 * mémoire de next ne doit pas être free.
**/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (del != NULL)
		del(lst->content);
	free(lst);
}
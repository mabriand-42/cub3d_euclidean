/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:26:44 by mabriand          #+#    #+#             */
/*   Updated: 2019/11/28 13:03:30 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * renvoie un pointeur sur la dernière occurrence du caractère c dans la chaîne s.
 **/

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	c2;
	char	*str;

	str = (char *)s;
	i = ft_strlen(str);
	c2 = (char)c;
	while (i > 0)
	{
		if (s[i] == c2)
		{
			return ((char *)(str + i));
		}
		i--;
	}
	if (s[i] == c2)
	{
		return ((char *)(str + i));
	}
	return (NULL);
}

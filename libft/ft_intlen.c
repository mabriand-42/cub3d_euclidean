/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:21:46 by mabriand          #+#    #+#             */
/*   Updated: 2020/01/16 14:22:51 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

size_t		ft_intlen(int n)
{
	int				i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}
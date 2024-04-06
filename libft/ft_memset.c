/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:41:36 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/04/05 20:41:53 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int p, size_t size)
{
	size_t			i;
	unsigned char	*memo;

	i = 0;
	memo = (unsigned char *)dest;
	while (i < size)
		memo[i++] = p;
	return (memo);
}

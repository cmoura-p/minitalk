/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:37:20 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/04/16 17:39:15 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	*ft_strjoin(unsigned char *s1, unsigned char s2)
{
	unsigned char	*s3;
	size_t			i;

	if (!s1)
		s1 = (unsigned char *)ft_calloc(1, sizeof(unsigned char));
	if (!s1)
		return (NULL);
	s3 = (unsigned char *)ft_calloc(ft_strlen(s1) + 2, sizeof(unsigned char));
	if (!s3)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	s3[i] = s2;
	free(s1);
	return (s3);
}

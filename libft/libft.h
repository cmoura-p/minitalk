/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:11:12 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/04/16 17:42:31 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int				ft_atoi(const char *str);
void			ft_putnbr(int nb);
size_t			ft_strlen(unsigned char *str);
void			ft_bzero(void *b, size_t len);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memset(void *dest, int p, size_t size);
unsigned char	*ft_strjoin(unsigned char *s1, unsigned char s2);

#endif
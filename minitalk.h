/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:57:03 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/04/16 18:20:01 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

/*   LIBFT   */
int				ft_atoi(const char *str);
void			ft_putnbr(int nb);
size_t			ft_strlen(unsigned char *str);
void			ft_bzero(void *b, size_t len);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memset(void *dest, int p, size_t size);
unsigned char	*ft_strjoin(unsigned char *s1, unsigned char s2);

#endif

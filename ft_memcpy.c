/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kexu <kexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:08:41 by kexu              #+#    #+#             */
/*   Updated: 2025/11/21 11:16:20 by kexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	if (!src && !dest)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;

	while (n--)
		*d++ = *s++;
	return (dest);
}
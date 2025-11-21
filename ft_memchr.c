/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kexu <kexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:59:19 by kexu              #+#    #+#             */
/*   Updated: 2025/11/21 15:23:21 by kexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char *p;
    
    p = (unsigned char*)s;
    while (n--)
    {
        if(*p == (unsigned char)c)
            return p;
        p++;
    }
    return (NULL);
}

#include <stdio.h>
#include <string.h>

int main()
{
    
char s1[20] = "Hello, libft";
char s2[20] = "Hello, libft";
char c1 = 'l';

    void *ret1 = ft_memchr(s1, c1, 10);
    void *ret2 = memchr(s2, c1, 10);

   printf("ft_memchr: ");
    if (ret1)
        printf("%s\n", (char *)ret1);
    else
        printf("NULL\n");

    printf("original: ");
    if (ret2)
        printf("%s\n", (char *)ret2);
    else
        printf("NULL\n");
    return (0);
}

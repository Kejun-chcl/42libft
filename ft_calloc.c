/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kexu <kexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:28:33 by kexu              #+#    #+#             */
/*   Updated: 2025/11/21 15:58:47 by kexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc (size_t nmemb, size_t size)
{
    void * p;
    
    //溢出检测方法
    //若 size == 0，则乘积为 0，不会溢出；
    //若 size != 0 且 count > SIZE_MAX / size，那么 count * size 一定超过最大值，不能安全分配。
    if (size != 0 && nmemb > SIZE_MAX / size)
        return (NULL);

    p = malloc (nmemb *size);
    if(!p)
        return (NULL);
    ft_bzero(p, nmemb *size);
    return (p);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void print_buffer(const unsigned char *buf, size_t len)
{
    for (size_t i = 0; i < len; i++)
        printf("%02X ", buf[i]);
    printf("\n");
}

int main(void)
{
    void *ft_ptr;
    void *ori_ptr;
    size_t i;

    /* -------- 1. 正常分配 -------- */
    ft_ptr  = ft_calloc(5, sizeof(int));
    ori_ptr = calloc(5, sizeof(int));

    printf("正常分配测试:\n");
    print_buffer((unsigned char *)ft_ptr, 5 * sizeof(int));
    print_buffer((unsigned char *)ori_ptr, 5 * sizeof(int));

    free(ft_ptr);
    free(ori_ptr);

    /* -------- 2. nmemb = 0 -------- */
    ft_ptr  = ft_calloc(0, 10);
    ori_ptr = calloc(0, 10);
    printf("nmemb = 0 测试: ft_ptr=%p | ori_ptr=%p\n", ft_ptr, ori_ptr);
    free(ft_ptr);
    free(ori_ptr);

    /* -------- 3. size = 0 -------- */
    ft_ptr  = ft_calloc(10, 0);
    ori_ptr = calloc(10, 0);
    printf("size = 0 测试: ft_ptr=%p | ori_ptr=%p\n", ft_ptr, ori_ptr);
    free(ft_ptr);
    free(ori_ptr);

    /* -------- 4. 溢出情况 -------- */
    size_t big = (size_t)-1;
    ft_ptr  = ft_calloc(big, 2);
    ori_ptr = calloc(big, 2);
    printf("溢出测试: ft_ptr=%p | ori_ptr=%p\n", ft_ptr, ori_ptr);

    /* -------- 5. 内容初始化测试 -------- */
    ft_ptr = ft_calloc(5, sizeof(char));
    printf("ft_calloc 内容初始化测试:\n");
    print_buffer((unsigned char *)ft_ptr, 5);
    free(ft_ptr);

    return 0;
}

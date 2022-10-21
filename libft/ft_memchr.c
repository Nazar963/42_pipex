/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:58:14 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/04 15:04:39 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	*char_found;
	unsigned char	char_to_find;

	str = (unsigned char *)s;
	char_found = NULL;
	char_to_find = (unsigned char)c;
	while (str && n > 0)
	{
		if (*str != char_to_find)
		{
			str++;
		}
		else
		{
			char_found = str;
			break ;
		}
		n--;
	}
	return (char_found);
}
/*int main()
{
    // char s[] = "loco is loco";
    
    // char *ptr = ft_memchr(s,'c',sizeof(s));
    // if (ptr != NULL)
    // {
    //     printf ("'c' found with mine: %ld.\n", ptr - s + 1);
    //     printf ("found:  %s\n", ptr);
    // }
    // else
    //     printf ("not found\n");

    // char sh[] = "loco is loco";
    
    // char *ptrh = memchr(sh,'c',sizeof(sh));
    // if (ptrh != NULL)
    // {
    //     printf ("'c' found with og: %ld.\n", ptrh - sh + 1);
    //     printf ("found:  %s\n", ptrh);
    // }
    // else
    //     printf ("not found\n");
	
	// char *loco = ft_memchr("bonjourno", 'n', 5);
	// printf("%s\n", loco);

	// char *foco = memchr("bonjourno", 'n', 5);
	// printf("%s\n", foco);

	// char *aloco = ft_memchr("bonsjour", 's', 3);
	// printf("%s\n", aloco);

	// char *afoco = memchr("bonsjour", 's', 3);
	// printf("%s\n", afoco);
    return (0);
}*/
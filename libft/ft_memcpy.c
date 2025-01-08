/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:18:47 by sle-nogu          #+#    #+#             */
/*   Updated: 2024/11/17 18:44:42 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str_dest;
	const char		*str_src;

	str_dest = dest;
	str_src = src;
	i = 0;
	if (!src && !dest)
		return (0);
	while (i < n)
	{
		str_dest[i] = str_src[i];
		i++;
	}
	return (dest);
}
/*
int main() {
    // Test 1: Test normal avec une copie partielle
    char str1[10] = "abcdefghi";
    char str_dest1[10] = "";
    printf("Avant ft_memcpy (str1): %s\n", str1);
    ft_memcpy(str_dest1, str1, 5);  // Copier les 5 premiers caractères
    printf("Après ft_memcpy (str_dest1): %s\n\n", str_dest1);

    // Test 2: Test avec n = 0 (aucune modification)
    char str2[10] = "abcdefghi";
    char str_dest2[10] = "";
    printf("Avant ft_memcpy (str2): %s\n", str2);
    ft_memcpy(str_dest2, str2, 0);  // Ne rien copier
    printf("Après ft_memcpy (str_dest2): %s\n\n", str_dest2);

    // Test 3: Test avec une copie complète de la chaîne
    char str3[10] = "abcdefghi";
    char str_dest3[10] = "";
    printf("Avant ft_memcpy (str3): %s\n", str3);
    ft_memcpy(str_dest3, str3, 10);  // Copier toute la chaîne
    printf("Après ft_memcpy (str_dest3): %s\n\n", str_dest3);

    // Test 4: Test avec des chaînes contenant des caractères non imprimables
    char str4[10] = "abc\0defghi";
    char str_dest4[10] = "";
    printf("Avant ft_memcpy (str4): ");
    for (int i = 0; i < 10; i++) {
        printf("%02x ", (unsigned char)str4[i]);
    }
    printf("\n");
    ft_memcpy(str_dest4, str4, 10);
    printf("Après ft_memcpy (str_dest4): ");
    for (int i = 0; i < 10; i++) {
        printf("%02x ", (unsigned char)str_dest4[i]);
    }
    printf("\n\n");

    // Test 5: Test avec des adresses de mémoire qui se chevauchent
    char str5[10] = "abcdefghi";
    printf("Avant ft_memcpy (str5): %s\n", str5);
    ft_memcpy(str5 + 3, str5, 5);  
    printf("Après ft_memcpy (str5): %s\n\n", str5);

    return 0;
}*/

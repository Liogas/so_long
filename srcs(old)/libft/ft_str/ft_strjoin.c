/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:57:41 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:47:48 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	new_s = (char *)malloc((ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
	{
		new_s[j] = s1[i];
		j++;
	}
	i = -1;
	while (s2[++i] != '\0')
	{
		new_s[j] = s2[i];
		j++;
	}
	new_s[j] = '\0';
	return (new_s);
}

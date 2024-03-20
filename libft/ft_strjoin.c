/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:32:59 by dzurita           #+#    #+#             */
/*   Updated: 2023/11/01 10:56:06 by dzurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			size_s1;
	char			*join;
	unsigned int	i;
	unsigned int	j;

	if (!s1)
		size_s1 = 0;
	else
		size_s1 = ft_strlen(s1);
	join = (char *)malloc((size_s1 + ft_strlen(s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = -1;
	while (++i < size_s1)
		join[i] = s1[i];
	j = 0;
	while (i < size_s1 + ft_strlen(s2))
		join[i++] = s2[j++];
	join[i] = '\0';
	return (join);
}

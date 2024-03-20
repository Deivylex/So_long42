/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:06:32 by dzurita           #+#    #+#             */
/*   Updated: 2023/12/11 15:06:38 by dzurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin_gnl(char *s1, char const *s2)
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
	{
		free (s1);
		return (NULL);
	}
	i = -1;
	while (++i < size_s1)
		join[i] = s1[i];
	j = 0;
	while (i < size_s1 + ft_strlen(s2))
		join[i++] = s2[j++];
	join[i] = '\0';
	free(s1);
	return (join);
}

char	*get_new_line(char *rem_data)
{
	int		i;
	char	*str;

	i = 0;
	while (rem_data[i] && rem_data[i] != '\n')
		i++;
	if (rem_data[i] == '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (rem_data[++i] && rem_data[i] != '\n')
		str[i] = rem_data[i];
	if (rem_data[i] == '\n')
	{
		str[i] = rem_data[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_rem_data(char	*rem_data)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (rem_data[i] && rem_data[i] != '\n')
		i++;
	if (rem_data[i] == 0 || !rem_data)
	{
		free(rem_data);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(rem_data) - i + 1));
	if (!str)
	{
		free(rem_data);
		return (NULL);
	}
	i++;
	j = 0;
	while (rem_data[i])
		str[j++] = rem_data[i++];
	str[j] = '\0';
	free(rem_data);
	return (str);
}

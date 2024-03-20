/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:42:30 by dzurita           #+#    #+#             */
/*   Updated: 2023/11/23 14:44:31 by dzurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*read_file(char	*rem_data, char	*buffer, int fd);
char	*get_new_line(char *rem_data);
char	*get_rem_data(char	*rem_data);
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char const *s2);

#endif

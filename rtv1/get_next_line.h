/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 17:11:09 by ataftai           #+#    #+#             */
/*   Updated: 2017/10/27 19:15:27 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 100
# include <fcntl.h>
# include <stdlib.h>

char	*make_mas(char *str, char *buff);
char	*find_chr(char *f_s, char **line, char **str);
int		str_add(char **str, char *buff, char **line);
int		get_next_line(const int fd, char **line);
#endif

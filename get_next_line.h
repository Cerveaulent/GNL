/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 10:20:55 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/23 23:43:35 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1000

# include "./libft/libft.h"
# include <fcntl.h>

int							get_next_line(const int fd, char **line);

typedef	struct				s_gnl_struct
{
	char					*left;
	int						fd;
	struct s_gnl_struct		*next;
}							t_gnl_struct;

#endif

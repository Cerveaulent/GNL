/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 15:59:42 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 17:29:46 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static	int				check_left(char **line, t_gnl_struct *gnl)
{
	char				*tmp;

	tmp = *line;
	if (!(ft_strchr(gnl->left, '\n')))
	{
		if (!(*line = ft_strjoin(tmp, gnl->left)))
			return (-1);
		ft_strdel(&(gnl->left));
	}
	else
	{
		if (!(*line = ft_strsub(gnl->left, 0, ft_strcspn(gnl->left, "\n"))))
			return (-1);
		ft_strdel(&tmp);
		tmp = gnl->left;
		if (!(gnl->left = ft_strsub(tmp, ft_strcspn(tmp, "\n")
			+ 1, ft_strlen(tmp) - 1)))
			return (-1);
		ft_strdel(&tmp);
		return (1);
	}
	ft_strdel(&tmp);
	return (0);
}

static int				check_line(char *buf, char **line, t_gnl_struct *gnl)
{
	char				*tmp;
	char				*tmp2;

	if (ft_strchr(buf, '\n'))
	{
		tmp = *line;
		if (!(tmp2 = ft_strsub(buf, 0, ft_strcspn(buf, "\n"))))
			return (-1);
		if (!(*line = ft_strjoin(tmp, tmp2)))
		{
			ft_strdel(&tmp2);
			return (-1);
		}
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
		if (!(gnl->left = ft_strsub(buf, ft_strcspn(buf, "\n") + 1,
			BUFF_SIZE - 1)))
			return (-1);
		return (1);
	}
	tmp = *line;
	if (!(*line = ft_strjoin(tmp, buf)))
		return (-1);
	ft_strdel(&tmp);
	return (0);
}

static	t_gnl_struct	*fd_manager(const int fd, t_gnl_struct *gnl)
{
	t_gnl_struct		*head;
	t_gnl_struct		*tmp2;

	head = gnl;
	tmp2 = NULL;
	while (gnl && gnl->fd != fd)
	{
		tmp2 = gnl;
		gnl = gnl->next;
	}
	if (!gnl)
	{
		if (!(gnl = (t_gnl_struct *)malloc(sizeof(t_gnl_struct))))
			return (NULL);
		gnl->fd = fd;
		gnl->left = NULL;
		gnl->next = head;
		return (gnl);
	}
	if (tmp2)
		tmp2->next = gnl->next;
	if (gnl != head)
		gnl->next = head;
	return (gnl);
}

int						get_next_line(const int fd, char **line)
{
	char				buf[BUFF_SIZE + 1];
	int					read_bt;
	static t_gnl_struct	*gnl;
	int					ret;

	ret = 0;
	if (!line || fd < 0 || BUFF_SIZE <= 0 || !(gnl = fd_manager(fd, gnl)) ||
		(read_bt = read(fd, buf, 0)) < 0 ||
		(!(*line = ft_strnew(0))))
		return (-1);
	read_bt = -1;
	if (gnl->left && ((ret = check_left(line, gnl)) == 1))
		return (ret);
	else if (ret == -1)
		return (ret);
	while ((read_bt = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[read_bt] = '\0';
		if (((ret = check_line(buf, line, gnl) == 1)))
			return (1);
		else if (ret == -1)
			return (ret);
	}
	return (0);
}

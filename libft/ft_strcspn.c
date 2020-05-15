/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcspn.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 13:59:09 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/18 20:22:11 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(char *reject, char *str)
{
	size_t nb;

	nb = 0;
	while (reject && (ft_strchr(str, *reject++) == NULL))
		nb++;
	return (nb);
}

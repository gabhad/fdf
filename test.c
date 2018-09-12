/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 09:10:31 by ghaddad           #+#    #+#             */
/*   Updated: 2018/09/12 09:10:32 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"
# include "unistd.h"

int main(int argc, char **argv)
{
	int fd;
//	int ret;
	char *line;

	(void)argc;
//	line = ft_strnew(100);
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	ft_printf("fd = %d\n", fd);
	ft_printf("line = %s\n", line);
	close (fd);
}

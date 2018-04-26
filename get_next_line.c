/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 16:27:05 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/04/10 17:32:19 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ftgetline(char **line,  char *buf, t_list *lst)
{
	int		len;

	len = lst->content_size - strlen(ft_strchr(lst->content, '\n'));
	line[0] = ft_strsub(lst->content, 0, len);
	free(lst->content);
	lst->content = ft_strsub(buf, len + 1, (lst->content_size));
	printf("content = %s\n", lst->content);
	return(line[0]);
}



char	*ftfind(char **line, int fd)
{
	static	t_list	*lst = NULL;
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*mod;

//	ret = read(fd, buf, BUFF_SIZE);
	lst = ft_lstnew(buf, BUFF_SIZE);
//	lst->content = ft_strdup(buf);
	lst->fd = fd;	
	while (read(fd, buf, BUFF_SIZE))
	{
		printf("HELLO\n");
		mod = ft_strdup(buf);
	//	free(lst->content);
		lst->content=ft_strjoin(mod, buf);
		printf("%s \n", lst->content);
	if (ft_strchr(lst->content, '\n') != 0)
		break;
	}

	line[0] = ftgetline(line, buf, lst);
	

	//lst->content = ft_strjoin(lst->content, buf);

	//printf("content = %s\n", lst->content); 
	//	if (ft_strchr(lst->content, '\n') != 0)
		//line[0] = ftgetline(line, buf, lst);


	return(line[0]);
}


//	lst->content = ft_strjoin(lst->content,	buf);



int	get_next_line(const int fd, char **line)
{

	char			*tmp;

	if (fd < 0 || line == 0 || BUFF_SIZE < 1)
		return (-1);
	*line = NULL;

	line[0] = ftfind(line, fd);

	printf("\nline = %s\n", line[0]); 



//	printf("content = %s\n", lst->content); 
//	printf("fd = %d", fd);

	//str = ft_strdup(buf); //

	//line[0] = ft_strsub(str, 0, len);

//	cr = ft_strsub(str, len + 1, (ret));


//	str = ft_strjoin(cr, buf);
	

	return (0);
}




# include <stdio.h>

int main(void)
{
	int		fd;
	char    *line;
	
	fd = open("42", O_RDONLY);
	if (fd == -1)
		return (1);
	while (get_next_line(fd, &line) == 1)
	{
		//printf("REEEs\n%s\n", line);
		free(line);
	}
	if (close(fd) == -1)
		return (1);
	return 0;
}


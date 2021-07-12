#include "get_next_line.h"

static void	ft_unit(char **balance, char *buffer)
{
	char	*tmp;

	tmp = *balance;
	*balance = ft_strjoin(*balance, buffer);
	free (tmp);
}

static void	ft_find_n(char **point, char **balance, char **res)
{
	char	*tmp;

	*point = ft_strchr(*balance);
	if (*point)
	{
		tmp = *balance;
		**point = '\0';
		(*point)++;
		*res = ft_strdup_new(*balance, 2);
		*balance = ft_strdup_new(*point, 1);
		free(tmp);
	}
}

int	ft_read_file(char **point, char **balance, char **res, int fd)
{
	char	*buffer;
	int		read_byte;

	read_byte = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (-1);
	while (read_byte && *point == NULL )
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == 0)
		{
			free(buffer);
			return (0);
		}
		buffer[read_byte] = '\0';
		if (*balance)
			ft_unit(balance, buffer);
		else
			*balance = ft_strdup_new(buffer, 1);
		ft_find_n(point, balance, res);
	}	
	free (buffer);
	return (read_byte);
}

char	*get_next_line(int fd)
{
	int			read_byte;
	static char	*balance;
	char		*point;
	char		*res;

	res = NULL;
	read_byte = 1;
	point = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (balance)
		ft_find_n(&point, &balance, &res);
	if (point == NULL)
		read_byte = ft_read_file(&point, &balance, &res, fd);
	if (read_byte == 0 )
	{
		if (balance && *balance != '\0')
		{
			res = ft_strdup_new(balance, 1);
			free(balance);
			balance = NULL;
		}
	}
	return (res);
}

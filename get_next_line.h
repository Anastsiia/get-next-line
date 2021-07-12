#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

char	*get_next_line(int fd);
size_t	ft_strlen (const char *str);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr (const char *str);
char	*ft_strdup_new (const char *str, int flag);

#endif

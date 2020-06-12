#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
# define BUFF_SIZE 32
# define FD_MAX 10240
void	memdel(void **ap)
{
	if (ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}
char	*ft_strnew(size_t size);
char		*ft_strjoin(char const *s1, char const *s2);
static char         **check_empty_string(char **stack)
{
    if (!(*stack))
        *stack = ft_strnew(0);
    return (stack);
}

static int          generate_new_line(char **stack, char **line)
{
    char            *temporary;

    if (!(*stack)[0])
        return (0);
    if (strchr(*stack, '\n'))
    {
        *(strchr(*stack, '\n')) = '\0';
        *line = strdup(*stack);
        temporary = strdup(strchr(*stack, '\0') + 1);
        free(*stack);
        if (temporary)
        {
            *stack = strdup(temporary);
            free(temporary);
        }
    }
    else
    {
        *line = strdup(*stack);
        memdel((void **)stack);
    }
    return (1);
}

static void         generate_new_string(char **stack, char *buffer)
{
    char            *temporary;

    temporary = ft_strjoin(*stack, buffer);
    free(*stack);
    *stack = strdup(temporary);
    free(temporary);
}

int                 get_next_line(const int fd, char **line)
{
	static char     *stack[FD_MAX];
	char            buffer[BUFF_SIZE + 1];
	int             amount;

	if (fd < 0 || read(fd, buffer, 0) || !line || fd > FD_MAX)
		return (-1);
	check_empty_string(&(stack[fd]));
	while (!(strchr(stack[fd], '\n')))
	{
		amount = read(fd, buffer, BUFF_SIZE);
		buffer[amount] = '\0';
		if (!amount)
            break ;
		generate_new_string(&(stack[fd]), buffer);
	}
	return (generate_new_line(&(stack[fd]), line));
}
char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*join_result;
	char	*join_result_begin;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	if (!(size = strlen(s1) + strlen(s2) + 1))
		return (NULL);
	join_result = (char *)malloc(sizeof(char) * size);
	if (!join_result)
		return (NULL);
	join_result_begin = join_result;
	while (*s1)
		*join_result++ = *s1++;
	while (*s2 != '\0')
		*join_result++ = *s2++;
	*join_result = '\0';
	return (join_result_begin);
}
char	*ft_strnew(size_t size)
{
	char *result;

	if (!(size + 1))
		return (NULL);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	memset(result, '\0', (size + 1));
	return (result);
}

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	println(int fd)
{
	char	*str = get_next_line(fd);
	int index = 0;

	while (index < 41)
	{
		printf("%c", str[index] < 32 ? 'G' : '+');
		index++;
	}
}

int	main()
{
	int fd = open("41_no_nl", O_RDONLY);

	println(fd);
	close(fd);
	return (0);
}

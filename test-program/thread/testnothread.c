#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
# include <sys/time.h>

int	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

int	main(int ac, char **av)
{
	(void)ac;
	int buffer_time;
	int	i = 0;
	unsigned int indx = 0;;

	buffer_time = get_time();
	while (i < atoi(av[1]))
	{
		while (indx < 4294967295)
			indx++;
		i++;
		printf("%i time reached 4294967295\n", i);
		indx = 4294967295;
	}
	printf("Time taken = [%d.%ds]", (get_time() - buffer_time) / 1000 \
		,(get_time() - buffer_time) % 1000);
	return (0);
}

// just a basic programe that count from min-int to max-int
// it's to test the time it take without thread
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
# include <sys/time.h>

int	thread_nb = 0;


// to have time
int	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

// the job that count from 0 to max(9223372036854775807)
void	*thread1t(void *arg)
{
	(void)arg;
	unsigned long long indx = 0;

	while (indx < 9223372036854775807)
		indx++;
	++thread_nb;
	printf("hi, am a thread and i'm done. thread%d\n" \
		, thread_nb);
	pthread_exit(EXIT_SUCCESS);
}

// the main
int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int buffer_time;
	int i = 0;
	int errc;

	if (!av[1])
		exit(-1);
	pthread_t	threads[atoi(av[1])];

	buffer_time = get_time();
	printf("before creating Thread\n");

	while (i < atoi(av[1])) // create threads
	{
		errc = pthread_create(&threads[i], NULL, thread1t, NULL);
		if (errc != 0)
			printf("Error - thread%d\n", errc);
		printf("thread created %lu\n", threads[i]);
		++i;
	}

	i = 0;
	while (i < atoi(av[1])) // join theads
	{
		pthread_join(threads[i], NULL);
		++i;
	}
	printf("after thread created\n");

	printf("Time taken = [%d.%ds]", (get_time() - buffer_time) / 1000 \
		,(get_time() - buffer_time) % 1000);
	return (EXIT_SUCCESS);
}

// it's a program that count from min-int to max-int
// it's to test how long does it take with threads
// it's way faster
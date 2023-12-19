# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include <unistd.h>

int	thread_nb = 0;
int	b_time = 0;

/*-structure for mutex data-*/

typedef struct s_mutex_data
{
	int	data;
	pthread_mutex_t mutex;
}				t_mutex_data;

// to have time in ms
int	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

// the job that count
void	*thread1t(void *arg)
{
	(void)arg;
	t_mutex_data *md = (t_mutex_data*) arg;
	pthread_t tid = pthread_self();

	while ((*md).data < 5000000)
	{
		pthread_mutex_lock(&(*md).mutex);
		if ((*md).data == 5000000) 
		{
			break;
			pthread_mutex_unlock(&(*md).mutex);
		}
		++(*md).data;
		pthread_mutex_unlock(&(*md).mutex);
	}
	pthread_mutex_unlock(&(*md).mutex);
	++thread_nb;
	printf("hi, am a thread [%ld] and i'm done and data = %d. thread%d\n" \
		, tid, (*md).data , thread_nb);
	pthread_exit(EXIT_SUCCESS);
}

// the main !
int	main(int ac, char **av)
{
	t_mutex_data	md;
	md.data = 0;

	(void)ac;
	int i = 0;
	int errc;

	if (!av[1])
		exit(-1);
	pthread_t	threads[atoi(av[1])];
	if (pthread_mutex_init(&md.mutex, NULL) != 0) // init mutex
	{
		printf("\n Error - Mutex initialisation failed \n");
		exit(-2);
	}

	b_time = get_time();
	printf("before creating Thread\n");

	while (i < atoi(av[1])) // create threads
	{
		errc = pthread_create(&threads[i], NULL, thread1t, &md);
		if (errc != 0)
			printf("Error - thread%d\n", errc);
		printf("thread created %lu\n", threads[i]);
		++i;
		usleep(500);
	}

	i = 0;
	while (i < atoi(av[1])) // join theads
	{
		pthread_join(threads[i], NULL);
		++i;
	}
	printf("after thread created\n");

	printf("Time taken = [%d.%ds]", (get_time() - b_time) / 1000 \
		,(get_time() - b_time) % 1000);
	pthread_mutex_destroy(&md.mutex);
	return (EXIT_SUCCESS);
}

// it's a program that count from min-int to max-int
// it's to test how long does it take with threads
// it's way faster
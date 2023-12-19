#include <unistd.h>
#include <stdio.h>
# include <sys/time.h>

int	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

int main(void)
{
    int i = -2147483648;
    int j = -2147483648;
    int k = -2147483648;
    int l = -2147483648;
    int buffer_time;

	buffer_time = get_time();
    while (i < 2147483647)
        i++;
    printf("i at %d\n", i);
    while (j < 2147483647)
        j++;
    printf("j at %d\n", j);
    while (k < 2147483647)
        k++;
    printf("k at %d\n", k);
    while (l < 2147483647)
        l++;
    printf("l at %d\n", l);
	printf("Time taken = %d.%ds", (get_time() - buffer_time) / 1000 \
        ,(get_time() - buffer_time) % 1000);
    return (0);
}
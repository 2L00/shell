#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


int count = 0;


void *ss(void *arg)
{
	int *count = (int *)arg;
	int i = 0;
	while (i < 100)
	{
		(*count)++;
		i++;
	}	
	return NULL;
}


void func()
{

	pthread_t tr;
	pthread_create(&tr, NULL, ss, &count);

}

int main()
{
	func();
	func();
	func();
	printf("%d\n", count);
}

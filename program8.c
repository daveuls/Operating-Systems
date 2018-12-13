//         Course: CS3450-01 Operating Systems
//           Name: Ulikowski, David
//     Assignment: Programming 8.1
//  Date assigned: 11/27/18
//	 Date due: 12/18/18
// Date handed in: 
//         Remark: program that simulates a deadlock

#include <stdio.h> 
#include <pthread.h> 
#include <stdlib.h>
pthread_mutex_t read_mutex;
pthread_mutex_t write_mutex;


void * write(void *temp) 
{
	char *ret;
	FILE *file1;
	char *str;

	pthread_mutex_lock(&write_mutex);
	sleep(5);
	pthread_mutex_lock(&read_mutex);
	printf("\nFile locked, please enter the message \n");
	str = (char *)malloc(10*sizeof(char));
	file1 = fopen("temp","w");
	scanf("%s",str);
	fprintf(file1,"%s",str);

	fclose(file1);

	pthread_mutex_unlock(&read_mutex);
	pthread_mutex_unlock(&write_mutex);
	printf("\nFile now unlocked \n");
	return ret;
}


void * read(void *temp) 
{
	char *ret;
	FILE *file1;
	char *str;

	pthread_mutex_lock(&read_mutex);
	sleep(5);
	pthread_mutex_lock(&write_mutex);
	printf("\n Opening file \n");
	file1 = fopen("temp","r");
	str = (char *)malloc(10*sizeof(char));
	fscanf(file1,"%s",str);
	printf("\n Message from file is %s \n",str);

	fclose(file1);

	pthread_mutex_unlock(&write_mutex);
	pthread_mutex_unlock(&read_mutex);
	return ret;
}




main() 
{
	pthread_t thread_id,thread_id1;
	pthread_attr_t attr;
	int ret;
	void *res;

	ret = pthread_create(&thread_id,NULL,&write,NULL);
	ret  =pthread_create(&thread_id1,NULL,&read,NULL);
	printf("\n Created thread");

	pthread_join(thread_id,&res);
	pthread_join(thread_id1,&res);
}

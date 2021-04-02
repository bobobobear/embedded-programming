#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <pthread.h>
#include <semaphore.h>

sem_t shared_data;
sem_t shared_buffer;

struct thread_arg{
	int sockfd;
	int clilen;
	struct sockaddr_in cli_addr;
};

void error(char *m)
{
	perror(m);
}

int *multiply_5(void *param){

	
	sem_wait(&shared_data);
	
	struct thread_arg *args = param;
	
	int sockfd = args->sockfd;
	int clilen = args->clilen;
	struct sockaddr_in cli_addr = args->cli_addr;
	
	int n;
	char buffer[256];
	
	int newsockfd = accept(sockfd,(struct sockaddr *)&cli_addr, &clilen);	

	if (newsockfd < 0) 
		error("ERROR on accept");
	
	n = read(newsockfd,buffer,255);
	
	if (n < 0) 
		error("ERROR reading from socket");
	
	//delay for seconds
	//int delay = 9999999999;
	//while(delay>0)
		//delay = delay-1;
	//printf("Client number: %d connected\n",n);
	
	int ans = atoi(buffer) * 5;
	printf("The value multiply by 5 is:  %d\n", ans);
	printf("Sending this data back to client side...\n");
	
	fflush(stdout);
	
	//convert integer to string
	char str[256];
	char *message1 = "Message Acknowledged\n";
	char *message2 = "Reply to client: ";
	sprintf(str, "%s%s%d",message1, message2, ans);
	
	int i = 2147483647;
	while(i>0){
		i = i-1;
	}
	int j = 2147483647;
        while(i>0){
                i = i-1;
        }
	int k = 2147483647;
        while(i>0){
                i = i-1;
        }


	

	n = write(newsockfd,str,256);
	
	if (n < 0)
                error("ERROR writing back to socket"); 
                
        //everytime a thread finished, it increase the semaphore that allowed only three thread running
        sem_post(&shared_buffer);
	
	return ans;
}
	

int main(int argc, char *argv[])
{ 
	sem_init(&shared_data, 0, 0);
	sem_init(&shared_buffer, 0, 3);
	
	int sockfd, port, clilen, n;
	//char buffer[256];
	struct sockaddr_in serv_addr, cli_addr;

	if (argc < 2)
		error("ERROR, no port provided\n");

	port = atoi(argv[1]);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd < 0)
		error("ERROR opening socket");
	
	memset((char *) &serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(port); //host to network

	if (bind(sockfd, (struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
		error("ERROR binding to socket");

	listen(sockfd,10);
	clilen = sizeof(cli_addr);
	
	
	int thread[3];
	pthread_t t[3];
	struct thread_arg args;
	
	//pass a struct to a struct
	args.sockfd = sockfd;
	args.cli_addr = cli_addr;
	args.clilen = clilen;
	
	int i = 0;
	while(1){ 
		//create a semaphore that only allowed at most three thread running at the same time
		sem_wait(&shared_buffer);
		
		//printf("Client %d successfully created!\n",i);
	
		thread[i] = pthread_create(&t[i], NULL, &multiply_5, (void *)&args);
	
		i = (i+1)%3;
		sem_post(&shared_data);
	}
	
	sem_destroy(&shared_data);
	sem_destroy(&shared_buffer);
	
	
	return 0;
}

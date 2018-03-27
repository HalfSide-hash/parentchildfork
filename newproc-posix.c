/**
 * This program forks a separate process using the fork()/exec() system calls.
 *
 * Figure 3.09
 *
 * @author Silberschatz, Galvin, and Gagne
 * Operating System Concepts  - Ninth Edition
 * Copyright John Wiley & Sons - 2013
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
pid_t pid;

	int n=0;

	do{
	printf("Enter a positive number greater than 0 to get Collatz'd: ");
	scanf("%d", &n);
	} while (n <= 0);

	/* fork a child process */
	pid = fork();

	if (pid < 0) { /* error occurred */
		fprintf(stderr, "Fork Failed\n");
		return 1;
	}
	else if (pid == 0) { /* child process */
		printf("I am the child %d\n",pid);
		printf("%d, ",n);
		while (n != 1)
		{
			if (n%2 == 0)
				n = n/2;
			else if (n%2 == 1)
				n = (3 * n) + 1;
			printf("%d, ",n);
		}
		printf("\nChild Process All Done\n");
		//execlp("/bin/ls","ls",NULL);
	}
	else { /* parent process */
		/* parent will wait for the child to complete */
		printf("The parent is now here hello %d\n",pid);
		wait();
		
		printf("Parent Confirms Child Complete\n");
	}
    
    return 0;
}

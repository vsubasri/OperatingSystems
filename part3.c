/*
 * Name: Valli Subasri
 * Student Number: 250697148
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(void) {
    int fds[2], status;

    pid_t pid;

    // create pipe descriptors
    pipe(fds);

	if (pipe(fds) < 0){
		perror("Fatal Error"); 
		exit(1);
	}

    //fork() returns 0 for child process, child-pid for parent process. 
    pid = fork();

    //parent process
    if (pid > 0) {

        close(fds[0]);

        //Inside parent, perform <stdout> redirection (dup2())
        if (dup2(fds[1],STDOUT_FILENO)<0) {
			perror("can't dup");
			exit(1);
		} 
        
        close(fds[1]);

        //Inside parent, execute ls -l command (execlp())
        status = execlp("ls","ls","-l", NULL);
	    if (status < 0){
	       perror("parent: exec problem");
	       exit(1);
	    }

	    wait(NULL);
     
    } 
    //child process
    else if (pid == 0) {   

        close(fds[1]);
        // Inside child, perform <stdin> redirection (dup2())
        if (dup2(fds[0],STDIN_FILENO)<0) {
			perror("can't dup");
			exit(1);
		} 

        // close the read-descriptor
        close(fds[0]);

        //inside child, execute grep command (execlp())
        status = execlp("grep","grep", "xxxx", NULL);
	    if (status < 0){
	       perror("child: exec problem");
	       exit(1);
	    }

	    wait(NULL);

    }

    //error forking 
    else {
        perror("fork");
        printf("Main function: Errno number is %d\n", errno);
        exit(pid);
    }

    return 0;
}

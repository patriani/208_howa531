/*
 ============================================================================
 Name        : howa531.c
 Author      : Austin Howard
 Version     :	v1.0
 Copyright   : Don't touch my stuff!!!
 Description : Hello World in C, Ansi-style
 ============================================================================
*	TO DO:
*  	
*	Run the program yet again with ls -al as
* 	the command tail. Is the entire command tail
* 	being passed to the child?
* 	
*	RESULT: Yes, the entire command is being passed to the child
* 	==============================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // includes fork() function
#include <sys/types.h> //  includes pid_t type 
#include <sys/wait.h> // define constants to use in waitpid()

// argc represents the number of commands 
// argv is an array of commands entered
int main(int argc, char* argv[]) {

	pid_t pid;

	if((pid = fork()) < 0){ // pid < 0 when the fork goes wrong
		perror("fork"); // print the system fail
	}
	else if(pid == 0){
		//Child process
		if(argc > 1){ // when commands are entered
			execvp(argv[1], &argv[1]);
			perror("execvp");
			exit(0);
		}
		else{
			perror("Not enough parameters\n");
			exit(0);
		}
	}
	else{
		//Parent process
		printf("Thanks for using the program!\n");
		return EXIT_SUCCESS;
	}
}

/*
 ============================================================================
 Name        : howa531.c
 Author      : Austin Howard
 Version     :	v1.0
 Copyright   : Don't touch my stuff!!!
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {

	pid_t pid;

	if((pid = fork()) < 0){
		perror("fork");
	}
	else if(pid == 0){
		//Child process
		if(argc > 1){
			execvp(argv[1], &argv[1]);
			perror("execvp");
			exit(0);
		}
		/*	-----------------------
		 *         QUESTIONS
		 *  -----------------------
		 *
		 * 	1) Run the executable with no command parameters and record the results
		 * 			RESULT:root@darkstar:~/workspace/howa541/Debug# ./howa541
						Thanks for using the program!
						Not enough parameters
						: Success
		 *	==============================================
		 *
		 * 	2) Run the program again with ls in the
		 * 	command tail (xxxx543 ls). Record the results.
		 * 			RESULT:root@darkstar:~/workspace/howa541/Debug# ./howa541 ls
						Thanks for using the program!
						root@darkstar:~/workspace/howa541/Debug# howa541  makefile  objects.mk  sources.mk  src
		 * 	==============================================
		 *
		 * 	3) Run the program yet again with ls -al as
		 * 	the command tail. Is the entire command tail
		 * 	being passed to the child?
		 * 			RESULT: Yes, the entire command is being passed to the child
		 * 	==============================================
		 *
		 * 	4) Explain why the call to execvp uses argv[1]
		 * 	instead of argv[0]. What ould happen if argv[0]
		 * 	were used?
		 * 			RESULT: Because it points to the file location,
		 * 			so we're wanting it to not look at a location but
		 * 			be pointed towards the command that we want to execute
		 * 			RESULT: If it was pointing towards the 0 pointer, then it
		 * 			launch the program again and again with the same
		 * 			parameters each time and lock up the system.
		 * 	==============================================
		 */
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

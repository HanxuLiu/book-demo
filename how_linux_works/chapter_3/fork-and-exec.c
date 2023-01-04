/*================================================================
*  Author: LiuHanxu
*  Date: 2023-01-04
*  Description: 
================================================================*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> // provide a declaration of exit()
#include <err.h>

int main() {
	pid_t pid = fork();
	if (pid == -1)
		err(EXIT_FAILURE, "fork() failed");
	if (pid == 0) {
		// child process came here because fork() returns 0 for child process
		char *args[] = { "/bin/echo", "hello world!" , NULL};
		printf("I'm child! my pid is %d.\n", getpid());
		fflush(stdout);
		execve("/bin/echo", args, NULL);
		err(EXIT_FAILURE, "exec() failed");
	} else {
		// parent process came here because fork() returns the pid of newly created child process (> 1)
		printf("I'm parent! my pid is %d and the pid of my child is %d.\n", getpid(), pid);
		exit(EXIT_SUCCESS);
	}
}

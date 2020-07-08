#include "apue.h"
#include <sys/wait.h>

int
main(void)
{
	pid_t	pid;
	int		status;

	char buf[1][5];
	char *buf2[6];
	buf[0][0] = '.';
	buf[0][1] = '.';
	buf[0][2] = 0;
	buf2[0] = "ls";
	buf2[1] = "-latr";
	buf2[2] = "/etc/passwd";
	buf2[3] = (char *)&buf[0][0];
	buf2[4] = (char *)0;
	buf2[5] = (char *)0;
	


		if ((pid = fork()) < 0) {
			err_sys("fork error");
		} else if (pid == 0) {		/* child */
			execvp(buf2[0], buf2);
			err_ret("couldn't execute: %s", buf2[0]);
			exit(127);
		}

		/* parent */
		if ((pid = waitpid(pid, &status, 0)) < 0)
			err_sys("waitpid error");
		printf("DONE ");
	exit(0);
}

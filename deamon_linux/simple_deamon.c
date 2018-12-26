#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>

int main(void) {

        /* Our process ID and Session ID */
        pid_t pid, sid;
        
        /* Fork off the parent process */
        pid = fork();
        if (pid < 0) {
                exit(EXIT_FAILURE);
        }
        /* If we got a good PID, then
           we can exit the parent process. */
        if (pid > 0) {
                exit(EXIT_SUCCESS);
        }

        /* Change the file mode mask */
        umask(0);
                
        /* Open any logs here */        
                
        /* Create a new SID for the child process */
        sid = setsid();
        if (sid < 0) {
                /* Log the failure */
                exit(EXIT_FAILURE);
        }
        

        
        /* Change the current working directory */
        if ((chdir("/")) < 0) {
                /* Log the failure */
                exit(EXIT_FAILURE);
        }
        
        /* Close out the standard file descriptors */
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);
        
        /* Daemon-specific initialization goes here */
        char *w_mode = "w";
        char *a_mode = "a";
        char *r_mode = "r";
        char logFilename[] = "/home/a/simple_deamon.log";

        /* The Big Loop */
        while (1) {
           /* Do some task here ... */
           time_t t = time(NULL);
           FILE *ifp, *log;
           char outputFilename[] = "/home/a/ahihi.txt";
           log = fopen(logFilename, a_mode);
           ifp = fopen(outputFilename, r_mode);
           struct tm tm = *localtime(&t);
           int num;

           if (ifp == NULL) {
               fprintf(log, "%d-%d-%d %d:%d:%d:    file ko ton tai !!\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
           } else {
               fprintf(log, "=============== file ton tai, bat du doc file ===============\n");
               while(fscanf(ifp, "%d", &num) != EOF) {
                   fprintf(log, "%d-%d-%d %d:%d:%d:    %d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, num);
                   sleep(1);
               }
               fclose(ifp);
           }
           fclose(log);
           sleep(10); /* wait 30 seconds */
        }
   exit(EXIT_SUCCESS);
}

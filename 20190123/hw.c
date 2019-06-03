
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
/*输入进程名字，获得该进程名字对应的进程号*/
int find_pid_by_name( char* ProcName, int* foundpid)
{
        DIR             *dir;
        struct dirent   *d;
        int             pid, i;
        char            *s;
        int pnlen;

        i = 0;
        foundpid[0] = 0;
        pnlen = strlen(ProcName);

        /* Open the /proc directory. */
        dir = opendir("/proc");
        if (!dir)
        {
                printf("cannot open /proc");
                return -1;
        }

        /* Walk through the directory. */
        while ((d = readdir(dir)) != NULL) {

                char exe [PATH_MAX+1];
                char path[PATH_MAX+1];
                int len;
                int namelen;

                /* See if this is a process */
                if ((pid = atoi(d->d_name)) == 0)       continue;

                snprintf(exe, sizeof(exe), "/proc/%s/exe", d->d_name);
                if ((len = readlink(exe, path, PATH_MAX)) < 0)
                        continue;
                path[len] = '\0';

                /* Find ProcName */
                s = strrchr(path, '/');
                if(s == NULL) continue;
                s++;

                /* we don't need small name len */
                namelen = strlen(s);
                if(namelen < pnlen)     continue;

                if(!strncmp(ProcName, s, pnlen)) {
                        /* to avoid subname like search proc tao but proc taolinke matched */
                        if(s[pnlen] == ' ' || s[pnlen] == '\0') {
                                foundpid[i] = pid;
                                i++;
                        }
                }
        }

        foundpid[i] = 0;
        closedir(dir);

        return  0;

}


int main(int argc, char *argv[])
{
        int i, rv, pid_t[128];
        if ( argc != 2 )
        {
                fprintf(stdout,"Usage %s procname\n",argv[0]);
                return 0;
        }

        rv = find_pid_by_name( argv[1], pid_t);
        if(!rv) {
                for(i=0; pid_t[i] != 0; i++)
                        printf("%d\n", pid_t[i]);
        }

        return 0;
  }

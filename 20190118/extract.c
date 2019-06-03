/* IP = 192.168.1.1 
  3 PORT = 8080 
  4 要求通过 系统IO 分解出192.168.1.1存入 第一个字符数组中，分解出8080 存入第二>    个字符数组中。最后打印输出。 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc,char** argv){
	int fdr = open(argv[1],O_RDONLY);
	off_t ret = lseek(fdr,0,SEEK_END);
	lseek(fdr,0,SEEK_SET);
        if(fdr == -1){
 	       perror("read");
        }
 
        char caBuf[ret+1];
        read(fdr,caBuf,ret);
        caBuf[ret] = '\0';

	int i = 0;
	char str1[20] = {'\0'};
	char str2[20] = {'\0'};
	int j = 0;
	while(1){
		char temp = '\0';
		temp = caBuf[i];
		if(temp == '\n'){
			break;
		}else if((temp >= '0' && temp <= '9') || temp == '.'){
			str1[j++] = temp;
		}
		i++;
	}

	j = 0;
	while(1){
		i++;
		char temp = '\0';
		temp = caBuf[i];
		if(temp == '\n'){
			break;
		}else if(temp >= '0' && temp <= '9'){
			str2[j++] = temp;
		}
	}
	printf("%s\n%s\n",str1,str2);
}






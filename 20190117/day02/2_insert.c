#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDWR);
	if (-1 == fd)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}	

	printf("请输入插入数据的位置:\n");
	int pos = 0;
	scanf("%d", &pos);

	//获得文件大小
	off_t size = lseek(fd, 0, SEEK_END);
	//重新将读写位置设置在文件首部
	lseek(fd, 0, SEEK_SET);

	//char newFileName[256] = "saasasssacascasca";
	char newFileName[256];
	strcpy(newFileName, argv[1]);
	strcat(newFileName, "~");
	int newfd = open(newFileName, O_RDWR|O_CREAT, 0664);
	if (-1 == newfd)
	{
		perror("open new file");
		exit(EXIT_FAILURE);
	}

	char caBuf[1024] = {'\0'};
	ssize_t ret = -1;
	//将指定位置之前的数据拷贝到新文件中
	while (pos)
	{
		if (pos < 1024)
		{
			ret = read(fd, caBuf, pos);
		}
		else
		{
			ret = read(fd, caBuf, 1024);
		}
		if (-1 == ret)
		{
			if (EINTR == errno)
			{
				continue;
			}
			break;
		}
		pos = pos - ret;
		write(newfd, caBuf, ret);
	}	

	printf("请输入要插入的新数据:\n");
	scanf("%s", caBuf);
	write(newfd, caBuf, strlen(caBuf));

	//将指定位置之后的数据拷贝到新文件中
	while (1)
	{
		ret = read(fd, caBuf, 1024);
		if (-1 == ret)
		{
			if (EINTR == errno)
			{
				continue;
			}
			break;
		}
		else if (0 == ret)
		{
			break;
		}

		write(newfd, caBuf, ret);
	}

	close(fd);
	close(newfd);	
	
	//删除旧文件
	remove(argv[1]);	

	rename(newFileName, argv[1]);

	return 0;
}







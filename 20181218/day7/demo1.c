#include<stdio.h>

int main(int argc,char** argv){
	int arr_1[5]={1,2,3,4,5};
	int arr_2[5]={1,2,3};
	int arr_3[5]={0};
	printf("%lu %lu %lu\n",sizeof(arr_1),sizeof(arr_2),sizeof(arr_3));
	//申明的数组最大容量为5个元素，每个元素的大小是int型4字节，那么他的最大容量就是20个字节
	int arr_4[5]={1,2,3,4,5};
	printf("%lu\n",sizeof(arr_4));
	//根据实际定义的元素数量，来确定了数组的最大容量

	int a=6;
	int arr_5[a];
	printf("%lu\n",sizeof(arr_5));
	
	int* arr1[2]={arr_1,arr_2};
	printf("%lu\n",sizeof(arr1));
	//#数组的名字，就是一个地址
	//arr1内存放的是“两个地址”
	//那么问题来了，一个地址在内存空间中占多少大小：在32位系统中，一个地址占据4个字节大小，64位系统中，一个地址占据8个字节大小
	int* arr2[2]={arr_3,arr_4};

	int** arr[2]={arr1,arr2};
	printf("%lu\n",sizeof(arr));
	int i=0,j=0;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			for(int k=0;k<5;k++){
				printf("%d\n",*(*(*(arr+i)+j)+k));
			}
		}
	}

	int arr_6[5]={arr_1[4]};
	//这里是用arr_1这个数组中的第4个元素去初始化arr_6中的第0个元素，其他元素默认为0;
	return 0;
}

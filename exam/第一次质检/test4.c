#include<stdio.h>

int insert(int* epID,int* epSLR){
	static int pos=0;
	int id=0,slr=0;
	printf("请输入员工工号:");
	scanf("%d",&epID[pos]);
	while(getchar()!='\n');
	printf("请输入员工工资:");
	scanf("%d",&epSLR[pos]);
	while(getchar()!='\n');
	pos++;
	return pos;
}

void epSort(int* epID,int* epSLR,int pos){
	int i=0,j=0;
	for(i=0;i<pos;i++){
		for(j=0;j<pos-1;j++){
			if(epSLR[j]<epSLR[j+1]){
				epSLR[j]=epSLR[j]^epSLR[j+1];
				epSLR[j+1]=epSLR[j]^epSLR[j+1];
				epSLR[j]=epSLR[j]^epSLR[j+1];

				epID[j]=epID[j]^epID[j+1];
				epID[j+1]=epID[j]^epID[j+1];
				epID[j]=epID[j]^epID[j+1];
			}
		}
	}
}

void printEp(int* epID,int* epSLR,int pos){
	int i=0;
	for(i=0;i<pos;i++){
		printf("工号:%d\n工资:%d\n",epID[i],epSLR[i]);
	}
}

void upDateEp(int* epID,int* epSLR,int pos){
	int id=0;
	int flag=0;
	int slr=0;
	int i=0;
	printf("请输入员工的ID:");
	scanf("%d",&id);
	while(getchar()!='\n');
	for(i=0;i<pos;i++){
		if(id==epID[i]){
			flag=1;
			break;
		}
	}
	if(flag==0){
		printf("员工不存在\n");
	}else{
		printf("请输入员工新的工资:");
		scanf("%d",&slr);
		while(getchar()!='\n');
		epSLR[i]=slr;
	}
}

int main(void){
	int ch=0;
	int epID[512]={0};
	int epSLR[512]={0};
	int pos=0;
	while(1){
		printf("1:添加员工\n");
		printf("2:排序员工\n");
		printf("3:修改员工\n");
		printf("4:打印员工信息\n");
		printf("请输入操作:");
		scanf("%d",&ch);
		while(getchar()!='\n');
		switch(ch){
			case 1:
				pos=insert(epID,epSLR);
				break;
			case 2:
				epSort(epID,epSLR,pos);
				break;
			case 3:
				upDateEp(epID,epSLR,pos);
				break;
			case 4:
				printEp(epID,epSLR,pos);
				break;
			default:
				return 0;
		}
	}
	return 0;
}

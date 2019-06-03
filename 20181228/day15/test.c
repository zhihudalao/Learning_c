#include<stdio.h>

int main(int argc,char** argv){
	if(argc!=3){
		return 0;
	}
	FILE* Rfp=fopen(argv[1],"r");
	FILE* Wfp=fopen(argv[2],"w");
	char buf[5120]={0};
	while(1){
		if(fgets(buf,sizeof(buf),Rfp)==NULL){
			break;
		}
		fputs(buf,Wfp);
	}
	fclose(Wfp);
	fclose(Rfp);
	return 0;
}

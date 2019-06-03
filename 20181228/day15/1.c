#include<stdio.h>
#include<string.h>
int main(int argc,char** argv){
	if(argc!=3){
		return 0;
	}
	FILE* Rfp=fopen(argv[1],"r");
	char buf[5120]={0};
	fread(buf,sizeof(buf),1,Rfp);
	fclose(Rfp);
	
	FILE* Wfp=fopen(argv[2],"w");
	fwrite(buf,strlen(buf),1,Wfp);
	fclose(Wfp);
	return 0;
}








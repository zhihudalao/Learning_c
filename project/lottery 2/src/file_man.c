#include<stdio.h>
#include<stdlib.h>
#include"user.h"
#include"issue_lottery.h"
#include"buy_ticket.h"

void decryption(FILE *fp);
void encryption(FILE *fp);
/***************************用户信息加载*****************************/
void user_load(ulink*user_head)
{
	if(user_head == NULL)
	{
		printf("头节点为空\n");
		return;
	}
	FILE *fp = fopen("user.db","rb+");
	if(fp == NULL)
	{
		system("touch user.db");
		return;
	}
	decryption(fp);//解密文件
	rewind(fp);//文件位置指针恢复
	while(1)
	{
		user data;
		int res = fread(&data,sizeof(user),1,fp);//二进制读取
		if(res<1)
		{
			break;
		}
		insert_after_user(user_head,data);//复制到链表
	}
	rewind(fp);//文件指针恢复
	encryption(fp);//解密完的文件重新加密
	fclose(fp);
}

/****************************用户信息保存************************/
void user_save(ulink*user_head)
{
	if(user_head == NULL)
	{
		printf("头节点为空\n");
		return;
	}
	FILE*fp = fopen("user.db","wb+");
	if (fp == NULL)
   	 {
        	fprintf(stderr, "can't find file user.db!\n");
       		return;
   	 }
	user_head = user_head->next;
	while(user_head!=NULL)
	{
		fwrite(&user_head->data,sizeof(user),1,fp);//二进制保存到文件
		user_head = user_head->next;
	}
	rewind(fp);//文件位置指针恢复
	encryption(fp);//文件加密
	fclose(fp);
}
/*******************************发行彩票信息加载***********************/
void lty_load(lty_lk*lty_head)
{
	if(lty_head == NULL)
	{
		printf("头节点为空\n");
		return;
	}
	FILE *fp = fopen("lottery.db","rb+");
	if(fp == NULL)
	{
		system("touch lottery.db");
		return;
	}
	decryption(fp);//解密文件
	rewind(fp);//文件位置指针恢复
	while(1)
	{
		lty lty_data;
		int res = fread(&lty_data,sizeof(lty),1,fp);//二进制读取保存到链表
		if(res<1)
		{
			break;
		}
		insert_after_lty(lty_head,lty_data);
	}
	rewind(fp);//文件指针恢复
	encryption(fp);//解密完的文件重新加密
	fclose(fp);


}
/*********************************发行彩票信息保存************************/
void lty_save(lty_lk*lty_head)
{
	if(lty_head == NULL)
	{
		printf("头节点为空\n");
		return;
	}
	FILE*fp = fopen("lottery.db","wb+");
	if (fp == NULL)
   	 {
        	fprintf(stderr, "can't find file lottery.db!\n");
       		return;
   	 }
	lty_head = lty_head->lty_next;
	while(lty_head!=NULL)
	{
		fwrite(&lty_head->lty_data,sizeof(lty),1,fp);
		lty_head = lty_head->lty_next;
	}
	rewind(fp);//文件位置指针恢复
	encryption(fp);//文件加密
	fclose(fp);
}
/*******************************购买彩票信息加载***************************/
void blty_load(blty_lk*blty_head)
{
	if(blty_head == NULL)
	{
		printf("头节点为空\n");
		return;
	}
	FILE *fp = fopen("buy_ticket.db","rb+");
	if(fp == NULL)
	{
		system("touch buy_ticket.db");
		return;
	}
	decryption(fp);//解密文件
	rewind(fp);//文件位置指针恢复
	while(1)
	{
		buy_lty blty_data;
		int res = fread(&blty_data,sizeof(buy_lty),1,fp);
		if(res<1)
		{
			break;
		}
		insert_after_blty(blty_head,blty_data);
	}
	rewind(fp);//文件指针恢复
	encryption(fp);//解密完的文件重新加密
	fclose(fp);
}



/******************************购买彩票信息保存***************************/
void blty_save(blty_lk*blty_head)
{
	if(blty_head == NULL)
	{
		printf("头节点为空\n");
		return;
	}
	FILE*fp = fopen("buy_ticket.db","wb+");
	if (fp == NULL)
   	 {
        	fprintf(stderr, "can't find file buy_ticket.db!\n");
       		return;
   	 }
	blty_head = blty_head->blty_next;
	while(blty_head!=NULL)
	{
		fwrite(&blty_head->blty_data,sizeof(buy_lty),1,fp);
		blty_head = blty_head->blty_next;
	}
	rewind(fp);//文件位置指针恢复
	encryption(fp);//文件加密
	fclose(fp);
}
/***************************文件加密************************/
void encryption(FILE *fp)
{
	int ch;
	while((ch = fgetc(fp)) != EOF)//读到文件尾
	{
		ch = ~ch;//取反加密
		fseek(fp,-1,1);//文件位置指针前移一个
		fputc(ch,fp);//将ch取反后重新放回

	}
}
/*************************文件解密*************************/
void decryption(FILE *fp)
{
	int ch;
	while((ch = fgetc(fp)) != EOF)
	{

			ch = ~ch;//取反解密
			fseek(fp,-1,1);//文件位置指针前移一个
			fputc(ch,fp);//取反后保存

	}

}

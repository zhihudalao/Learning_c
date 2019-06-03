#include <stdio.h>
#include <string.h>
int main(){
   char c[] = "This is runoob";
   char buffer[20];
   FILE *fp = fopen("file.txt", "w+");
   fwrite(c, strlen(c) + 1, 1, fp);
   fread(buffer, strlen(c)+1, 1, fp);
   printf("%s\n", buffer);
   fclose(fp);
   return 0;
}

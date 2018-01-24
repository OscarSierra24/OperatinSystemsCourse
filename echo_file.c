#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char * argv[]){
	//en 1 se encuentra el path y en 2 se encuentra el texto
	int file=open(argv[1],O_WRONLY | O_APPEND);
	if(file<0){
		return -1;
	}
	//---------------contador---------------------//
	int i,count;
	for(i=0, count=0; argv[2][i];i++){
		count++;	
	}
	printf("Count fue: %d\n\n",count);
	//--------------------------------------------//
	
	printf("argv2 es: %s",argv[2]);
	if(write(file,argv[2],count)!=count){
		write(2,"error\n",5);
		return -1;		
	}
} 

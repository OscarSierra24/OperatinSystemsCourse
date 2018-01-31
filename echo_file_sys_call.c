#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <errno.h>
#include <sys/stat.h>
int main(int argc, char * argv[] ){
	int file;	
	if((file=syscall(SYS_open, argv[1], O_WRONLY | O_APPEND))<0){
		printf("an error ocurred while opening the file");
		return -1;
	}
	int i, count;
	for(i=0, count=0;argv[2][i];i++){
		count++;
	}

	if(syscall(SYS_write, file,argv[2],count)!=count){
		printf("an error ocurred while writing in the file\n");	
		return -1;
	}
	else{
		printf("the program has been modified successfully");
	}
	close(file);
}

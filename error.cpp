#include <iostream>
#include <fcntl.h>	// for open(), O_RDONLY -- file control options
#include <errno.h>

using namespace std;	// for error code stored in "errno"


int main(int argc,char**argv) 
{ 
  	// Create a new file 
	int fd = open("myoutput.txt", O_CREAT|O_WRONLY|O_TRUNC, 0664); 
	if (fd < 0) 
	{ 
		perror("open"); 
		exit(1); 
  	} 
  // Redirect stdout to file 
	dup2(fd,1); 
  // Now printf that prints 
  // to stdout, will write to 
  // myoutput.txt 
	cout << ("Sample Text\n"); 
} 

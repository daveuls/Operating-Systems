//         Course: CS3450-01 Operating Systems
//           Name: Ulikowski, David
//     Assignment: Programming 2
//  Date assigned: 9/18/18
//	  Date due:10/2/18
// Date handed in: 10/2/18
//         Remark: Simple utility program: copies the contents of a source file named source.txt to a target file
// Objectives: to learn UNIX system calls open(), create(), read(), write(), and exit()
// **********************************************
// * To compile: g++ CopySource.cpp                   *
// *     To run: copy <sourceFile> <targetFile> *
// **********************************************

#include <iostream>
#include <fcntl.h>		// what for?
				// defines the following requests and arguments
				// for use by the functions fcntl() and open()

using namespace std;

void copy(int, int);		// What are passed?
				// File descriptors are passed to copy() function

char buffer[2048];		// What is the buffer used for? What does "2048" mean?
				// buffer is used to declar a char array for user input
				// 2048 is the size of the array of characters

int main(int argc, char *argv[])
{
   int fd_source, fd_target; 	// file descriptors; What are they used for?
				// represents the opened source and target files as integers 

   if (argc != 3) {		  // make sure command is correct with
				  // three arguments
      cout << "Need two arguments!" << endl;
      exit(1);
   }
   fd_source = open(argv[1], O_RDONLY);		// What is argv[1]? What is "O_RDONLY"   
						// "O_RDONLY" is to open file for read only purpose
   if (fd_source == -1) {			// make sure "open" call is successful
      cout << "Cannot open " << argv[1] << " file!" << endl;
      exit(1);
   }
   fd_target = creat(argv[2], 0666);		// What does 0666 mean?
   if (fd_target == -1) {			// make sure "create" call is successful
      cout << "Cannot create " << argv[2] << " file!" << endl; // What is argv[2]?
      exit(1);
   }
   copy(fd_source, fd_target);   
 
   exit(0);   
}

void copy(int source, int target)
{
   int count;

   while ((count = read(source, buffer, 2048)) > 0)	// reads source file and copies to target file
      write(target, buffer, 2048);		
}


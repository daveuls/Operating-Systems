//         Course: CS3450-01 Operating Systems
//           Name: Ulikowski, David
//     Assignment: Programming 1
//  Date assigned: 9/5/18
//	  Date due:9/13/18
// Date handed in: 9/13/18
//         Remark: UNIX utility program that accepts parameters in main function


#include <iostream>
#include <stdlib.h>

int main(int flagArg, char *flag[])
{
	if(flagArg == 1)
		std::cout << "myUtility executed\n";
	else if(flagArg == 2)
		std::cout << "myUtility executed with option " << flag[1][1] << "\n";
	else
	{
		std::cout << "myUtility executed with option ";
		for(int i = 1; i < flagArg; i++)
		{
			std::cout << flag[i][i];
			std::cout << " ";
		}
		std::cout <<"\n";
	}

	return 0;
}


 


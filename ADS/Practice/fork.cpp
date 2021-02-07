#include <iostream> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <sched.h>
using namespace std; 
int main() { 
	pid_t pid; 
	cout << "Before fork!!!!!" << endl;
	pid = fork(); 
	if(pid==0) { 
		cout <<"this is child process:" << getpid() <<"  " << getppid() <<  endl; 
		execv("/bin/date", "date", NULL);
		cout << endl << "-----------------------------" << endl;		
		exit(0);
	exit(0); 

	} else if(pid>0) { 
		cout << "this is parent process:" << getpid()<< "  "  << getppid() << endl; 
		execl("/bin/date", "date", NULL);
		exit(0);
	}
	else { 
		cout << "process is not created" << endl; 
	} 
exit(0);
return 0;
} 

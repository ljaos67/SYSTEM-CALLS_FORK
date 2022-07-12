/****************************************************************
   PROGRAM:   Assignment 1
   AUTHOR:    Leonart Jaos
   LOGON ID:  Z1911688
   DUE DATE:  02/05/2021

   FUNCTION:  Linux program in C++ which uses fork system call to 
			  start child processes.

   INPUT:     No input

   OUTPUT:    The program will output their PID and their parents'
			  and/or children's PID. Then a system command will
			  execute to show processes involved. Processes will
			  print a message after sleeping for 3 seconds.

   NOTES:     The interlacing of messages printed by different 
			  processes will depend on the timing of your program and
			  does not have to match the sample output.
****************************************************************/
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main()
{
	//first split, parent and child
	pid_t pid = fork();
	// second split, intermediate and grand child
	pid_t pid2 = fork();
	// error
	if(pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(pid > 0 && pid2 > 0)
	{
		// parent process
		cout << "PARENT: My PID is " << getpid() << ", my parent's PID is " << getppid() 
		<< ". My children are " << pid << ", " << pid2 << endl;
		sleep(1);
		// run system command
		cout << "PARENT: Issuing command: /bin/ps -f --ppid " << getppid() << "," 
		<< getpid() << "," << pid << "," <<  pid2 << endl;
		string s = "/bin/ps -f --ppid " + to_string(getppid()) + "," 
		+ to_string(getpid()) + "," + to_string(pid) + "," +  to_string(pid2);
		const char *str = s.c_str();
		system(str);
		// wait
		sleep(3);
		cout << "PARENT: Children processes are finished" << endl;
		
	}
	else if(pid == 0 && pid2 > 0)
	{
		//Intermediate parent
		cout << "INTERMEDIATE PARENT: My PID is " << getpid() << ", my parent's PID is " << getppid() << endl;;
		sleep(3);
		cout <<  "INTERMEDIATE PARENT: " << getpid() << " is awake" << endl;
		// exit process
		exit(EXIT_SUCCESS);
		
	}
	else if(pid > 0 && pid2 == 0)
	{
		// Child
		cout << "CHILD: My PID is " << getpid() << ", my parent's PID is " << getppid() << endl;
		sleep(3);
		cout << "CHILD: " << getpid() <<  " is awake" << endl;
		// exit process		
		exit(EXIT_SUCCESS);
	}
	else
	{
		// Grand child
		cout << "GRAND CHILD: My PID is " << getpid() << ", my parent's PID is " << getppid() << endl;
		sleep(3);
		cout << "GRAND CHILD: " << getpid()<< " is awake" << endl;
		// exit process		
		exit(EXIT_SUCCESS);
	}
    return 0;
}

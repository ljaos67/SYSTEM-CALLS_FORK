# SYSTEM-CALLS_FORK
a Linux program in C or C++ which uses fork system call to start child process(es)
You will call fork() twice to create 3 additional processes. Among them, one process is the child of the
initial process, but it is also the parent of another process. We call this process “Intermediate Parent”.
Each child, grand child or intermediate parent process will print out information like below:
CHILD: My PID is xxxx, my parent's PID is yyyy.
GRAND CHILD: My PID is xxxx, my parent's PID is yyyy.
INTERMEDIATE PARENT: My PID is xxxx, my parent's PID is yyyy. My child is
wwww.
After printing this information, the child/grand child or intermediate parent process should sleep for 3
seconds, then print the following message and exit:
CHILD: zzzz is awake.
GRAND CHILD: zzzz is awake.
INTERMEDIATE PARENT: xxxx is awake.
In the (initial) parent process, print the message:
PARENT: My PID is xxxx, my parent's PID is yyyy. My Children are wwww,
zzzz.
Then invoke the command “ps –f –-ppid …” from your program to show all the processes
involved. You can use the system() function to do this. The option “—ppid” must be followed
by the PARENT process ids of all the processes you want to list. For example, “/bin/ps -f --
ppid 26560,26803,26804,26805”. Manual page for ps command has more related details:
“ --ppid pidlist
Select by parent process ID. This selects the processes with a parent process ID in pidlist. That is, it selects processes
that are children of those listed in pidlist. ”
You should not use a general ps command here without specifying the parent ids of the
processes of interest.
If you use system(), which starts another process, you should see 5 processes in the output list
(see sample output later).
The parent process should wait for all the child processes to complete, then print the following message
and exit:
PARENT: Children processes are finished.
Note that each message is labeled according to the process that printed it, parent or child or grand child or
intermediate parent. When multiple messages are printed from the same process, they should appear in the
2
order in which they are printed. Each message should be single-spaced with a blank space between
messages.
An example output:
PARENT: My PID is 26803, my parent's PID is 26560, my children are 26804, 26805.
INTERMEDIATE PARENT: My PID is 26804, my parent's PID is 26803, my child is 26806.
CHILD: My PID is 26805, my parent's PID is 26803.
GRAND CHILD: My PID is 26806, my parent's PID is 26804.
PARENT: Issuing command: /bin/ps -f --ppid 26560,26803,26804,26805
UID PID PPID C STIME TTY TIME CMD
jzhou 26803 26560 0 09:42 pts/2 00:00:00 ./a.out
jzhou 26804 26803 0 09:42 pts/2 00:00:00 ./a.out
jzhou 26805 26803 0 09:42 pts/2 00:00:00 ./a.out
jzhou 26806 26804 0 09:42 pts/2 00:00:00 ./a.out
jzhou 26807 26803 0 09:42 pts/2 00:00:00 sh -c /bin/ps -f --ppid 26560,26803,26804,26805
INTERMEDIATE PARENT: 26804 is awake.
CHILD: 26805 is awake.
GRAND CHILD: 26806 is awake.
PARENT: Children processes are finished.
The interlacing of messages printed by different processes will depend on the timing of your program and
does not have to match the sample output.
Requirement:
Use man command to learn usages of the following system calls or functions. Some are useful for this
project.
fork() getpid( ) getppid( ) wait( ) waitpid( ) system( ) setbuf( )
You are required to check the return value of fork() system call.
Note on output buffer:
Output produced by system, which starts a separate subtask, could come out while previously printed
output is still in a buffer. For this assignment, it is ok if your program produces interleaved outputs from
different processes (for every single process, the messages should appear in order, as explained before).
If you are interested, you can study setbuf()/setvbuf() to use unbuffered output. For example, use
setbuf(stdout, NULL) at the beginning of your code can help get unbuffered output. The behavior of
setbuf can be compiler/system specific so the use of it is not required for the assignment.

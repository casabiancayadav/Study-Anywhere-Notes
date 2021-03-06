#  SYSTEM Calls

These System calls are very important to communicate a developer to interface low level API's.



##    Types of System Calls 

​	

1-> Process Control
2-> File Management
3-> Device Management
4-> Information Maintenance
5-> Communication

### Process Control

1. The Linux System calls under this are fork() , exit() , exec().

```markdown
1# pid_t fork(void) :
----------------------
   		> When the child process is successfully created, the PID of the child process 
   		  is returned in the parent process and 0 will be returned to the child process itself.
   		> The child process and parent process gets executed simultaneously.
   		> If there is any error then -1 is returned to the parent process and the child process is not             created.
   		> Please note that Unix will make an exact copy of the parent's address space and give it to the           child.
             Therefore, the parent and child processes have separate address spaces.
   		> Both processes start their execution right after the system call fork().
             Since both processes have identical but separate address spaces, those variables 
   		  initialized before the fork() call have the same values in both address spaces. 
   		  Since every process has its own address space, any modifications will be independent of the               others
   		> both parent and child share the memory address space of parent.
   		  In linux, these address space are divided into multiple pages. 
   		  Only when the child writes to one of the parent memory pages, a duplicate of 
   		  that page is created for the child. This is also known as copy on 
   		  write(Copy parent pages only when the child writes to it).  
   		
   		> But a parent and child differs in some of the PCB(process control block) attributes.
   		> Pending Signals - The child doesn’t inherit Parent’s pending signals.
   		  It will be empty for the child process when created.
   		> Memory Locks - The child doesn’t inherit its parent’s memory locks.
   		  Memory locks are locks which can be used to lock
   		  a memory area and then this memory area cannot be swapped to disk.
   		> Record Locks - The child doesn’t inherit its parent’s record locks.
   		  Record locks are associated with a file block or an entire file.
   		> rocess resource utilisation and CPU time consumed is set to zero for the child.
   		> The child also doesn’t inherit timers from the parent.		

2# vfork() :
-------------
			> vfork() system call, child and parent process share same address space.
			> Once child process is executed then parent process starts its execution.
			> While vfork() system call does not use copy-on-write.
			> Child process suspends parent process execution in vfork() system call.
			> If child process alters page in address space, it is visible to parent process.
			> There is no wastage of address space.
			
3# exec family :
-----------------
			> The exec() family of functions replaces the current process image with a new process image.
			  It loads the program into the current process space and runs it from the entry point.
			  PID of the process is not changed but the data, code, stack, heap, etc. of the process
			  are changed and are replaced with those of newly loaded process.
			  The new process is executed from the entry point.
			> There is no return from a successful exec, because the calling process image is overlaid by                 the new process image.
			> The new program is loaded into the same process space. The current process is just turned into
			  a new process and hence the process id PID is not changed, this is because we are not creating 
			  a new process we are just replacing a process with another process in exec.
			  If the currently running process contains more than one thread then all the 
			  threads will be terminated and the new process image will be loaded and then executed.
			  There are no destructor functions that terminate threads of current process.
			> The currently running process is ended.
```

### File Management

1-> The Linux System calls under this are open(), read(), write(), close().



###  Device Management

1-> The Linux System calls under this is ioctl().



###  Information Maintenance

1->  The System calls under this are getpid(), alarm(), sleep().



### Communication

1-> The system calls under this are pipe() , shmget() ,mmap().


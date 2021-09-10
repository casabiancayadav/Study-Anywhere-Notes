	
	---------------------------------------------------------------------
	+					Linux System Programming                        +
	---------------------------------------------------------------------
	---------------------------------------------------------------------
	
	
	*********************************************************************
	*																	*	
	*							Lecture-1								*
	*																	*
	*********************************************************************

	# Cpmpilation Stages :
		1 )	PreProcessor
		2 )	Assembler
		3 ) cpmpiler
		4 ) linker
		5 ) executative file
		
		
	#  ShortCut :
		1.-->> # suppose  you are into some dorectory. then  you need to go into root directory. then 
				again you want to come back.
				
				# root@vivek: home/osho/workspace/ldd/download
				# root@vivek: usr/include
				# root@vivek: ls -lrt
				# root@vivek: cd -
				# root@vivek: home/osho/workspace/ldd/download
				
		2.-->> # if you want to generate all compilation stages file at once. then type following command.

				# root@vivek: touch hello.c 
				# root@vivek: gcc -save-temp hello.c
				# root@vivek: 
				# root@vivek: 
		
			After this all stages file will generate including exe file.
			
			
		3.-->> # if you want to know the nature of any file. use below commmand.

				# root@vivek: file hello.c
					some output
				# root@vivek: file hello.i
					some output
				# root@vivek: file hello.o
					some output
					
		4.-->> # if you want to know about a object file. then use below command.

				# root@vivek: ldd hello.o
					some output
				# root@vivek: ldd a.out
					some output
					
				# root@vivek: objdump -D hello.o
					some output
				# root@vivek: objdump -D a.out
					some output	
					
		5.--> # if you want to know the size of a file.
				# root@vivek: size filename
				
				
				
		6.-->> # if you want to check that what address has been taken by your program into memory.
				then first write your program in such a way that it halt.
				then search your program process and note down process ID
				and them look into memory managment.
				
				# root@vivek: gcc hello.c
				# root@vivek: ./hello
				# root@vivek: ps -aef | grep hello
					some output
				# root@vivek: cat /proc/3877/maps
					some output, 3877 is process ID which can be different in your case.
					
						===>> All addresses shows here, are virtual addresses.
						===>> you can heap and stack address also  here. Physical address may be differnet
						
					
				
				
	
	*********************************************************************
	*																	*	
	*							Lecture-2								*
	*																	*
	*********************************************************************


	# A program has typically 4 sections.
		5. Stack Section
		4. Heap Section
		3. Data Section
		2. Bss Section
		1. Text/Code Section
		
			-->> All variables Static, Global, initilized other then Zero will take place into Data sections.
			-->> All variables Static, Global, initilized or Uninitilized with Zero will take place into Data sections.
			-->> All local  variables, funcation call and its parameters will take place into stack Section.
			-->> All dynamically created variables will take place into Heap Section.
			
			===>>> All the address can be seen using previous method. where we were using memory mapping
					of a process. [ ShortCut(6) ]


	# Interview Question :
		
		1.-->> What is the difference b/w decalration and Defination ?
		  
		  
		  
	
	*********************************************************************
	*																	*	
	*							Lecture-3								*
	*																	*
	*********************************************************************



	# nm command , Please find more about it.
	

	
	*********************************************************************
	*																	*	
	*							Lecture-4								*
	*																	*
	*********************************************************************


	Interview Question :
		1.-->> What happen if we pass Zero as the argument of malloc() function.
				Hint : See man page

					
					
					

	
	*********************************************************************
	*																	*	
	*							Lecture-7								*
	*																	*
	*********************************************************************

		1.-->> What is the Difference b/w function and system call ? 
		
		@=  system call is the interface b/w user space and kernal space to communicate 
			with lower level hardware.
		@=	When we see assembly code of a function. There we can clearly see function call.		
			but in case of system call we see some number and processor register i.e eax
			
		@= Every system call has seperate number.
		@= system_call basically generate interrupt which is handler by system call handler.
		@= system_call_handler do few things mentioned below.
			+	read EAX
			+	Lookup system_call switch table -- All system_call are listed in this table.
			+	Allocate kernel stack
			+	Update EIP register in PCB
			
		@= system_call are architecture specific.
		@= We can write our own system_call.
		@= System calls are very expensive in terms of Time.
		@= system calls are system demendent.
		
		
		
		# Writting our own custom system_call 
		
			## Important Link : https://medium.com/anubhav-shrimal/adding-a-hello-world-system-call-to-linux-kernel-dad32875872
			
			@:- Please keep in  mind all this process will take place in your newly download kernel.
			
			@:- Do not try to do this in your working kernel direcctory. you will not get syscall table file.
			
			@:- It has 2 to 3 hour.
			
			
			1. Goto linux code directory
				i.e 
					# root@vivek: uname -a
					# root@vivek: cd usr/src/linux-5.8
					# root@vivek: mkdir info
					# root@vivek: cd info
					
			2. Create header file say  'processInfo.h'
			3. asmlinkage long sys_listprocessInfo(void)
			4. create a '.c' file into 'info' directory.
			5. write a Makefile into same directory with following content.
				obj-y := listprocessInfo.o
				
				This ensure that the listprocessInfo.c file compiled and include in
				the kernel source code.
			6. list your system_call into system call table.	
			
			
			
			NOte : 
			
			Different archs have different syscall numbers defined in different files

			The syscall numbers are different for each architecture, e.g.:

			x86_64: arch/x86/entry/syscalls/syscall_64.tbl: read is 0

			x86: arch/x86/entry/syscalls/syscall_32.tbl: read is 3

			arm64: include/uapi/asm-generic/unistd.h: read is 63, 
			
			see also: https://reverseengineering.stackexchange.com/questions/16917/arm64-syscalls-table/18834#18834

			arm: arch/arm/tools/syscall.tbl, read is 3
			
			
			
			
			
		## Every function has 3 main things. When we translate a function into assembly code.
				Function name :
					Pre-amble
					function Body
					post-amble
			
		## IF you want to know more about assembly language then you can refere a Book.
			-- Professional Assembly Language -by Richaerd Blum
			
			
			
	
	*********************************************************************
	*																	*	
	*							Lecture-8								*
	*																	*
	*********************************************************************

	## Files are two type.
		1. regular/system files
		2. logical Files
		
	## All running process can be seen under /proc directory.
		Search process using process IDs.
		
	## EOF in linux generate by 'ctrl + D'.

	## writev and readv syscall is a pair of system calls that implement scatter/gather I/O.
                                                                        --------------------
		it means, we can put data at once into file. 
		                             ---------------
		it store data into intermediate buffer and push/pop data at once from/to file.

	## file locking is another imporatant concept. it can be done by many ways
		
		-->> File locking is a mechanism to restrict access to a file among multiple processes.
		It allows only one process to access the file in a specific time, thus avoiding the
		interceding update problem.
		
		-->> Linux supports two kinds of file locks: advisory locks and mandatory locks.


	
	*********************************************************************
	*																	*	
	*							Lecture-10								*
	*																	*
	*********************************************************************


	## fork() syscall
		
		-->>> Why do we need fork syscall?
		-->>> what is the diffence b/w process and thread.
		-->>> Difference between a Daemon process and an orphan process?
				 just think of daemons as intentionally orphaned processes.
				 They are intended to work without a parent, but this doesn't apply to every orphaned process!
				 It is sometimes desirable to intentionally orphan a process, usually to allow a long-running
				 job to complete without further user attention, or to start an indefinitely running service
				 or agent; such processes (without an associated session) are known as daemons, 
				 particularly if they are indefinitely running.
		
		-->>> Zombie process vs Orphan process ??
				An orphan process is a computer process whose parent process has finished or terminated,
				though it (child process) remains running itself.
				A zombie process or defunct process is a process that has completed execution 
				but still has an entry in the process table as its parent process didn't invoke
				an wait() system call.
				
		-->>> What are those things. Which are shared between parent process and child process ?
				( # ) File discriptor shared b/w child and parent process.
				( # ) 
				




	
	*********************************************************************
	*																	*	
	*							Lecture-11								*
	*																	*
	*********************************************************************


	-->> When you are dealing with multiple file descriptor then use select syscall.
	-->> 'mkfifo' is the command to make a spcial file. Basically a pipe.
	-->> 'poll' syscall is also used for handling multiple descriptor.
	-->> 'mmap' syscall is used to directy mapping file/data to virtual memory address.
			it reduce over heads.
	

	
	*********************************************************************
	*																	*	
	*							Lecture-12								*
	*																	*
	*********************************************************************

	-->> Inter process communication(IPC).
	-->> Msg Quees syscalls
		>>> msgget();
		>>> msgctl();
		>>>






















					
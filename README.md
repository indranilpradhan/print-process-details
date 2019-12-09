# print-process-details

Write a program which prints the following details for all processes or if provided a
process id explicitly then for only that:
Note : Format for output must be clear and precise but can be custom as per your idea.
1. Filename of the executable
2. State – print R for running ,S for Sleeping ,D for sleeping in an uninterruptible
wait, Z for zombie, T for traced or stopped
3. process id of parent process
4. session id
5. Environment variable details
6. File descriptors opened and associated with process.
7. Process root folder.
And also print the following system stats (not limited to) :
1. total number of context switches across all CPUs
2. number of processes currently running on CPUs.
3. number of processes currently blocked, waiting for I/O to complete.

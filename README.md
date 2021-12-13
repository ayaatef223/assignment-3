# MPI

Message Passing Interface (MPI) is a standardized and portable message-passing standard designed to function on parallel computing architectures
## Installation

in ubuntu terminal write 
```bash
sudo apt install mpich
```

## how to run 
1- save sum.c file to the desktop
2- open terminal and write 
```bash
cd ~/Desktop
mpicc -o sum sum.c -lm
mpirun -np <number of processes> ./sum 
```
## important notes:
1- enter the angle in degrees
2- mpirun -np <number of processes> ./sum   example ->  mpirun -np 4 ./sum 


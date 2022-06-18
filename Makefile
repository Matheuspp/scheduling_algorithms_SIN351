run: scheduler

scheduler: main.o
	 ./main.o

main.o: CpuSchedulingSimulatorMain
	gcc -o main.o CpuSchedulingSimulatorMain.c
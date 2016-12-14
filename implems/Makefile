all: compile test
compile: sequential mpi sequential_dynamic
clean: cleantest cleansequential cleanmpi cleansequential_dynamic
test: testsequential testmpi testsequential_dynamic

# In which directory should the executables go
OutputDir = bin
# Where to put the result of the tests
TestOutput = $(OutputDir)/test.log
# Value used to test. We will compute exp(XValue) for every implementation
XValue = 3
# MPI file with the name of the machines to use
MpiMachinesFile = mpi_machines.txt

CC = gcc
CCFLAGS = -std=c11 -Wall
TIME = ./timeMeasure.py
TIMEFLAGS = $(TestOutput)
MPICC = mpicc
MPICCFLAGS = $(CCFLAGS)
MPIEXEC = mpiexec

$(OutputDir):
	mkdir -p $(OutputDir)

cleantest:
	rm -f $(TestOutput)

sequential: $(OutputDir)
	$(CC) -o $(OutputDir)/sequential -lm $(CCFLAGS) sequential.c

cleansequential:
	rm -f $(OutputDir)/sequential

testsequential: sequential
	$(TIME) $(TIMEFLAGS) $(OutputDir)/sequential $(XValue) 10
	$(TIME) $(TIMEFLAGS) $(OutputDir)/sequential $(XValue) 100
	$(TIME) $(TIMEFLAGS) $(OutputDir)/sequential $(XValue) 1000
	$(TIME) $(TIMEFLAGS) $(OutputDir)/sequential $(XValue) 10000
	$(TIME) $(TIMEFLAGS) $(OutputDir)/sequential $(XValue) 100000

mpi: $(OutputDir)
	$(MPICC) -o $(OutputDir)/mpi -lm $(MPICCFLAGS) mpi.c

cleanmpi:
	rm -f $(OutputDir)/mpi

testmpi: mpi
	$(TIME) $(TIMEFLAGS) $(MPIEXEC) -n 2 -f $(MpiMachinesFile) $(OutputDir)/mpi $(XValue) 10
	$(TIME) $(TIMEFLAGS) $(MPIEXEC) -n 2 -f $(MpiMachinesFile) $(OutputDir)/mpi $(XValue) 100
	$(TIME) $(TIMEFLAGS) $(MPIEXEC) -n 2 -f $(MpiMachinesFile) $(OutputDir)/mpi $(XValue) 1000
	$(TIME) $(TIMEFLAGS) $(MPIEXEC) -n 2 -f $(MpiMachinesFile) $(OutputDir)/mpi $(XValue) 10000
	$(TIME) $(TIMEFLAGS) $(MPIEXEC) -n 2 -f $(MpiMachinesFile) $(OutputDir)/mpi $(XValue) 100000
	$(TIME) $(TIMEFLAGS) $(MPIEXEC) -n 4 -f $(MpiMachinesFile) $(OutputDir)/mpi $(XValue) 10
	$(TIME) $(TIMEFLAGS) $(MPIEXEC) -n 4 -f $(MpiMachinesFile) $(OutputDir)/mpi $(XValue) 100
	$(TIME) $(TIMEFLAGS) $(MPIEXEC) -n 4 -f $(MpiMachinesFile) $(OutputDir)/mpi $(XValue) 1000
	$(TIME) $(TIMEFLAGS) $(MPIEXEC) -n 4 -f $(MpiMachinesFile) $(OutputDir)/mpi $(XValue) 10000
	$(TIME) $(TIMEFLAGS) $(MPIEXEC) -n 4 -f $(MpiMachinesFile) $(OutputDir)/mpi $(XValue) 100000
	$(TIME) $(TIMEFLAGS) $(MPIEXEC) -n 8 -f $(MpiMachinesFile) $(OutputDir)/mpi $(XValue) 10
	$(TIME) $(TIMEFLAGS) $(MPIEXEC) -n 8 -f $(MpiMachinesFile) $(OutputDir)/mpi $(XValue) 100
	$(TIME) $(TIMEFLAGS) $(MPIEXEC) -n 8 -f $(MpiMachinesFile) $(OutputDir)/mpi $(XValue) 1000
	$(TIME) $(TIMEFLAGS) $(MPIEXEC) -n 8 -f $(MpiMachinesFile) $(OutputDir)/mpi $(XValue) 10000
	$(TIME) $(TIMEFLAGS) $(MPIEXEC) -n 8 -f $(MpiMachinesFile) $(OutputDir)/mpi $(XValue) 100000
	$(TIME) $(TIMEFLAGS) $(MPIEXEC) -n 16 -f $(MpiMachinesFile) $(OutputDir)/mpi $(XValue) 10
	$(TIME) $(TIMEFLAGS) $(MPIEXEC) -n 16 -f $(MpiMachinesFile) $(OutputDir)/mpi $(XValue) 100
	$(TIME) $(TIMEFLAGS) $(MPIEXEC) -n 16 -f $(MpiMachinesFile) $(OutputDir)/mpi $(XValue) 1000
	$(TIME) $(TIMEFLAGS) $(MPIEXEC) -n 16 -f $(MpiMachinesFile) $(OutputDir)/mpi $(XValue) 10000
	$(TIME) $(TIMEFLAGS) $(MPIEXEC) -n 16 -f $(MpiMachinesFile) $(OutputDir)/mpi $(XValue) 100000

sequential_dynamic: $(OutputDir)
	$(CC) -o $(OutputDir)/sequential_dynamic -lm $(CCFLAGS) sequential_dynamic.c

cleansequential_dynamic:
	rm -f $(OutputDir)/sequential_dynamic

testsequential_dynamic: sequential_dynamic
	$(TIME) $(TIMEFLAGS) $(OutputDir)/sequential_dynamic $(XValue) 10
	$(TIME) $(TIMEFLAGS) $(OutputDir)/sequential_dynamic $(XValue) 100
	$(TIME) $(TIMEFLAGS) $(OutputDir)/sequential_dynamic $(XValue) 1000
	$(TIME) $(TIMEFLAGS) $(OutputDir)/sequential_dynamic $(XValue) 10000
	$(TIME) $(TIMEFLAGS) $(OutputDir)/sequential_dynamic $(XValue) 100000
	$(TIME) $(TIMEFLAGS) $(OutputDir)/sequential_dynamic $(XValue) 1000000
	$(TIME) $(TIMEFLAGS) $(OutputDir)/sequential_dynamic $(XValue) 10000000
	$(TIME) $(TIMEFLAGS) $(OutputDir)/sequential_dynamic $(XValue) 100000000

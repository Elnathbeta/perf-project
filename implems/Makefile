all: compile test
compile: sequential mpi
clean: cleantest cleansequential cleanmpi
test: testsequential testmpi

# In which directory should the executables go
OutputDir = bin
# Where to put the result of the tests
TestOutput = $(OutputDir)/test.log
# Value used to test. We will compute exp(XValue) for every implementation
XValue = 20
# MPI file with the name of the machines to use
MpiMachinesFile = mpi_machines.txt

CC = gcc
CCFLAGS = -std=c11 -Wall
TIME = /usr/bin/time
TIMEFLAGS = -o $(TestOutput) --append --format "%C, %S, %U"
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
	$(TIME) $(TIMEFLAGS) $(MPIEXEC) -n 4 -f $(MpiMachinesFile) $(OutputDir)/mpi $(XValue) 10

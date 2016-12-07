all: compile test
compile: sequential
clean: cleantest cleansequential
test: testsequential

# In which directory should the executables go
OutputDir = bin
# Where to put the result of the tests
TestOutput = $(OutputDir)/test.log
# Value used to test. We will compute exp(XValue) for every implementation
XValue = 20

CC = gcc
CCFLAGS = -std=c11 -Wall
TIME = /usr/bin/time
TIMEFLAGS = -o $(TestOutput) --append --format "%C, %S, %U"

$(OutputDir):
	mkdir -p $(OutputDir)

cleantest:
	rm -f $(TestOutput)

sequential: $(OutputDir)
	$(CC) -o $(OutputDir)/sequential -lm $(CCFLAGS) sequential.c

cleansequential:
	rm -f $(OutputDir)/sequential

testsequential:
	$(TIME) $(TIMEFLAGS) $(OutputDir)/sequential $(XValue) 10
	$(TIME) $(TIMEFLAGS) $(OutputDir)/sequential $(XValue) 100
	$(TIME) $(TIMEFLAGS) $(OutputDir)/sequential $(XValue) 1000
	$(TIME) $(TIMEFLAGS) $(OutputDir)/sequential $(XValue) 10000
	$(TIME) $(TIMEFLAGS) $(OutputDir)/sequential $(XValue) 100000

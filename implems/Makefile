all: sequential
clean: cleansequential

OutputDir = bin

CC = gcc
CCFLAGS = -std=c11 -Wall

$(OutputDir):
	mkdir -p $(OutputDir)

sequential: $(OutputDir)
	$(CC) -o $(OutputDir)/sequential -lm $(CCFLAGS) sequential.c

cleansequential:
	rm -f $(OutputDir)/sequential

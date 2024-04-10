
all:
	gcc -c ./*.c
	gcc ./*.o

test: all
	@cat ./data.txt | ./a.out

clean:
	rm -f ./*.o ./*.out



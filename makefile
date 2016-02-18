all: hw1 part2

hw1: hw1.o
	g++ hw1.o -o hw1
hw1.o: hw1.cc product_record.h
	g++ -c -g hw1.cc

part2: part2.o
	g++ part2.o -o part2
part2.o: part2.cc
	g++ -c -g part2.cc

clean: 
	rm -f *.o
	rm -f hw1 part2
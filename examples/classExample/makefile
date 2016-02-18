mp3main: mp3main.o mp3.o
	g++ mp3main.o mp3.o -o mp3main
mp3main.o: mp3main.cc mp3.h
	g++ -c -g mp3main.cc
mp3.o: mp3.cc mp3.h
	g++ -c -g mp3.cc
clean: 
	rm -f *.o
	rm -f mp3main

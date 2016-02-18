getoptex: getoptex.o
	g++ getoptex.o -o getoptex
getoptex.o: getoptex.cc
	g++ -c -g getoptex.cc
readdirExample.o: readdirExample.cc
	g++ -c -g readdirExample.cc
readdirExample: readdirExample.o
	g++ readdirExample.o -o readdirExample
templateExample.o: templateExample.cc
	g++ -c -g templateExample.cc
templateExample: templateExample.o
	g++ templateExample.o -o templateExample
forkExample.o: forkExample.cc
	g++ -c -g forkExample.cc
forkExample: forkExample.o
	g++ forkExample.o -o forkExample
threadExample.o: threadExample.cc
	g++ -c -g threadExample.cc
threadExample: threadExample.o
	g++ threadExample.o -lpthread -o threadExample
clean: 
	rm *.o
	rm -f getoptex readdirExample templateExample forkExample threadExample

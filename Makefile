CC = g++
CPPFLAGS = -Wall -g -std=c++11

app:			app.o list.o song.o artist.o

app.o:			list.h song.h artist.h

list.o:			list.h song.h artist.h

song.o:			song.h

artist.o:		artist.h

.PHONY: clean	
clean:			# clean the directory
			rm app *.o
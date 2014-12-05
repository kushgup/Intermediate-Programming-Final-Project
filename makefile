CFLAGS = -std=c++11 -pedantic -Wall -Wextra -O -g
CC = g++

pg7:
PlayerHumanTest: PlayerHumanTest.o PlayerHuman.o Player.o
	$(CC) $(CFLAGS) -o PlayerHumanTest PlayerHumanTest.o PlayerHuman.o Player.o
PlayerHumanTest.o: PlayerHumanTest.cpp PlayerHuman.h Player.h OListIterator.h Token.h Card.h Move.h
	$(CC) $(CFLAGS) -c PlayerHumanTest.cpp
PlayerHuman.o: PlayerHuman.cpp PlayerHuman.h Player.h OListIterator.h Token.h Card.h Move.h
	$(CC) $(CFLAGS) -c PlayerHuman.cpp
Player.o: Player.cpp Player.h OListIterator.h Token.h Card.h Move.h
	$(CC) $(CFLAGS) -c Player.cpp

clean:
zip:
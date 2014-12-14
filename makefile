CFLAGS = -std=c++11 -pedantic -Wall -Wextra -O -g
CC = g++

All: Driver JaipurTest BankTest

Driver: Driver.o Game.o Bank.o Deck.o Card.o Field.o Player.o PlayerHuman.o PlayerComp.o Move.o
	$(CC) $(CFLAGS) -o Driver Driver.o Game.o Bank.o Deck.o Card.o Field.o Player.o PlayerHuman.o PlayerComp.o Move.o

JaipurTest: JaipurTest.o Game.o PlayerHuman.o PlayerComp.o Player.o Bank.o Move.o Card.o Field.o Deck.o
	$(CC) $(CFLAGS) -o JaipurTest JaipurTest.o Game.o PlayerHuman.o PlayerComp.o Player.o Bank.o Move.o Card.o Field.o Deck.o

BankTest: BankTest.o Bank.o Field.o Card.o Deck.o
	$(CC) $(CFLAGS) -o BankTest BankTest.o Bank.o Field.o Card.o Deck.o

BankTest.o: BankTest.cpp Bank.h Token.h
	$(CC) $(CFLAGS) -c BankTest.cpp

Bank.o: Bank.cpp Bank.h Token.h
	$(CC) $(CFLAGS) -c Bank.cpp

Card.o: Card.cpp Card.h
	$(CC) $(CFLAGS) -c Card.cpp

Deck.o: Deck.cpp Deck.h Card.h
	$(CC) $(CFLAGS) -c Deck.cpp

Driver.o: Driver.cpp Bank.h Card.h Deck.h Field.h Game.h Move.h OList.h OListIterator.h Player.h PlayerComp.h PlayerHuman.h State.h Token.h
	$(CC) $(CFLAGS) -c Driver.cpp

Field.o: Field.cpp Field.h Card.h Deck.h
	$(CC) $(CFLAGS) -c Field.cpp

Game.o: Game.cpp Game.h State.h PlayerComp.h PlayerHuman.h Player.h Bank.h Move.h Token.h Card.h Field.h OListIterator.h OList.h Deck.h
	$(CC) $(CFLAGS) -c Game.cpp

JaipurTest.o: JaipurTest.cpp Game.h State.h PlayerComp.h PlayerHuman.h Player.h Bank.h Move.h Token.h Card.h Field.h OListIterator.h OList.h Deck.h
	$(CC) $(CFLAGS) -c JaipurTest.cpp

Move.o: Move.cpp Move.h Card.h Field.h Deck.h OListIterator.h OList.h
	$(CC) $(CFLAGS) -c Move.cpp

Player.o: Player.cpp Player.h Bank.h Move.h Token.h Card.h Field.h OListIterator.h OList.h Deck.h
	$(CC) $(CFLAGS) -c Player.cpp

PlayerHumanTest.o: PlayerHumanTest.cpp PlayerHuman.h Player.h Bank.h Move.h Token.h Card.h Field.h OListIterator.h OList.h Deck.h 
	$(CC) $(CFLAGS) -c PlayerHumanTest.cpp

PlayerHuman.o: PlayerHuman.cpp PlayerHuman.h Player.h Bank.h Move.h Token.h Card.h Field.h OListIterator.h OList.h Deck.h
	$(CC) $(CFLAGS) -c PlayerHuman.cpp

PlayerComp.o: PlayerComp.cpp PlayerComp.h Player.h Bank.h Move.h Token.h Card.h Field.h OListIterator.h OList.h Deck.h
	$(CC) $(CFLAGS) -c PlayerComp.cpp

State.o: State.cpp State.h
	$(CC) $(CFLAGS) -c State.cpp

clean:
	\rm *.o JaipurTest BankTest Driver

zip:
	zip -l pg7.zip makefile README *.h *.cpp
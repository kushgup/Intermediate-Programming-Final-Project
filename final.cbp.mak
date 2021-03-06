#------------------------------------------------------------------------------#
# This makefile was generated by 'cbp2make' tool rev.147                       #
#------------------------------------------------------------------------------#


WORKDIR = %cd%

CC = gcc.exe
CXX = g++.exe
AR = ar.exe
LD = g++.exe
WINDRES = windres.exe

INC = 
CFLAGS = -Wall -fexceptions
RESINC = 
LIBDIR = 
LIB = 
LDFLAGS = 

INC_DEBUG = $(INC)
CFLAGS_DEBUG = $(CFLAGS) -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj\\Debug
DEP_DEBUG = 
OUT_DEBUG = bin\\Debug\\final.exe

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS) -O2
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS) -s
OBJDIR_RELEASE = obj\\Release
DEP_RELEASE = 
OUT_RELEASE = bin\\Release\\final.exe

OBJ_DEBUG = $(OBJDIR_DEBUG)\\Token.o $(OBJDIR_DEBUG)\\State.o $(OBJDIR_DEBUG)\\PlayerHuman.o $(OBJDIR_DEBUG)\\PlayerComp.o $(OBJDIR_DEBUG)\\Player.o $(OBJDIR_DEBUG)\\Bank.o $(OBJDIR_DEBUG)\\Move.o $(OBJDIR_DEBUG)\\Game.o $(OBJDIR_DEBUG)\\Field.o $(OBJDIR_DEBUG)\\Deck.o $(OBJDIR_DEBUG)\\Card.o $(OBJDIR_DEBUG)\\BankTest.o

OBJ_RELEASE = $(OBJDIR_RELEASE)\\Token.o $(OBJDIR_RELEASE)\\State.o $(OBJDIR_RELEASE)\\PlayerHuman.o $(OBJDIR_RELEASE)\\PlayerComp.o $(OBJDIR_RELEASE)\\Player.o $(OBJDIR_RELEASE)\\Bank.o $(OBJDIR_RELEASE)\\Move.o $(OBJDIR_RELEASE)\\Game.o $(OBJDIR_RELEASE)\\Field.o $(OBJDIR_RELEASE)\\Deck.o $(OBJDIR_RELEASE)\\Card.o $(OBJDIR_RELEASE)\\BankTest.o

all: debug release

clean: clean_debug clean_release

before_debug: 
	cmd /c if not exist bin\\Debug md bin\\Debug
	cmd /c if not exist $(OBJDIR_DEBUG) md $(OBJDIR_DEBUG)

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LDFLAGS_DEBUG) $(LIBDIR_DEBUG) $(OBJ_DEBUG) $(LIB_DEBUG) -o $(OUT_DEBUG)

$(OBJDIR_DEBUG)\\Token.o: Token.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Token.cpp -o $(OBJDIR_DEBUG)\\Token.o

$(OBJDIR_DEBUG)\\State.o: State.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c State.cpp -o $(OBJDIR_DEBUG)\\State.o

$(OBJDIR_DEBUG)\\PlayerHuman.o: PlayerHuman.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c PlayerHuman.cpp -o $(OBJDIR_DEBUG)\\PlayerHuman.o

$(OBJDIR_DEBUG)\\PlayerComp.o: PlayerComp.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c PlayerComp.cpp -o $(OBJDIR_DEBUG)\\PlayerComp.o

$(OBJDIR_DEBUG)\\Player.o: Player.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Player.cpp -o $(OBJDIR_DEBUG)\\Player.o

$(OBJDIR_DEBUG)\\Bank.o: Bank.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Bank.cpp -o $(OBJDIR_DEBUG)\\Bank.o

$(OBJDIR_DEBUG)\\Move.o: Move.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Move.cpp -o $(OBJDIR_DEBUG)\\Move.o

$(OBJDIR_DEBUG)\\Game.o: Game.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Game.cpp -o $(OBJDIR_DEBUG)\\Game.o

$(OBJDIR_DEBUG)\\Field.o: Field.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Field.cpp -o $(OBJDIR_DEBUG)\\Field.o

$(OBJDIR_DEBUG)\\Deck.o: Deck.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Deck.cpp -o $(OBJDIR_DEBUG)\\Deck.o

$(OBJDIR_DEBUG)\\Card.o: Card.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Card.cpp -o $(OBJDIR_DEBUG)\\Card.o

$(OBJDIR_DEBUG)\\BankTest.o: BankTest.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c BankTest.cpp -o $(OBJDIR_DEBUG)\\BankTest.o

clean_debug: 
	cmd /c del /f $(OBJ_DEBUG) $(OUT_DEBUG)
	cmd /c rd bin\\Debug
	cmd /c rd $(OBJDIR_DEBUG)

before_release: 
	cmd /c if not exist bin\\Release md bin\\Release
	cmd /c if not exist $(OBJDIR_RELEASE) md $(OBJDIR_RELEASE)

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LDFLAGS_RELEASE) $(LIBDIR_RELEASE) $(OBJ_RELEASE) $(LIB_RELEASE) -o $(OUT_RELEASE)

$(OBJDIR_RELEASE)\\Token.o: Token.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Token.cpp -o $(OBJDIR_RELEASE)\\Token.o

$(OBJDIR_RELEASE)\\State.o: State.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c State.cpp -o $(OBJDIR_RELEASE)\\State.o

$(OBJDIR_RELEASE)\\PlayerHuman.o: PlayerHuman.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c PlayerHuman.cpp -o $(OBJDIR_RELEASE)\\PlayerHuman.o

$(OBJDIR_RELEASE)\\PlayerComp.o: PlayerComp.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c PlayerComp.cpp -o $(OBJDIR_RELEASE)\\PlayerComp.o

$(OBJDIR_RELEASE)\\Player.o: Player.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Player.cpp -o $(OBJDIR_RELEASE)\\Player.o

$(OBJDIR_RELEASE)\\Bank.o: Bank.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Bank.cpp -o $(OBJDIR_RELEASE)\\Bank.o

$(OBJDIR_RELEASE)\\Move.o: Move.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Move.cpp -o $(OBJDIR_RELEASE)\\Move.o

$(OBJDIR_RELEASE)\\Game.o: Game.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Game.cpp -o $(OBJDIR_RELEASE)\\Game.o

$(OBJDIR_RELEASE)\\Field.o: Field.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Field.cpp -o $(OBJDIR_RELEASE)\\Field.o

$(OBJDIR_RELEASE)\\Deck.o: Deck.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Deck.cpp -o $(OBJDIR_RELEASE)\\Deck.o

$(OBJDIR_RELEASE)\\Card.o: Card.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Card.cpp -o $(OBJDIR_RELEASE)\\Card.o

$(OBJDIR_RELEASE)\\BankTest.o: BankTest.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c BankTest.cpp -o $(OBJDIR_RELEASE)\\BankTest.o

clean_release: 
	cmd /c del /f $(OBJ_RELEASE) $(OUT_RELEASE)
	cmd /c rd bin\\Release
	cmd /c rd $(OBJDIR_RELEASE)

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release


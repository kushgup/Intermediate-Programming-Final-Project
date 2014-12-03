CFLAGS = -std=c++11 -pedantic -Wall -Wextra -O -g
CC = g++

pg7:
%.o:    %.cpp
           $(compiler) $(flags) $*.cpp

clean:
zip:
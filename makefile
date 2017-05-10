CC = g++
MPICC = mpic++
GFLAGS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
CFLAGS = -c	-Wall -I$(IDIR) -std=c++11

IDIR = inc
SRCDIR = src
OBJDIR = obj
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

EXE = corvus

.phony: depend clean

all: $(SOURCES) $(EXE)

$(EXE): $(OBJECTS)
	$(CC) $^ -o $@ $(GFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm $(EXE) $(OBJDIR)/*.o

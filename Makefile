CC = g++
MPICC = mpic++
GFLAGS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
CFLAGS = -c	-Wall -I$(IDIR) -std=c++11

IDIR = inc
SRCDIR = src
OBJDIR = obj
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))
#OBJECTS = $(OBJDIR)/Asteroids.o $(OBJDIR)/Bullet.o $(OBJDIR)/Button.o $(OBJDIR)/Object.o $(OBJDIR)/Rock.o $(OBJDIR)/Ship.o

EXE = corvus

.phony: all depend clean

all: $(EXE)

$(EXE): $(OBJECTS)
	$(CC) $^ -o $@ $(GFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)/
	$(CC) $(CFLAGS) -c -o $@ $<

# make the object directory if it doesn't already exist
$(OBJDIR)/:
	mkdir -p $@

clean:
	rm $(EXE) $(OBJECTS)

CC = g++
MPICC = mpic++
GFLAGS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
CFLAGS = -Wall -I$(IDIR) -g -std=c++11

IDIR = inc
SRCDIR = src
OBJDIR = obj
SRCS = $(shell find $(SRCDIR) -name '*.cpp') # source files
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o) # object files
DEPS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.d) # dependancy files

# Name of the executable
EXE = corvus

.phony: all depend clean

# default target
all: $(EXE)

# create the executable from all the object files
$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(GFLAGS)

# run the program
run: $(EXE)
	./$(EXE)

# ensure the obj directories are created
$(SRCS): | $(OBJDIR)

# mirror the directory structure of src/ under obj/
$(OBJDIR):
	mkdir -p $(shell find $(SRCDIR) -type d | sed "s/src/obj/")

# build each of the object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

# remove the executable and the object files
clean:
	rm $(EXE) $(OBJS)

# auto dependancy management
-include $(DEPS)

# allow for printing out variables, good for debugging
print-% : ; @echo $* = $($*)

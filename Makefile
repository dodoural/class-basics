
CXX = /usr/bin/g++

DEPENDENCY = \
./inc/aclass.h \
./inc/myclass.h

BINDIR = ./build/
BIN = $(BINDIR)output
OBJDIR = ./build/object/

INCLUDE = \
-I./inc

SOURCEDIR = ./src/


CPPFLAGS = -std=c++1z $(INCLUDE) $(LIBS) $(DEFINES)
LD_FLAGS =


sources := $(wildcard $(SOURCEDIR)*.cpp)
objects := $(addprefix $(OBJDIR),$(notdir $(sources:.cpp=.o)))

.PHONY:all clean debug

all:$(BIN)

$(OBJDIR)%.o: $(SOURCEDIR)%.cpp $(DEPENDENCY)
	@mkdir -p $(OBJDIR)
	$(CXX) $(CPPFLAGS) $(LD_FLAGS) -c $<  -o $@

$(BIN):$(objects)
	@mkdir -p $(BINDIR)
	$(CXX) $(LD_FLAGS) $^ -o $@

clean:
	@rm -rf build/
debug:
	echo $(objects)

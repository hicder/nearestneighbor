CC = g++
CFLAGS = -g -O0 -std=c++11 -I/usr/local/include -Wno-deprecated-register -MP
LINKER = g++ -L/usr/local/lib
TESTLDFLAGS = -L/usr/local/lib -lgtest -lpthread -lcgal -lgmp -lmpfr
TESTCFLAGS = -I/usr/local/include -std=c++11

SOURCE= main.cpp Plane.cpp Line.cpp Subset.cpp VerticalRayDS.cpp VerticalRay.cpp Cutting.cpp Point.cpp Utils.cpp Cell.cpp
OBJ=$(join $(addsuffix ./obj/, $(dir $(SOURCE))), $(notdir $(SOURCE:.cpp=.o))) 
DEPENDS=$(join $(addsuffix ./.dep/, $(dir $(SOURCE))), $(notdir $(SOURCE:.cpp=.d)))
TARGET=nn
LIBS=-lgtest -lpthread -lcgal -lgmp -lmpfr

## Default rule executed
all: $(TARGET)
	@true

## Clean Rule
clean:
	@-rm -f $(TARGET) $(OBJ) $(DEPENDS)

## Rule for making the actual target
$(TARGET): $(OBJ)
	@echo "============="
	@echo "Linking the target $@"
	@echo "============="
	@$(LINKER) -o $@ $^ $(LIBS)

## Generic compilation rule
%.o : %.cpp
	@mkdir -p $(dir $@)
	@echo "============="
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

## Rules for object files from cpp files
## Object file for each file is put in obj directory
## one level up from the actual source directory.
./obj/%.o : %.cpp
	@mkdir -p $(dir $@)
	@echo "============="
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

## Make dependancy rules
./.dep/%.d: %.cpp
	@mkdir -p $(dir $@)
	@echo "============="
	@echo Building dependencies file for $*.o
	$(SHELL) -ec '$(CC) -M $(CFLAGS) $< | sed "s^$*.o^../obj/$*.o^" > $@'


.PHONY: clean

-include $(DEPENDS)

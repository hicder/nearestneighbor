CC = g++
CFLAGS = -g -O0 -std=c++11 -I/usr/local/include -Wno-deprecated-register -MP
LINKER = g++ -L/usr/local/lib
TESTLDFLAGS = -L/usr/local/lib
TESTCFLAGS = -I/usr/local/include -std=c++11

TESTDIR= ./test
TESTSRC= $(addprefix $(TESTDIR)/,PlaneTest.cpp UtilsTest.cpp CuttingTest.cpp IntegrationTest.cpp)
TESTOBJ=$(join $(addsuffix obj/, $(dir $(TESTSRC))), $(notdir $(TESTSRC:.cpp=.o)))
TESTTARGET=$(addprefix test/, $(notdir $(TESTSRC:.cpp=)))
TESTDEPENDS=$(join $(addsuffix .dep/, $(dir $(TESTSRC))), $(notdir $(TESTSRC:.cpp=.d)))

MAINSOURCE= main.cpp
MAINOBJ=$(join $(addsuffix obj/, $(dir $(MAINSOURCE))), $(notdir $(MAINSOURCE:.cpp=.o)))

SOURCE= Plane.cpp Line.cpp Subset.cpp VerticalRayDS.cpp VerticalRay.cpp Cutting.cpp Point.cpp Utils.cpp Cell.cpp
OBJ=$(join $(addsuffix obj/, $(dir $(SOURCE))), $(notdir $(SOURCE:.cpp=.o)))
DEPENDS=$(join $(addsuffix .dep/, $(dir $(SOURCE))), $(notdir $(SOURCE:.cpp=.d)))

TARGET=nn
LIBS=-lgtest -lpthread -lcgal -lgmp -lmpfr

## Default rule executed
all: $(TARGET) test
	@true

## Clean Rule
clean:
	@-rm -f $(TARGET) $(OBJ) $(DEPENDS) $(TESTTARGET) $(TESTOBJ) $(TESTDEPENDS) $(MAINOBJ)

## Rule for making the actual target
$(TARGET): $(MAINOBJ) $(OBJ)
	@echo "============="
	@echo "Linking the target $@"
	@echo "============="
	$(LINKER) -o $@ $^ $(LIBS)

## Generic compilation rule
%.o : %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

## Rules for object files from cpp files
## Object file for each file is put in obj directory
## one level up from the actual source directory.
./obj/%.o : %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(TESTDIR)/obj/%.o : $(TESTDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

## Make dependancy rules
./.dep/%.d: %.cpp
	@mkdir -p $(dir $@)
	$(SHELL) -ec '$(CC) -M $(CFLAGS) $< | sed "s^$*.o^../obj/$*.o^" > $@'

$(TESTDIR)/.dep/%.d: $(TESTDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(SHELL) -ec '$(CC) -M $(CFLAGS) $< | sed "s^$*.o^../obj/$*.o^" > $@'

test: $(TESTTARGET)
	$(foreach targ, $(TESTTARGET), $(SHELL) -ec $(targ);)

$(TESTDIR)/%:test/obj/%.o $(OBJ)
	$(CC) $(TESTLDFLAGS) -o $@ $^ $(LIBS)

.PHONY: clean test

ifneq ($(MAKECMDGOALS),clean)
-include $(DEPENDS)
-include $(TESTDEPENDS)
endif


CPPFLAGS = -g -std=c++11 -Wall -stdlib=libc++ -I/home/developer/blackbox/src
CC = clang-3.6
DEPFLAGS = -MT $@ -MMD -MP -MF $(@:.o=.d~)

SRC = $(shell find . -name '*.cpp')
OBJ = $(join $(dir $(SRC)), $(patsubst %.cpp,.%.o,$(notdir $(SRC))))
DEP = $(join $(dir $(SRC)), $(patsubst %.cpp,.%.d,$(notdir $(SRC))))

COMPILE.cpp = $(CC) $(DEPFLAGS) $(CPPFLAGS) -c -o $@
POSTCOMPILE = mv -f $(@:.o=.d~) $(@:.o=.d)

all: $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -lc++ -o app

$(OBJ): $(SRC)
$(OBJ): $(SRC) $(DEP)
	$(COMPILE.cpp) $(join $(dir $@) ,$(patsubst .%.o,%.cpp,$(notdir $@)))
	$(POSTCOMPILE)
	#
	#
	#

$(DEP): ;
.PRECIOUS: $(DEP)
.PHONY: all

-include $(DEP)

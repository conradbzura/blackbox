# define compiler
CC = clang-3.8

# define various build flags
CPP_FLAGS = -g -std=c++11 -Wall -I$(BLACKBOX)/src
BLD_FLAGS = -stdlib=libc++
DEP_FLAGS = -MT $@ -MMD -MP -MF $(patsubst $(OBJ_DIR)/%.o,$(DEP_DIR)/%.d~,$@)
LNK_FLAGS = -lc++

# define target application name
TARGET = app

# define root object and dependency directories
OBJ_DIR = $(BLACKBOX)/src/.obj
DEP_DIR = $(BLACKBOX)/src/.dep

# create object and dependency directories
$(shell mkdir -p $(OBJ_DIR) $(DEP_DIR))

# create source, object, and dependency file lists
SRC = $(shell find $(BLACKBOX)/src/main -name '*.cc')
OBJ = $(patsubst $(BLACKBOX)/src/%.cc,$(OBJ_DIR)/%.o,$(SRC))
DEP = $(patsubst $(BLACKBOX)/src/%.cc,$(DEP_DIR)/%.d,$(SRC))

# map source directory tree into object and dependency root directories
PRECOMPILE = mkdir -p $(@D) $(DEP_DIR)/$(<D)
# compile source
COMPILE = $(CC) -c $(DEP_FLAGS) $(BLD_FLAGS) $(CPP_FLAGS) $< -o $@
# rename temporary dependency files to make them permanent
POSTCOMPILE = mv -f $(patsubst $(OBJ_DIR)/%.o,$(DEP_DIR)/%.d~,$@) $(patsubst $(OBJ_DIR)/%.o,$(DEP_DIR)/%.d,$@)

# build all
all: $(OBJ)
	$(CC) $(CPP_FLAGS) $(LNK_FLAGS) $(OBJ) -o $(TARGET)

# clean
clean:
	@rm -f $(OBJ) $(DEP)

# delete default rule
$(OBJ): $(OBJ_DIR)/%.o: %.cc

# perform source compilation workflow
$(OBJ): $(OBJ_DIR)/%.o: %.cc $(DEP_DIR)/%.d
	@echo "\n>> Building "$<"..."
	@echo "\n>> Mapping source directory tree:"
	$(PRECOMPILE)
	@echo "\n>> Compiling source:"
	$(COMPILE)
	@echo "\n>> Persisting dependency file:"
	$(POSTCOMPILE)
	@echo "\n>> Finished building "$<".\n"

$(DEP_DIR)/%.d: ;
.PRECIOUS: $(DEP_DIR)/%.d
.PHONY: all clean

-include $(DEP)

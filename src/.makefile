# define compiler
CC = clang-3.6

# define various build flags
CPP_FLAGS = -g -std=c++11 -Wall -I/home/conrad/Projects/blackbox/src
BLD_FLAGS = -stdlib=libc++
DEP_FLAGS = -MT $@ -MMD -MP -MF $(patsubst $(OBJ_DIR)/%.o,$(DEP_DIR)/%.d~,$@)
LNK_FLAGS = -lc++

# define target application name
TARGET = app

# define root object and dependency directories
HOME = /home/conrad
OBJ_DIR = $(HOME)/Projects/blackbox/src/.obj
DEP_DIR = $(HOME)/Projects/blackbox/src/.dep
SYN_DIR = $(HOME)/.vim/plugin/cpp/src

# create object and dependency directories
$(shell mkdir -p $(OBJ_DIR) $(DEP_DIR) $(SYN_DIR))

# create source, object, and dependency file lists
SRC = $(shell find $(HOME)/Projects/blackbox/src/main -name '*.cc')
HDR = $(shell find $(HOME)/Projects/blackbox/src/main -name '*.h')
OBJ = $(patsubst $(HOME)/Projects/blackbox/src/%.cc,$(OBJ_DIR)/%.o,$(SRC))
DEP = $(patsubst $(HOME)/Projects/blackbox/src/%.cc,$(DEP_DIR)/%.d,$(SRC))
SYNC = $(patsubst $(HOME)/Projects/blackbox/src/%.cc,$(SYN_DIR)/%.cc.s,$(SRC))
SYNH = $(patsubst $(HOME)/Projects/blackbox/src/%.h,$(SYN_DIR)/%.h.s,$(HDR))

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


# Make a highlight file for types.  Requires Exuberant ctags and awk
syntax: $(SYNH)

$(SYNH): $(SYN_DIR)/%.h.s: %.h 
	@echo $<
	mkdir -p $(@D) $(SYN_DIR)/$(<D)
	ctags --c++-kinds=+cestu-dfgmpvn -o- $< |\
                awk 'BEGIN{printf("syntax keyword Type\t")}\
                        {printf("%s ", $$1)}END{print ""}' > $@



#methods.vim: $(SRC)
#	@echo $(SRC)
#	ctags --c++-kinds=+fp-cdegmstuvn -o- -R --fields=+ |\
                awk 'BEGIN{printf("syntax keyword Function\t")}\
                        {printf("%s ", $$1)}END{print ""}' > $@

#constants.vim: $(SRC)
#	@echo $(SRC)
#	ctags --c++-kinds=+d-cefgmpstuvn -o- -R --fields=+ |\
                awk 'BEGIN{printf("syntax keyword Constant\t")}\
                        {printf("%s ", $$1)}END{print ""}' > $@

-include $(DEP)

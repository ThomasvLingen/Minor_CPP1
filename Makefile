SILENT = @

# Compiler
CC = g++
LD = $(CC)

# Compiler flags
# Wall = all warnings
# Wextra = extra warnings
# g = debug symbols
# std=c++11 = C++11
INCLUDE_PATHS = -Isrc/ -Ilibs/fmt/
COMPILER_FLAGS = -Wall -Wextra -g -std=c++11 $(INCLUDE_PATHS)

# Linker flags
# g = debug symbols
LIBS_PATH = libs/
LIBS = -L$(LIBS_PATH) -lfmt
LINKER_FLAGS = -g

# Files to compile
SRC_PATH = src/
SRC_FILES = $(shell find $(SRC_PATH) -name '*.cpp')
OBJ_FILES = $(SRC_FILES:.cpp=.o)

# Path for the resulting file
BUILD_PATH = build/
RES_PATH = res/
PROGRAM_NAME = not_rogue
EXEC = $(BUILD_PATH)$(PROGRAM_NAME)

# fmt
FMT_PATH = $(LIBS_PATH)fmt/fmt/
FMT_BUILD_DIR = $(FMT_PATH)build/
FMT_LIB = libfmt.a
FMT_TARGET_PATH = $(LIBS_PATH)$(FMT_LIB)

# Compile stuff
%.o : %.cpp
	@echo CC $<
	$(SILENT) $(CC) -c $< $(COMPILER_FLAGS) -o $@

$(EXEC) : $(OBJ_FILES)
	@echo
	mkdir -p $(BUILD_PATH)
	@echo LD $@
	$(SILENT) $(LD) $(COMPILER_FLAGS) $(OBJ_FILES) $(LINKER_FLAGS) $(LIBS) -o $(EXEC)
	@echo
	@echo "Moving resources to build"
	cp -r $(RES_PATH) $(BUILD_PATH)
	@echo

$(FMT_TARGET_PATH) : $(FMT_PATH)
	mkdir -p $(FMT_BUILD_DIR)
	cd $(FMT_BUILD_DIR); cmake ..
	cd $(FMT_BUILD_DIR); make
	cp $(FMT_BUILD_DIR)$(FMT_LIB) $(FMT_TARGET_PATH)
	rm -r $(FMT_BUILD_DIR)

all : $(EXEC)

run : $(EXEC)
	$(EXEC)

libs : $(FMT_TARGET_PATH)

debug: $(EXEC)
	gdb $(EXEC)

memory_leaks: $(EXEC)
	valgrind --tool=memcheck --leak-check=full $(EXEC)

.PHONY: clean
clean:
	@echo "Cleaning build"
	rm -rf $(shell find $(SRC_PATH) -name '*.o')
	rm -rf $(BUILD_PATH)*



# This Makefile compiles the source files into executable.
#
# Patrick Schubert April 2018

TARGET=employeeDemo
CC=g++
CFLAGS=-std=c++11 -Wall -Wextra
TEST_FLAGS=

INCDIRS= -I./inc
SRCDIR= src
CPP_FILES = $(wildcard $(SRCDIR)/*.cpp)
INC_FILES = $(wildcard $(INCDIR)/*.hpp)

TEST_DIR= ./test
TEST_TARGET=$(TEST_DIR)/runAllTests
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_INCDIRS= -I/test/inc
GTEST_DIR =$(HOME)/tools/googletest/googletest
TEST_INCDIRS += -I$(GTEST_DIR)/include/
TEST_LIBS=-lgtest -L$(GTEST_DIR) -pthread

CFLAGS += $(INCDIRS)
TEST_FLAGS += $(TEST_INCDIRS) -pthread

# Store object files in seperate directory.
OBJDIR = obj
TEST_OBJDIR = $(TEST_DIR)/obj
OBJ_FILES = $(addprefix $(OBJDIR)/,$(notdir $(CPP_FILES:.cpp=.o)))
DEPS = $(OBJ_FILES:.o=.d)
TEST_OBJ_FILES = $(addprefix $(TEST_OBJDIR)/,$(notdir $(TEST_FILES:.cpp=.o)))
DEPS += $(TEST_OBJ_FILES:.o=.d)


all: $(TARGET) $(TEST_TARGET)
	-@$(TEST_TARGET)


-include $(DEPS)

# Build executable
$(TARGET): main.cpp $(OBJ_FILES)
	@echo "Building from objects... " $(OBJ_FILES)
	$(CC) $(CFLAGS) main.cpp $(OBJ_FILES) -o $(TARGET)
	@echo

# Compile cpp into object file
$(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(DEPS)
	@echo "Compiling $<, writing to $@..."
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Build test executable
$(TEST_TARGET): $(TEST_OBJ_FILES) $(OBJ_FILES)
	@echo "Building tests..."
	@$(CC) $(TEST_OBJ_FILES) $(OBJ_FILES) $(TEST_LIBS) -o $(TEST_TARGET)

# Build test object files
$(TEST_OBJDIR)/%.o: $(TEST_DIR)/%.cpp $(DEPS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(TEST_FLAGS) -c $< -o $@
	@echo

# Build test dependency files
$(TEST_OBJDIR)/%.d: $(TEST_DIR)/%.cpp $(INC_FILES)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(TEST_FLAGS) -MM -MT $(patsubst %.d,%.o,$(@)) -MF $@ $<

# Build regular dependency files
$(OBJDIR)/%.d: $(SRCDIR)/%.cpp $(INC_FILES)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(TEST_FLAGS) -MM -MT $(patsubst %.d,%.o,$(@)) -MF $@ $<

# Cleanup
.PHONY : clean
clean:
	@echo "Cleaning up..."
	rm -rf $(TARGET)
	rm -rf $(OBJDIR)
	rm -rf $(TEST_TARGET)
	rm -rf $(TEST_OBJDIR)



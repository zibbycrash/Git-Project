# comments
# Target : dependency
# <TAB>Command

PROJECT_NAME= calculator
TEST_PROJECT_NAME=TEST_$(PROJECT_NAME)

BUILD_DIR=Build

SRC=main.c\
src/calculator_operations.c\
src/addition.c\
src/division.c\
src/factorial.c\
src/modulus.c\
src/multiplication.c\
src/power.c\
src/subtraction.c 

TEST_SRC=test/test_calculator_operation.c\
unity/unity.c\
inc/my_header.h

INC=-Iinc\
-Iunity\
-Isrc

# To check if the os is windows or linux and set the executable file

ifdef OS
	RM = del /q
	FixPath = $(subst /,\,$1)
	EXEC = exe
else
	ifeq ($(shell uname),Linux)
	RM = rm -rf
	FixPath = $1
	EXEC = out
	endif
endif

$(PROJECT_NAME)=all

# Makefile will not run target command if the name with file already exists. To override this use

.PHONY : all test coverage run clean doc

all:$(BUILD_DIR)
	gcc $(SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(PROJECT_NAME).$(EXEC))
	
run: all
	$(call FixPath,$(BUILD_DIR)/$(PROJECT_NAME).$(EXEC))
	
test: $(SRC) $(TEST_SRC)
	gcc $^ $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJECT_NAME).$(EXEC))
	$(call FixPath,$(BUILD_DIR)/$(TEST_PROJECT_NAME).$(EXEC))
	
coverage:$(PROJECT_NAME)
	gcc -fprofile-arcs -ftest-coverage $(SRC)$(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJECT_NAME).$(EXEC))
	$(call FixPath,$(BUILD_DIR)/$(TEST_PROJECT_NAME).$(EXEC))
	gcov -a $(SRC)
	
doc:
	make -C doc $(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
	$(RM) $(call FixPath,$(BUILD_DIR)/*)
	make clean -c doc
	rmdir $(BUILD_DIR) doc/html
	
$(BUILD_DIR):
	mkdir Build
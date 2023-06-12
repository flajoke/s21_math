TARGET=s21_math
TARGET_LIB=s21_math.a
TARGET_CHECK=tests

CC=gcc 
CFLAGS=-Wall -Werror -Wextra -std=c11 -pedantic -g

SRC=abs.c acos.c asin.c atan.c ceil.c cos.c exp.c fabs.c floor.c fmod.c log.c pow.c sin.c sqrt.c tan.c
OBJ=$(SRC:%.c=%.o) 

CHECK_SRC=test.c
CHECK_OBJ=$(CHECK_SRC:%.c=%.o)
CHECK_CFLAGS=-lcheck -lm -lpthread

LIB_TOOL=ar
LIB_FLAGS=-rcs

RM=rm
RMFLAGS=-rf

SYSTEM=$(shell uname -s)

ifeq ($(SYSTEM),Linux)
	OPEN_CMD=xdg-open
	BREW=.
endif
ifeq ($(SYSTEM),Darwin)
	OPEN_CMD=open
	BREW:=$(HOME)/goinfre/homebrew
endif

PATH:=$(PATH):$(BREW)/bin

# --------------------------------------------------

all: $(TARGET_LIB)


%.o: %.c
	@printf "\033[0;33m • "
	$(CC) -c $(CFLAGS) $< -o $@

$(TARGET_LIB): $(OBJ)
	@echo 
	@echo  "\033[0;32m$(TARGET) static library:\033[0m"
	$(LIB_TOOL) $(LIB_FLAGS) $@ $^ 
	@echo 
	@echo  "\033[0;32mContents:\033[1;36m"
	@$(LIB_TOOL) -t $(TARGET_LIB) | sed -e 's/^/ • /'
	@echo
	@echo  "\033[0;32mDone!\033[0m"
	@echo

check: $(CHECK_SRC) $(TARGET_LIB) 
	@echo 
	@echo  "\033[0;32mcheck test:\033[0m"
	$(CC) $^ $(CFLAGS) $(CHECK_CFLAGS) -o $(TARGET_CHECK)
	@echo
	@echo  "\033[0;32mDone!\033[0m"
	@echo

gcov_report: CFLAGS:=--coverage $(CFLAGS)
gcov_report: clean lcov test
	@echo 
	@echo  "\033[0;32mGenerating .info coverage:\033[0m"
	-@rm -rf $(CHECK_SRC:.c=.gcda)
	@$(shell PATH=$(PATH) which lcov) -t "$(TARGET)" -o $(TARGET).info -c -d . | sed -f report_output.sed
	@echo 
	@echo  "\033[0;32mDone!\033[0m"
	@echo
	@echo  "\033[0;32mGenerating html report:\033[0m"
	-mkdir report
	@$(shell PATH=$(PATH) which genhtml)  -o report $(TARGET).info | sed -f report_output.sed
	$(OPEN_CMD) ./report/index.html
	@echo
	@echo  "\033[0;32mDone!\033[0m"
	@echo

lcov:
ifeq ("", "$(shell PATH=$(PATH) which lcov)")
	$(error Need to install lcov)
endif

clean:
	@echo 
	@echo  "\033[0;32mcleaning up:\033[0m"
	-rm -rf $(TARGET_CHECK)
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./tests && rm -rf ./gcov_report
	-rm -rf *.log  && rm -rf *.dSYM
	-rm -rf *.o    && rm -rf *.gcno
	-rm -rf *.a    && rm -rf *.gcda
	-rm -rf *.out  && rm -rf *.gcda
	-rm -rf ./report/
	@echo
	@echo  "\033[0;32mDone!\033[0m"
	@echo

rebuild: clean $(TARGET_LIB) check

format: 
	clang-format --style=Google -i *.c *.h
	clang-format --style=Google -n *.c *.h

test: check
	-@./$(TARGET_CHECK) | sed -f colorize_output.sed > check.log
	-@cat check.log
	

.PHONY: all clean check lcov format
	

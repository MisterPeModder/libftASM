NAME := unit

MAKEFLAGS += --no-builtin-rules

## Commands

CC := gcc
RM := rm -f
RMDIR := rmdir -p
MKDIR := mkdir -p

## Sources and includes

SRC_PATH := srcs
SRCS :=	args.c		\
		child.c		\
		colors.c	\
		launchers.c	\
		log.c		\
		main.c		\
		unit_test.c	\

SRCS := $(addprefix $(SRC_PATH)/,$(SRCS))

INCLUDES :=	launchers.h			\
			$(SRC_PATH)/test.h	\

# Compiler flags
CPPFLAGS = -iquote. -iquote$(SRC_PATH) -I../includes
CFLAGS := -Wall -Wextra -Werror -Wsign-conversion
LDFLAGS := -L.. -lfts

## INCLUDE LAUNCHERS HERE ##

-include launchers/part1.mk

## END ##

UNAME := $(shell uname -s 2> /dev/null)
ifeq ($(UNAME), Linux)
	CFLAGS += -D_GNU_SOURCE
endif

OBJ_PATH := .bin
OBJS := $(addprefix $(OBJ_PATH)/,$(SRCS:.c=.o))
OBJS_DIRS := $(sort $(dir $(OBJS)))

vpath %.o $(OBJS_DIRS)
vpath %.c $(sort $(dir $(SRCS)))

all: $(NAME)

$(NAME): $(OBJS_DIRS) $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

$(OBJS_DIRS):
	@$(MKDIR) $@

$(OBJ_PATH)/%.o: %.c $(INCLUDES)
	@echo "Compiling $<..."
	@$(CC) -c $< $(CPPFLAGS) $(CFLAGS) -o $@

clean:
	@$(RM) $(OBJS) 2> /dev/null || true
	@$(RM) -r logs 2> /dev/null || true
	@$(RMDIR) $(OBJS_DIRS) 2> /dev/null || true
	@echo "Removed all objects"

fclean: clean
	@$(RM) $(NAME)
	@echo "Removed $(NAME) executable"

re: fclean all

.PHONY: all clean fclean

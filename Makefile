NAME := libfts.a

SRC_PATH := srcs
OBJ_PATH := .bin

SRCS_NAMES :=	ft_bzero.s		\
				ft_isalnum.s	\
				ft_isalpha.s	\
				ft_isdigit.s	\
				ft_isprint.s	\
				ft_strcat.s		\
				ft_strlen.s		\

INCS := $(SRC_PATH)/macros.s

SRCS := $(addprefix $(SRC_PATH)/,$(SRCS_NAMES))
OBJS := $(addprefix $(OBJ_PATH)/,$(SRCS_NAMES:.s=.o))

ASM := nasm
LD := ld
RM := rm
RMDIR := rmdir -p
MKDIR := mkdir -p
LC = ar rcs

UNAME := $(shell uname -s 2> /dev/null)
ifeq ($(UNAME), Darwin)
	AFLAGS := -D IS_MACH -f macho64
	LDFLAGS := -macosx_version_min 10.8 -lSystem -I $(SRC_PATH)/
else
	AFLAGS := -f elf64 -I $(SRC_PATH)/
	LDFLAGS :=
endif

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJS)
	@#$(LD) $(LDFLAGS) $(OBJS) -o $(NAME)
	$(LC) $(NAME) $(OBJS)

$(OBJ_PATH):
	@$(MKDIR) $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.s $(INCS)
	$(ASM) $(AFLAGS) $< -o $@

clean:
	$(RM) $(OBJS) 2> /dev/null || true
	$(RMDIR) $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	$(RM) $(NAME) 2> /dev/null || true

re: fclean all

.PHONY: all clean fclean re

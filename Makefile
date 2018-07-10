NAME := exec

SRCS := test.s
OBJS := $(SRCS:.s=.o)
INCS := macros.s

ASM := nasm
LD := ld
RM := rm

UNAME := $(shell uname -s 2> /dev/null)
ifeq ($(UNAME), Darwin)
	AFLAGS := -D IS_MACH -f macho64
	LDFLAGS := -macosx_version_min 10.8 -lSystem
else
	AFLAGS := -f elf64
	LDFLAGS :=
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(NAME)

%.o: %.s $(INCS)
	$(ASM) $(AFLAGS) $< -o $@

clean:
	$(RM) $(OBJS) 2> /dev/null || true

fclean: clean
	$(RM) $(NAME) 2> /dev/null || true

re: fclean all

.PHONY: all clean fclean re

NAME				=		push_swap

NAME_BONUS			=		checker

NAME_LIBRARY		=		libpushswap.a

NAME_LIBRARY_BONUS	=		bonus/libpushswap_bonus.a

SRCS				=		stack/init.c \
							stack/number_to_weight.c \
							stack/list_utils.c \
							stack/push.c \
							stack/swap.c \
							stack/shift_up.c \
							stack/shift_down.c \
							bruteforce/bruteforce.c \
							bruteforce/execute_instruction.c \
							bruteforce/detect_useless_instruction.c \
							bruteforce/print_instruction.c \
							radix.c \
							exit_program.c 

SRCS_BONUS			=		bonus/checker_utils_bonus.c \
							bonus/ft_strncmp_bonus.c \
							bonus/get_next_line_for_bonus/get_next_line_for_bonus.c \
							bonus/get_next_line_for_bonus/get_next_line_utils_for_bonus.c \
							bonus/instruction_bonus/execute_instruction_bonus.c \
							bonus/instruction_bonus/push_bonus.c \
							bonus/instruction_bonus/shift_down_bonus.c \
							bonus/instruction_bonus/shift_up_bonus.c \
							bonus/instruction_bonus/swap_bonus.c \
							bonus/check_list_sorted_bonus.c

OBJS_BONUS			=		${SRCS_BONUS:.c=.o}

OBJS				=		${SRCS:.c=.o}

CFLAGS				=		-Wall -Wextra -Werror -g

LDFLAGS				=		-L. -lpushswap -g

LDFLAGS_BONUS		=		-L./bonus -lpushswap_bonus

CC					=		gcc


${NAME}	: ${NAME_LIBRARY} main.c
	gcc main.c $(CFLAGS) $(LDFLAGS) -o ${NAME}

${NAME_LIBRARY} : ${SRCS} ${OBJS}
		ar rcs ${NAME_LIBRARY} ${OBJS}

all : ${NAME_LIBRARY} ${NAME}

fclean : clean
	rm -f libpushswap.a bonus/libpushswap_bonus.a push_swap
	rm -f checker

clean : 
	rm -f *.o
	rm -f bruteforce/*.o
	rm -f stack/*.o
	rm -f bonus/*.o
	rm -f bonus/get_next_line_for_bonus/*.o
	rm -f bonus/instruction_bonus/*.o

re: fclean all

${NAME_BONUS} : ${NAME_LIBRARY} ${NAME_LIBRARY_BONUS} ${OBJS} bonus/main_bonus.c
		gcc bonus/main_bonus.c ${CFLAGS} ${LDFLAGS_BONUS} ${LDFLAGS} -o ${NAME_BONUS}

${NAME_LIBRARY_BONUS} : ${SRCS_BONUS} ${OBJS_BONUS}
		ar rcs ${NAME_LIBRARY_BONUS} ${OBJS_BONUS}

bonus: ${NAME_LIBRARY} ${NAME_LIBRARY_BONUS} ${NAME_BONUS}

.PHONY:	all clean fclean re bonus

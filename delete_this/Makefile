# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mykman <mykman@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/27 19:55:36 by mykman            #+#    #+#              #
#    Updated: 2021/09/24 18:14:55 by mykman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION
CC				=	@gcc
CFLAGS			=	-Wall -Wextra -Werror

RED				:=	\033[38;5;9m
GREEN			:=	\033[38;5;10m
BLUE			:= 	\033[38;5;14m
YELLOW			:=	\033[38;5;226m
RESET			:=	\033[38;5;7m
PREFIX			=	[${YELLOW}${FT}${RESET}]\t\t

# VARIABLES
FT				:=	libft
NAME			:=	${FT}.a
SRCS_PATH		:=	srcs
OBJS_PATH		:=	objs

INCLUDES		:=	-I./includes \
					-I./includes/private \

# FILES
SRCS_AREA		:=	area_collision.c \
					area_to_size.c \
					is_point_in_area.c \
					point_to_area.c \
					pos_to_area.c \
					size_to_area.c
SRCS_COLORS		:=	ft_rgb.c
SRCS_CTYPE		:=	ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_islower.c \
					ft_isnumber.c \
					ft_isprint.c \
					ft_isspace.c \
					ft_isupper.c \
					ft_todigit.c \
					ft_tolower.c \
					ft_toupper.c
SRCS_DLIST		:=	ft_dlstadd_back.c \
					ft_dlstadd_front.c \
					ft_dlstadd.c \
					ft_dlstclear.c \
					ft_dlstdelone.c \
					ft_dlstfirst.c \
					ft_dlstiter.c \
					ft_dlstlast.c \
					ft_dlstmax.c \
					ft_dlstmin.c \
					ft_dlstnew.c \
					ft_dlstremove_back.c \
					ft_dlstremove_front.c \
					ft_dlstremove.c \
					ft_dlstsize.c \
					ft_dlstswap.c
SRCS_LIST		:=	ft_lstadd_back.c \
					ft_lstadd_front.c \
					ft_lstclear.c \
					ft_lstdelone.c \
					ft_lstiter.c \
					ft_lstiterp.c \
					ft_lstlast.c \
					ft_lstmap.c \
					ft_lstnew.c \
					ft_lstremove.c \
					ft_lstsize.c \
					ft_lststrjoin.c
SRCS_MATH		:=	ft_byte_get.c \
					ft_byte_repeat.c \
					ft_cmp_bn.c \
					ft_max.c \
					ft_min.c \
					ft_pow.c \
					ft_rand.c \
					ft_randint.c \
					ft_randinit.c \
					ft_sign.c \
					ft_tab_int_max.c \
					ft_tab_int_min.c
SRCS_MEMORY		:=	ft_bzero.c \
					ft_calloc.c \
					ft_memccpy.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memdup.c \
					ft_memmove.c \
					ft_memset.c \
					ft_ternary.c
SRCS_POINT		:=	add_point.c \
					ft_fpoint_to_point.c \
					isbigger_point.c \
					isequal_point.c \
					issmaller_point.c \
					new_point.c \
					print_point.c \
					sub_point.c
SRCS_STDIO		:=	ft_padding.c \
					ft_print_memory_fd.c \
					ft_putchar_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_base_fd.c \
					ft_putnbr_fd.c \
					ft_putnchar.c \
					ft_puts.c \
					ft_putstr_fd.c \
					ft_putstr_non_printable_fd.c
SRCS_STRING		:=	ft_addprefix.c \
					ft_atoi_base_l.c \
					ft_atoi_base.c \
					ft_atoi.c \
					ft_atoi_l.c \
					ft_ctoa.c \
					ft_index.c \
					ft_intsize.c \
					ft_itoa.c \
					ft_split.c \
					ft_strchr.c \
					ft_strcmp.c \
					ft_strcount.c \
					ft_strdiv.c \
					ft_strdup.c \
					ft_strendwith.c \
					ft_striteri.c \
					ft_strjoin.c \
					ft_strjoinx.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strlen.c \
					ft_strmapi.c \
					ft_strncmp.c \
					ft_strndup.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_strstartwith.c \
					ft_strtol_l.c \
					ft_strtol.c \
					ft_strtrim.c \
					ft_strtypelen.c \
					ft_substr.c \
					ft_zutoa_base.c
SRCS_PRINTF		:=	ft_printf.c \
					ft_conversion.c \
					ft_tag.c \
					ft_utils.c
SRCS_TYPEPRINTF	:=	ft_print.c \
					ft_type_c.c \
					ft_type_d.c \
					ft_type_lx.c \
					ft_type_p.c \
					ft_type_pct.c \
					ft_type_s.c \
					ft_type_u.c \
					ft_type_ux.c
SRCS_GNL		:=	get_next_line.c

SRCS			:=	$(addprefix ${SRCS_PATH}/ft_area/, ${SRCS_AREA})
SRCS			+=	$(addprefix ${SRCS_PATH}/ft_ctype/, ${SRCS_CTYPE})
SRCS			+=	$(addprefix ${SRCS_PATH}/ft_colors/, ${SRCS_COLORS})
SRCS			+=	$(addprefix ${SRCS_PATH}/ft_dlist/, ${SRCS_DLIST})
SRCS			+=	$(addprefix ${SRCS_PATH}/ft_list/, ${SRCS_LIST})
SRCS			+=	$(addprefix ${SRCS_PATH}/ft_math/, ${SRCS_MATH})
SRCS			+=	$(addprefix ${SRCS_PATH}/ft_memory/, ${SRCS_MEMORY})
SRCS			+=	$(addprefix ${SRCS_PATH}/ft_point/, ${SRCS_POINT})
SRCS			+=	$(addprefix ${SRCS_PATH}/ft_stdio/, ${SRCS_STDIO})
SRCS			+=	$(addprefix ${SRCS_PATH}/ft_string/, ${SRCS_STRING})
SRCS			+=	$(addprefix ${SRCS_PATH}/ft_printf/, ${SRCS_PRINTF})
SRCS			+=	$(addprefix ${SRCS_PATH}/ft_printf/types/, ${SRCS_TYPEPRINTF})
SRCS			+=	$(addprefix ${SRCS_PATH}/get_next_line/, ${SRCS_GNL})
OBJS			:=	$(patsubst srcs%.c, objs%.o, ${SRCS})

# RULES
objs/%.o:	srcs/%.c
	${CC} ${CFLAGS} -c ${INCLUDES} $< -o $@
	@echo "${PREFIX}Compilation of $<..."

$(NAME):		${OBJS}
	@ar -rcs $@ $^
	@echo "${PREFIX}${GREEN}Library created !${RESET}"

all:				${NAME}

clean:
	@rm -f ${OBJS}
	@echo "${PREFIX}${BLUE}Cleaning object files...${RESET}"

fclean:
	@rm -f ${NAME} ${NAME_STD} ${NAME_PRINTF} ${NAME_GNL} ${OBJS}
	@echo "${PREFIX}${RED}Full clean.${RESET}"

re:					fclean all

.PHONY:				all clean fclean re

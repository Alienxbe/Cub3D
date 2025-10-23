# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marykman <marykman@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/07 23:35:18 by marykman          #+#    #+#              #
#    Updated: 2025/10/23 13:32:20 by marykman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -----------------------------------Colors------------------------------------

RED				:=	[38;5;9m
GREEN			:=	[38;5;10m
BLUE			:= 	[38;5;14m
YELLOW			:=	[38;5;226m
RESET			:=	[38;5;7m
PREFIX			=	[${YELLOW}${NAME}${RESET}]		

# ------------------------------------VARS-------------------------------------

CURRENT_FOLDER		:=	$(shell pwd)

ifeq ($(OS),Windows_NT)
	detected_OS := Windows
else
	detected_OS := $(shell uname)
endif

# ---------------------------------Compilation---------------------------------

CC					:=	@gcc
CFLAGS				:=	-Wall -Wextra -Werror

ifeq ($(detected_OS), Linux)
	MLXFLAGS		:=	-lXext -lX11 -lm -lz
	MLX_FOLDER		:=	libs/minilibx-linux
	DFLAGS			:=	-D LINUX
else ifeq ($(detected_OS), Darwin)
	MLXFLAGS		:=	-framework OpenGL -framework AppKit
	MLX_FOLDER		:=	libs/minilibx_opengl
	DFLAGS			:=	-D MACOS
endif

# ---------------------------------Librairies----------------------------------

FT_FOLDER			:=	libs/libft
SFE_FOLDER			:=	libs/SnowFlakeEngine

FT					:=	${FT_FOLDER}/libft.a
MLX					:=	${MLX_FOLDER}/libmlx.a
SFE					:=	${SFE_FOLDER}/libsfe.a

MAKE_FT				:=	@make -s -C ${FT_FOLDER}
MAKE_MLX			:=	@make -s -C ${MLX_FOLDER}
MAKE_SFE			:=	@make -s -C ${SFE_FOLDER}

INCLUDES			:=	-I ${MLX_FOLDER} \
						-I ${FT_FOLDER}/includes \
						-I ${SFE_FOLDER}/includes \
						-I ./includes
LIBRARIES			:=	-L./${SFE_FOLDER} -lsfe \
						-L./${FT_FOLDER} -lft \
						-L./${MLX_FOLDER} -lmlx

# --------------------------------Source files---------------------------------

NAME				:=	cub3d

FILES				:=	main.c \
						draw_line.c \
						draw_map.c
FILES_EVENTS		:=	convert.c \
						events.c
FILES_MINIMAP		:=	init.c \
						update.c \
						draw.c
FILES_PARSING		:=	parse_line.c \
						init_map.c \
						utils.c \
						errors.c
FILES_PLAYER		:=	init.c \
						update.c \
						draw.c \
						collisions.c \
						move.c
FILES_RAYCAST		:=	init.c \
						update.c \
						draw.c \
						raycast.c 
FILES_SC_MAIN		:=	init.c \
						update.c \
						draw.c \
						destroy.c

SRCS				:=	$(addprefix srcs/, ${FILES})
SRCS				+=	$(addprefix srcs/events/, ${FILES_EVENTS})
SRCS				+=	$(addprefix srcs/minimap/, ${FILES_MINIMAP})
SRCS				+=	$(addprefix srcs/parsing/, ${FILES_PARSING})
SRCS				+=	$(addprefix srcs/player/, ${FILES_PLAYER})
SRCS				+=	$(addprefix srcs/raycast/, ${FILES_RAYCAST})
SRCS				+=	$(addprefix srcs/sc_main/, ${FILES_SC_MAIN})
OBJS				:=	$(patsubst srcs%.c, objs%.o, ${SRCS})

# header files
FILES				:=	cub3d.h \
						events.h \
						minimap.h \
						parsing.h \
						player.h \
						sc_main.h \
						raycast.h

						
HEADERS				:=	$(addprefix includes/, ${FILES});

# -----------------------------------Rules-------------------------------------

objs/%.o:	srcs/%.c ${HEADERS}
	${CC} ${CFLAGS} ${DFLAGS} ${INCLUDES} -c $< -o $@
	@echo "${PREFIX}Compilation of $<..."
	

$(NAME):	${FT} ${MLX} ${SFE} ${OBJS} ${HEADERS}
	${CC} ${CFLAGS} ${DFLAGS} ${OBJS} ${LIBRARIES} ${MLXFLAGS} -o ${NAME}
	@echo "${PREFIX}${NAME} compiled!"

$(FT):
	${MAKE_FT}

$(MLX):
	${MAKE_MLX}

$(SFE):
	${MAKE_SFE} LIBFT_FOLDER=${CURRENT_FOLDER}/${FT_FOLDER} \
				MLX_FOLDER=${CURRENT_FOLDER}/${MLX_FOLDER}

all:	${NAME}

clean:
	${MAKE_FT} clean
	${MAKE_MLX} clean
	${MAKE_SFE} clean
	@rm -f ${OBJS}

fclean:
	${MAKE_FT} fclean
	${MAKE_MLX} clean
	${MAKE_SFE} fclean
	@rm -f ${NAME} ${OBJS}

re:		fclean all

# -----------------------------------.PHONY------------------------------------

.PHONY:	all clean fclean re

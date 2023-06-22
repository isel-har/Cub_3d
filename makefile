NAME=cub3d
CFLAGS= -Wextra -Wall -Werror
LINK= -lmlx -framework OpenGL -framework AppKit -lm
INC= inc/cub.h  inc/objects.h inc/get_next_line.h
MLX = minilibx/libmlx.a
GNL= gnl/get_next_line.c  gnl/get_next_line_utils.c
#------------------------files---------------------------------------------
SRS=mandatory/castrays.c      mandatory/ft_split.c      mandatory/moves2.c        mandatory/surfaces.c\
	mandatory/check_sides.c   mandatory/ft_split2.c     mandatory/new_texture.c   mandatory/tools.c\
	mandatory/convert.c       mandatory/init.c          mandatory/parsing1.c      mandatory/tools2.c\
	mandatory/creation.c      mandatory/intersections.c mandatory/parsing2.c\
	mandatory/free_elements.c mandatory/main.c          mandatory/parsing3.c\
	mandatory/ft_itoa.c       mandatory/moves1.c        mandatory/parsing4.c $(GNL)
OJS= $(SRS:.c=.o)
#----------------------bonus part----------------------------------------
BSRS= bonus/castrays.c       bonus/ft_split.c       bonus/mouse.c          bonus/player_mov.c\
	bonus/check_sides.c    bonus/ft_split2.c      bonus/new_texture.c    bonus/put_maps.c\
	bonus/convert.c        bonus/init.c           bonus/parsing1.c       bonus/surfaces.c\
	bonus/creation.c       bonus/intersections.c  bonus/parsing2.c       bonus/tools.c\
	bonus/free_elements.c  bonus/intersections2.c bonus/parsing3.c		bonus/gun.c\
	bonus/ft_itoa.c        bonus/main.c           bonus/parsing4.c $(GNL)
BOJS= $(BSRS:.c=.o)
#-------------------------rules-------------------------------------------
all: $(NAME)

$(NAME): $(MLX) $(OJS)
	cc $(CFLAGS) -o $(NAME) $(MLX) $(OJS) $(LINK)

%.o:mandatory/%.c $(INC)
	cc -c $(CFLAGS) $< -o $@

bonus: $(MLX) $(BOJS)
	cc $(CFLAGS) -o $(NAME) $(MLX) $(BOJS) $(LINK)

%.o:bonus/%.c $(INC)
	cc -c $(CFLAG)  $< -o $@

$(MLX):
	@make -C ./minilibx

clean:
	@rm -rf $(OJS) $(BOJS)

fclean: clean
	@make clean -C ./minilibx
	@rm -rf $(NAME)

re : fclean all
.PHONY : clean re all fclean bonus
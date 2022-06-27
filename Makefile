#                                    	.--,-``-.                  
#	  ,----..                  ,---,.  /   /     '.      ,---,     
#	 /   /   \         ,--,  ,'  .'  \/ ../        ;   .'  .' `\   
#	|   :     :      ,'_ /|,---.' .' |\ ``\  .`-    ',---.'     \  
#	.   |  ;. / .--. |  | :|   |  |: | \___\/   \   :|   |  .`\  | 
#	.   ; /--`,'_ /| :  . |:   :  :  /      \   :   |:   : |  '  | 
#	;   | ;   |  ' | |  . .:   |    ;       /  /   / |   ' '  ;  : 
#	|   : |   |  | ' |  | ||   :     \      \  \   \ '   | ;  .  | 
#	.   | '___:  | | :  ' ;|   |   . |  ___ /   :   ||   | :  |  ' 
#	'   ; : .'|  ; ' |  | ''   :  '; | /   /\   /   :'   : | /  ;  
#	'   | '/  :  | : ;  ; ||   |  | ; / ,,/  ',-    .|   | '` ,/   
#	|   :    /'  :  `--'   \   :   /  \ ''\        ; ;   :  .'     
#	 \   \ .' :  ,      .-./   | ,'    \   \     .'  |   ,.'       
#	  `---`    `--`----'   `----'       `--`-,,-'    '---'         
	
NAME		:= cub3D
GNL			:= src/get_next_line/get_next_line_utils.c \
				src/get_next_line/get_next_line.c
PARSER		:= src/parser/parser.c \
				src/parser/parser_conf.c \
				src/parser/parser_map.c \
				src/parser/parser_utils.c \
				src/parser/parser_color.c 
VALIDATOR	:= src/validator/validator.c \
				src/validator/validator_map.c \
				src/validator/validator_file.c

UTILS		:= src/utils/str_utils0.c \
				src/utils/str_utils1.c \
				src/utils/str_utils2.c \
				src/utils/print_utils0.c 

GAME		:= src/game/game.c \
				src/game/init_game.c \
				src/game/hooks.c 

RENDER		:= src/render/render_utils0.c \

OBJ			:= $(patsubst %.c, %.o, $(GNL)) \
			$(patsubst %.c, %.o, $(PARSER)) \
			$(patsubst %.c, %.o, $(UTILS)) \
			$(patsubst %.c, %.o, $(VALIDATOR)) \
			$(patsubst %.c, %.o, $(GAME)) \
			$(patsubst %.c, %.o, $(RENDER)) \
			src/cub3D.o

#getting resolution of mac
#RWIDTH		:= $(shell system_profiler SPDisplaysDataType | grep Resolution | awk '{print $$2}') 
#RHIGHT		:= $(shell system_profiler SPDisplaysDataType | grep Resolution | awk '{print $$4}')

CC			:= cc
#FLAGS		:= -Wall -Wextra -Werror  -D WIN_H=$(RHIGHT)  -D WIN_W=$(RWIDTH)  -g -fsanitize=address 
#FLAGS		:= -Wall -Wextra -Werror  -D WIN_H=1760  -D WIN_W=3200  -g -fsanitize=address 
FLAGS		:= -Wall -Wextra -Werror   -g -fsanitize=address 

.PHONY: all clean fclean re bonus

all: $(NAME)
$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJ)   -o $(NAME) 
%.o: %.c
	@$(CC) $(FLAGS) -c $<  -o $@

bonus:
	@echo bonus

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

#	████████ ███████ ███████ ████████ ███████ 
#	   ██    ██      ██         ██    ██      
#	   ██    █████   ███████    ██    ███████ 
#	   ██    ██           ██    ██         ██ 
#	   ██    ███████ ███████    ██    ███████ 

t: $(NAME)
	@./$(NAME) maps/f.cub	|| true	
test: print_test file_extension

print_test:
	@echo "\033[36m████████ ███████ ███████ ████████ ███████ \033[0m"
	@echo "\033[36m   ██    ██      ██         ██    ██      \033[0m"
	@echo "\033[36m   ██    █████   ███████    ██    ███████ \033[0m"
	@echo "\033[36m   ██    ██           ██    ██         ██ \033[0m"
	@echo "\033[36m   ██    ███████ ███████    ██    ███████ \033[0m"

file_extension: $(NAME)
	@echo "\033[92m Test File Extension\033[0m"
	@./$(NAME) maps/t.cub	|| true	
	@./$(NAME) maps/t.cubb	|| true	
	@./$(NAME) maps/t.cu	|| true	
	@./$(NAME) maps/.cudb	|| true	
	@./$(NAME) maps/.cub	|| true	
	@echo "\033[92m End Test File Extension\033[0m"


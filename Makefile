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
				src/parser/parser_utils.c 
VALIDATOR	:= src/validator/validator.c \
				src/validator/validator_map.c \
				src/validator/validator_file.c

UTILS		:= src/utils/str_utils0.c \
				src/utils/str_utils1.c \
				src/utils/str_utils2.c 

OBJ			:= $(patsubst %.c, %.o, $(GNL)) \
			$(patsubst %.c, %.o, $(PARSER)) \
			$(patsubst %.c, %.o, $(UTILS)) \
			$(patsubst %.c, %.o, $(VALIDATOR)) \
			src/cub3D.o

CC			:= cc
FLAGS		:= -Wall -Wextra -Werror -g #-fsanitize=address 
.PHONY: all clean fclean re bonus

all: $(NAME)
$(NAME): $(OBJ)
	@$(CC)  $(FLAGS)  $(OBJ) -o $(NAME) 
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

t: print_test file_extension

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


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
				src/parser/validator.c \
				src/parser/parser_conf.c \
				src/parser/parser_utils.c 
UTILS		:= src/utils/str_utils0.c \
				src/utils/str_utils1.c

OBJ			:= $(patsubst %.c, %.o, $(GNL)) \
			$(patsubst %.c, %.o, $(PARSER)) \
			$(patsubst %.c, %.o, $(UTILS)) \
			src/cub3D.o

CC			:= cc
FLAGS		:= -Wall -Wextra -Werror
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

t: file_extension

#		______________________ _____________________________
#		\__    ___/\_   _____//   _____/\__    ___/   _____/
#		  |    |    |    __)_ \_____  \   |    |  \_____  \ 
#		  |    |    |        \/        \  |    |  /        \
#		  |____|   /_______  /_______  /  |____| /_______  /
#		                   \/        \/                  \/ 

file_extension: $(NAME)
	@echo "\033[92m Test File Extension\033[0m"
	@./$(NAME) maps/t.cub	|| true	
	@./$(NAME) maps/t.cubb	|| true	
	@./$(NAME) maps/t.cu	|| true	
	@./$(NAME) maps/.cudb	|| true	
	@./$(NAME) maps/.cub	|| true	
	@echo "\033[92m End Test File Extension\033[0m"


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 18:19:03 by rjobert           #+#    #+#              #
#    Updated: 2024/05/29 18:26:25 by rjobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
FLAGS = -MMD -std=c++98 #-Wall -Wextra -Werror #-fsanitize=address,undefined -g
NAME = testserv
RM = rm -rf

SRC_DIR = ./srcs/
INC_DIR = ./include/ ./include/Config/
OBJS_PATH	= ./OBJS/

SRC_NAME = main.cpp server/Server.cpp http/Request.cpp http/Response.cpp \
	server/Location.cpp http/DirectoryListing.cpp config/LocationConfig.cpp \
	config/ServerConfig.cpp server/Cluster.cpp http/CGI.cpp
INC_NAME = Server.hpp Location.hpp Requst.hpp Response.hpp colors.h \
	Location.hpp DirectoryListing.hpp Config/Directives.hpp Cluster.hpp LocationConfig.hpp \
	ServerConfig.hpp 


SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))
INCS = $(addprefix $(INC_DIR), $(INC_NAME))
ALL_INC = $(addprefix -I, $(INC_DIR))

OBJS = $(SRC:$(SRC_DIR)%.cpp=$(OBJS_PATH)%.o)
DEPS	= $(addprefix $(SRC_DIR), $(SRC_NAME:.cpp=.d))

all: $(OBJS_PATH) $(NAME)

-include $(DEPS)
$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(ALL_INC) -o $(NAME)


$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)
	# mkdir -p $(OBJS_PATH)/networking
	
$(OBJS_PATH)%.o: $(SRC_DIR)%.cpp Makefile
	@mkdir -p $(dir $@) 
	$(CC) $(FLAGS) $(ALL_INC) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)
	$(RM) $(OBJS_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
	

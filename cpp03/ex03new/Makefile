# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rleskine <rleskine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 16:29:22 by rleskine          #+#    #+#              #
#    Updated: 2023/11/29 19:10:17 by rleskine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	NowItsWeird

SRC			=	main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
LIBS		=	

SRCDIR		=	src
OBJDIR		=	obj
INCDIR		=	include
LIBFLG		=	

OBJ			=	$(foreach o, $(SRC:.cpp=.o),$(OBJDIR)/$(o))
LIBINC		=	$(foreach l, $(LIBS),-I $(l) -L $(l) -l$(l:lib%=%))
LIBARC		=	$(foreach l, $(LIBS),$(l)/$(l).a)
INCLUDE		=	$(foreach i, $(INCDIR),-I $(i)) $(foreach l, $(LIBS),-I $(l))

CFLAGS		=	-Wall -Wextra -Werror -std=c++98
SFLAGS		=	-fsanitize=address -g -Wno-shadow

CC 			=	c++

# == Determine OS and CPU core count =
OS := $(shell uname)

ifeq ($(OS),Linux)
  NPROCS:=$(shell grep -c ^processor /proc/cpuinfo)
endif
ifeq ($(OS),Darwin) # Assume Mac OS X
  NPROCS:=$(shell sysctl hw.ncpu | grep -o '[0-9]\+')
endif
# ====================================

all: $(NAME)

san: fclean setdebug $(NAME)

setdebug:
	$(eval CFLAGS := $(CFLAGS) $(SFLAGS))

$(NAME): $(OBJ) $(LIBARC)
	$(CC) $(CFLAGS) $(INCLUDE) $(LIBFLG) $(LIBINC) $(MLX42) -o $@ $(OBJ)

$(OBJ): $(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@if [ $(OBJDIR) != '.' ] && [ ! -d $(OBJDIR) ]; then mkdir $(OBJDIR); fi
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $(SRCDIR)/$(notdir $(@:.o=.cpp))

$(LIBARC): %:
	$(MAKE) -j$(NPROCS) -C $(basename $(notdir $@))

clean:
	@$(foreach l, $(LIBS),$(MAKE) -C $(l) clean;)
	@rm -f $(foreach o, $(OBJ),$(o))
	@if [ $(OBJDIR) != '.' ] && [ -d $(OBJDIR) ]; then rmdir $(OBJDIR); fi

fclean: clean
	@$(foreach l, $(LIBS),$(MAKE) -C $(l) fclean;)
	@if [ -f $(NAME) ]; then /bin/rm $(NAME); fi

re: fclean all

.PHONY: bonus
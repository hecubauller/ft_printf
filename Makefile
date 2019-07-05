# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huller <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/05 20:42:10 by huller            #+#    #+#              #
#    Updated: 2019/07/05 20:51:59 by huller           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GRN         =   \x1B[32m
MAG         =   \x1B[35m
RES         =   \x1B[0m


NAME            =   libftprintf.a

# FDF
SRC_PATH        =   srcs/
OBJ_PATH        =   srcs/obj/
INC_PATH        =   includes/
# LIBFT
LIB_PATH        =   libft/
LIB_INC_PATH    =   libft/includes/

# PRINTF
SRC_NAME        =	ft_itoa_fp.c    mexp.c            str_ad.c\
e_zrs.c           ft_ox.c           pw.c              str_ml.c\
fld_edge.c        ft_p.c            pw_to_str.c       t_str.c\
fr_p.c            ft_printf.c       reader.c          wzrs.c\
ft_c.c            ft_printf.h       res_o_fr.c        zrs.c\
ft_e.c            ft_round.c        rnd.c\
add_z.c           ft_f.c            int_p.c           rnd_z.c\
apply_flags.c     ft_fld.c          libft             rndg.c\
author            ft_g.c            rndg_z.c\
c_str.c           ft_itoa_base.c    mantis.c          s_str.c\
ft_d.c            ft_rg.c           res_w_fr.c

OBJ_NAME        =   $(SRC_NAME:.c=.o)
INC_NAME        =   ft_printf.h
# LIBFT
LIB_NAME        =   libft.a
LIB_INC_NAME    =   libft.h

# FDF
OBJ             =   $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC             =   $(addprefix $(INC_PATH), $(INC_NAME))
# LIBFT
LIB             =   $(addprefix $(LIB_PATH), $(LIB_NAME))
LIB_INC         =   $(addprefix $(LIB_INC_PATH), $(LIB_INC_NAME))

.PHONY:             all $(LIB_NAME) clean fclean re


all:                $(LIB_NAME) $(NAME)

# LIBFT
$(LIB_NAME):
                    @make -C $(LIB_PATH)
# PRINTF
$(NAME):            $(LIB) $(OBJ)
                    @gcc -Wall -Wextra -Werror $(OBJ) \
						-L $(LIB_PATH) -lft -o $(NAME)
                    @echo "$(GRN)\nLinking [ $(NAME) ] SUCCESS$(RES)"

# LIBFT
$(LIB):             $(LIB_NAME)
# PRINTF
$(OBJ_PATH)%.o:     $(SRC_PATH)%.c $(INC) $(LIB_INC)
                    @mkdir -p $(OBJ_PATH)
                    @gcc -Wall -Wextra -Werror \
                        -I $(INC_PATH) -I $(LIB_INC_PATH) -o $@ -c $<
                    @echo "$(GRN).\c$(RES)"

clean:
                    @make -C $(LIB_PATH) fclean
                    @rm -f $(OBJ)
                    @rm -rf $(OBJ_PATH)
                    @echo "$(MAG)Cleaning [ $(NAME) ] OK$(RES)"

fclean:             clean
                    @rm -f $(NAME)
                    @echo "$(MAG)Delete [ $(NAME) ] OK$(RES)"

re:                 fclean all

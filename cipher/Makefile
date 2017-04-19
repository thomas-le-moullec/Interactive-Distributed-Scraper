NAME       =        cipher

CC          =       g++

RM          =       rm -f

SRCS        =       	main.cpp		\
            ACipher.cpp         \
			Caesar.cpp          \
			Xor.cpp

OBJS        =       $(SRCS:.cpp=.o)

CPPFLAGS    =       -I . -lpthread


all         :       $(NAME)

$(NAME)     :       $(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(CPPFLAGS)

clean       :
			$(RM) $(OBJS)

fclean      :
			$(RM) $(OBJS)
			$(RM) $(NAME)

re          :       fclean all

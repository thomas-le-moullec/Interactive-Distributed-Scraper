NAME       =        socket

CC          =       g++

RM          =       rm -f

SRCS        =       	ProcessManagerSockets.cpp		\
			Socket.cpp              \
			main.cpp

OBJS        =       $(SRCS:.cpp=.o)

CPPFLAGS    =       -lpthread


all         :       $(NAME)

$(NAME)     :       $(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(CPPFLAGS)

clean       :
			$(RM) $(OBJS)

fclean      :
			$(RM) $(OBJS)
			$(RM) $(NAME)

re          :       fclean all

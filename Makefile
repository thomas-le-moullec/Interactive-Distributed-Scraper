NAME					=			plazza

CC						=			g++

RM						=			rm -rf

SRCSPATH			=			./Sources/

SRCS					=			$(SRCSPATH)main.cpp \
										$(SRCSPATH)AController.cpp \
										$(SRCSPATH)AModel.cpp \
										$(SRCSPATH)AProcess.cpp \
										$(SRCSPATH)AProcessManager.cpp \
										$(SRCSPATH)ASocket.cpp \
										$(SRCSPATH)AStrategyCipher.cpp \
										$(SRCSPATH)AThreadsPool.cpp \
										$(SRCSPATH)AView.cpp \
										$(SRCSPATH)Caesar.cpp \
										$(SRCSPATH)CondVar.cpp \
										$(SRCSPATH)ContextInformation.cpp \
										$(SRCSPATH)Information.cpp \
										$(SRCSPATH)Mutex.cpp \
										$(SRCSPATH)Ncurses.cpp \
										$(SRCSPATH)NoGui.cpp \
										$(SRCSPATH)Process.cpp \
										$(SRCSPATH)ProcessManagerSockets.cpp \
										$(SRCSPATH)Socket.cpp \
										$(SRCSPATH)StrategyEmailAddress.cpp \
										$(SRCSPATH)StrategyIpAddress.cpp \
										$(SRCSPATH)StrategyPhoneNumber.cpp \
										$(SRCSPATH)Thread.cpp \
										$(SRCSPATH)ThreadPool.cpp \
										$(SRCSPATH)Time.cpp \
										$(SRCSPATH)Xor.cpp \

OBJS					=			$(SRCS:.cpp=.o)

CPPFLAGS			=			-I ./Includes -lpthread

CXXFLAGS			=

all:								$(NAME)

$(NAME):						$(OBJS)
										$(CC) -o $(NAME) $(CPPFLAGS) $(CXXFLAGS) $(OBJS)

clean:
										$(RM) $(OBJS)

fclean:							clean
										$(RM) $(NAME)

re:									fclean all

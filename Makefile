NAME					=			plazza

CC						=			g++

RM						=			rm -rf

SRCSPATH			=			./Sources/
ERRORSPATH			=			./Errors/

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
										$(SRCSPATH)OpaqueType.cpp \
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
										$(SRCSPATH)Regex.cpp
										$(ERRORSPATH)Errors.cpp \

OBJS					=			$(SRCS:.cpp=.o)

CPPFLAGS			=			-I ./Includes -I ./Errors -lpthread -lncurses

CXXFLAGS			=

all:								$(NAME)

$(NAME):						$(OBJS)
										$(CC) -o $(NAME)  $(CXXFLAGS) $(OBJS) $(CPPFLAGS)

clean:
										$(RM) $(OBJS)

fclean:							clean
										$(RM) $(NAME)

re:									fclean all

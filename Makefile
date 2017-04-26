NAME					=			plazza

NAMEUI				=			plazzaGraphic

CC						=			g++

RM						=			rm -rf

SRCSPATH			=			./Sources/

NOGUIPATH			=			$(SRCSPATH)NoGui/

GUIPATH				=			$(SRCSPATH)Gui/

ERRORSPATH		=			./Errors/

SRCSGUI				=			$(GUIPATH)main.cpp \
										$(GUIPATH)Ncurses.cpp \

SRCSNOGUI			=			$(NOGUIPATH)main.cpp \
										$(NOGUIPATH)NoGui.cpp \

SRCS					=			$(SRCSPATH)AController.cpp \
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
										$(SRCSPATH)Regex.cpp \
										$(SRCSPATH)Errors.cpp \

OBJSGUI				=			$(SRCSGUI:.cpp=.o) \
										$(SRCS:.cpp=.o) \

OBJSNOGUI			=			$(SRCSNOGUI:.cpp=.o) \
										$(SRCS:.cpp=.o) \

CPPFLAGS			=			-I ./Includes -lpthread -lncurses

CXXFLAGS			=			-W -Wall -Wextra -std=c++11

all:								$(NAME)

ui:									$(NAMEUI)

$(NAME):						$(OBJSNOGUI)
										$(CC) -o $(NAME) $(CXXFLAGS) $(OBJSNOGUI) $(CPPFLAGS)

$(NAMEUI):					$(OBJSGUI)
										$(CC) -o $(NAMEUI) $(CXXFLAGS) $(OBJSGUI) $(CPPFLAGS)

clean:
										$(RM) $(OBJSGUI) $(OBJSNOGUI)

fclean:							clean
										$(RM) $(NAME) $(NAMEUI)

re:									fclean all

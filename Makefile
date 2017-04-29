NAME					=			plazza

NAMEUI				=			plazzaGraphic

CC						=			g++

RM						=			rm -rf

SRCSPATH			=			./Sources/

ENCAPSULATION	=			$(SRCSPATH)Encapsulation/

ERRORS				=			$(SRCSPATH)Errors/

EXECUTION			=			$(SRCSPATH)Execution/

MODEL					=			$(SRCSPATH)Model/

PROCESS				=			$(SRCSPATH)Process/

VIEW					=			$(SRCSPATH)View/

NOGUI					=			$(VIEW)NoGui/

GUI						=			$(VIEW)Gui/

SRCSGUI				=			$(GUI)main.cpp \
										$(GUI)Ncurses.cpp \
										$(GUI)Sfml.cpp \

SRCSNOGUI			=			$(NOGUI)main.cpp \
										$(NOGUI)NoGui.cpp \

SRCS					=			$(ENCAPSULATION)Thread.cpp \
										$(ENCAPSULATION)CondVar.cpp \
										$(ENCAPSULATION)Mutex.cpp \
										$(ENCAPSULATION)OpaqueType.cpp \
										$(ENCAPSULATION)Time.cpp \
										$(ENCAPSULATION)Regex.cpp \
										$(ERRORS)Errors.cpp \
										$(EXECUTION)AStrategyCipher.cpp \
										$(EXECUTION)Caesar.cpp \
										$(EXECUTION)Xor.cpp \
										$(EXECUTION)Atbash.cpp \
										$(EXECUTION)StrategyEmailAddress.cpp \
										$(EXECUTION)StrategyIpAddress.cpp \
										$(EXECUTION)StrategyPhoneNumber.cpp \
										$(EXECUTION)StrategyCreditCardNumber.cpp \
										$(MODEL)AModel.cpp \
										$(MODEL)ContextInformation.cpp \
										$(MODEL)Information.cpp \
										$(PROCESS)AController.cpp \
										$(PROCESS)AProcess.cpp \
										$(PROCESS)AProcessManager.cpp \
										$(PROCESS)ASocket.cpp \
										$(PROCESS)AThreadsPool.cpp \
										$(PROCESS)Process.cpp \
										$(PROCESS)ProcessManagerSockets.cpp \
										$(PROCESS)Socket.cpp \
										$(PROCESS)ThreadPool.cpp \
										$(VIEW)AView.cpp \

OBJSGUI				=			$(SRCSGUI:.cpp=.o) \
										$(SRCS:.cpp=.o) \

OBJSNOGUI			=			$(SRCSNOGUI:.cpp=.o) \
										$(SRCS:.cpp=.o) \

CPPFLAGS			=			-I ./Includes -lpthread

CPPFLAGSUI		=			-I ./Includes -lpthread -lncurses -lsfml-graphics -lsfml-window -lsfml-system

CXXFLAGS			=			-W -Wall -Wextra -std=c++11

all:								$(NAME)

ui:									$(NAMEUI)

$(NAME):						$(OBJSNOGUI)
										$(CC) -o $(NAME) $(CXXFLAGS) $(OBJSNOGUI) $(CPPFLAGS)

$(NAMEUI):					$(OBJSGUI)
										$(CC) -o $(NAMEUI) $(CXXFLAGS) $(OBJSGUI) $(CPPFLAGSUI)

clean:
										$(RM) $(OBJSGUI) $(OBJSNOGUI)

fclean:							clean
										$(RM) $(NAME) $(NAMEUI)

re:									fclean all

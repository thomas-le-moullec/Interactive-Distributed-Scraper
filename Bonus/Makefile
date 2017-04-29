NAMECC					=			creditcard_generator

NAMEAT					=			atbash_generator

NAMECA					=			caesar_generator

NAMEXO					=			xor_generator

NAMEIP					=			ip_generator

NAMEMA					=			email_generator

CC							=			g++

RM							=			rm -rf

SRCSPATH				=			./

CCGSRCS					=			$(SRCSPATH)creditCardGenerator.cpp

GATSRCS					=			$(SRCSPATH)generateAtbash.cpp

CAESRCS					=			$(SRCSPATH)generateCaesar.cpp

XORSRCS					=			$(SRCSPATH)generateXor.cpp

IPSRCS					=			$(SRCSPATH)ipGenerator.cpp

MAISRCS					=			$(SRCSPATH)mailGenerator.cpp

CCGOBJS					=			$(CCGSRCS:.cpp=.o)

GATOBJS					=			$(GATSRCS:.cpp=.o)

CAEOBJS					=			$(CAESRCS:.cpp=.o)

XOROBJS					=			$(XORSRCS:.cpp=.o)

IPOBJS					=			$(IPSRCS:.cpp=.o)

MAIOBJS					=			$(MAISRCS:.cpp=.o)

all:									$(NAMECC) $(NAMEAT) $(NAMECA) $(NAMEXO) $(NAMEIP) $(NAMEMA)

$(NAMECC):						$(CCGOBJS)
											$(CC) -o $(NAMECC) $(CCGOBJS)

$(NAMEAT):						$(GATOBJS)
											$(CC) -o $(NAMEAT) $(GATOBJS)

$(NAMECA):						$(CAEOBJS)
											$(CC) -o $(NAMECA) $(CAEOBJS)

$(NAMEXO):						$(XOROBJS)
											$(CC) -o $(NAMEXO) $(XOROBJS)

$(NAMEIP):						$(IPOBJS)
											$(CC) -o $(NAMEIP) $(IPOBJS)

$(NAMEMA):						$(MAIOBJS)
											$(CC) -o $(NAMEMA) $(MAIOBJS)

clean:
											$(RM) $(CCGOBJS) $(GATOBJS) $(CAEOBJS) $(XOROBJS) $(IPOBJS) $(MAIOBJS)

fclean:							  clean
										  $(RM) $(NAMECC) $(NAMEAT) $(NAMECA) $(NAMEXO) $(NAMEIP) $(NAMEMA)

re:										fclean all

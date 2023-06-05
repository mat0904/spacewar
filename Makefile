##
## EPITECH PROJECT, 2023
## mat
## File description:
## Makefile
##

MAIN_SRC	=	src/main.cpp

FILE_SRC	=	src/spacewar.cpp \
				src/gloop.cpp \
				src/display.cpp \
				\
				src/event/event.cpp \
				src/event/player_event.cpp \
				\
				src/game/game.cpp \
				\
				src/hud/hud.cpp \
				\
				src/ship/ship.cpp \
				\
				src/player/player.cpp

FILE_OBJ	=	$(FILE_SRC:.cpp=.o)
MAIN_OBJ	=	$(MAIN_SRC:.cpp=.o)

CC	=	g++
CFLAGS	= -Wall -Wextra
SANITIZE	=	-g3 -fsanitize=address
LIB	=	-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS	=	$(LIB)
COVERAGE	=	--coverage -lcriterion
EXE	=	spacewar

all:	$(EXE)

%.o:	%.c
		$(CC) -o $@ -c $< $(CFLAGS)

%_test.o:	%.c
			$(CC) -o $@ -c $<

main.o:	main.c
		$(CC) -o $@ -c $< $(CFLAGS)

$(EXE):	$(FILE_OBJ) $(MAIN_OBJ)
		$(CC) -o $(EXE) $(FILE_OBJ) $(MAIN_OBJ) $(LDFLAGS)

RUN:	$(EXE)
		./$(EXE)

sanitize:	$(FILE_OBJ) $(MAIN_OBJ)
			$(CC) -o $(EXE) $^ $(LDFLAGS)

clean:
		rm -rf $(MAIN_OBJ)
		rm -rf $(FILE_OBJ)
		$(shell find * -name "vgcore.*" -delete)

fclean:	clean
		rm -rf $(EXE)

re:	fclean all

.PHONY: all

sanitize: CFLAGS += $(SANITIZE)
sanitize: LDFLAGS += $(SANITIZE)

CC = g++
CFLAGS = -Wall -g -std=c++17
LIB = -lmingw32 -lSDL2main -lSDL2

OBJDIR = bin
SRCDIR = src
INCDIR = -Isrc -Isrc/engine -Isrc/engine/*/ -Isrc/engine/SDL2 -Llib

APP = build/main
SRC = $(wildcard src/*.cpp)  $(wildcard src/*/*.cpp) $(wildcard src/*/*.c) $(wildcard src/*/*/*.cpp) $(wildcard src/*/*/*.c)
OBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(basename $(notdir $(SRC)))))

#DIR = $(sort $(dir $(wildcard src/*/)))
#DIR = $(wildcard src/*/) 

#all:
#	$(DIR)

#$(OBJDIR)/%.o: src/%.cpp
#	$(CC) $(INCDIR) $(CFLAGS) -c -o $@ $< 
#$(OBJDIR)/%.o: src/engine/glad/%.cpp 
#	$(CC) $(INCDIR) $(CFLAGS) -c -o $@ $<
#$(OBJDIR)/%.o: src/engine/glm/%.cpp 
#	$(CC) $(INCDIR) $(CFLAGS) -c -o $@ $<
#$(OBJDIR)/%.o: src/engine/imgui/%.cpp 
#	$(CC) $(INCDIR) $(CFLAGS) -c -o $@ $<
#$(OBJDIR)/%.o: src/engine/%.cpp 
#	$(CC) $(INCDIR) $(CFLAGS) -c -o $@ $<

#$(OBJDIR)/%.o: src/engine/glad/%.c ~
#	$(CC) $(INCDIR) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/%.o: src/%.cpp
	$(CC) $(INCDIR) $(CFLAGS) -c -o $@ $<
$(OBJDIR)/%.o: src/*/%.cpp
	$(CC)  $(INCDIR) $(CFLAGS) -c -o $@ $<
$(OBJDIR)/%.o: src/*/*/%.cpp
	$(CC)  $(INCDIR) $(CFLAGS) -c -o $@ $<
$(OBJDIR)/%.o: src/*/*/%.c
	$(CC)  $(INCDIR) $(CFLAGS) -c -o $@ $<


#$(OBJDIR)/%.o: $(SRC)
#	echo $^
#	$(CC) $(CFLAGS) -c -o $@ $^

all: $(APP) 
	@echo complete

$(APP): $(OBJ)
	$(CC) $(INCDIR) $(CFLAGS) -o $@ $^ $(LIB)

.PHONY: clean
clean:
	del $(OBJDIR)\*.o



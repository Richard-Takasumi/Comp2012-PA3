CPPFLAGS = -std=c++11 -Wall -g
CPPFLAGS_leak = -std=c++11 -fsanitize=address,leak,undefined -g

OBJ_DIR = obj
OBJ_DIR_leak = obj_leak

SRCS	= main.cpp BST_Mailman.cpp BST_PostOffice.cpp Mail.cpp
OBJS	= $(SRCS:.cpp=.o)
DEPS	= $(OBJS:.o=.d)

OBJECTS = $(addprefix $(OBJ_DIR)/,$(OBJS))
OBJECTS_leak = $(addprefix $(OBJ_DIR_leak)/,$(OBJS))

all: create_directory pa3.exe # pa3_leak.exe
# Remove the '#' in the above line to add pa3_leak.exe,
# if you want to test memory leakage on your machine. 

create_directory:
	if not exist "$(OBJ_DIR)"  mkdir $(OBJ_DIR) 
	if not exist "$(OBJ_DIR_leak)"  mkdir $(OBJ_DIR_leak)

# mkdir -p $(OBJ_DIR) $(OBJ_DIR_leak)
# If you are using Windows, use the following command to replace "mkdir -p $(OBJ_DIR) $(OBJ_DIR_leak)"

pa3.exe: $(OBJECTS)
	g++ $(CPPFLAGS) -o $@ $^

pa3_leak.exe: $(OBJECTS_leak)
	g++ -o $@ $(CPPFLAGS_leak) $^

# To include the .d dependency files
-include $(OBJ_DIR)/$(DEPS)

$(OBJ_DIR)/%.o: %.cpp
	g++ $(CPPFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR_leak)/%.o: %.cpp
	g++ $(CPPFLAGS_leak) -MMD -MP -c $< -o $@

clean:
	rmdir /Q /S $(OBJ_DIR) $(OBJ_DIR_leak)
	del *.exe
# rm -rf $(OBJ_DIR) $(OBJ_DIR_leak) *.exe
# If you are using Windows, use the following command to replace "rm -rf $(OBJ_DIR) $(OBJ_DIR_leak) *.exe"

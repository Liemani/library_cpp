NAME = libcpp.a

SRCS = \
       Stopwatch.cpp \
       Timespec.cpp \
       Utility.cpp \

OBJS = $(SRCS:.cpp=.o)
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDE  =
LIBRARY =
COMPILE = $(CXX) $(CXXFLAGS) $(INCLUDE) $(DEBUG_OPTION)
LINK = $(COMPILE) $(LIBRARY)
RM = rm -f
AR = ar rc



.PHONY: all debug setdebug clean fclean re
all : $(NAME)

debug : clean setdebug $(NAME)
setdebug :
	$(eval DEBUG_OPTION = -g)

clean :
	$(RM) $(OBJS)
fclean : clean
	$(RM) $(NAME)

re : fclean all



$(NAME) : $(OBJS)
	$(AR) $@ $^

testStopwatch : $(OBJS) testStopwatch.o
	$(LINK) -o $@ $^

%.o : %.cpp
	$(COMPILE) -o $@ -c $<

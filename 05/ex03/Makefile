NAME=AForm
SRCS=	Bureaucrat.cpp \
		AForm.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		Intern.cpp \
		main.cpp
OBJS=${SRCS:.cpp=.o}
CC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98 

all: ${NAME}

%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o $@  

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
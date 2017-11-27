CXX = g++
CXXFLAGS = -std=c++0x
SRCS = main.cpp twoOpt.cpp
HEADERS = twoOpt.hpp
OBJS = main.o twoOpt.o
EXECUTABLE = opt

default: ${SRCS} ${HEADERS} ${OBJS}
	${CXX} ${OBJS} -o ${EXECUTABLE}

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -c $(:@.cpp=.o)

clean:
	rm ${OBJS} ${EXECUTABLE}

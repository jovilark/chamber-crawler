CXX=g++
CXXFLAGS=-std=c++14 -MMD -g -Wall

INCLUDEDIR=Headers
SOURCEDIR=Sources
INCLUDES=$(wildcard ${INCLUDEDIR}/*.h)
SOURCES=$(wildcard ${SOURCEDIR}/*.cc)
OBJECTS=${SOURCES:.cc=.o}
DEPENDS=${OBJECTS:.o=.d}
EXEC=cc3k

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean echoes

clean:
	rm ${OBJECTS} ${DEPENDS} 

echoes:
	@echo "INC files: $(INCLUDES)"  
	@echo "SRC files: $(SOURCES)"
	@echo "OBJ files: $(OBJECTS)"
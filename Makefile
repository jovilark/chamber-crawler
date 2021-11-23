CXX=g++
CXXFLAGS=-std=c++14 -MMD

INCLUDEDIR=./Headers
SOURCEDIR=./Source
INCLUDES=$(wildcard *.h ${INCLUDEDIR})
SOURCES=$(wildcard *.cc ${SOURCEDIR})
OBJECTS=${SOURCES:.cc=.o}
DEPENDS=${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
    ${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean echoes

clean:
    rm ${OBJECTS} ${DEPENDS} ${EXEC}

echoes:
    @echo "INC files: $(INCLUDES)"  
    @echo "SRC files: $(SOURCES)"
    @echo "OBJ files: $(OBJECTS)"
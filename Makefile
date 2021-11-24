CXX=g++
CXXFLAGS=-std=c++14 -MMD

INCLUDEDIR=Headers
SOURCEDIR=Sources
OBJECTDIR=Objects
BINDIR=Bin
INCLUDES=$(wildcard ${INCLUDEDIR}/*.h)
SOURCES=$(wildcard ${SOURCEDIR}/*.cc)
OBJECTS=${SOURCES:.cc=.o}
DEPENDS=${OBJECTS:.o=.d}
EXEC=CC3K

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
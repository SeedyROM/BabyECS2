CXX= g++
CXXFLAGS= -O3 -std=c++14 -g -ggdb -w -Wfatal-errors -fPIC
LIBRARYS= -lsfml-system -lsfml-graphics -lsfml-window
INCLUDES= -I./include

#
# Hackity hack, whatever it works.
#
DEPENDENCIES  = $(wildcard src/*.cpp)
DEPENDENCIES += $(wildcard src/**/*.cpp)
DEPENDENCIES := $(DEPENDENCIES:src/%.cpp=%.o)
DEPENDENCIES := $(DEPENDENCIES:%.o=bin/%.o)
OBJECT_FILES := $(foreach dep, $(DEPENDENCIES), bin/$(notdir $(dep)))

default: BabyECS

bin/%.o: src/%.cpp include/%.hpp
	$(CXX) $(INCLUDES) $(LIBRARYS) $(CXXFLAGS) -c $< -o ./bin/$(notdir $@)

BabyECS: $(DEPENDENCIES)
	$(CXX) ./test/main.cpp -o ./bin/BabyECS $(OBJECT_FILES) $(LIBRARYS) $(INCLUDES) $(CXXFLAGS)

.PHONY: clean run test
clean:
	-rm bin/*.o bin/BabyECS

run:
	./bin/BabyECS

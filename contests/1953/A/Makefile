CPPFLAGS = --std=c++17 -O3 -Wall -Werror -pedantic

BINARIES = main_v1 main_v2

all: $(BINARIES)

$(BINARIES): %: %.cpp
	g++ $(CPPFLAGS) $< -o $@

clean:
	rm -rf $(BINARIES)

# Makefile cho dự án Catch2
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Targets
all: test

# Biên dịch file test
test: test_ticket.exe
	./test_ticket.exe

test_ticket.exe: test_ticket.cpp ticket.cpp
	$(CXX) $(CXXFLAGS) -o test_ticket.exe test_ticket.cpp ticket.cpp

# Biên dịch chương trình chính (nếu cần)
main: main.exe

main.exe: main.cpp ticket.cpp
	$(CXX) $(CXXFLAGS) -o main.exe main.cpp ticket.cpp

# Dọn dẹp
clean:
	del *.exe

.PHONY: all test main clean
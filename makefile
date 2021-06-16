CC = g++
flags = -std=c++11 -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self
exe = builder.exe
deps = country.o city.o
hs = country.h city.h
lib = libroadBuilder.so

$(exe): main.o $(lib)
	$(CC) main.o -o $(exe) -Wl,-rpath=/usr/lib -L/usr/lib -lroadBuilder

$(lib): $(deps)
	$(CC) -shared $^ -o $(lib)
	sudo mv $(lib) /usr/lib

%.o: %.cpp %.h
	$(CC) $(flags) -fPIC -o $@ $< -c

main.o: main.cpp $(hs)
	$(CC) $(flags) -o $@ $< -c

run:
	make
	./$(exe)

clean:
	rm -f *.o *.so $(exe)

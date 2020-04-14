main: main.o Date.o Print.o Time.o
	g++ main.o Date.o Print.o Time.o -o main

main.o: main.cpp
	g++ -c main.cpp

Date.o: lib/Date.cpp
	g++ -c lib/Date.cpp

Print.o: lib/Print.cpp
	g++ -c lib/Print.cpp

Time.o: lib/Time.cpp
	g++ -c lib/Time.cpp

clean:
	rm *.o main
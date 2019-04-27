age.o:age.h
	g++ -c age.cpp
child.o:child.h
	g++ -c child.cpp
interface.o:interface.h
	g++ -c interface.cpp
rank.o:rank.h
	g++ -c rank.cpp
score.o:score.h
	g++ -c score.cpp
main.o:main.cpp interface.h age.h child.h rank.h score.h
	g++ -c main.cpp
execute:interface.o child.o age.o rank.o score.o main.o
	g++ main.o interface.o child.o age.o rank.o score.o -o execute


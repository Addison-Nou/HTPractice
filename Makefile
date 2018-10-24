proj2: Hashtable.o ChainedHash.o LinearHash.o DoubleHash.o
	g++ Hashtable.o ChainedHash.o LinearHash.o DoubleHash.o -o Hashtable

Hashtable.o: Hashtable.cpp
	g++ -c Hashtable.cpp

ChainedHash.o: ChainedHash.cpp ChainedHash.h
	g++ -c ChainedHash.cpp
	
LinearHash.o: LinearHash.cpp LinearHash.h
	g++ -c LinearHash.cpp

DoubleHash.o: DoubleHash.cpp DoubleHash.h
	g++ -c DoubleHash.cpp

clean: rm *.o proj2

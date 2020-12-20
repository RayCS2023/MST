all: mstdriver

mstdriver: DisjointSet.cpp DisjointSet.cpp MST.cpp MST.hpp msttest.cpp
		g++ -std=c++11 -o mstdriver msttest.cpp

run:    mstdriver
	./mstdriver < test1.in > out1.out
	./mstdriver < test2.in > out2.out
	./mstdriver < test3.in > out3.out
	./mstdriver < test4.in > out4.out
	./mstdriver < test5.in > out5.out
	./mstdriver < test6.in > out6.out
	./mstdriver < test07.in > out07.out
	./mstdriver < test08.in > out08.out
	./mstdriver < test09.in > out09.out
	./mstdriver < test10.in > out10.out
	./mstdriver < test11.in > out11.out
	./mstdriver < test12.in > out12.out
	./mstdriver < mytest1.in > mytest1.out
	./mstdriver < mytest2.in > mytest2.out
	./mstdriver < mytest3.in > mytest3.out
	./mstdriver < mytest4.in > mytest4.out
	./mstdriver < mytest5.in > mytest5.out
	./mstdriver < mytest6.in > mytest6.out
	./mstdriver < mytest7.in > mytest7.out
	./mstdriver < mytest8.in > mytest8.out
	./mstdriver < mytest9.in > mytest9.out
	./mstdriver < mytest10.in > mytest10.out
	./mstdriver < mytest11.in > mytest11.out
	./mstdriver < FATTESTCASE.in > FATTESTCASE.out

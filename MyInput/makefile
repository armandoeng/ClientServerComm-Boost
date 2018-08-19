myinput:
	g++ -c myinput.cpp -o ./static/myinput.o
	ar crv ./static/libmyinput.a ./static/myinput.o
	g++ -c -fPIC myinput.cpp -o ./shared/myinput.o
	g++ -shared ./shared/myinput.o -o ./shared/libmyinput.dll
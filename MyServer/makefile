all: server

server: mainServer.o myserver.o myconnection.o
	cp ../MyInput/input.json ./static/
	cp ../MyInput/input.json ./shared/
	cp ../MyInput/shared/libmyinput.dll ./shared/
	g++ -o ./static/server ./obj/mainServer.o ./obj/myserver.o ./obj/myconnection.o -lboost_system -L../MyInput/static -lmyinput
	g++ -o ./shared/server ./obj/mainServer.o ./obj/myserver.o ./obj/myconnection.o -lboost_system -L../MyInput/static -lmyinput
	
myserver.o: myserver.cpp
	g++ -c myserver.cpp -o ./obj/myserver.o -I../MyInput
	
myconnection.o: myconnection.cpp
	g++ -c myconnection.cpp -o ./obj/myconnection.o
	
mainServer.o: mainServer.cpp
	g++ -c mainServer.cpp -o ./obj/mainServer.o
	
clean:
	rm -f ./obj/*.*
	rm -f ./shared/*.*
	rm -f ./static/*.*
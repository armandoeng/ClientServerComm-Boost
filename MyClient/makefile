all:client

client: mainClient.o myclient.o
	cp ../MyInput/input.json ./static/
	cp ../MyInput/input.json ./shared/
	cp ../MyInput/shared/libmyinput.dll ./shared/
	g++ -o ./static/client ./obj/mainClient.o ./obj/myclient.o -L../MyInput/static -lmyinput -lboost_system
	g++ -o ./shared/client ./obj/mainClient.o ./obj/myclient.o -L../MyInput/shared -lmyinput -lboost_system
	
myclient.o: myclient.cpp
	g++ -c myclient.cpp -o ./obj/myclient.o -I../MyInput
	
mainClient.o: mainClient.cpp
	g++ -c mainClient.cpp -o ./obj/mainClient.o
	
clean:
	rm -f ./obj/*.*
	rm -f ./shared/*.*
	rm -f ./static/*.*
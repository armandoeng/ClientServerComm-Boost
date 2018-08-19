all: clean	
	$(MAKE) -C MyInput
	$(MAKE) -C MyClient	
	$(MAKE) -C MyServer

clean:
	$(MAKE) clean -C MyInput
	$(MAKE) clean -C MyClient	
	$(MAKE) clean -C MyServer
	
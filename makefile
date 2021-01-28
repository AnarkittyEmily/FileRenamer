CC=g++
 

install:
	@echo "Installing"
	@g++ FileRenamer.cpp -o rename -std=c++20 -lstdc++
	@echo "Compiling file.."
	@mv ./rename /usr/bin/rename
	@echo "Moving file to /usr/bin.."
	@echo "Installed!"

uninstall:
	@echo "Uninstalling.."
	@rm /usr/bin/rename
	@echo "Uninstalled"
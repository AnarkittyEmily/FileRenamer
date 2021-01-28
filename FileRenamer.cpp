#include <iostream>
#include <filesystem>

using std::string; 
namespace fs = std::filesystem; 

void displayHelp() {
    std::cout <<
        "Renames a file, directory, (directories that are not present within your HOME directory need sudo privileges) \n" 
        "Takes two arguments, the name of the file and the new file \n"
        "NOTE: using ~ DOES NOT WORK, you must specify your home environment (for example, /home/emily)."
    << std::endl;

}


int renameFile(string fileName, string newName) {
    if (!fs::exists(fileName)) {
        std::cout << "Could not find file\n";
        return 1; 
    } 

    fs::rename(fileName, newName); 
    if (!fs::exists(fileName) and fs::exists(newName)) {
        std::cout << "Rename successful!\n"; 
        return 0; 
    }

    return 0; 
}

int main(int argc, char* argv[]) {
    if (argc > 2) {
        string fileName(argv[1]); 
        string newFile(argv[2]);
        renameFile(fileName, newFile);  
    } else if (argc > 1 ) {
        string help(argv[1]);    
        if (help == "--help") {
            displayHelp();
        }
    } else {
        std::cout << "Not enough arguments, type renameFile --help for a list of options\n";
    }
}
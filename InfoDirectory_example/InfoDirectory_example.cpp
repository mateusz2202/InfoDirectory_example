#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <filesystem>
#include <vector>
#include <thread>
#include <mutex>
#include <future>
#include "InfoDirectory_example.h"

namespace fs = std::filesystem;

int main()
{
    //Create test directory
    const fs::path exampleDirectory{ "exampleDirectory" };
    fs::create_directories(exampleDirectory / "dir1" / "dir2" / "dir3");
    //Create test files
    auto file = std::ofstream{ exampleDirectory / "file1.txt" };
    file << "hello\n\nworld\n!\nHi!";
    file.close();
    std::ofstream{ exampleDirectory / "dir1" / "file1.txt" };
    std::ofstream{ exampleDirectory / "dir1" / "file2.txt" };
    file = std::ofstream{ exampleDirectory / "dir1" / "dir2" / "file1.txt" };
    file << "hello\n\n\nworld\n\n!\nHi!";
    file.close();
    std::ofstream{ exampleDirectory / "dir1" / "dir2" / "file2.txt" };
    std::ofstream{ exampleDirectory / "dir1" / "dir2" / "file3.txt" };
   
    //Info about directory
    std::cout << "-----------------------------------------\n";
    std::cout << "Informacje ogolne\n";
    std::cout << "-----------------------------------------\n";
    get_info_directory(exampleDirectory);   
    std::cout << "-----------------------------------------\n";
    //Info about not empty file
    std::cout << "Informacje o niepustych plikach\n";
    std::cout << "-----------------------------------------\n";
    write_not_empty_file(exampleDirectory);
    std::cout << "-----------------------------------------\n";
    //Info about paths visited
    std::cout << "Odwiedzone sciezki\n";
    std::cout << "-----------------------------------------\n";
    write_directory(exampleDirectory);
    std::cout << "-----------------------------------------\n";
    //tree directory
    std::cout << "Struktura katalogu\n";
    std::cout << "-----------------------------------------\n";
    std::system("tree /F exampleDirectory");

    // delete the exampleDirectory dir and all contents within it, including subdirs
    fs::remove_all(exampleDirectory);
  

}



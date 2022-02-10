#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <filesystem>
#include <future>
namespace fs = std::filesystem;

std::size_t count_element_in_directory(fs::path path, bool(*func)(fs::file_status)) {
    size_t n = 0;
    for (auto it = fs::recursive_directory_iterator(path); it != fs::recursive_directory_iterator(); ++it)
        if (func(it->symlink_status())) n++;
    return n;
}
std::size_t count_empty_element_in_directory(fs::path path, bool(*func)(fs::file_status)) {
    size_t n = 0;
    for (auto const& dir_entry : fs::recursive_directory_iterator{ path })
        if (fs::is_empty(dir_entry) && func(dir_entry.status()))n++;
    return n;
}
void write_directory(fs::path path) {
    for (auto const& dir_entry : fs::recursive_directory_iterator{ path })
        std::cout << dir_entry << "\n";
}
void write_info_file(fs::path path) {
    std::ifstream myfile(path);
    unsigned count_line = 0;
    unsigned count_line_empty = 0;
    std::string line;
    while (std::getline(myfile, line)) {
        if (line == "")
            count_line_empty++;
        count_line++;
    }
    std::cout << "plik zawiera: " << count_line << " linijek\n";
    std::cout << "w tym: " << count_line_empty << " pustych linijek\n";
}
void write_not_empty_file(fs::path path) {
    for (auto const& dir_entry : fs::recursive_directory_iterator{ path })
        if (!fs::is_empty(dir_entry) && fs::is_regular_file(dir_entry.status()))
        {
            std::cout << dir_entry << "\n";
            write_info_file(dir_entry);
        }
}
int foo(int a) {
    return a * a;
}
void get_info_directory(fs::path path) {
    auto a = std::async([&] { return count_element_in_directory(path, &fs::is_regular_file);  });
    auto b = std::async([&] { return count_element_in_directory(path, &fs::is_directory);  });
    auto c = std::async([&] { return count_empty_element_in_directory(path, &fs::is_regular_file);  });
    auto d = std::async([&] { return count_empty_element_in_directory(path, &fs::is_directory);  });
    std::cout << "Ilosc plikow: " << a.get() << std::endl;
    std::cout << "Ilosc katalogow: " << b.get()<< std::endl;
    std::cout << "Ilosc pustych plikow: " << c.get()<< std::endl;
    std::cout << "Ilosc pustych katalogow: " << d.get() << std::endl;  
}

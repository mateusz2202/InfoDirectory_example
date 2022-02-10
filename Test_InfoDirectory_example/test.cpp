#include "pch.h"
#include "../InfoDirectory_example/InfoDirectory_example.h"


TEST(Test1_count_element_in_directory, positiveNumberOfFiles) {
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
	EXPECT_EQ(6, count_element_in_directory(exampleDirectory, &fs::is_regular_file));
    fs::remove_all(exampleDirectory);
}
TEST(Test2_count_element_in_directory, positiveNumberOfFiles) {
    //Create test directory
    const fs::path exampleDirectory{ "exampleDirectory" };
    fs::create_directories(exampleDirectory / "dir1" / "dir2" / "dir3");
    //Create test files
    auto file = std::ofstream{ exampleDirectory / "file1.txt" };
    file << "hello\n\nworld\n!\nHi!";
    file.close();
    std::ofstream{ exampleDirectory / "dir1" / "file1.txt" };
    std::ofstream{ exampleDirectory / "dir1" / "file2.txt" };  
    EXPECT_EQ(3, count_element_in_directory(exampleDirectory, &fs::is_regular_file));
    fs::remove_all(exampleDirectory);
}
TEST(Test3_count_element_in_directory, positiveNumberOfFiles) {
    //Create test directory
    const fs::path exampleDirectory{ "exampleDirectory" };
    fs::create_directories(exampleDirectory / "dir1" / "dir2" / "dir3");
     
    EXPECT_EQ(0, count_element_in_directory(exampleDirectory, &fs::is_regular_file));
    fs::remove_all(exampleDirectory);
}
TEST(Test4_count_element_in_directory, noPositiveNumberOfFiles) {
    //Create test directory
    const fs::path exampleDirectory{ "exampleDirectory" };
    fs::create_directories(exampleDirectory / "dir1" / "dir2" / "dir3");

    EXPECT_NE(-1, count_element_in_directory(exampleDirectory, &fs::is_regular_file));
    fs::remove_all(exampleDirectory);
}
TEST(Test5_count_element_in_directory, PositiveNumberOfDirectory) {
    //Create test directory
    const fs::path exampleDirectory{ "exampleDirectory" };
    fs::create_directories(exampleDirectory / "dir1" / "dir2" / "dir3");

    EXPECT_EQ(3, count_element_in_directory(exampleDirectory, &fs::is_directory));
    fs::remove_all(exampleDirectory);
}
TEST(Test6_count_element_in_directory, PositiveNumberOfDirectory) {
    //Create test directory
    const fs::path exampleDirectory{ "exampleDirectory" };
    fs::create_directories(exampleDirectory / "dir1" );

    EXPECT_EQ(1, count_element_in_directory(exampleDirectory, &fs::is_directory));
    fs::remove_all(exampleDirectory);
}
TEST(Test7_count_element_in_directory, PositiveNumberOfDirectory) {
    //Create test directory
    const fs::path exampleDirectory{ "exampleDirectory" };
    fs::create_directory(exampleDirectory);

    EXPECT_EQ(0, count_element_in_directory(exampleDirectory, &fs::is_directory));
    fs::remove_all(exampleDirectory);
}
TEST(Test8_count_element_in_directory, NoPositiveNumberOfDirectory) {
    //Create test directory
    const fs::path exampleDirectory{ "exampleDirectory" };
    fs::create_directory(exampleDirectory);

    EXPECT_NE(-10, count_element_in_directory(exampleDirectory, &fs::is_directory));
    fs::remove_all(exampleDirectory);
}
TEST(Test9_count_empty_element_in_directory, PositiveNumberOfDirectory) {
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

    EXPECT_EQ(4, count_empty_element_in_directory(exampleDirectory, &fs::is_regular_file));
    fs::remove_all(exampleDirectory);
}
TEST(Test10_count_empty_element_in_directory, NoPositiveNumberOfDirectory) {
    //Create test directory
    const fs::path exampleDirectory{ "exampleDirectory" };
    fs::create_directories(exampleDirectory / "dir1" / "dir2" / "dir3");
    //Create test files
    auto file = std::ofstream{ exampleDirectory / "file1.txt" };
    file << "hello\n\nworld\n!\nHi!";
    file.close();
    std::ofstream{ exampleDirectory / "dir1" / "file1.txt" };
    std::ofstream{ exampleDirectory / "dir1" / "file2.txt" };
  

    EXPECT_NE(3, count_empty_element_in_directory(exampleDirectory, &fs::is_regular_file));
    fs::remove_all(exampleDirectory);
}
TEST(Test11_count_empty_element_in_directory, PositiveNumberOfFiles) {
    //Create test directory
    const fs::path exampleDirectory{ "exampleDirectory" };
    fs::create_directories(exampleDirectory / "dir1" / "dir2" / "dir3");
    //Create test files
    auto file = std::ofstream{ exampleDirectory / "file1.txt" };
    file << "hello\n\nworld\n!\nHi!";
    file.close();
    std::ofstream{ exampleDirectory / "dir1" / "file1.txt" };
    std::ofstream{ exampleDirectory / "dir1" / "file2.txt" };
  

    EXPECT_EQ(1, count_empty_element_in_directory(exampleDirectory, &fs::is_directory));
    fs::remove_all(exampleDirectory);
}
TEST(Test12_count_empty_element_in_directory, NoPositiveNumberOfFiles) {
    //Create test directory
    const fs::path exampleDirectory{ "exampleDirectory" };
    fs::create_directories(exampleDirectory / "dir1" / "dir2" / "dir3"/"dir4");
    //Create test files
    auto file = std::ofstream{ exampleDirectory / "file1.txt" };
    file << "hello\n\nworld\n!\nHi!";
    file.close();
    std::ofstream{ exampleDirectory / "dir1" / "file1.txt" };
    std::ofstream{ exampleDirectory / "dir1" / "file2.txt" };


    EXPECT_NE(2, count_empty_element_in_directory(exampleDirectory, &fs::is_directory));
    fs::remove_all(exampleDirectory);
}
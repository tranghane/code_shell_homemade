//THIS IS CODESHELL HOMEMADE

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  // Uncomment this block to pass the first stage
while (true) {
  std::cout << "$ ";
  std::string input;
  std::getline(std::cin, input);
  if (input == "exit 0") {
    break;
  }
  std::cout << input << ": command not found\n";
}
}
//go to src, run this to run the program
// g++ main.cpp -o my_program

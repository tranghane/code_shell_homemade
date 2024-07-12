// THIS IS CODESHELL HOMEMADE

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  // Uncomment this block to pass the first stage
  while (true)
  {
    std::cout << "$ ";
    std::string input;
    std::getline(std::cin, input);


    if (input.find("exit") == 0 && input[5] == '0' && input.length() == 6) //exit 0 builtin
    {
      break;
    }
    else if (input.find("echo") == 0) //echo builtin
    {
      // for (int i = 5; i < input.length(); i++)
      // {
      //   std::cout << input[i];
      // }
      const int ECHO_LEN = 5; // Including space
      std::string text = input.substr(ECHO_LEN);
      std::cout << text << std::endl;
    }
    else
    {
      std::cout << input << ": command not found\n";
    }
  }
}
// go to src, run this to run the program
//  g++ main.cpp -o my_program

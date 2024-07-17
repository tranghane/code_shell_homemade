// THIS IS CODESHELL HOMEMADE

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <map>
using namespace std;
int main()
{
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  // Uncomment this block to pass the first stage
  std::map<string, string> commandToType = {
    {"echo", "a shell builtin"},
    {"exit", "a shell builtin"},
    {"cat", "/bin/cat"},
    {"type", "a shell builtin"}
  };
  std::cout << "$ ";
  while (true)
  {
    
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
      std::cout << "$ ";
    }
    else if (input.find("type") == 0) { //type builtin
      const int TYPE_LEN = 5;
      std::string text = input.substr(TYPE_LEN);
      if (commandToType.find(text) == commandToType.end()) { //if can't find
        std::cout << text + ": not found" << std::endl;
        std::cout << "$ ";
      } else {
        std::cout << text + " is " + commandToType[text]<< std::endl;
        std::cout << "$ ";
      }
    }
    else
    {
      std::cout << input << ": command not found\n";
      std::cout << "$ ";
    }
  }
  return 0;
}
// go to src, run this to run the program
//  g++ main.cpp -o my_program

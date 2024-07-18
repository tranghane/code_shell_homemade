// THIS IS CODESHELL HOMEMADE

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <map>
#include <sstream>
#include <filesystem>
using namespace std;

// check path from name
std::string get_path(std::string fileName)
{
  // get the environment variable PATH
  std::string path_env = std::getenv("PATH");

  // convert it to a stringstream
  std::stringstream ss(path_env);

  // variable to store path and use for getline
  std::string path;

  // go over the stringstream, aka the environment variable PATH
  while (!ss.eof())
  {
    // for each path, create an abs_path
    getline(ss, path, ':');
    string abs_path = path + '/' + fileName;

    // use abs_path to check if the file exist
    if (filesystem::exists(abs_path))
    {
      return abs_path;
    }
  }
  // if find nothing return
  return "";
}
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
      {"type", "a shell builtin"}};
  std::cout << "$ ";
  while (true)
  {

    std::string input;
    std::getline(std::cin, input);

    if (input.find("exit") == 0 && input[5] == '0' && input.length() == 6) // exit 0 builtin
    {
      break;
    }
    else if (input.find("echo") == 0) // echo builtin
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
    else if (input.find("type") == 0)
    { // type builtin
      const int TYPE_LEN = 5;
      std::string text = input.substr(TYPE_LEN);

      if (commandToType.find(text) == commandToType.end())
      { // if can't find
        std::cout << text + ": not found" << std::endl;
        std::cout << "$ ";
      }
      else
      {
        std::string path = get_path(input);
        if (path.empty())
        {
          std::cout << input << " not found\n";
        }
        else
        {
          std::cout << input << " is " << path << std::endl;
        }
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

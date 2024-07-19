// THIS IS CODESHELL HOMEMADE

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <map>
#include <sstream>
#include <filesystem>
#include <cstdlib>
#include <fstream>
using namespace std;

// get the argument of the input
std::vector<std::string> split_string(const std::string &s, char delimiter)
{
  std::stringstream ss(s);
  std::vector<std::string> return_vect;
  std::string token;
  while (getline(ss, token, delimiter))
  {
    return_vect.push_back(token);
  }
  return return_vect;
}

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
      {"type", "a shell builtin"}};
  std::cout << "$ ";

  // to get the arguments of the command
  std::vector<std::string> arguments;
  while (true)
  {

    std::string input;
    std::getline(std::cin, input);

    // get the argument
    arguments = split_string(input, ' ');

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

      if (commandToType.find(text) != commandToType.end())
      { // if can find in dictionary     meaning one of the built in command
        std::cout << arguments[1] << " is a shell builtin" << std::endl;
        std::cout << "$ ";
      }
      else
      {                                            // if can't find
        std::string path = get_path(arguments[1]); // Use arguments[1] here
        if (path.empty())
        {                                              // if empty, meaning no such file
          std::cout << arguments[1] << " not found\n"; // Use arguments[1] here
          std::cout << "$ ";
        }
        else
        { // one of the built in command
          std::cout << input << " is " << path << std::endl;
          std::cout << "$ ";
        }
      }
    }

    else
    {
      std::cout << input << ": command not found\n";
      std::string filepath;

      // trying to run a program
      std::string path_string = getenv("PATH");
      std::vector<std::string> path = split_string(path_string, ':');
      for (int i = 0; i < path.size(); i++)
      {
        filepath = path[i] + '/' + arguments[0];
        std::ifstream file(filepath);
        if (file.good())
        {
          // run the program using system
          std::string command = "exec " + path[i] + '/' + input;
          std::system(command.c_str());
          break;
        }
        else if (i == path.size() - 1)
        {
          std::cout << arguments[0] << ": not found\n";
        }
      }
      std::cout << "$ ";
    }
  }
  return 0;
}
// go to src, run this to run the program
//  g++ main.cpp -o my_program

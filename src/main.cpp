#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <filesystem>
std::vector<std::string> splitString(std::string string, char delimiter)
{
  std::stringstream ss(string);
  std::vector<std::string> return_vector;
  std::string token;
  while (getline(ss, token, delimiter))
  {
    return_vector.push_back(token);
  }
  return return_vector;
}

std::string cwd = std::filesystem::current_path();
std::string WORKING_DIR = cwd.substr(0, cwd.length());
// static std::string WORKING_DIR = "/app";
void handlePwd()
{
  std::cout << WORKING_DIR << '\n';
}

void handleCd(const std::string &argument)
{
  if (argument[0] == '/' && std::filesystem::exists(argument))
    WORKING_DIR = argument;
  else if (argument[0] == '.')
  {
    if (argument == "./")
    { // ./ mean do nothin
    }
    else if (argument == "../")
    { // move back
      // Move back one level, but prevent going beyond root
      size_t last_slash = WORKING_DIR.find_last_of('/');
      if (last_slash != std::string::npos && last_slash > 0)
        WORKING_DIR = WORKING_DIR.substr(0, last_slash);
      else
        std::cout << "Cannot move beyond root directory\n";
    }
    else
    { // cd ./somefolder
      std::string relative_path = argument.substr(2);
      std::string new_path = WORKING_DIR + "/" + relative_path;

      if (std::filesystem::is_directory(new_path))
      {
        WORKING_DIR = new_path;
      }
      else
      {
        std::cout << relative_path << ": Not a valid folder\n";
      }
    }
  }
  else
  {
    // Check if it's an existing folder
    std::string folder_path = WORKING_DIR + "/" + argument;
    if (std::filesystem::is_directory(folder_path))
      WORKING_DIR = folder_path;
    else
      std::cout << argument << ": Not a valid folder\n";
  }
}

void handleTypeCommand(std::string command, std::string arguments, std::vector<std::string> path_vect)
{
  if (arguments == "exit" || arguments == "echo" || arguments == "type" || arguments == "pwd")
  {
    std::cout << arguments << " is a shell builtin\n";
  }
  else
  {
    std::string filepath;
    for (int i = 0; i < path_vect.size(); i++)
    {
      filepath = path_vect[i] + '/' + arguments;
      std::ifstream file(filepath);
      if (file.good())
      {
        std::cout << arguments << " is " << filepath << "\n";
        return;
      }
    }
    std::cout << arguments << ": not found\n";
  }
}
int main()
{
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;
  std::string path_string = std::getenv("PATH");
  std::vector<std::string> path_vector = splitString(path_string, ':');
  // Uncomment this block to pass the first stage
  while (true)
  {
    std::cout << "$ ";

    std::string input;
    std::getline(std::cin, input);
    if (input == "exit 0")
    {
      return 0;
    }
    std::string command = input.substr(0, input.find(" "));
    std::string arguments = input.substr(input.find(" ") + 1);
    if (command == "echo")
    {
      std::cout << arguments << "\n";
    }
    else if (command == "type")
    {
      handleTypeCommand(command, arguments, path_vector);
    }
    else if (command == "pwd")
    {
      handlePwd();
    }
    else if (command == "cd")
    {
      handleCd(arguments);
    }
    else
    {
      std::string filepath;
      for (int i = 0; i < path_vector.size(); i++)
      {
        filepath = path_vector[i] + '/' + command;
        std::ifstream file(filepath);
        if (file.good())
        {
          std::string exec_command = "exec " + path_vector[i] + "/" + input;
          std::system(exec_command.c_str());
          break;
        }
        else if (i == path_vector.size() - 1)
        {
          std::cout << command << ": not found\n";
        }
      }
    }
  }
}
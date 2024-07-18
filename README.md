[![progress-banner](https://backend.codecrafters.io/progress/shell/1a304fe4-98bf-4ea5-88aa-b93901fb7898)](https://app.codecrafters.io/users/codecrafters-bot?r=2qF)

This is a starting point for C++ solutions to the
["Build Your Own Shell" Challenge](https://app.codecrafters.io/courses/shell/overview).

In this challenge, you'll build your own POSIX compliant shell that's capable of
interpreting shell commands, running external programs and builtin commands like
cd, pwd, echo and more. Along the way, you'll learn about shell command parsing,
REPLs, builtin commands, and more.

**Note**: If you're viewing this repo on GitHub, head over to
[codecrafters.io](https://codecrafters.io) to try the challenge.

# Passing the first stage

The entry point for your `shell` implementation is in `src/main.cpp`. Study and
uncomment the relevant code, and push your changes to pass the first stage:

```sh
git add .
git commit -m "pass 1st stage" # any msg
git push origin master
```

Time to move on to the next stage!

# Stage 2 & beyond

Note: This section is for stages 2 and beyond.

1. Ensure you have `cmake` installed locally
1. Run `./your_shell.sh` to run your program, which is implemented in
   `src/main.cpp`.
1. Commit your changes and run `git push origin master` to submit your solution
   to CodeCrafters. Test output will be streamed to your terminal.


# This is a homemade Linux codeshell
## Completed task:
- Handle missing command
- REPL (Read-Eval-Print Loop)
- Exit builtin
- Echo builtin
- Type builtin
## How to run program:
- make sure to fix the path of your vcpkg in `your_shell.sh`
- Run `./your_shell.sh` to run your program, which is implemented in
   `src/main.cpp`.
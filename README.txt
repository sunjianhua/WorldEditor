A new and better editor for Warcraft 3.

How to build (for gcc):
  Debug: g++ *.cpp -o "World Editor - Debug.exe" -g -std=c++11 -D__DEBUG__ -Wall -Wextra -pedantic
  Release: g++ *.cpp -o "World Editor.exe" -O2 -s -std=c++11 -Wall -Wextra -pedantic

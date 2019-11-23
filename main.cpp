#include <iostream>
#include <fstream>
#include <stdlib.h> // for exit
// #include <stdio.h>  // printf, scanf, puts, NULL
// #include <stdlib.h> // srand, rand
// #include <ctime>
using namespace std;

#define time 100
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void delay(int d);
void My_Print(char letter);
void setRandomColor();

int main() {
  // srand(time(NULL)); // initialize random seed

  ifstream inFile;
  inFile.open("message.txt");
  string line;

  if(inFile.fail())
  {
    cout << "File failed to open. Program terminated." << endl;
    exit(1);
  }

  

  while(!inFile.eof())
  {
    getline(inFile, line);
    for(int i=0; i<line.length(); i++)
    {
      setRandomColor();
      My_Print(line.at(i)); 
    }
    cout << endl;
  }

} // end of main
void delay(int d)
{
 int i;
 float a;
 for (i=0;i<(d*10000);i++) a=(float)(i/0.1f);
}
void My_Print(char letter)
{
 cout << letter;
 delay(time);
 cout.flush();
}
void setRandomColor()
{
  int x = rand() % 6 + 1;

  switch(x)
  {
    case 1:
    cout << ANSI_COLOR_RED;
    break;
    case 2:
    cout << ANSI_COLOR_BLUE;
    break;
    case 3:
    cout << ANSI_COLOR_CYAN;
    break;
    case 4:
    cout << ANSI_COLOR_GREEN;
    break;
    case 5:
    cout << ANSI_COLOR_YELLOW;
    break;
    case 6:
    cout << ANSI_COLOR_MAGENTA;
    break;
  }

}
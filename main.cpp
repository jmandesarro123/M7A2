#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

/*This is a program about my Tech Shop. It shows how to read and write to files.
Name: Johnathan DeSarro
Date: November 22, 2020
Class: COP2000*/


//Define Global Constant
const int MAX = 10; //Eventually need to reset to 10

//Function Prototyping
bool readInventory(string itemNames[], double itemCost[], int itemNoShip[MAX][2]);
void displayInventory(string itemNames[], double itemCost[], int itemNoShip[MAX][2]);
void writeFile(string itemNames[], double itemCost[], int itemNoShip[MAX][2]);
void logo();
void menu();

//Don't forget to add comments! You need to look back at the PDF file.
int main() 
{
  
  //Define Variables:
  int MenuChoice = 0;
  string itemNames[MAX];
  double itemCost[MAX];
  int itemNoShip[MAX][2];

do
{
 logo(); 
 menu();
 cin >> MenuChoice;
 if (MenuChoice)
 {
  if (MenuChoice == 1)
  {
    readInventory(itemNames, itemCost, itemNoShip);
  }  
  else if (MenuChoice == 2)
  {
    displayInventory(itemNames, itemCost, itemNoShip);
  }
  else if (MenuChoice == 3)
  {
    writeFile(itemNames, itemCost, itemNoShip);
  }
  else if (MenuChoice == 4)
  {
    cout << "Thank you! Have a great day!\n";
    return 0;
  }
  else
  {
   cout << "Please enter a valid menu option. "; 
  }
}
}
while (MenuChoice);
}


//Function Definitions
bool readInventory(string itemNames[], double itemCost[], int itemNoShip[MAX][2])
{
  bool readFile = false;
  
  ifstream inputFile;
  inputFile.open("inputInventory.txt");
  if (inputFile)
{
  
  //Message
  cout << "Reading file data...\n";
   for (int row = 0; row < MAX; row++)
  {
    getline (inputFile, itemNames[row], '-');
    cout << itemNames[row] << '\t';
    inputFile >> itemCost[row];
    cout << itemCost[row] << '\t';
    inputFile >> itemNoShip[row][0];
    cout << itemNoShip[row][0] << '\t';
    inputFile >> itemNoShip[row][1];
    cout << itemNoShip[row][1];
    cout << endl;
  }

  readFile = true;
  inputFile.close();
}
else
  {
    cout << "Error reading file...";
    return 0;
  }
  return readFile;  
}  
//This needs fixing. Figure out how to make program end when file can't be read.
void displayInventory(string itemNames[], double itemCost[], int itemNoShip[MAX][2])
{
   cout << "Item Description          Cost Per Item   No. of Items    Shipping(1-Yes, 0-No)\n";
    for (int row = 0; row < MAX; row++)
  {
    cout << itemNames[row] << '\t';
    cout << itemCost[row] << '\t';
    cout << itemNoShip[row][0] << '\t';
    cout << itemNoShip[row][1] << endl;
  }
}

void writeFile(string itemNames[], double itemCost[], int itemNoShip[MAX][2])
{
  ofstream outFile;
  outFile.open("outputInventory.txt");
  cout << "Printing to file...\n";
  for (int row = 0; row < MAX; row++)
  {
    outFile << itemNames[row] << '\t';
    outFile << itemCost[row] << '\t';
    outFile << itemNoShip[row][0] << '\t';
    outFile << itemNoShip[row][1] << endl;
  }
}

void menu()
{
cout << "1. Read in Inventory \n";
cout << "2. Display Inventory \n";
cout << "3. Write to File \n";
cout << "4. Exit\n";
cout << "Please make a selection: > ";
}
void logo()
{
  cout << "\nJohnathan DeSarro's Tech Shop\n"
  "*****************************\n\n"
  "       ********\n"
  "        ********\n"
  "         ********\n"
  "          ********\n"
  "           ********\n"
  "          ********\n"
  "         ********\n"
  "        ********\n"
  "       ********\n"
  "\n"
  "*****************************\n\n\n";
}





 //Program Psuedocode:
  //a) Declare variables and arrays (see above) [not done]
  //b) Start do/while loop [done]
    //i) call logo function
    //[done]
    //ii) call menu function
    //[done]
    //iii) read in menu input
    //[done]
    //iv) switch/if on men input [done]
      //(1) if menu input is 1 
        //(a) call readInventory function and capture 
        //returned value 
        //(b) if returned value (file was not read) 
        //output error message and exit program 
      //(2) if menu input is 2 
        //(a) call displayInventory function 
      //(3) if menu input is 3 
        //(a) call writeFile function 
      //(4) if menu input is 4 
        //(a) output message exiting program 
      //(5) if menu input is not 1-4 output error 
      //message 
  //c) End do/while loop [done]
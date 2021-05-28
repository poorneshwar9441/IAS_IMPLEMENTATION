#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;
typedef long long int ll;
ll Ram[1000][4]; // 0 - 499 locations are reservered for instructions
ll Ram2[1000];   // 500 - 999 locations are reserved for the data

void Read_file()
{ 
//---LOAD the RAM_data (variables) here ----//
  Ram2[700] = 0;
  Ram2[701] = 1;
  Ram2[801] = 20; // nth fibonanci number
  Ram2[802] = 1;  // counter
  Ram2[803] = 1;  // incrementer

  Ram2[750] = 504;
  Ram2[751] = 26;
  Ram2[752] = 0;
  Ram2[753] = 1;

  Ram2[600] = 1;
  Ram2[501] = 4;
  Ram2[502] = 1; // multiplier 
  Ram2[503] = 1;

//------------------------------------------//
  string s = "output.out"; // only-for-instructions
  int number = 0;

  ifstream file(s);
  
  int count1 = 0;
  int count2 = 0;

  while(file >> number)
  {
  	 if(count2 < 4)
  	 {
  	 	Ram[count1][count2] = number;
  	 	count2++;
  	 }
  	 else
  	 {  
  	 	count2 = 0;
  	 	count1++;
  	 	Ram[count1][count2] = number;
  	 	count2++;
  	 }
  	 
  }
  file.close();
}
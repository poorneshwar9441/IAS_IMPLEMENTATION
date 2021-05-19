#include<iostream>
typedef long long int ll;

ll Ram[1000][4]; // memory locations 0-499 reserved for instructions
ll Ram2[1000];   // memory locations 500-999 reserved for data

// ------ we can load our custum program here ----//
void load_program() // loads the program to Ram
{

  //program to find factorial of number at memory location 501
  Ram[0][0] = 9;
  Ram[0][1] = 502;
  Ram[0][2] = 11;
  Ram[0][3] = 600;

  Ram[1][0] = 33;
  Ram[1][1] = 600;
  Ram[1][2] = 1;
  Ram[1][3] = 502;

  Ram[2][0] = 5;
  Ram[2][1] = 503;
  Ram[2][2] = 33;
  Ram[2][3] = 502;

  Ram[3][0] = 1;
  Ram[3][1] = 501;
  Ram[3][2] = 6;
  Ram[3][3] = 503;

  Ram[4][0] = 33;
  Ram[4][1] = 501;
  Ram[4][2] = 1;
  Ram[4][3] = 501;

  Ram[5][0] = 15;
  Ram[5][1] = 0;

  Ram2[600] = 1;
  Ram2[501] = 10; // number to find factorial
  Ram2[502] = 1;
  Ram2[503] = 1;

//--------------// -> program to find fibonancii numbers in the series
  Ram[5][2] = 1;
  Ram[5][3] = 700; // LOAD 700

  Ram[6][0] = 5;     // ADD 701
  Ram[6][1] = 701;   // STOR 800 z = x+y
  Ram[6][2] = 33;     
  Ram[6][3] = 800;

  Ram[7][0] = 1;   // LOAD 701 
  Ram[7][1] = 701;               // x = y
  Ram[7][2] = 33;  // STOR 700
  Ram[7][3] = 700;

  Ram[8][0] = 1;   // LOAD 800
  Ram[8][1] = 800;               //y = z
  Ram[8][2] = 33;  // STOR 701
  Ram[8][3] = 701;

  Ram[9][0] = 1;   // LOAD 802  // 1
  Ram[9][1] = 802;
  Ram[9][2] = 5;   // ADD 803   //2;
  Ram[9][3] = 803;   

  Ram[10][0] = 33;  // STOR 802  // 2;
  Ram[10][1] = 802;
  Ram[10][2] = 1;   // LOAD 801  // 20 = acc
  Ram[10][3] = 801;

  Ram[11][0] = 6;   // SUB 802  // 20 - ac
  Ram[11][1] = 802;
  Ram[11][2] = 16; // JUMP if >=0
  Ram[11][3] = 5;


  Ram2[700] = 1;
  Ram2[701] = 1;
  Ram2[801] = 20; // nth fibonanci number
  Ram2[802] = 1; // counter
  Ram2[803] = 1; // incrementer

}
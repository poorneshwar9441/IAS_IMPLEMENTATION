#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;

typedef long long int ll;


ll Ram[1000][4]; // Ram locations 0-499 reserved for Instrutions
ll Ram2[1000];   // Ram locations 500-999 reserverd for data



/**
 
[[op,data, op, data];
 

**/

class Cpu
{

  /**
   * cpu registers
   * 
   * 
   * 
   */
public:
  ll IBR[2];

  ll IR;
  ll PC;
  ll MAR;
  ll AC; 
  ll MQ;
  ll MBR;



  void initiliaze()
  {
     this->IBR[0] = 0;
     this->IBR[1] = 0;
     this->IR = 0;
     this->PC = 0;
     this->AC = 0;
     this->MQ = 0;
     this->MBR = 0;
     this->MAR = 0;


  }
  void decode()
  { 

     this->IR = ::Ram[(this->PC)][0];//left opcode
     this->MBR = ::Ram[this->PC][1];//left d ata  
     this->IBR[0] = ::Ram[this->PC][2];// Rightopcode
     this->IBR[1] = ::Ram[this->PC][3];//Right data;
     execute(); // left instuction;
     IR = IBR[0];
     MBR = IBR[1];
     execute();//Right instruction;
     this->PC += 1;
     
  }
  void execute()
  { 

     switch(IR)
     {

    // Data Transfer Instructions
         case(10):
             this->AC = this->MQ;
             break;
         case(9):
              this->MQ = Ram2[this->MBR];
              break;

         case(33):
              Ram2[this->MBR] = this->AC;
              break;

         case(1):
              this->AC = Ram2[this->MBR];
              break;

         case(2):
              this->AC = Ram2[this->MBR]*-1;
              break;

         case(3):
             this->AC = abs(Ram2[this->MBR]);
             break;

         case(4):
             this->AC = -1*abs(Ram2[this->MBR]);
             break;

      // Arthematic Instructions
         case(5):
            this->AC = this->AC+Ram2[this->MBR];
            break;

         case(7):
            this->AC = this->AC+abs(Ram2[this->MBR]);
            break;

         case(6):
            this->AC = this->AC-(Ram2[this->MBR]);
            break;

         case(8):
            this->AC = this->AC - abs(Ram2[this->MBR]);
            break;

         case(11):
            this->AC = this->MQ * Ram2[this->MBR];
            break;

         case(12):
            this->AC = (this->AC)%(Ram2[this->MBR]);
            this->MQ = this->AC / Ram2[this->MBR];
            break;

         case(20):
            this->AC = this->AC *2;
            break;

         case(21):
            (this->AC) = (this->AC)/2;
            break;

     }

  }

};

int main(int argv,char const *s[])
{ 
  
// program 
  Ram[0][0] = 9;
  Ram[0][1] = 501;
  Ram[0][2] = 10;
  Ram[0][3] = 0;

  Ram[1][0] = 33;
  Ram[1][1] = 501;
  Ram[1][2] = 5;
  Ram[1][3] = 501;

  Ram2[501] = -20;
// end

  Cpu c;
  while(c.PC < 500)
  {
    c.decode();
  }

  cout << c.AC << endl;
  cout << c.MQ << endl;

}
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include "Program_loader.h"

using namespace std;

typedef long long int ll;

/**
 
[[op,data, op, data]] structure of instruction [op data]
 

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
  int current_instuction; // 0 for left and 1 for Right
  int skip_right;
  int skip_left;
  ll PREV_IR;

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
     this->current_instuction = 0;
     this->skip_right = 0;
     this->skip_right = 0;
     this->PREV_IR = 0;


  }
  void decode()
  { 

     this->IR = ::Ram[(this->PC)][0];//left opcode
     this->MBR = ::Ram[this->PC][1];//left d ata  
     this->IBR[0] = ::Ram[this->PC][2];// Rightopcode
     this->IBR[1] = ::Ram[this->PC][3];//Right data;

     ll current_PC = this->PC;

    if((this->PREV_IR != 14) && ((this->PREV_IR != 16) || (this->AC <=0)))
    { 
      execute(); 
    }
    if(this->PC == current_PC)
    { 
          
     this->IR = IBR[0];
     this->MBR = IBR[1];
     execute();     //Right instruction;
     if((this->IR != 13) && (this->IR != 14) && ((this->IR != 15) || (this->AC<=0)) && ((this->IR != 16) || (this->AC <= 0)))
     {
       this->PC += 1;
     }
    }
    this->PREV_IR = this->IR;
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

        // Unconditional_Branch
         case(13): 
            (this->PC) = this->MBR;
             break;

         case(14):
             (this->PC) = this->MBR;
              break;

        // conditional_Branch
          case(15):
              if(this->AC > 0)
              {
                 this->PC = this->MBR;
              }
              break;

          case(16):
              if(this->AC > 0)
              {
                this->PC = this->MBR;
              }
              break;
     }
  }

};
int main(int argv,char const *s[])
{ 
  
  load_program();


  Cpu c;
  c.initiliaze(); // initilizes all the registers
  
  while(c.PC < 500)
  {
    cout << "PC:" <<c.PC  << " ";
    cout << "AC:" <<c.AC  << " ";
    cout << "MQ:" <<c.MQ << "  ";
    cout << "FIB : " << Ram2[700] << " ";
    cout << "FIB2: " << Ram2[701] << "  ";
    cout << "FIB3:  " << Ram2[800] << "  ";
    //cout << "Counter " << Ram2[802] << " ";
    cout << "Ram2: "<< Ram2[600] << "  " << endl;
    c.decode();
  }
  cout << "factorial:" << " " << Ram2[600] << endl;
  cout << "fibonanci:" << " " << Ram2[700] << endl;
}
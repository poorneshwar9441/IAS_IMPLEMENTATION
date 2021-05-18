#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;

typedef long long int ll;


ll Ram[1000][4]; // Ram locations 0-499 reserved for Instrutions
ll Ram2[1000];   // Ram locations 500-999 reserverd for data



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

    if((this->PREV_IR != 14) && (this->PREV_IR != 16))
    { 
      execute(); 
    }
    if(this->PC == current_PC)
    { 
          
     this->IR = IBR[0];
     this->MBR = IBR[1];
     execute();     //Right instruction;
     this->PC += 1;
    }
    this->PREV_IR = this->IR;
     
  }
  void execute()
  { 

     switch(IR)
     {

    // Data Transfer Instructions
         case(10):// LOAD MQ
             this->AC = this->MQ;
             break;
         case(9):// LOAD MQ.M(X)
              this->MQ = Ram2[this->MBR];
              break;

         case(33):// STOR M(X)
              Ram2[this->MBR] = this->AC;
              break;

         case(1):// LOAD M(X)
              this->AC = Ram2[this->MBR];
              break;

         case(2):// LOAD -M(X)
              this->AC = Ram2[this->MBR]*-1;
              break;

         case(3)://LOAD |M(X)|
             this->AC = abs(Ram2[this->MBR]);
             break;

         case(4)://LOAD -|M(X)|
             this->AC = -1*abs(Ram2[this->MBR]);
             break;

      // Arthematic Instructions
         case(5)://ADD M(X)
            this->AC = this->AC+Ram2[this->MBR];
            break;

         case(7)://ADD |M(X)|
            this->AC = this->AC+abs(Ram2[this->MBR]);
            break;

         case(6)://SUB M(X)
            this->AC = this->AC-(Ram2[this->MBR]);
            break;

         case(8)://SUB |M(X)
            this->AC = this->AC - abs(Ram2[this->MBR]);
            break;

         case(11):// MUL M(X)
            this->AC = this->MQ * Ram2[this->MBR];
            break;
 
         case(12)://DIV M(X)
            this->AC = (this->AC)%(Ram2[this->MBR]);
            this->MQ = this->AC / Ram2[this->MBR];
            break;

         case(20):// LSH
            this->AC = this->AC *2;
            break;

         case(21)://RSH
            (this->AC) = (this->AC)/2;
            break; 

        // Unconditional_Branch
         case(13): //JUMP M(X,0:19)
            (this->PC) = this->MBR;
             break;

         case(14)://JUMP M(X,20:39)
             (this->PC) = this->MBR;
              break;

        // conditional_Branch
          case(15):// JUMP + M(X,0:19) 
              if(this->AC > 0)
              {
                 this->PC = this->MBR;
              }
              break;

          case(16):// JUMP + M(X,20:39)
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
  
// program to calculate factorial of a given number
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
// end

  Cpu c;
  c.initiliaze();
  //cout << c.PC << endl;
  while(c.PC < 500)
  {
    cout << "PC:" <<c.PC  << " ";
    cout << "AC:" <<c.AC  << " ";
    cout << "MQ:" <<c.MQ << " ";
    cout << "Ram2: "<< Ram2[600] << "  " << endl;
    c.decode();

  //cout << "hello" << endl;

}
cout << Ram2[600] << endl;
}

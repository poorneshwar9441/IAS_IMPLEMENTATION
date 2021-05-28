#include<iostream>
#include<fstream>

using namespace std;

//***this program creates output.out file***//

void create_binary_code(string file1)
{

   ifstream file(file1);
   ofstream file2("output.out");
   int number = 0;
   string s;
   
   while(file >> s)
   {
    
      if(s == "LOAD")
      {
      	 file2 << 1 << endl;
      	 
      }
      else if(s == "STOR")
      {
      	 file2 << 33 << endl;
      	 
      }
      else if(s == "ADD")
      {
         file2 << 5 << endl;
        
      }
      else if(s == "SUB")
      {
         file2 << 6 << endl;
      }
      else if(s == "MUL")
      {
         file2 << 11 << endl;
      }
      else if(s == "DIV")
      {
         file2 << 12 << endl;
      } 
      else if(s == "LOADMQ_MEM") //m(x) contents to MQ
      {
          file2 << 9 << endl;
      }
      else if(s == "JUMPL")
      {
          file2 << 13 << endl;
      }
      else if(s == "JUMPR")
      {
          file2 << 14 << endl;
      }
      else if(s == "JUMPL+")
      {
          file2 << 15 << endl;
      }
      else if(s == "JUMPR+")
      {
          file2 << 16 << endl;
      }
      else if(s == "LOADMQ")//Mq contents to Ac
      {
         file2 << 10 << endl;
      }
      else
      {
      	 file2 << s << endl;
      }

   }
}
int main(int argv,char const *s[])
{
	create_binary_code(s[1]);
}
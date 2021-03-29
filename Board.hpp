

#include "Direction.hpp"

#include <map>
//#include <vector> 
#include <string>
using namespace std;


namespace ariel {
	// Defines a class
 
class Board{
 public:
      u_int Mxrow=0;
      u_int  Mxcol=0;
      u_int  Mincol=0;
      u_int  Minrow=0;
   
    map<unsigned int,map<unsigned int,char>> board;//genric
  
  public:
  Board(){
    
  }

~Board(){}//destructor 

void show();
void post(u_int rowH,u_int colV,Direction d,string const &advertisement  );
string read(u_int h,u_int  v,Direction,u_int  n);
void initBoard(u_int  rows, u_int columns);
void cleanBoard();



};
}



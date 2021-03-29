#include <iostream>
#include<ctype.h>
#include "Board.hpp"
#include <stdexcept>

//#include "doctest.h"



using namespace std;
namespace ariel {

   void Board::cleanBoard(){//clean the board
       for(u_int i=Minrow;i<Mxrow;i++){
      for(u_int  j=Mincol ;j<Mxcol;j++){
         this->board[i][j]='_';
   }
       }
   }
   
 
void Board::initBoard(u_int  rows,  u_int columns){// init the board with hold the exactly size(Mxsize)and min size(Minsize)
    Mxrow =max(Mxrow,rows);
    Minrow=min(Minrow,rows);
    Mxcol =max(Mxcol,columns);
    Mincol=min(Mincol,columns);
   
    
  
}
   


void Board::post(u_int rowH,u_int colV,Direction d,string const &advertisement ){//post a message on the board
   if(advertisement.empty()){//if we need to post nothing so we do nothing
      return ;
   }
   uint size=advertisement.size();
   switch (d){
      case Direction::Vertical:
   
      initBoard(rowH+size,colV);
  
      for(uint i=0;i<size;i++){
         this->board[rowH][colV]=advertisement[i];
         rowH++;
         
      }
      break;
      case Direction::Horizontal:
       
     
         initBoard(rowH,colV+size);
    
      for(uint  i=0;i<size;i++){
         this->board[rowH][colV]=advertisement[i];
        colV++;
        


   }
   break;
   }

}
string Board::read( u_int h,u_int v,Direction d,u_int   n){//read a message from the board
   string ans;
   try{
   switch(d){
      case Direction::Horizontal:
         
     for(uint i =v;i<v+n;i++){
        if (board[h].count(i) != 0 && board.count(h) != 0 ){//existing something to read in map if not add and read '_'
      ans+=this->board[h][i];
      //v++;
        }
        else{
           ans+='_';
        }

   }
    break;

   case Direction::Vertical:
      for(uint  i =h;i<h+n;i++){
      if ( board[i].count(v) != 0&&board.count(i) != 0){//existing something to read in map if not add and read '_'
      ans+=this->board[i][v];}
      else
      {
          ans+='_';
      }
      
     
     
      }
     
         
       
      
      break;
   }
   }
      catch(exception &e){
      cout<<"error"<<endl;
      }
   
   
return ans;
   
}
void Board:: show(){//show the board 
 cout<<"The Board:"<<endl;
 
   for(uint  i=this->Minrow;i<this->Mxrow;i++){
      
      for(uint  j=this->Mincol ;j<this->Mxcol;j++){
        if(this->board[i][j]!='_'){
           cout<<"row"<<i<<":";
           //cout<<i;
           //cout<<":";
           cout<<"col "<<j<<":";

           
          cout<<"| ";
          cout<<this->board[i][j];
          cout<< " |";

   }
         if(j+1==this->Mxcol){
         cout<<endl;
         }
      
      }
      
         

   
}
  
}
}

   
    
    

    


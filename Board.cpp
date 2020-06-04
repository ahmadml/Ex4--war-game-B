#include "Board.hpp"
#include <iostream>
#include <limits>
#include <math.h>
using namespace std;

namespace WarGame {


         Soldier*& Board :: operator[](std::pair<int,int> location){
             //if(board[location.first][location.second]!=nullptr)
             return board[location.first][location.second];
        }


        Soldier* Board:: operator[](std::pair<int,int> location) const{
            return  board[location.first][location.second];
        }

        void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction) {
            std::pair<int,int> temp = source;
            if(source.first>=board.size() || source.second>=board[0].size() || source.first<0 || source.second<0) throw out_of_range{"error"};
            Soldier* sol = board[source.first][source.second];
            if(sol!=nullptr && sol->nop==player_number){
                if(direction==Up) temp.first+=1;
                if(direction==Down) temp.first-=1;
                if(direction==Left) temp.second-=1;
                if(direction==Right) temp.second+=1;
                if(temp.first<board.size() && temp.second<board[0].size() && temp.second>=0 && temp.first>=0 && board[temp.first][temp.second]==nullptr ){
                    board[temp.first][temp.second]=board[source.first][source.second];
                    board[source.first][source.second]=nullptr;
                    sol = board[temp.first][temp.second];
                    sol->attak(temp,this->board,player_number);
                }
               else throw out_of_range{"error"};
            }
            else  throw out_of_range{"error"};
        }



         bool Board::has_soldiers(uint nop) const {
            int count=0;
             for(int i=0; i<board.size();i++){
                 for(int j=0; j<board[i].size();j++){
                     Soldier* sol= board[i][j];
                     if(sol!=nullptr && sol->nop==nop && sol->hp>0){
                        return true;
                     }
                 }
             }
             return false;
         }
}

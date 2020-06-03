#include "Soldier.hpp"

class SniperCommander : public  Soldier {
public:
SniperCommander(int nop){
this->damage = 100;
this->nop=nop;
this->hp=120;
}

virtual void attak(std::pair<int,int> source,std::vector<std::vector<Soldier*>> &board,uint player_number){
    int max = 0;
    std::pair<int,int> lo;
    for(int i=0; i<board.size();i++){
        for(int j=0; j<board[i].size();j++){
            Soldier* sol= board[i][j];
            if(sol!=nullptr && sol->nop!=player_number){
                if(sol->hp >= max){
                    max = sol->hp;
                    lo.first=i;
                    lo.second=j;
                }
            }
        }
    }
    Soldier* s= board[lo.first][lo.second];
    s->hp-=this->damage;
    //std::cout<<"s";
     for(int i=0; i<board.size();i++){
        for(int j=0; j<board[i].size();j++){
            Soldier* sol= board[i][j];
            if(sol!=nullptr && sol->nop==player_number && sol->damage==50){
                std::pair<int,int> temp;
                temp.first=i;
                temp.second=j;
                sol->attak(temp,board,player_number);
            } 
        }
    } 
}
};
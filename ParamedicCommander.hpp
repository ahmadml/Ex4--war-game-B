#include "Soldier.hpp"

class ParamedicCommander : public  Soldier {
public:
ParamedicCommander(int nop){
this->damage = 1;
this->nop = nop;
this->hp = 200;
}

virtual void attak(std::pair<int,int> source,std::vector<std::vector<Soldier*>> &board,uint player_number){
    std::pair<int,int> lo;
    for(int i=source.first-1; i<=source.first+1;i++){
        for(int j=source.second-1; j<=source.second+1;j++){
            
            if(i>=0 && i<board.size() && j>=0 && j<board[0].size()){
                Soldier* sol= board[i][j];
                if(sol!=nullptr && sol->nop==player_number){
                if(sol->damage==10) sol->hp=100;
                if(sol->damage==20) sol->hp=150;
                if(sol->damage==50) sol->hp=100;
                if(sol->damage==100) sol->hp=120;
                if(sol->damage==0) sol->hp=100;
               if(sol->damage==1) sol->hp=200;
                }
            }
        } 
    }
    for(int i=0; i<board.size();i++){
        for(int j=0; j<board[i].size();j++){
            Soldier* sol= board[i][j];
            if(sol!=nullptr && sol->nop==player_number && sol->damage==0){
                std::pair<int,int> temp;
                temp.first=i;
                temp.second=j;
                sol->attak(temp,board,player_number);
            }
        }
    }
}
};

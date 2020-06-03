#include "Soldier.hpp"

class Paramedic : public  Soldier {
public:
Paramedic(int nop){
this->damage = 0;
this->nop=nop;
this->hp=100;
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
                if(typeid(*sol)==typeid(ParamedicCommander)) sol->hp=200;
                }
            }
        } 
    }
}
};
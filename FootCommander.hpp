#include "Soldier.hpp"

class FootCommander : public  Soldier {
public:
FootCommander(int nop){
this->nop=nop;
this->damage = 20;
this->hp=150;
}
double destance(int i, int j, std::pair<int,int> source){
    int x = (i-source.first)*(i-source.first);
    int y = (j-source.second)*(j-source.second);
    double des = std::sqrt(x+y);
    return des;
}
virtual void attak(std::pair<int,int> source,std::vector<std::vector<Soldier*>> &board,uint player_number){
    int min = 1000;
    //std::cout<<player_number<<"footcoo\n";
    std::pair<int,int> lo;
    for(int i=0; i<board.size();i++){
        for(int j=0; j<board[i].size();j++){
            Soldier* sol= board[i][j];
            if(sol!=nullptr && sol->nop!=player_number){
                double des = destance(i,j,source);
                if(des<min){
                     min = des;
                    lo.first=i;
                    lo.second=j;
                }
            }
       }
    }
     Soldier* s= board[lo.first][lo.second];
     s->hp-=this->damage;

      for(int i=0; i<board.size();i++){
        for(int j=0; j<board[i].size();j++){
            Soldier* sol= board[i][j];
            if(sol!=nullptr && sol->nop==player_number && sol->damage==10){
                std::pair<int,int> temp;
                temp.first=i;
                temp.second=j;
                sol->attak(temp,board,player_number);
            } 
        }
    } 
}
};
#include "doctest.h"
#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"




WarGame::Board Board1(){
    WarGame::Board board1(11,11);
// fill player 1
    board1[{1,2}]= new FootSoldier(1);
    board1[{9,9}]= new FootCommander(1);
    board1[{10,1}]= new Sniper(1);
    board1[{1,1}]= new SniperCommander(1);
    board1[{5,5}]= new Paramedic(1);
    board1[{7,9}]= new ParamedicCommander(1);
//fill player 2
    board1[{2,3}]= new FootSoldier(2);
    board1[{1,5}]= new FootCommander(2);
    board1[{4,5}]= new Sniper(2);
    board1[{8,9}]= new SniperCommander(2);
    board1[{4,1}]= new Paramedic(2);
    board1[{9,7}]= new ParamedicCommander(2);
    return board1;
}
WarGame::Board Board2(){
    WarGame::Board board2 (8,8);
    // fill player 1

    board2[{8,8}] = new FootSoldier(1);
    board2[{3,3}] = new Paramedic(1);
    board2[{2,2}] = new FootCommander(1);
    board2[{1,1}] = new SniperCommander(1);
    board2[{8,7}] = new Sniper(1);
    board2[{6,7}] = new ParamedicCommander(1);
// fill player 2
    board2[{7,7}] = new FootSoldier(2);
    board2[{6,6}] = new SniperCommander(2);
    board2[{5,5}] = new FootCommander(2);
    board2[{4,4}] = new Paramedic(2);
    board2[{7,8}] = new Sniper(2);
    board2[{7,6}] = new ParamedicCommander(2);
    return board2;
}



TEST_CASE("Checking board1"){
    WarGame::Board board1 = Board1();
            CHECK(board1.has_soldiers(1));
            CHECK(board1.has_soldiers(2));


    //check player1 fill
            CHECK_FALSE(typeid(board1[{1,2}]) == typeid(FootSoldier));
            CHECK_FALSE(typeid(board1[{9,9}]) == typeid(FootCommander));
            CHECK_FALSE(typeid(board1[{10,1}]) == typeid(Sniper));
            CHECK_FALSE(typeid(board1[{1,1}]) == typeid(SniperCommander));
            CHECK_FALSE(typeid(board1[{5,5}]) == typeid(Paramedic));
            CHECK_FALSE(typeid(board1[{7,9}]) == typeid(ParamedicCommander));
            CHECK_FALSE(typeid(board1[{1,2}]) == typeid(FootCommander));
            CHECK_FALSE(typeid(board1[{8,9}]) == typeid(Sniper));
            CHECK_FALSE(typeid(board1[{10,1}]) == typeid(SniperCommander));
            CHECK_FALSE(typeid(board1[{1,1}]) == typeid(Paramedic));
            CHECK_FALSE(typeid(board1[{5,5}]) == typeid(ParamedicCommander));
            CHECK_FALSE(typeid(board1[{7,9}]) == typeid(Sniper));

            CHECK_FALSE(typeid(board1[{2,3}]) == typeid(FootSoldier));
            CHECK_FALSE(typeid(board1[{1,5}]) == typeid(FootCommander));
            CHECK_FALSE(typeid(board1[{4,5}]) == typeid(Sniper));
            CHECK_FALSE(typeid(board1[{8,9}]) == typeid(SniperCommander));
            CHECK_FALSE(typeid(board1[{4,1}]) == typeid(Paramedic));
            CHECK_FALSE(typeid(board1[{9,7}]) == typeid(ParamedicCommander));

            CHECK_FALSE(typeid(board1[{2,3}]) == typeid(FootCommander));
            CHECK_FALSE(typeid(board1[{1,5}]) == typeid(Sniper));
            CHECK_FALSE(typeid(board1[{4,5}]) == typeid(SniperCommander));
            CHECK_FALSE(typeid(board1[{8,9}]) == typeid(Paramedic));
            CHECK_FALSE(typeid(board1[{4,1}]) == typeid(ParamedicCommander));
            CHECK_FALSE(typeid(board1[{9,7}]) == typeid(Sniper));
            CHECK_FALSE(typeid(board1[{2,3}]) == typeid(FootSoldier));
            CHECK_FALSE(typeid(board1[{0,5}]) == typeid(FootCommander));
            CHECK_FALSE(typeid(board1[{4,0}]) == typeid(Sniper));
            CHECK_FALSE(typeid(board1[{0,9}]) == typeid(SniperCommander));
            CHECK_FALSE(typeid(board1[{4,0}]) == typeid(Paramedic));
            CHECK_FALSE(typeid(board1[{0,7}]) == typeid(ParamedicCommander));

            CHECK_FALSE(typeid(board1[{2,0}]) == typeid(FootCommander));
            CHECK_FALSE(typeid(board1[{8,5}]) == typeid(Sniper));
            CHECK_FALSE(typeid(board1[{8,5}]) == typeid(SniperCommander));
            CHECK_FALSE(typeid(board1[{0,9}]) == typeid(Paramedic));
            CHECK_FALSE(typeid(board1[{0,1}]) == typeid(ParamedicCommander));
            CHECK_FALSE(typeid(board1[{9,0}]) == typeid(Sniper));
}
TEST_CASE("Checking board2"){
    WarGame::Board board2 = Board1();

            CHECK(board2.has_soldiers(1));
            CHECK(board2.has_soldiers(2));


    //check player1 fill
            CHECK_FALSE(typeid(board2[{1,2}]) == typeid(FootSoldier));
            CHECK_FALSE(typeid(board2[{9,9}]) == typeid(FootCommander));
            CHECK_FALSE(typeid(board2[{10,1}]) == typeid(Sniper));
            CHECK_FALSE(typeid(board2[{1,1}]) == typeid(SniperCommander));
            CHECK_FALSE(typeid(board2[{5,5}]) == typeid(Paramedic));
            CHECK_FALSE(typeid(board2[{7,9}]) == typeid(ParamedicCommander));

            CHECK_FALSE(typeid(board2[{1,2}]) == typeid(FootCommander));
            CHECK_FALSE(typeid(board2[{8,9}]) == typeid(Sniper));
            CHECK_FALSE(typeid(board2[{10,1}]) == typeid(SniperCommander));
            CHECK_FALSE(typeid(board2[{1,1}]) == typeid(Paramedic));
            CHECK_FALSE(typeid(board2[{5,5}]) == typeid(ParamedicCommander));
            CHECK_FALSE(typeid(board2[{7,9}]) == typeid(Sniper));
    
 
            CHECK_FALSE(typeid(board2[{2,3}]) == typeid(FootSoldier));
            CHECK_FALSE(typeid(board2[{1,5}]) == typeid(FootCommander));
            CHECK_FALSE(typeid(board2[{4,5}]) == typeid(Sniper));
            CHECK_FALSE(typeid(board2[{8,9}]) == typeid(SniperCommander));
            CHECK_FALSE(typeid(board2[{4,1}]) == typeid(Paramedic));
            CHECK_FALSE(typeid(board2[{9,7}]) == typeid(ParamedicCommander));

            CHECK_FALSE(typeid(board2[{2,3}]) == typeid(FootCommander));
            CHECK_FALSE(typeid(board2[{1,5}]) == typeid(Sniper));
            CHECK_FALSE(typeid(board2[{4,5}]) == typeid(SniperCommander));
            CHECK_FALSE(typeid(board2[{8,9}]) == typeid(Paramedic));
            CHECK_FALSE(typeid(board2[{4,1}]) == typeid(ParamedicCommander));
            CHECK_FALSE(typeid(board2[{9,7}]) == typeid(Sniper));
}
TEST_CASE("Checking board3"){
    WarGame::Board board3 = Board1();

            CHECK(board3.has_soldiers(1));
            CHECK(board3.has_soldiers(2));


    //check player1 fill
            CHECK_FALSE(typeid(board3[{1,2}]) == typeid(FootSoldier));
            CHECK_FALSE(typeid(board3[{9,9}]) == typeid(FootCommander));
            CHECK_FALSE(typeid(board3[{10,1}]) == typeid(Sniper));
            CHECK_FALSE(typeid(board3[{1,1}]) == typeid(SniperCommander));
            CHECK_FALSE(typeid(board3[{5,5}]) == typeid(Paramedic));
            CHECK_FALSE(typeid(board3[{7,9}]) == typeid(ParamedicCommander));
            CHECK_FALSE(typeid(board3[{1,2}]) == typeid(FootCommander));
            CHECK_FALSE(typeid(board3[{8,9}]) == typeid(Sniper));
            CHECK_FALSE(typeid(board3[{10,1}]) == typeid(SniperCommander));
            CHECK_FALSE(typeid(board3[{1,1}]) == typeid(Paramedic));
            CHECK_FALSE(typeid(board3[{5,5}]) == typeid(ParamedicCommander));
            CHECK_FALSE(typeid(board3[{7,9}]) == typeid(Sniper));
    
 
            CHECK_FALSE(typeid(board3[{2,3}]) == typeid(FootSoldier));
            CHECK_FALSE(typeid(board3[{1,5}]) == typeid(FootCommander));
            CHECK_FALSE(typeid(board3[{4,5}]) == typeid(Sniper));
            CHECK_FALSE(typeid(board3[{8,9}]) == typeid(SniperCommander));
            CHECK_FALSE(typeid(board3[{4,1}]) == typeid(Paramedic));
            CHECK_FALSE(typeid(board3[{9,7}]) == typeid(ParamedicCommander));

            CHECK_FALSE(typeid(board3[{2,3}]) == typeid(FootCommander));
            CHECK_FALSE(typeid(board3[{1,5}]) == typeid(Sniper));
            CHECK_FALSE(typeid(board3[{4,5}]) == typeid(SniperCommander));
            CHECK_FALSE(typeid(board3[{8,9}]) == typeid(Paramedic));
            CHECK_FALSE(typeid(board3[{4,1}]) == typeid(ParamedicCommander));
            CHECK_FALSE(typeid(board3[{9,7}]) == typeid(Sniper));
            CHECK_FALSE(typeid(board3[{4,5}]) == typeid(Sniper));
            CHECK_FALSE(typeid(board3[{8,9}]) == typeid(SniperCommander));
            CHECK_FALSE(typeid(board3[{4,1}]) == typeid(Paramedic));
            CHECK_FALSE(typeid(board3[{9,7}]) == typeid(ParamedicCommander));

            CHECK_FALSE(typeid(board3[{0,3}]) == typeid(FootCommander));
            CHECK_FALSE(typeid(board3[{8,5}]) == typeid(Sniper));
            CHECK_FALSE(typeid(board3[{0,5}]) == typeid(SniperCommander));
            CHECK_FALSE(typeid(board3[{8,0}]) == typeid(Paramedic));
             CHECK_FALSE(typeid(board3[{8,3}]) == typeid(FootCommander));
            CHECK_FALSE(typeid(board3[{1,0}]) == typeid(Sniper));
            CHECK_FALSE(typeid(board3[{7,5}]) == typeid(SniperCommander));
            CHECK_FALSE(typeid(board3[{8,2}]) == typeid(Paramedic));
            CHECK_FALSE(typeid(board3[{0,1}]) == typeid(ParamedicCommander));
            CHECK_FALSE(typeid(board3[{9,6}]) == typeid(Sniper));
            CHECK_FALSE(typeid(board3[{7,5}]) == typeid(Sniper));
            CHECK_FALSE(typeid(board3[{0,9}]) == typeid(SniperCommander));
            CHECK_FALSE(typeid(board3[{4,8}]) == typeid(Paramedic));
            CHECK_FALSE(typeid(board3[{1,7}]) == typeid(ParamedicCommander));

}
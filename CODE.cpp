////////////////////////////GROUP MEMBERS//////////////////////////////////////
/*////////////////////////////////////////////////////////////////////////////
1-Lubna Mahmoud AlHourani #139191
2-Lina Mohammed AlDwairi #136729
3-Sadan Fayez Nsour #137019
/////////////////////////////////////////////////////////////////////////////*/
//////////////////////////////////////////////////////////////////////////////



#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include<algorithm>
#include<map>
#include <cstring>
#include <stdio.h>
using namespace std;

class node {

public:
    int a[9] = { 0, 1, 1, 2, 3, 3, 5, 4, 6 };
    int index = 0;//index of the blank
    int level = 0;
    int cost=0;
    node *parent=NULL;
    //the constructor shuffle the intial state
    node() {
        //to determind different 'seed' or starting point for the random_shuffle function
       //to give us different order every time we run the random  shuffle function.
        srand(time(0));

        //built in random function
       random_shuffle(begin(a), end(a));
    }
    void print() {
        int column = 0;
        for (int row = 0; row < 3; row++) {
            cout << a[column] << " " << a[++column] << " " << a[++column];
            cout << endl;
            ++column;
        }
    }
    //to find the index of the blank box
    void findO() {

        for (int i = 0; i < 9; i++)
            if (a[i] == 0)
                index = i;

    }
    //First Heuristc Function
    int NumOfMisPlacedTiles(node n){
    int count=0;
    int goalstate[9]={0,1,1,2,3,3,4,5,6};
    for(int i=0;i<9;i++)
    if(n.a[i]!=goalstate[i])
    count=count+1;
    return count;
    }
    //Second Heuristic Function
    int TotalManhatenDistance(node n){
    int count=0;
        
        //index 0
         if(n.a[0]==2)
        count=count+1;
        else if(n.a[0]==4)
        count=count+2;
        else if(n.a[0]==5)
        count=count+3;
        else if(n.a[0]==6)
        count=count+4;
        
        //index 1
        if(n.a[1]==2)
        count=count+2;
        else if(n.a[1]==4)
        count=count+2;
        else if(n.a[1]==5)
        count=count+2;
        else if(n.a[1]==6)
        count=count+3;
        
        //index 2
        if(n.a[2]==2)
        count=count+3;
        else if(n.a[2]==4)
        count=count+4;
        else if(n.a[2]==5)
        count=count+3;
        else if(n.a[2]==6)
        count=count+2;
        
        //index 3
        else if(n.a[3]==4)
        count=count+1;
        else if(n.a[3]==5)
        count=count+2;
        else if(n.a[3]==6)
        count=count+3;
        
        //index 4
        if(n.a[4]==2)
        count=count+1;
        else if(n.a[4]==4)
        count=count+2;
        else if(n.a[4]==5)
        count=count+4;
        else if(n.a[4]==6)
        count=count+2;
        
        //index 5
        if(n.a[5]==2)
        count=count+2;
        else if(n.a[5]==4)
        count=count+3;
        else if(n.a[5]==5)
        count=count+2;
        else if(n.a[5]==6)
        count=count+1;
    
        //index 6
        if(n.a[6]==2)
        count=count+1;
        else if(n.a[6]==5)
        count=count+1;
        else if(n.a[6]==6)
        count=count+2;
        
        //index 7
        if(n.a[7]==2)
        count=count+2;
        else if(n.a[7]==4)
        count=count+1;
        else if(n.a[7]==6)
        count=count+1;
        
        //index 8
        if(n.a[8]==2)
        count=count+3;
        else if(n.a[8]==4)
        count=count+2;
        else if(n.a[8]==5)
        count=count+1;
        
        //For 1 & 1
        //index 0
        if(n.a[0]==1 && n.a[1]==1)
        count=count+2;
        if(n.a[0]==1 && n.a[2]==1)
        count=count+1;
        if(n.a[0]==1 && n.a[3]==1)
        count=count+4;
        if(n.a[0]==1 && n.a[4]==1)
        count=count+2;
        if(n.a[0]==1 && n.a[5]==1)
        count=count+2;
        if(n.a[0]==1 && n.a[6]==1)
        count=count+5;
        if(n.a[0]==1 && n.a[7]==1)
        count=count+4;
        if(n.a[0]==1 && n.a[8]==1)
        count=count+3;
        
        //index 1
        if(n.a[1]==1 && n.a[3]==1)
        count=count+3;
        if(n.a[1]==1 && n.a[4]==1)
        count=count+2;
        if(n.a[1]==1 && n.a[5]==1)
        count=count+1;
        if(n.a[1]==1 && n.a[6]==1)
        count=count+4;
        if(n.a[1]==1 && n.a[7]==1)
        count=count+3;
        if(n.a[1]==1 && n.a[8]==1)
        count=count+2;

        //index 2
        if(n.a[2]==1 && n.a[3]==1)
        count=count+2;
        if(n.a[2]==1 && n.a[4]==1)
        count=count+1;
        if(n.a[2]==1 && n.a[5]==1)
        count=count+2;
        if(n.a[2]==1 && n.a[6]==1)
        count=count+3;
        if(n.a[2]==1 && n.a[7]==1)
        count=count+2;
        if(n.a[2]==1 && n.a[8]==1)
        count=count+3;
        
        //index 3
        if(n.a[3]==1 && n.a[4]==1)
        count=count+4;
        if(n.a[3]==1 && n.a[5]==1)
        count=count+3;
        if(n.a[3]==1 && n.a[6]==1)
        count=count+5;
        if(n.a[3]==1 && n.a[7]==1)
        count=count+5;
        if(n.a[3]==1 && n.a[8]==1)
        count=count+4;
        
        //index 4
        if(n.a[4]==1 && n.a[5]==1)
        count=count+2;
        if(n.a[4]==1 && n.a[6]==1)
        count=count+5;
        if(n.a[4]==1 && n.a[7]==1)
        count=count+4;
        if(n.a[4]==1 && n.a[8]==1)
        count=count+3;
        
        //index 5
        if(n.a[5]==1 && n.a[6]==1)
        count=count+4;
        if(n.a[5]==1 && n.a[7]==1)
        count=count+3;
        if(n.a[5]==1 && n.a[8]==1)
        count=count+4;
        
        //index 6
        if(n.a[6]==1 && n.a[7]==1)
        count=count+6;
        if(n.a[6]==1 && n.a[8]==1)
        count=count+5;

        //index 7
        if(n.a[7]==1 && n.a[8]==1)
        count=count+4;

        //For 3 & 3
        //index 0
        if(n.a[0]==3 && n.a[1]==3)
        count=count+4;
        if(n.a[0]==3 && n.a[2]==3)
        count=count+3;
        if(n.a[0]==3 && n.a[3]==3)
        count=count+4;
        if(n.a[0]==3 && n.a[4]==3)
        count=count+3;
        if(n.a[0]==3 && n.a[5]==3)
        count=count+2;
        if(n.a[0]==3 && n.a[6]==3)
        count=count+5;
        if(n.a[0]==3 && n.a[7]==3)
        count=count+4;
        if(n.a[0]==3 && n.a[8]==3)
        count=count+3;
        
        //index 1
        if(n.a[1]==3 && n.a[2]==3)
        count=count+2;
        if(n.a[1]==3 && n.a[3]==3)
        count=count+3;
        if(n.a[1]==3 && n.a[4]==3)
        count=count+2;
        if(n.a[1]==3 && n.a[5]==3)
        count=count+1;
        if(n.a[1]==3 && n.a[6]==3)
        count=count+4;
        if(n.a[1]==3 && n.a[7]==3)
        count=count+3;
        if(n.a[1]==1 && n.a[8]==3)
        count=count+2;

        //index 2
        if(n.a[2]==3 && n.a[3]==3)
        count=count+2;
        if(n.a[2]==3 && n.a[4]==3)
        count=count+1;
        if(n.a[2]==3 && n.a[5]==3)
        count=count+2;
        if(n.a[2]==3 && n.a[6]==3)
        count=count+3;
        if(n.a[2]==3 && n.a[7]==3)
        count=count+2;
        if(n.a[2]==1 && n.a[8]==3)
        count=count+3;
        
        //index 3
        if(n.a[3]==3 && n.a[4]==3)
        count=count+2;
        if(n.a[3]==3 && n.a[5]==3)
        count=count+1;
        if(n.a[3]==3 && n.a[6]==3)
        count=count+4;
        if(n.a[3]==3 && n.a[7]==3)
        count=count+3;
        if(n.a[3]==1 && n.a[8]==3)
        count=count+2;
        
        //index 4
        if(n.a[4]==3 && n.a[6]==3)
        count=count+3;
        if(n.a[4]==3 && n.a[7]==3)
        count=count+2;
        if(n.a[4]==3 && n.a[8]==3)
        count=count+1;
        
        //index 5
        if(n.a[5]==3 && n.a[6]==3)
        count=count+2;
        if(n.a[5]==3 && n.a[7]==3)
        count=count+1;
        if(n.a[5]==3 && n.a[8]==3)
        count=count+2;
        
        //index 6
        if(n.a[6]==3 && n.a[7]==3)
        count=count+4;
        if(n.a[6]==3 && n.a[8]==3)
        count=count+3;

        //index 7
        if(n.a[7]==3 && n.a[8]==3)
        count=count+2;
        
    return count;
}
    //for Astar
    int Cost(int &g){
        int h1=0;
        int h2=0;
        h1=NumOfMisPlacedTiles(*this);
        h2=TotalManhatenDistance(*this);
        return h1+h2+g;
    }
    
    //Expand Function to use at BFS & IDS Algo.
    void Expand(list<node> &fringe) {
         this->findO();
        if (index == 0) {
            fringe.push_back(this->Right());
            fringe.back().level=this->level+1;
            fringe.back().parent=this;
            fringe.push_back(this->Down());
            fringe.back().level=this->level+1;
            fringe.back().parent=this;
        }
        else if (index == 1) {
                fringe.push_back(this->Left());
                fringe.back().level=this->level+1;
                fringe.back().parent=this;
                fringe.push_back(this->Right());
                fringe.back().level=this->level+1;
                fringe.back().parent=this;
                fringe.push_back(this->Down());
                fringe.back().level=this->level+1;
                fringe.back().parent=this;
        }
        else if (index == 2) {
    
                fringe.push_back(this->Left());
                fringe.back().level=this->level+1;
                fringe.back().parent=this;
                fringe.push_back(this->Down());
                fringe.back().level=this->level+1;
                fringe.back().parent=this;
        }
        else if (index == 3) {
           fringe.push_back(this->Up());
           fringe.back().level=this->level+1;
           fringe.back().parent=this;
           fringe.push_back(this->Down());
           fringe.back().level=this->level+1;
           fringe.back().parent=this;
           fringe.push_back(this->Right());
           fringe.back().level=this->level+1;
           fringe.back().parent=this;
        }
        else if (index == 4) {
            fringe.push_back(this->Left());
            fringe.back().level=this->level+1;
            fringe.back().parent=this;
            fringe.push_back(this->Down());
            fringe.back().level=this->level+1;
            fringe.back().parent=this;
            fringe.push_back(this->Right());
            fringe.back().level=this->level+1;
            fringe.back().parent=this;
            fringe.push_back(this->Up());
            fringe.back().level=this->level+1;
            fringe.back().parent=this;
        }
        else if (index == 5) {
            fringe.push_back(this->Left());
            fringe.back().level=this->level+1;
            fringe.back().parent=this;
            fringe.push_back(this->Down());
            fringe.back().level=this->level+1;
            fringe.back().parent=this;
            fringe.push_back(this->Up());
            fringe.back().level=this->level+1;
            fringe.back().parent=this;
        }
        else if (index == 6) {
            fringe.push_back(this->Right());
            fringe.back().level=this->level+1;
            fringe.back().parent=this;
            fringe.push_back(this->Up());
            fringe.back().level=this->level+1;
            fringe.back().parent=this;
        }
        else if (index == 7) {
             fringe.push_back(this->Up());
             fringe.back().level=this->level+1;
             fringe.back().parent=this;
             fringe.push_back(this->Right());
             fringe.back().level=this->level+1;
             fringe.back().parent=this;
             fringe.push_back(this->Left());
             fringe.back().level=this->level+1;
             fringe.back().parent=this;
        }
        else if (index == 8) {
                fringe.push_back(this->Left());
                fringe.back().level=this->level+1;
                fringe.back().parent=this;
                fringe.push_back(this->Up());
                fringe.back().level=this->level+1;
                fringe.back().parent=this;
        }
               

          
    }
    //Sort Function to use at ExpandAstar Function
    void sort(list<node> &fringe){
        fringe.sort([](const node &f, const node &s) { return f.cost < s.cost; });
    }
    //Expand Function to use at A* Algo.
    void ExpandAstar(list<node> &fringe,int &g) {
         this->findO();
        if (index == 0) {
                fringe.push_front(this->Down());
                fringe.front().cost=fringe.front().Cost(g);
                fringe.front().level=this->level+1;
                fringe.front().parent=this;
                fringe.push_front(this->Right());
                fringe.front().level=this->level+1;
                fringe.front().cost=fringe.front().Cost(g);
                fringe.front().parent=this;
        }
        else if (index == 1) {

                fringe.push_front(this->Left());
                fringe.front().cost=fringe.front().Cost(g);
                fringe.front().level=this->level+1;
                fringe.front().parent=this;
                fringe.push_front(this->Down());
                fringe.front().cost=fringe.front().Cost(g);
                fringe.front().level=this->level+1;
                fringe.front().parent=this;
                fringe.push_front(this->Right());
                fringe.front().cost=fringe.front().Cost(g);
                fringe.front().level=this->level+1;
                fringe.front().parent=this;
            
        }
        else if (index == 2) {
                fringe.push_front(this->Left());
                fringe.front().cost=fringe.front().Cost(g);
                fringe.front().level=this->level+1;
                fringe.front().parent=this;
                fringe.push_front(this->Down());
                fringe.front().cost=fringe.front().Cost(g);
                fringe.front().level=this->level+1;
                fringe.front().parent=this;
        }
        else if (index == 3) {
                fringe.push_front(this->Up());
                fringe.front().cost=fringe.front().Cost(g);
                fringe.front().level=this->level+1;
                fringe.front().parent=this;
                fringe.push_front(this->Down());
                fringe.front().cost=fringe.front().Cost(g);
                fringe.front().level=this->level+1;
                fringe.front().parent=this;
                fringe.push_front(this->Right());
                fringe.front().cost=fringe.front().Cost(g);
                fringe.front().level=this->level+1;
                fringe.front().parent=this;
        }
        else if (index == 4) {
                fringe.push_front(this->Left());
                fringe.front().cost=fringe.front().Cost(g);
                fringe.front().level=this->level+1;
                fringe.front().parent=this;
                fringe.push_front(this->Down());
                fringe.front().cost=fringe.front().Cost(g);
                fringe.front().level=this->level+1;
                fringe.front().parent=this;
                fringe.push_front(this->Right());
                fringe.front().cost=fringe.front().Cost(g);
                fringe.front().level=this->level+1;
                fringe.front().parent=this;
                fringe.push_front(this->Up());
                fringe.front().cost=fringe.front().Cost(g);
                fringe.front().level=this->level+1;
                fringe.front().parent=this;
        }
        else if (index == 5) {
                fringe.push_front(this->Up());
                fringe.front().cost=fringe.front().Cost(g);
                fringe.front().level=this->level+1;
                fringe.front().parent=this;
                fringe.push_front(this->Down());
                fringe.front().cost=fringe.front().Cost(g);
                fringe.front().level=this->level+1;
                fringe.front().parent=this;
                fringe.push_front(this->Left());
                fringe.front().cost=fringe.front().Cost(g);
                fringe.front().level=this->level+1;
                fringe.front().parent=this;
        }
        else if (index == 6) {
                fringe.push_front(this->Up());
                fringe.front().cost=fringe.front().Cost(g);
                fringe.front().level=this->level+1;
                fringe.front().parent=this;
                fringe.push_front(this->Right());
                fringe.front().cost=fringe.front().Cost(g);
                fringe.front().level=this->level+1;
                fringe.front().parent=this;

        }
        else if (index == 7) {
                fringe.push_front(this->Up());
                fringe.front().cost=fringe.front().Cost(g);
                fringe.front().level=this->level+1;
                fringe.front().parent=this;
                fringe.push_front(this->Left());
                fringe.front().cost=fringe.front().Cost(g);
                fringe.front().level=this->level+1;
                fringe.front().parent=this;
                fringe.push_front(this->Right());
                fringe.front().cost=fringe.front().Cost(g);
                fringe.front().level=this->level+1;
                fringe.front().parent=this;

        }
        else if (index == 8) {
                fringe.push_front(this->Left());
                fringe.front().cost=fringe.front().Cost(g);
                fringe.front().level=this->level+1;
                fringe.front().parent=this;
                fringe.push_front(this->Up());
                fringe.front().cost=fringe.front().Cost(g);
                fringe.front().level=this->level+1;
                fringe.front().parent=this;
                
        }
        sort(fringe);
    }
    //Goal Test function
    bool GoalTest() {
        bool condtion = true;
        int goalarr[9] = { 0,1,1,2,3,3,4,5,6 };
        for (int i = 0; i < 9; i++)
            if (a[i] != goalarr[i])
                condtion = false;
        return condtion;


    }
    //UP Action function
    node Up() {
        node d;
        d = *this;
        d.findO();
        if (d.index == 3)
        {
            d.a[3] = d.a[0];
            d.a[0] = 0;
        }
        else if (d.index == 4) {
            d.a[4] = d.a[1];
            d.a[1] = 0;
        }
        else if (d.index == 5) {
            d.a[5] = d.a[2];
            d.a[2] = 0;
        }
        else if (d.index == 6)
        {
            d.a[6] = d.a[3];
            d.a[3] = 0;
        }
        else if (d.index == 7) {
            d.a[7] = d.a[4];
            d.a[4] = 0;
        }
        else if (d.index == 8) {
            d.a[8] = d.a[5];
            d.a[5] = 0;
        }
        return d;
    }
    //DOWN Action function
    node Down() {
        node d = *this;
        if (d.index == 0) {
            d.a[0] = d.a[3];
            d.a[3] = 0;

        }
        else if (d.index == 1) {
            d.a[1] = d.a[4];
            d.a[4] = 0;

        }
        else if (d.index == 2) {
            d.a[2] = d.a[5];
            d.a[5] = 0;
        }
        else if (d.index == 3)
        {
            d.a[3] = d.a[6];
            d.a[6] = 0;
        }
        else if (d.index == 4) {
            d.a[4] = d.a[7];
            d.a[7] = 0;
        }
        else if (d.index == 5) {
            d.a[5] = d.a[8];
            d.a[8] = 0;
        }
        return d;
    }
    //Right Action function
    node Right() {
        node d = *this;
        if (d.index == 0)
        {
            d.a[0] = d.a[1];
            d.a[1] = 0;
        }
        else if (d.index == 1) {
            d.a[1] = d.a[2];
            d.a[2] = 0;
        }
        else if (d.index == 3) {
            d.a[3] = d.a[4];
            d.a[4] = 0;
        }
        else if (d.index == 4)
        {
            d.a[4] = d.a[5];
            d.a[5] = 0;
        }
        else if (d.index == 6) {
            d.a[6] = d.a[7];
            d.a[7] = 0;
        }
        else if (d.index == 7) {
            d.a[7] = d.a[8];
            d.a[8] = 0;
        }
        return d;
    }
    //Left Action function
    node Left() {
        node d = *this;
        if (d.index == 1)
        {
            d.a[1] = d.a[0];
            d.a[0] = 0;
        }
        else if (d.index == 2) {
            d.a[2] = d.a[1];
            d.a[1] = 0;
        }
        else if (d.index == 4) {
            d.a[4] = d.a[3];
            d.a[3] = 0;
        }
        else if (d.index == 5)
        {
            d.a[5] = d.a[4];
            d.a[4] = 0;
        }
        else if (d.index == 7) {
            d.a[7] = d.a[6];
            d.a[6] = 0;
        }
        else if (d.index == 8) {
            d.a[8] = d.a[7];
            d.a[7] = 0;
        }
        return d;
    }
};


class searching {
public:

    void BFS(node root) {
        list<node> fringe;
        map<list<int>,int>explored;
        list<node> PathToSolution;
        bool GoalFound = false;
        fringe.push_back(root);
        
        while(!GoalFound){
         
            //create a Queue
            //1- check if current is goal, if so then terminate
            node Current =fringe.front();
            GoalFound=Current.GoalTest();
            if(GoalFound)
            { 
                cout<<"The Goal Is Found Using the Breadth First Search Algorithm\n";
                cout<<"Number of Generated nodes in the BFS: "<<explored.size()+fringe.size()<<endl;
                cout<<"Number of Expanded nodes in the BfS: "<<explored.size()<<endl;
                cout<<"The Solution Found At Level: "<<Current.level<<endl;
                cout<<"The Number Of Steps: "<<Current.level<<endl;
                
                ///////////////////To find the path but it does not work correctly/////////////////////////////
                //int steps=0;
                   /*while(Current.parent!=NULL){
                        PathToSolution.push_front(Current);
                        
                        Current=*(Current.parent);
                        steps=steps+1;
                        if(steps>10)break;
                    }*/
                //////////////////////////////////////////////////////////////////////////////////////////////
                break;   
            }
            //2- else
            else
            {
                list<int>l={Current.a[0],Current.a[1],Current.a[2],Current.a[3],Current.a[4],Current.a[5],Current.a[6],Current.a[7],Current.a[8]};
                fringe.pop_front();
                if(!explored[l])
                {
                Current.Expand(fringe);
                explored[l]++;
                }
            }
        }
       
    }
    void IDS(node root) {
        list<node> fringe;
        list<node> PathToSolution;
        map<list<int>,int>explored;
        bool GoalFound = false;
        int fringe_size=0;
        fringe.push_back(root);
        node Current=root;
         
        while(!GoalFound){
            fringe_size=fringe_size+fringe.size();
            //create a Queue
            //1- check if current is goal, if so then terminate
            list<node> Currentlevelnodes;
         
            while(!fringe.empty()){
                    
                Currentlevelnodes.push_front(fringe.back());
                Current=fringe.back();
                 if(Current.GoalTest()){
                    GoalFound=true;
                    break;
                }
                fringe.pop_back();}

            if(GoalFound)
            { 
                cout<<"The Goal Is Found Using the Iterative Deeping Search Algorithm\n";
                cout<<"Number of Generated nodes in the IDS: "<<explored.size()+fringe_size<<endl;
                cout<<"Number of Expanded nodes in the IDS: "<<explored.size()<<endl;
                cout<<"The Solution Found At Level: "<<Current.level<<endl;
                cout<<"The Number Of Steps: "<<Current.level<<endl;
                
                ///////////////////To find the path but it does not work correctly/////////////////////////////
                //int steps=0;
                   /*while(Current.parent!=NULL){
                        PathToSolution.push_front(Current);
                        
                        Current=*(Current.parent);
                        steps=steps+1;
                        if(steps>10)break;
                    }*/
                //////////////////////////////////////////////////////////////////////////////////////////////
                break;   
            }
            //2- else
            else
            {
                fringe.clear();
               for(list<node>::iterator it = Currentlevelnodes.begin(); it != Currentlevelnodes.end(); ++it){
                  list<int>l={it->a[0],it->a[1],it->a[2],it->a[3],it->a[4],it->a[5],it->a[6],it->a[7],it->a[8]};
                if(!explored[l])
                {
                it->Expand(fringe);
                explored[l]++;
                   
               }
               }
                Currentlevelnodes.clear();
            
            } 
         }
 
    }
    void Astar(node root){
        list<node> fringe;
        list<node> PathToSolution;
        map<list<int>,int>explored;
        bool GoalFound = false;
        
        //put the root in the fringe
        fringe.push_front(root);
        int g=0;
        node Current =root;
        while(!GoalFound){
          
            //put the front of the fringe in the current
            Current =fringe.front();
            //check if Current is goal
            GoalFound=Current.GoalTest();
            if(GoalFound)
            {
                cout<<"The Goal Is Found Using The A* Algorithm\n";
                cout<<"Number of Generated nodes in the A*: "<<explored.size()+fringe.size()<<endl;
                cout<<"Number of Expanded nodes in the A*: "<<explored.size()<<endl;
                cout<<"The Solution Found At Level: "<<Current.level<<endl;
                cout<<"The Number Of Steps: "<<Current.level<<endl;
                ///////////////////To find the path but it does not work correctly/////////////////////////////
                //int steps=0;
                   /*while(Current.parent!=NULL){
                        PathToSolution.push_front(Current);
                        
                        Current=*(Current.parent);
                        steps=steps+1;
                        if(steps>10)break;
                    }*/
                //////////////////////////////////////////////////////////////////////////////////////////////
                break;   
            }
            
            
            else
            {   //pop Current from front of the fringe
                list<int>l={Current.a[0],Current.a[1],Current.a[2],Current.a[3],Current.a[4],Current.a[5],Current.a[6],Current.a[7],Current.a[8]};
                fringe.pop_front();
                
                //if Current is not explored before exoplre it then add it to explored list
                if(!explored[l])
                {Current.ExpandAstar(fringe,g);
                
                explored[l]++;}
            }
           
        }
       
}
};



int main()
{

        searching algo;
        node root;
        cout << endl << "Initial state: " << endl;
        root.print();
    algo.BFS(root);
        cout<<endl;
        cout<<endl;
    algo.IDS(root);
        cout<<endl;
        cout<<endl;
    algo.Astar(root);
        return 0;
}
//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp
///
/// @author Aaron Nguyen [anguy112@ucr.edu]
/// @SID:861106832
/// @date May 25, 2015

//  ================== END ASSESSMENT HEADER ===============
#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <chrono>
#include <ctime>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;




//set and unordered_set have same member variables so use template
template<typename L>
void insertFind(float n, vector<string> list,L setType, float &findTime, float &insertTime)
{
    
    
    
    //insert
    chrono::time_point<chrono::system_clock> insertStart, insertEnd;
    
    //starts the clock
    insertStart = chrono::system_clock::now();
    for(unsigned i = 0; i < n; i++)
    {
        setType.insert(list.at(i));
    }
    insertEnd = chrono::system_clock::now(); //stop the clock
    
    auto elapsed_insert_Time = chrono::duration_cast<chrono::microseconds>(insertEnd - insertStart).count(); //total time it took
    
    insertTime = elapsed_insert_Time / n; //the average time
    
    //-----------------------------------------------------------------------------
    //find
    chrono::time_point<chrono::system_clock> findStart, findEnd;
    
    findStart = chrono::system_clock::now(); //start
    for(unsigned i = 0; i < n; i++)
    {
        setType.find(list.at(i));
    }
    findEnd = chrono::system_clock::now(); //stop
    
    auto elapsed_find_Time = chrono::duration_cast<chrono::microseconds>(findEnd - findStart).count(); //total time
    
    findTime = elapsed_find_Time / n; //average time
    
}


int main()
{
    
    vector<string> list;

    string word;
    ifstream wordfile("words.txt");
    
    srand(13);
    
    while (wordfile >> word)
    {
        list.push_back(word);
    }
    
    
    

     float n;
     set<string>TreeSet;
     float treeFindTime;
     float treeInsertTime;
     unordered_set<string>HashSet;
     float hashFindTime;
     float hashInsertTime;
     
     
    ofstream myfile;
    myfile.open ("data.txt");
   
    
    for(int i = 0; i < 10; i++)
    {
        //clear the sets after every loop
        TreeSet.clear();
        HashSet.clear();
        
        n = 5000 * (i+1);
    
       // random_shuffle ( list.begin(), list.end() );
        
        
        for(unsigned i = 0; i < list.size(); i ++)
        {
             
            swap(list.at(i), list.at(rand() % list.size()));
        }
        
        insertFind( n, list, TreeSet, treeFindTime, treeInsertTime);
        
        insertFind(n, list, HashSet, hashFindTime, hashInsertTime);
        
        //<n> <tree-insert-time> <hash-insert-time> <tree-query-time> <hash-query-time>
        myfile << n << " " << treeInsertTime << " " << hashInsertTime << " " << treeFindTime << " " << hashFindTime << endl;
        
    }
    
    myfile.close();
    
    
   return 0;

}






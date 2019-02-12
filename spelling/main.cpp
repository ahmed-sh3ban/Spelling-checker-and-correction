#include <iostream>
#include <string> 
#include <fstream>
#include "trie.h"
#include <ctime>
#include <ctype.h>
using namespace std;
int main(int argc , char* argv[])
{
        bool oneword = false;
        string SearchWord;
        ifstream myfile;
	ifstream myfilee;
         if(argc == 1)
         {
         
         myfile.open("/home/pixar/Desktop/spelling/Te.txt");
         myfilee.open("/home/pixar/Desktop/spelling/Tee.txt");
         }
         else if(argc == 2)
         {
         int i=0;
         myfile.open("/home/pixar/Desktop/spelling/Te.txt");
         oneword = true;
         SearchWord = (string) argv[1];
           while(argv[1][i])
           {
             SearchWord[i]=tolower(argv[1][i]);
             i++;
           }
         }
        
	else if(argc == 3)
	{
		//char* Dictionary =  argv[2];
		myfile.open(argv[1]);
		myfilee.open(argv[2]);
	}
	else
	{
	cout << "Please enter the value and the dictionary\n";
		return 1;
	
	}
	trie obj = trie();
	
	
	//
	
	int start_s;
	//	
        start_s=clock();
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{	
			char name[100];
			if(myfile >> name)
			obj.load(name);
			
		}
		if(oneword)
		{
		obj.check(SearchWord);
		
		obj.showData();
		}
		
		
                

	}
	else
		{
			cout << "sorry, couldnt open your file\n";
            return 1;
        }
        
        
    if(!oneword)
    {
	if (myfilee.is_open())
	{
		while (!myfilee.eof())
		{	
			char name[100];
			if(myfilee >> name)
			{
			int i =0;
		        	while(name[i])
                         {
                          name[i]=tolower(name[i]);
                          i++;
                          }
			  obj.check(name);
			}
			
			
		}
		
		obj.showData();
		//obj.D(SearchWord);
		
                

	}
	else
		{
			cout << "sorry, couldnt open your file2\n";
            return 1;
        }
    }

	int stop_s=clock();
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << endl;
	return 0;
}

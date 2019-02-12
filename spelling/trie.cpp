#include "trie.h"
#include <iostream>
#include <string> 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
using namespace std;

trie::trie()
{
	Head = new Node();
	wordcounts=0;
}


trie::~trie()
{
	 
}

void trie::load(char character[100])
{

	Node* Current = Head;

	string name = (string)character;

		for (int index = 0; index < name.length(); index++)
		{
			int ASCII = (int)tolower(character[index]) % 97;

			if (Current->children[ASCII] == NULL)
			{
				Current->children[ASCII] = new Node();
			}
			
			Current = Current->children[ASCII];

			if (index == name.length() - 1)
			{
				Current->isword = true;
				Current->word = name;
				Current->counter++;
				
				
			}
			
		}
	

}
void trie::check(string checkword)

{
  Node* current=Head;
  bool found = false;
  for(int i=0;i<checkword.length();i++)
  {

      int ascii=(int)tolower(checkword[i]) % 97;
      
      if(current->children[ascii] == NULL )
      {
       
        //cout<<"Sorry word not found\n";
        break;
      }

      else

      {
         current = current->children[ascii];
      }
       if(i == checkword.length()-1)

         {
             if(current->isword==true)
             {
           
              // cout << "Word Found\n";
               found = true;
               
       
                break;
            }
           else
           {
             // cout<<"Sorry word not found\n";
            
              setofvalidwords[checkword];
               break;

           }
         }


    }
    if(!found)
    {
     GetTotalwordsNumber(checkword);
      
    }
    
}


void trie::GetTotalwordsNumber(string checkword)
{

  wordcounts = getAllrealwords(Head , 0 , checkword);
 
 
}


int trie::getAllrealwords(Node* current , int count, string checkword)
{
  char Word[100];
  char Wrong[100];
  
 int count1;

 if(current->isword==true)
  {

    int repeated = current->counter;
    strcpy(Word,(current->word).c_str());
    strcpy(Wrong,checkword.c_str());
    Levenshtine(Wrong,Word,repeated);
    count++;
  }

  for(int x =0; x<26;x++)
  {
  
   if(current->children[x] != NULL)   
    { 
      count= getAllrealwords(current->children[x], count,checkword); 
    }
    
    else continue;
  }
   


return count;


} 

void trie :: Levenshtine(char Invalidword[100],char Validword[100],int repeated)
{
  

 size_t len1 = strlen(Validword);
 size_t len2 = strlen(Invalidword);
 float Limit = ceil(len2*0.25);


 int matrix [len1+1][len2+1];

 for(int fillrow = 0; fillrow  <= len1; fillrow++)
 matrix[fillrow][0] = fillrow;

 for(int fillcol = 0; fillcol  <= len2; fillcol++)
 matrix[0][fillcol] = fillcol;

 for(int row = 1; row <= len1;row++)
 {
    for(int col =1; col <= len2;col++)
    { 

      if( Validword[row-1]==Invalidword[col-1] )
      {
        matrix[row][col] =  matrix[row-1][col-1];
      }
      else
      {
    
        matrix[row][col] = min(matrix[row-1][col-1]+1, // Substitution
        min(matrix[row-1][col]+1 // Delete
       ,matrix[row][col-1]+1)); // Insert
   
      }

    }
 }
 int editDistance = matrix[len1][len2];

 if(editDistance <= Limit)
 {
 Word w;
    w.correction = Validword;
    w.repeated   = repeated;  
    w.percent = (len1 - editDistance) * 10;
   setofvalidwords[Invalidword].push_back(w);
 }
}

void trie::showData()
{

  for (map< string,vector<Word> >::const_iterator it =  setofvalidwords.begin(); it !=  setofvalidwords.end(); it++)
        {

          cout <<"The correction of word: " << it->first <<endl;
      
             for(int x =0; x < (it->second).size();x++)
             {
            int TruePrecent = (it->second)[x].percent + ((float)(it->second)[x].repeated/ (float)wordcounts)*100;
                 cout << (it->second)[x].correction <<"\t Percent: "<< TruePrecent <<"\tRepeated:   "<<(it->second)[x].repeated<< endl;
             } 
          cout << endl;
         }

}







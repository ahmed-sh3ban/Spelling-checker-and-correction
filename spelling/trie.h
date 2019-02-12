#include <string> 
#include <vector>
#include <map>
#ifndef TRIES
#define TRIES


class trie
{
public:
	struct Node
	{
		bool isword;
		Node* children[27];
		std::string word;
		int counter;
	};
	
	struct Word
	{
	std::string correction;
	int percent;
	int repeated;
	};
	void load(char character[100]);
	void check(std::string);
	void correct();
	void unload();
	int  getAllrealwords(Node* current , int count, std::string checkword);
	void GetTotalwordsNumber(std::string checkword);
	void Levenshtine(char Invalidword[100],char Validword[100],int repeated);
	void showData(void);
	void sortingAnddisplay(std::vector<Word>v);
	trie();
	~trie();

private:
	Node* Head;
	std::map< std::string, std::vector<Word> > setofvalidwords;
	int wordcounts;
	
};

#endif // !TRIES

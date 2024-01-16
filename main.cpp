/*
 * Name:            Noah Nininger
 * Date Submitted:  03/06/23
 * Lab Section:     001
 * Assignment Name: Spell Checker Using a Hash Table
 */
 
 #include "stringset.h"
 #include <iostream>
 #include <fstream>
 
 void testStringset(Stringset& words);
 void loadStringset(Stringset& words, string filename);
 vector<string> spellcheck(const Stringset& words, string word);
 /*
 int main()
 {
     Stringset wordlist;
     testStringset(wordlist);
     return 0;
 }*/
 
 void testStringset(Stringset& words)
 {
     string choice;
     string word;
     do
     {
         cout << "I: insert word" << endl;
         cout << "F: find word" << endl;
         cout << "R: remove word" << endl;
         cout << "P: print words in stringset" << endl;
         cout << "Q: quit" << endl;
         cin >> choice;
         switch (choice[0])
         {
             case 'I':
             case 'i':
                cout << "Enter word to insert: ";
                cin >> word;
                words.insert(word);
                break;
             case 'F':
             case 'f':
                cout << "Enter word to find: ";
                cin >> word;
                if (words.find(word))
                {
                    cout << word << " in stringset" << endl;
                }
                else
                {
                    cout << word << " not in stringset" << endl;
                }
                break;
             case 'R':
             case 'r':
                cout << "Enter word to remove: ";
                cin >> word;
                words.remove(word);
                break;
             case 'P':
             case 'p':
                vector<list<string>> t = words.getTable();
                int numWords = words.getNumElems();
                int tSize = words.getSize();
                for(int i=0; i<tSize; ++i)
                {
                    list<string>::iterator pos;
                    for (pos = t[i].begin(); pos != t[i].end(); ++pos)
                    {
                        cout << *pos << endl;
                    }
                }
                cout << "Words: " << numWords << endl;
         }
     } while (choice[0] != 'Q' && choice[0] != 'q');
 }
 

 // implement these functions
 void loadStringset(Stringset& words, string filename)
 {
 // creates an object to read file info and creates variable for the current
 // word in a string
    std::ifstream in(filename);
    std::string current;

    while(std::getline(in, current))    // inserts into stringset
        { words.insert(current); }
 }
 
 vector<string> spellcheck(const Stringset& words, string word)
 {
    vector<string> spellCorrecter; // vector to hold possible alternatives
    string newWord = word; // variable to test alternate character on

 // loops through each character
    for (long unsigned int i = 0; i < word.length(); i++)
    {
        for (char j = 'a'; j < 'z' + 1; j++)
        {
         // copies the word with a data at index
            newWord.replace(i, 1, 1, j);

         // if newWord is in the string set AND isn't the original word
            if (newWord != word && words.find(newWord))
                { spellCorrecter.push_back(newWord); }

            newWord = word;
        }
    }

    return spellCorrecter;
 }

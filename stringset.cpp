/*
 * Name:            Noah Nininger
 * Date Submitted:  03/06/23
 * Lab Section:     001
 * Assignment Name: Spell Checker Using a Hash Table
 */

#include "stringset.h"

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const
{
    return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
    return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
    return size;
}



// implement these functions
void Stringset::insert(string word)
{
    if (!find(word))    // ensures word isn't in string set
    {
        int location;
        string word1;
        std::hash<std::string> hash;

        if (num_elems >= size)      // ensures max size
        {
            size *= 2;
            vector<list<string>> v(size);   // vector for new hash table

         // re-hashes each value in a new vector
            for (int i = 0; i < size / 2; i++) 
            {
                for(list<string>::const_iterator j = table[i].begin(); 
                                                 j != table[i].end(); ++j) 
                {
                    word1 = *j;
                    location = hash(word1) % size;
                    v[location].push_back(word1);
                    table[i].remove(word);
                }
            }
            table = v; // assigns the old table to the new table
        }

        location = hash(word) % size;
        table[location].push_back(word);
        num_elems++;
    }
}

bool Stringset::find(string word) const
{
    std::hash<std::string> hash;
    int location = hash(word) % size;

 // loops through list
    for(list<string>::const_iterator i = table[location].begin();
                                     i != table[location].end(); ++i) 
    {
        if (*i == word) // if word is found
            { return true; }
    }

    return false;
}

void Stringset::remove(string word)
{
    if (find(word))     // ensures word is in list
    {
        std::hash<std::string> hash;
        int location = hash(word) % size;
        table[location].remove(word);    // removes word
        num_elems--;        // reduces size
    }
}

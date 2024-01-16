/*
 * Name:            Noah Nininger
 * Date Submitted:  03/06/23
 * Lab Section:     001
 * Assignment Name: Spell Checker Using a Hash Table
 */

#pragma once

#include <string>
#include <vector>
#include <list>
using namespace std;

//Stringset class, do not modify definitions for existing members
class Stringset
{
    private:
        vector<list<string>> table;
        int num_elems;
        int size;
    public:
        Stringset();
        vector<list<string>> getTable() const;
        int getNumElems() const;
        int getSize() const;
        void insert(string word);
        bool find(string word) const;
        void remove(string word);
};

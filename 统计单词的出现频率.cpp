#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

class WordsFrequency {
public:
    unordered_map<string, int> mydic;
    WordsFrequency(vector<string>& book) {
        for (string i : book)
            mydic[i]++;
    }

    
    int get(string word) {
        return mydic[word];
    }
};


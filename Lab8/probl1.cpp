#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>

struct WordCompare
{
    bool operator() (const std::pair<std::string, int>& firstWord, const std::pair<std::string, int>& secondWord)
    {
        if (firstWord.second != secondWord.second)
        {
            return firstWord.second < secondWord.second;
        }
        else
        {
            return firstWord.first > secondWord.first;
        }
    }
};

void fixString(std::string& word) {
    std::string separators = " ,?!.\n";
    for (int i = 0; i < word.length(); i++) {
        if (separators.find(word[i]) != separators.npos) {
            word.erase(i, 1);
            i--;
        }
    }
}

void toLowerCase(std::string& word) {
    for (int i = 0; i < word.length(); i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            char ch = word[i];
            word.erase(i, 1);
            word.insert(i, 1, (ch - ('A' - 'a')));
        }
    }
}

int main()
{
    std::map<std::string, int> word_map;
    std::ifstream input("input.txt");
    for (std::string word; getline(input, word, ' ');) {
        fixString(word);
        if (word.length() != 0) {
            toLowerCase(word);
            if (word_map.find(word) != word_map.end()) {
                word_map[word] += 1;
            }
            else {
                word_map[word] = 1;
            }
        }
    }
    input.close();

    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, WordCompare> sortedWords(word_map.begin(), word_map.end());
    while (!sortedWords.empty())
    {
        std::pair<std::string, int> outputWord = sortedWords.top();
        std::cout << outputWord.first << " => " << outputWord.second << std::endl;
        sortedWords.pop();
    }
    return 0;
}

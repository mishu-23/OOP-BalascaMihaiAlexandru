#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <cctype>

struct WordCount {
    std::string word;
    int count;
    bool operator<(const WordCount& other) const {
        if (count != other.count) {
            return count < other.count;
        }
        return word > other.word;
    }   
};

int main() {
    std::ifstream file("in.txt");
    std::string phrase;
    std::getline(file, phrase);
    file.close();

    std::map<std::string, int> wordCount;
    size_t start = 0;
    size_t end = phrase.find_first_of(" ,.!?");

    while (end != std::string::npos) {
        std::string word = phrase.substr(start, end - start);
        if (!word.empty()) {
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            ++wordCount[word];
        }
        start = end + 1;
        end = phrase.find_first_of(" ,.!?", start);
    }

    std::priority_queue<WordCount> sortedWords;
    for (auto pair : wordCount) {
        WordCount a;
        a.count = pair.second;
        a.word = pair.first;
        sortedWords.push(a);
    }

    while (!sortedWords.empty()) {

        auto pair = sortedWords.top();
        std::cout << pair.word << " => " << pair.count << '\n';
        sortedWords.pop();
    }

    return 0;
}
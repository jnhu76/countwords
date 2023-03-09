#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <cctype>


int main(int argc, char* argv[]) {
    if (argc != 2) {
        return -1;
    }
    std::string filename = argv[1];
    std::string word;
    std::ifstream infile(filename);

    std::map<std::string, int> counts;

    while (infile >> word) {
        std::transform(word.begin(), word.end(), word.begin(),
        [](unsigned char c){return std::tolower(c);});
        counts[word]++;
    }

    std::vector<std::pair<std::string, int>> ordered(counts.begin(), counts.end());

    std::sort(ordered.begin(), ordered.end(),
    [](auto const& a, auto const& b) {return a.second > b.second;});

    for (auto const& elem: ordered) {
        std::cout << elem.first << ": " << elem.second << "\n";
    }

    return 0;
}

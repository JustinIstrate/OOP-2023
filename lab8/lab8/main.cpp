#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>

struct cmp {
    bool operator()(std::map<std::string, int>::iterator x1, std::map<std::string, int>::iterator x2) {
        if (x1->second < x2->second)
            return true;
        if (x1->second > x2->second)
            return false;
        if (x1->first < x2->first)
            return false;
        return true;
    }
};
int main() {
    std::ifstream in("input.txt");

    std::string text;
    std::getline(in, text);
    std::string aux;
    std::vector<std::string> v;
    std::map<std::string, int> m;
    for (unsigned i = 0; i < text.size(); i++) {
        if (text[i] == ' ' || text[i] == ',' || text[i] == '?' || text[i] == '!' || text[i] == '.') {
            while (text[i] == ' ' || text[i] == ',' || text[i] == '?' || text[i] == '!' || text[i] == '.')
                i++;
            i--;
            v.push_back(aux);
            m[aux]++;
            aux = "";
        } else if (text[i] >= 'A' && text[i] <= 'Z')
            aux += text[i] + 32;
        else
            aux += text[i];
    }
    std::priority_queue<
          std::map<std::string, int>::iterator,
          std::vector<std::map<std::string, int>::iterator>,
          cmp>
          p;
    std::map<std::string, int>::iterator it = m.begin();
    while (it != m.end()) {
        p.push(it);
        it++;
    }
    while (!p.empty()) {
        std::cout << p.top()->first << " => " << p.top()->second<< std::endl;
        p.pop();
    }
}
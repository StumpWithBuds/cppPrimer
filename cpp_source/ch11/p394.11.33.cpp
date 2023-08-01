#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>

std::map<std::string, std::string> build_map(std::ifstream&);
const std::string& transform(const std::string&, const std::map<std::string, std::string>&);

void word_transform(std::ifstream& map_file, std::ifstream& input) {
    std::map<std::string, std::string> trans_map = build_map(map_file);
    std::string text;
    while(getline(input, text)){
        std::istringstream stream(text);
        std::string word;
        bool first_word = true;
        while (stream >> word) {
            if (first_word)
                first_word = false;
            else
                std::cout << " ";

            std::cout << transform(word, trans_map);
        }
        std::cout << std::endl;
    }
}

std::map<std::string, std::string> build_map(std::ifstream& map_file) {
    std::map<std::string, std::string> trans_map;
    std::string key, value;
    // while (map_file >> key && getline(map_file, value)) {
    while (map_file >> key && map_file >> value) {
        if (value.size() > 0) {
            // trans_map[key] = value;
            // trans_map.insert({key, value.substr(1)});
            trans_map.insert({key, value});
        }
        // else 
        //     throw runtime_error("no rule for " + key);
    }
    return trans_map;
} 

const std::string& transform(const std::string& s, const std::map<std::string, std::string>& m) {
    std::map<std::string, std::string>::const_iterator iter = m.find(s);
    if (iter != m.cend()){
        return iter->second;
    }
    else 
        return s;
}

int main() {
    std::ifstream code_file("./code_file.txt"), map_file("./map_file.txt");
    // std::cout << "good " << std::endl;
    word_transform(map_file, code_file);
    return 0;
}
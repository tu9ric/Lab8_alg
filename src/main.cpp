#include <iostream>
#include "Index.h"
#include <filesystem>

std::set<std::string> brute_search(const std::string& key, const std::vector<std::string>& paths)
{
    std::set<std::string> docs; 
    std::string word;
    for(const auto& path: paths)
    {
        std::ifstream file(path);
        while(std::getline(file, word, ' '))
        {
            Index::normalize(word);
            if(word == key)
            {
                docs.insert(path);
                continue;
            }
        }
    }
    return docs;
}

int main(int, char**){
    Index books;
    std::string folder = "C:\\Users\\artem\\OneDrive\\Desktop\\Study\\alg_and_structcures\\LAB8\\docs";
    std::vector<std::string> paths;
    std::string word = "you";
    for(const auto & entry : std::filesystem::directory_iterator(folder))
    {
        paths.push_back(std::string(entry.path().string()));
    }
    books.add_files(paths);
    
    for(const auto& doc: books[word])
    {
        std::cout << word << " -> " << doc << std::endl;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    for(const auto& doc: brute_search(word, paths))
    {
        std::cout << word << " -> " << doc << std::endl;
        std::cout << std::endl;
    }


}

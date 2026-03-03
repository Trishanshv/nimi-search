#include"parser.h"
#include<fstream>
#include<sstream>
#include<cctype>
#include<unordered_set>

std::string Parser::normalize(const std::string&text){
    std::string norm;
    for(char c: text){
        if(std::isalpha(static_cast<unsigned char>(c))) norm.push_back(std::tolower(c));
        else
        norm.push_back(' ');
    }
    return norm;
}

bool Parser::isStopWord(const std::string& word){
    return m_stopwords.find(word) != m_stopwords.end();
}

DynamicArray<std::string> Parser::tokenizer(const std::string& text){
    std::string norm = normalize(text);
    std::istringstream iss(norm);

    DynamicArray<std::string> tokens;
    std::string word;
    while(iss >> word){
        if(!isStopWord(word)) tokens.push_back(word);
    }
    return tokens;
}

Parser::Parser(const std::string& stopwordFile){
    std::ifstream file (stopwordFile);
    std::string w;
    while(file >> w){
        m_stopwords.insert(w);
    }
}
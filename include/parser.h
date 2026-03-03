#ifndef PARSER_H
#define PARSER_H

#include<string>
#include"dynamic_array.h"
#include<unordered_set>

class Parser{
std::unordered_set<std::string> m_stopwords;
std::string normalize(const std::string& word);
bool isStopWord(const std::string& word); 

public:
    Parser(const std::string& stopwordFile="config/stopwords.txt");
    DynamicArray<std::string> tokenizer(const std::string& text);

};

#endif
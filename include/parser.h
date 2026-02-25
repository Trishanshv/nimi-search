#ifndef PARSER_H
#define PARSER_H

#include<string>
#include"dynamic_array.h"
#include<unordered_set>

class Parser{
std::unordered_set<std::string> m_stopwords;
std::string normalize(const std::string& word);
static bool isStopWord(const std::string& word, const std::string& stopwordFile); 

public:
    Parser(const std::string& stopwordFile="config/stopwords.txt");
    static DynamicArray<std::string> tokenizer(const std::string& text, const std::string& stopwordFile = "config/stopwords.txt");

};

#endif
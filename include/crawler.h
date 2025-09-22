#ifndef CRAWLER_H
#define CRAWLER_H

#include <string>
#include "dynamic_array.h"

struct Document {
    int docID;
    std::string content;
    std::string path;
};

DynamicArray<Document> crawler(const std::string& startPath, int maxDepth);

#endif
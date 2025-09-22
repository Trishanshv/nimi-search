#include "crawler.h"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>
#include <queue>

namespace fs = std::filesystem;

struct DirAndDepth {
    fs::path path;
    int depth;
};

static std::string  readFile(const fs::path& filepath){
    
}

DynamicArray<Document> crawl_folder(const std::string& startPath,int depth){
    DynamicArray<Document> readDocs;
    std::queue<DirAndDepth> q;

    q.push({fs::path(startPath),0});
    int docID=0;
    
    while(!q.empty()){
        DirAndDepth current=q.front();
        q.pop();
        if(current.depth>depth) continue;

        for(const auto& entry:fs::directory_iterator(current.path)){
            try
            {
                if(entry.is_directory()){
                    q.push({entry.path(),current.depth+1});
                }
                else if(entry.is_regular_file() && entry.path().extension()==".txt"){
                    Document doc;
                    doc.docID=docID++;
                    doc.path =entry.path().string();
                    doc.content=readFile(entry.path());
                    readDocs.push_back(std::move(doc));
                }
            }
            catch(const std::exception& e){std::cerr << e.what() <<'file Path:-'<<entry.path()<<'\n';}
        }
    }
    return readDocs;
}
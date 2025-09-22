#include <iostream>
#include <string>
#include "crawler.h"

int main(int argc, char** argv) {
    std::string startPath = (argc>1)? argv[1]:"../data";
    std::cout<<"Crawling Folder:"<<startPath<<'\n';

    DynamicArray<Document> docs=crawl_folder(startPath,2);

    size_t siz=docs.Size();
    std::cout<<"Crawled "<<siz<<" documents\n";
    for(size_t i=0;i<siz;i++){
        std::cout<<"Document ID: "<<docs[i].docID<<", Path: "<<docs[i].path<<", Content Size: "<<docs[i].content.size()<<'\n';
    }
}

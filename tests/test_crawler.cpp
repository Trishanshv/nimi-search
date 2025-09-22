#include<cassert>
#include "crawler.h"
#include <iostream>

int main(){
    DynamicArray<Document> docs=crawl_folder("../data",1);
    assert(docs.Size()>0);
    std::cout<<"[TEST] Crawler found "<<docs.Size()<<" documents\n";
    return 0;
}
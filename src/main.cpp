#include <iostream>
#include <string>

int main(int argc, char** argv) {
    std::string banner = "Mini Search Engine ready";
    // Show how to pass optional config (example)
    std::cout << banner << std::endl;
    if (argc > 1) {
        std::cout << "Config/path: " << argv[1] << std::endl;
    } else {
        std::cout << "Run: mini_search_engine <path-to-docs> (optional)" << std::endl;
    }
    return 0;
}

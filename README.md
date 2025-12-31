# Nimi Search

A Mini Search Engine in C++ (From Scratch, No STL Vector)Nimi-Search is a low-level, educational search engine implemented in modern C++ for Windows (MinGW).
The project is designed to demonstrate core search-engine internals—such as crawling, tokenization, indexing, ranking, caching, and query processing—built without using std::vector,
relying instead on custom memory-managed containers. This project focuses strictly on systems-level data structures and algorithms rather than frameworks.

---

##Project Status

ModuleStatusCMake Build System| Completed
Project Architecture & Layout| Completed
Custom Dynamic Array (replaces std::vector)| Completed
BFS Folder Crawler (depth-limited)| Completed
Text File Loader| Completed
Raw Document Ingestion| Completed
Tokenizer + Normalizer + Stopword Removal| Completed
Test Harnesses| Completed

##Project Architecture

```
Plaintextnimi-search/
├── src/
│   ├── main.cpp           - Entry point
│   ├── crawler.cpp        - BFS traversal logic
│   └── parser.cpp         - Text normalization & tokenization
├── include/
│   ├── crawler.h          - Crawler definitions
│   ├── parser.h           - Parser definitions
│   └── dynamic_array.h    - Custom memory-managed container
├── config/
│   └── stopwords.txt      - List of words to filter
├── data/
│   └── *.txt              - Sample corpus
├── tests/
│   └── test_parser.cpp    - Unit tests
├── bench/                 - Benchmarking tools
└── CMakeLists.txt         - Build configuration
```

##Build Instructions (Windows / MinGW)

```
RequirementsCMake ≥ 3.10MinGW-w64 (GCC)C++17 enabledBuild StepsCreate a build directory and generate Makefiles:Bashmkdir build
cd build
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
Compile the project:Bashmingw32-make
RunTo run the engine against a data directory:Bash./nimi_search.exe data
```
## How It Works

When you run the executable,
the engine performs the following pipeline:BFS Crawling: Performs a Breadth-First Search on the target folder up to the configured depth.
Discovery: Identifies .txt files in the directory tree.
Ingestion: Loads full file contents into memory.
Processing: Normalizes text (lowercasing, punctuation removal) and tokenizes the content.
Filtering: Applies stop-word filtering using config/stopwords.txt.
Output: Prints discovered document paths and prepares data for indexing.

---
### Design Principles

No std::vector: Utilizes custom manual memory management to demonstrate understanding of heap allocation and resizing logic.
Systems-Level Focus: Prioritizes raw pointers and custom containers over high-level STL abstractions where educational value is high.
BFS Traversal: Implements graph traversal algorithms for file system crawling.Clean Architecture: Modular separation of concerns (Crawler vs. Parser vs. Data Structures).
Warning-Clean: Compiles with -Wall -Wextra for strict code quality.

## Roadmap (In Progress)

The following modules are currently in development to transition from a crawler to a full search engine:
```
[ ] Inverted Index: Mapping tokens to document IDs (Posting lists).
[ ] Trie-based Autocomplete: Efficient prefix search for query suggestions.
[ ] Ranking Algorithms: TF-IDF scoring and Top-K retrieval.
[ ] Spell Correction: Levenshtein distance implementation.
[ ] Caching: LRU (Least Recently Used) cache for frequent queries.
[ ] Advanced Scoring: Bloom Filters and PageRank.
[ ] Interactive Shell: CLI for user search queries.
[ ] Profiling: Benchmarks for memory usage and speed.
```

## Why This Project Exists
This project is intentionally built from scratch to demonstrate:Deep understanding of memory layouts and pointer arithmetic.Low-level container design (implementation of dynamic arrays).Core information-retrieval algorithms (Indexing, Ranking, Tokenizing).Performance-aware C++ development

---

    // A note on the name:
    if (you.wondering() || you.assumed(TYPO)) {
        return "Sorry to say this, but I have a very bad naming sense.";
    }

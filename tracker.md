# Nimi Search Tracker

Last updated: 2026-02-26

## 1) Repository Audit (completed)

Reviewed project files:
- Core: `CMakeLists.txt`, `README.md`
- Config/editor: `.gitignore`, `.gitattributes`, `.vscode/*`
- Source: `src/main.cpp`, `src/crawler.cpp`, `src/parser.cpp`
- Headers: `include/crawler.h`, `include/dynamic_array.h`, `include/parser.h`
- Tests: `tests/test_crawler.cpp`
- Data corpus: `data/sample_01.txt` ... `data/sample_10.txt`

Not included for planning detail (generated artifacts):
- `build/**` (CMake-generated files, objects, executable)

## 2) Current State Snapshot

### Working
- BFS folder crawl for `.txt` files is implemented.
- Document ingestion (path + content) is implemented.
- Custom `DynamicArray<T>` is used in crawler path.
- Basic crawler test exists (`tests/test_crawler.cpp`).

### Gaps / Risks found
- `parser.cpp` is not currently part of the executable build in `CMakeLists.txt`.
- Parser API/implementation mismatch:
	- `Parser::tokenizer` is `static` but calls `normalize` that is non-static.
	- `isStopWord` implementation is commented out but still referenced.
- README status claims parser pipeline is completed, but code/build integration is incomplete.
- `data/*` is ignored by git (except `.gitkeep`), so sample corpus may differ across machines.

## 3) Project Phases

## Phase 0 — Stabilize Baseline
**Goal:** Ensure current code compiles cleanly and matches documented behavior.

Tasks:
- [ ] Add `src/parser.cpp` to CMake target.
- [ ] Fix parser API consistency (`static` vs instance methods).
- [ ] Restore working stopword logic (or adjust interface).
- [ ] Build with warnings enabled and resolve parser-related compile errors.
- [ ] Update README status table to reflect actual state.

Exit criteria:
- `nimi_search` builds successfully from clean `build/`.
- Parser module compiles and links.

## Phase 1 — Parser Quality & Tests
**Goal:** Make tokenization/normalization reliable and testable.

Tasks:
- [ ] Add parser-focused tests (`tests/test_parser.cpp`).
- [ ] Test normalization rules (case, punctuation, symbols).
- [ ] Test stopword filtering behavior.
- [ ] Test edge cases (empty text, whitespace-only, mixed punctuation).

Exit criteria:
- Parser tests pass consistently.
- Behavior documented in README with short examples.

## Phase 2 — Inverted Index MVP
**Goal:** Build searchable index from crawled documents.

Tasks:
- [ ] Define index structures (`term -> posting list(docID, tf)`).
- [ ] Index all crawled docs using parser output.
- [ ] Add simple query function (single-term + AND semantics).
- [ ] Add deterministic result ordering for reproducible output.

Exit criteria:
- Query returns matching document IDs/paths from sample corpus.
- Basic index tests cover build + lookup behavior.

## Phase 3 — Ranking (TF/TF-IDF)
**Goal:** Return most relevant results first.

Tasks:
- [ ] Implement TF scoring baseline.
- [ ] Add IDF and TF-IDF score calculation.
- [ ] Add top-k retrieval API.
- [ ] Validate ranking with controlled sample queries.

Exit criteria:
- Ranked top-k output exists for multi-term queries.
- Scoring logic covered by unit tests.

## Phase 4 — Query UX (CLI)
**Goal:** Usable interactive search loop.

Tasks:
- [ ] Implement CLI REPL (`search> ...`).
- [ ] Add help/exit commands.
- [ ] Print concise ranked results (docID, score, path).
- [ ] Add command-line options (data path, depth, top-k).

Exit criteria:
- User can index + search in one run from terminal.

## Phase 5 — Performance Features
**Goal:** Improve responsiveness and scalability.

Tasks:
- [ ] Add query-result LRU cache.
- [ ] Add trie-based autocomplete for prefixes.
- [ ] Add optional spell-correction prototype (Levenshtein).
- [ ] Create benchmark harness in `bench/`.

Exit criteria:
- Benchmarks report indexing time, query latency, and memory footprint.

## Phase 6 — Hardening & Packaging
**Goal:** Make project reproducible and contributor-friendly.

Tasks:
- [ ] Document full build/run/test steps in README.
- [ ] Add CI-friendly test command and layout.
- [ ] Ensure cross-machine path handling works.
- [ ] Clean up naming/consistency in docs and symbols.

Exit criteria:
- Fresh clone can build, test, and run with documented commands.

## 4) Immediate Next Actions (recommended)

1. Complete **Phase 0** first (parser + CMake integration).
2. Add parser tests from **Phase 1** before indexing work.
3. Start inverted index MVP only after parser behavior is locked.

---

## 5) Progress Board

- [x] Repository audit completed.
- [ ] Phase 0 started.
- [ ] Phase 1 started.
- [ ] Phase 2 started.
- [ ] Phase 3 started.
- [ ] Phase 4 started.
- [ ] Phase 5 started.
- [ ] Phase 6 started.

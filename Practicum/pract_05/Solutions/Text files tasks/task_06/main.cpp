#include <iostream>
#include <fstream>

const constexpr int MAX_RELATION_SIZE = 25;

struct Pair {
    int x;
    int y;
};

struct Relation {
    int size;
    Pair pairs[MAX_RELATION_SIZE];
};

void writePairToFile(std::ofstream& ofs, const Pair& pair) {
    if (!ofs.is_open()) {
        return;
    }
    ofs << pair.x << ' '<< pair.y << std::endl;
}

Pair readPairFromFile(std::ifstream & ifs) {
    Pair pair;
    if (!ifs.is_open()) {
        return pair;
    }

    ifs >> pair.x >> pair.y;
    return pair;
}

void writeRelationToFile(std::ofstream& ofs, const Relation& relation) {
    if (!ofs.is_open()) {
        return;
    }

    ofs << relation.size << std::endl;
    for (int i = 0; i < relation.size; ++i) {
        writePairToFile(ofs, relation.pairs[i]);
    }
}

Relation readRelationFromFile(std::ifstream& ifs) {
    Relation relation;

    ifs >> relation.size;
    for (int i = 0; i < relation.size; ++i) {
        relation.pairs[i] = readPairFromFile(ifs);
    }
    return relation;
}
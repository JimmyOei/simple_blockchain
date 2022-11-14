#ifndef BLOCK_H
#define BLOCK_H

#include "transaction.h"

#include <cstddef>

struct Block {
    Transaction transactions;

    std::size_t prevHash;

    Block(Transaction transactions, std::size_t prevHash): transactions(transactions), prevHash(prevHash) {};
    Block(): transactions(Transaction()), prevHash(std::size_t()) {};
};

#endif
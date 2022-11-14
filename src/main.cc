#include "../include/transaction.h"
#include "../include/block.h"

#include <cstddef>
#include <iostream>
#include <vector>
#include <functional>
#include <memory>

std::vector<Block> blockchain;

void broadcast(Transaction tx) {
    Block* curr = &blockchain.back();
    std::hash<std::size_t> hasher;
    blockchain.push_back(Block(tx, hasher(hasher(curr->prevHash)  
                                                 + hasher(hasher(curr->transactions.quantity) 
                                                                 + hasher(curr->transactions.sender) 
                                                                 + hasher(curr->transactions.receiver)))));
}

void printBlockchain() {
    std::hash<std::size_t> hasher;
    for(int i =0; i < blockchain.size(); i++) {
        std::cout << "Block " << i << ": " << std::endl;
        std::cout << "transaction: " << blockchain[i].transactions.sender << " -- " << blockchain[i].transactions.quantity << " --> " << blockchain[i].transactions.receiver << std::endl;
        std::cout << "Hash: " << hasher(hasher(blockchain[i].prevHash)  
                                                 + hasher(hasher(blockchain[i].transactions.quantity) 
                                                                 + hasher(blockchain[i].transactions.sender) 
                                                                 + hasher(blockchain[i].transactions.receiver))) << std::endl;
        std::cout << "prevHash " << blockchain[i].prevHash << std::endl;
    }
}

void menu() {
    bool quit = false;
    while(!quit) {
        std::cout << std::endl << "[MENU] 0: input transaction, 1: print chain, 2: quit" << std::endl;
        int input;
        std::cin >> input;
        switch(input) {
            case 0:
                broadcast(inputTransaction());
                break;
            case 1:
                printBlockchain();
                break;
            case 2:
                quit = true;
                break;
        }
    }
}

int main() {
    blockchain.push_back(Block()); //genesis

    menu();

    return 0;
}
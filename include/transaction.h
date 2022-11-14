#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <cstddef>
#include <iostream>

struct Transaction {
    std::size_t receiver;

    std::size_t sender;

    std::size_t quantity;

    Transaction(): receiver(std::size_t()), sender(std::size_t()), quantity(std::size_t()) {};
    Transaction(std::size_t receiver, std::size_t sender, std::size_t quantity): receiver(receiver), sender(sender), quantity(quantity) {};
};

Transaction inputTransaction() {
    std::size_t receiver;
    std::size_t sender;
    std::size_t quantity;

    std::cout << "Input sender: " << std::endl;
    std::cin >> sender;
    std::cout << "Input quantity: " << std::endl;
    std::cin >> quantity;
    std::cout << "Input receiver: " << std::endl;
    std::cin >> receiver;

    return Transaction(receiver, sender ,quantity);
}

#endif
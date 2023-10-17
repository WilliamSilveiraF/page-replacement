#include "manager.h"
#include <vector>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <number_of_frames>" << std::endl;
        return 1;
    }

    int numberOfFrames = std::stoi(argv[1]);
    std::vector<int> pages;
    int page;
    
    while (std::cin >> page) {
        pages.push_back(page);
    }

    int totalPages = pages.size();
    Manager manager(numberOfFrames);

    std::cout << numberOfFrames << " quadros" << std::endl;
    std::cout << totalPages << " refs" << std::endl;
    manager.executeFIFO(pages.data(), totalPages);
    manager.executeLRU(pages.data(), totalPages);
    manager.executeOPT(pages.data(), totalPages);
    
    return 0;
}

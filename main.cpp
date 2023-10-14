#include "manager.h"

int main() {
    int pages[] = {0, 1, 7, 2, 3, 2, 7, 6, 5, 7, 2};
    Manager manager(4);
    
    manager.executeFIFO(pages, sizeof(pages)/sizeof(pages[0]));
    manager.executeLRU(pages, sizeof(pages)/sizeof(pages[0]));
    manager.executeOPT(pages, sizeof(pages)/sizeof(pages[0]));
    
    return 0;
}

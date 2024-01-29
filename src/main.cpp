#pragma once
#include "Liste/Liste.h"
#include <iostream>

int main() {

    List<int> l;

    l.printList();
     
    std::cout << "highest : " << l.getHighest() << std::endl;

    List<int> b(l);

    b.printList();

    std::cout << l.length() << std::endl;
    std::cout << b.length() << std::endl;
    
    l.clear();

    std::cout << "b : ";
    b.printList();

    std::cout << "l : ";
    l.printList();

    std::cout << "length l : ";
    std::cout << l.length() << std::endl;
    
    return 0;
}
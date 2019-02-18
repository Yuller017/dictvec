#include <iostream>
#include <string>

#include "dictvec.h"

int main()
{
    Dictvec<std::string, double> dv1, dv2;
    dv1.add("aaa", 1);
    dv1.add("bbb", 2);
    dv1.add("ccc", 3);
    dv1.add("ddd", 4);
    dv1.add("eee", 5);
    dv1.add("fff", 6);
    dv1.add("ggg", 7);
    dv1.add("hhh", 8);
    dv1.add("iii", 9);
    dv1.add("jjj", 10);
    //dv1.display();

    dv2.add("aaa", 0.1);
    dv2.add("bbb", 0.2);
    dv2.add("ccc", 0.3);
    dv2.add("dev", 0.4);
    dv2.add("eee", 0.5);
    dv2.add("fff", 0.6);
    dv2.add("gbf", 0.7);
    dv2.add("hjk", 0.8);
    dv2.add("iii", 0.9);
    dv2.add("jjj", 1.1);
    //dv2.display();

    auto dv3 = dv1 * dv2;
    dv3.display(std::cout);
    std::cout << std::endl;

    (2*dv3).display(std::cout);
    std::cout << std::endl;

    dv3 = dv1 + dv2;
    dv3.display(std::cout);

    return 0;
}

#ifndef TEST_RUN
#include "deque.hpp"
#include <deque>

#include <iostream>
    
    int main()
    {
       // nostd::deque A(10000, "5");
        //std::deque<std::string> my_deque;
        //std::cout << my_deque.max_size();
       
        nostd::deque as(5, "asd");
        nostd::deque as1(as);
        //std::cout << as1.at(3);
        //as.clear();
        //as.clear();
        //std::cout << as1.size();
        //nostd::deque as2;
        //as1.pop_back();
      //  std::cout << std::endl << as1[2];
        nostd::deque ex(2,"sjs");
        as1.push_front("olala");
        //std::cout << std::endl << as1.front();
        as1.push_front("ofvlala");
        //std::cout << std::endl << as1.front();
        //as1.push_back("haha");
        //std::cout << std::endl << as1.back();
       // as1.push_back("haha2");
        //std::cout << std::endl << as1.back();
        //std::cout << std::endl << ex.back();
        //as1.clear();
        //std::cout << std::endl << as1.size()<<std::endl;
        //as1.swap(ex);
        //std::cout << as1.size()<<std::endl;
        //std::cout << ex.size();
        as1.clear();
        as1.push_front("h");
        std::cout << as1.size() << " ";
        std::cout << as1[0] << " ";
        as1.push_front("fkd");
        std::cout << as1.size() << " ";
        std::cout << as1[1] << " ";
        as1.push_front("hey");
        std::cout << as1.size() << " ";
        std::cout << as1[2] << std::endl;
        as1.insert(as1.begin() + 1, "dhf");
        std::cout << as1.back();
        std::cout << as1.size()<<std::endl;
        as1.insert(as1.begin(), ex.begin(), ex.end());
        std::cout << as1.size() << std::endl << as1[0]<<" "<< as1[1] << std::endl;
        std::cout << as1.size() << std::endl;
        as1.pop_back();
        as1.pop_front();
        std::cout << as1.size() << std::endl;

       // as1.push_front("jfu");
       // as1.push_front("jnff");
         


        return 0;
    }

#endif
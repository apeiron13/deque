#ifdef TEST_RUN
#include "deque.hpp"



void main()
{
	//nostd::deque as(5, "asd");
	//nostd::deque as1(as);
	//as1.clear();
	//as1.front();
	//as1.assign(5, "jgj");
	//std::cout << as1.capacity();
	//as1.assign(as.begin(), as.begin() + 2);
	//std::cout << as1[0]<<std::endl;
	//std::cout << as1[1];// << " " << " " << as1[2];// << " " << as1[3] << " " << as1[4] << " " << as1[5] << as1[6];
	//nostd::deque olala(100000,"fvfv");
	//std::cout << " "<<olala[23454];
	//std::cout << olala.size() << " " << olala.capacity() << " " << olala.capacity_back() << " cp " << olala.capacity_front() << " cf ";
	nostd::deque ol(2, "djh0");
	nostd::deque ola(3, "yr");
	ol.swap(ola);
	std::cout << std::endl<<ol.size() << " size " << ol.capacity() << " capacity " << ol[0] << " " << ol[1] << std::endl;
	std::cout << ola.size() << " size " << ola.capacity() << " capacity " << ola[0] << " " << ola[1] << std::endl;
	nostd::swap(ola, ol);
	std::cout << std::endl << ol.size() << " size " << ol.capacity() << " capacity " << ol[0] << " " << ol[1] << std::endl;
	std::cout << ola.size() << " size " << ola.capacity() << " capacity " << ola[0] << " " << ola[1] << std::endl;
	ol.push_front("1");
	ol.push_front("2");
	ol.push_back("123");
	ol.push_back("456");
	ol.erase(ol.begin());
	ol.erase(ol.end()-1);
	ol.push_front("3");
	ol.push_front("4");
	ol.push_front("5");
	std::cout << ol[0];
	ol.resize(4);
   ol.resize(6,"hf");
   ol.resize(4);
   if (ol > ola)
	   std::cout << "not reater";
   else
	   std::cout << "smaller";
	ol.clear();
	ol.push_back("u");
	ol.push_back("olll");
	ol.push_front("g");
	ol.insert(ol.begin()+2, "qwe");
	if (ol >= ola)
		std::cout << "greater or equal";
	else
		std::cout << "smaller";
	if (ol < ola)
		std::cout << "smaller";
	else
		std::cout << "greater";
	//nostd::deque hey;
	//hey.assign(4,"gnfxx");
	//ol.push_front("6");
	//ol.push_front("7");*/
	//std::cout << ol[0] << " " << ol[1] << " " << ol[2] << " " << ol[3] << " ";
	//std::cout << ol[4] << " " << ol[5] << std::endl;
	//std::cout << " " << ol[6] << " " << ol[7] << std::endl;
}
#endif
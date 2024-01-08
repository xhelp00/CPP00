#include "Serializer.hpp"
#include <cstdlib>
#include <bitset>
#include <cstdio>

int main(int ac, char** av)
{
	if (ac == 3)
	{
		Data data1;
		data1.num = atoi(av[1]);
		data1.str = av[2];
		
		std::cout << std::endl;
		std::cout << data1.num << " " << data1.str << std::endl;
		
		std::cout <<  "\nSerializing...\n"  << std::endl;
		uintptr_t raw = Serializer::serialize(&data1);

		std::cout << "Data binary representation: "  << std::bitset<64>(raw) << std::endl;
		//printf("%p\n", &data1);
		//printf("%lx\n", raw);

		std::cout << "\nDeserializing...\n" << std::endl;
		Data* data2 = Serializer::deserialize(raw);
		std::cout << data2->num << " " << data2->str << std::endl;
		std::cout << std::endl;
	
	}
	else
		return (std::cerr << "Wrong number of arguments" << std::endl, 1);
	return 0;

}
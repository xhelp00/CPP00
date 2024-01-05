#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::Serializer(const Serializer& other)
{
	*this = other;
}

Serializer::~Serializer()
{}

Serializer& Serializer::operator=(const Serializer& other)
{
	if (this == &other)
		return *this;
	return *this;
}


uintptr_t Serializer::serialize(Data* data)
{
	return (reinterpret_cast<uintptr_t>(data));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
#include "Serializer.hpp"

int main() {
	Data originalData;
	originalData.name = "Goncalo";
	originalData.age = 24;

	std::cout << originalData.name << std::endl;
	std::cout << originalData.age << std::endl;

	uintptr_t raw = Serializer::serialize(&originalData);

	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << deserializedData->name << std::endl;
	std::cout << deserializedData->age << std::endl;
	return 0;
}

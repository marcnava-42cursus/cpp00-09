#include "Serializer.hpp"

#include <iomanip>
#include <iostream>

int main(void) {
    Data data;
    data.id = 42;
    data.name = "serializer";
    data.value = 3.14159;

    Data *original = &data;
    uintptr_t raw = Serializer::serialize(original);
    Data *restored = Serializer::deserialize(raw);

    std::cout << "Original pointer:  " << original << std::endl;
    std::cout << "Serialized value:  0x" << std::hex << raw << std::dec << std::endl;
    std::cout << "Restored pointer:  " << restored << std::endl;

    if (original == restored) {
        std::cout << "Pointer round-trip: OK" << std::endl;
    } else {
        std::cout << "Pointer round-trip: FAIL" << std::endl;
    }

    std::cout << "Data.id:    " << restored->id << std::endl;
    std::cout << "Data.name:  " << restored->name << std::endl;
    std::cout << "Data.value: " << restored->value << std::endl;

    return 0;
}

#ifndef Vas_Common_H
#define Vas_Common_H
// Для работы специальных типов на C++
#include <cstdint>

class reg_32bit
{
private:
	uint32_t memoryRef;

public:
	reg_32bit(const uint32_t &tempRef) :
			memoryRef(tempRef)
	{
	}

	bool setBit(bool val, const uint32_t pos);
	bool setVal(const uint32_t val, const uint32_t pos);

	// TYPE print_register() const;
};

#endif

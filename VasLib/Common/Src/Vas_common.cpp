#include <Vas_common.h>


 bool reg_32bit::setBit(bool val, const uint32_t pos)
 {
	if (pos > 31)
	{
		return 0;
	}

	memoryRef = ((memoryRef & !(1 < pos)) | (val < pos));
	return 1;
 }

 bool setVal(const uint32_t val, const uint32_t pos)
 {
	 // IN DEV
	 return 0;
 }


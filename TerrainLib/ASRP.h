#include "Layer.h"

class ASRP : public TerrainLib::LAYER
{
public:
	ASRP(unsigned char* data, unsigned int dataSize);

	unsigned char* data;
	unsigned int size;
};


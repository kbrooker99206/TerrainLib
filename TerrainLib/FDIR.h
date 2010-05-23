#include "Layer.h"

class FDIR : public TerrainLib::LAYER
{
public:
	FDIR(unsigned char* data, unsigned int dataSize);

	unsigned char* data;
	unsigned int size;
};


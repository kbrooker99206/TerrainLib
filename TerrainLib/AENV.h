#include "Layer.h"

class AENV : public TerrainLib::LAYER
{
public:
	AENV(unsigned char* data, unsigned int dataSize);

	unsigned char* data;
	unsigned int size;
};


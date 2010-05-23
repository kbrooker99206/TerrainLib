#include "Layer.h"

class AHTR : public TerrainLib::LAYER
{
public:
	AHTR(unsigned char* data, unsigned int dataSize);

	unsigned char* data;
	unsigned int size;
};


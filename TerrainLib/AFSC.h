#include "Layer.h"

class AFSC : public TerrainLib::LAYER
{
public:
	AFSC(unsigned char* data, unsigned int dataSize);

	unsigned char* data;
	unsigned int size;
};
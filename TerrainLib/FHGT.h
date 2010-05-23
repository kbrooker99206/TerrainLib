#include "Layer.h"

class FHGT : public TerrainLib::LAYER
{
public:
	FHGT(unsigned char* data, unsigned int dataSize);

	unsigned char* data;
	unsigned int size;
};
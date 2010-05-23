#include "Layer.h"

class ASCN : public TerrainLib::LAYER
{
public:
	ASCN(unsigned char* data, unsigned int dataSize);

	unsigned char* data;
	unsigned int size;
};
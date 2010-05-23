#include "Layer.h"

class ASCR : public TerrainLib::LAYER
{
public:
	ASCR(unsigned char* data, unsigned int dataSize);

	unsigned char* data;
	unsigned int size;
};
#include "Layer.h"

class AHCN : public TerrainLib::LAYER
{
public:
	AHCN(unsigned char* data, unsigned int dataSize);

	int   unk1;
	float unk2;
};
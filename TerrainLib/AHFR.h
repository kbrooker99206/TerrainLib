#include "Layer.h"

class AHFR : public TerrainLib::LAYER
{
public:
	AHFR(unsigned char* data, unsigned int dataSize);

	int   unk1;
	int   unk2;
	float unk3;
};
#include "Layer.h"

class AHTR : public TerrainLib::LAYER
{
public:
	AHTR(unsigned char* data, unsigned int dataSize);

	float flat_ratio;
	float height_delta;
};


#include "Layer.h"

class BPLN : public TerrainLib::LAYER
{
public:
	BPLN(unsigned char* data, unsigned int dataSize);
	
	std::vector<TerrainLib::VERTEX*> verts;

	int feather_type;
	float feather_amount;
	float line_width;
};
#include "Layer.h"

class BPOL : public TerrainLib::LAYER
{
public:
	BPOL(unsigned char* data, unsigned int dataSize);
	
	std::vector<TerrainLib::VERTEX*> verts;

	int feather_type;
	float shore_smoothness;
	int is_water;
	float water_height;
	float water_shader_size;
	unsigned char* water_shader;
};
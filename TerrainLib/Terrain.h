#include "IFF.h"
#include "TerrainStructures.h"

namespace TerrainLib
{
	class CONTAINER_LAYER;
	class LAYER;

	class Trn
	{
	public:
		Trn(std::string trnFile);

		int getError() {return error;}

		//This magical function returns the height of the terrain at a particular point.
		//float getHeight(float x, float y);

		//This function returns the IFF File Object.
		IFFLib::IFF* getIFFObject() {return mObject;}
		std::vector<MFAM*>* getFractalFamilies() {return &FractalFamilies;}
		std::vector<FFAM*>* getFloraFamilies() {return &FloraFamilies;}
		std::vector<LAYER*>* getLayers() {return &layers;}

	private:
		void _handleBasicData(unsigned char* data, unsigned int dataSize);
		LAYER* Trn::_loadLayer(IFFLib::IFF::NODE* parent);

		//This is the actual IFF file on disk that represents the terrain file. It is used when loading the terrain.
		IFFLib::IFF* mObject;

		//Indicates an error.
		int error;

		//+++ TERRAIN VARIABLES BELOW +++

		//Basic Data
		unsigned char* filename;
		float map_width;
		float chunk_width;
		int   tiles_per_chunk;
		int   header_type;
		float global_water_height;
		float water_shader_size;
		unsigned char* water_shader_name;
		float seconds_per_world_cycle;

		std::vector<SFAM*> ShaderFamilies;
		std::vector<FFAM*> FloraFamilies;
		std::vector<RFAM*> RadialFloraFamilies;
		std::vector<EFAM*> EnvironmentFamilies;
		std::vector<MFAM*> FractalFamilies;

		std::vector<LAYER*> layers;
	};

};
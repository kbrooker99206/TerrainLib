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

		void SaveTerrain(std::string outputFile);

		int getError() {return error;}

		//This magical function returns the height of the terrain at a particular point.
		//float getHeight(float x, float y);

		//This function returns the IFF File Object.
		std::vector<MFAM*>* getFractalFamilies() {return &FractalFamilies;}
		std::vector<FFAM*>* getFloraFamilies() {return &FloraFamilies;}
		std::vector<LAYER*>* getLayers() {return &layers;}

		HEADER* getHeaderData(){return &header;}
		FOOTER* getFooterData(){return &footer;}

	private:
		void _loadHeader(unsigned char* data, unsigned int dataSize);
		void _loadFooter(IFFLib::IFF::NODE* parentNode);
		LAYER* Trn::_loadLayer(IFFLib::IFF::NODE* parent);

		//Indicates an error.
		int error;

		//+++ TERRAIN VARIABLES BELOW +++

		HEADER header;

		std::vector<SFAM*> ShaderFamilies;
		std::vector<FFAM*> FloraFamilies;
		std::vector<RFAM*> RadialFloraFamilies;
		std::vector<EFAM*> EnvironmentFamilies;
		std::vector<MFAM*> FractalFamilies;
		std::vector<LAYER*> layers;

		FOOTER footer;
	};

};
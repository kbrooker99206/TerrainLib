#include "..\TerrainLib\Terrain.h"
#include "..\TerrainLib\Layer.h"

//Boundries
#include "..\TerrainLib\BREC.h"
#include "..\TerrainLib\BCIR.h"
#include "..\TerrainLib\BPOL.h"
#include "..\TerrainLib\BPLN.h"

//Height
#include "..\TerrainLib\AHCN.h"
#include "..\TerrainLib\AHFR.h"
#include "..\TerrainLib\AHFT.h"

void outputLayerTree(FILE** output, std::vector<TerrainLib::LAYER*>* input, unsigned int counter=0);

int main( int argc, char* argv[])
{
	system("pause");

	char* name_array[] = {
							"09",
							"10",
							"11",
							"character_farm",
							"cinco_city_test_m5",
							"corellia",
							"creature_test",
							"dantooine",
							"dathomir",
							"endor",
							"endor_asommers",
							"floratest",
							"godclient_test",
							"lok",
							"naboo",
							"rivertest",
							"rori",
							"runtimerules",
							"simple",
							"taanab",
							"talus",
							"tatooine",
							"test_wearables",
							"tutorial",
							"umbra",
							"watertabletest",
							"yavin4"
									};

	for(unsigned int i=0; i < 27; i++)
	{
		printf("==%s.trn==\n", name_array[i]);
		char temp[128];
		sprintf(temp, "%s.trn", name_array[i]);
		TerrainLib::Trn Terrain1(temp);

		//Do the deed
		sprintf(temp, "%s.txt", name_array[i]);

		FILE* output = fopen(temp, "w");

		std::vector<TerrainLib::MFAM*>* fractals = Terrain1.getFractalFamilies();

		fprintf(output, "==FRACTAL FAMILIES==\n");

		for(unsigned int i=0; i < fractals->size(); i++)
		{
			fprintf(output, "\nfractal_id: %d\n", fractals->at(i)->fractal_id);
			fprintf(output, "fractal_label: %s\n", fractals->at(i)->fractal_label);

			fprintf(output, "unk1: %d\n", fractals->at(i)->unk1);
			fprintf(output, "unk2: %d\n", fractals->at(i)->unk2);
			fprintf(output, "unk3: %f\n", fractals->at(i)->unk3);
			fprintf(output, "unk4: %d\n", fractals->at(i)->unk4);
			fprintf(output, "unk5: %f\n", fractals->at(i)->unk5);
			fprintf(output, "unk6: %d\n", fractals->at(i)->unk6);
			fprintf(output, "unk7: %f\n", fractals->at(i)->unk7);
			fprintf(output, "unk8: %f\n", fractals->at(i)->unk8);
			fprintf(output, "unk9: %f\n", fractals->at(i)->unk9);
			fprintf(output, "unk10: %f\n", fractals->at(i)->unk10);
			fprintf(output, "unk11: %f\n", fractals->at(i)->unk11);
			fprintf(output, "unk12: %f\n", fractals->at(i)->unk12);
			fprintf(output, "unk13: %d\n", fractals->at(i)->unk13);
		}

		fprintf(output, "\n\n==LAYERS==\n\n");
		outputLayerTree(&output, Terrain1.getLayers());

		fclose(output);
	}

	system("pause");

	return 0;
}

void outputLayerTree(FILE** output, std::vector<TerrainLib::LAYER*>* input, unsigned int counter)
{
	for(unsigned int i=0; i < input->size(); ++i)
	{
		switch(input->at(i)->type)
		{
		case TerrainLib::LAYER_CONTAINER:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				TerrainLib::CONTAINER_LAYER* tempContainer = static_cast<TerrainLib::CONTAINER_LAYER*>(input->at(i));
				fprintf(*output, "CONTAINER_LAYER : %s : %s\n", tempContainer->customName, tempContainer->description);

				outputLayerTree(output, &tempContainer->children, counter+1);
			}
			break;
		case TerrainLib::LAYER_BREC:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				BREC* tempContainer = static_cast<BREC*>(input->at(i));
				fprintf(*output, "Boundry Rectangle : POS1: (%f,%f), POS2: (%f,%f), Feather Type: (%d), Feather Amount: (%f)\n", tempContainer->x1, tempContainer->y1, tempContainer->x2, tempContainer->y2, tempContainer->feather_type, tempContainer->feather_amount);
			}
			break;
		case TerrainLib::LAYER_BCIR:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				BCIR* tempContainer = static_cast<BCIR*>(input->at(i));
				fprintf(*output, "Boundry Circle : POS: (%f,%f), RAD: %f, Feather Type: (%d), Feather Amount: (%f)\n", tempContainer->x, tempContainer->y, tempContainer->rad, tempContainer->feather_type, tempContainer->feather_amount);
			}
			break;
		case TerrainLib::LAYER_BPOL:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				BPOL* tempContainer = static_cast<BPOL*>(input->at(i));
				fprintf(*output, "Boundry Polygon : Points: {");

				for(unsigned int j=0; j < tempContainer->verts.size(); j++)
				{
					if(j!=0)
						fprintf(*output, ",");

					fprintf(*output, "(%f, %f)", tempContainer->verts.at(j)->x, tempContainer->verts.at(j)->y);
				}
				fprintf(*output, "}, Feathering Type: (%d), Shore Smoothness: (%f), Water: (%s), Water Height (%f), Water-Shader-Size: (%f), Water_Shader: (%s)\n",
					tempContainer->feather_type, tempContainer->shore_smoothness, ((tempContainer->is_water == 1) ? "yes" : "no"), tempContainer->water_height, tempContainer->water_shader_size, tempContainer->water_shader);

			}
			break;
		case TerrainLib::LAYER_BPLN:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				BPLN* tempContainer = static_cast<BPLN*>(input->at(i));
				fprintf(*output, "Boundry Polyline : Points: {");

				for(unsigned int j=0; j < tempContainer->verts.size(); j++)
				{
					if(j!=0)
						fprintf(*output, ",");

					fprintf(*output, "(%f, %f)", tempContainer->verts.at(j)->x, tempContainer->verts.at(j)->y);
				}
				fprintf(*output, "}, Feathering Type: (%d), Feather Amount: (%f), Line Width: (%f)\n",
					tempContainer->feather_type, tempContainer->feather_amount, tempContainer->line_width);
			}
			break;
		case TerrainLib::LAYER_AHCN:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				AHCN* tempContainer = static_cast<AHCN*>(input->at(i));
				fprintf(*output, "Height Constant : (%d), (%f)\n", tempContainer->unk1, tempContainer->unk2);
			}
			break;
		case TerrainLib::LAYER_AHFR:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				AHFR* tempContainer = static_cast<AHFR*>(input->at(i));
				fprintf(*output, "Height Fractal : (%d), (%d), (%f)\n", tempContainer->unk1, tempContainer->unk2, tempContainer->unk3);
			}
			break;
		case TerrainLib::LAYER_AHTR:
			{

			}
			break;
		case TerrainLib::LAYER_AHFT:
			{

			}
			break;
		}					
	}
}
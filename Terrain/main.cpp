#include "..\TerrainLib\Terrain.h"
#include "..\TerrainLib\Layer.h"

//Boundries
#include "..\TerrainLib\BREC.h"
#include "..\TerrainLib\BCIR.h"
#include "..\TerrainLib\BPOL.h"
#include "..\TerrainLib\BPLN.h"

//Filters
#include "..\TerrainLib\FDIR.h"
#include "..\TerrainLib\FFRA.h"
#include "..\TerrainLib\FHGT.h"
#include "..\TerrainLib\FSLP.h"

//Shader
#include "..\TerrainLib\ASCN.h"
#include "..\TerrainLib\ACCN.h"
#include "..\TerrainLib\FSHD.h"

//Height
#include "..\TerrainLib\AHCN.h"
#include "..\TerrainLib\AHFR.h"
#include "..\TerrainLib\AHTR.h"

//Flora
#include "..\TerrainLib\AFSC.h"
#include "..\TerrainLib\AFSN.h"
#include "..\TerrainLib\AFDN.h"
#include "..\TerrainLib\AFDF.h"

//Other
#include "..\TerrainLib\AENV.h"
#include "..\TerrainLib\AEXC.h"
#include "..\TerrainLib\AROA.h"
#include "..\TerrainLib\ARIV.h"
#include "..\TerrainLib\ACRF.h"
#include "..\TerrainLib\ACRH.h"
#include "..\TerrainLib\ASRP.h"

#pragma warning(disable:4996) //sick of meaningless warnings

void outputLayerTree(FILE** output, std::vector<TerrainLib::LAYER*>* input, unsigned int counter=0);

int main( int argc, char* argv[])
{
	system("pause");

	char* name_array[] = {
							"corellia",
							"09",
							"10",
							"11",
							"character_farm",
							"cinco_city_test_m5",
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

	for(unsigned int j=0; j < 27; j++)
	{
		printf("==%s.trn==\n", name_array[j]);

		char temp[128];
		sprintf(temp, "%s.trn", name_array[j]);
		TerrainLib::Trn Terrain1(temp);

		TerrainLib::HEADER* headerData = Terrain1.getHeaderData();
		TerrainLib::FOOTER* footerData = Terrain1.getFooterData();

		//Do the deed
		sprintf(temp, "%s.txt", name_array[j]);

		FILE* output = fopen(temp, "w");

		fprintf(output, "==Basic Header Info==\n");

		fprintf(output, "Filename: %s\n", headerData->filename);
		fprintf(output, "Map Width: %f\n", headerData->map_width);
		fprintf(output, "Chunk Width: %f\n",headerData->chunk_width);
		fprintf(output, "tiles_per_chunk: %d\n",headerData->tiles_per_chunk);
		fprintf(output, "header_type: %d\n", headerData->header_type);
		fprintf(output, "global_water_height: %f\n", headerData->global_water_height);
		fprintf(output, "water_shader_size: %f\n", headerData->water_shader_size);
		fprintf(output, "water_shad er_name: %s\n", headerData->water_shader_name);
		fprintf(output, "seconds_per_world_cycle: %f\n", headerData->seconds_per_world_cycle);

		fprintf(output, "\n==Flora Header Info==\n");
		
		fprintf(output, "Collidable_MinDist: %f\n", headerData->Collidable_MinDist);
		fprintf(output, "Collidable_MaxDist: %f\n", headerData->Collidable_MaxDist);
		fprintf(output, "Collidable_TileSize: %f\n", headerData->Collidable_MaxDist);
		fprintf(output, "Collidable_TileBorder: %f\n", headerData->Collidable_MaxDist);
		fprintf(output, "Collidable_Seed: %f\n\n", headerData->Collidable_Seed);

		fprintf(output, "NonCollidable_MinDist: %f\n", headerData->NonCollidable_MinDist);
		fprintf(output, "NonCollidable_MaxDist: %f\n", headerData->NonCollidable_MaxDist);
		fprintf(output, "NonCollidable_TileSize: %f\n", headerData->NonCollidable_MaxDist);
		fprintf(output, "NonCollidable_TileBorder: %f\n", headerData->NonCollidable_MaxDist);
		fprintf(output, "NonCollidable_Seed: %f\n\n", headerData->NonCollidable_Seed);

		fprintf(output, "NearRadial_MinDist: %f\n", headerData->NearRadial_MinDist);
		fprintf(output, "NearRadial_MaxDist: %f\n", headerData->NearRadial_MaxDist);
		fprintf(output, "NearRadial_TileSize: %f\n", headerData->NearRadial_TileSize);
		fprintf(output, "NearRadial_TileBorder: %f\n", headerData->NearRadial_TileBorder);
		fprintf(output, "NearRadial_Seed: %f\n\n", headerData->NearRadial_Seed);

		fprintf(output, "FarRadial_MinDist: %f\n", headerData->FarRadial_MinDist);
		fprintf(output, "FarRadial_MaxDist: %f\n", headerData->FarRadial_MaxDist);
		fprintf(output, "FarRadial_TileSize: %f\n", headerData->FarRadial_TileSize);
		fprintf(output, "FarRadial_TileBorder: %f\n", headerData->FarRadial_TileBorder);
		fprintf(output, "FarRadial_Seed: %f\n\n", headerData->FarRadial_Seed);

		fprintf(output, "\n== Map Data ==\n");
		fprintf(output, "gameMapWidth: %f\n", footerData->gameWidth);
		fprintf(output, "chunkGameWidth: %f\n", footerData->chunkGameWidth);
		fprintf(output, "chunkBitSize: %u\n", footerData->chunkBitFieldSize);
		fprintf(output, "bitMapWidth: %u\n", footerData->bitMapWidth);

		std::vector<TerrainLib::MFAM*>* fractals = Terrain1.getFractalFamilies();
		fprintf(output, "\n==FRACTAL FAMILIES==\n");

		for(unsigned int i=0; i < fractals->size(); i++)
		{
			fprintf(output, "\nfractal_id: %d\n", fractals->at(i)->fractal_id);
			fprintf(output, "fractal_label: %s\n", fractals->at(i)->fractal_label);

			fprintf(output, "seed: %d\n", fractals->at(i)->seed);
			fprintf(output, "unk2: %d\n", fractals->at(i)->unk2);
			fprintf(output, "unk3: %f\n", fractals->at(i)->unk3);
			fprintf(output, "unk4: %d\n", fractals->at(i)->unk4);
			fprintf(output, "unk5: %f\n", fractals->at(i)->unk5);
			fprintf(output, "unk6: %f\n", fractals->at(i)->unk6);
			//fprintf(output, "unk7: %f\n", fractals->at(i)->unk7);
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

		//Do the deed...again
		sprintf(temp, "%s.wmap", name_array[j]);
		output = fopen(temp, "w");

		for(unsigned int i=0; i < footerData->WMAP_SIZE; i++)
			fprintf(output, "%02X ", footerData->WMAP[i]);

		fclose(output);

		sprintf(temp, "%s.smap", name_array[j]);
		output = fopen(temp, "w");

		for(unsigned int i=0; i < footerData->SMAP_SIZE; i++)
			fprintf(output, "%02X ", footerData->SMAP[i]);

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
				fprintf(*output, "Affector Height Constant : (%d), (%f)\n", tempContainer->unk1, tempContainer->unk2);
			}
			break;
		case TerrainLib::LAYER_AHFR:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				AHFR* tempContainer = static_cast<AHFR*>(input->at(i));
				fprintf(*output, "Affector Height Fractal : fractal_id:(%d), (%d), (%f)\n", tempContainer->unk1, tempContainer->unk2, tempContainer->unk3);
			}
			break;
		case TerrainLib::LAYER_AHTR:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				AHTR* tempContainer = static_cast<AHTR*>(input->at(i));
				fprintf(*output, "Affector Height Terrace: Flat Ratio: (%f), Height Delta (%f)\n", tempContainer->flat_ratio, tempContainer->height_delta);
			}
			break;	
		case TerrainLib::LAYER_FDIR:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				FDIR* tempContainer = static_cast<FDIR*>(input->at(i));

				fprintf(*output, "Filter Direction: ");
				for(unsigned int j = 0; j < tempContainer->size; j++)
					fprintf(*output, "%02X ", tempContainer->data[j]);

				fprintf(*output, "\n");
			}
			break;
		case TerrainLib::LAYER_FFRA:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				FFRA* tempContainer = static_cast<FFRA*>(input->at(i));

				fprintf(*output, "Filter Fractal: ");
				for(unsigned int j = 0; j < tempContainer->size; j++)
					fprintf(*output, "%02X ", tempContainer->data[j]);

				fprintf(*output, "\n");
			}
			break;
		case TerrainLib::LAYER_FHGT:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				FHGT* tempContainer = static_cast<FHGT*>(input->at(i));
				fprintf(*output, "Filter Height: minHeight:(%f), maxHeight(%f), feather_type:(%d), feather_amount(%f)\n", tempContainer->minHeight, tempContainer->maxHeight, tempContainer->feather_type, tempContainer->feather_amount);
			}
			break;
		case TerrainLib::LAYER_FSLP:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				FSLP* tempContainer = static_cast<FSLP*>(input->at(i));

				fprintf(*output, "Filter Slope: ");
				for(unsigned int j = 0; j < tempContainer->size; j++)
					fprintf(*output, "%02X ", tempContainer->data[j]);

				fprintf(*output, "\n");
			}
			break;
		case TerrainLib::LAYER_ASCN:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				ASCN* tempContainer = static_cast<ASCN*>(input->at(i));

				fprintf(*output, "Affector Shader Constant: ");
				for(unsigned int j = 0; j < tempContainer->size; j++)
					fprintf(*output, "%02X ", tempContainer->data[j]);

				fprintf(*output, "\n");
			}
			break;
		case TerrainLib::LAYER_ASRP:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				ASRP* tempContainer = static_cast<ASRP*>(input->at(i));

				fprintf(*output, "Affector Shader Replace: ");
				for(unsigned int j = 0; j < tempContainer->size; j++)
					fprintf(*output, "%02X ", tempContainer->data[j]);

				fprintf(*output, "\n");
			}
			break;
		case TerrainLib::LAYER_ACCN:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				ACCN* tempContainer = static_cast<ACCN*>(input->at(i));

				fprintf(*output, "Affector Shader Color Constant: ");
				for(unsigned int j = 0; j < tempContainer->size; j++)
					fprintf(*output, "%02X ", tempContainer->data[j]);

				fprintf(*output, "\n");
			}
			break;
		case TerrainLib::LAYER_FSHD:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				FSHD* tempContainer = static_cast<FSHD*>(input->at(i));

				fprintf(*output, "Filter Shader: ");
				for(unsigned int j = 0; j < tempContainer->size; j++)
					fprintf(*output, "%02X ", tempContainer->data[j]);

				fprintf(*output, "\n");
			}
			break;
		case TerrainLib::LAYER_AFSC:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				AFSC* tempContainer = static_cast<AFSC*>(input->at(i));

				fprintf(*output, "Affector Flora Static Collidable: ");
				for(unsigned int j = 0; j < tempContainer->size; j++)
					fprintf(*output, "%02X ", tempContainer->data[j]);

				fprintf(*output, "\n");
			}
			break;
		case TerrainLib::LAYER_AFSN:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				AFSN* tempContainer = static_cast<AFSN*>(input->at(i));

				fprintf(*output, "Affector Flora Static Non-Collidable: ");
				for(unsigned int j = 0; j < tempContainer->size; j++)
					fprintf(*output, "%02X ", tempContainer->data[j]);

				fprintf(*output, "\n");
			}
			break;
		case TerrainLib::LAYER_AFDN:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				AFSC* tempContainer = static_cast<AFSC*>(input->at(i));

				fprintf(*output, "Affector Flora Dynamic Near: ");
				for(unsigned int j = 0; j < tempContainer->size; j++)
					fprintf(*output, "%02X ", tempContainer->data[j]);

				fprintf(*output, "\n");
			}
			break;
		case TerrainLib::LAYER_AFDF:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				AFDF* tempContainer = static_cast<AFDF*>(input->at(i));

				fprintf(*output, "Affector Flora Dynamic Far: ");
				for(unsigned int j = 0; j < tempContainer->size; j++)
					fprintf(*output, "%02X ", tempContainer->data[j]);

				fprintf(*output, "\n");
			}
			break;
		case TerrainLib::LAYER_AENV:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				AENV* tempContainer = static_cast<AENV*>(input->at(i));

				fprintf(*output, "Affector Environment: ");
				for(unsigned int j = 0; j < tempContainer->size; j++)
					fprintf(*output, "%02X ", tempContainer->data[j]);

				fprintf(*output, "\n");
			}
			break;
		case TerrainLib::LAYER_AEXC:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				AEXC* tempContainer = static_cast<AEXC*>(input->at(i));

				fprintf(*output, "Affector Exclude!");

				fprintf(*output, "\n");
			}
			break;
		case TerrainLib::LAYER_AROA:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				AROA* tempContainer = static_cast<AROA*>(input->at(i));

				fprintf(*output, "Affector Road: ");
				for(unsigned int j = 0; j < tempContainer->size2; j++)
					fprintf(*output, "%02X ", tempContainer->data2[j]);
				fprintf(*output, "\n");

				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");
				fprintf(*output, "\tRoad Segment: ");
				for(unsigned int j = 0; j < tempContainer->size; j++)
					fprintf(*output, "%02X ", tempContainer->data[j]);

				fprintf(*output, "\n");
			}
			break;
		case TerrainLib::LAYER_ARIV:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				ARIV* tempContainer = static_cast<ARIV*>(input->at(i));

				fprintf(*output, "Affector River: ");
				for(unsigned int j = 0; j < tempContainer->size2; j++)
					fprintf(*output, "%02X ", tempContainer->data2[j]);
				fprintf(*output, "\n");

				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");
				fprintf(*output, "\tRiver Segment: ");
				for(unsigned int j = 0; j < tempContainer->size; j++)
					fprintf(*output, "%02X ", tempContainer->data[j]);

				fprintf(*output, "\n");
			}
			break;
		case TerrainLib::LAYER_ACRF:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				ACRF* tempContainer = static_cast<ACRF*>(input->at(i));

				fprintf(*output, "Affector Color Ramp Fractal: ");
				for(unsigned int j = 0; j < tempContainer->size; j++)
					fprintf(*output, "%02X ", tempContainer->data[j]);
				fprintf(*output, "\n");
			}
			break;
		case TerrainLib::LAYER_ACRH:
			{
				for(unsigned int j = 0; j < counter; j++)
					fprintf(*output, "\t");

				ACRH* tempContainer = static_cast<ACRH*>(input->at(i));

				fprintf(*output, "Affector Color Ramp Height: ");
				for(unsigned int j = 0; j < tempContainer->size; j++)
					fprintf(*output, "%02X ", tempContainer->data[j]);
				fprintf(*output, "\n");
			}
			break;
		}
	}
}
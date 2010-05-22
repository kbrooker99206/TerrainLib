#include "..\TerrainLib\Terrain.h"


int main( int argc, char* argv[])
{
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
	}

	system("pause");

	return 0;
}
#include <vector>

namespace TerrainLib
{

class SFAM
{
public:

	SFAM(unsigned char* data);
	~SFAM()
	{
		for(unsigned int i=0; i < children.size(); i++)
			delete children[i];
	}

	int family_id;
	unsigned char* family_name;
	unsigned char* file_name;
	char  unk1;
	char  unk2;
	char  unk3;
	float unk4;
	float unk5;
	//int child_count

	static class SFAM_CHILD
	{
	public:
		unsigned char* shader_name;
		float unk1;
	};

	std::vector<SFAM_CHILD*> children;
};

class FFAM
{
public:

	FFAM(unsigned char* data);

	int family_id;
	unsigned char* family_name;
	char  unk1;
	char  unk2;
	char  unk3;
	float unk4;
	float unk5;
	//int child_count;

	static class FFAM_CHILD
	{
	public:

		unsigned char* appearance_name;
		float unk1;
		int   unk2;
		float unk3;
		float unk4;
		int   unk5;
		int   unk6;
		float unk7;
		float unk8;
	};

	std::vector<FFAM_CHILD*> children;
};

class RFAM
{
public:

	RFAM(unsigned char* data);

	int family_id;
	unsigned char* family_name;
	char unk1;
	char unk2;
	char unk3;
	float unk4;
	//int child_count;

	static class RFAM_CHILD
	{
	public:

		unsigned char* shader_name;
		float unk1;
		float unk2;
		float unk3;
		float unk4;
		int   unk5;
		float unk6;
		float unk7;
		int   unk8;
		int   unk9;
	};

	std::vector<RFAM_CHILD*> children;
};

class EFAM
{
public:

	EFAM(unsigned char* data);

	int family_id;
	unsigned char* family_name;
	char  unk1;
	char  unk2;
	char  unk3;
	float unk4;
};

class MFAM
{
public:

	MFAM(unsigned char* data, unsigned char* data2);

	int fractal_id;
	unsigned char* fractal_label;

	//MFRCFORM

	int   unk1;
	int   unk2;
	float unk3;
	int   unk4;
	float unk5;
	int   unk6;
	float unk7;
	float unk8;
	float unk9;
	float unk10;
	float unk11;
	float unk12;
	int   unk13;
};

};
#include "Layer.h"

//Boundries
#include "BREC.h"
#include "BCIR.h"
#include "BPOL.h"
#include "BPLN.h"

//Filters
#include "FDIR.h"
#include "FFRA.h"
#include "FHGT.h"
#include "FSLP.h"

//Shader
#include "ASCN.h"
#include "ASCR.h"
#include "ACCN.h"
#include "FSHD.h"

//Height
#include "AHCN.h"
#include "AHFR.h"
#include "AHFT.h"

//Flora
#include "AFSC.h"
#include "AFSN.h"
#include "AFDN.h"
#include "AFDF.h"

//Other
#include "AENV.h"
#include "AEXC.h"
#include "AROA.h"
#include "ARIV.h"
#include "ACRF.h"
#include "ACRH.h"
#include "AHTR.h"
#include "ASRP.h"

using namespace TerrainLib;
using namespace IFFLib;

LAYER* LAYER::LOAD(IFF::NODE* node)
{
	LAYER* layer = NULL;

	//See if the name is prefixed funkily or something
	char* nameStart = node->name;

	//Do it
	if(nameStart[0] == 'A')
	{
		if(nameStart[1] == 'C')
		{
			if(nameStart[2] == 'C')
			{
				if(nameStart[3] == 'N')
				{
					layer = new ACCN(node->children[1]->data, node->children[1]->size);
				}
			}
			else if(nameStart[2] == 'R')
			{
				if(nameStart[3] == 'F')
				{
					layer = new ACRF(node->children[1]->data, node->children[1]->size);
				}
				else if(nameStart[3] == 'H')
				{
					layer = new ACRH(node->children[1]->data, node->children[1]->size);
				}
			}
		}
		else if(nameStart[1] == 'E')
		{
			if(nameStart[2] == 'N')
			{
				if(nameStart[3] == 'V')
				{
					layer = new AENV(node->children[1]->data, node->children[1]->size);
				}
			}
			else if(nameStart[2] == 'X')
			{
				if(nameStart[3] == 'C')
				{
					layer = new AEXC(node->children[1]->data, node->children[1]->size);
				}
			}
		}
		else if(nameStart[1] == 'F')
		{
			if(nameStart[2] == 'D')
			{
				if(nameStart[3] == 'F')
				{
					layer = new AFDF(node->children[1]->data, node->children[1]->size);
				}
				else if(nameStart[3] == 'N')
				{
					layer = new AFDN(node->children[1]->data, node->children[1]->size);
				}
			}
			else if(nameStart[2] == 'S')
			{
				if(nameStart[3] == 'C')
				{
					layer = new AFSC(node->children[1]->data, node->children[1]->size);
				}
				else if(nameStart[3] == 'N')
				{
					layer = new AFSN(node->children[1]->data, node->children[1]->size);
				}
			}
		}
		else if(nameStart[1] == 'H')
		{
			if(nameStart[2] == 'C')
			{
				if(nameStart[3] == 'N')
				{
					layer = new AHCN(node->children[1]->data, node->children[1]->size);
				}
			}
			else if(nameStart[2] == 'F')
			{
				if(nameStart[3] == 'R')
				{
					layer = new AHFR(node->children[1]->data, node->children[1]->size);
				}
				else if(nameStart[3] == 'T')
				{
					layer = new AHFT(node->children[1]->data, node->children[1]->size);
				}
			}
			else if(nameStart[2] == 'T')
			{
				if(nameStart[3] == 'R')
				{
					layer = new AHTR(node->children[1]->data, node->children[1]->size);
				}
			}
		}
		else if(nameStart[1] == 'R')
		{
			if(nameStart[2] == 'I')
			{
				if(nameStart[3] == 'V')
				{
					layer = new ARIV(node->children[1]->data, node->children[1]->size);
				}
			}
			else if(nameStart[2] == 'O')
			{
				if(nameStart[3] == 'A')
				{
					layer = new AROA(node->children[1]->data, node->children[1]->size);
				}
			}
		}
		else if(nameStart[1] == 'S')
		{
			if(nameStart[2] == 'C')
			{
				if(nameStart[3] == 'N')
				{
					layer = new ASCN(node->children[1]->data, node->children[1]->size);
				}
				else if(nameStart[3] == 'R')
				{
					layer = new ASCR(node->children[1]->data, node->children[1]->size);
				}
			}
			else if(nameStart[2] == 'R')
			{
				if(nameStart[3] == 'P')
				{
					layer = new ASRP(node->children[1]->data, node->children[1]->size);
				}
			}
		}
	}
	else if(nameStart[0] == 'B')
	{
		if(nameStart[1] == 'C')
		{
			if(nameStart[2] == 'I')
			{
				if(nameStart[3] == 'R')
				{
					layer = new BCIR(node->children[1]->data, node->children[1]->size);
				}
			}
		}
		else if(nameStart[1] == 'P')
		{
			if(nameStart[2] == 'L')
			{
				if(nameStart[3] == 'N')
				{
					layer = new BPLN(node->children[1]->data, node->children[1]->size);
				}
			}
			else if(nameStart[2] == 'O')
			{
				if(nameStart[3] == 'L')
				{
					layer = new BPLN(node->children[1]->data, node->children[1]->size);
				}
			}
		}
		else if(nameStart[1] == 'R')
		{
			if(nameStart[2] == 'E')
			{
				if(nameStart[3] == 'C')
				{
					layer = new BREC(node->children[1]->data, node->children[1]->size);
				}
			}
		}
	}
	else if(nameStart[0] == 'F')
	{
		if(nameStart[1] == 'D')
		{
			if(nameStart[2] == 'I')
			{
				if(nameStart[3] == 'R')
				{
					layer = new FDIR(node->children[1]->data, node->children[1]->size);
				}
			}
		}
		else if(nameStart[1] == 'F')
		{
			if(nameStart[2] == 'R')
			{
				if(nameStart[3] == 'A')
				{
					layer = new FFRA(node->children[1]->data, node->children[1]->size);
				}
			}
		}
		else if(nameStart[1] == 'H')
		{
			if(nameStart[2] == 'G')
			{
				if(nameStart[3] == 'T')
				{
					layer = new FHGT(node->children[1]->data, node->children[1]->size);
				}
			}
		}
		else if(nameStart[1] == 'S')
		{
			if(nameStart[2] == 'H')
			{
				if(nameStart[3] == 'D')
				{
					layer = new FSHD(node->children[1]->data, node->children[1]->size);
				}
			}
			else if(nameStart[2] == 'L')
			{
				if(nameStart[3] == 'P')
				{
					layer = new FSLP(node->children[1]->data, node->children[1]->size);
				}
			}
		}
	}

	if(layer)
	{
		//Find it's data.
		unsigned char* data = node->children[0]->children[0]->children[0]->data;

		layer->enabled    = (data[0] == 1) ? true : false;
		layer->customName = &data[4];
	}

	return layer;
}

ACCN::ACCN(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_ACCN;

	//LAYER READING CODE GOES HERE
}

ASCN::ASCN(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_ASCN;

	//LAYER READING CODE GOES HERE
}

ASCR::ASCR(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_ASCR;

	//LAYER READING CODE GOES HERE
}

FSHD::FSHD(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_ACCN;

	//LAYER READING CODE GOES HERE
}

ACRF::ACRF(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_ACRF;

	//LAYER READING CODE GOES HERE
}

ACRH::ACRH(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_ACRH;

	//LAYER READING CODE GOES HERE
}

AENV::AENV(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_AENV;

	//LAYER READING CODE GOES HERE
}

AEXC::AEXC(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_AEXC;

	//LAYER READING CODE GOES HERE
}

AROA::AROA(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_AROA;

	//LAYER READING CODE GOES HERE
}

AHCN::AHCN(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_AHCN;

	//LAYER READING CODE GOES HERE
}

AHFR::AHFR(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_AHFR;

	//LAYER READING CODE GOES HERE
}

AHFT::AHFT(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_AHFT;

	//LAYER READING CODE GOES HERE
}

FFRA::FFRA(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_FFRA;

	//LAYER READING CODE GOES HERE
}

FHGT::FHGT(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_FHGT;

	//LAYER READING CODE GOES HERE
}

FSLP::FSLP(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_FSLP;

	//LAYER READING CODE GOES HERE
}

BREC::BREC(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_BREC;

	memcpy(&x1, &data[0], 4);
	memcpy(&y1, &data[4], 4);
	
	memcpy(&x2, &data[8], 4);
	memcpy(&y2, &data[12], 4);

	memcpy(&feather_type, &data[16], 4);
	memcpy(&feather_amount, &data[20], 4);

	//printf("==BREC==\nPOS1: (%f,%f)\nPOS2: (%f,%f)\nFeather Type: (%d)\nFeather Amount: (%f)\n", x1, y1, x2, y2, feather_type, feather_amount);

}

BPOL::BPOL(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_BPOL;

	//LAYER READING CODE GOES HERE
}

BPLN::BPLN(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_BPLN;

	//LAYER READING CODE GOES HERE
}

BCIR::BCIR(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_BCIR;
	memcpy(&x, &data[0], 4);
	memcpy(&y, &data[4], 4);
	
	memcpy(&rad, &data[8], 4);

	memcpy(&feather_type, &data[12], 4);
	memcpy(&feather_amount, &data[16], 4);

	printf("==BCIR==\nPOS: (%f,%f)\nRAD: %f\nFeather Type: (%d)\nFeather Amount: (%f)\n", x, y, rad, feather_type, feather_amount);
}

AFSC::AFSC(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_AFSC;

	//LAYER READING CODE GOES HERE
}

AFSN::AFSN(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_AFSN;

	//LAYER READING CODE GOES HERE
}

AFDF::AFDF(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_AFDF;

	//LAYER READING CODE GOES HERE
}

AFDN::AFDN(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_AFDN;

	//LAYER READING CODE GOES HERE
}

ARIV::ARIV(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_ARIV;

	//These are generally unused and can be ignored.

	//LAYER READING CODE GOES HERE
}

AHTR::AHTR(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_AHTR;
	
	//LAYER READING CODE GOES HERE
}

ASRP::ASRP(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_ASRP;
	
	//LAYER READING CODE GOES HERE
}

FDIR::FDIR(unsigned char* data, unsigned int dataSize)
{
	type = LAYER_FDIR;

	//LAYER READING CODE GOES HERE
}
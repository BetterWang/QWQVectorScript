#include <TChain.h>
#include <iostream>

char const * fname[] = {
	"test/",									// 0
	"../QVector/HIMinimumBias3/crab_HIMB3_QVector_v5/160501_180514/0000/",		// 1 1-3 GeV/c
	"../QVector/HIMinimumBias3/crab_HIMB3_QVector_randq_v1/160608_174408/0000/",	// 2 randq 1-3 GeV/c
	"../QVector/HIMinimumBias3/crab_HIMB3_QVector_randq_v2/160609_180344/0000/",	// 3 randq 1-3 GeV/c 0.505 pos
	"../QVector/HIMinimumBias1/crab_HIMB1_QVector_v5/160615_174308/0000/",		// 4 HIMB1 1-3 GeV/c
	"../QVector/HIMinimumBias2/crab_HIMB2_QVector_v5/160616_103828/0000/",		// 5 HIMB2 1-3 GeV/c
	"../QVector/HIMinimumBias4/crab_HIMB4_QVector_v5/160616_103838/0000/",		// 6 HIMB4 1-3 GeV/c
	"NA",										// 7 merged 1,4,5,6 HIMB[1,2,3,4] 1-3 GeV/c
	"../QVector/Hydjet_Quenched_MinBias_5020GeV_750/crab_Hydjet_QVector_v5/160616_192548/0000/",		// 8 Hydjet 1-3 GeV/c
	"../QVector/Hydjet_Quenched_MinBias_5020GeV_750/crab_Hydjet_QVector_randq_v1/160617_094658/0000/",	// 9 Hydjet randq 1-3 GeV/c
	"../QVector/HIMinimumBias1/crab_HIMB1_QVector_randq_v1/160617_090018/0000/",	// 10 HIMB1 randq 1-3 GeV/c
	"../QVector/HIMinimumBias2/crab_HIMB2_QVector_randq_v1/160617_090032/0000/",	// 11 HIMB2 randq 1-3 GeV/c
	"../QVector/HIMinimumBias4/crab_HIMB4_QVector_randq_v1/160617_090047/0000/",	// 12 HIMB4 randq 1-3 GeV/c
};

char const * ftxt[] = {
	"test/",								// 0
	"txt/HIMB3_v1/",							// 1
	"txt/HIMB3_randq_v1/",							// 2
	"txt/HIMB3_randq_v2/",							// 3
	"txt/HIMB1_v1/",							// 4
	"txt/HIMB2_v1/",							// 5
	"txt/HIMB4_v1/",							// 6
	"txt/HIMB_1234_v1/",							// 7
	"txt/Hydjet_v1/",							// 8
	"txt/Hydjet_randq_v1/",							// 9
	"txt/HIMB1_randq_v1/",							// 10
	"txt/HIMB2_randq_v1/",							// 11
	"txt/HIMB4_randq_v1/",							// 12
};

TChain * chV = new TChain("trV");
void addchain(int s1)
{
	std::cout << fname[s1] << std::endl;
	chV->Add(Form("%s/qvector*.root/QVector/trV", fname[s1]));
}

#include <TChain.h>
#include <iostream>

char const * fname[] = {
	"test/",									// 0
	"../QVector/HIMinimumBias3/crab_HIMB3_QVector_v5/160501_180514/0000/",		// 1 1-3 GeV/c
	"../QVector/HIMinimumBias3/crab_HIMB3_QVector_randq_v1/160608_174408/0000/",	// 2 randq 1-3 GeV/c
	"../QVector/HIMinimumBias3/crab_HIMB3_QVector_randq_v2/160609_180344/0000/",	// 3 randq 1-3 GeV/c 0.505 pos
	"../QVector/HIMinimumBias1/crab_HIMB1_QVector_v5_hlt/160619_093028/0000/",	// 4 HIMB1 1-3 GeV/c
	"../QVector/HIMinimumBias2/crab_HIMB2_QVector_v5/160616_103828/0000/",		// 5 HIMB2 1-3 GeV/c
	"../QVector/HIMinimumBias4/crab_HIMB4_QVector_v5/160616_103838/0000/",		// 6 HIMB4 1-3 GeV/c
	"NA",										// 7 merged 1,4,5,6 HIMB[1,2,3,4] 1-3 GeV/c
	"../QVector/Hydjet_Quenched_MinBias_5020GeV_750/crab_Hydjet_QVector_v5/160616_192548/0000/",		// 8 Hydjet 1-3 GeV/c
	"../QVector/Hydjet_Quenched_MinBias_5020GeV_750/crab_Hydjet_QVector_randq_v1/160617_094658/0000/",	// 9 Hydjet randq 1-3 GeV/c
	"../QVector/HIMinimumBias1/crab_HIMB1_QVector_randq_v1_hlt/160619_093149/0000/",	// 10 HIMB1 randq 1-3 GeV/c
	"../QVector/HIMinimumBias2/crab_HIMB2_QVector_randq_v1/160617_090032/0000/",	// 11 HIMB2 randq 1-3 GeV/c
	"../QVector/HIMinimumBias4/crab_HIMB4_QVector_randq_v1/160617_090047/0000/",	// 12 HIMB4 randq 1-3 GeV/c
	"NA",										// 13 merged randq 2,10,11,12 HIMB[1,2,3,4] 1-3 GeV/c
	"../QVector/HIMinimumBias5/crab_HIMB5_QVector_v5/160620_181533/0000/",		// 14 HIMB5 pp rereco 30-100%
	"../QVector/HIMinimumBias5/crab_HIMB5_QVector_randq_v1/160621_094008/0000/",	// 15 HIMB5 pp rereco 30-100% randq
	"../QVector/HIMinimumBias5/crab_HIMB5_QVector_ALICE_v5/160621_102445/0000/",		// 16 HIMB5 pp rereco 30-100% ALICE 0.3 < pT < 5.0 |eta|<0.8
	"../QVector/HIMinimumBias5/crab_HIMB5_QVector_ALICE_randq_v1/160621_102457/0000/",	// 17 HIMB5 pp rereco 30-100% randq ALICE 0.3 < pT < 5.0 |eta|<0.8
	"../QVector/HIMinimumBias5/crab_HIMB5_QVector_eff_ALICE_v5/160622_151042/0000/",	// 18 HIMB5 pp rereco 30-100% eff ALICE 0.3 < pT < 5.0 |eta|<0.8
	"../QVector/HIMinimumBias5/crab_HIMB5_QVector_eff_ALICE_randq_v1/160622_151052/0000/",	// 19 HIMB5 pp rereco 30-100% eff randq ALICE 0.3 < pT < 5.0 |eta|<0.8
	"../QVector/HIMinimumBias5/crab_HIMB5_QVector_ALICE_forward_v1/160624_114653/0000/",	// 20 HIMB5 pp rereco 30-100% ALICE 0.3 < pT < 5.0 -2.4 <eta<-0.8
	"../QVector/HIMinimumBias5/crab_HIMB5_QVector_ALICE_forward_randq_v1/160627_141827/0000/",	// 21 HIMB5 pp rereco 30-100% randq ALICE 0.3 < pT < 5.0 -2.4 <eta<-0.8
	"../QVector/HIMinimumBias5/crab_HIMB5_QVector_ALICE_v6/160628_102151/0000/",			// 22 HIMB5 pp rereco 30-100% ALICE 0.3 < pT < 5.0, |eta|<0.8, pixelLayer > 0
	"../QVector/HIMinimumBias5/crab_HIMB5_QVector_ALICE_v7/160630_094402/0000/",			// 23 HIMB5 pp rereco 30-100% ALICE 0.3 < pT < 5.0, |eta|<0.8, pixelLayer > 0 more update on tracking
	"../QVector/PAHighPt/crab_pPbHM_QVector_v3/160702_092114/0000/",				// 24 pPb HM ALICE pPb+Pbp+rereco
	"../QVector/PAHighPt/crab_pPbHM_QVector_eff_v3/160707_153554/0000/",				// 25 pPb HM ALICE pPb+Pbp+rereco eff
	"../QVector/PAHighPt/crab_pPbHM_QVector_eff_v4/160713_120759/0000/",				// 26 pPb HM ALICE 0.3 < pT < 5.0 pPb+rereco |eta|<0.8 eff
	"../QVector/PAHighPt/crab_pPbHM_QVector_eff_reverse_v4/160713_120810/0000/",			// 27 pPb HM ALICE 0.3 < pT < 5.0 Pbp |eta|<0.8 eff
	"../QVector/PAHighPt/crab_pPbHM_QVector_eff_v5/160714_101155/0000/",				// 28 pPb HM ALICE 0.3 < pT < 5.0 pPb+rereco |eta|<2.4 eff
	"../QVector/PAHighPt/crab_pPbHM_QVector_eff_reverse_v5/160714_101204/0000/",			// 29 pPb HM ALICE 0.3 < pT < 5.0 Pbp |eta|<2.4 eff
	"../QVector/PAHighPt/crab_pPbHM_QVector_eff_v6/160715_134033/0000/",				// 30 pPb HM ALICE 0.3 < pT < 3.0 pPb+rereco |eta|<2.4 eff
	"../QVector/PAHighPt/crab_pPbHM_QVector_eff_reverse_v6/160715_134043/0000/",			// 31 pPb HM ALICE 0.3 < pT < 3.0 Pbp |eta|<2.4 eff
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
	"txt/HIMB_1234_randq_v1/",						// 13
	"txt/HIMB5_pp_v1",							// 14
	"txt/HIMB5_pp_randq_v1",						// 15
	"txt/HIMB5_pp_ALICE_v1",						// 16
	"txt/HIMB5_pp_ALICE_randq_v1",						// 17
	"txt/HIMB5_pp_eff_ALICE_v1",						// 18
	"txt/HIMB5_pp_eff_ALICE_randq_v1",					// 19
	"txt/HIMB5_pp_ALICE_forward_v1",					// 20
	"txt/HIMB5_pp_ALICE_forward_randq_v1",					// 21
	"txt/HIMB5_pp_ALICE_v6",						// 22
	"txt/HIMB5_pp_ALICE_v7",						// 23
	"txt/PA_HM_ALICE",							// 24
	"txt/PA_HM_ALICE_eff",							// 25
	"txt/PA_HM_ALICE_eff_v4",						// 26
	"txt/PA_HM_ALICE_eff_reverse_v4",					// 27
	"txt/PA_HM_ALICE_eff_v5",						// 28
	"txt/PA_HM_ALICE_eff_reverse_v5",					// 29
	"txt/PA_HM_ALICE_eff_v6",						// 30
	"txt/PA_HM_ALICE_eff_reverse_v6",					// 31
};

TChain * chV = new TChain("trV");
void addchain(int s1)
{
	std::cout << fname[s1] << std::endl;
	chV->Add(Form("%s/qvector*.root/QVector/trV", fname[s1]));
	chV->Add(Form("%s/qvector*.root/QVector100/trV", fname[s1]));
	chV->Add(Form("%s/qvector*.root/QVector130/trV", fname[s1]));
	chV->Add(Form("%s/qvector*.root/QVector160/trV", fname[s1]));
	chV->Add(Form("%s/qvector*.root/QVector190/trV", fname[s1]));
	chV->Add(Form("%s/qvector*.root/QVector220/trV", fname[s1]));
}

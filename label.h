#include <TChain.h>
#include <iostream>

char const * fname[] = {
	"test/",									// 0
	"../QVector/HIMinimumBias3/crab_HIMB3_QVector_v1/160411_135103/0000/",		// 1 1-3 GeV/c
};

char const * txt[] = {
	"test/",								// 0
	"txt/HIMB3_v1/",							// 1
}

TChain * chV = new TChain("trV");
void addchain(int s1)
{
	std::cout << fname[s1] << std::endl;
	chV->Add(Form("%s/*.root/QVector/trV", fname[s1]));
}

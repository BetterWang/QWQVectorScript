#include "label.h"
#include "noff.h"

void rebin(int s1 = 1)
{
	TFile * f = new TFile(Form("%s/output.root", ftxt[s1]));
	TH1D *	hQ1c   = (TH1D*) f->Get("hQ1c");
	TH1D *	hQ1w   = (TH1D*) f->Get("hQ1w");
	TH1D *	hQ2    = (TH1D*) f->Get("hQ2");
	TH1D *	hQ2w   = (TH1D*) f->Get("hQ2w");

	TH1D *	hQ1pp  = (TH1D*) f->Get("hQ1pp");
	TH1D *	hQ1nn  = (TH1D*) f->Get("hQ1nn");
	TH1D *	hQ1pn  = (TH1D*) f->Get("hQ1pn");
	TH1D *	hQ1ppw = (TH1D*) f->Get("hQ1ppw");
	TH1D *	hQ1nnw = (TH1D*) f->Get("hQ1nnw");
	TH1D *	hQ1pnw = (TH1D*) f->Get("hQ1pnw");

	TH1D *	hQ2pp  = (TH1D*) f->Get("hQ2pp");
	TH1D *	hQ2nn  = (TH1D*) f->Get("hQ2nn");
	TH1D *	hQ2pn  = (TH1D*) f->Get("hQ2pn");
	TH1D *	hQ2aa  = (TH1D*) f->Get("hQ2aa");
	TH1D *	hQ2nnw = (TH1D*) f->Get("hQ2nnw");
	TH1D *	hQ2ppw = (TH1D*) f->Get("hQ2ppw");
	TH1D *	hQ2pnw = (TH1D*) f->Get("hQ2pnw");
	TH1D *	hQ2aaw = (TH1D*) f->Get("hQ2aaw");

	TH1D *	hQ3pp  = (TH1D*) f->Get("hQ3pp");
	TH1D *	hQ3nn  = (TH1D*) f->Get("hQ3nn");
	TH1D *	hQ3ss  = (TH1D*) f->Get("hQ3ss");
	TH1D *	hQ3pn  = (TH1D*) f->Get("hQ3pn");
	TH1D *	hQ3ppw = (TH1D*) f->Get("hQ3ppw");
	TH1D *	hQ3nnw = (TH1D*) f->Get("hQ3nnw");
	TH1D *	hQ3ssw = (TH1D*) f->Get("hQ3ssw");
	TH1D *	hQ3pnw = (TH1D*) f->Get("hQ3pnw");

	TH1D *	hQ3Sc  = (TH1D*) f->Get("hQ3Sc");

	TH1D *	hCent   = (TH1D*) f->Get("hCent");
	TH1D *	hMult   = (TH1D*) f->Get("hMult");
	TH1D *	hMultp  = (TH1D*) f->Get("hMultp");
	TH1D *	hMultn  = (TH1D*) f->Get("hMultn");

	TH1D *	hv2aa   = (TH1D*) hQ2aa->Clone("hv2aa");
	TH1D *	hv2pp   = (TH1D*) hQ2pp->Clone("hv2pp");
	TH1D *	hv2nn   = (TH1D*) hQ2nn->Clone("hv2nn");
	TH1D *	hv2pn   = (TH1D*) hQ2pn->Clone("hv2pn");

	TH1D *	

	for ( int c = 0; c < 200; c++ ) {
		
	}


}

/*
 * =====================================================================================
 *
 *       Filename:  utility.h
 *
 *    Description:  utility functions needed for plot and data handling
 *
 *        Version:  1.0
 *        Created:  06/08/2016 16:57:36
 *       Revision:  none
 *       Compiler:  ROOT
 *
 *         Author:  Quan Wang
 *   Organization:  CERN
 *
 * =====================================================================================
 */


void splitCanv3(TCanvas * c);
void compare2(TCanvas * c);
void sqrthist(TH1D* h);

//TH2D * rebin2DX(TH2D* h, char * name, int N, const double *xbin)
//{
//	double val = 0;
//	double err = 0;
//
//}


void compare2(TCanvas * c, TH1D* h1, TH1D* h2, string xtitle, string ytitle)
{
	splitCanv3(c);
	double up = std::max(h1->GetMaximum(), h2->GetMaximum());
	double low = std::min(h1->GetMinimum(), h2->GetMinimum());
	TH2D * hframe = new TH2D("hdata", Form(";%s;%s", xtitle.c_str(), ytitle.c_str()), 1, h1->GetXaxis()->GetXmin(), h1->GetXaxis()->GetXmax(), 1, low, up);
	c1->cd(1);
	hframe->Draw();
	h1->Draw("same");
	h2->Draw("same");

	c1->cd(2);
	TH1D * hdiff = (TH1D*) h1->Clone();
	hdiff->Add(h2, -1);
	TH2D * hframediff = new TH2D("hdiff", Form(";%s;Diff", xtitle.c_str()), 1, h1->GetXaxis()->GetXmin(), h1->GetXaxis()->GetXmax(), 1, hdiff->GetMinimum(), hdiff->GetMaximum());
	hframediff->Draw();
	hdiff->Draw("same");

	c1->cd(3);
}

void splitCanv3(TCanvas * c)
{
        if (!c) return;

        c->cd(0);
        TPad * p1 = new TPad("pad1", "Data", 0., 0.6, 1., 1.);
        p1->SetLeftMargin(0.15);
        p1->SetRightMargin(0.05);
        p1->SetBottomMargin(0.);
        p1->SetTopMargin(0.05);
        p1->Draw();
        p1->SetNumber(1);

        TPad * p2 = new TPad("pad2", "Diff", 0., 0.3, 1., 0.6);
        p2->SetLeftMargin(0.15);
        p2->SetRightMargin(0.05);
        p2->SetBottomMargin(0.0);
        p2->SetTopMargin(0.);
        p2->SetGrid();
        p2->Draw();
        p2->SetNumber(2);

        TPad * p3 = new TPad("pad3", "Ratio", 0., 0.0, 1., 0.3);
        p3->SetLeftMargin(0.15);
        p3->SetRightMargin(0.05);
        p3->SetBottomMargin(0.25);
        p3->SetTopMargin(0.);
        p3->SetGrid();
        p3->Draw();
        p3->SetNumber(3);

	c->cd(1);
}




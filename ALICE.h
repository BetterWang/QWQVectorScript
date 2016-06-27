TGraphAsymmErrors * gr_ALICE_3part_tpccumu_ss;
TGraphAsymmErrors * gr_ALICE_3part_tpccumu_os;

TGraphAsymmErrors * gr_ALICE_2part_tpccumu_ss;
TGraphAsymmErrors * gr_ALICE_2part_tpccumu_os;

TGraphAsymmErrors * gr_ALICE_coscos_ss;
TGraphAsymmErrors * gr_ALICE_coscos_os;
TGraphAsymmErrors * gr_ALICE_sinsin_ss;
TGraphAsymmErrors * gr_ALICE_sinsin_os;

void ALICE()
{
	// Plot: p8370_d1x1y2
	double p8370_d1x1y1_xval[] = { 2.5, 7.5, 15.0, 25.0, 35.0, 45.0, 55.0, 65.0, 75.0 };
	double p8370_d1x1y1_xerrminus[] = { 2.5, 2.5, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0 };
	double p8370_d1x1y1_xerrplus[] = { 2.5, 2.5, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0 };
	double p8370_d1x1y1_yval[] = { 0.0, 4.0E-6, -3.0E-6, -1.4E-5, -2.6E-5, -3.9E-5, 2.2E-5, 2.49E-4, 0.001059 };
	double p8370_d1x1y1_yerrminus[] = { 4.0E-6, 5.0E-6, 5.0E-6, 7.0E-6, 1.1E-5, 1.8E-5, 3.6E-5, 8.7E-5, 2.79E-4 };
	double p8370_d1x1y1_yerrplus[] = { 4.0E-6, 5.0E-6, 5.0E-6, 7.0E-6, 1.1E-5, 1.8E-5, 3.6E-5, 8.7E-5, 2.79E-4 };
	double p8370_d1x1y1_ystatminus[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
	double p8370_d1x1y1_ystatplus[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
	int p8370_d1x1y1_numpoints = 9;

	double p8370_d1x1y2_xval[] = { 2.5, 7.5, 15.0, 25.0, 35.0, 45.0, 55.0, 65.0, 75.0 };
	double p8370_d1x1y2_xerrminus[] = { 2.5, 2.5, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0 };
	double p8370_d1x1y2_xerrplus[] = { 2.5, 2.5, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0 };
	double p8370_d1x1y2_yval[] = { -1.6E-5, -2.3E-5, -5.5E-5, -1.06E-4, -1.66E-4, -2.76E-4, -3.79E-4, -4.25E-4, -2.93E-4 };
	double p8370_d1x1y2_yerrminus[] = { 3.0E-6, 3.0E-6, 3.0E-6, 5.0E-6, 8.0E-6, 1.3E-5, 2.6E-5, 6.3E-5, 1.96E-4 };
	double p8370_d1x1y2_yerrplus[] = { 3.0E-6, 3.0E-6, 3.0E-6, 5.0E-6, 8.0E-6, 1.3E-5, 2.6E-5, 6.3E-5, 1.96E-4 };
	double p8370_d1x1y2_ystatminus[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
	double p8370_d1x1y2_ystatplus[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
	int p8370_d1x1y2_numpoints = 9;

	for ( int i = 0; i < 9; i++ ) {
		p8370_d1x1y1_xval[i] *= 2;
		p8370_d1x1y1_xerrminus[i] *= 2;
		p8370_d1x1y1_xerrplus[i] *= 2;
		p8370_d1x1y2_xval[i] *= 2;
		p8370_d1x1y2_xerrminus[i] *= 2;
		p8370_d1x1y2_xerrplus[i] *= 2;
	}

	// Plot: p8370_d5x1y2
	double p8370_d5x1y1_xval[] = { 2.5, 7.5, 15.0, 25.0, 35.0, 45.0, 55.0, 65.0 };
	double p8370_d5x1y1_xerrminus[] = { 2.5, 2.5, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0 };
	double p8370_d5x1y1_xerrplus[] = { 2.5, 2.5, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0 };
	double p8370_d5x1y1_yval[] = { 4.57E-4, 5.61E-4, 7.32E-4, 0.001021, 0.001432, 0.002121, 0.003306, 0.005447 };
	double p8370_d5x1y1_yerrminus[] = { 2.0E-6, 3.0E-6, 3.0E-6, 4.0E-6, 6.324555320336759E-6, 1.0049875621120892E-5, 1.824828759089466E-5, 3.413209633175202E-5 };
	double p8370_d5x1y1_yerrplus[] = { 2.0E-6, 3.0E-6, 3.0E-6, 4.0E-6, 6.324555320336759E-6, 1.0049875621120892E-5, 1.824828759089466E-5, 3.413209633175202E-5 };
	double p8370_d5x1y1_ystatminus[] = { 2.0E-6, 3.0E-6, 3.0E-6, 4.0E-6, 6.0E-6, 1.0E-5, 1.8E-5, 3.4E-5 };
	double p8370_d5x1y1_ystatplus[] = { 2.0E-6, 3.0E-6, 3.0E-6, 4.0E-6, 6.0E-6, 1.0E-5, 1.8E-5, 3.4E-5 };
	int p8370_d5x1y1_numpoints = 8;

	double p8370_d5x1y2_xval[] = { 2.5, 7.5, 15.0, 25.0, 35.0, 45.0, 55.0, 65.0 };
	double p8370_d5x1y2_xerrminus[] = { 2.5, 2.5, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0 };
	double p8370_d5x1y2_xerrplus[] = { 2.5, 2.5, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0 };
	double p8370_d5x1y2_yval[] = { 1.39E-4, 1.78E-4, 2.41E-4, 3.57E-4, 5.02E-4, 7.57E-4, 0.001168, 0.002095 };
	double p8370_d5x1y2_yerrminus[] = { 2.0E-6, 2.0E-6, 2.2360679774997895E-6, 3.1622776601683796E-6, 5.0E-6, 9.899494936611665E-6, 1.4422205101855957E-5, 2.4738633753705964E-5 };
	double p8370_d5x1y2_yerrplus[] = { 2.0E-6, 2.0E-6, 2.2360679774997895E-6, 3.1622776601683796E-6, 5.0E-6, 9.899494936611665E-6, 1.4422205101855957E-5, 2.4738633753705964E-5 };
	double p8370_d5x1y2_ystatminus[] = { 2.0E-6, 2.0E-6, 2.0E-6, 3.0E-6, 4.0E-6, 7.0E-6, 1.2E-5, 2.4E-5 };
	double p8370_d5x1y2_ystatplus[] = { 2.0E-6, 2.0E-6, 2.0E-6, 3.0E-6, 4.0E-6, 7.0E-6, 1.2E-5, 2.4E-5 };
	int p8370_d5x1y2_numpoints = 8;

	for ( int i = 0; i < 8; i++ ) {
		p8370_d5x1y1_xval[i] *=2;
		p8370_d5x1y1_xerrminus[i] *=2;
		p8370_d5x1y1_xerrplus[i] *=2;
		p8370_d5x1y2_xval[i] *= 2;
		p8370_d5x1y2_xerrminus[i] *= 2;
		p8370_d5x1y2_xerrplus[i] *= 2;
	}


	gr_ALICE_3part_tpccumu_os = new TGraphAsymmErrors(p8370_d1x1y1_numpoints, p8370_d1x1y1_xval, p8370_d1x1y1_yval, p8370_d1x1y1_xerrminus, p8370_d1x1y1_xerrplus, p8370_d1x1y1_yerrminus, p8370_d1x1y1_yerrplus);
	gr_ALICE_3part_tpccumu_os->SetName("/HepData/8370/d1x1y1");
	gr_ALICE_3part_tpccumu_os->SetTitle("/HepData/8370/d1x1y1");
	gr_ALICE_3part_tpccumu_ss = new TGraphAsymmErrors(p8370_d1x1y2_numpoints, p8370_d1x1y2_xval, p8370_d1x1y2_yval, p8370_d1x1y2_xerrminus, p8370_d1x1y2_xerrplus, p8370_d1x1y2_yerrminus, p8370_d1x1y2_yerrplus);
	gr_ALICE_3part_tpccumu_ss->SetName("/HepData/8370/d1x1y2");
	gr_ALICE_3part_tpccumu_ss->SetTitle("/HepData/8370/d1x1y2");


	gr_ALICE_3part_tpccumu_ss->SetMarkerStyle(kOpenCircle);
	gr_ALICE_3part_tpccumu_os->SetMarkerStyle(kOpenCircle);

	gr_ALICE_3part_tpccumu_ss->SetMarkerColor(kRed);
	gr_ALICE_3part_tpccumu_ss->SetLineColor(kRed);

	gr_ALICE_3part_tpccumu_os->SetMarkerColor(kBlue);
	gr_ALICE_3part_tpccumu_os->SetLineColor(kBlue);

	gr_ALICE_3part_tpccumu_ss->SetMarkerSize(1.0);
	gr_ALICE_3part_tpccumu_os->SetMarkerSize(1.0);


	gr_ALICE_2part_tpccumu_os = new TGraphAsymmErrors(p8370_d5x1y1_numpoints, p8370_d5x1y1_xval, p8370_d5x1y1_yval, p8370_d5x1y1_xerrminus, p8370_d5x1y1_xerrplus, p8370_d5x1y1_yerrminus, p8370_d5x1y1_yerrplus);
	gr_ALICE_2part_tpccumu_os->SetName("/HepData/8370/d5x1y1");
	gr_ALICE_2part_tpccumu_os->SetTitle("/HepData/8370/d5x1y1");
	gr_ALICE_2part_tpccumu_ss = new TGraphAsymmErrors(p8370_d5x1y2_numpoints, p8370_d5x1y2_xval, p8370_d5x1y2_yval, p8370_d5x1y2_xerrminus, p8370_d5x1y2_xerrplus, p8370_d5x1y2_yerrminus, p8370_d5x1y2_yerrplus);
	gr_ALICE_2part_tpccumu_ss->SetName("/HepData/8370/d5x1y2");
	gr_ALICE_2part_tpccumu_ss->SetTitle("/HepData/8370/d5x1y2");

	gr_ALICE_2part_tpccumu_ss->SetMarkerStyle(kOpenCircle);
	gr_ALICE_2part_tpccumu_os->SetMarkerStyle(kOpenCircle);

	gr_ALICE_2part_tpccumu_ss->SetMarkerColor(kRed);
	gr_ALICE_2part_tpccumu_ss->SetLineColor(kRed);

	gr_ALICE_2part_tpccumu_os->SetMarkerColor(kBlue);
	gr_ALICE_2part_tpccumu_os->SetLineColor(kBlue);

	gr_ALICE_2part_tpccumu_ss->SetMarkerSize(1.0);
	gr_ALICE_2part_tpccumu_os->SetMarkerSize(1.0);


	double p8370_d6x1y1_xval[] = { 2.5, 7.5, 15.0, 25.0, 35.0, 45.0, 55.0, 65.0, 75.0 };
	double p8370_d6x1y1_xerrminus[] = { 2.5, 2.5, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0 };
	double p8370_d6x1y1_xerrplus[] = { 2.5, 2.5, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0 };
	double p8370_d6x1y1_yval[] = { 2.28E-4, 2.82E-4, 3.64E-4, 5.03E-4, 7.03E-4, 0.001041, 0.001664, 0.002848, 0.005128 };
	double p8370_d6x1y1_yerrminus[] = { 1.8110770276274833E-5, 9.486832980505138E-6, 4.242640687119286E-6, 7.211102550927978E-6, 1.8973665961010275E-5, 2.3259406699226016E-5, 4.47213595499958E-5, 9.192388155425118E-5, 2.1298121982935491E-4 };
	double p8370_d6x1y1_yerrplus[] = { 1.8110770276274833E-5, 9.486832980505138E-6, 4.242640687119286E-6, 7.211102550927978E-6, 1.8973665961010275E-5, 2.3259406699226016E-5, 4.47213595499958E-5, 9.192388155425118E-5, 2.1298121982935491E-4 };
	double p8370_d6x1y1_ystatminus[] = { 2.0E-6, 3.0E-6, 3.0E-6, 4.0E-6, 6.0E-6, 1.0E-5, 2.0E-5, 4.7E-5, 1.45E-4 };
	double p8370_d6x1y1_ystatplus[] = { 2.0E-6, 3.0E-6, 3.0E-6, 4.0E-6, 6.0E-6, 1.0E-5, 2.0E-5, 4.7E-5, 1.45E-4 };
	int p8370_d6x1y1_numpoints = 9;

	double p8370_d6x1y2_xval[] = { 2.5, 7.5, 15.0, 25.0, 35.0, 45.0, 55.0, 65.0, 75.0 };
	double p8370_d6x1y2_xerrminus[] = { 2.5, 2.5, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0 };
	double p8370_d6x1y2_xerrplus[] = { 2.5, 2.5, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0 };
	double p8370_d6x1y2_yval[] = { 6.2E-5, 7.7E-5, 9.3E-5, 1.25E-4, 1.68E-4, 2.4E-4, 3.94E-4, 8.35E-4, 0.001818 };
	double p8370_d6x1y2_yerrminus[] = { 1.8110770276274833E-5, 8.246211251235321E-6, 6.324555320336759E-6, 1.0440306508910551E-5, 2.0396078054371142E-5, 4.5541190146942804E-5, 5.4817880294662984E-5, 1.218400590938793E-4, 1.8890473789717397E-4 };
	double p8370_d6x1y2_yerrplus[] = { 1.8110770276274833E-5, 8.246211251235321E-6, 6.324555320336759E-6, 1.0440306508910551E-5, 2.0396078054371142E-5, 4.5541190146942804E-5, 5.4817880294662984E-5, 1.218400590938793E-4, 1.8890473789717397E-4 };
	double p8370_d6x1y2_ystatminus[] = { 2.0E-6, 2.0E-6, 2.0E-6, 3.0E-6, 4.0E-6, 7.0E-6, 1.4E-5, 3.4E-5, 1.02E-4 };
	double p8370_d6x1y2_ystatplus[] = { 2.0E-6, 2.0E-6, 2.0E-6, 3.0E-6, 4.0E-6, 7.0E-6, 1.4E-5, 3.4E-5, 1.02E-4 };
	int p8370_d6x1y2_numpoints = 9;


	double p8370_d7x1y1_xval[] = { 2.5, 7.5, 15.0, 25.0, 35.0, 45.0, 55.0, 65.0, 75.0 };
	double p8370_d7x1y1_xerrminus[] = { 2.5, 2.5, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0 };
	double p8370_d7x1y1_xerrplus[] = { 2.5, 2.5, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0 };
	double p8370_d7x1y1_yval[] = { 2.28E-4, 2.78E-4, 3.68E-4, 5.18E-4, 7.29E-4, 0.00108, 0.001642, 0.002599, 0.004069 };
	double p8370_d7x1y1_yerrminus[] = { 1.8110770276274833E-5, 9.486832980505138E-6, 4.242640687119286E-6, 7.211102550927978E-6, 1.8973665961010275E-5, 2.3259406699226016E-5, 4.47213595499958E-5, 9.192388155425118E-5, 2.1298121982935491E-4 };
	double p8370_d7x1y1_yerrplus[] = { 1.8110770276274833E-5, 9.486832980505138E-6, 4.242640687119286E-6, 7.211102550927978E-6, 1.8973665961010275E-5, 2.3259406699226016E-5, 4.47213595499958E-5, 9.192388155425118E-5, 2.1298121982935491E-4 };
	double p8370_d7x1y1_ystatminus[] = { 2.0E-6, 3.0E-6, 3.0E-6, 4.0E-6, 6.0E-6, 1.0E-5, 2.0E-5, 4.7E-5, 1.45E-4 };
	double p8370_d7x1y1_ystatplus[] = { 2.0E-6, 3.0E-6, 3.0E-6, 4.0E-6, 6.0E-6, 1.0E-5, 2.0E-5, 4.7E-5, 1.45E-4 };
	int p8370_d7x1y1_numpoints = 9;

	double p8370_d7x1y2_xval[] = { 2.5, 7.5, 15.0, 25.0, 35.0, 45.0, 55.0, 65.0, 75.0 };
	double p8370_d7x1y2_xerrminus[] = { 2.5, 2.5, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0 };
	double p8370_d7x1y2_xerrplus[] = { 2.5, 2.5, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0 };
	double p8370_d7x1y2_yval[] = { 7.8E-5, 1.0E-4, 1.48E-4, 2.31E-4, 3.34E-4, 5.17E-4, 7.73E-4, 0.00126, 0.002112 };
	double p8370_d7x1y2_yerrminus[] = { 1.8110770276274833E-5, 8.246211251235321E-6, 6.324555320336759E-6, 1.0440306508910551E-5, 2.0396078054371142E-5, 4.5541190146942804E-5, 5.4817880294662984E-5, 1.218400590938793E-4, 1.8890473789717397E-4 };
	double p8370_d7x1y2_yerrplus[] = { 1.8110770276274833E-5, 8.246211251235321E-6, 6.324555320336759E-6, 1.0440306508910551E-5, 2.0396078054371142E-5, 4.5541190146942804E-5, 5.4817880294662984E-5, 1.218400590938793E-4, 1.8890473789717397E-4 };
	double p8370_d7x1y2_ystatminus[] = { 2.0E-6, 2.0E-6, 2.0E-6, 3.0E-6, 4.0E-6, 7.0E-6, 1.4E-5, 3.4E-5, 1.02E-4 };
	double p8370_d7x1y2_ystatplus[] = { 2.0E-6, 2.0E-6, 2.0E-6, 3.0E-6, 4.0E-6, 7.0E-6, 1.4E-5, 3.4E-5, 1.02E-4 };
	int p8370_d7x1y2_numpoints = 9;


	for ( int i = 0; i < 9; i++ ) {
		p8370_d6x1y1_xval[i] *= 2;
		p8370_d6x1y1_xerrminus[i] *= 2;
		p8370_d6x1y1_xerrplus[i] *= 2;

		p8370_d6x1y2_xval[i] *= 2;
		p8370_d6x1y2_xerrminus[i] *= 2;
		p8370_d6x1y2_xerrplus[i] *= 2;

		p8370_d7x1y1_xval[i] *= 2;
		p8370_d7x1y1_xerrminus[i] *= 2;
		p8370_d7x1y1_xerrplus[i] *= 2;

		p8370_d7x1y2_xval[i] *= 2;
		p8370_d7x1y2_xerrminus[i] *= 2;
		p8370_d7x1y2_xerrplus[i] *= 2;
	}


	gr_ALICE_sinsin_os = new TGraphAsymmErrors(p8370_d7x1y1_numpoints, p8370_d7x1y1_xval, p8370_d7x1y1_yval, p8370_d7x1y1_xerrminus, p8370_d7x1y1_xerrplus, p8370_d7x1y1_yerrminus, p8370_d7x1y1_yerrplus);
	gr_ALICE_sinsin_os->SetName("/HepData/8370/d7x1y1");
	gr_ALICE_sinsin_os->SetTitle("/HepData/8370/d7x1y1");
	gr_ALICE_sinsin_ss = new TGraphAsymmErrors(p8370_d7x1y2_numpoints, p8370_d7x1y2_xval, p8370_d7x1y2_yval, p8370_d7x1y2_xerrminus, p8370_d7x1y2_xerrplus, p8370_d7x1y2_yerrminus, p8370_d7x1y2_yerrplus);
	gr_ALICE_sinsin_ss->SetName("/HepData/8370/d7x1y2");
	gr_ALICE_sinsin_ss->SetTitle("/HepData/8370/d7x1y2");


	gr_ALICE_coscos_os = new TGraphAsymmErrors(p8370_d6x1y1_numpoints, p8370_d6x1y1_xval, p8370_d6x1y1_yval, p8370_d6x1y1_xerrminus, p8370_d6x1y1_xerrplus, p8370_d6x1y1_yerrminus, p8370_d6x1y1_yerrplus);
	gr_ALICE_coscos_os->SetName("/HepData/8370/d6x1y1");
	gr_ALICE_coscos_os->SetTitle("/HepData/8370/d6x1y1");
	gr_ALICE_coscos_ss = new TGraphAsymmErrors(p8370_d6x1y2_numpoints, p8370_d6x1y2_xval, p8370_d6x1y2_yval, p8370_d6x1y2_xerrminus, p8370_d6x1y2_xerrplus, p8370_d6x1y2_yerrminus, p8370_d6x1y2_yerrplus);
	gr_ALICE_coscos_ss->SetName("/HepData/8370/d6x1y2");
	gr_ALICE_coscos_ss->SetTitle("/HepData/8370/d6x1y2");


	gr_ALICE_coscos_os->SetMarkerStyle(kOpenCircle);
	gr_ALICE_coscos_ss->SetMarkerStyle(kOpenCircle);
	gr_ALICE_sinsin_os->SetMarkerStyle(kOpenCircle);
	gr_ALICE_sinsin_ss->SetMarkerStyle(kOpenCircle);

	gr_ALICE_coscos_os->SetMarkerSize(1.0);
	gr_ALICE_coscos_ss->SetMarkerSize(1.0);
	gr_ALICE_sinsin_os->SetMarkerSize(1.0);
	gr_ALICE_sinsin_ss->SetMarkerSize(1.0);

	gr_ALICE_coscos_os->SetMarkerColor(kBlue);
	gr_ALICE_coscos_ss->SetMarkerColor(kRed);
	gr_ALICE_sinsin_os->SetMarkerColor(kBlue);
	gr_ALICE_sinsin_ss->SetMarkerColor(kRed);

	gr_ALICE_coscos_os->SetLineColor(kBlue);
	gr_ALICE_coscos_ss->SetLineColor(kRed);
	gr_ALICE_sinsin_os->SetLineColor(kBlue);
	gr_ALICE_sinsin_ss->SetLineColor(kRed);

}

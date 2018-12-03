void half(){

  TFile * files[12] = {};

  files[0] = TFile::Open("ROC0p005.root");
  files[1] = TFile::Open("ROC0p01.root");
  files[2] = TFile::Open("ROC0p02.root");
  files[3] = TFile::Open("ROC0p03.root");
  files[4] = TFile::Open("ROC0p05.root");
  files[5] = TFile::Open("ROC0p10.root");
  files[6] = TFile::Open("ROC0p15.root");
  files[7] = TFile::Open("ROC0p20.root");
  files[8] = TFile::Open("ROC0p30.root");
  files[9] = TFile::Open("ROC0p50.root");
  files[10] = TFile::Open("ROC0p75.root");
  files[11] = TFile::Open("ROCFull.root");
  const double totjets = 147000000.0;
  double jets[12] = {0.005*totjets,0.01*totjets,0.02*totjets,0.03*totjets,0.05*totjets,0.1*totjets,0.15*totjets,0.2*totjets,0.3*totjets,0.5*totjets,0.75*totjets,totjets};
  TGraph * graphlvsb[12] = {};
  TGraph * graphcvsb[12] = {};
  for(int z = 0; z < 12; z++){
    graphlvsb[z] = (TGraph*)files[z]->Get("roccurve_0");
    graphcvsb[z] = (TGraph*)files[z]->Get("roccurve_1");
  }
  double x = 0.0;
  double y = 0.0;
  double yc = 0.0;
  double lvsbwp1[12] = {};
  double lvsbwp2[12] = {};
  double lvsbwp3[12] = {};
  double cvsbwp1[12] = {};
  double cvsbwp2[12] = {};
  double cvsbwp3[12] = {};
  cout << graphcvsb[3]->Eval(0.1) << endl;
  for(int z = 0; z < 12; z++){
    y = 0.0;
    yc = 0.0;
    for(int n = 0; n<1000; n++){
      x = n*(1.0/999.0);
      y = graphlvsb[z]->Eval(x);
      yc = graphcvsb[z]->Eval(x);
      if( std::abs(y-0.1) < 0.002){
	lvsbwp1[z] = x;
      }
      if( std::abs(y-0.01) < 0.0001){
	lvsbwp2[z] = x;
      }
      if( std::abs(y-0.001) < 0.0001){
	lvsbwp3[z] = x;
      }
      if( std::abs(yc-0.1) < 0.002){
	cvsbwp1[z] = x;
      }
      if( std::abs(yc-0.01) < 0.0001){
	cvsbwp2[z] = x;
      }
      if( std::abs(yc-0.001) < 0.0001){
	cvsbwp3[z] = x;
      }      

    }
  }
  gr1 = new TGraph(12,jets,lvsbwp1);
  gr2 = new TGraph(12,jets,lvsbwp2);
  gr3 = new TGraph(12,jets,lvsbwp3);
  gr4 = new TGraph(12,jets,cvsbwp1);
  gr5 = new TGraph(12,jets,cvsbwp2);
  gr6 = new TGraph(12,jets,cvsbwp3);

  TCanvas *c1 = new TCanvas("c1", "ROCS",50,50,1500,800);
  c1->SetLogx();
  c1->SetGrid();
  gr1->SetTitle("B-tag efficiency vs training sample size");
  gr1->Draw("ACP");
  gr1->SetLineColor(2);
  gr1->GetYaxis()->SetRangeUser(0.01,1.0);
  gr1->GetXaxis()->SetTitle("number of jets");
  gr1->GetYaxis()->SetTitle("b-tag efficiency");
  gr2->Draw("CP");
  gr2->SetLineColor(4);
  gr3->Draw("CP");
  gr3->SetLineColor(kGreen+3);
  gr4->Draw("CP");
  gr4->SetLineColor(2);
  gr4->SetLineStyle(10);
  gr5->Draw("CP");
  gr5->SetLineColor(4);
  gr5->SetLineStyle(10);
  //  gr6->Draw("CP");
  gr6->SetLineColor(3);
  gr6->SetLineStyle(10);
  gr1->SetLineWidth(2);
  gr2->SetLineWidth(2);
  gr3->SetLineWidth(2);
  gr4->SetLineWidth(2);
  gr5->SetLineWidth(2);
  gr6->SetLineWidth(2);
  auto legend = new TLegend(0.28,0.65,0.48,0.8);
  legend->AddEntry(gr1,"mistag 0.1","l");
  legend->AddEntry(gr2,"mistag 0.01","l");
  legend->AddEntry(gr3,"mistag 0.001","l");
  legend->Draw();
}

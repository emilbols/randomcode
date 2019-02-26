{
  TCanvas *c16 = new TCanvas("c16", "ROCS",50,50,1200,900);
  c16->SetGrid();
  TFile f1("DFOrg.root");
  TFile f2("DFPrunedROC.root");
  TGraph *lvsb1 = (TGraph*)f1.Get("roccurve_0");
  TGraph *cvsb1 = (TGraph*)f1.Get("roccurve_1");
  TGraph *lvsb2 = (TGraph*)f2.Get("roccurve_0");
  TGraph *cvsb2 = (TGraph*)f2.Get("roccurve_1");
  lvsb1->SetLineColor(kRed);
  cvsb1->SetLineColor(kRed);
  lvsb2->SetLineColor(kBlue);
  cvsb2->SetLineColor(kBlue);
  lvsb1->SetLineWidth(2);
  cvsb1->SetLineWidth(2);
  lvsb2->SetLineWidth(2);
  cvsb2->SetLineWidth(2);  
  cvsb1->Draw();
  lvsb1->Draw("same");
  lvsb2->Draw("same");
  cvsb2->Draw("same");
  cvsb1->SetTitle("Comparison between Pruned and Full DF in CMSSW");
  c16->Update();
}

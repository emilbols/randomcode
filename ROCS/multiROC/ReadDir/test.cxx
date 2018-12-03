
void test(){
  TFile * files[2] = {};
  files[0] = TFile::Open("ROC2.root");
  files[1] = TFile::Open("DeepCSVOld.root");
  TGraph * graphlvsb[2] = {};
  TGraph * graphcvsb[2] = {};
  for(int z = 0; z < 2; z++){
    graphlvsb[z] = (TGraph*)files[z]->Get("roccurve_0");
    graphcvsb[z] = (TGraph*)files[z]->Get("roccurve_1");
    graphcvsb[z]->SetLineStyle(10);
  }
  TCanvas *c1 = new TCanvas("c1", "ROCS",50,50,1500,800);
  c1->SetLogy();
  c1->SetGrid();
  graphlvsb[0]->Draw();
  graphcvsb[0]->Draw("same");
  graphlvsb[0]->SetLineColor(kGreen);
  graphcvsb[0]->SetLineColor(kGreen);
  graphlvsb[0]->SetFillColor(kGreen);
  graphcvsb[0]->SetFillColor(kGreen);
  graphlvsb[1]->Draw("same");
  graphcvsb[1]->Draw("same");
  graphlvsb[1]->SetLineColor(kRed);
  graphcvsb[1]->SetLineColor(kRed);
  graphlvsb[1]->SetFillColor(kRed);
  graphcvsb[1]->SetFillColor(kRed);
  auto legend = new TLegend(0.28,0.65,0.48,0.8);
  legend->AddEntry(graphlvsb[0],"vertex dependent model","f");
  legend->AddEntry(graphlvsb[1],"track dependent model","f");
  legend->Draw();
}

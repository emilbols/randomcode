#include <TMultiGraph.h>

void TT_LABEL(Double_t x,Double_t y){
  TLatex l; //l.SetTextAlign(12); l.SetTextSize(tsize);
  l.SetNDC();
  l.SetTextFont(42);
  l.SetTextColor(kBlack);
  l.SetTextSize(0.04);
  l.DrawLatex(x,y,"QCD events ");
}
void PT_LABEL_30(Double_t x,Double_t y){
  TLatex l; //l.SetTextAlign(12); l.SetTextSize(tsize);
  l.SetNDC();
  l.SetTextFont(42);
  l.SetTextColor(kBlack);
  l.SetTextSize(0.04);
  l.DrawLatex(x,y,"AK4jets (p_{T} > 600 GeV) ");
}

void limited(){
  TFile * files[3] = {};
  
  files[0] = TFile::Open("DeepCSV_0p15_HighPTMore.root");    
  files[1] = TFile::Open("DeepCSV_1p00_HighPTMore2.root");
  files[2] = TFile::Open("DeepCSV_0p02_HighPTMore.root");

  TGraph * graphlvsb[3] = {};
  TGraph * graphcvsb[3] = {};
  auto mg1  = new TMultiGraph();
  auto mg2  = new TMultiGraph();
  auto legend = new TLegend(0.28,0.65,0.48,0.8);
  for(int z = 0; z < 3; z++){
    graphlvsb[z] = (TGraph*)files[z]->Get("roccurve_0");
    graphlvsb[z]->SetLineColor(1+z);
    graphlvsb[z]->SetFillColor(1+z);
    graphcvsb[z] = (TGraph*)files[z]->Get("roccurve_1");
    graphcvsb[z]->SetLineStyle(10);
    graphcvsb[z]->SetLineColor(1+z);
    graphcvsb[z]->SetFillColor(1+z);
  }
  graphlvsb[0]->SetLineColor(kRed);
  graphcvsb[0]->SetLineColor(kRed);
  graphlvsb[1]->SetLineColor(kBlue);
  graphcvsb[1]->SetLineColor(kBlue);
  graphlvsb[2]->SetLineColor(kBlack);
  graphcvsb[2]->SetLineColor(kBlack);
  graphlvsb[0]->SetFillColor(kRed);
  graphcvsb[0]->SetFillColor(kRed);
  graphlvsb[1]->SetFillColor(kBlue);
  graphcvsb[1]->SetFillColor(kBlue);
  graphlvsb[2]->SetFillColor(kBlack);
  graphcvsb[2]->SetFillColor(kBlack);
    mg1->Add(graphlvsb[0]);
    mg2->Add(graphcvsb[0]);
    mg1->Add(graphlvsb[1]);
    mg2->Add(graphcvsb[1]);
    mg1->Add(graphlvsb[2]);
    mg2->Add(graphcvsb[2]);

  TCanvas *c1 = new TCanvas("c1", "ROCS",50,50,1500,800);
  c1->SetGrid();
  graphlvsb[0]->SetTitle("QCD pt > 600GeV");
  mg1->Draw("aC");
  mg2->Draw("C");
  mg1->GetXaxis()->SetRangeUser(0,1);
  mg1->SetTitle("QCD pt > 600GeV");
  mg1->GetXaxis()->SetTitle("B-jet efficiency");
  mg1->GetYaxis()->SetRangeUser(0.0005,1);
  mg1->GetYaxis()->SetTitle("misid. probability");
  c1->SetLogy();
  c1->Update();
  TT_LABEL(0.14,0.772);
  PT_LABEL_30(0.14,0.722);
  legend->AddEntry(graphlvsb[2],"2.94 mil jets","f");
  legend->AddEntry(graphlvsb[0],"22.05 mil jets","f");
  legend->AddEntry(graphlvsb[1],"147 mil jets","f");

  legend->Draw();  
}

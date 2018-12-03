#include <TMultiGraph.h>

void TT_LABEL(Double_t x,Double_t y){
  TLatex l; //l.SetTextAlign(12); l.SetTextSize(tsize);
  l.SetNDC();
  l.SetTextFont(42);
  l.SetTextColor(kBlack);
  l.SetTextSize(0.04);
  l.DrawLatex(x,y,"t#bar{t} events ");
}
void PT_LABEL_30(Double_t x,Double_t y){
  TLatex l; //l.SetTextAlign(12); l.SetTextSize(tsize);
  l.SetNDC();
  l.SetTextFont(42);
  l.SetTextColor(kBlack);
  l.SetTextSize(0.04);
  l.DrawLatex(x,y,"AK4jets (p_{T} > 30 GeV) ");
}


void limited(){
  TFile * files[5] = {};
  
  files[0] = TFile::Open("DeepCSV_skim_ttBar.root");   
  files[1] = TFile::Open("ROCFull.root");
  TGraph * graphlvsb[5] = {};
  TGraph * graphcvsb[5] = {};
  auto mg1  = new TMultiGraph();
  auto mg2  = new TMultiGraph();
  auto legend = new TLegend(0.28,0.65,0.48,0.8);
  for(int z = 0; z < 2; z++){
    graphlvsb[z] = (TGraph*)files[z]->Get("roccurve_0");
    graphlvsb[z]->SetLineColor(1+z);
    graphlvsb[z]->SetFillColor(1+z);
    graphcvsb[z] = (TGraph*)files[z]->Get("roccurve_1");
    graphcvsb[z]->SetLineStyle(10);
    graphcvsb[z]->SetLineColor(1+z);
    graphcvsb[z]->SetFillColor(1+z);
    mg1->Add(graphlvsb[z]);
    mg2->Add(graphcvsb[z]);

  }
  //graphlvsb[0]->SetLineColor(4);
  //graphcvsb[0]->SetLineColor(4);
  //graphlvsb[1]->SetFillColor(4);
  //graphcvsb[1]->SetFillColor(4);
  TCanvas *c1 = new TCanvas("c1", "ROCS",50,50,1500,800);
  c1->SetGrid();
  mg1->Draw("aC");
  mg2->Draw("C");
  mg1->GetXaxis()->SetRangeUser(0,1);
  mg1->SetNameTitle("TT-bar 30 > pt","TT-bar 30 > pt");
  mg1->GetXaxis()->SetTitle("B-jet efficiency");
  mg1->GetYaxis()->SetRangeUser(0.0005,1);
  mg1->GetYaxis()->SetTitle("misid. probability");
  c1->SetLogy();
  c1->Update();

  TT_LABEL(0.14,0.772);
  PT_LABEL_30(0.14,0.722);
  
   legend->AddEntry(graphlvsb[0],"Skimmed","f");
  legend->AddEntry(graphlvsb[1],"Full","f");

  legend->Draw();  
}

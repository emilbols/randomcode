#include <TMultiGraph.h>
#include "tdrstyle.C"
#include "CMS_lumi.C"
void CMS_LABEL(Double_t x,Double_t y){
    TLatex l; //l.SetTextAlign(12); l.SetTextSize(tsize); 
    l.SetNDC();
    l.SetTextFont(72);
    l.SetTextColor(kBlack);
    l.SetTextSize(0.05);
    l.DrawLatex(x,y,"#bf{Preliminary}");
}
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
  l.DrawLatex(x,y,"AK4jets (p_{T} > 200 GeV) ");
}


void limited(){


  writeExtraText = false;       // if extra text
  extraText  = "t#bar{t} events";  // default extra text is "Preliminary"
  lumi_sqrtS = "#sqrt{s} = 13 TeV";
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetCanvasColor(kWhite);
  gStyle->SetLegendBorderSize(1);
  gStyle->SetLabelColor(1, "XYZ");
  gStyle->SetLabelFont(42, "XYZ");
  gStyle->SetLabelOffset(0.007, "XYZ");
  gStyle->SetLabelSize(0.04, "XYZ");
  gStyle->SetAxisColor(1, "XYZ");
  gStyle->SetStripDecimals(kTRUE);
  gStyle->SetTickLength(0.03, "XYZ");
  gStyle->SetNdivisions(510, "XYZ");
  gStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
  gStyle->SetPadTickY(1);
  gStyle->SetTitleColor(1, "XYZ");
  gStyle->SetTitleFont(42, "XYZ");
  gStyle->SetTitleSize(0.045, "XYZ");
  // tdrStyle->SetTitleXSize(Float_t size = 0.02); // Another way to set the size?
  // tdrStyle->SetTitleYSize(Float_t size = 0.02);
  gStyle->SetTitleXOffset(0.9);
  gStyle->SetTitleYOffset(1.15);

  TFile * files[5] = {};
  
  files[0] = TFile::Open("DF_frac0p02_Skim_Final_ttBarHad_200.root");  
  files[1] = TFile::Open("DF_frac0p30_Skim_Final_ttBarHad_200.root");  
  files[2] = TFile::Open("DFRNN_lrpSkimV2_cuttracks_v2_ttbarhad_200.root"); //DFRNN_lrpSkimV2_cuttracks_v2_ttbarhad_200.root 
  files[3] = TFile::Open("DF_frac0p50_Skim_Final_ttBarHad_200.root");
  //files[3] = TFile::Open("DeepFlavour10Xon94X.root");	
  TGraph * graphlvsb[4] = {};
  TGraph * graphcvsb[4] = {};
  auto mg1  = new TMultiGraph();
  auto mg2  = new TMultiGraph();
  auto legend = new TLegend(0.1375,0.53,0.3377,0.686);
  for(int z = 0; z < 4; z++){
    graphlvsb[z] = (TGraph*)files[z]->Get("roccurve_0");
    graphlvsb[z]->SetLineColor(1+z);
    graphlvsb[z]->SetFillColor(1+z);
    graphcvsb[z] = (TGraph*)files[z]->Get("roccurve_1");
    graphcvsb[z]->SetLineStyle(7);
    graphcvsb[z]->SetLineColor(1+z);
    graphcvsb[z]->SetFillColor(1+z);
    graphlvsb[z]->SetLineWidth(2); 
    graphcvsb[z]->SetLineWidth(2);
    if(z < 4){
    	mg1->Add(graphlvsb[z]);
    	mg2->Add(graphcvsb[z]);
    }
  }
  TCanvas *c1 = new TCanvas("c1", "ROCS",50,50,1200,900);
  c1->SetGrid();
  graphlvsb[0]->SetLineColor(kGreen+3);
  graphcvsb[0]->SetLineColor(kGreen+3);
  graphlvsb[0]->SetFillColor(kGreen+3);
  graphcvsb[0]->SetFillColor(kGreen+3);
  graphlvsb[2]->SetLineColor(kBlue);
  graphcvsb[2]->SetLineColor(kBlue);
  graphlvsb[2]->SetFillColor(kBlue);
  graphcvsb[2]->SetFillColor(kBlue);
  graphlvsb[3]->SetLineColor(kBlack);
  graphcvsb[3]->SetLineColor(kBlack);
  mg1->Draw("aC");
  mg2->Draw("C");
  mg1->GetXaxis()->SetRangeUser(0,1);
  mg1->SetNameTitle("TT-bar 200 > pt","TT-bar 200 > pt");
  mg1->GetXaxis()->SetTitle("b jet efficiency");
  mg1->GetYaxis()->SetRangeUser(0.0005,1);
  mg1->GetYaxis()->SetTitle("misid. probability");
  c1->SetLogy();
  c1->Update();
  CMS_lumi( c1, 0, 11 );
  CMS_LABEL(0.535,0.812);
  TT_LABEL(0.14,0.772);
  PT_LABEL_30(0.14,0.722);
  
  legend->AddEntry(graphlvsb[0],"1.97M jets","l");
  legend->AddEntry(graphlvsb[1],"29.1M jets","l");
  legend->AddEntry(graphlvsb[3],"49.3M jets","l");
  legend->AddEntry(graphlvsb[2],"98.5M jets","l");

  legend->Draw();  
  //auto legend2 = new TLegend(0.1375,0.4064,0.3377,0.50287);
  //legend2->AddEntry(graphlvsb[3],"udsg","l");
  //legend2->AddEntry(graphcvsb[3],"c","l");
  //legend2->Draw();
}

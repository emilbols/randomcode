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
    l.DrawLatex(x,y,"AK4jets (p_{T} > 30 GeV) ");
}
void PT_LABEL_90(Double_t x,Double_t y){
    TLatex l; //l.SetTextAlign(12); l.SetTextSize(tsize); 
    l.SetNDC();
    l.SetTextFont(42);
    l.SetTextColor(kBlack);
    l.SetTextSize(0.04);
    l.DrawLatex(x,y,"AK4jets (p_{T} > 90 GeV) ");
}
void PT_LABEL_200(Double_t x,Double_t y){
    TLatex l; //l.SetTextAlign(12); l.SetTextSize(tsize); 
    l.SetNDC();
    l.SetTextFont(42);
    l.SetTextColor(kBlack);
    l.SetTextSize(0.04);
    l.DrawLatex(x,y,"AK4jets (p_{T} > 200 GeV) ");
}
void PT_LABEL_300(Double_t x,Double_t y){
    TLatex l; //l.SetTextAlign(12); l.SetTextSize(tsize); 
    l.SetNDC();
    l.SetTextFont(42);
    l.SetTextColor(kBlack);
    l.SetTextSize(0.04);
    l.DrawLatex(x,y,"AK4jets (p_{T} > 300 GeV) ");
}

void NoPuppi(){
  //gROOT->LoadMacro("tdrstyle.C");
  //setTDRStyle();
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
  writeExtraText = false;       // if extra text
  extraText  = "t#bar{t} events";  // default extra text is "Preliminary"
  //lumi_sqrtS = "#sqrt{s} = 13 TeV";
  lumi_sqrtS = "41.9 fb^{-1} (13 TeV, 2017)";
  const int nr = 16;
  TFile * files[nr] = {};
  
  files[0] = TFile::Open("DF_Skim_NoPupAss/DF_Slim_NoRNN_v2.root"); //DeepFlavour10Xon10X.root DFSkimEpoch30.root
  files[1] = TFile::Open("DF_Skim_NoPupAss/DF_NoAss_TTBarHad_10X_30GeV.root"); //

  files[2] = TFile::Open("DeepFlavour10Xon94XLept.root");
  files[3] = TFile::Open("DF_Skim_NoPupAss/DF_NoAss_TTBarLept_10X_30GeV.root"); 
  
  files[4] = TFile::Open("DeepFlavour10XQCD.root"); // evaluated on 94X 120to170
  files[5] = TFile::Open("DF_Skim_NoPupAss/DF_NoAss_QCD120to170_94X_30GeV.root");
  
  files[6] = TFile::Open("DF_Original_QCD3200toInf_94X_500GeV.root");
  files[7] = TFile::Open("DF_Skim_NoPupAss/DF_NoAss_QCD3200toInf_94X_500GeV.root"); 

  files[8] = TFile::Open("DeepFlavour10XTTbar200GeV.root ");
  files[9] = TFile::Open("DF_Skim_NoPupAss/DF_NoAss_TTBarHad_10X_200GeV.root");
  
  files[10] = TFile::Open("DFOriginal_TTBarCTag_30pt.root");
  files[11] = TFile::Open("DF_Skim_NoPupAss/DF_NoAss_TTBarHad_CTag_30GeV.root");
  
  files[12] = TFile::Open("DFOriginal_TTBarUDSTag_30pt.root");
  files[13] = TFile::Open("DF_Skim_NoPupAss/DF_NoAss_TTBarHad_UDSTag_30GeV.root");

  files[14] = TFile::Open("DF_Skim_NoPupAss/DFFull_comparewithpup_ROC.root");
  files[15] = TFile::Open("DF_Skim_NoPupAss/DFPrunedNoPuppiROC.root");

  
  
  TGraph * graphlvsb[nr] = {};
  TGraph * graphcvsb[nr] = {};
  auto mg1  = new TMultiGraph();
  auto mg2  = new TMultiGraph();
  for(int z = 0; z < nr; z++){
    graphlvsb[z] = (TGraph*)files[z]->Get("roccurve_0");
    graphcvsb[z] = (TGraph*)files[z]->Get("roccurve_1");
    if(z%2 == 0){
      graphcvsb[z]->SetLineColor(kRed);
      graphlvsb[z]->SetLineColor(kRed);
    }
    else{
      graphcvsb[z]->SetLineColor(kBlue);
      graphlvsb[z]->SetLineColor(kBlue);
    }
    graphcvsb[z]->SetLineStyle(7);
    graphlvsb[z]->SetLineWidth(2); 
    graphcvsb[z]->SetLineWidth(2);
  }

  TCanvas *c1 = new TCanvas("c1", "ROCS",50,50,1200,900);
  c1->SetGrid();
  graphlvsb[0]->Draw("CA");
  graphcvsb[0]->Draw("same");
  graphlvsb[0]->SetTitle(""); 
  graphlvsb[0]->SetTitle("DeepFlavour Skim: evaluated on 10X TTBar Hadronic");
  graphlvsb[0]->GetXaxis()->SetTitle("b jet efficiency");
  graphlvsb[0]->GetYaxis()->SetTitle("misid. probability");
  graphlvsb[1]->Draw("same");
  graphcvsb[1]->Draw("same");
  graphlvsb[0]->GetXaxis()->SetRangeUser(0.0,1.0);
  graphlvsb[0]->GetYaxis()->SetRangeUser(0.00055,1);
  c1->SetLogy();
  TT_LABEL(0.14,0.772);
  PT_LABEL_30(0.14,0.722);

  auto legend1 = new TLegend(0.1419,0.5384,0.4044,0.6877);
  legend1->AddEntry(graphlvsb[0],"DeepFlavour","l");
  legend1->AddEntry(graphlvsb[1],"DeepFlavour Skim","l");
  legend1->Draw();  

  auto legend3 = new TLegend(0.539232,0.243398,0.80217,0.392652);
  legend3->AddEntry(graphlvsb[0],"DeepFlavour","l");
  legend3->AddEntry(graphlvsb[1],"DeepFlavour Skim","l");

  
  auto legend2 = new TLegend(0.68,0.145,0.88,0.24225);
  legend2->AddEntry(graphlvsb[0],"udsg","l");
  legend2->AddEntry(graphcvsb[0],"c","l");
  legend2->Draw();   

  
  TCanvas *c2 = new TCanvas("c2", "ROCS",50,50,1200,900);
  c2->SetGrid();
  graphcvsb[2]->Draw(); 
  graphlvsb[2]->Draw("same");
  graphlvsb[2]->GetXaxis()->SetRangeUser(0.0,1.0);
  graphlvsb[2]->GetYaxis()->SetRangeUser(0.00055,1);

  graphcvsb[2]->GetXaxis()->SetTitle("b-jet efficiency");
  graphcvsb[2]->GetYaxis()->SetTitle("mistag rate");  
  graphcvsb[2]->SetTitle("DeepFlavour Skim: evaluated on 94X TTBar leptonic");
  graphcvsb[3]->Draw("same"); 
  graphlvsb[3]->Draw("same");
  c2->SetLogy();
  
  TT_LABEL(0.14,0.772);
  PT_LABEL_30(0.14,0.722);
  legend1->Draw(); 
  legend2->Draw();

  TCanvas *c3 = new TCanvas("c4", "ROCS",50,50,1200,900);
  c3->SetGrid();
  graphlvsb[4]->Draw();
  graphlvsb[4]->GetXaxis()->SetTitle("b jet efficiency");
  graphlvsb[4]->GetYaxis()->SetTitle("misid. probability"); 
  graphlvsb[4]->GetXaxis()->SetRangeUser(0.0,1.0);
  graphlvsb[4]->GetYaxis()->SetRangeUser(0.00055,1);

  graphlvsb[4]->SetTitle("Comparison on 94X QCD 120 to 170 GeV");
  graphcvsb[4]->Draw("same"); 
  graphlvsb[5]->Draw("same");
  graphcvsb[5]->Draw("same");
  c3->SetLogy();

  legend1->Draw(); 
  legend2->Draw();
   
  TCanvas *c5 = new TCanvas("c5", "ROCS",50,50,1200,900);
  c5->SetGrid();
  graphlvsb[6]->Draw();
  graphlvsb[6]->GetXaxis()->SetRangeUser(0.0,1.0);
  graphlvsb[6]->GetYaxis()->SetRangeUser(0.00055,1);
  graphlvsb[6]->GetXaxis()->SetTitle("b jet efficiency");
  graphlvsb[6]->GetYaxis()->SetTitle("misid. probability"); 
  graphlvsb[6]->SetTitle("Comparison on 94X QCD pt > 500GeV");
  graphcvsb[6]->Draw("same"); 
  graphlvsb[7]->Draw("same");
  graphcvsb[7]->Draw("same"); 
  c5->SetLogy();
  legend1->Draw(); 
  legend2->Draw();
  
  TCanvas *c6 = new TCanvas("c6", "ROCS",50,50,1200,900);
  c6->SetGrid();
  graphlvsb[8]->Draw();
  graphlvsb[8]->GetXaxis()->SetRangeUser(0.0,1.0);
  graphlvsb[8]->GetYaxis()->SetRangeUser(0.00055,1);
  graphlvsb[8]->GetXaxis()->SetTitle("b jet efficiency");
  graphlvsb[8]->GetYaxis()->SetTitle("misid. probability"); 
  graphlvsb[8]->SetTitle("TTbar 10X pt > 200 GeV");
  graphcvsb[8]->Draw("same"); 
  graphlvsb[9]->Draw("same");
  graphcvsb[9]->Draw("same");
  c6->SetLogy();
  TT_LABEL(0.14,0.772);
  PT_LABEL_200(0.14,0.722);
  legend1->Draw();   
  legend2->Draw();

  TCanvas *c7 = new TCanvas("c7", "ROCS",50,50,1200,900);
  c7->SetGrid();
  graphlvsb[10]->Draw();
  graphlvsb[10]->GetXaxis()->SetRangeUser(0.0,1.0);
  graphlvsb[10]->GetYaxis()->SetRangeUser(0.00055,1);
  graphlvsb[10]->GetXaxis()->SetTitle("c-jet efficiency");
  graphlvsb[10]->GetYaxis()->SetTitle("misid. probability"); 
  graphlvsb[10]->SetTitle("C-Tag 10X TTBar Had pt>30GeV");
  graphcvsb[10]->Draw("same"); 
  graphlvsb[11]->Draw("same");
  graphcvsb[11]->Draw("same");
  c7->SetLogy();
  TT_LABEL(0.14,0.772);
  PT_LABEL_30(0.14,0.722);
  legend3->Draw();   

  TCanvas *c8 = new TCanvas("c8", "ROCS",50,50,1200,900);
  c8->SetGrid();
  graphlvsb[12]->Draw();
  graphlvsb[12]->GetXaxis()->SetRangeUser(0.0,1.0);
  graphlvsb[12]->GetYaxis()->SetRangeUser(0.00055,1);
  graphlvsb[12]->GetXaxis()->SetTitle("uds-jet efficiency");
  graphlvsb[12]->GetYaxis()->SetTitle("misid. probability"); 
  graphlvsb[12]->SetTitle("UDSG-Tag 10X TTBar Had pt>30GeV");
  graphcvsb[12]->Draw("same"); 
  graphlvsb[13]->Draw("same");
  graphcvsb[13]->Draw("same");
  c8->SetLogy();
  TT_LABEL(0.14,0.772);
  PT_LABEL_30(0.14,0.722);
  legend3->Draw();   

  TCanvas *c9 = new TCanvas("c9", "ROCS",50,50,1200,900);
  c9->SetGrid();
  graphcvsb[14]->Draw();
  graphcvsb[14]->GetXaxis()->SetRangeUser(0.0,1.0);
  graphcvsb[14]->GetYaxis()->SetRangeUser(0.00055,1);
  graphcvsb[14]->GetXaxis()->SetTitle("b-jet efficiency");
  graphcvsb[14]->GetYaxis()->SetTitle("misid. probability"); 
  graphcvsb[14]->SetTitle("CMSSW implementation 10X Comparison");
  graphlvsb[14]->Draw("same"); 
  graphlvsb[15]->Draw("same");
  graphcvsb[15]->Draw("same");
  c9->SetLogy();
  legend3->Draw();   

  
}


  


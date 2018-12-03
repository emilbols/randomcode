#include <TMultiGraph.h>

void script(){
  const char *dirname="/home/emil/NNStudies/fractionofdata/multirocs/ReadDir";
  const char *ext=".root";
  const char *lead="ROC";

  TFile *filearray[10] = {};
  TSystemDirectory dir(dirname, dirname);
  TList *files = dir.GetListOfFiles();
  TString strings[10] = {}; 
  int c = 0;
  if (files) {
    TSystemFile *file;
    TString fname;
    TString intermediate;
    TIter next(files);
    while ((file=(TSystemFile*)next())) {
      fname = file->GetName();
      if (!file->IsDirectory() && fname.EndsWith(ext)) {
	cout << fname.Data() << endl;
	filearray[c] = TFile::Open(fname);
	intermediate = fname.Remove(TString::kLeading,*lead);
	strings[c] = intermediate.Remove(TString::kTrailing, *ext);
	c++;
      }
    }
  }
  TGraph * graphlvsb[10] = {};
  TGraph * graphcvsb[10] = {};
  for(int z = 0; z < 10; z++){
    graphlvsb[z] = (TGraph*)filearray[z]->Get("roccurve_0");
    graphcvsb[z] = (TGraph*)filearray[z]->Get("roccurve_1");
  }
  auto mg1  = new TMultiGraph();
  auto mg2  = new TMultiGraph();
  for(int z = 0; z < 10; z++){
    graphlvsb[z]->SetTitle((strings[z]+" l vs b"));
    graphlvsb[z]->SetLineColor(kRed+z);
    graphcvsb[z]->SetTitle((strings[z]+" c vs b"));
    graphcvsb[z]->SetLineColor(kBlue+z);
    mg1->Add(graphlvsb[z]);
    mg2->Add(graphcvsb[z]);
  }
  //TFile *hfile13 = TFile::Open("../orgROC.root");  
  //TGraph * blDeepCSV = (TGraph*)hfile13->Get("roccurve_0");
  //TGraph * cbDeepCSV = (TGraph*)hfile13->Get("roccurve_1");
  
  double mean1[100] = {};
  double stdsum1[100] = {};
  double std1[100] = {};
  double std12[100] = {};
  double mean2[100] = {};
  double stdsum2[100] = {};
  double std2[100] = {};
  double std22[100] = {};
  double x[100] = {};
  for(int n = 0; n < 100; n++){
    x[n] = n/99.0;
  }
  double size = 10.0;
  TList* grlist1;
  grlist1 = mg1->GetListOfGraphs();
  TIter next(grlist1);
  TObject *obj1;
  TGraph *gr1;
  int l = 0;
  while ((obj1 = next())) {
    gr1=(TGraph*)obj1;
    for(int n = 0; n < 100; n++){
      double z = n/99.0;
      mean1[n] = mean1[n] + gr1->Eval(z)/(size);
    }
  }
  cout << mean1[53] << endl;
  cout << l << endl;
  TList* grlist2;
  grlist2 = mg2->GetListOfGraphs();
  TIter next1(grlist2);
  TObject *obj2;
  TGraph *gr2;
  while ((obj2 = next1())) {
    gr2=(TGraph*)obj2;
    for(int n = 0; n < 100; n++){
      double z = n/99.0;
      mean2[n] = mean2[n] + gr2->Eval(z)/(size);
    }
  }
  TIter next2(grlist2);
  TObject *obj3;
  TGraph *gr3;
  while ((obj3 = next2())) {
    gr3=(TGraph*)obj3;
    for(int n = 0; n < 100; n++){
      double z = n/99.0;
      stdsum2[n] = stdsum2[n] + (gr3->Eval(z)-mean2[n] )*(gr3->Eval(z)-mean2[n] )/(size);
    }
  }
  for(int n = 0; n < 100; n++){
    std2[n] = sqrt(stdsum2[n]);
    std22[n] = std2[n]*2.0;
  }

  TIter next3(grlist1);
  TObject *obj4;
  TGraph *gr4;
  while ((obj4 = next3())) {
    gr4=(TGraph*)obj4;
    for(int n = 0; n < 100; n++){
      double z = n/99.0;
      stdsum1[n] = stdsum1[n] + (gr4->Eval(z)-mean1[n] )*(gr4->Eval(z)-mean1[n] )/(size);
    }
  }
  for(int n = 0; n < 100; n++){
    std1[n] = sqrt(stdsum1[n]);
    std12[n] = std1[n]*2.0;
  }
    
 TCanvas *c1 = new TCanvas("c1", "ROCS",50,50,1500,800);
  c1->SetGrid();
  double zero[100] = {};
  TGraphErrors* ge = new TGraphErrors(100, x, mean1, zero, std1);
  ge->SetTitle("DeepCSV Sensitivity to Initialization of Weights");
  ge->SetFillColor(4);
  ge->SetFillStyle(1001);
  //ge->Draw("a C 3");
  ge->GetXaxis()->SetRangeUser(0,1);
  ge->GetYaxis()->SetRangeUser(0.0005,1);
  TGraphErrors* ge1 = new TGraphErrors(100, x, mean1, zero, std12);
  ge1->SetTitle("Roc Curve Error band");
  ge1->SetFillColor(4);
  ge1->SetFillStyle(3001);
  //ge1->Draw("C 3 same");

  TGraphErrors* ge2 = new TGraphErrors(100, x, mean2, zero, std2);
  ge2->SetFillColor(2);
  ge2->SetFillStyle(1001);
  //ge2->Draw("3 C same");
  mg1->Draw("aC");
  mg2->Draw("C");
  c1->SetLogy();
  c1->BuildLegend();
  c1->Update();
  TGraphErrors* ge3 = new TGraphErrors(100, x, mean2, zero, std22);
  ge3->SetTitle("");
  ge3->SetFillColorAlpha(kRed,0.0);
  ge3->SetFillStyle(3001);
  // ge3->Draw("C 3 same");
  /*
  blDeepCSV->Draw("same");
  blDeepCSV->SetLineColor(kBlack);
  cbDeepCSV->Draw("same");
  cbDeepCSV->SetLineColor(kBlack);
  */
  /*
  auto legend = new TLegend(0.28,0.65,0.48,0.8);
  legend->AddEntry(ge,"udsg vs b 1#sigma","f");
  legend->AddEntry(ge1,"udsg vs b 2#sigma","f");
  legend->AddEntry(ge2,"c vs b 1#sigma","f");
  legend->AddEntry(ge3,"c vs b 2#sigma","f");

  legend->Draw();
  */
}

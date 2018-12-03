#include <TMultiGraph.h>

void script(){
  const char *dirname="/home/emil/NNStudies/ROCS/multiROC/ReadDir";
  const char *ext=".root";
  TFile *filearray[12] = {};
  TSystemDirectory dir(dirname, dirname);
  TList *files = dir.GetListOfFiles();
  int c = 0;
  if (files) {
    TSystemFile *file;
    TString fname;
    TIter next(files);
    while ((file=(TSystemFile*)next())) {
      fname = file->GetName();
      if (!file->IsDirectory() && fname.EndsWith(ext)) {
	cout << fname.Data() << endl;
	filearray[c] = TFile::Open(fname);
	c++;
      }
    }
  }
  TGraph * graphlvsb[12] = {};
  for(int z = 0; z < 12; z++){
    graphlvsb[z] = (TGraph*)filearray[z]->Get("roccurve_0");
  }
  auto mg1  = new TMultiGraph();
  auto mg2  = new TMultiGraph();
  for(int z = 0; z < 12; z++){
    mg1->Add(graphlvsb[z]);
  }
  
  double mean1[200] = {};
  double stdsum1[200] = {};
  double std1[200] = {};
  double std12[200] = {};
  double mean2[200] = {};
  double stdsum2[200] = {};
  double std2[200] = {};
  double std22[200] = {};
  double x[200] = {};
  for(int n = 0; n < 200; n++){
    x[n] = n/199.0;
  }
  double size = 12.0;
  TList* grlist1;
  grlist1 = mg1->GetListOfGraphs();
  TIter next(grlist1);
  TObject *obj1;
  TGraph *gr1;
  int l = 0;
  while ((obj1 = next())) {
    gr1=(TGraph*)obj1;
    for(int n = 0; n < 200; n++){
      double z = n/199.0;
      mean1[n] = mean1[n] + gr1->Eval(z)/(size);
    }
  }

  TIter next3(grlist1);
  TObject *obj4;
  TGraph *gr4;
  while ((obj4 = next3())) {
    gr4=(TGraph*)obj4;
    for(int n = 0; n < 200; n++){
      double z = n/199.0;
      stdsum1[n] = stdsum1[n] + (gr4->Eval(z)-mean1[n] )*(gr4->Eval(z)-mean1[n] )/(size);
    }
  }
  for(int n = 0; n < 200; n++){
    std1[n] = sqrt(stdsum1[n]);
    std12[n] = std1[n]*2.0;
  }
  
  TCanvas *c1 = new TCanvas("c1", "ROCS",50,50,1500,800);
  c1->SetGrid();
  double zero[200] = {};
  TGraphErrors* ge = new TGraphErrors(200, x, mean1, zero, std1);
  ge->SetTitle("DeepCSV Sensitivity to Initialization of Weights");
  ge->SetFillColor(4);
  ge->SetFillStyle(1001);
  ge->Draw("a 3");
  ge->GetXaxis()->SetRangeUser(0,1);
  ge->GetXaxis()->SetTitle("b-jet efficiency");
  ge->GetYaxis()->SetTitle("misid. probability");
  ge->GetYaxis()->SetRangeUser(0.0005,1);
  TGraphErrors* ge1 = new TGraphErrors(200, x, mean1, zero, std12);
 // ge1->SetTitle("DeepCSV spread due to initialization");
  ge1->SetFillColor(4);
  ge1->SetFillStyle(3001);
  //  ge1->Draw("C 3 same");

  /*
  blDeepCSV->Draw("same");
  blDeepCSV->SetLineColor(kBlack);
  cbDeepCSV->Draw("same");
  cbDeepCSV->SetLineColor(kBlack);
  */
  auto legend = new TLegend(0.28,0.65,0.48,0.8);
  legend->AddEntry(ge,"1#sigma","f");
  legend->AddEntry(ge1,"2#sigma","f");

  legend->Draw();

  
  
}

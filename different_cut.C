#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

//using namespace std;

#include "TCanvas.h"
#include "TFile.h"
#include "TNtuple.h"
#include "TProfile.h"
#include "TBenchmark.h"
#include "TStyle.h"
#include "TPaveText.h"
#include "TFrame.h"
#include "TF1.h"
#include "TROOT.h"
#include "TSystem.h"
#include "TInterpreter.h"
#include "TStyle.h"
#include "TH1.h"
#include "TH2.h"
#include "TMath.h"
#include "TTree.h"
#include "TH1F.h"


using namespace std;
vector <int> gEStart;
vector <int> gEEnd;
vector <int> gEType;

int ReadBadEventId(int run)
{
  ifstream INPUT_filea;
  INPUT_filea.open(Form("/w/hallb-scifs1a/primex/liye/compton_work/ana_data/flux/flux_%06d.dat",run));
  if( !INPUT_filea)cout<<"ERROR!!!! CAN'T OPEN input file for run "<<run<<endl;

  char strline[2561];
  int n=0, runnumber,start,end,e3,type;

  while(!INPUT_filea.eof())
    {
      INPUT_filea>>runnumber>>start>>end>>e3>>type;
      INPUT_filea.getline(strline,2560);
      gEStart.push_back(start);
      gEEnd.push_back(end);
      gEType.push_back(type);
      if ( type <1 || type >2 )
	{ 
	  cout<<setw(12)<<start<<" "<<setw(12)<<end<<" "<<setw(6)<<type<<endl;
	}
      else
	n++;
  }
  return n;

}


bool IsGoodEvent(int eventid)
{
  vector<int>::iterator it;
  int size = (int)gEType.size();
  int i=0;
  for (i=0; i<size; i++)
    {
      if (eventid >= gEStart[i] && eventid <= gEEnd[i]) break;
    }
  if(gEType[i]!=1 && gEType[i]!=2)  
    {
      //cout<<"event "<<eventid<<" is a bad event\n";
      return false;
    }
  else return true;
}

//usage: exe <run#>
int main(int argc, char** argv)
{
  int run = atoi(argv[1]);
  TFile *f1 = new TFile(Form("li_prim_ana%d.root",run),"r");
  /*
  //just in case this script is executed multiple times
  delete gROOT->GetListOfFiles()->FindObject("prim_ana65078.root");
  delete gROOT->GetListOfFiles()->FindObject("prim_ana65078.root");
  delete gROOT->GetListOfCanvases()->FindObject("c1");

  gBenchmark->Start("compton_liye_1");
  */
  //
  // Connect ROOT histogram/ntuple demonstration file
  // generated by example $ROOTSYS/tutorials/hsimple.C.
  // TString dir = gSystem->UnixPathName(__FILE__);
  // dir.ReplaceAll("ntuple1.C","../hsimple.C");
  // dir.ReplaceAll("/./","/");
  // if (gBenchmark->GetBench("hsimple") < 0) gInterpreter->LoadMacro(dir.Data());
  // TFile *f1 = (TFile*)gROOT->ProcessLineFast("hsimple(1)");
  // if (!f1) return 0;
  



  int eventid;

  int  Eid;
  int  Tid;      // Tcounter channel ID
  float Tdiff;   //time difference between Hycal and Tcounter 
  float Eg;      // incoming photon energy
  float e1;      // cluster 1 energy
  float x1;      // cluster 1 x position
  float y1;      // cluster 1 y position
  float e0;     
  float e2;      // cluster 2 energy
  float x2;      // cluster 2 x position
  float y2;      // cluster 2 y position

  /*
  float  id1, id2, type1, type2;
  float invm[kMax], angle[kMax];
  */
  float PI=3.1415927;	
  int goodnumber=ReadBadEventId(run);
  if(goodnumber<1) return -1;

  //	TFile *f1 = new TFile("prim_ana65080.root");
  //	if (!f1) cout << "Error!! can not open file" << endl;



  //  TFile *f1 = new TFile("prim_ana65079.root","r");
  //TFile *f1 = new TFile("li_prim_ana65078.root","r");
 
  TTree *event = (TTree*)f1->Get("event");

  //TDirectory *dd = (TDirectory*)f1->Get("tagger");
  // TNtuple *event = (TNtuple*) dd->Get("cmpt_ntuple");

  //event->SetBranchAddress("run", &run);
  event->SetBranchAddress("eventid", &eventid);
  event->SetBranchAddress("Tdiff", &Tdiff);
  event->SetBranchAddress("Tid", &Tid);
  event->SetBranchAddress("Eid", &Eid);
  event->SetBranchAddress("Eg",&Eg);
  //event->SetBranchAddress("id1",&id1);
  //event->SetBranchAddress("id2",&id2);
  //  event->SetBranchAddress("type1",type1);
  //  event->SetBranchAddress("type2",type2);
  event->SetBranchAddress("x1",&x1);
  event->SetBranchAddress("y1",&y1);
  event->SetBranchAddress("x2",&x2);
  event->SetBranchAddress("y2",&y2);
  event->SetBranchAddress("e1",&e1);
  event->SetBranchAddress("e2",&e2);
  event->SetBranchAddress("e0",&e0);

  TH1F *h_evn = new TH1F("h_evn","eventid",100000,0,31000000);
  TH1F *h_E = new TH1F("h_E","E0 = eg - e1 -e2",1000,-2,2);
  TH1F *h_tdiff = new TH1F("tdiff","Tdiff",300,-10,10);  
  TH1F *h_x = new TH1F("h_x","X position",60,-30,30);
  TH1F *h_sep = new TH1F("h_sep","Cluster Separation",500,0,50);
  TH1F *h_angle = new TH1F("h_angle","Azimuthal Angle Difference",500,120,240);


  TH1F *h_z0 = new TH1F("h_z0","Z position",600,-30,1200);
  TH1F *h_z1 = new TH1F("h_z1","Z position",600,-30,1200);
  TH1F *h_z2 = new TH1F("h_z2","Z position",600,-30,1200);
  TH1F *h_z3 = new TH1F("h_z3","Z position",600,-30,1200);

	
  TH2F *h_x_y_1 = new TH2F("h_x_y_1"," XY position for cluster1", 200,-20,20,500,-20,20);
  TH2F *h_x_y_2 = new TH2F("h_x_y_2"," XY position for cluster2", 200,-20,20,500,-20,20);
  TH2F *h_sep_2d = new TH2F("h_sep_2d"," Cluster Separation", 200,-40,40,200,-40,40);
  TH1F *h_cosphi = new TH1F("h_cosphi","cosphi",600,0,4);



//THStack *helass = new THStack("helass","");
  TH1F *helas0 = new TH1F("helas0","Elasticity:  E_{0} - (E_{1} + E_{2})",300,-1.5,1.5);
  TH1F *helas1 = new TH1F("helas1","Elasticity:  E_{0} - (E_{1} + E_{2})",300,-1.5,1.5);
  TH1F *helas2 = new TH1F("helas2","Elasticity:  E_{0} - (E_{1} + E_{2})",300,-1.5,1.5);
  TH1F *helas3 = new TH1F("helas3","Elasticity:  E_{0} - (E_{1} + E_{2})",300,-1.5,1.5);

/*
  TH1F *helas4 = new TH1F("helas4","Elasticity:  E_{0} - (E_{1} + E_{2})",300,-0.5,1.5);
  helass->Add(helas4);
  TH1F *helas5 = new TH1F("helas5","Elasticity:  E_{0} - (E_{1} + E_{2})",300,-0.5,1.5);
  helass->Add(helas5);
  TH1F *helas6 = new TH1F("helas6","Elasticity:  E_{0} - (E_{1} + E_{2})",300,-0.5,1.5);
  helass->Add(helas6);
  TH1F *helas7 = new TH1F("helas7","Elasticity:  E_{0} - (E_{1} + E_{2})",300,-0.5,1.5);

  helass->Add(helas7);

*/



  int nevents = event->GetEntries();
  //      nevents = 30;
  cout<<"number of events: "<<nevents<<endl;
  for(int i=1;i<=nevents;i++){
    // if(i%100000==0)cout<<i<<endl;
    //Progress bar
    Double_t  entries=nevents;
    Double_t ratio = i/(Double_t)entries;
    cout<<setw(8)<<(int)(ratio*100)<<"%\r"<<flush;
    event->GetEntry(i);
        
      

    // ========  cut ==================
    if(!IsGoodEvent(eventid)) continue;
     

    float angle_diff=0,  angle1_a=0 , angle2_a=0, sep=0, sep_x=0, sep_y=0 ;
	
    float r1=0,r2=0;
	
    //float e0 =0;
	
    double z;
    double a = 1.0 - (0.5109989e-3*Eg)/e1/e2;
    double b = (x1*x1*x2*x2 + x1*x1*y2*y2 + y1*y1*x2*x2 + y1*y1*y2*y2);
    double c = (x1*x1 + y1*y1 + x2*x2 + y2*y2);
    double d = (x1*x1*x2*x2 + y1*y1*y2*y2 + 2*x1*x2*y1*y2);
    double e = x1*x2 + y1*y2;
    double A = a*a - 1;
    double B = a*a*c - 2*e;
    double C = a*a*b - d;
    double t = (- B - sqrt(B*B - 4*A*C))/2./A;
    if (t >= 0) {
      z = sqrt(t);
    } else {
      z = -100.;}

    if ( x1 >0 ) {  angle1_a = atan(y1/x1)*180.0/PI;  }
    if ( x1 <0 ) {  angle1_a = atan(y1/x1)*180.0/PI + 180.0 ; }
    if ( x2 >0 ) {  angle2_a = atan(y2/x2)*180.0/PI; } 
    if ( x2 <0 ) {  angle2_a = atan(y2/x2)*180.0/PI + 180.0 ; }

    float angle_diff0 = angle1_a - angle2_a;
    if ( angle_diff0 > 0 ) { angle_diff = angle_diff0;}
    if ( angle_diff0 <= 0 ) { angle_diff = -angle_diff0;} 


    sep_x = x1-x2 ;
    sep_y = y1-y2 ;
    sep = sqrt(sep_x*sep_x + sep_y*sep_y);




    //	 float angle1 = stan(sqrt(x1*x1+y1*y1)/702.0)*180.0/PI;    //in deg 
    //	 float angle2 = atan(sqrt(x2*x2+y2*y2)/702.0)*180.0/PI;    
	

    if (abs(x1)< 4.154 && abs(y1)< 4.154) continue;
    if (abs(x1)> 32.2 && abs(y1)>32.2) continue;
    if (abs(x2)< 4.154 && abs(y2)< 4.154) continue;	
    if (abs(x2)> 32.2 && abs(y2)> 32.2) continue;

    h_x_y_1->Fill(x1,y1);
    h_x_y_2->Fill(x2,y2);		

    if (e1 < 0.5 || e2 <0.5 ) continue;
    if (e1+e2 <=2.5 ) continue;

    if (Tdiff < -6.0 || Tdiff > 4.0) continue;
    if (angle_diff < 140.0 || angle_diff > 220.0 ) continue;  
        
    //  if (sep < 16.0 ) continue;
    if (e0 > 1.0 || e0 < -1.0 ) continue;


    helas0->Fill(e0);
	
    h_tdiff->Fill(Tdiff);
    h_angle->Fill(angle_diff);   
    h_sep->Fill(sep);
    h_sep_2d->Fill(sep_x,sep_y);
    h_z0->Fill(z);
    h_evn->Fill(eventid);

    if ( sep > 16.0 ) {helas1->Fill(e0); h_z1->Fill(z);}
    if ( sep > 17.0 ) {helas2->Fill(e0); h_z2->Fill(z);}
    if ( sep > 18.0 ) {helas3->Fill(e0); h_z3->Fill(z);}
    // cout<<event->GetEntries()<<endl;

    //return 0;
  

  }

  //  TFile *f = new TFile(Form("/w/hallb-scifs1a/primex/liye/222/result_%d.root",run),"RECREATE");
 
 TFile *f = new TFile(Form("/w/hallb-scifs1a/primex/liye/222/result02.root",run),"RECREATE");
 

  h_z0->Write();
  h_z1->Write();
  h_z2->Write();
  h_z3->Write();


  h_x_y_1->Write();
  h_x_y_2->Write();
  // h_E->Write();
  h_tdiff->Write();
  h_angle->Write();
  h_sep_2d->Write();
  h_sep->Write();
  h_evn->Write();
  
 

  
  helas3->SetTitleSize(0.035,"X");
  helas3->GetXaxis()->SetTitle("Elasticity: E_{0} - (E_{1} + E_{2}) (GeV)");
 // helass->Draw("nostack");
  helas0->Write();
  helas1->Write();
  helas2->Write();
  helas3->Write();

/*
  latex.DrawLatex(0.465,0.035,"Elasticity: E_{0} - (E_{1} + E_{2})  (GeV)");
        cout << "\n===>>> IN TIME: " << intime << "\n" << endl;
  TLegend *legend;
  if (intime) legend = new TLegend(0.650,0.650,0.920,0.915);
  if (!intime) legend = new TLegend(0.110,0.650,0.390,0.915);
  legend->SetTextFont(52);
  legend->AddEntry(helas0,"All Events","f");
  legend->AddEntry(helas1,"Coincidence","f");
  legend->AddEntry(helas2,"+ Coplanarity","f");
  legend->AddEntry(helas3,"+ Fiducial","f");
  legend->AddEntry(helas4,"+ R minimum","f");
  //~ legend->AddEntry(helas5,"+ no Pair Bgrd","f");
  //  legend->AddEntry(helas6,"+ z Target","f");
  //    legend->AddEntry(helas7,"+ Energy Diff.","f");
  //      legend->Draw();
*/



  /*
  TCanvas *c1 = new TCanvas("c1","XY position",800,800);
  gStyle->SetPalette(0,0);
  c1->cd();
  //	h_E->GetXaxis()->SetTitle("eg-(e1+e2) (GeV)");	
  //	h_E->Draw();
  //	h_tdiff->Draw();
  h_x_y_1->Draw("zcol");
  //	h_angle->GetXaxis()->SetTitle(" Azimuthal Angle difference (deg)");
  //	h_angle->Draw();
  //	h_sep->Draw();	
  //	h_sep_2d->Draw("zcol");
  //	h_z->Draw();

  TCanvas *c2 = new TCanvas("c2","e0 = Eg-e1-e2",800,800);
  c2->cd();
  h_z->Draw(); 
  //c1->SaveAs("/w/hallb-scifs1a/primex/liye/compton_work/plot/z_recon_65078.png");
  */
  return 0;
}

/*
int main()
{
  compton_liye_1();
  return 0;
}


*/












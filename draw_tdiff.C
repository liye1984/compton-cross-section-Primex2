
void draw_tdiff(){

int ne = 1.0 ;	
  Double_t Ecounter[20],Eyield[20],Tyield[20],flux[20],EAcc[20],TAcc[20],,dd[20];
  Double_t Ecross[20],Tcross[20];
  Double_t MCTyield[20],MCEyield[20];
  Double_t Tratio[20],Eratio[20],Teff[20],Eeff[20];
  Double_t yerr1[20],yerr2[20],yerr3[20]; 
  Double_t aa[20],bb[20],Tid[20],run[20];
  Double_t Tid_1[20],Tid_5[20],Tid_9[20],Tid_13[20],Tid_17[20],Tid_64881[20],Tid_64882[20],Tid_64878[20],Tid_65077[20],Tid_65078[20],Tid_65079[20],Tid_65080[20];




 

//===========   tdiff alienment for #65078  ======================//

	Tid_65078[0]= 1.778;	Tid_65078[1]= 1.684;	Tid_65078[2]= 1.69;
	Tid_65078[3]= 1.667;	Tid_65078[4]= 1.642;	Tid_65078[5]= 1.618;
	Tid_65078[6]= 1.533;	Tid_65078[7]= 1.452;	Tid_65078[8]= 1.541;
	Tid_65078[9]= 1.49;	Tid_65078[10]= 1.443;	Tid_65078[11]= 1.541;
	Tid_65078[12]= 1.405;	Tid_65078[13]= 1.309;	Tid_65078[14]= 1.253;
	Tid_65078[15]= 1.018;	Tid_65078[16]= 1.034;	Tid_65078[17]= 0.759;

//===========   tdiff alienment for #64878  ======================//

	Tid_64878[0]= 2.615;	Tid_64878[1]= 2.528;	Tid_64878[2]= 2.515;
	Tid_64878[3]= 2.490;	Tid_64878[4]= 2.557;	Tid_64878[5]= 2.472;
	Tid_64878[6]= 2.444;	Tid_64878[7]= 2.250;	Tid_64878[8]= 2.302;
	Tid_64878[9]= 2.249;	Tid_64878[10]= 2.188;	Tid_64878[11]= 2.278;
	Tid_64878[12]= 2.204;	Tid_64878[13]= 2.019;	Tid_64878[14]= 1.925;
	Tid_64878[15]= 1.634;	Tid_64878[16]= 1.642;	Tid_64878[17]= 1.407;


//===========  different runs tdiffs for Tid =1   ======================//

	Tid_1[0]= 2.626;	Tid_1[1]= 2.616;	Tid_1[2]= 2.615;
	Tid_1[3]= 2.611;	Tid_1[4]= 2.638;	Tid_1[5]= 2.587;
	Tid_1[6]= 2.617;	Tid_1[7]= 2.605;	Tid_1[8]= 2.611;
	Tid_1[9]= 2.598;	Tid_1[10]= 2.625;	Tid_1[11]= 2.668;
	
	
//===========  different runs tdiffs for Tid =5   ======================//

	Tid_5[0]= 2.587;	Tid_5[1]= 2.594;	Tid_5[2]= 2.557;
	Tid_5[3]= 2.573;	Tid_5[4]= 2.581;	Tid_5[5]= 2.566;
	Tid_5[6]= 2.587;	Tid_5[7]= 2.554;	Tid_5[8]= 2.444;
	Tid_5[9]= 2.415;	Tid_5[10]= 2.460;	Tid_5[11]= 2.478;

//===========  different runs tdiffs for Tid =9   ======================//

	Tid_9[0]= 2.316;	Tid_9[1]= 2.294;	Tid_9[2]= 2.302;
	Tid_9[3]= 2.294;	Tid_9[4]= 2.299;	Tid_9[5]= 2.326;
	Tid_9[6]= 2.332;	Tid_9[7]= 2.335;	Tid_9[8]= 2.215;
	Tid_9[9]= 2.197;	Tid_9[10]= 2.182;	Tid_9[11]= 2.220;


//===========  different runs tdiffs for Tid =13   ======================//

	Tid_13[0]= 2.185;	Tid_13[1]= 2.205;	Tid_13[2]= 2.204;
	Tid_13[3]= 2.163;	Tid_13[4]= 2.175;	Tid_13[5]= 2.170;
	Tid_13[6]= 2.180;	Tid_13[7]= 2.171;	Tid_13[8]= 1.985;
	Tid_13[9]= 1.967;	Tid_13[10]= 2.022;	Tid_13[11]= 2.039;
//===========  different runs tdiffs for Tid =17   ======================//

	Tid_17[0]= 1.617;	Tid_17[1]= 1.659;	Tid_17[2]= 1.642;
	Tid_17[3]= 1.628;	Tid_17[4]= 1.639;	Tid_17[5]= 1.635;
	Tid_17[6]= 1.630;	Tid_17[7]= 1.646;	Tid_17[8]= 1.433;
	Tid_17[9]= 1.431;	Tid_17[10]= 1.413;	Tid_17[11]= 1.446;
float s = 175;

	run[0]= 64876;	run[1]= 64877;	run[2]= 64878;
	run[3]= 64879;	run[4]= 64880;	run[5]= 64881;
	run[6]= 64882;	run[7]= 64883;	run[8]= 64886;
	run[9]= 64887;	run[10]= 64888;	run[11]= 64889;



for ( int i=0;i<18;i++){
	
	Tid[i] = i+1;
	EAcc[i] = MCEyield[i]/1000000.0;
	TAcc[i] = MCTyield[i]/1000000.0;
	Ecross[i]= Eyield[i]/ne/flux[i]/EAcc[i];
	Tcross[i]= Tyield[i]/ne/flux[i]/TAcc[i];
	dd[i]= flux[i]/TAcc[i];
	aa[i]= Tyield[i]/Teff[i];
	bb[i]= Eyield[i]/Eeff[i];
	Tratio[i]= 100.0*(Tyield[i]-MCTyield[i])/Tyield[i];
	Eratio[i]= 100.0*(Eyield[i]-MCEyield[i])/Eyield[i];


    }
	
	



   TMultiGraph *mg = new TMultiGraph("mg"," T-counter tdiff alienment #64878 ");
   TGraphErrors *g1 = new TGraphErrors(18,Tid,Tid_64878,0,0);
   TGraphErrors *g2 = new TGraphErrors(12,run,Tid_5,0,0);	
   TGraphErrors *g3 = new TGraphErrors(12,run,Tid_9,0,0);
   TGraphErrors *g4 = new TGraphErrors(12,run,Tid_13,0,0);
   TGraphErrors *g5 = new TGraphErrors(12,run,Tid_17,0,0);





  TCanvas *c11 = new TCanvas("c11","counts vs T",600,600);
  
 
//  g1->Draw("A*");
g1->SetName("g1");
g1->SetTitle("");  
g1->SetMarkerStyle(21);
g1->SetMarkerColor(2);
g1->SetMarkerSize(1.0);
g1->SetDrawOption("AP");
g1->SetLineColor(2);
g1->SetLineWidth(0.5);
g1->SetFillStyle(0);


g2->SetName("g2");
g2->SetTitle("");
g2->SetMarkerStyle(21); 
g2->SetMarkerSize(1.0);
g2->SetMarkerColor(3);
g2->SetDrawOption("AP");
g2->SetLineColor(3);
g2->SetLineWidth(0.5);
g2->SetFillStyle(0);

g3->SetName("g3");
g3->SetMarkerStyle(21);
g3->SetMarkerColor(4);
g3->SetMarkerSize(1.0);
g3->SetDrawOption("AP");
g3->SetLineColor(4);
g3->SetLineWidth(0.5);
g3->SetFillStyle(0);

g4->SetName("g4");
g4->SetMarkerStyle(21);
g4->SetMarkerColor(5);
g4->SetMarkerSize(1.0);
g4->SetDrawOption("AP");
g4->SetLineColor(5);
g4->SetLineWidth(0.5);
g4->SetFillStyle(0);

g5->SetName("g5");
g5->SetMarkerStyle(21);
g5->SetMarkerColor(6);
g5->SetMarkerSize(1.0);
g5->SetDrawOption("AP");
g5->SetLineColor(6);
g5->SetLineWidth(0.5);
g5->SetFillStyle(0);

mg->Add(g1);
//mg->Add(g2);
//mg->Add(g3);
//mg->Add(g4);
//mg->Add(g5);



mg->Draw("ALP");
mg->GetXaxis()->SetTitle(" Tid # ");
mg->GetYaxis()->SetTitle(" alienment (ns) ");
gPad->Modified();


//mg->GetYaxis()->SetLimits(0,1);


TLegend *leg;
  

leg = new TLegend(0.1,0.7,0.48,0.9);
leg->AddEntry("g1","Tid = 1 ");
leg->AddEntry("g2","Tid = 5 ");
leg->AddEntry("g3","Tid = 9 ");
leg->AddEntry("g4","Tid = 13 ");
leg->AddEntry("g5","Tid = 17 ");


//leg->Draw();






  //g1->GetXaxis()->SetRange(0,1400);
/*
  g1->Fit("fitf","","",0,0);
  Double_t parameter[2];

  fitf->GetParameters(parameter);
  cout<<"y[500]="<<parameter[0] + parameter[1] * 500<<endl;

*/



 }







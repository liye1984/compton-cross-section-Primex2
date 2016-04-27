
void draw_cross(){

int ne = 1.0 ;	
  Double_t Ecounter[20],Eyield[20],Tyield[20],flux[20],EAcc[20],TAcc[20],,dd[20];
  Double_t Ecross[20],Tcross[20];
  Double_t MCTyield[20],MCEyield[20];
  Double_t Tratio[20],Eratio[20],Teff[20],Eeff[20];
  Double_t yerr1[20],yerr2[20],yerr3[20]; 
  Double_t aa[20],bb[20],Tid[20];
  Double_t Energy[18];
  Double_t Tid_64876[20],Tid_64877[20],Tid_64878[20],Tid_64879[20],Tid_64880[20],Tid_64881[20],Tid_64882[20],Tid_64883[20],Tid_65077[20],Tid_65078[20],Tid_65079[20],Tid_65080[20];




 // static Int_t n=3;
/*
  Double_t fit(Double_t *x,Double_t *par){
    return par[0]+par[1]*x[0];
  }

  TF1 *fitf = new TF1("fitf",fit,-10,25,2);
*/
 

//===========  E-counter energy ======================//
  
 	Energy[0]= 5.281;	Energy[1]= 5.241;	Energy[2]= 5.195;
	Energy[3]= 5.145;	Energy[4]= 5.093;	Energy[5]= 5.041;
	Energy[6]= 4.988;	Energy[7]= 4.937;	Energy[8]= 4.883;
	Energy[9]= 4.827;	Energy[10]= 4.774;	Energy[11]= 4.727;
	Energy[12]= 4.663;	Energy[13]= 4.609;	Energy[14]= 4.554;
	Energy[15]= 4.503;	Energy[16]= 4.447;	Energy[17]= 4.400;

//===========  flux for data #65078  ======================//

flux[0]  =  0.09635431 ;flux[1]  =  0.11835440 ;flux[2]  =  0.14258032 ;
flux[3]  =  0.09068396 ;flux[4]  =  0.10953348 ;flux[5]  =  0.11160288 ;
flux[6]  =  0.10954737 ;flux[7]  =  0.10446773 ;flux[8]  =  0.11691161 ;
flux[9]  =  0.10968841 ;flux[10] =  0.13868611 ;flux[11] =  0.08827386 ;
flux[12] =  0.08825523 ;flux[13] =  0.12572067 ;flux[14] =  0.09069942 ;
flux[15] =  0.08882608 ;flux[16] =  0.10125915 ;flux[17] =  0.12353780 ;

//===========  E-counter yield for data #65078  ======================//
/*	Eyield[0]= 2266.0;	Eyield[1]= 2618.0;	Eyield[2]= 2911.0;
	Eyield[3]= 2822.0;	Eyield[4]= 3193.0;	Eyield[5]= 3447.0;
	Eyield[6]= 3898.0;	Eyield[7]= 3566.0;	Eyield[8]= 3710.0;
	Eyield[9]= 3676.0;	Eyield[10]= 3926.0;	Eyield[11]= 3245.0;
	Eyield[12]= 1705.0;	Eyield[13]= 4062.0;	Eyield[14]= 4453.0;
	Eyield[15]= 4062.0;	Eyield[16]= 4709.0;	Eyield[17]= 5226.0;

*/
//======  only 6 E-channel  yield for data #65078  ======================//
	Eyield[0]= 1549.0;	Eyield[1]= 1529.0;	Eyield[2]= 1750.0;
	Eyield[3]= 1495.0;	Eyield[4]= 1963.0;	Eyield[5]= 1889.0;
	Eyield[6]= 2307.0;	Eyield[7]= 2302.0;	Eyield[8]= 2210.0;
	Eyield[9]= 2153.0;	Eyield[10]= 2333.0;	Eyield[11]= 2310.0;
	Eyield[12]= 1023.0;	Eyield[13]= 2583.0;	Eyield[14]= 2635.0;
	Eyield[15]= 2533.0;	Eyield[16]= 2089.0;	Eyield[17]= 3156.0;





//===========  E-counter yield for MC  ======================//
	MCEyield[0]= 5146.0;	MCEyield[1]= 5973.0;	MCEyield[2]= 6409.0;
	MCEyield[3]= 6106.0;	MCEyield[4]= 6845.0;	MCEyield[5]= 7625.0;
	MCEyield[6]= 8237.0;	MCEyield[7]= 8055.0;	MCEyield[8]= 7961.0;
	MCEyield[9]= 7521.0;	MCEyield[10]= 8461.0;	MCEyield[11]= 7030.0;
	MCEyield[12]= 3795.0;	MCEyield[13]= 8462.0;	MCEyield[14]= 9405.0;
	MCEyield[15]= 8837.0;	MCEyield[16]= 9881.0;	MCEyield[17]= 7624.0;
//===========  T-counter yield for data #65078  ======================//
	Tyield[0]= 2456.0;	Tyield[1]= 3087.0;	Tyield[2]= 3825.0;
	Tyield[3]= 2563.0;	Tyield[4]= 3173.0;	Tyield[5]= 3290.0;
	Tyield[6]= 3353.0;	Tyield[7]= 3133.0;	Tyield[8]= 3663.0;
	Tyield[9]= 3655.0;	Tyield[10]= 4519.0;	Tyield[11]= 2884.0;
	Tyield[12]= 2995.0;	Tyield[13]= 4437.0;	Tyield[14]= 3238.0;
	Tyield[15]= 3254.0;	Tyield[16]= 3714.0;	Tyield[17]= 4556.0;
//===========  T-counter yield for MC  ======================//
	MCTyield[0]= 7121.0;	MCTyield[1]= 6627.0;	MCTyield[2]= 8251.0;
	MCTyield[3]= 6450.0;	MCTyield[4]= 6481.0;	MCTyield[5]= 7639.0;
	MCTyield[6]= 7042.0;	MCTyield[7]= 8381.0;	MCTyield[8]= 7213.0;
	MCTyield[9]= 7241.0;	MCTyield[10]= 9802.0;	MCTyield[11]= 5274.0;
	MCTyield[12]= 7564.0;	MCTyield[13]= 9623.0;	MCTyield[14]= 6380.0;
	MCTyield[15]= 7024.0;	MCTyield[16]= 8960.0;	MCTyield[17]= 6300.0;
//===========   efficiency for T-counter  ======================//
	Teff[0]= 0.8655;	Teff[1]= 0.8875;	Teff[2]= 0.9093;
	Teff[3]= 0.9246;	Teff[4]= 0.9335;	Teff[5]= 0.9396;
	Teff[6]= 0.9454;	Teff[7]= 0.9506;	Teff[8]= 0.9537;
	Teff[9]= 0.9557;	Teff[10]= 0.9600;	Teff[11]= 0.9610;
	Teff[12]= 0.9636;	Teff[13]= 0.9653;	Teff[14]= 0.9662;
	Teff[15]= 0.9676;	Teff[16]= 0.9677;	Teff[17]= 0.9687;
	
//===========   efficiency for E-counter center part ======================//

	Eeff[0]= 0.8655;	Eeff[1]= 0.8875;	Eeff[2]= 0.9093;
	Eeff[3]= 0.9246;	Eeff[4]= 0.9335;	Eeff[5]= 0.9396;
	Eeff[6]= 0.9454;	Eeff[7]= 0.9506;	Eeff[8]= 0.9537;
	Eeff[9]= 0.9557;	Eeff[10]= 0.9600;	Eeff[11]= 0.9610;
	Eeff[12]= 0.9636;	Eeff[13]= 0.9653;	Eeff[14]= 0.9662;
	Eeff[15]= 0.9676;	Eeff[16]= 0.9677;	Eeff[17]= 0.9687;

//===========   tdiff alienment for #64878  ======================//

	Tid_64878[0] = 2.614;	Tid_64878[1] = 2.568;	Tid_64878[2] = 2.528;
	Tid_64878[3] = 2.515;	Tid_64878[4] = 2.575;	Tid_64878[5] = 2.477;
	Tid_64878[6] = 2.470;	Tid_64878[7] = 2.281;	Tid_64878[8] = 2.309;
	Tid_64878[9] = 2.258;	Tid_64878[10]= 2.201;	Tid_64878[11]= 2.289;
	Tid_64878[12]= 2.184;	Tid_64878[13]= 1.997;	Tid_64878[14]= 1.925;
	Tid_64878[15]= 1.654;	Tid_64878[16]= 1.637;	Tid_64878[17]= 1.419;

//===========   tdiff alienment for #65078  ======================//
	
  Tid_65078[0] = 2.625;	Tid_65078[1] = 2.568;	Tid_65078[2] = 2.498;
  Tid_65078[3] = 2.422;	Tid_65078[4] = 2.449;	Tid_65078[5] = 2.327;
  Tid_65078[6] = 2.344;	Tid_65078[7] = 2.170;	Tid_65078[8] = 2.204;
  Tid_65078[9] = 2.099;	Tid_65078[10]= 2.065;	Tid_65078[11]= 2.157;
  Tid_65078[12]= 2.001;	Tid_65078[13]= 1.847;	Tid_65078[14]= 1.704;
  Tid_65078[15]= 1.470;	Tid_65078[16]= 1.431;	Tid_65078[17]= 1.206;


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
	
	



   TMultiGraph *mg = new TMultiGraph("mg"," T-counter tdiff alienment #65078");
   TGraphErrors *g1 = new TGraphErrors(18,Tid,Tid_65078,0,0);
   TGraphErrors *g2 = new TGraphErrors(18,Ecounter,MCTyield,0,0);	
//   TGraphErrors *g3 = new TGraphErrors(6,x,y3,0,yerr3);

  TCanvas *c11 = new TCanvas("c11","counts vs T",600,600);
  
 
//  g1->Draw("A*");
g1->SetName("g1");
g1->SetTitle("");  
g1->SetMarkerStyle(21);
g1->SetMarkerColor(2);
g1->SetMarkerSize(1.0);
g1->SetDrawOption("AP");
g1->SetLineColor(1);
g1->SetLineWidth(0);
g1->SetFillStyle(0);
g1->GetYaxis()->SetTitle("alienment (ns)");
g1->GetXaxis()->SetTitle("Tid numbers");


g2->SetName("g2");
g2->SetTitle("");
g2->SetMarkerStyle(22); 
g2->SetMarkerSize(1.5);
g2->SetMarkerColor(4);
g2->SetDrawOption("P");
g2->SetLineColor(2);
g2->SetLineWidth(0);
g2->SetFillStyle(0);




mg->Add(g1);
//mg->Add(g2);


mg->Draw("AP");
mg->GetXaxis()->SetTitle(" Tid ");
mg->GetYaxis()->SetTitle(" alienment (ns) ");
gPad->Modified();


//mg->GetYaxis()->SetLimits(0,1);


TLegend *leg;
  

leg = new TLegend(0.1,0.7,0.5,0.9);
leg->AddEntry("g1","E-counter yield ");
leg->AddEntry("g2","T-counter yield");
//leg->AddEntry("g3","1.30-1.55deg angle bin");
leg->Draw();






  //g1->GetXaxis()->SetRange(0,1400);
/*
  g1->Fit("fitf","","",0,0);
  Double_t parameter[2];

  fitf->GetParameters(parameter);
  cout<<"y[500]="<<parameter[0] + parameter[1] * 500<<endl;

*/



 }







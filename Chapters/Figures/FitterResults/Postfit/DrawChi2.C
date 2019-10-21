{
   gStyle->SetOptStat(0000);
   TCanvas *c1 = new TCanvas("c1","transparent pad",200,10,700,500);
   TPad *pad1 = new TPad("pad1","",0,0,1,1);
   TPad *pad2 = new TPad("pad2","",0,0,1,1);
   pad2->SetFillStyle(4000); //will be transparent
   pad1->Draw();
   pad1->cd();
   TF1 *chi2 = new TF1("chi2","1/2.54011888031302306e-02*0.954*ROOT::Math::chisquared_pdf(x, 125.)", 50, 200);
   TF1 *cdf =  new TF1("cdf", "ROOT::Math::chisquared_cdf_c(x, 125.)", 50, 200);
   chi2->SetLineColor(kBlack);
   chi2->SetLineWidth(1);
   chi2->SetFillColor(kGray);
   chi2->SetFillStyle(3001);
   chi2->GetXaxis()->SetTitle("#chi^{2} Value");
   chi2->GetXaxis()->SetTitleOffset(.7);
   chi2->GetXaxis()->CenterTitle();
   chi2->GetYaxis()->SetTitle("Probability");
   chi2->GetYaxis()->SetTitleOffset(.7);
   //chi2->SetLineStyle(9);
   chi2->Draw();
   //pad1->Update(); //this will force the generation of the "stats" box
   //pad1->Modified();
   c1->cd();
   //compute the pad range with suitable margins
   Double_t ymin = 0.;
   Double_t ymax = 1.;
   Double_t dy = (ymax-ymin)/0.8; //10 per cent margins top and bottom
   Double_t xmin = 50;
   Double_t xmax = 200;
   Double_t dx = (xmax-xmin)/0.8; //10 per cent margins left and right
   pad2->Range(xmin-0.1*dx,ymin-0.1*dy,xmax+0.1*dx,ymax+0.1*dy);
   pad2->Draw();
   pad2->cd();
   cdf->Draw("][sames fill");
   TLine* chi2Value = new TLine(115.535462003, 0, 115.535462003, 1);
   chi2Value->SetLineStyle(9);
   chi2Value->SetLineWidth(3);
   chi2Value->SetLineColor(interface.kcbRed);
   chi2Value->Draw();
   TLegend* l = new TLegend(0.581662, 0.643312, 0.945559, 0.870488);
   l->AddEntry(chi2, "F(#chi^{2},r=125)", "F");
   l->AddEntry(cdf, "ICDF", "L");
   l->AddEntry(chi2Value, "#chi^{2}_{P0DvsFGD}", "L");
   l->SetFillStyle(0);
   l->SetBorderSize(0);
   l->Draw();
   pad2->Update();
   // draw axis on the right side of the pad
   //TGaxis *axis = new TGaxis(xmax,ymin,xmax,ymax,ymin,ymax,50510,"+L");
   //axis->SetLabelColor(kRed);
   //axis->Draw();
   interface.SaveCanvasAs(c1, "P0DFGDNDFluxSKFluxXSecChi2");
}

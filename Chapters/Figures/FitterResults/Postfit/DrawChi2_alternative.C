{
   gStyle->SetOptStat(0000);
   TCanvas *c1 = new TCanvas("c1","transparent pad",200,10,700,500);
   TPad *pad1 = new TPad("pad1","",0,0,1,1);
   TPad *pad2 = new TPad("pad2","",0,0,1,1);
   pad2->SetFillStyle(4000); //will be transparent
   pad1->Draw();
   pad1->cd();
   TF1 *chi2 = new TF1("chi2","1/3.29414053249132630e-02*0.954*ROOT::Math::chisquared_pdf(x, 75.)", 25, 150);
   TF1 *cdf =  new TF1("cdf", "ROOT::Math::chisquared_cdf_c(x, 75.)", 25, 150);
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
   Double_t xmin = 25;
   Double_t xmax = 150;
   Double_t dx = (xmax-xmin)/0.8; //10 per cent margins left and right
   pad2->Range(xmin-0.1*dx,ymin-0.1*dy,xmax+0.1*dx,ymax+0.1*dy);
   pad2->Draw();
   pad2->cd();
   cdf->Draw("][sames fill");
   const Double_t x1 = 81.4116109445;
   TLine* chi2Value = new TLine(x1, 0, x1, 1);
   chi2Value->SetLineStyle(9);
   chi2Value->SetLineWidth(3);
   chi2Value->SetLineColor(interface.kcbRed);
   chi2Value->Draw();
   const Double_t p5PC = 96.21;
   TLine* chi2FivePercentValue = new TLine(p5PC, 0, p5PC, 0.5);
   chi2FivePercentValue->SetLineWidth(3);
   chi2FivePercentValue->SetLineColor(interface.kcbBlue);
   chi2FivePercentValue->Draw();
   TArrow *ar = new TArrow(p5PC, 0.5, p5PC+15 ,0.5 ,0.05, "|>");
   ar->SetLineColor(interface.kcbBlue);
   ar->SetFillColor(interface.kcbBlue);
   ar->SetLineWidth(3);
   ar->Draw();
   TLegend* l = new TLegend(0.532951, 0.547771, 0.896848, 0.870488);
   l->AddEntry(chi2, "F(#chi^{2},r=75)", "F");
   l->AddEntry(cdf, "ICDF", "L");
   l->AddEntry(chi2Value, "#chi^{2} P0DvsFGD", "L");
   l->AddEntry(ar, "5\% level", "L");
   l->SetFillStyle(0);
   l->SetBorderSize(0);
   l->Draw();
   pad2->Update();
   // draw axis on the right side of the pad
   //TGaxis *axis = new TGaxis(xmax,ymin,xmax,ymax,ymin,ymax,50510,"+L");
   //axis->SetLabelColor(kRed);
   //axis->Draw();
   interface.SaveCanvasAs(c1, "P0DFGDNDFluxSKFluxXSecChi2_alternative");
}

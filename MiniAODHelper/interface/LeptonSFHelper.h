#ifndef _LeptonSFHelper_h
#define _LeptonSFHelper_h

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

#include "TMath.h"
#include "TFile.h"
#include "TH2F.h"

#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"


class LeptonSFHelper {
  
 public:
  LeptonSFHelper( );
  ~LeptonSFHelper( );

  std::map< std::string, float>  GetLeptonSF( const std::vector< pat::Electron >& Electrons,
					      const std::vector< pat::Muon >& Muons);
  
  float GetElectronSF(  float electronPt , float electronEta , int syst , std::string type  );
  float GetMuonSF(  float muonPt , float muonEta , int syst , std::string type  );

 private:

  void SetElectronHistos( );
  void SetMuonHistos( );

  TH2F *h_ele_ID_abseta_pt_ratio;
  TH2F *h_ele_TRIGGER_abseta_pt_ratio;
  TH2F *h_ele_ISO_abseta_pt_ratio;

  TH2F *h_mu_ID_abseta_pt_ratio;
  TH2F *h_mu_TRIGGER_abseta_pt_ratio4p3;
  TH2F *h_mu_TRIGGER_abseta_pt_ratio4p2;
  TH2F *h_mu_ISO_abseta_pt_ratio;

  float electronMaxPt;
  float muonMaxPt;


};

#endif

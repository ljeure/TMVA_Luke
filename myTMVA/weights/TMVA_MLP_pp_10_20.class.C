// Class: ReadMLP
// Automatically generated by MethodBase::MakeClass
//

/* configuration options =====================================================

#GEN -*-*-*-*-*-*-*-*-*-*-*- general info -*-*-*-*-*-*-*-*-*-*-*-

Method         : MLP::MLP
TMVA Release   : 4.2.0         [262656]
ROOT Release   : 6.02/13       [393741]
Creator        : leure
Date           : Mon Jun  5 16:50:08 2017
Host           : Linux vocms029.cern.ch 2.6.32-504.12.2.el6.x86_64 #1 SMP Thu Mar 12 07:33:00 CET 2015 x86_64 x86_64 x86_64 GNU/Linux
Dir            : /afs/cern.ch/user/l/leure/newWS/CMSSW_7_5_8_patch3/macros/TMVA_Luke/myTMVA
Training events: 2278
Analysis type  : [Classification]


#OPT -*-*-*-*-*-*-*-*-*-*-*-*- options -*-*-*-*-*-*-*-*-*-*-*-*-

# Set by User:
NCycles: "600" [Number of training cycles]
HiddenLayers: "N+5" [Specification of hidden layer architecture]
NeuronType: "tanh" [Neuron activation function type]
V: "False" [Verbose output (short form of "VerbosityLevel" below - overrides the latter one)]
VarTransform: "N" [List of variable transformations performed before training, e.g., "D_Background,P_Signal,G,N_AllClasses" for: "Decorrelation, PCA-transformation, Gaussianisation, Normalisation, each for the given class of events ('AllClasses' denotes all events of all classes, if no class indication is given, 'All' is assumed)"]
H: "True" [Print method-specific help message]
TestRate: "5" [Test for overtraining performed at each #th epochs]
UseRegulator: "False" [Use regulator to avoid over-training]
# Default:
RandomSeed: "1" [Random seed for initial synapse weights (0 means unique seed for each run; default value '1')]
EstimatorType: "MSE" [MSE (Mean Square Estimator) for Gaussian Likelihood or CE(Cross-Entropy) for Bernoulli Likelihood]
NeuronInputType: "sum" [Neuron input function type]
VerbosityLevel: "Default" [Verbosity level]
CreateMVAPdfs: "False" [Create PDFs for classifier outputs (signal and background)]
IgnoreNegWeightsInTraining: "False" [Events with negative weights are ignored in the training (but are included for testing and performance evaluation)]
TrainingMethod: "BP" [Train with Back-Propagation (BP), BFGS Algorithm (BFGS), or Genetic Algorithm (GA - slower and worse)]
LearningRate: "2.000000e-02" [ANN learning rate parameter]
DecayRate: "1.000000e-02" [Decay rate for learning parameter]
EpochMonitoring: "False" [Provide epoch-wise monitoring plots according to TestRate (caution: causes big ROOT output file!)]
Sampling: "1.000000e+00" [Only 'Sampling' (randomly selected) events are trained each epoch]
SamplingEpoch: "1.000000e+00" [Sampling is used for the first 'SamplingEpoch' epochs, afterwards, all events are taken for training]
SamplingImportance: "1.000000e+00" [ The sampling weights of events in epochs which successful (worse estimator than before) are multiplied with SamplingImportance, else they are divided.]
SamplingTraining: "True" [The training sample is sampled]
SamplingTesting: "False" [The testing sample is sampled]
ResetStep: "50" [How often BFGS should reset history]
Tau: "3.000000e+00" [LineSearch "size step"]
BPMode: "sequential" [Back-propagation learning mode: sequential or batch]
BatchSize: "-1" [Batch size: number of events/batch, only set if in Batch Mode, -1 for BatchSize=number_of_events]
ConvergenceImprove: "1.000000e-30" [Minimum improvement which counts as improvement (<0 means automatic convergence check is turned off)]
ConvergenceTests: "-1" [Number of steps (without improvement) required for convergence (<0 means automatic convergence check is turned off)]
UpdateLimit: "10000" [Maximum times of regulator update]
CalculateErrors: "False" [Calculates inverse Hessian matrix at the end of the training to be able to calculate the uncertainties of an MVA value]
WeightRange: "1.000000e+00" [Take the events for the estimator calculations from small deviations from the desired value to large deviations only over the weight range]
##


#VAR -*-*-*-*-*-*-*-*-*-*-*-* variables *-*-*-*-*-*-*-*-*-*-*-*-

NVar 10
Dtrk1Pt                       Dtrk1Pt                       Dtrk1Pt                       Dtrk1Pt                                                         'F'    [0.500156283379,11.9162597656]
DRestrk1Pt                    DRestrk1Pt                    DRestrk1Pt                    DRestrk1Pt                                                      'F'    [0.528972029686,17.9831829071]
DRestrk2Pt                    DRestrk2Pt                    DRestrk2Pt                    DRestrk2Pt                                                      'F'    [0.503112733364,17.9460926056]
DtktkRespt                    DtktkRespt                    DtktkRespt                    DtktkRespt                                                      'F'    [8.00088214874,19.785320282]
Dchi2cl                       Dchi2cl                       Dchi2cl                       Dchi2cl                                                         'F'    [0.0502614192665,0.999811887741]
DtktkRes_chi2cl               DtktkRes_chi2cl               DtktkRes_chi2cl               DtktkRes_chi2cl                                                 'F'    [0.0515457801521,0.999825298786]
Dalpha                        Dalpha                        Dalpha                        Dalpha                                                          'F'    [9.7360854852e-05,0.199994683266]
DtktkRes_alpha                DtktkRes_alpha                DtktkRes_alpha                DtktkRes_alpha                                                  'F'    [0.000620291160885,0.19980455935]
DsvpvDistance/DsvpvDisErr     DsvpvDistance_D_DsvpvDisErr   DsvpvDistance/DsvpvDisErr     DsvpvDistance/DsvpvDisErr                                       'F'    [2.00035476685,1013.29718018]
DtktkRes_svpvDistance/DtktkRes_svpvDisErr   DtktkRes_svpvDistance_D_DtktkRes_svpvDisErr DtktkRes_svpvDistance/DtktkRes_svpvDisErr   DtktkRes_svpvDistance/DtktkRes_svpvDisErr                                                   'F'    [2.00124073029,153.179229736]
NSpec 0


============================================================================ */

#include <vector>
#include <cmath>
#include <string>
#include <iostream>

#ifndef IClassifierReader__def
#define IClassifierReader__def

class IClassifierReader {

 public:

   // constructor
   IClassifierReader() : fStatusIsClean( true ) {}
   virtual ~IClassifierReader() {}

   // return classifier response
   virtual double GetMvaValue( const std::vector<double>& inputValues ) const = 0;

   // returns classifier status
   bool IsStatusClean() const { return fStatusIsClean; }

 protected:

   bool fStatusIsClean;
};

#endif

class ReadMLP : public IClassifierReader {

 public:

   // constructor
   ReadMLP( std::vector<std::string>& theInputVars ) 
      : IClassifierReader(),
        fClassName( "ReadMLP" ),
        fNvars( 10 ),
        fIsNormalised( false )
   {      
      // the training input variables
      const char* inputVars[] = { "Dtrk1Pt", "DRestrk1Pt", "DRestrk2Pt", "DtktkRespt", "Dchi2cl", "DtktkRes_chi2cl", "Dalpha", "DtktkRes_alpha", "DsvpvDistance/DsvpvDisErr", "DtktkRes_svpvDistance/DtktkRes_svpvDisErr" };

      // sanity checks
      if (theInputVars.size() <= 0) {
         std::cout << "Problem in class \"" << fClassName << "\": empty input vector" << std::endl;
         fStatusIsClean = false;
      }

      if (theInputVars.size() != fNvars) {
         std::cout << "Problem in class \"" << fClassName << "\": mismatch in number of input values: "
                   << theInputVars.size() << " != " << fNvars << std::endl;
         fStatusIsClean = false;
      }

      // validate input variables
      for (size_t ivar = 0; ivar < theInputVars.size(); ivar++) {
         if (theInputVars[ivar] != inputVars[ivar]) {
            std::cout << "Problem in class \"" << fClassName << "\": mismatch in input variable names" << std::endl
                      << " for variable [" << ivar << "]: " << theInputVars[ivar].c_str() << " != " << inputVars[ivar] << std::endl;
            fStatusIsClean = false;
         }
      }

      // initialize min and max vectors (for normalisation)
      fVmin[0] = -1;
      fVmax[0] = 0.99999988079071;
      fVmin[1] = -1;
      fVmax[1] = 1;
      fVmin[2] = -1;
      fVmax[2] = 1;
      fVmin[3] = -1;
      fVmax[3] = 1;
      fVmin[4] = -1;
      fVmax[4] = 1;
      fVmin[5] = -1;
      fVmax[5] = 0.99999988079071;
      fVmin[6] = -1;
      fVmax[6] = 1;
      fVmin[7] = -1;
      fVmax[7] = 1;
      fVmin[8] = -1;
      fVmax[8] = 1;
      fVmin[9] = -1;
      fVmax[9] = 1;

      // initialize input variable types
      fType[0] = 'F';
      fType[1] = 'F';
      fType[2] = 'F';
      fType[3] = 'F';
      fType[4] = 'F';
      fType[5] = 'F';
      fType[6] = 'F';
      fType[7] = 'F';
      fType[8] = 'F';
      fType[9] = 'F';

      // initialize constants
      Initialize();

      // initialize transformation
      InitTransform();
   }

   // destructor
   virtual ~ReadMLP() {
      Clear(); // method-specific
   }

   // the classifier response
   // "inputValues" is a vector of input values in the same order as the 
   // variables given to the constructor
   double GetMvaValue( const std::vector<double>& inputValues ) const;

 private:

   // method-specific destructor
   void Clear();

   // input variable transformation

   double fMin_1[3][10];
   double fMax_1[3][10];
   void InitTransform_1();
   void Transform_1( std::vector<double> & iv, int sigOrBgd ) const;
   void InitTransform();
   void Transform( std::vector<double> & iv, int sigOrBgd ) const;

   // common member variables
   const char* fClassName;

   const size_t fNvars;
   size_t GetNvar()           const { return fNvars; }
   char   GetType( int ivar ) const { return fType[ivar]; }

   // normalisation of input variables
   const bool fIsNormalised;
   bool IsNormalised() const { return fIsNormalised; }
   double fVmin[10];
   double fVmax[10];
   double NormVariable( double x, double xmin, double xmax ) const {
      // normalise to output range: [-1, 1]
      return 2*(x - xmin)/(xmax - xmin) - 1.0;
   }

   // type of input variable: 'F' or 'I'
   char   fType[10];

   // initialize internal variables
   void Initialize();
   double GetMvaValue__( const std::vector<double>& inputValues ) const;

   // private members (method specific)

   double ActivationFnc(double x) const;
   double OutputActivationFnc(double x) const;

   int fLayers;
   int fLayerSize[3];
   double fWeightMatrix0to1[16][11];   // weight matrix from layer 0 to 1
   double fWeightMatrix1to2[1][16];   // weight matrix from layer 1 to 2

   double * fWeights[3];
};

inline void ReadMLP::Initialize()
{
   // build network structure
   fLayers = 3;
   fLayerSize[0] = 11; fWeights[0] = new double[11]; 
   fLayerSize[1] = 16; fWeights[1] = new double[16]; 
   fLayerSize[2] = 1; fWeights[2] = new double[1]; 
   // weight matrix from layer 0 to 1
   fWeightMatrix0to1[0][0] = -1.09939151653433;
   fWeightMatrix0to1[1][0] = 1.42601258410976;
   fWeightMatrix0to1[2][0] = 1.28923116038775;
   fWeightMatrix0to1[3][0] = 1.88901163123614;
   fWeightMatrix0to1[4][0] = -1.97617689664328;
   fWeightMatrix0to1[5][0] = -2.22345821017421;
   fWeightMatrix0to1[6][0] = -0.705234296701896;
   fWeightMatrix0to1[7][0] = 4.44607751866513;
   fWeightMatrix0to1[8][0] = -1.49761224154945;
   fWeightMatrix0to1[9][0] = -1.65561439319016;
   fWeightMatrix0to1[10][0] = -1.7128317686393;
   fWeightMatrix0to1[11][0] = -0.0783427265741445;
   fWeightMatrix0to1[12][0] = -1.9555627339687;
   fWeightMatrix0to1[13][0] = -0.216436625457246;
   fWeightMatrix0to1[14][0] = -0.672697295762153;
   fWeightMatrix0to1[0][1] = 0.629874263235862;
   fWeightMatrix0to1[1][1] = -0.763435889135578;
   fWeightMatrix0to1[2][1] = 1.92368208501154;
   fWeightMatrix0to1[3][1] = 0.329290519416934;
   fWeightMatrix0to1[4][1] = 0.803518891774397;
   fWeightMatrix0to1[5][1] = -0.425692319338494;
   fWeightMatrix0to1[6][1] = -0.852520109463518;
   fWeightMatrix0to1[7][1] = 0.937945627316758;
   fWeightMatrix0to1[8][1] = -0.518676289911595;
   fWeightMatrix0to1[9][1] = 0.705224549435916;
   fWeightMatrix0to1[10][1] = 0.0209380460525559;
   fWeightMatrix0to1[11][1] = 1.47207515359743;
   fWeightMatrix0to1[12][1] = 0.0874413898504572;
   fWeightMatrix0to1[13][1] = -1.58914289333013;
   fWeightMatrix0to1[14][1] = -0.277363105069718;
   fWeightMatrix0to1[0][2] = 0.649007692664694;
   fWeightMatrix0to1[1][2] = 1.39462680597015;
   fWeightMatrix0to1[2][2] = -1.03445884945222;
   fWeightMatrix0to1[3][2] = -0.0779610127132375;
   fWeightMatrix0to1[4][2] = 0.420057144858554;
   fWeightMatrix0to1[5][2] = -0.259793034101029;
   fWeightMatrix0to1[6][2] = -1.80063590517949;
   fWeightMatrix0to1[7][2] = 0.94397214458539;
   fWeightMatrix0to1[8][2] = -1.29033417460455;
   fWeightMatrix0to1[9][2] = 0.77411967563679;
   fWeightMatrix0to1[10][2] = 0.725830059735355;
   fWeightMatrix0to1[11][2] = 0.962475532225861;
   fWeightMatrix0to1[12][2] = 1.8823016076688;
   fWeightMatrix0to1[13][2] = 1.35937265123216;
   fWeightMatrix0to1[14][2] = -0.887823489455822;
   fWeightMatrix0to1[0][3] = -1.32585305710877;
   fWeightMatrix0to1[1][3] = 0.44584506272524;
   fWeightMatrix0to1[2][3] = -0.403418817153491;
   fWeightMatrix0to1[3][3] = 1.52780942053627;
   fWeightMatrix0to1[4][3] = 0.960696428542803;
   fWeightMatrix0to1[5][3] = 0.570504737470235;
   fWeightMatrix0to1[6][3] = 0.772109417922266;
   fWeightMatrix0to1[7][3] = -0.834494197443276;
   fWeightMatrix0to1[8][3] = 0.786593038616044;
   fWeightMatrix0to1[9][3] = -0.53930778148362;
   fWeightMatrix0to1[10][3] = -0.901343170868825;
   fWeightMatrix0to1[11][3] = -0.791631171131115;
   fWeightMatrix0to1[12][3] = -0.290108594726836;
   fWeightMatrix0to1[13][3] = 1.68375520022928;
   fWeightMatrix0to1[14][3] = 0.518393360305816;
   fWeightMatrix0to1[0][4] = -1.5540084826443;
   fWeightMatrix0to1[1][4] = 0.232260792967182;
   fWeightMatrix0to1[2][4] = 0.185425378284988;
   fWeightMatrix0to1[3][4] = 0.449878026492751;
   fWeightMatrix0to1[4][4] = 1.62272782388119;
   fWeightMatrix0to1[5][4] = -0.765037266844643;
   fWeightMatrix0to1[6][4] = -0.258877495332097;
   fWeightMatrix0to1[7][4] = 0.343821730929307;
   fWeightMatrix0to1[8][4] = 0.189180944942343;
   fWeightMatrix0to1[9][4] = 0.214584817570947;
   fWeightMatrix0to1[10][4] = -0.609092260673536;
   fWeightMatrix0to1[11][4] = -0.766563543757424;
   fWeightMatrix0to1[12][4] = 0.158508971487955;
   fWeightMatrix0to1[13][4] = 0.774403656400101;
   fWeightMatrix0to1[14][4] = 0.397433878534802;
   fWeightMatrix0to1[0][5] = -0.295316322459887;
   fWeightMatrix0to1[1][5] = -1.8876281220513;
   fWeightMatrix0to1[2][5] = -1.70973577723503;
   fWeightMatrix0to1[3][5] = 0.644109680887492;
   fWeightMatrix0to1[4][5] = 0.866158555598988;
   fWeightMatrix0to1[5][5] = 0.477832579625811;
   fWeightMatrix0to1[6][5] = 0.828726107010567;
   fWeightMatrix0to1[7][5] = 0.221166045287205;
   fWeightMatrix0to1[8][5] = -0.900348330349801;
   fWeightMatrix0to1[9][5] = -0.16647655469944;
   fWeightMatrix0to1[10][5] = 0.109797357960122;
   fWeightMatrix0to1[11][5] = 0.605435739614554;
   fWeightMatrix0to1[12][5] = -0.56769329466105;
   fWeightMatrix0to1[13][5] = -1.51195318275306;
   fWeightMatrix0to1[14][5] = -1.46331319864833;
   fWeightMatrix0to1[0][6] = -0.574185915628243;
   fWeightMatrix0to1[1][6] = -0.0356184659028352;
   fWeightMatrix0to1[2][6] = 0.674182230470531;
   fWeightMatrix0to1[3][6] = -1.15308977894707;
   fWeightMatrix0to1[4][6] = -1.22001558297983;
   fWeightMatrix0to1[5][6] = 2.16107091638397;
   fWeightMatrix0to1[6][6] = -1.07918793904702;
   fWeightMatrix0to1[7][6] = -0.128090951339714;
   fWeightMatrix0to1[8][6] = -1.4501961625655;
   fWeightMatrix0to1[9][6] = 0.0231987106389163;
   fWeightMatrix0to1[10][6] = -2.0411518437475;
   fWeightMatrix0to1[11][6] = -1.7345029309805;
   fWeightMatrix0to1[12][6] = 0.296014006622822;
   fWeightMatrix0to1[13][6] = 1.68795574702854;
   fWeightMatrix0to1[14][6] = -1.22991138932293;
   fWeightMatrix0to1[0][7] = 0.819144539931547;
   fWeightMatrix0to1[1][7] = -1.28892340659286;
   fWeightMatrix0to1[2][7] = -0.515790430485607;
   fWeightMatrix0to1[3][7] = 0.00889368689087303;
   fWeightMatrix0to1[4][7] = -0.0244105600643064;
   fWeightMatrix0to1[5][7] = -2.29119314433564;
   fWeightMatrix0to1[6][7] = -0.054718968993834;
   fWeightMatrix0to1[7][7] = -0.563468493359098;
   fWeightMatrix0to1[8][7] = -0.00604796292900674;
   fWeightMatrix0to1[9][7] = -0.687052387369821;
   fWeightMatrix0to1[10][7] = 1.47220969940712;
   fWeightMatrix0to1[11][7] = 0.239511804448946;
   fWeightMatrix0to1[12][7] = -1.62759186013975;
   fWeightMatrix0to1[13][7] = 0.983135943600367;
   fWeightMatrix0to1[14][7] = -0.931273515867445;
   fWeightMatrix0to1[0][8] = -2.15713021425334;
   fWeightMatrix0to1[1][8] = -0.610793208762231;
   fWeightMatrix0to1[2][8] = -0.520312287942568;
   fWeightMatrix0to1[3][8] = 2.20493340475353;
   fWeightMatrix0to1[4][8] = 0.635366581209489;
   fWeightMatrix0to1[5][8] = 0.955667106182292;
   fWeightMatrix0to1[6][8] = -0.402520438550747;
   fWeightMatrix0to1[7][8] = -1.92055593725359;
   fWeightMatrix0to1[8][8] = -1.52351986972661;
   fWeightMatrix0to1[9][8] = 2.22089731409935;
   fWeightMatrix0to1[10][8] = -0.339542504722837;
   fWeightMatrix0to1[11][8] = -2.36266207382155;
   fWeightMatrix0to1[12][8] = 0.949718810859178;
   fWeightMatrix0to1[13][8] = -0.831423197745394;
   fWeightMatrix0to1[14][8] = -0.879282081698583;
   fWeightMatrix0to1[0][9] = 0.575643194365552;
   fWeightMatrix0to1[1][9] = 1.16568498589696;
   fWeightMatrix0to1[2][9] = -1.92003938470237;
   fWeightMatrix0to1[3][9] = 0.653915669575181;
   fWeightMatrix0to1[4][9] = 1.75757084610988;
   fWeightMatrix0to1[5][9] = 1.39274083826212;
   fWeightMatrix0to1[6][9] = 0.0290690408958381;
   fWeightMatrix0to1[7][9] = -0.621743484824897;
   fWeightMatrix0to1[8][9] = -0.85978309607691;
   fWeightMatrix0to1[9][9] = -3.05500533092685;
   fWeightMatrix0to1[10][9] = 1.1422990287088;
   fWeightMatrix0to1[11][9] = 0.604661980003003;
   fWeightMatrix0to1[12][9] = 0.236003024390901;
   fWeightMatrix0to1[13][9] = 0.156380549227676;
   fWeightMatrix0to1[14][9] = -0.620199144076838;
   fWeightMatrix0to1[0][10] = -0.801672959033719;
   fWeightMatrix0to1[1][10] = 1.35913157204809;
   fWeightMatrix0to1[2][10] = 2.09961406267387;
   fWeightMatrix0to1[3][10] = -1.03963022791907;
   fWeightMatrix0to1[4][10] = -0.478808497806764;
   fWeightMatrix0to1[5][10] = -0.788513309630666;
   fWeightMatrix0to1[6][10] = 1.20545429716088;
   fWeightMatrix0to1[7][10] = 2.64390138822111;
   fWeightMatrix0to1[8][10] = 1.56390496753054;
   fWeightMatrix0to1[9][10] = -2.65565879126516;
   fWeightMatrix0to1[10][10] = 1.98390445658035;
   fWeightMatrix0to1[11][10] = 1.37247697711146;
   fWeightMatrix0to1[12][10] = 0.0250020850247578;
   fWeightMatrix0to1[13][10] = -0.0356284602789296;
   fWeightMatrix0to1[14][10] = 1.86304921014911;
   // weight matrix from layer 1 to 2
   fWeightMatrix1to2[0][0] = 0.059043836304096;
   fWeightMatrix1to2[0][1] = -0.0240045309261902;
   fWeightMatrix1to2[0][2] = 0.142443807829775;
   fWeightMatrix1to2[0][3] = -0.464385723879132;
   fWeightMatrix1to2[0][4] = 0.040663658190799;
   fWeightMatrix1to2[0][5] = -0.298966460940576;
   fWeightMatrix1to2[0][6] = 0.885060759066777;
   fWeightMatrix1to2[0][7] = 0.598387814881334;
   fWeightMatrix1to2[0][8] = 0.843638922945792;
   fWeightMatrix1to2[0][9] = -0.784226743671818;
   fWeightMatrix1to2[0][10] = 0.0486975143106455;
   fWeightMatrix1to2[0][11] = -0.670056239073071;
   fWeightMatrix1to2[0][12] = 0.216841878648122;
   fWeightMatrix1to2[0][13] = -0.0282590225119763;
   fWeightMatrix1to2[0][14] = -0.629574613688228;
   fWeightMatrix1to2[0][15] = -1.55694776572159;
}

inline double ReadMLP::GetMvaValue__( const std::vector<double>& inputValues ) const
{
   if (inputValues.size() != (unsigned int)fLayerSize[0]-1) {
      std::cout << "Input vector needs to be of size " << fLayerSize[0]-1 << std::endl;
      return 0;
   }

   for (int l=0; l<fLayers; l++)
      for (int i=0; i<fLayerSize[l]; i++) fWeights[l][i]=0;

   for (int l=0; l<fLayers-1; l++)
      fWeights[l][fLayerSize[l]-1]=1;

   for (int i=0; i<fLayerSize[0]-1; i++)
      fWeights[0][i]=inputValues[i];

   // layer 0 to 1
   for (int o=0; o<fLayerSize[1]-1; o++) {
      for (int i=0; i<fLayerSize[0]; i++) {
         double inputVal = fWeightMatrix0to1[o][i] * fWeights[0][i];
         fWeights[1][o] += inputVal;
      }
      fWeights[1][o] = ActivationFnc(fWeights[1][o]);
   }
   // layer 1 to 2
   for (int o=0; o<fLayerSize[2]; o++) {
      for (int i=0; i<fLayerSize[1]; i++) {
         double inputVal = fWeightMatrix1to2[o][i] * fWeights[1][i];
         fWeights[2][o] += inputVal;
      }
      fWeights[2][o] = OutputActivationFnc(fWeights[2][o]);
   }

   return fWeights[2][0];
}

double ReadMLP::ActivationFnc(double x) const {
   // hyperbolic tan
   return tanh(x);
}
double ReadMLP::OutputActivationFnc(double x) const {
   // identity
   return x;
}
   
// Clean up
inline void ReadMLP::Clear() 
{
   // clean up the arrays
   for (int lIdx = 0; lIdx < 3; lIdx++) {
      delete[] fWeights[lIdx];
   }
}
   inline double ReadMLP::GetMvaValue( const std::vector<double>& inputValues ) const
   {
      // classifier response value
      double retval = 0;

      // classifier response, sanity check first
      if (!IsStatusClean()) {
         std::cout << "Problem in class \"" << fClassName << "\": cannot return classifier response"
                   << " because status is dirty" << std::endl;
         retval = 0;
      }
      else {
         if (IsNormalised()) {
            // normalise variables
            std::vector<double> iV;
            iV.reserve(inputValues.size());
            int ivar = 0;
            for (std::vector<double>::const_iterator varIt = inputValues.begin();
                 varIt != inputValues.end(); varIt++, ivar++) {
               iV.push_back(NormVariable( *varIt, fVmin[ivar], fVmax[ivar] ));
            }
            Transform( iV, -1 );
            retval = GetMvaValue__( iV );
         }
         else {
            std::vector<double> iV;
            int ivar = 0;
            for (std::vector<double>::const_iterator varIt = inputValues.begin();
                 varIt != inputValues.end(); varIt++, ivar++) {
               iV.push_back(*varIt);
            }
            Transform( iV, -1 );
            retval = GetMvaValue__( iV );
         }
      }

      return retval;
   }

//_______________________________________________________________________
inline void ReadMLP::InitTransform_1()
{
   // Normalization transformation, initialisation
   fMin_1[0][0] = 0.501355588436;
   fMax_1[0][0] = 11.9162597656;
   fMin_1[1][0] = 0.500156283379;
   fMax_1[1][0] = 10.1492881775;
   fMin_1[2][0] = 0.500156283379;
   fMax_1[2][0] = 11.9162597656;
   fMin_1[0][1] = 0.528972029686;
   fMax_1[0][1] = 17.9831829071;
   fMin_1[1][1] = 0.679787576199;
   fMax_1[1][1] = 17.9776611328;
   fMin_1[2][1] = 0.528972029686;
   fMax_1[2][1] = 17.9831829071;
   fMin_1[0][2] = 0.503957271576;
   fMax_1[0][2] = 16.4435195923;
   fMin_1[1][2] = 0.503112733364;
   fMax_1[1][2] = 17.9460926056;
   fMin_1[2][2] = 0.503112733364;
   fMax_1[2][2] = 17.9460926056;
   fMin_1[0][3] = 8.00088214874;
   fMax_1[0][3] = 19.785320282;
   fMin_1[1][3] = 8.33374977112;
   fMax_1[1][3] = 19.7318401337;
   fMin_1[2][3] = 8.00088214874;
   fMax_1[2][3] = 19.785320282;
   fMin_1[0][4] = 0.0504381991923;
   fMax_1[0][4] = 0.998341560364;
   fMin_1[1][4] = 0.0502614192665;
   fMax_1[1][4] = 0.999811887741;
   fMin_1[2][4] = 0.0502614192665;
   fMax_1[2][4] = 0.999811887741;
   fMin_1[0][5] = 0.0515457801521;
   fMax_1[0][5] = 0.999825298786;
   fMin_1[1][5] = 0.0519448369741;
   fMax_1[1][5] = 0.996817946434;
   fMin_1[2][5] = 0.0515457801521;
   fMax_1[2][5] = 0.999825298786;
   fMin_1[0][6] = 9.7360854852e-05;
   fMax_1[0][6] = 0.199994683266;
   fMin_1[1][6] = 0.000548715470359;
   fMax_1[1][6] = 0.19975912571;
   fMin_1[2][6] = 9.7360854852e-05;
   fMax_1[2][6] = 0.199994683266;
   fMin_1[0][7] = 0.0017870918382;
   fMax_1[0][7] = 0.19980455935;
   fMin_1[1][7] = 0.000620291160885;
   fMax_1[1][7] = 0.193031564355;
   fMin_1[2][7] = 0.000620291160885;
   fMax_1[2][7] = 0.19980455935;
   fMin_1[0][8] = 2.00035476685;
   fMax_1[0][8] = 135.795303345;
   fMin_1[1][8] = 2.00165367126;
   fMax_1[1][8] = 1013.29718018;
   fMin_1[2][8] = 2.00035476685;
   fMax_1[2][8] = 1013.29718018;
   fMin_1[0][9] = 2.0597653389;
   fMax_1[0][9] = 101.10533905;
   fMin_1[1][9] = 2.00124073029;
   fMax_1[1][9] = 153.179229736;
   fMin_1[2][9] = 2.00124073029;
   fMax_1[2][9] = 153.179229736;
}

//_______________________________________________________________________
inline void ReadMLP::Transform_1( std::vector<double>& iv, int cls) const
{
   // Normalization transformation
   if (cls < 0 || cls > 2) {
   if (2 > 1 ) cls = 2;
      else cls = 2;
   }
   const int nVar = 10;

   // get indices of used variables

   // define the indices of the variables which are transformed by this transformation
   static std::vector<int> indicesGet;
   static std::vector<int> indicesPut;

   if ( indicesGet.empty() ) { 
      indicesGet.reserve(fNvars);
      indicesGet.push_back( 0);
      indicesGet.push_back( 1);
      indicesGet.push_back( 2);
      indicesGet.push_back( 3);
      indicesGet.push_back( 4);
      indicesGet.push_back( 5);
      indicesGet.push_back( 6);
      indicesGet.push_back( 7);
      indicesGet.push_back( 8);
      indicesGet.push_back( 9);
   } 
   if ( indicesPut.empty() ) { 
      indicesPut.reserve(fNvars);
      indicesPut.push_back( 0);
      indicesPut.push_back( 1);
      indicesPut.push_back( 2);
      indicesPut.push_back( 3);
      indicesPut.push_back( 4);
      indicesPut.push_back( 5);
      indicesPut.push_back( 6);
      indicesPut.push_back( 7);
      indicesPut.push_back( 8);
      indicesPut.push_back( 9);
   } 

   static std::vector<double> dv;
   dv.resize(nVar);
   for (int ivar=0; ivar<nVar; ivar++) dv[ivar] = iv[indicesGet.at(ivar)];
   for (int ivar=0;ivar<10;ivar++) {
      double offset = fMin_1[cls][ivar];
      double scale  = 1.0/(fMax_1[cls][ivar]-fMin_1[cls][ivar]);
      iv[indicesPut.at(ivar)] = (dv[ivar]-offset)*scale * 2 - 1;
   }
}

//_______________________________________________________________________
inline void ReadMLP::InitTransform()
{
   InitTransform_1();
}

//_______________________________________________________________________
inline void ReadMLP::Transform( std::vector<double>& iv, int sigOrBgd ) const
{
   Transform_1( iv, sigOrBgd );
}

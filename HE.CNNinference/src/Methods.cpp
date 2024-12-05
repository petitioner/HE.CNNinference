#include "Tools.h"
#include "Methods.h"


#include "NTL/ZZX.h"

#include <cmath>




#include <NTL/BasicThreadPool.h>
#include <NTL/RR.h>
#include <NTL/ZZ.h>

#include <iomanip>
#include <set>
#include <map>
#include <typeinfo>
#include <vector>
#include <algorithm>    // std::shuffle
#include <vector>        // std::vector
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

#include <unistd.h>

#include "HEAAN.h"

int CNNinference(int rownum, int vctslots, int image_height, int image_width, vector<vector<vector<double>>> dataset, vector<vector<double>> weights)
{
  cout << endl << endl << endl << endl;
  cout << "" << endl << endl;
  cout << "rownum: " << rownum << endl;
  cout << "vctslots: " << vctslots << endl;
  cout << "image_height: " << image_height << endl;
  cout << "image_width: " << image_width << endl;

  cout << "!!! testAllFunctions() !!!" << endl;
  //-----------------------------------------
  long logN = 11;
  long logQ = 1200;
  long logp = 60;
  long logSlots = 3;

logp = 23; 


long logT = 2;
long slots = 1 << logSlots;
long logq = 29; 

  TimeUtils timeutils;
  SecretKey sk(logN);
  sk.saveToFile("seckey.dat");
  auto secretKey = SecretKey::loadFromFile("seckey.dat");
      
  Scheme sche(logN, logQ);
  auto pubKey = sche.generatePubKey(secretKey);
  sche.setEncryptionKey(pubKey);
  sche.saveEncKeyToFile("pubkey.dat");
  auto conjKey = sche.generateConjKey(secretKey);
  sche.setConjugationKey(conjKey);
  sche.saveConjKeyToFile("conjKey.dat");
  auto multKey = sche.generateMultKey(secretKey);
  sche.setMultiplicationKey(multKey);
  sche.saveMultKeyToFile("multKey.dat");
  auto leftRotKey = sche.generateLeftRotKey(secretKey, 1);
  sche.setLeftRotKey(1, leftRotKey);
  sche.saveLeftRotKeyToFile(1, leftRotKey, "leftRotKey1.dat");
  auto rightRotKey = sche.generateRightRotKey(secretKey, 1);
  sche.setRightRotKey(1, rightRotKey);
  sche.saveRightRotKeyToFile(1, rightRotKey, "rightRotKey1.dat");

  sche.addBootKey(secretKey, 0, logq + 4);
  sche.addBootKey(secretKey, logSlots, logq + 4);
  sche.saveBootContextMapToFile("bootcontextmap.dat");
  sche.saveLeftRotKeyMapToFile("leftrotkeymap.dat"); 



  Scheme scheme(logN, logQ);
  scheme.setSecretKey(Scheme::loadSecretKeyFromFile("seckey.dat"));
  scheme.setEncryptionKey(Scheme::loadEncKeyFromFile("pubkey.dat"));
  scheme.setMultiplicationKey(Scheme::loadMultKeyFromFile("multKey.dat"));
  scheme.setConjugationKey(Scheme::loadConjKeyFromFile("conjKey.dat"));
  scheme.setLeftRotKey(1, Scheme::loadLeftRotKeyFromFile(1, "leftRotKey1.dat"));
  scheme.setRightRotKey(1, Scheme::loadRightRotKeyFromFile(1, "rightRotKey1.dat", 1<<(logN-1)) );
  scheme.setBootContextMap(Scheme::loadBootContextMapFromFile("bootcontextmap.dat", logN) );
  scheme.setLeftRotKeyMap(Scheme::loadLeftRotKeyMapFromFile("leftrotkeymap.dat")   );
  
  //scheme.sdf(secretKey, 0, logq + 4);
  //scheme.sdf(secretKey, logSlots, logq + 4);
  //-----------------------------------------
  timeutils.start("Key generating");
  //scheme.addBootKey(secretKey, 0, logq + 4);
  //scheme.addBootKey(secretKey, logSlots, logq + 4);
  timeutils.stop("Key generated");
//-----------------------------------------
  
  //-----------------------------------------
  srand(time(NULL));
  //-----------------------------------------

  
  ///////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////

  double mval = EvaluatorUtils::randomReal();
  Ciphertext cipher = scheme.encrypt(mval, logp, logQ);
  
  double dval = scheme.decryptSingle(secretKey, cipher);
  StringUtils::showcompare(mval, dval, "Enc and Dec");
  cout << endl << endl << endl;
  
  auto negct = cipher.negate();
  dval = scheme.decryptSingle(secretKey, negct);
  StringUtils::showcompare(mval, dval, "negate()");
  dval = scheme.decryptSingle(secretKey, cipher);
  StringUtils::showcompare(mval, dval, "same()");
    cout << endl << endl << endl;
  
  
  cipher.negateAndEqual();
  dval = scheme.decryptSingle(secretKey, cipher);
  StringUtils::showcompare(mval, dval, "negateAndEqual()");
  cipher.negateAndEqual();
    cout << endl << endl << endl;
  
  cipher = scheme.encrypt(mval, logp, logQ);
  cout << "cipher.logp = " << cipher.logp << endl;
  auto ctrs = cipher.reScaleBy(1);
  cout << "ctrs = cipher.reScaleBy(1);kjlgjhghjj" << endl;
  cout << "ctrs.logp = " << ctrs.logp << endl;
  dval = scheme.decryptSingle(secretKey, ctrs);
  StringUtils::showcompare(mval, dval, "reScaleBy(1)");
    cout << endl << endl << endl;
  
  
  cout << "cipher.logp = " << cipher.logp << endl;
  cipher.reScaleByAndEqual(1);
  cout << "cipher.reScaleByAndEqual(1);" << endl;
  cout << "cipher.logp = " << cipher.logp << endl;
  dval = scheme.decryptSingle(secretKey, cipher);
  StringUtils::showcompare(mval, dval, "reScaleByAndEqual(1)");
    cout << endl << endl << endl;
  
  
  cipher = scheme.encrypt(mval, logp, logQ);
  cout << "cipher.logp = " << cipher.logp << endl;
  ctrs = cipher.reScaleTo(30);
  cout << "ctrs = cipher.reScaleTo(30);llllllllllll" << endl;
  cout << "ctrs.logp = " << ctrs.logp << endl;
  dval = scheme.decryptSingle(secretKey, ctrs);
  StringUtils::showcompare(mval, dval, "reScaleTo(30)");  
  cout << endl << endl << endl;
  
  
  cipher = scheme.encrypt(mval, logp, logQ);
  cout << "cipher.logp = " << cipher.logp << endl;
  cipher.reScaleToAndEqual(30);
  cout << "cipher.reScaleToAndEqual(30);jjjjjjjjjj" << endl;
  cout << "cipher.logp = " << cipher.logp << endl;
  dval = scheme.decryptSingle(secretKey, cipher);
  StringUtils::showcompare(mval, dval, "reScaleToAndEqual(30);"); 
    cout << endl << endl << endl;
  
  
  cipher = scheme.encrypt(mval, logp, logQ);
  cout << "cipher.logq = " << cipher.logq << endl;
  ctrs = cipher.modDownBy(10);
  cout << "ctrs = cipher.modDownBy(10);" << endl;
  cout << "ctrs.logq = " << ctrs.logq << endl;
  dval = scheme.decryptSingle(secretKey, ctrs);
  StringUtils::showcompare(mval, dval, "modDownBy(10)");
    cout << endl << endl << endl;
  
  
  cout << "cipher.logq = " << cipher.logq << endl;
  cipher.modDownByAndEqual(80);
  cout << "cipher.modDownByAndEqual(80);" << endl;
  cout << "cipher.logq = " << cipher.logq << endl;
  dval = scheme.decryptSingle(secretKey, cipher);
  StringUtils::showcompare(mval, dval, "modDownByAndEqual(80)");
    cout << endl << endl << endl;
  
  
  cout << "cipher.logq = " << cipher.logq << endl;
  ctrs = cipher.modDownTo(300);
  cout << "ctrs = cipher.modDownTo(300);" << endl;
  cout << "ctrs.logq = " << ctrs.logq << endl;
  dval = scheme.decryptSingle(secretKey, ctrs);
  StringUtils::showcompare(mval, dval, "modDownTo(300)");
    cout << endl << endl << endl;
  
  
  cout << "cipher.logq = " << cipher.logq << endl;
  cipher.modDownToAndEqual(300);
  cout << "cipher.modDownToAndEqual(300);" << endl;
  cout << "cipher.logq = " << cipher.logq << endl;
  dval = scheme.decryptSingle(secretKey, cipher);
  StringUtils::showcompare(mval, dval, "modDownToAndEqual(300)");
    cout << endl << endl << endl;
  
  
  double mval1 = EvaluatorUtils::randomReal();
  Ciphertext cipher1 = scheme.encrypt(mval1, logp, logQ);
  double mval2 = EvaluatorUtils::randomReal();
  Ciphertext cipher2 = scheme.encrypt(mval2, logp, logQ);
  
  auto cipher3 = scheme.add(cipher1, cipher2);
  dval = scheme.decryptSingle(secretKey, cipher3);
  StringUtils::showcompare(mval1+mval2, dval, "add(cipher1, cipher2)");
  cout << endl << endl << endl;
  
  Ciphertext cipher4; cipher4.copy(cipher1);
  scheme.addAndEqual(cipher4, cipher2);
  dval = scheme.decryptSingle(secretKey, cipher4);
  StringUtils::showcompare(mval1+mval2, dval, "addAndEqual(cipher1, cipher2)");
  cout << endl << endl << endl;
  
  double cnst = EvaluatorUtils::randomReal();
  auto cipher5 = scheme.addConst(cipher1, cnst);
  dval = scheme.decryptSingle(secretKey, cipher5);
  StringUtils::showcompare(mval1+cnst, dval, "addConst(cipher1, cnst)");
  cout << endl << endl << endl; 
  
  Ciphertext cipher6; cipher6.copy(cipher1);
  scheme.addConstAndEqual(cipher6, cnst);
  dval = scheme.decryptSingle(secretKey, cipher6);
  StringUtils::showcompare(mval1+cnst, dval, "addConstAndEqual(cipher1, cnst)");
  cout << endl << endl << endl; 
  
  
  
  mval1 = EvaluatorUtils::randomReal();
  cipher1 = scheme.encrypt(mval1, logp, logQ);
  mval2 = EvaluatorUtils::randomReal();
  cipher2 = scheme.encrypt(mval2, logp, logQ);
  
  auto cipher7 = scheme.sub(cipher1, cipher2);
  dval = scheme.decryptSingle(secretKey, cipher7);
  StringUtils::showcompare(mval1-mval2, dval, "sub(cipher1, cipher2)");
  cout << endl << endl << endl;
  
  Ciphertext cipher8(cipher1), cipher9(cipher2);
  scheme.subAndEqual(cipher8, cipher9);
  dval = scheme.decryptSingle(secretKey, cipher8);
  StringUtils::showcompare(mval1-mval2, dval, "subAndEqual(cipher1, cipher2)");
  cout << endl << endl << endl;
  
  Ciphertext cipher10(cipher1), cipher11(cipher2);
  scheme.subAndEqual2(cipher10, cipher11);
  dval = scheme.decryptSingle(secretKey, cipher11);
  StringUtils::showcompare(mval1-mval2, dval, "subAndEqual2(cipher1, cipher2)");
  cout << endl << endl << endl; 
  
  cnst = EvaluatorUtils::randomReal();
  
  auto cipher12 = scheme.subConst(cipher1, cnst);
  dval = scheme.decryptSingle(secretKey, cipher12);
  StringUtils::showcompare(mval1-cnst, dval, "subConst");
  cout << endl << endl << endl; 
  
  Ciphertext cipher13(cipher1);
  scheme.subConstAndEqual(cipher13, cnst);
  dval = scheme.decryptSingle(secretKey, cipher13);
  StringUtils::showcompare(mval1-cnst, dval, "subConstAndEqual");
  cout << endl << endl << endl;
  
  
  mval1 = EvaluatorUtils::randomReal();
  cipher1 = scheme.encrypt(mval1, logp, logQ);
  mval2 = EvaluatorUtils::randomReal();
  cipher2 = scheme.encrypt(mval2, logp, logQ);
  
  auto cipher14 = scheme.mult(cipher1, cipher2);
  dval = scheme.decryptSingle(secretKey, cipher14);
  StringUtils::showcompare(mval1*mval2, dval, "mult(cipher1, cipher2)");
  cout << endl << endl << endl; 
  
  Ciphertext cipher15(cipher1);
  scheme.multAndEqual(cipher15, cipher2);
  dval = scheme.decryptSingle(secretKey, cipher15);
  StringUtils::showcompare(mval1*mval2, dval, "multandEqual(cipher1, cipher2)");
  cout << endl << endl << endl; 
  
        Ciphertext cipher16(cipher1);
  scheme.imultAndEqual(cipher16);
  scheme.imultAndEqual(cipher16);
  dval = scheme.decryptSingle(secretKey, cipher16);
  StringUtils::showcompare(-mval1, dval, "imultandEqual(cipher1) twice");
  cout << endl << endl << endl; 
  
  
  cnst = EvaluatorUtils::randomReal();
  auto cipher17 = scheme.multByConst(cipher1, cnst, 30);
  dval = scheme.decryptSingle(secretKey, cipher17);
  StringUtils::showcompare(cnst*mval1, dval, "multByConst(cipher1, cnst, 30)");
  cout << endl << endl << endl;
  
  Ciphertext cipher18(cipher1);
  scheme.multByConstAndEqual(cipher18, cnst, 30);
  dval = scheme.decryptSingle(secretKey, cipher18);
  StringUtils::showcompare(cnst*mval1, dval, "multByConstAndEqual(cipher1, cnst, 30)");
  cout << endl << endl << endl;
  
  ///////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////
    // 设置输出流
    std::cout << std::fixed; // 使用定点表示法
    std::cout << std::setprecision(3); // 设置小数点后精度为 3
  
  slots = 1<<logSlots;
  cout << endl<< endl<< endl<< "slots: " << slots << endl<< endl<< endl;
  auto mvec = EvaluatorUtils::randomRealArray(slots);


  cipher = scheme.encrypt(mvec, slots, logp, logQ);
  auto dvec = scheme.decrypt(secretKey, cipher);
  StringUtils::showcompare(mvec, dvec, slots, "val");

  
 cout << endl << "--------------- END ---------------" << endl;

  return 0;
}


int HE_SquareMatrixMult(long dim)  // dim = 4, 16, 64 
{
  
 cout << endl << "--------------- END ---------------" << endl;

  return 0;
}

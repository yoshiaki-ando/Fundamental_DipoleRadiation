/*
 * main.cpp
 *
 * 微小ダイポール波源が作る電界
 * （ダイポールを含む、ダイポールと垂直な平面内のみ計算）
 *
 *  Created on: 2023/06/07
 *      Author: ando
 *
 */
#include <iostream>
#include <cmath>
#include <complex>
#include <fstream>

#include "dipoleradiation.h"
#include "idl.h"

int main(void){
  std::complex <double> zj { 0.0, 1.0 };

  constexpr double DX { 1.0e0 }; /* FDTDに用いたセルサイズ */
  double r = std::sqrt( (25*DX)*(25*DX) + (25*DX)*(25*DX) ); /* ダイポールからの距離 */

  /* 出力する時間の調整 */
  constexpr int Nt { 600 };
  constexpr double Dt { 2.0*t_max / Nt };

  /* 逆フーリエ変換する角周波数の刻み */
  constexpr int Nomg { 200 };
  constexpr double Domega { omega_max / Nomg };

  std::ofstream ofs("Ez.dat");
  for(int n = 1; n < Nt; n++){
    double t = n*Dt;
    std::complex <double> Ezt { 0.0, 0.0 };

    /*
     * 逆フーリエ変換
     * Ez(t) = 1/(2π) * ∫ E(ω) exp(jωt) dω
     *
     */
    for(int i = -Nomg; i < Nomg; i++){
      double omega = (i+0.5) * Domega; /* ω=0は極限操作が必要なので避ける */

      Ezt += Etheta( omega, Idl(omega), r ) * std::exp( zj * omega * t );
    }

    /* Ez = - E_θ
     * E_θ(t) = 1/(2π) * Σ E_θ(i Δω) Δω
     */
    Ezt = -1.0 * Ezt * Domega / 2.0 / M_PI;

    ofs << t << " " << std::real(Ezt) << " " << std::imag(Ezt) << "\n";
  }
  ofs.close();


  return 0;
}

/*
 * Etheta.cpp
 *
 * 微小ダイポールの作る電界E_θ(ω)
 * θ = π/2 で固定
 *
 *  Created on: 2023/06/07
 *      Author: ando
 */
#include <cmath>
#include <complex>

#include <physical_constants.h>

#include "dipoleradiation.h"

std::complex <double> Etheta(
    const double omega,
    std::complex <double> Idl,
//    Current_f Idl,
    const double r){
  std::complex <double> E { 0.0, 0.0 };
  std::complex <double> zj { 0.0, 1.0 };

  /*
   * E_θ = j ω μ IΔl / (4π) * exp(-jkr) * { 1/r - j/(kr^2) - 1/(k^2r^3) ) }
   */

  const double k0 = omega / C0;
  E = zj * omega * MU0 * Idl / 4.0 / M_PI
      * std::exp(-1.0 * zj * k0 * r ) *
      ( 1.0/r - zj/(k0*r*r) - 1.0/(k0*k0 * r*r*r) );

  return E;
}

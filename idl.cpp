/*
 * idl.cpp
 *
 *  Created on: 2023/06/07
 *      Author: ando
 */
#include <cmath>
#include <complex>

#include <physical_constants.h>

#include "idl.h"

std::complex <double> Idl(double omega){
  std::complex <double> zj { 0.0, 1.0 }; /* 虚数単位 */

  /*
   *
   * Idl(ω) = -j √(2π) * ωσ^2 exp( - σ^2 ω^2 / 2 ) exp(-jωt0)
   *
   */

  return -1.0 * zj * std::sqrt(2.0*M_PI) * sig*sig * omega *
      std::exp(-sig*sig * omega*omega / 2.0) * std::exp(-zj * omega * t0);
}

#include "ne_ds.h"
#include "Solar_4a74f551_1_ds_sys_struct.h"
#include "Solar_4a74f551_1_ds_duf.h"
#include "Solar_4a74f551_1_ds.h"
#include "Solar_4a74f551_1_ds_externals.h"
#include "Solar_4a74f551_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T Solar_4a74f551_1_ds_duf ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t6 , NeDsMethodOutput * t7 ) { PmRealVector out ;
real_T U_idx_0 ; real_T intermediate_der17 ; int32_T M_idx_0 ; int32_T
M_idx_1 ; M_idx_0 = t6 -> mM . mX [ 0 ] ; M_idx_1 = t6 -> mM . mX [ 1 ] ;
U_idx_0 = t6 -> mU . mX [ 0 ] ; out = t7 -> mDUF ; U_idx_0 = U_idx_0 *
0.016666666666666718 * 1.602176487E-19 / 6.1746137514E-21 ;
intermediate_der17 = 0.43246334953252086 ; if ( U_idx_0 > 80.0 ) { U_idx_0 =
- ( intermediate_der17 * 3.48954275907586E-7 * 5.54062238439351E+34 ) ; }
else if ( M_idx_1 != 0 ) { U_idx_0 = - ( intermediate_der17 *
3.48954275907586E-7 * 4.9060947306492808E-35 ) ; } else { U_idx_0 = - (
pmf_exp ( U_idx_0 ) * intermediate_der17 * 3.48954275907586E-7 ) ; } if (
M_idx_0 != 0 ) { intermediate_der17 = - 0.0027266666666666667 ; } else {
intermediate_der17 = 0.0 ; } out . mX [ 0 ] = U_idx_0 ; out . mX [ 1 ] =
intermediate_der17 ; ( void ) sys ; ( void ) t7 ; return 0 ; }

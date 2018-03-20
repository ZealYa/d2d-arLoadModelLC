#ifndef _MY_testmodel1_D1E3B3D405CB60B382A20109046C7C6D
#define _MY_testmodel1_D1E3B3D405CB60B382A20109046C7C6D

#include <cvodes/cvodes.h>
#include <cvodes/cvodes_dense.h>
#include <cvodes/cvodes_sparse.h>
#include <nvector/nvector_serial.h>
#include <sundials/sundials_types.h>
#include <sundials/sundials_math.h>
#include <cvodes/cvodes_klu.h>
#include <sundials/sundials_sparse.h>
#include <udata.h>
#include <math.h>
#include <mex.h>
#include <arInputFunctionsC.h>



 void fu_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(void *user_data, double t);
 void fsu_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(void *user_data, double t);
 void fv_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(realtype t, N_Vector x, void *user_data);
 void dvdx_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(realtype t, N_Vector x, void *user_data);
 void dvdu_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(realtype t, N_Vector x, void *user_data);
 void dvdp_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(realtype t, N_Vector x, void *user_data);
 int fx_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(realtype t, N_Vector x, N_Vector xdot, void *user_data);
 void fxdouble_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(realtype t, N_Vector x, double *xdot_tmp, void *user_data);
 void fx0_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(N_Vector x0, void *user_data);
 int dfxdx_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(long int N, realtype t, N_Vector x,N_Vector fx, DlsMat J, void *user_data,N_Vector tmp1, N_Vector tmp2, N_Vector tmp3);
 int dfxdx_out_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(realtype t, N_Vector x, realtype* J, void *user_data); int dfxdx_sparse_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(realtype t, N_Vector x,N_Vector fx, SlsMat J, void *user_data,N_Vector tmp1, N_Vector tmp2, N_Vector tmp3);
 int fsx_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(int Ns, realtype t, N_Vector x, N_Vector xdot,int ip, N_Vector sx, N_Vector sxdot, void *user_data,N_Vector tmp1, N_Vector tmp2);
 int subfsx_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(int Ns, realtype t, N_Vector x, N_Vector xdot,int ip, N_Vector sx, N_Vector sxdot, void *user_data,N_Vector tmp1, N_Vector tmp2);
 void fsx0_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(int ip, N_Vector sx0, void *user_data);
 void subfsx0_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(int ip, N_Vector sx0, void *user_data);
 void csv_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(realtype t, N_Vector x, int ip, N_Vector sx, void *user_data);
 void dfxdp0_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(realtype t, N_Vector x, double *dfxdp0, void *user_data);

 void dfxdp_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(realtype t, N_Vector x, double *dfxdp, void *user_data);

 void fz_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(double t, int nt, int it, int nz, int nx, int nu, int iruns, double *z, double *p, double *u, double *x);
 void fsz_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(double t, int nt, int it, int np, double *sz, double *p, double *u, double *x, double *z, double *su, double *sx);

 void dfzdx_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(double t, int nt, int it, int nz, int nx, int nu, int iruns, double *dfzdxs, double *z, double *p, double *u, double *x);
#endif /* _MY_testmodel1_D1E3B3D405CB60B382A20109046C7C6D */




#include "testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3.h"
#include <cvodes/cvodes.h>
#include <cvodes/cvodes_dense.h>
#include <cvodes/cvodes_sparse.h>
#include <nvector/nvector_serial.h>
#include <sundials/sundials_types.h>
#include <sundials/sundials_math.h>
#include <sundials/sundials_sparse.h>
#include <cvodes/cvodes_klu.h>
#include <udata.h>
#include <math.h>
#include <mex.h>
#include <arInputFunctionsC.h>





 void fu_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(void *user_data, double t)
{
  UserData data = (UserData) user_data;
  double *p = data->p;
  data->u[0] = spline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0);

  return;
}


 void fsu_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(void *user_data, double t)
{
  UserData data = (UserData) user_data;
  double *p = data->p;
  data->su[6] = Dspline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0,1.0);
  data->su[7] = Dspline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0,2.0);
  data->su[8] = Dspline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0,3.0);
  data->su[9] = Dspline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0,4.0);
  data->su[10] = Dspline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0,5.0);

  return;
}


 void fv_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(realtype t, N_Vector x, void *user_data)
{
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *x_tmp = N_VGetArrayPointer(x);
  data->v[0] = p[2]*u[0]*x_tmp[0];
  data->v[1] = (p[3]*(x_tmp[1]*x_tmp[1]))/p[0];
  data->v[2] = p[4]*x_tmp[2];
  data->v[3] = p[5]*x_tmp[3];
  data->v[4] = p[5]*x_tmp[4];
  data->v[5] = p[1]*x_tmp[5];
  data->v[6] = p[1]*x_tmp[6];
  data->v[7] = p[5]*x_tmp[7];

  return;
}


 void dvdx_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(realtype t, N_Vector x, void *user_data)
{
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *x_tmp = N_VGetArrayPointer(x);
  data->dvdx[0] = p[2]*u[0];
  data->dvdx[9] = (p[3]*x_tmp[1]*2.0)/p[0];
  data->dvdx[18] = p[4];
  data->dvdx[27] = p[5];
  data->dvdx[36] = p[5];
  data->dvdx[45] = p[1];
  data->dvdx[54] = p[1];
  data->dvdx[63] = p[5];

  return;
}


 void dvdu_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(realtype t, N_Vector x, void *user_data)
{
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *x_tmp = N_VGetArrayPointer(x);
  data->dvdu[0] = p[2]*x_tmp[0];

  return;
}


 void dvdp_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(realtype t, N_Vector x, void *user_data)
{
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *x_tmp = N_VGetArrayPointer(x);
  data->dvdp[1] = -1.0/(p[0]*p[0])*p[3]*(x_tmp[1]*x_tmp[1]);
  data->dvdp[13] = x_tmp[5];
  data->dvdp[14] = x_tmp[6];
  data->dvdp[16] = u[0]*x_tmp[0];
  data->dvdp[25] = (x_tmp[1]*x_tmp[1])/p[0];
  data->dvdp[34] = x_tmp[2];
  data->dvdp[43] = x_tmp[3];
  data->dvdp[44] = x_tmp[4];
  data->dvdp[47] = x_tmp[7];

  return;
}


 int fx_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(realtype t, N_Vector x, N_Vector xdot, void *user_data)
{
  UserData data = (UserData) user_data;
  int is;
  double *qpositivex = data->qpositivex;
  double *p = data->p;
  double *u = data->u;
  double *v = data->v;
  double *x_tmp = N_VGetArrayPointer(x);
  double *xdot_tmp = N_VGetArrayPointer(xdot);
  fu_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(data, t);
  fv_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(t, x, data);
  xdot_tmp[0] = -v[0]+v[7]*3.214285714285714E-1;
  xdot_tmp[1] = v[0]-v[1]*2.0;
  xdot_tmp[2] = v[1]-v[2];
  xdot_tmp[3] = v[2]*3.111111111111111-v[3];
  xdot_tmp[4] = v[3]*2.0-v[4];
  xdot_tmp[5] = v[4]-v[5];
  xdot_tmp[6] = v[5]-v[6];
  xdot_tmp[7] = v[6]-v[7];
  for (is=0; is<8; is++) {
    if(mxIsNaN(xdot_tmp[is])) xdot_tmp[is] = 0.0;
    if(qpositivex[is]>0.5 && x_tmp[is]<0.0 && xdot_tmp[is]<0.0) xdot_tmp[is] = -xdot_tmp[is];
  }

  return(*(data->abort));
}


 void fxdouble_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(realtype t, N_Vector x, double *xdot_tmp, void *user_data)
{
  int is;
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *v = data->v;
  fu_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(data, t);
  fv_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(t, x, data);
  xdot_tmp[0] = -v[0]+v[7]*3.214285714285714E-1;
  xdot_tmp[1] = v[0]-v[1]*2.0;
  xdot_tmp[2] = v[1]-v[2];
  xdot_tmp[3] = v[2]*3.111111111111111-v[3];
  xdot_tmp[4] = v[3]*2.0-v[4];
  xdot_tmp[5] = v[4]-v[5];
  xdot_tmp[6] = v[5]-v[6];
  xdot_tmp[7] = v[6]-v[7];
  for (is=0; is<8; is++) {
    if(mxIsNaN(xdot_tmp[is])) xdot_tmp[is] = 0.0;
  }

  return;
}


 void fx0_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(N_Vector x0, void *user_data)
{
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *x0_tmp = N_VGetArrayPointer(x0);
  x0_tmp[0] = p[0];

  return;
}


 int dfxdx_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(long int N, realtype t, N_Vector x, 
  	N_Vector fx, DlsMat J, void *user_data, 
  	N_Vector tmp1, N_Vector tmp2, N_Vector tmp3)
{
  int is;
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *dvdx = data->dvdx;
  dvdx_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(t, x, data);
  for (is=0; is<64; is++) {
    J->data[is] = 0.0;
  }
  J->data[0] = -dvdx[0];
  J->data[1] = dvdx[0];
  J->data[9] = dvdx[9]*-2.0;
  J->data[10] = dvdx[9];
  J->data[18] = -dvdx[18];
  J->data[19] = dvdx[18]*3.111111111111111;
  J->data[27] = -dvdx[27];
  J->data[28] = dvdx[27]*2.0;
  J->data[36] = -dvdx[36];
  J->data[37] = dvdx[36];
  J->data[45] = -dvdx[45];
  J->data[46] = dvdx[45];
  J->data[54] = -dvdx[54];
  J->data[55] = dvdx[54];
  J->data[56] = dvdx[63]*3.214285714285714E-1;
  J->data[63] = -dvdx[63];
  for (is=0; is<64; is++) {
    if(mxIsNaN(J->data[is])) J->data[is] = 0.0;
  }

  return(0);
}


 int dfxdx_out_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(realtype t, N_Vector x, realtype* J, void *user_data) {
  int is;
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *dvdx = data->dvdx;
  dvdx_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(t, x, data);
  for (is=0; is<64; is++) {
    J[is] = 0.0;
  }
  J[0] = -dvdx[0];
  J[1] = dvdx[0];
  J[9] = dvdx[9]*-2.0;
  J[10] = dvdx[9];
  J[18] = -dvdx[18];
  J[19] = dvdx[18]*3.111111111111111;
  J[27] = -dvdx[27];
  J[28] = dvdx[27]*2.0;
  J[36] = -dvdx[36];
  J[37] = dvdx[36];
  J[45] = -dvdx[45];
  J[46] = dvdx[45];
  J[54] = -dvdx[54];
  J[55] = dvdx[54];
  J[56] = dvdx[63]*3.214285714285714E-1;
  J[63] = -dvdx[63];
  for (is=0; is<64; is++) {
    if(mxIsNaN(J[is])) J[is] = 0.0;
  }

  return(0);
}


 int dfxdx_sparse_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(realtype t, N_Vector x, 
  	N_Vector fx, SlsMat J, void *user_data, 
  	N_Vector tmp1, N_Vector tmp2, N_Vector tmp3)
{
  int is;
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *dvdx = data->dvdx;
  dvdx_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(t, x, data);
  SlsSetToZero(J);
    J->rowvals[0] = 0;
    J->rowvals[1] = 1;
    J->rowvals[2] = 1;
    J->rowvals[3] = 2;
    J->rowvals[4] = 2;
    J->rowvals[5] = 3;
    J->rowvals[6] = 3;
    J->rowvals[7] = 4;
    J->rowvals[8] = 4;
    J->rowvals[9] = 5;
    J->rowvals[10] = 5;
    J->rowvals[11] = 6;
    J->rowvals[12] = 6;
    J->rowvals[13] = 7;
    J->rowvals[14] = 0;
    J->rowvals[15] = 7;

    J->colptrs[0] = 0;
    J->colptrs[1] = 2;
    J->colptrs[2] = 4;
    J->colptrs[3] = 6;
    J->colptrs[4] = 8;
    J->colptrs[5] = 10;
    J->colptrs[6] = 12;
    J->colptrs[7] = 14;
    J->colptrs[8] = 16;

  J->data[0] = -dvdx[0];
  J->data[1] = dvdx[0];
  J->data[2] = dvdx[9]*-2.0;
  J->data[3] = dvdx[9];
  J->data[4] = -dvdx[18];
  J->data[5] = dvdx[18]*3.111111111111111;
  J->data[6] = -dvdx[27];
  J->data[7] = dvdx[27]*2.0;
  J->data[8] = -dvdx[36];
  J->data[9] = dvdx[36];
  J->data[10] = -dvdx[45];
  J->data[11] = dvdx[45];
  J->data[12] = -dvdx[54];
  J->data[13] = dvdx[54];
  J->data[14] = dvdx[63]*3.214285714285714E-1;
  J->data[15] = -dvdx[63];
  for (is=0; is<16; is++) {
    if(mxIsNaN(J->data[is])) J->data[is] = RCONST(0.0);
  }

  return(0);
}


 int fsx_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(int Ns, realtype t, N_Vector x, N_Vector xdot, 
  	int ip, N_Vector sx, N_Vector sxdot, void *user_data, 
  	N_Vector tmp1, N_Vector tmp2)
{
  int is;
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *sv = data->sv;
  double *dvdx = data->dvdx;
  double *dvdu = data->dvdu;
  double *dvdp = data->dvdp;
  double *x_tmp = N_VGetArrayPointer(x);
  double *su = data->su;
  double *sx_tmp = N_VGetArrayPointer(sx);
  double *sxdot_tmp = N_VGetArrayPointer(sxdot);
  fsu_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(data, t);
  dvdx_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(t, x, data);
  dvdu_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(t, x, data);
  dvdp_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(t, x, data);
  for (is=0; is<8; is++) {
    sv[is] = 0.0;
  }
  sv[0] = dvdu[0]*su[(ip*1)+0]+dvdx[0]*sx_tmp[0];
  sv[1] = dvdx[9]*sx_tmp[1];
  sv[2] = dvdx[18]*sx_tmp[2];
  sv[3] = dvdx[27]*sx_tmp[3];
  sv[4] = dvdx[36]*sx_tmp[4];
  sv[5] = dvdx[45]*sx_tmp[5];
  sv[6] = dvdx[54]*sx_tmp[6];
  sv[7] = dvdx[63]*sx_tmp[7];
  switch (ip) {
    case 0: {
      sv[1] += dvdp[1];
    } break;
    case 1: {
      sv[5] += dvdp[13];
      sv[6] += dvdp[14];
    } break;
    case 2: {
      sv[0] += dvdp[16];
    } break;
    case 3: {
      sv[1] += dvdp[25];
    } break;
    case 4: {
      sv[2] += dvdp[34];
    } break;
    case 5: {
      sv[3] += dvdp[43];
      sv[4] += dvdp[44];
      sv[7] += dvdp[47];
    } break;
    case 6: {

    } break;
    case 7: {

    } break;
    case 8: {

    } break;
    case 9: {

    } break;
    case 10: {

    } break;
  }
  sxdot_tmp[0] = -sv[0]+sv[7]*3.214285714285714E-1;
  sxdot_tmp[1] = sv[0]-sv[1]*2.0;
  sxdot_tmp[2] = sv[1]-sv[2];
  sxdot_tmp[3] = sv[2]*3.111111111111111-sv[3];
  sxdot_tmp[4] = sv[3]*2.0-sv[4];
  sxdot_tmp[5] = sv[4]-sv[5];
  sxdot_tmp[6] = sv[5]-sv[6];
  sxdot_tmp[7] = sv[6]-sv[7];
  for (is=0; is<8; is++) {
    if(mxIsNaN(sxdot_tmp[is])) sxdot_tmp[is] = 0.0;
  }

  return(0);
}


 int subfsx_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(int Ns, realtype t, N_Vector x, N_Vector xdot, 
  	int ip, N_Vector sx, N_Vector sxdot, void *user_data, 
  	N_Vector tmp1, N_Vector tmp2)
 {
   UserData data = (UserData) user_data;
   return fsx_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(Ns, t, x, xdot, data->sensIndices[ip], sx, sxdot, user_data, tmp1, tmp2);
 };

 void csv_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(realtype t, N_Vector x, int ip, N_Vector sx, void *user_data)
{
  int is;
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *sv = data->sv;
  double *dvdx = data->dvdx;
  double *dvdu = data->dvdu;
  double *dvdp = data->dvdp;
  double *x_tmp = N_VGetArrayPointer(x);
  double *su = data->su;
  double *sx_tmp = N_VGetArrayPointer(sx);
  for (is=0; is<8; is++) {
    sv[is] = 0.0;
  }
  sv[0] = dvdu[0]*su[(ip*1)+0]+dvdx[0]*sx_tmp[0];
  sv[1] = dvdx[9]*sx_tmp[1];
  sv[2] = dvdx[18]*sx_tmp[2];
  sv[3] = dvdx[27]*sx_tmp[3];
  sv[4] = dvdx[36]*sx_tmp[4];
  sv[5] = dvdx[45]*sx_tmp[5];
  sv[6] = dvdx[54]*sx_tmp[6];
  sv[7] = dvdx[63]*sx_tmp[7];
  switch (ip) {
    case 0: {
      sv[1] += dvdp[1];
    } break;
    case 1: {
      sv[5] += dvdp[13];
      sv[6] += dvdp[14];
    } break;
    case 2: {
      sv[0] += dvdp[16];
    } break;
    case 3: {
      sv[1] += dvdp[25];
    } break;
    case 4: {
      sv[2] += dvdp[34];
    } break;
    case 5: {
      sv[3] += dvdp[43];
      sv[4] += dvdp[44];
      sv[7] += dvdp[47];
    } break;
    case 6: {

    } break;
    case 7: {

    } break;
    case 8: {

    } break;
    case 9: {

    } break;
    case 10: {

    } break;
  }

  return;
}


 void fsx0_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(int ip, N_Vector sx0, void *user_data)
{
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *sx0_tmp = N_VGetArrayPointer(sx0);
  switch (ip) {
    case 0: {
      sx0_tmp[0] = 1.0;
    } break;
  }

  return;
}


 void subfsx0_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(int ip, N_Vector sx0, void *user_data)
 {
   UserData data = (UserData) user_data;
   fsx0_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(data->sensIndices[ip], sx0, user_data);
 };

 void dfxdp0_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(realtype t, N_Vector x, double *dfxdp0, void *user_data)
{
  int is;
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *dvdp = data->dvdp;
  double *dvdx = data->dvdx;
  double *dvdu = data->dvdu;
  double *x_tmp = N_VGetArrayPointer(x);
  dfxdp0[0] = -dvdx[0];
  dfxdp0[1] = dvdp[1]*-2.0+dvdx[0];
  dfxdp0[2] = dvdp[1];
  dfxdp0[13] = -dvdp[13];
  dfxdp0[14] = dvdp[13]-dvdp[14];
  dfxdp0[15] = dvdp[14];
  dfxdp0[16] = -dvdp[16];
  dfxdp0[17] = dvdp[16];
  dfxdp0[25] = dvdp[25]*-2.0;
  dfxdp0[26] = dvdp[25];
  dfxdp0[34] = -dvdp[34];
  dfxdp0[35] = dvdp[34]*3.111111111111111;
  dfxdp0[40] = dvdp[47]*3.214285714285714E-1;
  dfxdp0[43] = -dvdp[43];
  dfxdp0[44] = dvdp[43]*2.0-dvdp[44];
  dfxdp0[45] = dvdp[44];
  dfxdp0[47] = -dvdp[47];
  dfxdp0[48] = -dvdu[0]*Dspline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0,1.0);
  dfxdp0[49] = dvdu[0]*Dspline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0,1.0);
  dfxdp0[56] = -dvdu[0]*Dspline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0,2.0);
  dfxdp0[57] = dvdu[0]*Dspline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0,2.0);
  dfxdp0[64] = -dvdu[0]*Dspline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0,3.0);
  dfxdp0[65] = dvdu[0]*Dspline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0,3.0);
  dfxdp0[72] = -dvdu[0]*Dspline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0,4.0);
  dfxdp0[73] = dvdu[0]*Dspline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0,4.0);
  dfxdp0[80] = -dvdu[0]*Dspline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0,5.0);
  dfxdp0[81] = dvdu[0]*Dspline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0,5.0);
  for (is=0; is<88; is++) {
    if(mxIsNaN(dfxdp0[is])) dfxdp0[is] = 0.0;
  }

  return;
}


 void dfxdp_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(realtype t, N_Vector x, double *dfxdp, void *user_data)
{
  int is;
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *dvdp = data->dvdp;
  double *dvdx = data->dvdx;
  double *dvdu = data->dvdu;
  double *x_tmp = N_VGetArrayPointer(x);
  dfxdp[1] = dvdp[1]*-2.0;
  dfxdp[2] = dvdp[1];
  dfxdp[13] = -dvdp[13];
  dfxdp[14] = dvdp[13]-dvdp[14];
  dfxdp[15] = dvdp[14];
  dfxdp[16] = -dvdp[16];
  dfxdp[17] = dvdp[16];
  dfxdp[25] = dvdp[25]*-2.0;
  dfxdp[26] = dvdp[25];
  dfxdp[34] = -dvdp[34];
  dfxdp[35] = dvdp[34]*3.111111111111111;
  dfxdp[40] = dvdp[47]*3.214285714285714E-1;
  dfxdp[43] = -dvdp[43];
  dfxdp[44] = dvdp[43]*2.0-dvdp[44];
  dfxdp[45] = dvdp[44];
  dfxdp[47] = -dvdp[47];
  dfxdp[48] = -dvdu[0]*Dspline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0,1.0);
  dfxdp[49] = dvdu[0]*Dspline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0,1.0);
  dfxdp[56] = -dvdu[0]*Dspline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0,2.0);
  dfxdp[57] = dvdu[0]*Dspline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0,2.0);
  dfxdp[64] = -dvdu[0]*Dspline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0,3.0);
  dfxdp[65] = dvdu[0]*Dspline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0,3.0);
  dfxdp[72] = -dvdu[0]*Dspline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0,4.0);
  dfxdp[73] = dvdu[0]*Dspline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0,4.0);
  dfxdp[80] = -dvdu[0]*Dspline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0,5.0);
  dfxdp[81] = dvdu[0]*Dspline_pos5(t,0.0,p[6],5.0,p[7],1.0E1,p[8],2.0E1,p[9],6.0E1,p[10],0.0,0.0,5.0);
  for (is=0; is<88; is++) {
    if(mxIsNaN(dfxdp[is])) dfxdp[is] = 0.0;
  }

  return;
}


 void fz_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(double t, int nt, int it, int nz, int nx, int nu, int iruns, double *z, double *p, double *u, double *x){
  z[nz*nt*iruns+it+nt*0] = x[nx*nt*iruns+it+nt*0]+x[nx*nt*iruns+it+nt*1]+x[nx*nt*iruns+it+nt*2]*2.0;
  z[nz*nt*iruns+it+nt*1] = x[nx*nt*iruns+it+nt*1]+x[nx*nt*iruns+it+nt*2]*2.0;

  return;
}


 void fsz_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(double t, int nt, int it, int np, double *sz, double *p, double *u, double *x, double *z, double *su, double *sx){
  int jp;
  for (jp=0; jp<np; jp++) {
      sz[it + nt*2*jp + nt*0] = sx[it + nt*8*jp + nt*0]+sx[it + nt*8*jp + nt*1]+sx[it + nt*8*jp + nt*2]*2.0;
      sz[it + nt*2*jp + nt*1] = sx[it + nt*8*jp + nt*1]+sx[it + nt*8*jp + nt*2]*2.0;
  };



  return;
}


 void dfzdx_testmodel_comp_BDB78A19B65A0938C69C4E7EB287DCB3(double t, int nt, int it, int nz, int nx, int nu, int iruns, double *dfzdxs, double *z, double *p, double *u, double *x){
      dfzdxs[nx*nt*iruns+it+nt*0] = 1.0;
      dfzdxs[nx*nt*iruns+it+nt*2] = 1.0;
      dfzdxs[nx*nt*iruns+it+nt*3] = 1.0;
      dfzdxs[nx*nt*iruns+it+nt*4] = 2.0;
      dfzdxs[nx*nt*iruns+it+nt*5] = 2.0;


  return;
}



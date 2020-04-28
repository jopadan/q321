#pragma once
// auto-generated, do not modify (see cook_shader.js)

// trim_newlines       : true
// consistent_floats   : false
// rename_ids          : true
// rename_vec_fields   : true
// rename_globals      : true
// min_macro_savings   : 8

// src/demo/data/shaders/fragment_shaders.glsl: 43988 => 19765 (44.9%)
const char g_fragment_shaders[] =
"#define A vec2\n"
"#define B float\n"
"#define C vec3\n"
"#define D return\n"
"#define I mix\n"
"#define L fract\n"
"#define M vec4\n"
"#define P abs\n"
"#define Q length\n"
"#define S max\n"
"#define T min\n"
"#define V rgb\n"
"#define W UV\n"
"#define Z Time\n"
"#define aa FCol\n"
"#define ac void\n"
"#define ag int\n"
"#define aj Texture0\n"
"#define an texture\n"
"#define ar for\n"
"#define at dot\n"
"#define ay floor\n"
"#define a5 sqrt\n"
"#define aI normalize\n"
"uniform M Z,Cam;uniform sampler2D aj,Texture1;in C Pos,Nor,Ref;in A W,LUV;in M Clr;out M aa;\n"
"#define aW(x)((x)*(x)*(3.-2.*(x)))\n"
"#define O(x)(x)*(x)\n"
"#define b4(x)at(x,x)\n"
"#define ao(x)clamp(x,0.,1.)\n"
"#define J(r,g,b)(C(r,g,b)/255.)\n"
"B aB=3.1415927,b5=2.*aB,aK=1.618034;A b6(B i){B G=1.324718;D L(.5+i/A(G,G*G));}B aC(B i){D L(.5+i*aK);}B b7(B f){B i=ay(f);D I(aC(i),aC(i+1.),aW(f-i));}B aL(A v){D T(v.r,v.g);}B aL(C v){D T(v.r,T(v.g,v.b));}B aL(M v){D T(T(v.r,v.g),T(v.b,v.a));}B a4(A v){D S(v.r,v.g);}B a4(C v){D S(v.r,S(v.g,v.b));}B a4(M v){D S(S(v.r,v.g),S(v.b,v.a));}B aM(A v){D v.r+v.g;}B aX(B a,B b){D P(a)<P(b)?a:b;}B aY(B x,B s){D P(x)-s;}A b8(A v){B l=at(v,v);D l>0.?v/a5(l):v;}B F(B b9,B bA,B x){D 1.-ao(P(x-b9)/bA);}B E(B aZ,B bB,B x){D ao((x-aZ)/(bB-aZ));}B F(B a,B b,B c,B x){D T(E(a,b,x),E(c,b,x));}A ad(B x){D A(sin(x),cos(x));}mat2 a2(B x){A v=ad(radians(x));D mat2(v.g,v.r,-v.r,v.g);}A ai(A z,B p,B s){D z+sin(z.gr*aB*p)*s;}A ai(A z,B t,B p,B s){D z+sin(z.gr*aB*p+t)*s;}B aQ(B v,B m){D m-P(v-m);}A aQ(A v,B m){v.r=aQ(v.r,m);D v;}A ba(A z,A s){z.r+=ay(z.g*s.g)*(.5/s.r);D L(z)*s;}C aD(A z,B r){D C(z-=clamp(z,r,1.-r),Q(z)/r);}C aD(A z,A s,B r){s=s.gr/aL(s);z*=s;D C(z-=clamp(z,A(r),s-r),Q(z)/r);}B H(A p){C q=L(p.rgr*.09153);q+=at(q,q.gbr+19.19);D L((q.r+q.g)*q.b);}B H(B p){p=L(p*.1031);p*=p+33.33;p*=p+p;D L(p);}C bR(B p){C ak=L(C(p)*C(.1031,.1030,.0973));ak+=at(ak,ak.gbr+33.33);D L((ak.rrg+ak.gbb)*ak.bgr);}A bC(A p){C ak=L(C(p.rgr)*C(.1031,.1030,.0973));ak+=at(ak,ak.gbr+33.33);D L((ak.rr+ak.gb)*ak.bg);}M bD(B p){M al=L(M(p)*M(.1031,.1030,.0973,.1099));al+=at(al,al.abrg+33.33);D L((al.rrgb+al.gbba)*al.bgar);}M bD(A p){M al=L(M(p.rgrg)*M(.1031,.1030,.0973,.1099));al+=at(al,al.abrg+33.33);D L((al.rrgb+al.gbba)*al.bgar);}B ae(B x,B p){D H(mod(x,p));}B N(B x){B i;D I(H(i=ay(x)),H(i+1.),aW(x-i));}B X(B x,B p){B i;D I(ae(i=ay(x),p),ae(i+1.,p),x-i);}B ae(A p,A s){D H(mod(p,s));}B X(A p,A s){p*=s;A i=ay(p);p-=i;p*=p*(3.-2.*p);B bE=ae(i+A(0,0),s);B bF=ae(i+A(0,1),s);B bG=ae(i+A(1,1),s);B bH=ae(i+A(1,0),s);D I(I(bE,bH,p.r),I(bF,bG,p.r),p.g);}B K(A p,A az,B aE,B aF,ag aR){B aG=X(p,az),a3=1.,tw=1.;ar(ag i=0;i<aR;++i){p=L(p+aK);az*=aF;a3*=aE;aG+=X(p,az)*a3;tw+=a3;}D aG/tw;}B K(A p,A az,B aE,B aF){D K(p,az,aE,aF,4);}\n"
"#define a6(v)F(.5,.5,v)\n"
"B bc(A p,A az,B aE,B aF,ag aR){B aG=a6(X(p,az)),a3=1.,tw=1.;ar(ag i=0;i<aR;++i){p=L(p+aK);az*=aF;a3*=aE;aG+=a6(X(p,az))*a3;tw+=a3;}D aG/tw;}A aN(A p,A a,A b){A ab=b-a,ap=p-a;B t=ao(at(ap,ab)/at(ab,ab));D ab*t+a;}B Y(A p,A b){A d=P(p)-b;D T(S(d.r,d.g),0.)+Q(S(d,0.));}B aH(A p,A b){D a4(P(p)-b);}B au(A p,B r){D Q(p)-r;}B aS(A p,A r){D au(p/r,1.)/T(r.r,r.g);}B aT(B a,B b){D S(a,-b);}B bd(B a,B b,B k){B h=ao(.5+0.5*(b-a)/k);D I(b,a,h)-k*h*(1.-h);}A be(B x){A d=A(dFdx(x),dFdy(x));D d/S(Q(d),1e-8);}B U(B s,B d){D ao(1.-s/d);}B U(B s){D ao(1.-s/fwidth(s));}\n"
"#define aU(bI,z,bJ){A p[3];B r[3];p[0]=z;p[1]=z+dFdx(z);p[2]=z+dFdy(z);ar(ag i=0;i<3;++i)r[i]=bJ;bI=C(b8(A(r[1],r[2])-r[0]),r[0]);}\n"
"M bf(A z,B s){D M(z/=s,a5(ao(1.-b4(z))),Q(z)-1.);}B bK(C n){B l=aM(n.gb)*.7;D pow(ao(l),4.)+l;}B bh(A z,B s){z/=s;z.g+=.06;z.r*=2.;D E(.3,.0,Q(z));}C aO(C c,A z,B s){M b=bf(z,s);c*=1.+bK(b.V)*U(b.a)*.5;c*=1.-O(bh(z,20.*s))*(1.-U(b.a))*.3;D c;}C bi(A p,B ad,B bL){C e=C(-1,0,1),r=C(1e5);A am=ay(p*ad),bS=e.gg;p-=(am+.5)/ad;B af=.5*ae(am+e.gg,A(ad));B a7=.5*ae(am+e.rg,A(ad));B a8=.5*ae(am+e.gb,A(ad));B a9=.5*ae(am+e.bg,A(ad));B aA=.5*ae(am+e.gr,A(ad));B bj=.5*ae(am+e.rb,A(ad));B bk=.5*ae(am+e.bb,A(ad));B bl=.5*ae(am+e.br,A(ad));B bm=.5*ae(am+e.rr,A(ad));A[4]av,l;if(mod((am.r+am.g),2.)<.5){l[0]=1.+A(a8-a7,bj-af);l[1]=1.+A(-a8+a9,bk-af);l[2]=1.+A(-aA+a9,-bl+af);l[3]=1.+A(aA-a7,-bm+af);av[0]=A(a8,af)+l[0]*A(-.5,.5);av[1]=A(a8,af)+l[1]*A(.5,.5);av[2]=A(aA,af)+l[2]*A(.5,-.5);av[3]=A(aA,af)+l[3]*A(-.5,-.5);}else{l[0]=1.+A(-bj+af,a8-a7);l[1]=1.+A(bk-af,a8-a9);l[2]=1.+A(bl-af,-aA+a9);l[3]=1.+A(-bm+af,-aA+a7);av[0]=A(af,a7)+l[0]*A(-.5,.5);av[1]=A(af,a9)+l[1]*A(.5,.5);av[2]=A(af,a9)+l[2]*A(.5,-.5);av[3]=A(af,a7)+l[3]*A(-.5,-.5);}ar(ag i=0;i<4;i++){l[i]/=ad;B bx=aH(p-av[i]/ad,l[i]/2.-bL/ad);if(bx<r.r)r=C(bx,am+av[i]);}D r;}A bn(A p,A bo){p*=bo;A n=ay(p),f=p-n,bp,g,o,r;B bq=8.0,d;ar(ag i=0;i<9;++i){g=A(i%3-1,i/3-1);o=bC(mod(n+g,bo));r=g+o-f;d=aM(P(r));if(d<bq){bq=d;bp=r;}}D bp;}B bs(C p){p=aI(p);C a=mod(degrees(atan(p,p.gbr)),360.);D X(a.r/8.,45.)*E(.9,.0,P(p.b))+X(a.g/8.,45.)*E(.7,.0,P(p.r));}A bt(C p,ag ax){D(ax==0)?p.gb:(ax==1)?p.rb:p.rg;}ag bu(C n){n=P(n)+C(.01,.02,.03);B m=a4(n);D(m==n.r)?0:(m==n.g)?1:2;}C bM(C c){C V=ao(P(mod(c.r*6.+C(0,4,2),6.)-3.)-1.);V*=V*(3.-2.*V);D c.b*I(C(1.),V,c.g);}C aw(){C d=Cam.V-Pos;B b=K(d.rg/256.*a2(Cam.a),A(3),.7,3.,4),l=1.-E(14.,-6.,Q(d.rg)-b*8.)*E(128.,48.,d.b)*step(.1,Nor.b);D an(Texture1,LUV).V*3.*l;}\n"
"#define R(a0)C a0(A);ac a0(){aa=M(a0(W),1);}C a0(A z)\n"
"#define as(a0)M a0(A);ac a0(){aa=a0(W);}M a0(A z)\n"
"R(cmet52){B b=K(z,A(5),.9,3.,4);C c=I(J(48,41,33),J(103,101,104),b);D c;}R(ptrshn){B b=K(z,A(3),.9,3.,4);C c=I(J(49,45,43),J(81,75,78),b*b);D c;}R(dmnd2c){B b=K(z,A(7),.9,3.);z.r*=-1.5;z.g+=z.r*.5;z.r=1.-z.r+z.g;z=L(z*28.);B f=ao(1.-Q(.1-z));f*=E(.6,.2,Q(.6-z));f*=E(.6,.8,Q(.1-z));f*=E(.2,.6,b)*2.+1.;B l=1.-E(.2,b+2.,a4(P(z-.5)));D C((f+1.)*I(.21,.29,b*b)*l);}R(dmnd2cow){B b=K(z,A(7),.9,3.);C c=dmnd2c(z);B r=Q(z-.5);c=I(c,c*J(70,61,53),E(.5,.2,r+b*b*b));D c;}B bw(A z,B s){B d=1e6,i=0.;ar(;i<5.;++i){A p=A(0,-s)*a2(i*72.);d=T(d,Q(z-aN(z,p,p*a2(144.))));}D d;}as(dmnd2pnt){C c=dmnd2cow(z);z=L(z)-.5;B b=K(z,A(3),.9,3.),d=T(P(Q(z)-.4),bw(z,.35));D M(c,U(d-.02+b*.02,.01));}ac dmnd2pnt_m(){M c=an(aj,W);aa=M(c.V*aw()+J(111,55,0)*c.a*(sin(Z.r*aB)*.5+.5),1);}R(dmnd2cjp){B b=K(z,A(7),.9,3.,4);C c=dmnd2c(z);B r=Q(z-.5);B m=E(.46,.45,r);B l=1.5-1.5*E(.0,.3,r*r);l=I(l,2.5,F(.42,.07,r));l=I(l,3.5,F(.44,.05,r));l=I(l,2.6,F(.36,.03,r));B n=.3+.2*E(.35,.30,r);l*=1.-n*E(.3,.7,b);l*=1.-.3*O(E(.13,.05,r));l=I(l,2.5,E(.04,.01,r));l-=l*F(.03,.01,r)*.7;c=I(c,J(68,66,54)*l,m);c*=1.-O(F(.34,.02,r));c*=1.-O(F(.46,.03,r));c*=1.-F(.41,.03,r)*.7;D c;}A bN(A z,B s){D A(1.-Q(z)/s,U(Q(z)-s));}as(lpdmnd){B b=K(z,A(5),.9,3.),t,o,k,r;C c=dmnd2c(z);A u,v;u.r=P(z.r-.5);u.g=T(z.g,.4);r=Q(u-A(0,.4))-(.18-.06*E(.4,1.,z.g));k=.25-.15*E(.9,.96,z.g)+.03*O(E(.82,.86,z.g))+.07*E(.8,.2,z.g)+.07*O(E(.35,.22,z.g))-.07*E(.22,.0,z.g);o=Y(z-A(.5,.5),A(k,.46));o=S(o,-Y(u,A(.15,.03))+.06);c=I(c,C(.6,.55,.55)-z.g*.3+b*.2,U(o));c*=1.-.7*F(.0,.013,o);c*=1.-(r/.5-.1)*U(o);t=S(r,z.g-.96);o=P(t-.02)-.03;o=S(o,z.g-1.+u.r*.5);o=S(o,z.g-.96);c=I(c,C(1,1,.9)-z.g*.55,F(-.01,.01,o));c=I(c,C(.2*b+.1),U(t,.01));c*=1.-.2*F(.0,.05,t)*U(o);v=bN(u=z-A(.5,.4),.02);c*=1.+J(111,80,70)*F(.03,.01,Q(u));c*=1.-.5*F(.02,.01,Q(u));c=I(c,J(111,66,44)*(v.r*1.5+.2),v.g);D M(c,U(t-.03,.02));}ac lpdmnd_m(){M c=an(aj,W);A z=L(W);z.r=P(.5-z.r);B t=L(-Z.r),r=Q(z-A(0,.4)),l=t*pow(S(0.,1.-r),4.)*c.a;if(t>.75)l+=E(.03,.01,P(L(z.g+z.r*.5+t*2.)-.45))*E(.1,.08,z.r);aa=M(c.V*aw()+J(180,150,5)*l,1);}R(mtlfw10){B b=K(z,A(5),.9,3.,4);C c=I(J(44,14,16),J(93,63,63),b*b);D c;}C by(A z){B e=3e-3,a=0.;A g=A(6),r=bn(z,g);ar(ag i=0;i<9;++i)a+=aM(P(bn(A(i%3-1,i/3-1)*e+z,g)-r));D C(z+r.rg/g,a);}R(mtlfw15){B b=K(z,A(3),.9,3.,4);C c=I(J(80,70,72),J(128,120,120),b*b);C v=by(z);c*=I(.95,1.1,X(v.rg,A(6)));c=I(c,J(168,128,120),E(.5,1.,v.b)*b*.7);D c;}as(mtlfw15ow){B b=K(z,A(3),.9,3.,4);C c=I(J(80,70,72),J(128,120,120),b*b);C v=by(z);B m=E(.5,1.,v.b);B r=E(.4,.2,Q(.5-L(v.rg)));c*=I(.95,1.1,X(v.rg,A(6)))-2.*r*b*b;c=I(c,J(168,128,120),m*b*.7);D M(c,m*r);}ac mtlfw15ow_m(){M c=an(aj,W);aa=M(c.V*aw()+F(.5,.125,L(W.g*.5+Z.r*.5))*c.a*.3,1);}R(mtlfb3){B b=K(z,A(5),.9,3.,4);C pt=bi(z,8.,.31);C c=I(J(66,58,55),J(118,107,105),b);B l=1.-.5*E(.034,.036,pt.r);l=I(l,1.4,F(.033,.004,pt.r));D c*l;}B bO(A z){B b=X(z,A(64)),f=0.,d=1e6;ar(;f<11.;++f)d=bd(d,P(Q(.5-P(z-b6(f)))-I(.36,.29,aC(f+.7)))-I(.015,.03,b),.01);D d*1e2;}C bz(A z){C s,p;ar(ag i=0;i<3;++i){p=C(z,0);p[i]+=1e-4;s[i]=bO(p.rg);}D C(aI(s.rg-s.b),s.b);}R(mtlt12f){B b=K(z,A(5),.9,3.,4),l;C c=I(J(51,46,43),J(165,147,143),b*b),d=bz(z);l=1.-.5*(d.g-d.r)*F(.5,3.,d.b)*E(1.,.0,d.b);D c*l*.8;}R(mtlt6f){B b=K(z,A(3),1.1,3.,4),l;C c=I(J(51,46,43),J(165,147,143),b*b),d=bz(z);l=1.-.5*(d.g-d.r)*F(.5,3.,d.b)*E(1.,.0,d.b);D c*l;}R(mtlbk03){B b=K(z,A(5),.9,3.,4),l=.18*(.7+b*b);C g;z=ai(z,13.,.007);aU(g,z,O(E(.3+b*.2,.9,K(p[i],A(23),.5,2.,4))));D C(l*(1.-g.g*g.b));}R(giron01e){B b=K(z,A(5),.9,3.,4),l=.18*(.7+b*b);C c=I(J(77,55,53),J(62,48,48),X(z,A(128,13)))*(.7+b*b),g;z=ai(z,13.,.007);aU(g,z,O(E(.6+b*.3,.95,X(p[i],A(47,23)))));c*=E(1.3,.9,g.b);D C(c*(1.+g.g*g.b));}B b0(A z,A s){z.g=S(z.g,0.);D aS(z,s);}C b1(A z){D C(.06+.1*H(z*133.7));}C aP(C c,C b,A z,B h,B s){B y=(z.g-h)/s,p=1.-y*y;c*=1.-F(-1.,1.,y);if(p>0.)c=b*(p*(.8+.2*F(.5,.25,L(z.r/s))))*(.7+O(F(.2,.7,y)));D c;}C b1(A z,B n){D C(n*n*.4);}R(giron01nt3){z.r*=.5;B b=K(z*A(2,1),A(3,5),.9,3.,4),n=.8+.8*b*b,t=z.g+.2*T(.5,F(.5,.375,L(z.r*4.))),bP=b0(z-A(.25,.62),A(3,2)/32.),aJ=b0(z-A(.25,.55),A(3,2)/48.),r;C c=I(J(66,50,51),J(111,66,44),a5(F(.31,.01,z.g))),ah;A p=z,q;p.r=L(p.r*4.);if(z.g>.3)c=aO(c,A(4.*P(p.r-.5)-1.6,L(z.g*16.)-.5),.07);r=P(p.r-.5);c*=1.-.3*E(.31,.32,z.g)*E(.87,.86,z.g)*(E(.035,.03,.5-r)+F(.48,.01,r)-F(.46,.02,r));c=I(c*n,b1(z,b),S(E(.31,.3,z.g),U(aJ)));c*=E(1.5,.7,z.g);if(z.g<.306)c*=1.-F(.3,.05,z.g)*U(-aJ+10.,20.);c*=1.-F(.316,.004,z.g)*U(-aJ);if(z.g<.1)c*=.0;q=z;q.g+=F(.1,.01,mod(q.r,.33))/2e2;c=aP(c,2.*b*J(93,84,79),z,.185,.015);c=aP(c,2.*b*J(138,77,48),z,.13,.025);c=aP(c,2.*b*J(112,71,51),z,.09,.015);c=aP(c,2.*b*J(138,77,48),q,.05,.015);p.r=P(L(z.r*6.-.5)-.5)/6.;c*=1.+.5*E(.04,.03,p.r)*F(.18,.03,p.g);r=aH(p-A(0,.12),A(.03,.01));r=aT(r,aH(p-A(0,.11),A(.01)));c*=1.-O(F(.0,.04,r));c=I(c,J(166,99,77)*2.*b*(.75+.5*O(F(.125,.01,z.g))),U(r));q=p;q.g-=.07;r=au(q,.03);c*=1.-O(F(.0,.07,r));c=I(c,J(127,83,72)*b*2.*E(.01,-.005,r),E(.005,.0,r));q.g-=.004;r=au(q,.015);c*=O(E(-.01,.01,r));q.g+=.013;r=au(q,.05);c+=J(67,38,30)*4.*a5(b)*O(F(-.02,.015,r)*F(.023,.02,z.g));r=aT(bP,aJ);r=aT(r,(z.g-.3)*3e2);c*=1.-.5*F(-2.,17.,aJ)*E(.26,.3,z.g);ah=J(67,39,17)*n;ah=I(ah,C(n*.2),F(0.,4.,r)*b);ah*=1.-.4*pow(F(.0,3.,r),4.);ah+=(ah+.6)*a5(b)*O(F(-6.,8.,r)*F(.66,.04,z.g))*U(r);if(z.g<.55)ah=aO(ah,A(24.*P(z.r-.25)-1.85,L(z.g*24.+.5)-.5),.15);c=I(c,giron01e(z),E(.85,.9,t)+step(z.g,1./256.));c*=1.+F(.88,.015,t)-O(F(.87,.03,t));D I(c,ah,E(1.,.1,r));}C bQ(C c,A z,ag w,ag h){B b=K(z,A(w,h),.5,2.,2);c*=.9-.3*E(.15,.1,P(b-.5));D I(c,J(145,140,137),F(.5,.1,b));}R(gmtlbg6){z=ai(z,9.,.005);ag i=0,l[]=ag[](13,43,17,47,23,59,27,63);B b=K(z,A(19),.7,2.,4);C c=J(40,50,60)*(.5+b);ar(;i<8;i+=2)c=bQ(c,z,l[i],l[i+1]);D c;}R(glrgbk3b){B b=K(ai(z,5.,.02),A(5),1.,3.,5),n=X(z,A(13));A p=ba(z,A(8)),q=L(p),a1=p-q;C c=J(91,61,42)*(.8+.8*b*b);c=I(c,J(70,30,15)*(.8+.8*b*b),aD(q,.1).b*.3);c*=1.-O(aD(q,.01+b*.05).b)*n*b*b;c*=1.+F(.4,.3,aD(q,.01+b*.07).b)*a5(b)*.3;c*=.9+.2*H(a1)*(1.-aD(q,.1).b);c*=.9+.4*pow(bc(z-H(a1/8.),A(5),.6,2.,4),4.);D c;}R(gblks15){B b=K(z,A(5),.9,3.,4),t=bc(ai(z,4.,.01),A(7),.5,3.,5),n=X(ai(z,4.,.05),A(9)),a1,e;C pt=bi(z,4.,.1+n*t*.05),c;A d=be(pt.r);a1=H(L(pt.gb));c=J(74,65,62)*(.8+.8*b*b);c+=F(.6,.3,n)*E(.3,.9,b*t)*.2;c*=1.-F(.5,.4,n)*E(.5,.7,t)*.1;c=I(c,J(86,74,78),F(.5,.1,b)*F(.7,.3,a1)*.7);c=I(c,J(105,90,70),F(.3,.1,t)*F(.3,.3,a1)*.3);e=F(.015,.005+.015*n,pt.r)+F(.4,.1,n*t)*.4;c*=1.-b*E(.015,.05,pt.r)*.7;c*=1.+e*b*(d.g-.5)*.7;c*=.9+.2*a1;c*=.9+.2*a6(X(z-pt.gr,A(5)));D c;}as(gcntr2trn){B b=K(z-=.5,A(5),.9,3.,4),t=.75+b*b,n=X(ai(z,7.,.02),A(17)),r=Q(z),k=r>.4?38.:r>.32?28.:16.,a=L(atan(z.g,z.r)/b5),i=ay(a*k),aq=P(P(r-.41-n*.002)*1e2-6.),m=E(1.5,1.4,aq),aV[]=B[](1.,3.,-.145,-1.,2.,.166),d,b2,s;A p=z;C c=J(78,68,63);c*=1.+.5*O(F(.49,.005+.015*n*n+.015*b,r));c=I(c,J(83,52,47)*(.6+.4*n*n),m)*t;c*=1.-.5*F(1.5,.5,aq)+b*F(1.,.5+.5*n,P(r-.418)*1e2-5.)-b*F(.5,.08,L(a*k+.5))*m+b*F(.5,.1,L(a*k+.55))*m;m=E(.34,.33,r);c=I(c*(1.-.5*m),J(83,52,47)*t,n*b*m);c=I(c,J(112,86,31)*t,m*O(F(.1,.15,.45,b)));c=I(c,J(77,66,77)*t,m*E(.5,.8,b)*.5);c*=1.-.7*F(.27,.34,.35,r);aq=r+n*.004;m=r>.21&&r<.31?1.:0.;c*=1.-F(.325,.005,aq)-F(.31,.005,aq)-b*O(F(.29,.005,aq))-b*O(F(.23,.01,aq))-.5*O(F(.21,.02,aq))+O(F(.3,.01,aq))*b+O(F(.22,.01,aq))*b-b*F(.5,.07,L(a*k+.5))*m;if(r<.23)i+=37.;if(r<.31)i+=73.;if(r<.31)i+=91.;c*=I(1.,.9+.2*aC(i),m);m=E(.01,.0,P(r-.411)-.039);i=ay(a*72.);p*=a2(i*5.);s=0.;d=1e6;ag j=0;ar(;j<6;j+=3){d=aX(d,b2=at(p,aI(A(aV[j],aV[j+1])))+aV[j+2]);s+=s+B(b2>0.);}if(s==3.)++i;else i+=66.*s;i=aC(i);c=I(c,t*J(90,80,75),m);c=I(c,t*J(127,111,88),i*b*m);c*=I(1.,.7+.6*H(i),m);c*=1.-m*O(F(.0,.006,d))*b+m*O(F(.006,.006,P(d)))*b*.5;i=ay(a*4.);p=P(z*a2(i*90.+45.));d=1e6;ar(j=0;j<2;++j,p=P(p*a2(45.)))d=aX(d,P(Q(p-A(0,.12))-.16));m=E(.21,.2,r);aq=aY(aY(d,.012),.001);c*=1.-E(.21,.2,r)*U(.012-d)+b*m*O(F(.005,.005,d))-.5*m*O(U(aq-.001,.001));D M(c,(1.-E(.21,.15,r)*U(.028-d,.02))*E(.07,.087,r));}as(gcntr2trn_m){A p=L(W)-.5;B b=K(a2(Z.r*333.)*p/(.8+.2*sin(Z.r*61.)),A(53),.7,2.,4);M c=M(1.-b*C(0,.3,1),1),ah=an(aj,(a2(Z.r*30.)*p/(.8+.2*sin(Z.r*1.26)))+.5);c.V=I(c.V,ah.V,ah.a);ah=an(aj,W);c.V=I(c.V,ah.V,ah.a)*aw();D c;}R(gtprst3){B b=K(z,A(13),.9,3.,4),n=K(z,A(7),.9,3.,4);C c=I(J(60,50,50),J(87,47,37),O(E(.7,.25,n)))*(.7+.8*b*b),g;z=ai(z,31.,.003);aU(g,z,a5(E(.0,.9,X(p[i],A(93)))));c*=1.-(g.g+.4)*O(b*g.b)*g.b;D c;}R(skcpthrt){B b=K(ai(z,7.,.01),A(9),.7,2.,4);C c=J(127,70,55)*(.85+.3*b);c*=1.-.2*O(E(.2,.05,b*b));c*=1.+.3*E(.6,.9,b);c*=1.-.2*O(F(.6,.3,K(ai(z,5.,.03),A(6),.6,2.,4)));D c;}R(gskull4){B b=K(z,A(13),.9,3.,4);C c=J(60,50,46)*(.875+b*b);D c;}R(gmtlspsld){B b=K(z,A(7),.9,3.,4),n=K(z,A(5),.9,3.,4);C c=I(J(103,56,53),J(73,58,71),smoothstep(.4,.5,n))*(.75+b*b);D c;}R(gmtlsp4b){B b=K(z,A(13),.9,3.,4),n=X(ai(z,5.,.05),A(9)),d=a6(L(z.r*4.)),m=E(.1,.15,d)*E(1.,.99,z.g);C c=J(51,44,44);c=I(c,J(73,55,52),E(.2,.2,b)*n*m);c=I(c,J(69,60,66),E(.7,.1,b)*b*m);c=I(c,J(99,77,77),E(.1,.5,n)*n*m*b*b*.3);c*=.6+.3*b+.3*b*b;c*=1.+.9*O(F(.21,.02+.1*n,d+b*.05))*m*b;c*=1.-O(E(.49,.5,P(z.g-.5)));c*=1.-E(.05,.2,d)*E(.16,.1,d);c*=1.+F(.99,.007,z.g);D aO(c,A(d-.4,L(z.g*8.)-.5),.07);}C b3(A z,B s){B b=K(z,A(3,1.+s+s),.7,2.,4),d=a6(z.r),m;z.g*=2.;C c=I(J(71,60,58),J(110,88,77),E(.1,.05,d))*(.7+.6*b);c*=1.-E(.05,.0,z.r)*(1.-b*b);c*=1.+.5*F(.05,.02,z.r);A p=A(d-.35,L(z.g*s)-.5);M k=bf(p,.11);m=U(k.a);c*=1.-.7*bh(p,1.1)*(1.-m);c=I(c,(k.g>.0?J(128,105,88):J(200,111,66)*E(-.2,.7,k.b))*(.4+2.*b*pow(ao(aM(k.gb*.7)),4.))*(1.-.6*F(-.1,.4,k.g)),m);D c;}R(gspbdrbb){D b3(z,4.);}R(gkarntwr4a){D gspbdrbb(z.gr);}R(gkarntwrst){D b3(z,1.);}R(gxstrtop4){B b=K(z,A(40,5),.9,3.,4);C c=J(110,110,98)*(.8+.8*b*b);if(z.g<1./4.)c*=.5;c*=1.-.4*E(.4,.0,b)+.5*E(.02,.0,z.g)+.2*F(.24,.01,z.g);D c;}R(gwdclg1a){A p=z,q;p.g*=22.;q=L(p);B b=K(z,A(3,23),1.,2.,6),n=K(z,A(3,33),.7,3.,4),a1=H(p.g-q.g);C c=J(92,67,53)*(.8+.8*b*b);c*=1.-O(E(.1,.0,T(q.g,1.-q.g)))*b;c*=1.-.2*smoothstep(.3,.7,n);c*=.8+.3*b*a1;D c;}R(gwdclg1bd){B b=K(z,A(13),.9,3.,4),x=z.r*16./3.;C c=gwdclg1a(z)*E(.15,.21,z.r);if(x<1.)c=J(59,48,49)*(.7+.6*b);c*=1.+.5*F(.05,.05,a6(x));D aO(c,A(P(z.r-3./32.)-.07,mod(z.g,.1)-.05),.004);}R(gsltrfc){A p=ba(z,A(6,4)),q=L(p),u=q;B b=K(ai(z-=.5,5.,.03),A(13),.9,2.,3),n=X(z,A(73,7)),t=(.75+b*b)*(.8+.4*b7(z.r*93.)),r;C c=C(.25*t);u.g+=u.g*2.-.01-.03*n;r=Q(u-=clamp(u,A(.49,.5),A(.51,3)));c*=1.-.7*b*O(E(.07,.03,P(r-.5)))+.5*b*F(.35,.1,r)*O(E(.2,.1,q.g))-.3*O(E(.8,1.,q.g))-.3*(E(.3,.1,q.g))*E(.4,.6,r)+.2*O(E(.5,.1,q.g))*E(.45,.4,r);D c;}R(cable){B b=K(z,A(5),.9,3.,4),h=L(z.g*10.);C c=I(J(53,48,42),J(38,38,36),b);c*=.6+b*.8;c*=1.-.5*O(F(.5,.5,h));c*=1.+.5*O(F(.25,.25,h));c*=1.+.5*O(F(.65,.35,h));D c;}R(bmtsprt){B b=K(z,A(7,3),.9,3.,4),h=z.g+b*.04,l=1.-.15;C c=I(J(59,48,40),J(110,108,102),b*b);l=I(l,.5,F(.34,.05,z.g));l=I(l,.5,E(.08,.05,P(z.g-.7)));l=I(l,.3,F(.7,.03,z.g));l=I(l,1.5,F(.01,.03,z.g));l=I(l,2.2,F(.89,.1,h));l=I(l,1.6,E(.07,.04,P(z.g-.44)));l=I(l,2.5,F(.5,.04,h));l=I(l,1.7,F(.18,.04,h));D c*l;}R(brdr11b){B b=K(z,A(5,3),.9,3.,4);C c=I(J(74,66,55),J(99,90,78),b*b);z.r*=2.;A p=aN(z,A(.5,.625),A(1.5,.625));B d=Q(p-z),m=E(.22,.20,d),l=1.-.15*m;l=I(l,.5,E(.7,.9,z.g)*m);l=I(l,1.-be(d).g*.5,F(.22,.04,d));l=I(l,.6,O(F(.19,.05,d)));l=I(l,.5,E(.05,0.,z.g));l=I(l,.5,F(.26,.05,z.g));l=I(l,1.7,E(.93,1.,z.g));l=I(l,1.7,F(.23,.04,z.g));D c*l;}as(blt414k){B b=K(z,A(1,5),.4,3.,4);C c=I(J(56,49,43),J(142,136,136),b);z=.5-P(z-.5);z.g*=4.;B a=F(.0,.1,Q(z-aN(z,A(.41,.5),A(.42,3.5)))),d=aL(z),l=1.-.7*S(0.,1.-d/.15);l*=1.-.8*E(.24,.31,T(d,z.g-.1));c+=J(80,80,20)*a;D M(c*I(l,2.7,a),a);}as(light5){B b=K(z,A(1,5),.4,3.,4);C c=I(J(56,49,43),J(142,136,136),b);z=.5-P(z-.5);z.g*=8.;B d=Q(z-aN(z,A(.27,.3),A(.27,7.7))),a=F(.0,.17,d),l=1.-.5*F(.17,.07,d);c+=J(80,80,20)*a;D M(c*I(l,2.7,a),a);}as(lt2){A p=P(z-.5);B b=K(z,A(1),.4,3.,4),r=Q(p),a=E(.37,.33,r)*(.5+2.*b),l=1.+.0*E(.08,.03,P(r-.41));C c=I(J(56,49,43),J(142,136,136),b);l=I(l,7.,E(.44,.1*b,r));l*=1.-.5*O(F(.46,.04,r));l*=1.-.4*O(F(.36,.04,r));D M(c*l,a);}as(gpntgmlt1k){B b=K(z,A(5),.9,3.,4),d=bd(bw(z-=.5,.35),P(au(z,.4)),.02),a=pow(U(d-.02,.15),8.),o=T(S(Y(z,A(.46)),-au(z,.51)),P(au(z,.44)));C c=J(76,62,47)*(.8+.8*b*b);c*=1.+(b+.5)*U(P(o)-.01,.01);c*=1.-E(.1,.05,d)*U(au(z,.4));D M(c+1.*C(1,1,.3)*a,a);}as(icon){z.g-=.57;z.r=P(z.r-.48);B d=aS(z,A(.31,.12))/50.;d=S(d,-aS(z-A(0,.01),A(.28,.07))/120.);d=S(d,-Y(z-A(.0,.1),A(.22,.12)));d=S(d,-Y(z-A(.0,.1),A(.09,.31)));d=T(d,aH(z-A(.0,-.09),A(F(-.09,.32,z.g)*.04,.32)));d=T(d,aH(z-A(.11,-.21),A(F(-.07,.3,z.g)*.03,.15)));z.g+=.07;B b=Q(z)-.47,m=U(b);C c=1.-C(.7,1,1)*U(S(.007-d,b+.04));D M(c*m,m);}as(q3bnr){z*=A(256,64);z.g+=2.;B d=au(z-A(81,30),11.);d=S(d,z.r-80.);d=S(d,-au(z-A(84,26),9.));d=T(d,Y(z-A(73,37),A(4,9))-4.);d=S(d,-Y(z-A(73,37),A(0,7))+1.);d=T(d,Y(z-A(91.5,47),A(4,19))-4.);d=S(d,-Y(z-A(91.5,47),A(0,17.5))+1.);d=T(d,Y(aQ(z,111.)-A(105.+E(23.,50.,z.g)*3.,43),A(3.5,19)));d=T(d,Y(z-A(111,32),A(4,3)));d=T(d,Y(z-A(126,37),A(3,13)));d=T(d,Y(z-A(125.5+E(23.,50.,z.g)*10.,44),A(3.5,6)));d=T(d,Y(z-A(136.5-E(23.,50.,z.g)*9.,32),A(3.5,8)));d=T(d,Y(z-A(148.5,37),A(7,13)));d=S(d,-Y(z-A(155,33),A(6,3)));d=S(d,-Y(z-A(155,43),A(6,2)));d=T(d,Y(z-A(168,37),A(3.5,13)));d=T(d,Y(z-A(178.,37),A(3.5,13)));d=T(d,Y(z-A(188,37),A(3.5,13)));d=S(d,z.g-50.);D M(U(d,.8),0,0,H(z*511.));}ac q3bnr_m(){C c=an(aj,W*2.).V*step(.5,L(Z.r*.5));c=I(c*aw(),C(.5,0,0),F(L(Z.r*2.),1./64.,L(W.g)));aa=M(c+bs(Ref)*.25+an(aj,W+H(Z.rr)).a*.1,1);}ac beam(){A z=L(bt(Pos.V,bu(Nor))/128.);z.r+=Z.r/33.;B b=K(z,A(7),.9,2.),f=L(Pos.b/128.-.375);aa=M(2.*J(95,85,80)*f*f*f*f*I(1.,b,.5),0.);}ac flame(){A z=L(W),p=z;p.g+=p.g-Z.r;z.r+=sin(p.g*7.)*.2*z.g;B n=K(p+sin(p.gr*aB*9.+A(0,Z.r*9.))*.015+X(p,A(5))*.1,A(13),.4,3.,4),b=Y(z-A(.5,.25),A(.05*O(E(.4,.2,z.g)),.1)),m=O(U(b+n*.25,.35));aa=E(.0,.4,m)*M(7,.5,.2,0);}ac Generic(){B l=at(Nor,aI(C(2,0,8)));l=l*.4+.7;A z=bt(Pos,bu(Nor));C c=C(.5);c*=bM(C(L(aK*Z.a+.25),1.,1.));aa=M(c*l,1);}ac fixture(){M c=an(aj,W);aa=M(c.V*I(aw(),C(1),c.a),1);}ac dmnd2cjp_m(){M c=an(aj,W);B r=Q(L(W)-.5);B s=I(.4,8.,L(Z.r*1.5));aa=M(c.V*aw()+J(240,130,5)*F(.1,.05,r/s)*E(.37,.32,r),1);}ac Lmapped(){C c=an(aj,W).V;aa=M(c*aw(),1);}ac shiny(){M c=an(aj,W);c.V*=1.+c.a*bs(Ref);aa=M(c.V*aw(),1);}ac timhel(){C d=aI(Pos-Cam.V);d.b=d.b*4.+2.;A z=aI(d).rg*2.;B b=E(.2,1.,K(z-Z.r*A(.1,.2),A(5),.5,2.,6));z.g*=1.5;B s=E(.3,1.,K(z-Z.r*A(.1,.18),A(5),.6,2.,6));aa=M(C(b,0,0)+J(80,30,8)*s*s*2.,1);}ac lava(){A z=ai(W/8.,Z.r*.5,2.,.05);B b=K(z,A(7),.9,2.,4);C c=J(91,22,14)*(.2+1.6*b);c=I(c,J(144,44,0),F(.6,.2,K(z,A(3),.7,3.,4)));c=I(c,J(244,144,66)*b*2.,O(F(.55,.25,K(z,A(11),.5,2.,4))));aa=M(c*ao(a4(aw())),1);}ac lavaf(){lava();}ac Loading(){aa=an(aj,(.5+W*127.)/128.,2.5);aa.V*=.7+.3*X(W,.5/fwidth(W));}ac UI(){aa=an(aj,W)*Clr;}";

// src/demo/data/shaders/vertex_shaders.glsl: 2378 => 1502 (63.2%)
const char g_vertex_shaders[] =
"#define c void\n"
"#define e location\n"
"#define f gl_Position\n"
"uniform mat4 MVP;uniform vec4 Time,Cam;layout(e=0)in vec4 P;layout(e=1)in vec4 T;layout(e=2)in vec3 N;layout(e=3)in vec4 C;out vec3 Pos,Nor,Ref;out vec2 UV,LUV;out vec4 Clr;c Generic(){f=MVP*P;Pos=P.rgb;Nor=N;UV=T.rg;LUV=T.ba;Ref=normalize(reflect((P-Cam).rgb,N));}c d(){f=P;UV=P.rg*.5+.5;}c UI(){f=vec4(2.*P.r-1.,1.-2.*P.g,1,1);UV=T.rg;Clr=C;}c cmet52(){d();}c dmnd2c(){d();}c dmnd2cow(){d();}c dmnd2cjp(){d();}c dmnd2pnt(){d();}c lpdmnd(){d();}c ptrshn(){d();}c mtlfw10(){d();}c mtlfw15(){d();}c mtlfw15ow(){d();}c mtlfb3(){d();}c mtlt12f(){d();}c mtlt6f(){d();}c mtlbk03(){d();}c gmtlbg6(){d();}c glrgbk3b(){d();}c gblks15(){d();}c gtprst3(){d();}c skcpthrt(){d();}c gskull4(){d();}c gcntr2trn(){d();}c gmtlspsld(){d();}c gmtlsp4b(){d();}c gspbdrbb(){d();}c gkarntwr4a(){d();}c gkarntwrst(){d();}c giron01e(){d();}c giron01nt3(){d();}c gxstrtop4(){d();}c gwdclg1a(){d();}c gwdclg1bd(){d();}c gsltrfc(){d();}c bmtsprt(){d();}c cable(){d();}c brdr11b(){d();}c blt414k(){d();}c light5(){d();}c lt2(){d();}c gpntgmlt1k(){d();}c icon(){d();}c q3bnr(){d();}c Loading(){d();}c Lmapped(){Generic();}c mtlfw15ow_m(){Generic();}c dmnd2cjp_m(){Generic();}c dmnd2pnt_m(){Generic();}c lpdmnd_m(){Generic();}c fixture(){Generic();}c beam(){Generic();}c flame(){Generic();}c q3bnr_m(){Generic();}c shiny(){Generic();}c gcntr2trn_m(){Generic();}c timhel(){Generic();}c lavaf(){Generic();}c lava(){Generic();f+=MVP[2]*sin(Time.r*.5+dot(P.rgb/1e2,vec3(1)))*4.;}";

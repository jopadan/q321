#pragma once
// auto-generated, do not modify (see cook_shader.js)

// trim_newlines       : true
// consistent_floats   : false
// rename_ids          : true
// rename_vec_fields   : true
// rename_globals      : true
// min_macro_savings   : 8

// src/demo/data/shaders/fragment_shaders.glsl: 48524 => 21618 (44.6%)
const char g_fragment_shaders[] =
"#define A vec2\n"
"#define B float\n"
"#define C vec3\n"
"#define E return\n"
"#define I mix\n"
"#define M fract\n"
"#define O abs\n"
"#define P vec4\n"
"#define R length\n"
"#define S max\n"
"#define U min\n"
"#define V rgb\n"
"#define W UV\n"
"#define X int\n"
"#define aa Time\n"
"#define ac FCol\n"
"#define ad void\n"
"#define aj Texture0\n"
"#define am for\n"
"#define aq texture\n"
"#define au dot\n"
"#define ay floor\n"
"#define a3 sqrt\n"
"#define aJ normalize\n"
"uniform P aa,Cam;uniform sampler2D aj,Texture1;in C Pos,Nor,Ref;in A W,LUV;in P Clr;out P ac;\n"
"#define aX(x)((x)*(x)*(3.-2.*(x)))\n"
"#define L(x)(x)*(x)\n"
"#define b5(x)au(x,x)\n"
"#define ar(x)clamp(x,0.,1.)\n"
"#define J(r,g,b)(C(r,g,b)/255.)\n"
"B aB=3.1415927,b6=2.*aB,aL=1.618034;A b7(B i){B G=1.324718;E M(.5+i/A(G,G*G));}B aC(B i){E M(.5+i*aL);}B b8(B f){B i=ay(f);E I(aC(i),aC(i+1.),aX(f-i));}B aM(A v){E U(v.r,v.g);}B aM(C v){E U(v.r,U(v.g,v.b));}B aM(P v){E U(U(v.r,v.g),U(v.b,v.a));}B a6(A v){E S(v.r,v.g);}B a6(C v){E S(v.r,S(v.g,v.b));}B a6(P v){E S(S(v.r,v.g),S(v.b,v.a));}B aN(A v){E v.r+v.g;}B aY(B a,B b){E O(a)<O(b)?a:b;}B aZ(B x,B s){E O(x)-s;}B aQ(B x,B s){E sign(x)*S(0.,O(x)-s);}A b9(A v){B l=au(v,v);E l>0.?v/a3(l):v;}B D(B bA,B bB,B x){E 1.-ar(O(x-bA)/bB);}B F(B ba,B bC,B x){E ar((x-ba)/(bC-ba));}B D(B a,B b,B c,B x){E U(F(a,b,x),F(c,b,x));}A ae(B x){E A(sin(x),cos(x));}mat2 a2(B x){A v=ae(radians(x));E mat2(v.g,v.r,-v.r,v.g);}A ah(A z,B p,B s){E z+sin(z.gr*aB*p)*s;}A ah(A z,B t,B p,B s){E z+sin(z.gr*aB*p+t)*s;}B aR(B v,B m){E m-O(v-m);}A aR(A v,B m){v.r=aR(v.r,m);E v;}A bc(A z,A s){z.r+=ay(z.g*s.g)*(.5/s.r);E M(z)*s;}C aD(A z,B r){E C(z-=clamp(z,r,1.-r),R(z)/r);}C aD(A z,A s,B r){s=s.gr/aM(s);z*=s;E C(z-=clamp(z,A(r),s-r),R(z)/r);}B H(A p){C q=M(p.rgr*.09153);q+=au(q,q.gbr+19.19);E M((q.r+q.g)*q.b);}B H(B p){p=M(p*.1031);p*=p+33.33;p*=p+p;E M(p);}C bU(B p){C ak=M(C(p)*C(.1031,.1030,.0973));ak+=au(ak,ak.gbr+33.33);E M((ak.rrg+ak.gbb)*ak.bgr);}A bD(A p){C ak=M(C(p.rgr)*C(.1031,.1030,.0973));ak+=au(ak,ak.gbr+33.33);E M((ak.rr+ak.gb)*ak.bg);}P bE(B p){P al=M(P(p)*P(.1031,.1030,.0973,.1099));al+=au(al,al.abrg+33.33);E M((al.rrgb+al.gbba)*al.bgar);}P bE(A p){P al=M(P(p.rgrg)*P(.1031,.1030,.0973,.1099));al+=au(al,al.abrg+33.33);E M((al.rrgb+al.gbba)*al.bgar);}B af(B x,B p){E H(mod(x,p));}B N(B x){B i;E I(H(i=ay(x)),H(i+1.),aX(x-i));}B Y(B x,B p){B i;E I(af(i=ay(x),p),af(i+1.,p),x-i);}B af(A p,A s){E H(mod(p,s));}B Y(A p,A s){p*=s;A i=ay(p);p-=i;p*=p*(3.-2.*p);B bF=af(i+A(0,0),s);B bG=af(i+A(0,1),s);B bH=af(i+A(1,1),s);B bI=af(i+A(1,0),s);E I(I(bF,bI,p.r),I(bG,bH,p.r),p.g);}B K(A p,A az,B aE,B aF,X aS){B aG=Y(p,az),a4=1.,tw=1.;am(X i=0;i<aS;++i){p=M(p+aL);az*=aF;a4*=aE;aG+=Y(p,az)*a4;tw+=a4;}E aG/tw;}B K(A p,A az,B aE,B aF){E K(p,az,aE,aF,4);}\n"
"#define a5(v)D(.5,.5,v)\n"
"B bd(A p,A az,B aE,B aF,X aS){B aG=a5(Y(p,az)),a4=1.,tw=1.;am(X i=0;i<aS;++i){p=M(p+aL);az*=aF;a4*=aE;aG+=a5(Y(p,az))*a4;tw+=a4;}E aG/tw;}A aO(A p,A a,A b){A ab=b-a,ap=p-a;B t=ar(au(ap,ab)/au(ab,ab));E ab*t+a;}B Z(A p,A b){A d=O(p)-b;E U(S(d.r,d.g),0.)+R(S(d,0.));}B aH(A p,A b){E a6(O(p)-b);}B an(A p,B r){E R(p)-r;}B aT(A p,A r){E an(p/r,1.)/U(r.r,r.g);}B aU(B a,B b){E S(a,-b);}B be(B a,B b,B k){B h=ar(.5+0.5*(b-a)/k);E I(b,a,h)-k*h*(1.-h);}A bf(B x){A d=A(dFdx(x),dFdy(x));E d/S(R(d),1e-8);}B T(B s,B d){E ar(1.-s/d);}B T(B s){E ar(1.-s/fwidth(s));}\n"
"#define aV(bJ,z,bK){A p[3];B r[3];p[0]=z;p[1]=z+dFdx(z);p[2]=z+dFdy(z);am(X i=0;i<3;++i)r[i]=bK;bJ=C(b9(A(r[1],r[2])-r[0]),r[0]);}\n"
"P bh(A z,B s){E P(z/=s,a3(ar(1.-b5(z))),R(z)-1.);}B bL(C n){B l=aN(n.gb)*.7;E pow(ar(l),4.)+l;}B bi(A z,B s){z/=s;z.g+=.06;z.r*=2.;E F(.3,.0,R(z));}C aI(C c,A z,B s){P b=bh(z,s);c*=1.+bL(b.V)*T(b.a)*.5;c*=1.-L(bi(z,20.*s))*(1.-T(b.a))*.3;E c;}C bj(A p,B ae,B bM){C e=C(-1,0,1),r=C(1e5);A ao=ay(p*ae),bV=e.gg;p-=(ao+.5)/ae;B ag=.5*af(ao+e.gg,A(ae));B a7=.5*af(ao+e.rg,A(ae));B a8=.5*af(ao+e.gb,A(ae));B a9=.5*af(ao+e.bg,A(ae));B aA=.5*af(ao+e.gr,A(ae));B bk=.5*af(ao+e.rb,A(ae));B bl=.5*af(ao+e.bb,A(ae));B bm=.5*af(ao+e.br,A(ae));B bn=.5*af(ao+e.rr,A(ae));A[4]av,l;if(mod((ao.r+ao.g),2.)<.5){l[0]=1.+A(a8-a7,bk-ag);l[1]=1.+A(-a8+a9,bl-ag);l[2]=1.+A(-aA+a9,-bm+ag);l[3]=1.+A(aA-a7,-bn+ag);av[0]=A(a8,ag)+l[0]*A(-.5,.5);av[1]=A(a8,ag)+l[1]*A(.5,.5);av[2]=A(aA,ag)+l[2]*A(.5,-.5);av[3]=A(aA,ag)+l[3]*A(-.5,-.5);}else{l[0]=1.+A(-bk+ag,a8-a7);l[1]=1.+A(bl-ag,a8-a9);l[2]=1.+A(bm-ag,-aA+a9);l[3]=1.+A(-bn+ag,-aA+a7);av[0]=A(ag,a7)+l[0]*A(-.5,.5);av[1]=A(ag,a9)+l[1]*A(.5,.5);av[2]=A(ag,a9)+l[2]*A(.5,-.5);av[3]=A(ag,a7)+l[3]*A(-.5,-.5);}am(X i=0;i<4;i++){l[i]/=ae;B bx=aH(p-av[i]/ae,l[i]/2.-bM/ae);if(bx<r.r)r=C(bx,ao+av[i]);}E r;}A bo(A p,A bp){p*=bp;A n=ay(p),f=p-n,bq,g,o,r;B bs=8.0,d;am(X i=0;i<9;++i){g=A(i%3-1,i/3-1);o=bD(mod(n+g,bp));r=g+o-f;d=aN(O(r));if(d<bs){bs=d;bq=r;}}E bq;}B bt(C p){p=aJ(p);C a=mod(degrees(atan(p,p.gbr)),360.);E Y(a.r/8.,45.)*F(.9,.0,O(p.b))+Y(a.g/8.,45.)*F(.7,.0,O(p.r));}A bu(C p,X ax){E(ax==0)?p.gb:(ax==1)?p.rb:p.rg;}X bw(C n){n=O(n)+C(.01,.02,.03);B m=a6(n);E(m==n.r)?0:(m==n.g)?1:2;}C bN(C c){C V=ar(O(mod(c.r*6.+C(0,4,2),6.)-3.)-1.);V*=V*(3.-2.*V);E c.b*I(C(1.),V,c.g);}C aw(){C d=Cam.V-Pos;B b=K(d.rg/256.*a2(Cam.a),A(3),.7,3.,4),l=1.-F(14.,-6.,R(d.rg)-b*8.)*F(128.,48.,d.b)*step(.1,Nor.b);E aq(Texture1,LUV).V*3.*l;}\n"
"#define Q(a0)C a0(A);ad a0(){ac=P(a0(W),1);}C a0(A z)\n"
"#define at(a0)P a0(A);ad a0(){ac=a0(W);}P a0(A z)\n"
"Q(cmet52){B b=K(z,A(5),.9,3.,4);C c=I(J(48,41,33),J(103,101,104),b);E c;}Q(ptrshn){B b=K(z,A(3),.9,3.,4);C c=I(J(49,45,43),J(81,75,78),b*b);E c;}Q(dmnd2c){B b=K(z,A(7),.9,3.);z.r*=-1.5;z.g+=z.r*.5;z.r=1.-z.r+z.g;z=M(z*28.);B f=ar(1.-R(.1-z));f*=F(.6,.2,R(.6-z));f*=F(.6,.8,R(.1-z));f*=F(.2,.6,b)*2.+1.;B l=1.-F(.2,b+2.,a6(O(z-.5)));E C((f+1.)*I(.21,.29,b*b)*l);}Q(dmnd2cow){B b=K(z,A(7),.9,3.);C c=dmnd2c(z);B r=R(z-.5);c=I(c,c*J(70,61,53),F(.5,.2,r+b*b*b));E c;}B by(A z,B s){B d=1e6,i=0.;am(;i<5.;++i){A p=A(0,-s)*a2(i*72.);d=U(d,R(z-aO(z,p,p*a2(144.))));}E d;}at(dmnd2pnt){C c=dmnd2cow(z);z=M(z)-.5;B b=K(z,A(3),.9,3.),d=U(O(R(z)-.4),by(z,.35));E P(c,T(d-.02+b*.02,.01));}ad dmnd2pnt_m(){P c=aq(aj,W);ac=P(c.V*aw()+J(111,55,0)*c.a*(sin(aa.r*aB)*.5+.5),1);}Q(dmnd2cjp){B b=K(z,A(7),.9,3.,4);C c=dmnd2c(z);B r=R(z-.5);B m=F(.46,.45,r);B l=1.5-1.5*F(.0,.3,r*r);l=I(l,2.5,D(.42,.07,r));l=I(l,3.5,D(.44,.05,r));l=I(l,2.6,D(.36,.03,r));B n=.3+.2*F(.35,.30,r);l*=1.-n*F(.3,.7,b);l*=1.-.3*L(F(.13,.05,r));l=I(l,2.5,F(.04,.01,r));l-=l*D(.03,.01,r)*.7;c=I(c,J(68,66,54)*l,m);c*=1.-L(D(.34,.02,r));c*=1.-L(D(.46,.03,r));c*=1.-D(.41,.03,r)*.7;E c;}A bO(A z,B s){E A(1.-R(z)/s,T(R(z)-s));}at(lpdmnd){B b=K(z,A(5),.9,3.),t,o,k,r;C c=dmnd2c(z);A u,v;u.r=O(z.r-.5);u.g=U(z.g,.4);r=R(u-A(0,.4))-(.18-.06*F(.4,1.,z.g));k=.25-.15*F(.9,.96,z.g)+.03*L(F(.82,.86,z.g))+.07*F(.8,.2,z.g)+.07*L(F(.35,.22,z.g))-.07*F(.22,.0,z.g);o=Z(z-A(.5,.5),A(k,.46));o=S(o,-Z(u,A(.15,.03))+.06);c=I(c,C(.6,.55,.55)-z.g*.3+b*.2,T(o));c*=1.-.7*D(.0,.013,o);c*=1.-(r/.5-.1)*T(o);t=S(r,z.g-.96);o=O(t-.02)-.03;o=S(o,z.g-1.+u.r*.5);o=S(o,z.g-.96);c=I(c,C(1,1,.9)-z.g*.55,D(-.01,.01,o));c=I(c,C(.2*b+.1),T(t,.01));c*=1.-.2*D(.0,.05,t)*T(o);v=bO(u=z-A(.5,.4),.02);c*=1.+J(111,80,70)*D(.03,.01,R(u));c*=1.-.5*D(.02,.01,R(u));c=I(c,J(111,66,44)*(v.r*1.5+.2),v.g);E P(c,T(t-.03,.02));}ad lpdmnd_m(){P c=aq(aj,W);A z=M(W);z.r=O(.5-z.r);B t=M(-aa.r),r=R(z-A(0,.4)),l=t*pow(S(0.,1.-r),4.)*c.a;if(t>.75)l+=F(.03,.01,O(M(z.g+z.r*.5+t*2.)-.45))*F(.1,.08,z.r);ac=P(c.V*aw()+J(180,150,5)*l,1);}Q(mtlfw10){B b=K(z,A(5),.9,3.,4);C c=I(J(44,14,16),J(93,63,63),b*b);E c;}C bz(A z){B e=3e-3,a=0.;A g=A(6),r=bo(z,g);am(X i=0;i<9;++i)a+=aN(O(bo(A(i%3-1,i/3-1)*e+z,g)-r));E C(z+r.rg/g,a);}Q(mtlfw15){B b=K(z,A(3),.9,3.,4);C c=I(J(80,70,72),J(128,120,120),b*b);C v=bz(z);c*=I(.95,1.1,Y(v.rg,A(6)));c=I(c,J(168,128,120),F(.5,1.,v.b)*b*.7);E c;}at(mtlfw15ow){B b=K(z,A(3),.9,3.,4);C c=I(J(80,70,72),J(128,120,120),b*b);C v=bz(z);B m=F(.5,1.,v.b);B r=F(.4,.2,R(.5-M(v.rg)));c*=I(.95,1.1,Y(v.rg,A(6)))-2.*r*b*b;c=I(c,J(168,128,120),m*b*.7);E P(c,m*r);}ad mtlfw15ow_m(){P c=aq(aj,W);ac=P(c.V*aw()+D(.5,.125,M(W.g*.5+aa.r*.5))*c.a*.3,1);}Q(mtlfb3){B b=K(z,A(5),.9,3.,4);C pt=bj(z,8.,.31);C c=I(J(66,58,55),J(118,107,105),b);B l=1.-.5*F(.034,.036,pt.r);l=I(l,1.4,D(.033,.004,pt.r));E c*l;}B bP(A z){B b=Y(z,A(64)),f=0.,d=1e6;am(;f<11.;++f)d=be(d,O(R(.5-O(z-b7(f)))-I(.36,.29,aC(f+.7)))-I(.015,.03,b),.01);E d*1e2;}C b0(A z){C s,p;am(X i=0;i<3;++i){p=C(z,0);p[i]+=1e-4;s[i]=bP(p.rg);}E C(aJ(s.rg-s.b),s.b);}Q(mtlt12f){B b=K(z,A(5),.9,3.,4),l;C c=I(J(51,46,43),J(165,147,143),b*b),d=b0(z);l=1.-.5*(d.g-d.r)*D(.5,3.,d.b)*F(1.,.0,d.b);E c*l*.8;}Q(mtlt6f){B b=K(z,A(3),1.1,3.,4),l;C c=I(J(51,46,43),J(165,147,143),b*b),d=b0(z);l=1.-.5*(d.g-d.r)*D(.5,3.,d.b)*F(1.,.0,d.b);E c*l;}Q(mtlbk03){B b=K(z,A(5),.9,3.,4),l=.18*(.7+b*b);C g;z=ah(z,13.,.007);aV(g,z,L(F(.3+b*.2,.9,K(p[i],A(23),.5,2.,4))));E C(l*(1.-g.g*g.b));}Q(giron01e){B b=K(z,A(5),.9,3.,4),l=.18*(.7+b*b);C c=I(J(77,55,53),J(62,48,48),Y(z,A(128,13)))*(.7+b*b),g;z=ah(z,13.,.007);aV(g,z,L(F(.6+b*.3,.95,Y(p[i],A(47,23)))));c*=F(1.3,.9,g.b);E C(c*(1.+g.g*g.b));}B b1(A z,A s){z.g=S(z.g,0.);E aT(z,s);}C b2(A z){E C(.06+.1*H(z*133.7));}C aP(C c,C b,A z,B h,B s){B y=(z.g-h)/s,p=1.-y*y;c*=1.-D(-1.,1.,y);if(p>0.)c=b*(p*(.8+.2*D(.5,.25,M(z.r/s))))*(.7+L(D(.2,.7,y)));E c;}C b2(A z,B n){E C(n*n*.4);}Q(giron01nt3){z.r*=.5;B b=K(z*A(2,1),A(3,5),.9,3.,4),n=.8+.8*b*b,t=z.g+.2*U(.5,D(.5,.375,M(z.r*4.))),bQ=b1(z-A(.25,.62),A(3,2)/32.),aK=b1(z-A(.25,.55),A(3,2)/48.),r;C c=I(J(66,50,51),J(111,66,44),a3(D(.31,.01,z.g))),ai;A p=z,q;p.r=M(p.r*4.);if(z.g>.3)c=aI(c,A(4.*O(p.r-.5)-1.6,M(z.g*16.)-.5),.07);r=O(p.r-.5);c*=1.-.3*F(.31,.32,z.g)*F(.87,.86,z.g)*(F(.035,.03,.5-r)+D(.48,.01,r)-D(.46,.02,r));c=I(c*n,b2(z,b),S(F(.31,.3,z.g),T(aK)));c*=F(1.5,.7,z.g);if(z.g<.306)c*=1.-D(.3,.05,z.g)*T(-aK+10.,20.);c*=1.-D(.316,.004,z.g)*T(-aK);if(z.g<.1)c*=.0;q=z;q.g+=D(.1,.01,mod(q.r,.33))/2e2;c=aP(c,2.*b*J(93,84,79),z,.185,.015);c=aP(c,2.*b*J(138,77,48),z,.13,.025);c=aP(c,2.*b*J(112,71,51),z,.09,.015);c=aP(c,2.*b*J(138,77,48),q,.05,.015);p.r=O(M(z.r*6.-.5)-.5)/6.;c*=1.+.5*F(.04,.03,p.r)*D(.18,.03,p.g);r=aH(p-A(0,.12),A(.03,.01));r=aU(r,aH(p-A(0,.11),A(.01)));c*=1.-L(D(.0,.04,r));c=I(c,J(166,99,77)*2.*b*(.75+.5*L(D(.125,.01,z.g))),T(r));q=p;q.g-=.07;r=an(q,.03);c*=1.-L(D(.0,.07,r));c=I(c,J(127,83,72)*b*2.*F(.01,-.005,r),F(.005,.0,r));q.g-=.004;r=an(q,.015);c*=L(F(-.01,.01,r));q.g+=.013;r=an(q,.05);c+=J(67,38,30)*4.*a3(b)*L(D(-.02,.015,r)*D(.023,.02,z.g));r=aU(bQ,aK);r=aU(r,(z.g-.3)*3e2);c*=1.-.5*D(-2.,17.,aK)*F(.26,.3,z.g);ai=J(67,39,17)*n;ai=I(ai,C(n*.2),D(0.,4.,r)*b);ai*=1.-.4*pow(D(.0,3.,r),4.);ai+=(ai+.6)*a3(b)*L(D(-6.,8.,r)*D(.66,.04,z.g))*T(r);if(z.g<.55)ai=aI(ai,A(24.*O(z.r-.25)-1.85,M(z.g*24.+.5)-.5),.15);c=I(c,giron01e(z),F(.85,.9,t)+step(z.g,1./256.));c*=1.+D(.88,.015,t)-L(D(.87,.03,t));E I(c,ai,F(1.,.1,r));}C bR(C c,C k,A z,X w,X h){B b=K(z,A(w,h),.5,2.,2);c*=.9-.3*F(.15,.1,O(b-.5));E I(c,k,D(.5,.1,b));}Q(gmtlbg6){z=ah(z,9.,.005);X i=0,l[]=X[](13,43,17,47,23,59,27,63);B b=K(z,A(19),.7,2.,4);C c=J(40,50,60)*(.5+b);am(;i<8;i+=2)c=bR(c,J(145,140,137),z,l[i],l[i+1]);E c;}C bS(C c,C k,A z,X w,X h){B b=K(z,A(w,h),.5,2.,2);c*=1.-.15*L(F(.15,.1,O(b-.5)));E I(c,k,D(.5,.1,b));}Q(gblks17f2){B b=K(z,A(13),.9,3.,4),n=K(z,A(7),.9,3.,4);C c=I(J(111,66,55),J(80,55,52),L(F(.8,.2,n)))*(.8+.8*b*b),k=c;z=ah(z,13.,.01);X i=0,l[]=X[](13,43,17,47,23,59,27,63);b=K(z,A(19),.7,2.,4);am(;i<6;i+=2)c=bS(c,k,z,l[i],l[i+1]);E c;}C bT(C c,C k,A z,X w,X h){B b=K(z,A(w,h),.5,2.,1);c*=.9-.3*L(F(.15,.1,O(b-.5)));E I(c,k,D(.5,.1,b));}Q(gkarnclma2r){B b=K(z,A(3,29),.9,2.,4),t=.8+.8*b*b,d=O(z.g-.61),o=F(.25,.24,d),m;C c=J(140,127,127),k=c;A p=z;c*=1.-.1*F(.85,.86,z.g);c=t*I(c,J(110,55,50),F(.33,.32,z.g));p.g+=p.r*.11+b*.007;p.g=M(p.g*9.)-.5;m=F(.0,.1,O(p.g)-.2);X i=0,l[]=X[](3,29,5,37,9,63,27,63);am(;i<6;i+=2)c=I(c,bT(c,k,z,l[i],l[i+1]),m*o);c*=1.+t*o*(+.6*D(.1,.1,p.g)-.7*D(-.25,.3,p.g)-.5*D(.2,.1,p.g));c=I(c,J(99,66,51)*t,D(-.15,.1,p.g)*o);c*=1.+D(.36,.005,z.g)+D(.34,.005,z.g)+D(.865,.005,z.g)+D(.89,.01,z.g)-.5*L(D(.245,.01,d))-.7*L(D(.35,.01,z.g))-.5*L(D(.325,.02,z.g))-.8*L(D(.875,.02,z.g))-.3*L(D(.9,.02,z.g));c*=.3+a3(a5(z.r));E c;}Q(glrgbk3b){B b=K(ah(z,5.,.02),A(5),1.,3.,5),n=Y(z,A(13));A p=bc(z,A(8)),q=M(p),a1=p-q;C c=J(91,61,42)*(.8+.8*b*b);c=I(c,J(70,30,15)*(.8+.8*b*b),aD(q,.1).b*.3);c*=1.-L(aD(q,.01+b*.05).b)*n*b*b;c*=1.+D(.4,.3,aD(q,.01+b*.07).b)*a3(b)*.3;c*=.9+.2*H(a1)*(1.-aD(q,.1).b);c*=.9+.4*pow(bd(z-H(a1/8.),A(5),.6,2.,4),4.);E c;}Q(gblks15){B b=K(z,A(5),.9,3.,4),t=bd(ah(z,4.,.01),A(7),.5,3.,5),n=Y(ah(z,4.,.05),A(9)),a1,e;C pt=bj(z,4.,.1+n*t*.05),c;A d=bf(pt.r);a1=H(M(pt.gb));c=J(74,65,62)*(.8+.8*b*b);c+=D(.6,.3,n)*F(.3,.9,b*t)*.2;c*=1.-D(.5,.4,n)*F(.5,.7,t)*.1;c=I(c,J(86,74,78),D(.5,.1,b)*D(.7,.3,a1)*.7);c=I(c,J(105,90,70),D(.3,.1,t)*D(.3,.3,a1)*.3);e=D(.015,.005+.015*n,pt.r)+D(.4,.1,n*t)*.4;c*=1.-b*F(.015,.05,pt.r)*.7;c*=1.+e*b*(d.g-.5)*.7;c*=.9+.2*a1;c*=.9+.2*a5(Y(z-pt.gr,A(5)));E c;}Q(gblks18c){B b=K(z,A(13,1),.7,2.,3);C c=gblks15(z)*.7;c*=1.-L(F(.4,1.,b));E c;}Q(gklblki){B b=K(z,A(5),.9,3.,4),n=K(z,A(31,3),.5,3.,3),t=.75+b*b,d,o,i;A p=z;C c=gblks15(z);if(z.g>.38)E c;c=I(J(92,43,15),J(66,44,33),F(.1,.05,z.g))*t*(.5+.5*F(.0,.35,z.g));c+=L(D(.32,.015,z.g))*b+.3*b*D(.34,.05,z.g);c*=1.-D(.38,.01+b*b*.03,z.g)+3.*D(.15,.2,z.g)*(n-.5);p.r=mod(p.r,1./7.)-.07;p.g-=.21;d=an(A(.75*p.r,aQ(p.g,.1)),.033);o=T(d,.005);d=an(A(.75*p.r,aQ(p.g+.005,.09)),.033);i=T(d+.015);c=I(c,J(83,81,66)*t,(o-i)*F(.1,.3,z.g));c*=1.-F(.17,.25,z.g)*i;c+=L(D(.0,.015,d))*D(.32,.03,z.g);c*=1.+3.*pow(D(-.01,.03,d),4.)*D(.09,.03,z.g);d=an(A(.75*p.r,aQ(p.g+.03,.1)),.033);c*=1.-T(d+.01,.02)*(1.-o);if(z.g>.0"/*continued on next line*/
/*cont.*/"9&&z.g<.3)c=aI(c,A((O(p.r)-.035)*36.,M(z.g*36.)-.5),.1);E c;}at(gcntr2trn){B b=K(z-=.5,A(5),.9,3.,4),t=.75+b*b,n=Y(ah(z,7.,.02),A(17)),r=R(z),k=r>.4?38.:r>.32?28.:16.,a=M(atan(z.g,z.r)/b6),i=ay(a*k),as=O(O(r-.41-n*.002)*1e2-6.),m=F(1.5,1.4,as),aW[]=B[](1.,3.,-.145,-1.,2.,.166),d,b3,s;A p=z;C c=J(78,68,63);c*=1.+.5*L(D(.49,.005+.015*n*n+.015*b,r));c=I(c,J(83,52,47)*(.6+.4*n*n),m)*t;c*=1.-.5*D(1.5,.5,as)+b*D(1.,.5+.5*n,O(r-.418)*1e2-5.)-b*D(.5,.08,M(a*k+.5))*m+b*D(.5,.1,M(a*k+.55))*m;m=F(.34,.33,r);c=I(c*(1.-.5*m),J(83,52,47)*t,n*b*m);c=I(c,J(112,86,31)*t,m*L(D(.1,.15,.45,b)));c=I(c,J(77,66,77)*t,m*F(.5,.8,b)*.5);c*=1.-.7*D(.27,.34,.35,r);as=r+n*.004;m=r>.21&&r<.31?1.:0.;c*=1.-D(.325,.005,as)-D(.31,.005,as)-b*L(D(.29,.005,as))-b*L(D(.23,.01,as))-.5*L(D(.21,.02,as))+L(D(.3,.01,as))*b+L(D(.22,.01,as))*b-b*D(.5,.07,M(a*k+.5))*m;if(r<.23)i+=37.;if(r<.31)i+=73.;if(r<.31)i+=91.;c*=I(1.,.9+.2*aC(i),m);m=F(.01,.0,O(r-.411)-.039);i=ay(a*72.);p*=a2(i*5.);s=0.;d=1e6;X j=0;am(;j<6;j+=3){d=aY(d,b3=au(p,aJ(A(aW[j],aW[j+1])))+aW[j+2]);s+=s+B(b3>0.);}if(s==3.)++i;else i+=66.*s;i=aC(i);c=I(c,t*J(90,80,75),m);c=I(c,t*J(127,111,88),i*b*m);c*=I(1.,.7+.6*H(i),m);c*=1.-m*L(D(.0,.006,d))*b+m*L(D(.006,.006,O(d)))*b*.5;i=ay(a*4.);p=O(z*a2(i*90.+45.));d=1e6;am(j=0;j<2;++j,p=O(p*a2(45.)))d=aY(d,O(R(p-A(0,.12))-.16));m=F(.21,.2,r);as=aZ(aZ(d,.012),.001);c*=1.-F(.21,.2,r)*T(.012-d)+b*m*L(D(.005,.005,d))-.5*m*L(T(as-.001,.001));E P(c,(1.-F(.21,.15,r)*T(.028-d,.02))*F(.07,.087,r));}at(gcntr2trn_m){A p=M(W)-.5;B b=K(a2(aa.r*333.)*p/(.8+.2*sin(aa.r*61.)),A(53),.7,2.,4);P c=P(1.-b*C(0,.3,1),1),ai=aq(aj,(a2(aa.r*30.)*p/(.8+.2*sin(aa.r*1.26)))+.5);c.V=I(c.V,ai.V,ai.a);ai=aq(aj,W);c.V=I(c.V,ai.V,ai.a)*aw();E c;}Q(gtprst3){B b=K(z,A(13),.9,3.,4),n=K(z,A(7),.9,3.,4);C c=I(J(60,50,50),J(87,47,37),L(F(.7,.25,n)))*(.7+.8*b*b),g;z=ah(z,31.,.003);aV(g,z,a3(F(.0,.9,Y(p[i],A(93)))));c*=1.-(g.g+.4)*L(b*g.b)*g.b;E c;}Q(skcpthrt){B b=K(ah(z,7.,.01),A(9),.7,2.,4);C c=J(127,70,55)*(.85+.3*b);c*=1.-.2*L(F(.2,.05,b*b));c*=1.+.3*F(.6,.9,b);c*=1.-.2*L(D(.6,.3,K(ah(z,5.,.03),A(6),.6,2.,4)));E c;}Q(gskull4){B b=K(z,A(13),.9,3.,4);C c=J(60,50,46)*(.875+b*b);E c;}Q(gmtlspsld){B b=K(z,A(7),.9,3.,4),n=K(z,A(5),.9,3.,4);C c=I(J(103,56,53),J(73,58,71),smoothstep(.4,.5,n))*(.75+b*b);E c;}Q(gmtlsp4b){B b=K(z,A(13),.9,3.,4),n=Y(ah(z,5.,.05),A(9)),d=a5(M(z.r*4.)),m=F(.1,.15,d)*F(1.,.99,z.g);C c=J(51,44,44);c=I(c,J(73,55,52),F(.2,.2,b)*n*m);c=I(c,J(69,60,66),F(.7,.1,b)*b*m);c=I(c,J(99,77,77),F(.1,.5,n)*n*m*b*b*.3);c*=.6+.3*b+.3*b*b;c*=1.+.9*L(D(.21,.02+.1*n,d+b*.05))*m*b;c*=1.-L(F(.49,.5,O(z.g-.5)));c*=1.-F(.05,.2,d)*F(.16,.1,d);c*=1.+D(.99,.007,z.g);E aI(c,A(d-.4,M(z.g*8.)-.5),.07);}C b4(A z,B s){B b=K(z,A(3,1.+s+s),.7,2.,4),d=a5(z.r),m;z.g*=2.;C c=I(J(71,60,58),J(110,88,77),F(.1,.05,d))*(.7+.6*b);c*=1.-F(.05,.0,z.r)*(1.-b*b);c*=1.+.5*D(.05,.02,z.r);A p=A(d-.35,M(z.g*s)-.5);P k=bh(p,.11);m=T(k.a);c*=1.-.7*bi(p,1.1)*(1.-m);c=I(c,(k.g>.0?J(128,105,88):J(200,111,66)*F(-.2,.7,k.b))*(.4+2.*b*pow(ar(aN(k.gb*.7)),4.))*(1.-.6*D(-.1,.4,k.g)),m);E c;}Q(gspbdrbb){E b4(z,4.);}Q(gkarntwr4a){E gspbdrbb(z.gr);}Q(gkarntwrst){E b4(z,1.);}Q(gxstrtop4){B b=K(z,A(40,5),.9,3.,4);C c=J(110,110,98)*(.8+.8*b*b);if(z.g<1./4.)c*=.5;c*=1.-.4*F(.4,.0,b)+.5*F(.02,.0,z.g)+.2*D(.24,.01,z.g);E c;}Q(gwdclg1a){A p=z,q;p.g*=22.;q=M(p);B b=K(z,A(3,23),1.,2.,6),n=K(z,A(3,33),.7,3.,4),a1=H(p.g-q.g);C c=J(92,67,53)*(.8+.8*b*b);c*=1.-L(F(.1,.0,U(q.g,1.-q.g)))*b;c*=1.-.2*smoothstep(.3,.7,n);c*=.8+.3*b*a1;E c;}Q(gwdclg1bd){B b=K(z,A(13),.9,3.,4),x=z.r*16./3.;C c=gwdclg1a(z)*F(.15,.21,z.r);if(x<1.)c=J(59,48,49)*(.7+.6*b);c*=1.+.5*D(.05,.05,a5(x));E aI(c,A(O(z.r-3./32.)-.07,mod(z.g,.1)-.05),.004);}Q(gsltrfc){A p=bc(z,A(6,4)),q=M(p),u=q;B b=K(ah(z-=.5,5.,.03),A(13),.9,2.,3),n=Y(z,A(73,7)),t=(.75+b*b)*(.8+.4*b8(z.r*93.)),r;C c=C(.25*t);u.g+=u.g*2.-.01-.03*n;r=R(u-=clamp(u,A(.49,.5),A(.51,3)));c*=1.-.7*b*L(F(.07,.03,O(r-.5)))+.5*b*D(.35,.1,r)*L(F(.2,.1,q.g))-.3*L(F(.8,1.,q.g))-.3*(F(.3,.1,q.g))*F(.4,.6,r)+.2*L(F(.5,.1,q.g))*F(.45,.4,r);E c;}Q(cable){B b=K(z,A(5),.9,3.,4),h=M(z.g*10.);C c=I(J(53,48,42),J(38,38,36),b);c*=.6+b*.8;c*=1.-.5*L(D(.5,.5,h));c*=1.+.5*L(D(.25,.25,h));c*=1.+.5*L(D(.65,.35,h));E c;}Q(bmtsprt){B b=K(z,A(7,3),.9,3.,4),h=z.g+b*.04,l=1.-.15;C c=I(J(59,48,40),J(110,108,102),b*b);l=I(l,.5,D(.34,.05,z.g));l=I(l,.5,F(.08,.05,O(z.g-.7)));l=I(l,.3,D(.7,.03,z.g));l=I(l,1.5,D(.01,.03,z.g));l=I(l,2.2,D(.89,.1,h));l=I(l,1.6,F(.07,.04,O(z.g-.44)));l=I(l,2.5,D(.5,.04,h));l=I(l,1.7,D(.18,.04,h));E c*l;}Q(brdr11b){B b=K(z,A(5,3),.9,3.,4);C c=I(J(74,66,55),J(99,90,78),b*b);z.r*=2.;A p=aO(z,A(.5,.625),A(1.5,.625));B d=R(p-z),m=F(.22,.20,d),l=1.-.15*m;l=I(l,.5,F(.7,.9,z.g)*m);l=I(l,1.-bf(d).g*.5,D(.22,.04,d));l=I(l,.6,L(D(.19,.05,d)));l=I(l,.5,F(.05,0.,z.g));l=I(l,.5,D(.26,.05,z.g));l=I(l,1.7,F(.93,1.,z.g));l=I(l,1.7,D(.23,.04,z.g));E c*l;}at(blt414k){B b=K(z,A(1,5),.4,3.,4);C c=I(J(56,49,43),J(142,136,136),b);z=.5-O(z-.5);z.g*=4.;B a=D(.0,.1,R(z-aO(z,A(.41,.5),A(.42,3.5)))),d=aM(z),l=1.-.7*S(0.,1.-d/.15);l*=1.-.8*F(.24,.31,U(d,z.g-.1));c+=J(80,80,20)*a;E P(c*I(l,2.7,a),a);}at(light5){B b=K(z,A(1,5),.4,3.,4);C c=I(J(56,49,43),J(142,136,136),b);z=.5-O(z-.5);z.g*=8.;B d=R(z-aO(z,A(.27,.3),A(.27,7.7))),a=D(.0,.17,d),l=1.-.5*D(.17,.07,d);c+=J(80,80,20)*a;E P(c*I(l,2.7,a),a);}at(lt2){A p=O(z-.5);B b=K(z,A(1),.4,3.,4),r=R(p),a=F(.37,.33,r)*(.5+2.*b),l=1.+.0*F(.08,.03,O(r-.41));C c=I(J(56,49,43),J(142,136,136),b);l=I(l,7.,F(.44,.1*b,r));l*=1.-.5*L(D(.46,.04,r));l*=1.-.4*L(D(.36,.04,r));E P(c*l,a);}at(gpntgmlt1k){B b=K(z,A(5),.9,3.,4),d=be(by(z-=.5,.35),O(an(z,.4)),.02),a=pow(T(d-.02,.15),8.),o=U(S(Z(z,A(.46)),-an(z,.51)),O(an(z,.44)));C c=J(76,62,47)*(.8+.8*b*b);c*=1.+(b+.5)*T(O(o)-.01,.01);c*=1.-F(.1,.05,d)*T(an(z,.4));E P(c+1.*C(1,1,.3)*a,a);}at(icon){z.g-=.57;z.r=O(z.r-.48);B d=aT(z,A(.31,.12))/50.;d=S(d,-aT(z-A(0,.01),A(.28,.07))/120.);d=S(d,-Z(z-A(.0,.1),A(.22,.12)));d=S(d,-Z(z-A(.0,.1),A(.09,.31)));d=U(d,aH(z-A(.0,-.09),A(D(-.09,.32,z.g)*.04,.32)));d=U(d,aH(z-A(.11,-.21),A(D(-.07,.3,z.g)*.03,.15)));z.g+=.07;B b=R(z)-.47,m=T(b);C c=1.-C(.7,1,1)*T(S(.007-d,b+.04));E P(c*m,m);}at(q3bnr){z*=A(256,64);z.g+=2.;B d=an(z-A(81,30),11.);d=S(d,z.r-80.);d=S(d,-an(z-A(84,26),9.));d=U(d,Z(z-A(73,37),A(4,9))-4.);d=S(d,-Z(z-A(73,37),A(0,7))+1.);d=U(d,Z(z-A(91.5,47),A(4,19))-4.);d=S(d,-Z(z-A(91.5,47),A(0,17.5))+1.);d=U(d,Z(aR(z,111.)-A(105.+F(23.,50.,z.g)*3.,43),A(3.5,19)));d=U(d,Z(z-A(111,32),A(4,3)));d=U(d,Z(z-A(126,37),A(3,13)));d=U(d,Z(z-A(125.5+F(23.,50.,z.g)*10.,44),A(3.5,6)));d=U(d,Z(z-A(136.5-F(23.,50.,z.g)*9.,32),A(3.5,8)));d=U(d,Z(z-A(148.5,37),A(7,13)));d=S(d,-Z(z-A(155,33),A(6,3)));d=S(d,-Z(z-A(155,43),A(6,2)));d=U(d,Z(z-A(168,37),A(3.5,13)));d=U(d,Z(z-A(178.,37),A(3.5,13)));d=U(d,Z(z-A(188,37),A(3.5,13)));d=S(d,z.g-50.);E P(T(d,.8),0,0,H(z*511.));}ad q3bnr_m(){C c=aq(aj,W*2.).V*step(.5,M(aa.r*.5));c=I(c*aw(),C(.5,0,0),D(M(aa.r*2.),1./64.,M(W.g)));ac=P(c+bt(Ref)*.25+aq(aj,W+H(aa.rr)).a*.1,1);}ad beam(){A z=M(bu(Pos.V,bw(Nor))/128.);z.r+=aa.r/33.;B b=K(z,A(7),.9,2.),f=M(Pos.b/128.-.375);ac=P(2.*J(95,85,80)*f*f*f*f*I(1.,b,.5),0.);}ad flame(){A z=M(W),p=z;p.g+=p.g-aa.r;z.r+=sin(p.g*7.)*.2*z.g;B n=K(p+sin(p.gr*aB*9.+A(0,aa.r*9.))*.015+Y(p,A(5))*.1,A(13),.4,3.,4),b=Z(z-A(.5,.25),A(.05*L(F(.4,.2,z.g)),.1)),m=L(T(b+n*.25,.35));ac=F(.0,.4,m)*P(7,.5,.2,0);}ad Generic(){B l=au(Nor,aJ(C(2,0,8)));l=l*.4+.7;A z=bu(Pos,bw(Nor));C c=C(.5);c*=bN(C(M(aL*aa.a+.25),1.,1.));ac=P(c*l,1);}ad fixture(){P c=aq(aj,W);ac=P(c.V*I(aw(),C(1),c.a),1);}ad dmnd2cjp_m(){P c=aq(aj,W);B r=R(M(W)-.5);B s=I(.4,8.,M(aa.r*1.5));ac=P(c.V*aw()+J(240,130,5)*D(.1,.05,r/s)*F(.37,.32,r),1);}ad Lmapped(){C c=aq(aj,W).V;ac=P(c*aw(),1);}ad shiny(){P c=aq(aj,W);c.V*=1.+c.a*bt(Ref);ac=P(c.V*aw(),1);}ad timhel(){C d=aJ(Pos-Cam.V);d.b=d.b*4.+2.;A z=aJ(d).rg*2.;B b=F(.2,1.,K(z-aa.r*A(.1,.2),A(5),.5,2.,6));z.g*=1.5;B s=F(.3,1.,K(z-aa.r*A(.1,.18),A(5),.6,2.,6));ac=P(C(b,0,0)+J(80,30,8)*s*s*2.,1);}ad lava(){A z=ah(W/8.,aa.r*.5,2.,.05);B b=K(z,A(7),.9,2.,4);C c=J(91,22,14)*(.2+1.6*b);c=I(c,J(144,44,0),D(.6,.2,K(z,A(3),.7,3.,4)));c=I(c,J(244,144,66)*b*2.,L(D(.55,.25,K(z,A(11),.5,2.,4))));ac=P(c*ar(a6(aw())),1);}ad lavaf(){lava();}ad Loading(){ac=aq(aj,(.5+W*127.)/128.,2.5);ac.V*=.7+.3*Y(W,.5/fwidth(W));}ad UI(){"/*continued on next line*/
/*cont.*/"ac=aq(aj,W)*Clr;}";

// src/demo/data/shaders/vertex_shaders.glsl: 2489 => 1577 (63.4%)
const char g_vertex_shaders[] =
"#define c void\n"
"#define e location\n"
"#define f gl_Position\n"
"uniform mat4 MVP;uniform vec4 Time,Cam;layout(e=0)in vec4 P;layout(e=1)in vec4 T;layout(e=2)in vec3 N;layout(e=3)in vec4 C;out vec3 Pos,Nor,Ref;out vec2 UV,LUV;out vec4 Clr;c Generic(){f=MVP*P;Pos=P.rgb;Nor=N;UV=T.rg;LUV=T.ba;Ref=normalize(reflect((P-Cam).rgb,N));}c d(){f=P;UV=P.rg*.5+.5;}c UI(){f=vec4(2.*P.r-1.,1.-2.*P.g,1,1);UV=T.rg;Clr=C;}c cmet52(){d();}c dmnd2c(){d();}c dmnd2cow(){d();}c dmnd2cjp(){d();}c dmnd2pnt(){d();}c lpdmnd(){d();}c ptrshn(){d();}c mtlfw10(){d();}c mtlfw15(){d();}c mtlfw15ow(){d();}c mtlfb3(){d();}c mtlt12f(){d();}c mtlt6f(){d();}c mtlbk03(){d();}c gmtlbg6(){d();}c glrgbk3b(){d();}c gblks15(){d();}c gblks18c(){d();}c gklblki(){d();}c gtprst3(){d();}c gblks17f2(){d();}c gkarnclma2r(){d();}c skcpthrt(){d();}c gskull4(){d();}c gcntr2trn(){d();}c gmtlspsld(){d();}c gmtlsp4b(){d();}c gspbdrbb(){d();}c gkarntwr4a(){d();}c gkarntwrst(){d();}c giron01e(){d();}c giron01nt3(){d();}c gxstrtop4(){d();}c gwdclg1a(){d();}c gwdclg1bd(){d();}c gsltrfc(){d();}c bmtsprt(){d();}c cable(){d();}c brdr11b(){d();}c blt414k(){d();}c light5(){d();}c lt2(){d();}c gpntgmlt1k(){d();}c icon(){d();}c q3bnr(){d();}c Loading(){d();}c Lmapped(){Generic();}c mtlfw15ow_m(){Generic();}c dmnd2cjp_m(){Generic();}c dmnd2pnt_m(){Generic();}c lpdmnd_m(){Generic();}c fixture(){Generic();}c beam(){Generic();}c flame(){Generic();}c q3bnr_m(){Generic();}c shiny(){Generic();}c gcntr2trn_m(){Generic();}c timhel(){Generic();}c lavaf(){Generic();}c lava(){Generic();f+=MVP[2]*sin(Time.r*.5+dot(P.rgb/1e2,vec3(1)))*4.;}";

#pragma once
// auto-generated, do not modify (see cook_shader.js)

// trim_newlines       : true
// consistent_floats   : false
// rename_ids          : true
// rename_vec_fields   : true
// rename_globals      : true
// min_macro_savings   : 8

// src/demo/data/shaders/fragment_shaders.glsl: 30595 => 13784 (45.1%)
const char g_fragment_shaders[] =
"#define j vec2\n"
"#define y float\n"
"#define z vec3\n"
"#define A return\n"
"#define B mix\n"
"#define F vec4\n"
"#define J fract\n"
"#define K length\n"
"#define L max\n"
"#define M abs\n"
"#define O min\n"
"#define Q UV\n"
"#define T rgb\n"
"#define U FCol\n"
"#define Z void\n"
"#define aa Time\n"
"#define ag Texture0\n"
"#define ah texture\n"
"#define az floor\n"
"#define a8 normalize\n"
"uniform F aa,Cam;uniform sampler2D ag,Texture1;in z Pos,Nor,Ref;in j Q,LUV;in F Clr;out F U;\n"
"#define aX(x)((x)*(x)*(3.-2.*(x)))\n"
"#define R(x)(x)*(x)\n"
"#define aY(x)dot(x,x)\n"
"#define af(x)clamp(x,0.,1.)\n"
"#define C(r,g,b)(z(r,g,b)/255.)\n"
"y ay=3.1415927,by=2.*ay,a5=1.618034;j aZ(y i){y G=1.324718;A J(.5+i/j(G,G*G));}y ba(y i){A J(.5+i*a5);}y a6(j v){A O(v.r,v.g);}y a6(z v){A O(v.r,O(v.g,v.b));}y a6(F v){A O(O(v.r,v.g),O(v.b,v.a));}y ar(j v){A L(v.r,v.g);}y ar(z v){A L(v.r,L(v.g,v.b));}y ar(F v){A L(L(v.r,v.g),L(v.b,v.a));}y a9(j v){A v.r+v.g;}y E(y bc,y bd,y x){A 1.-af(M(x-bc)/bd);}y D(y aD,y be,y x){A af((x-aD)/(be-aD));}j W(y x){A j(sin(x),cos(x));}mat2 aA(y x){j v=W(radians(x));A mat2(v.g,v.r,-v.r,v.g);}j ao(j w,y p,y s){A w+sin(w.gr*ay*p)*s;}j ao(j w,y t,y p,y s){A w+sin(w.gr*ay*p+t)*s;}j bf(j w,j s){w.r+=az(w.g*s.g)*(.5/s.r);A J(w)*s;}z a0(j w,y r){A z(w-=clamp(w,r,1.-r),K(w)/r);}z a0(j w,j s,y r){s=s.gr/a6(s);w*=s;A z(w-=clamp(w,j(r),s-r),K(w)/r);}y H(j p){z q=J(p.rgr*.09153);q+=dot(q,q.gbr+19.19);A J((q.r+q.g)*q.b);}y H(y p){p=J(p*.1031);p*=p+33.33;p*=p+p;A J(p);}z bz(y p){z ad=J(z(p)*z(.1031,.1030,.0973));ad+=dot(ad,ad.gbr+33.33);A J((ad.rrg+ad.gbb)*ad.bgr);}j bh(j p){z ad=J(z(p.rgr)*z(.1031,.1030,.0973));ad+=dot(ad,ad.gbr+33.33);A J((ad.rr+ad.gb)*ad.bg);}F b0(y p){F as=J(F(p)*F(.1031,.1030,.0973,.1099));as+=dot(as,as.abrg+33.33);A J((as.rrgb+as.gbba)*as.bgar);}y X(y x,y p){A H(mod(x,p));}y N(y x){y i;A B(H(i=az(x)),H(i+1.),aX(x-i));}y V(y x,y p){y i;A B(X(i=az(x),p),X(i+1.,p),x-i);}y X(j p,j s){A H(mod(p,s));}y V(j p,j s){p*=s;j i=az(p);p-=i;p*=p*(3.-2.*p);y bi=X(i+j(0,0),s);y bj=X(i+j(0,1),s);y bk=X(i+j(1,1),s);y bl=X(i+j(1,0),s);A B(B(bi,bl,p.r),B(bj,bk,p.r),p.g);}y I(j p,j aj,y a1,y a2,int aB){y a3=V(p,aj),aq=1.,tw=1.;for(int i=0;i<aB;++i){p=J(p+a5);aj*=a2;aq*=a1;a3+=V(p,aj)*aq;tw+=aq;}A a3/tw;}y I(j p,j aj,y a1,y a2){A I(p,aj,a1,a2,4);}\n"
"#define a4(v)E(.5,.5,v)\n"
"y aE(j p,j aj,y a1,y a2,int aB){y a3=a4(V(p,aj)),aq=1.,tw=1.;for(int i=0;i<aB;++i){p=J(p+a5);aj*=a2;aq*=a1;a3+=a4(V(p,aj))*aq;tw+=aq;}A a3/tw;}j a7(j p,j a,j b){j ab=b-a,ap=p-a;y t=af(dot(ap,ab)/dot(ab,ab));A ab*t+a;}y S(j p,j b){j d=M(p)-b;A O(L(d.r,d.g),0.)+K(L(d,0.));}y aC(j p,j b){A ar(M(p)-b);}y aF(j p,y r){A K(p)-r;}y aG(j p,j r){A(K(p/r)-1.)/O(r.r,r.g);}y bm(y a,y b,y k){y h=af(.5+0.5*(b-a)/k);A B(b,a,h)-k*h*(1.-h);}j aH(y x){j d=j(dFdx(x),dFdy(x));A d/L(K(d),1e-8);}y ac(y s,y d){A af(1.-s/d);}y ac(y s){A af(1.-s/fwidth(s));}j aI(j v,y m){A j(m-M(v.r-m),v.g);}z aJ(j p,y W,y bn){z e=z(-1,0,1),r=z(1e5);j ae=az(p*W),b1=e.gg;p-=(ae+.5)/W;y Y=.5*X(ae+e.gg,j(W));y at=.5*X(ae+e.rg,j(W));y au=.5*X(ae+e.gb,j(W));y av=.5*X(ae+e.bg,j(W));y aw=.5*X(ae+e.gr,j(W));y aK=.5*X(ae+e.rb,j(W));y aL=.5*X(ae+e.bb,j(W));y aM=.5*X(ae+e.br,j(W));y aN=.5*X(ae+e.rr,j(W));j[4]ai,l;if(mod((ae.r+ae.g),2.)<.5){l[0]=1.+j(au-at,aK-Y);l[1]=1.+j(-au+av,aL-Y);l[2]=1.+j(-aw+av,-aM+Y);l[3]=1.+j(aw-at,-aN+Y);ai[0]=j(au,Y)+l[0]*j(-.5,.5);ai[1]=j(au,Y)+l[1]*j(.5,.5);ai[2]=j(aw,Y)+l[2]*j(.5,-.5);ai[3]=j(aw,Y)+l[3]*j(-.5,-.5);}else{l[0]=1.+j(-aK+Y,au-at);l[1]=1.+j(aL-Y,au-av);l[2]=1.+j(aM-Y,-aw+av);l[3]=1.+j(-aN+Y,-aw+at);ai[0]=j(Y,at)+l[0]*j(-.5,.5);ai[1]=j(Y,av)+l[1]*j(.5,.5);ai[2]=j(Y,av)+l[2]*j(.5,-.5);ai[3]=j(Y,at)+l[3]*j(-.5,-.5);}for(int i=0;i<4;i++){l[i]/=W;y bx=aC(p-ai[i]/W,l[i]/2.-bn/W);if(bx<r.r)r=z(bx,ae+ai[i]);}A r;}j aO(j p,j aP){p*=aP;j n=az(p),f=p-n,aQ,g,o,r;y aR=8.0,d;for(int i=0;i<9;++i){g=j(i%3-1,i/3-1);o=bh(mod(n+g,aP));r=g+o-f;d=a9(M(r));if(d<aR){aR=d;aQ=r;}}A aQ;}y aS(z p){p=a8(p);z a=mod(degrees(atan(p,p.gbr)),360.);A V(a.r/8.,45.)*D(.9,.0,M(p.b))+V(a.g/8.,45.)*D(.7,.0,M(p.r));}j aT(z p,int ax){A(ax==0)?p.gb:(ax==1)?p.rb:p.rg;}int aU(z n){n=M(n)+z(.01,.02,.03);y m=ar(n);A(m==n.r)?0:(m==n.g)?1:2;}z bo(z c){z T=af(M(mod(c.r*6.+z(0,4,2),6.)-3.)-1.);T*=T*(3.-2.*T);A c.b*B(z(1.),T,c.g);}z ak(){z d=Cam.T-Pos;y b=I(d.rg/256.*aA(Cam.a),j(3),.7,3.,4),l=1.-D(14.,-6.,K(d.rg)-b*8.)*D(128.,48.,d.b)*step(.1,Nor.b);A ah(Texture1,LUV).T*3.*l;}\n"
"#define P(al)z al(j);Z al(){U=F(al(Q),1);}z al(j w)\n"
"#define an(al)F al(j);Z al(){U=al(Q);}F al(j w)\n"
"P(cmet52){y b=I(w,j(5),.9,3.,4);z c=B(C(48,41,33),C(103,101,104),b);A c;}P(ptrshn){y b=I(w,j(3),.9,3.,4);z c=B(C(49,45,43),C(81,75,78),b*b);A c;}P(dmnd2c){y b=I(w,j(7),.9,3.);w.r*=-1.5;w.g+=w.r*.5;w.r=1.-w.r+w.g;w=J(w*28.);y f=af(1.-K(.1-w));f*=D(.6,.2,K(.6-w));f*=D(.6,.8,K(.1-w));f*=D(.2,.6,b)*2.+1.;y l=1.-D(.2,b+2.,ar(M(w-.5)));A z((f+1.)*B(.21,.29,b*b)*l);}P(dmnd2cow){y b=I(w,j(7),.9,3.);z c=dmnd2c(w);y r=K(w-.5);c=B(c,c*C(70,61,53),D(.5,.2,r+b*b*b));A c;}an(dmnd2pnt){z c=dmnd2cow(w);w=J(w)-.5;y b=I(w,j(3),.9,3.),d=M(K(w)-.4),i=0.;for(;i<5.;++i){j p=j(0,-.35)*aA(i*72.);d=O(d,K(w-a7(w,p,p*aA(144.))));}A F(c,ac(d-.02+b*.02,.01));}Z dmnd2pnt_m(){F c=ah(ag,Q);U=F(c.T*ak()+C(111,55,0)*c.a*(sin(aa.r*ay)*.5+.5),1);}P(dmnd2cjp){y b=I(w,j(7),.9,3.,4);z c=dmnd2c(w);y r=K(w-.5);y m=D(.46,.45,r);y l=1.5-1.5*D(.0,.3,r*r);l=B(l,2.5,E(.42,.07,r));l=B(l,3.5,E(.44,.05,r));l=B(l,2.6,E(.36,.03,r));y n=.3+.2*D(.35,.30,r);l*=1.-n*D(.3,.7,b);l*=1.-.3*R(D(.13,.05,r));l=B(l,2.5,D(.04,.01,r));l-=l*E(.03,.01,r)*.7;c=B(c,C(68,66,54)*l,m);c*=1.-R(E(.34,.02,r));c*=1.-R(E(.46,.03,r));c*=1.-E(.41,.03,r)*.7;A c;}j bp(j w,y s){A j(1.-K(w)/s,ac(K(w)-s));}an(lpdmnd){y b=I(w,j(5),.9,3.),t,o,k,r;z c=dmnd2c(w);j u,v;u.r=M(w.r-.5);u.g=O(w.g,.4);r=K(u-j(0,.4))-(.18-.06*D(.4,1.,w.g));k=.25-.15*D(.9,.96,w.g)+.03*R(D(.82,.86,w.g))+.07*D(.8,.2,w.g)+.07*R(D(.35,.22,w.g))-.07*D(.22,.0,w.g);o=S(w-j(.5,.5),j(k,.46));o=L(o,-S(u,j(.15,.03))+.06);c=B(c,z(.6,.55,.55)-w.g*.3+b*.2,ac(o));c*=1.-.7*E(.0,.013,o);c*=1.-(r/.5-.1)*ac(o);t=L(r,w.g-.96);o=M(t-.02)-.03;o=L(o,w.g-1.+u.r*.5);o=L(o,w.g-.96);c=B(c,z(1,1,.9)-w.g*.55,E(-.01,.01,o));c=B(c,z(.2*b+.1),ac(t,.01));c*=1.-.2*E(.0,.05,t)*ac(o);v=bp(u=w-j(.5,.4),.02);c*=1.+C(111,80,70)*E(.03,.01,K(u));c*=1.-.5*E(.02,.01,K(u));c=B(c,C(111,66,44)*(v.r*1.5+.2),v.g);A F(c,ac(t-.03,.02));}Z lpdmnd_m(){F c=ah(ag,Q);j w=J(Q);w.r=M(.5-w.r);y t=J(-aa.r),r=K(w-j(0,.4)),l=t*pow(L(0.,1.-r),4.)*c.a;if(t>.75)l+=D(.03,.01,M(J(w.g+w.r*.5+t*2.)-.45))*D(.1,.08,w.r);U=F(c.T*ak()+C(180,150,5)*l,1);}P(mtlfw10){y b=I(w,j(5),.9,3.,4);z c=B(C(44,14,16),C(93,63,63),b*b);A c;}z aV(j w){y e=3e-3,a=0.;j g=j(6),r=aO(w,g);for(int i=0;i<9;++i)a+=a9(M(aO(j(i%3-1,i/3-1)*e+w,g)-r));A z(w+r.rg/g,a);}P(mtlfw15){y b=I(w,j(3),.9,3.,4);z c=B(C(80,70,72),C(128,120,120),b*b);z v=aV(w);c*=B(.95,1.1,V(v.rg,j(6)));c=B(c,C(168,128,120),D(.5,1.,v.b)*b*.7);A c;}an(mtlfw15ow){y b=I(w,j(3),.9,3.,4);z c=B(C(80,70,72),C(128,120,120),b*b);z v=aV(w);y m=D(.5,1.,v.b);y r=D(.4,.2,K(.5-J(v.rg)));c*=B(.95,1.1,V(v.rg,j(6)))-2.*r*b*b;c=B(c,C(168,128,120),m*b*.7);A F(c,m*r);}Z mtlfw15ow_m(){F c=ah(ag,Q);U=F(c.T*ak()+E(.5,.125,J(Q.g*.5+aa.r*.5))*c.a*.3,1);}P(mtlfb3){y b=I(w,j(5),.9,3.,4);z pt=aJ(w,8.,.31);z c=B(C(66,58,55),C(118,107,105),b);y l=1.-.5*D(.034,.036,pt.r);l=B(l,1.4,E(.033,.004,pt.r));A c*l;}y bq(j w){y b=V(w,j(64)),f=0.,d=1e6;for(;f<11.;++f)d=bm(d,M(K(.5-M(w-aZ(f)))-B(.36,.29,ba(f+.7)))-B(.015,.03,b),.01);A d*1e2;}z aW(j w){z s,p;for(int i=0;i<3;++i){p=z(w,0);p[i]+=1e-4;s[i]=bq(p.rg);}A z(a8(s.rg-s.b),s.b);}P(mtlt12f){y b=I(w,j(5),.9,3.,4),l;z c=B(C(51,46,43),C(165,147,143),b*b),d=aW(w);l=1.-.5*(d.g-d.r)*E(.5,3.,d.b)*D(1.,.0,d.b);A c*l*.8;}P(mtlt6f){y b=I(w,j(3),1.1,3.,4),l;z c=B(C(51,46,43),C(165,147,143),b*b),d=aW(w);l=1.-.5*(d.g-d.r)*E(.5,3.,d.b)*D(1.,.0,d.b);A c*l;}P(mtlbk03){y b=I(w,j(5),.9,3.,4);z c=B(C(36,35,33),C(56,54,52),b*b);A c;}P(gmtlbg6){y b=I(w,j(13),1.,3.,4);z c=B(C(36,35,31),C(132,132,132),b);A c;}P(glrgbk3b){y b=I(ao(w,5.,.02),j(5),1.,3.,5),n=V(w,j(13));j p=bf(w,j(8)),q=J(p),am=p-q;z c=C(91,61,42)*(.8+.8*b*b);c=B(c,C(70,30,15)*(.8+.8*b*b),a0(q,.1).b*.3);c*=1.-R(a0(q,.01+b*.05).b)*n*b*b;c*=1.+E(.4,.3,a0(q,.01+b*.07).b)*sqrt(b)*.3;c*=.9+.2*H(am)*(1.-a0(q,.1).b);c*=.9+.4*pow(aE(w-H(am/8.),j(5),.6,2.,4),4.);A c;}P(gblks15){y b=I(w,j(5),.9,3.,4),t=aE(ao(w,4.,.01),j(7),.5,3.,5),n=V(ao(w,4.,.05),j(9)),am,e;z pt=aJ(w,4.,.1+n*t*.05),c;j d=aH(pt.r);am=H(J(pt.gb));c=C(91,67,61)*(.8+b*b*.8);c+=E(.6,.3,n)*D(.3,.9,b*t)*.2;c*=1.-E(.5,.4,n)*D(.5,.7,t)*.1;c=B(c,C(86,74,78),E(.5,.1,b)*E(.7,.3,am)*.7);c=B(c,C(105,90,70),E(.3,.1,t)*E(.3,.3,am)*.3);e=E(.015,.005+.015*n,pt.r)+E(.4,.1,n*t)*.4;c*=1.-b*D(.015,.05,pt.r)*.7;c*=1.+e*b*(d.g-.5)*.7;c*=.9+.2*am;c*=.9+.2*a4(V(w-pt.gr,j(5)));A c;}P(gtprst3){y b=I(w,j(13),.9,3.,4),n=V(ao(w,4.,.05),j(9));z c=B(C(56,48,49),C(100,50,40),.7*(n+b)*.5)*(.875+b*b);A c;}P(gmtlspsld){y b=I(w,j(7),.9,3.,4),n=I(w,j(5),.9,3.,4);z c=B(C(103,56,53),C(73,58,71),smoothstep(.4,.5,n))*(.75+b*b);A c;}F bs(j w,y s){A F(w/=s,sqrt(af(1.-aY(w))),K(w)-1.);}y bt(z n){y l=a9(n.gb)*.7;A pow(af(l),4.)+l;}y bu(F b,y s){y t=D(s,-s,b.g);A af(t*s-b.a)*t;}z bw(z c,j w,y s){F b=bs(w,s);c*=1.+bt(b.T)*ac(b.a)*.5;c*=1.-R(bu(b,1.7))*(1.-ac(b.a))*.3;A c;}P(gmtlsp4b){y b=I(w,j(13),.9,3.,4),n=V(ao(w,5.,.05),j(9)),d=a4(J(w.r*4.)),m=D(.1,.15,d)*D(1.,.99,w.g);z c=C(51,44,44);c=B(c,C(73,55,52),D(.2,.2,b)*n*m);c=B(c,C(69,60,66),D(.7,.1,b)*b*m);c=B(c,C(99,77,77),D(.1,.5,n)*n*m*b*b*.3);c*=.6+.3*b+.3*b*b;c*=1.+.9*R(E(.21,.02+.1*n,d+b*.05))*m*b;c*=1.-R(D(.49,.5,M(w.g-.5)));c*=1.-D(.05,.2,d)*D(.16,.1,d);c*=1.+E(.99,.007,w.g);c=bw(c,j(d-.4,J(w.g*8.)-.5),.07);A c;}P(gwdclg1a){j p=w,q;p.g*=22.;q=J(p);y b=I(w,j(3,23),1.,2.,6),n=I(w,j(3,33),.7,3.,4),am=H(p.g-q.g);z c=C(92,67,53)*(.8+.8*b*b);c*=1.-R(D(.1,.0,O(q.g,1.-q.g)))*b;c*=1.-.2*smoothstep(.3,.7,n);c*=.8+.3*b*am;A c;}P(gwdclg1bd){y b=I(w,j(13),.9,3.,4),x=w.r*16./3.;j p=aI(w,3./32.);z c=gwdclg1a(w);c*=D(.15,.21,w.r);if(x<1.)c=C(59,48,49)*(.7+.6*b);c*=1.+.5*E(.05,.05,a4(x));p.g=mod(p.g,.1);c*=1.+b*R(D(1.,.3,K(p*1e2-j(2,5))));A c;}P(cable){y b=I(w,j(5),.9,3.,4),h=J(w.g*10.);z c=B(C(53,48,42),C(38,38,36),b);c*=.6+b*.8;c*=1.-.5*R(E(.5,.5,h));c*=1.+.5*R(E(.25,.25,h));c*=1.+.5*R(E(.65,.35,h));A c;}P(bmtsprt){y b=I(w,j(7,3),.9,3.,4),h=w.g+b*.04,l=1.-.15;z c=B(C(59,48,40),C(110,108,102),b*b);l=B(l,.5,E(.34,.05,w.g));l=B(l,.5,D(.08,.05,M(w.g-.7)));l=B(l,.3,E(.7,.03,w.g));l=B(l,1.5,E(.01,.03,w.g));l=B(l,2.2,E(.89,.1,h));l=B(l,1.6,D(.07,.04,M(w.g-.44)));l=B(l,2.5,E(.5,.04,h));l=B(l,1.7,E(.18,.04,h));A c*l;}P(brdr11b){y b=I(w,j(5,3),.9,3.,4);z c=B(C(74,66,55),C(99,90,78),b*b);w.r*=2.;j p=a7(w,j(.5,.625),j(1.5,.625));y d=K(p-w),m=D(.22,.20,d),l=1.-.15*m;l=B(l,.5,D(.7,.9,w.g)*m);l=B(l,1.-aH(d).g*.5,E(.22,.04,d));l=B(l,.6,R(E(.19,.05,d)));l=B(l,.5,D(.05,0.,w.g));l=B(l,.5,E(.26,.05,w.g));l=B(l,1.7,D(.93,1.,w.g));l=B(l,1.7,E(.23,.04,w.g));A c*l;}an(blt414k){y b=I(w,j(1,5),.4,3.,4);z c=B(C(56,49,43),C(142,136,136),b);w=.5-M(w-.5);w.g*=4.;y a=E(.0,.1,K(w-a7(w,j(.41,.5),j(.42,3.5)))),d=a6(w),l=1.-.7*L(0.,1.-d/.15);l*=1.-.8*D(.24,.31,O(d,w.g-.1));c+=C(80,80,20)*a;A F(c*B(l,2.7,a),a);}an(light5){y b=I(w,j(1,5),.4,3.,4);z c=B(C(56,49,43),C(142,136,136),b);w=.5-M(w-.5);w.g*=8.;y d=K(w-a7(w,j(.27,.3),j(.27,7.7))),a=E(.0,.17,d),l=1.-.5*E(.17,.07,d);c+=C(80,80,20)*a;A F(c*B(l,2.7,a),a);}an(lt2){j p=M(w-.5);y b=I(w,j(1),.4,3.,4),r=K(p),a=D(.37,.33,r)*(.5+2.*b),l=1.+.0*D(.08,.03,M(r-.41));z c=B(C(56,49,43),C(142,136,136),b);l=B(l,7.,D(.44,.1*b,r));l*=1.-.5*R(E(.46,.04,r));l*=1.-.4*R(E(.36,.04,r));A F(c*l,a);}an(icon){w.g-=.57;w.r=M(w.r-.48);y d=aG(w,j(.31,.12))/50.;d=L(d,-aG(w-j(0,.01),j(.28,.07))/120.);d=L(d,-S(w-j(.0,.1),j(.22,.12)));d=L(d,-S(w-j(.0,.1),j(.09,.31)));d=O(d,aC(w-j(.0,-.09),j(E(-.09,.32,w.g)*.04,.32)));d=O(d,aC(w-j(.11,-.21),j(E(-.07,.3,w.g)*.03,.15)));w.g+=.07;y b=K(w)-.47,m=ac(b);z c=1.-z(.7,1,1)*ac(L(.007-d,b+.04));A F(c*m,m);}an(q3bnr){w*=j(256,64);w.g+=2.;y d=aF(w-j(81,30),11.);d=L(d,w.r-80.);d=L(d,-aF(w-j(84,26),9.));d=O(d,S(w-j(73,37),j(4,9))-4.);d=L(d,-S(w-j(73,37),j(0,7))+1.);d=O(d,S(w-j(91.5,47),j(4,19))-4.);d=L(d,-S(w-j(91.5,47),j(0,17.5))+1.);d=O(d,S(aI(w,111.)-j(105.+D(23.,50.,w.g)*3.,43),j(3.5,19)));d=O(d,S(w-j(111,32),j(4,3)));d=O(d,S(w-j(126,37),j(3,13)));d=O(d,S(w-j(125.5+D(23.,50.,w.g)*10.,44),j(3.5,6)));d=O(d,S(w-j(136.5-D(23.,50.,w.g)*9.,32),j(3.5,8)));d=O(d,S(w-j(148.5,37),j(7,13)));d=L(d,-S(w-j(155,33),j(6,3)));d=L(d,-S(w-j(155,43),j(6,2)));d=O(d,S(w-j(168,37),j(3.5,13)));d=O(d,S(w-j(178.,37),j(3.5,13)));d=O(d,S(w-j(188,37),j(3.5,13)));d=L(d,w.g-50.);A F(ac(d,.8),0,0,H(w*511.));}Z q3bnr_m(){z c=ah(ag,Q*2.).T*step(.5,J(aa.r*.5));c=B(c*ak(),z(.5,0,0),E(J(aa.r*2.),1./64.,J(Q.g)));U=F(c+aS(Ref)*.25+ah(ag,Q+H(aa.rr)).a*.1,1);}Z beam(){j w=J(aT(Pos.T,aU(Nor))/128.);w.r+=aa.r/33.;y b=I(w,j(7),.9,2.),f=J(Pos.b/128.-.375);U=F(2.*C(95,85,80)*f*f*f*f*B(1.,b,.5),0.);}Z flame(){j w=J(Q),p=w;p.g+=p.g-aa.r;w.r+=sin(p.g*7.)*.2*w.g;y n=I(p+sin(p.gr*ay*9.+j(0,aa.r*9.))*.015+V(p,j(5))*.1,j(13),.4,3.,4),b=S(w-j(.5,.25),j(.05*R(D(.4,.2,w.g)),.1)),m=R(ac(b+n*.25,.35));U=D(.0,.4,m)*F(7,.5,.2,0);}Z Generic(){y l=dot(Nor,a8(z(2,0,8)));l=l*.4+.7;j w=aT(Pos,aU(Nor));z c=z(.5);c*=bo(z(J(a5*aa.a+.25),1.,1.));U=F(c*l,1);}Z fixture(){F c=ah(ag,Q);U=F(c.T*B(ak(),z(1),c.a),1);}Z dmnd2cjp_m(){F c=ah(ag,Q);y r=K(J(Q)-.5);y s=B(.4,8.,J(aa.r*1.5));U=F(c.T*ak()+C(240,130,5)*E(.1,.05,r/s)*D(.37,.32,r),1);}Z Lmapped(){z c=ah(ag,Q).T;U=F(c*ak(),1);}Z shiny(){F c=ah(ag,Q);c.T*=1.+c.a*aS(Ref);U=F(c.T*ak(),1);}Z timhel(){z d=a8(Pos-Cam.T);d.b=d.b*4.+2.;j w=a8(d).rg*2.;y b=I(w-aa.r*j(.1,.2),j(5),.5,2.,6);w.g*=1.5;y s=D(.3,1.,I(w-aa.r*j(.1,.18),j(5),.6,2.,6));U=F(z(b,0,0)+C(80,30,8)*s*s*2.,1);}Z lava(){j w=ao(Q/8.,aa.r*.5,2.,.05);y b=I(w,j(7),.9,2.,4);z c=C(91,22,14)*(.2+1.6*b);c=B(c,C(144,44,0),E(.6,.2,I(w,j(3),.7,3.,4)));c=B(c,C(244,144,66)*b*2.,R(E(.55,.25,I(w,j(11),.5,2.,4))));U=F(c*af(ar(ak())),1);}Z Loading(){U=ah(ag,(.5+Q*127.)/128.,2.5);U.T*=.7+.3*V(Q,.5/fwidth(Q));}Z UI(){U=ah(ag,Q)*Clr;}";

// src/demo/data/shaders/vertex_shaders.glsl: 1899 => 1192 (62.8%)
const char g_vertex_shaders[] =
"#define c void\n"
"#define e location\n"
"#define f gl_Position\n"
"uniform mat4 MVP;uniform vec4 Cam;layout(e=0)in vec4 P;layout(e=1)in vec4 T;layout(e=2)in vec3 N;layout(e=3)in vec4 C;out vec3 Pos,Nor,Ref;out vec2 UV,LUV;out vec4 Clr;c Generic(){f=MVP*P;Pos=P.rgb;Nor=N;UV=T.rg;LUV=T.ba;Ref=normalize(reflect((P-Cam).rgb,N));}c d(){f=P;UV=P.rg*.5+.5;}c UI(){f=vec4(2.*P.r-1.,1.-2.*P.g,1,1);UV=T.rg;Clr=C;}c cmet52(){d();}c dmnd2c(){d();}c dmnd2cow(){d();}c dmnd2cjp(){d();}c dmnd2pnt(){d();}c lpdmnd(){d();}c ptrshn(){d();}c mtlfw10(){d();}c mtlfw15(){d();}c mtlfw15ow(){d();}c mtlfb3(){d();}c mtlt12f(){d();}c mtlt6f(){d();}c mtlbk03(){d();}c gmtlbg6(){d();}c glrgbk3b(){d();}c gblks15(){d();}c gtprst3(){d();}c gmtlspsld(){d();}c gmtlsp4b(){d();}c gwdclg1a(){d();}c gwdclg1bd(){d();}c bmtsprt(){d();}c cable(){d();}c brdr11b(){d();}c blt414k(){d();}c light5(){d();}c lt2(){d();}c icon(){d();}c q3bnr(){d();}c Loading(){d();}c Lmapped(){Generic();}c mtlfw15ow_m(){Generic();}c dmnd2cjp_m(){Generic();}c dmnd2pnt_m(){Generic();}c lpdmnd_m(){Generic();}c fixture(){Generic();}c beam(){Generic();}c flame(){Generic();}c q3bnr_m(){Generic();}c shiny(){Generic();}c timhel(){Generic();}c lava(){Generic();}";

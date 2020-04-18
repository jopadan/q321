#pragma once
// auto-generated, do not modify (see cook_shader.js)

// trim_newlines       : true
// consistent_floats   : false
// rename_ids          : true
// rename_vec_fields   : true
// rename_globals      : true
// min_macro_savings   : 8

// src/demo/data/shaders/fragment_shaders.glsl: 27571 => 12280 (44.5%)
const char g_fragment_shaders[] =
"#define j vec2\n"
"#define y float\n"
"#define z vec3\n"
"#define A return\n"
"#define B mix\n"
"#define F vec4\n"
"#define I fract\n"
"#define K length\n"
"#define L max\n"
"#define M abs\n"
"#define O min\n"
"#define P UV\n"
"#define R rgb\n"
"#define T FCol\n"
"#define Y void\n"
"#define aa Time\n"
"#define af Texture0\n"
"#define ag texture\n"
"#define aw floor\n"
"#define a4 normalize\n"
"uniform F aa,Cam;uniform sampler2D af,Texture1;in z Pos,Nor,Ref;in j P,LUV;in F Clr;out F T;\n"
"#define aU(x)((x)*(x)*(3.-2.*(x)))\n"
"#define Z(x)(x)*(x)\n"
"#define sat(x)clamp(x,0.,1.)\n"
"#define C(r,g,b)(z(r,g,b)/255.)\n"
"y am=3.1415927,bp=2.*am,a1=1.618034;j aV(y i){y G=1.324718;A I(.5+i/j(G,G*G));}y aW(y i){A I(.5+i*a1);}y a5(j v){A O(v.r,v.g);}y a5(z v){A O(v.r,O(v.g,v.b));}y a5(F v){A O(O(v.r,v.g),O(v.b,v.a));}y av(j v){A L(v.r,v.g);}y av(z v){A L(v.r,L(v.g,v.b));}y av(F v){A L(L(v.r,v.g),L(v.b,v.a));}y aA(j v){A v.r+v.g;}y E(y aX,y aY,y x){A 1.-sat(M(x-aX)/aY);}y D(y aB,y aZ,y x){A sat((x-aB)/(aZ-aB));}j U(y x){A j(sin(x),cos(x));}mat2 a6(y x){j v=U(radians(x));A mat2(v.g,v.r,-v.r,v.g);}j ba(j w,y p,y s){A w+sin(w.gr*am*p)*s;}j bc(j w,j s){w.r+=aw(w.g*s.g)*(.5/s.r);A I(w)*s;}z a2(j w,y r){A z(w-=clamp(w,r,1.-r),K(w)/r);}y H(j p){z q=I(p.rgr*.09153);q+=dot(q,q.gbr+19.19);A I((q.r+q.g)*q.b);}y H(y p){p=I(p*.1031);p*=p+33.33;p*=p+p;A I(p);}z bq(y p){z ac=I(z(p)*z(.1031,.1030,.0973));ac+=dot(ac,ac.gbr+33.33);A I((ac.rrg+ac.gbb)*ac.bgr);}j bd(j p){z ac=I(z(p.rgr)*z(.1031,.1030,.0973));ac+=dot(ac,ac.gbr+33.33);A I((ac.rr+ac.gb)*ac.bg);}F bs(y p){F aq=I(F(p)*F(.1031,.1030,.0973,.1099));aq+=dot(aq,aq.abrg+33.33);A I((aq.rrgb+aq.gbba)*aq.bgar);}y V(y x,y p){A H(mod(x,p));}y N(y x){y i;A B(H(i=aw(x)),H(i+1.),aU(x-i));}y W(y x,y p){y i;A B(V(i=aw(x),p),V(i+1.,p),x-i);}y V(j p,j s){A H(mod(p,s));}y W(j p,j s){p*=s;j i=aw(p);p-=i;p*=p*(3.-2.*p);y be=V(i+j(0,0),s);y bf=V(i+j(0,1),s);y bh=V(i+j(1,1),s);y bi=V(i+j(1,0),s);A B(B(be,bi,p.r),B(bf,bh,p.r),p.g);}y J(j p,j ai,y ay,y az,int a7){y a0=W(p,ai),an=1.,tw=1.;for(int i=0;i<a7;++i){p=I(p+a1);ai*=az;an*=ay;a0+=W(p,ai)*an;tw+=an;}A a0/tw;}y J(j p,j ai,y ay,y az){A J(p,ai,ay,az,4);}\n"
"#define a8(v)E(.5,.5,v)\n"
"y aC(j p,j ai,y ay,y az,int a7){y a0=a8(W(p,ai)),an=1.,tw=1.;for(int i=0;i<a7;++i){p=I(p+a1);ai*=az;an*=ay;a0+=a8(W(p,ai))*an;tw+=an;}A a0/tw;}j a3(j p,j a,j b){j ab=b-a,ap=p-a;y t=sat(dot(ap,ab)/dot(ab,ab));A ab*t+a;}y Q(j p,j b){j d=M(p)-b;A O(L(d.r,d.g),0.)+K(L(d,0.));}y a9(j p,j b){A av(M(p)-b);}y aD(j p,y r){A K(p)-r;}y aE(j p,j r){A(K(p/r)-1.)/O(r.r,r.g);}y bj(y a,y b,y k){y h=sat(.5+0.5*(b-a)/k);A B(b,a,h)-k*h*(1.-h);}j aF(y x){j d=j(dFdx(x),dFdy(x));A d/L(K(d),1e-8);}y ae(y s,y d){A sat(1.-s/d);}y ae(y s){A sat(1.-s/fwidth(s));}j bk(j v,y m){A j(m-M(v.r-m),v.g);}z aG(j p,y U,y bl){z e=z(-1,0,1),r=z(1e5);j ad=aw(p*U),bt=e.gg;p-=(ad+.5)/U;y X=.5*V(ad+e.gg,j(U));y ar=.5*V(ad+e.rg,j(U));y as=.5*V(ad+e.gb,j(U));y at=.5*V(ad+e.bg,j(U));y au=.5*V(ad+e.gr,j(U));y aH=.5*V(ad+e.rb,j(U));y aI=.5*V(ad+e.bb,j(U));y aJ=.5*V(ad+e.br,j(U));y aK=.5*V(ad+e.rr,j(U));j[4]ah,l;if(mod((ad.r+ad.g),2.)<.5){l[0]=1.+j(as-ar,aH-X);l[1]=1.+j(-as+at,aI-X);l[2]=1.+j(-au+at,-aJ+X);l[3]=1.+j(au-ar,-aK+X);ah[0]=j(as,X)+l[0]*j(-.5,.5);ah[1]=j(as,X)+l[1]*j(.5,.5);ah[2]=j(au,X)+l[2]*j(.5,-.5);ah[3]=j(au,X)+l[3]*j(-.5,-.5);}else{l[0]=1.+j(-aH+X,as-ar);l[1]=1.+j(aI-X,as-at);l[2]=1.+j(aJ-X,-au+at);l[3]=1.+j(-aK+X,-au+ar);ah[0]=j(X,ar)+l[0]*j(-.5,.5);ah[1]=j(X,at)+l[1]*j(.5,.5);ah[2]=j(X,at)+l[2]*j(.5,-.5);ah[3]=j(X,ar)+l[3]*j(-.5,-.5);}for(int i=0;i<4;i++){l[i]/=U;y bx=a9(p-ah[i]/U,l[i]/2.-bl/U);if(bx<r.r)r=z(bx,ad+ah[i]);}A r;}j aL(j p,j aM){p*=aM;j n=aw(p),f=p-n,aN,g,o,r;y aO=8.0,d;for(int i=0;i<9;++i){g=j(i%3-1,i/3-1);o=bd(mod(n+g,aM));r=g+o-f;d=aA(M(r));if(d<aO){aO=d;aN=r;}}A aN;}y aP(z p){p=a4(p);z a=mod(degrees(atan(p,p.gbr)),360.);A W(a.r/8.,45.)*D(.9,.0,M(p.b))+W(a.g/8.,45.)*D(.7,.0,M(p.r));}j aQ(z p,int ax){A(ax==0)?p.gb:(ax==1)?p.rb:p.rg;}int aR(z n){n=M(n)+z(.01,.02,.03);y m=av(n);A(m==n.r)?0:(m==n.g)?1:2;}z bm(z c){z R=sat(M(mod(c.r*6.+z(0,4,2),6.)-3.)-1.);R*=R*(3.-2.*R);A c.b*B(z(1.),R,c.g);}z ak(){z d=Cam.R-Pos;y b=J(d.rg/256.*a6(Cam.a),j(3),.7,3.,4),l=1.-D(14.,-6.,K(d.rg)-b*8.)*D(128.,48.,d.b)*step(.1,Nor.b);A ag(Texture1,LUV).R*3.*l;}\n"
"#define S(aj)z aj(j);Y aj(){T=F(aj(P),1);}z aj(j w)\n"
"#define al(aj)F aj(j);Y aj(){T=aj(P);}F aj(j w)\n"
"S(cmet52){y b=J(w,j(5),.9,3.,4);z c=B(C(48,41,33),C(103,101,104),b);A c;}S(ptrshn){y b=J(w,j(3),.9,3.,4);z c=B(C(49,45,43),C(81,75,78),b*b);A c;}S(dmnd2c){y b=J(w,j(7),.9,3.);w.r*=-1.5;w.g+=w.r*.5;w.r=1.-w.r+w.g;w=I(w*28.);y f=sat(1.-K(.1-w));f*=D(.6,.2,K(.6-w));f*=D(.6,.8,K(.1-w));f*=D(.2,.6,b)*2.+1.;y l=1.-D(.2,b+2.,av(M(w-.5)));A z((f+1.)*B(.21,.29,b*b)*l);}S(dmnd2cow){y b=J(w,j(7),.9,3.);z c=dmnd2c(w);y r=K(w-.5);c=B(c,c*C(70,61,53),D(.5,.2,r+b*b*b));A c;}al(dmnd2pnt){z c=dmnd2cow(w);w=I(w)-.5;y b=J(w,j(3),.9,3.),d=M(K(w)-.4),i=0.;for(;i<5.;++i){j p=j(0,-.35)*a6(i*72.);d=O(d,K(w-a3(w,p,p*a6(144.))));}A F(c,ae(d-.02+b*.02,.01));}Y dmnd2pnt_m(){F c=ag(af,P);T=F(c.R*ak()+C(111,55,0)*c.a*(sin(aa.r*am)*.5+.5),1);}S(dmnd2cjp){y b=J(w,j(7),.9,3.,4);z c=dmnd2c(w);y r=K(w-.5);y m=D(.46,.45,r);y l=1.5-1.5*D(.0,.3,r*r);l=B(l,2.5,E(.42,.07,r));l=B(l,3.5,E(.44,.05,r));l=B(l,2.6,E(.36,.03,r));y n=.3+.2*D(.35,.30,r);l*=1.-n*D(.3,.7,b);l*=1.-.3*Z(D(.13,.05,r));l=B(l,2.5,D(.04,.01,r));l-=l*E(.03,.01,r)*.7;c=B(c,C(68,66,54)*l,m);c*=1.-Z(E(.34,.02,r));c*=1.-Z(E(.46,.03,r));c*=1.-E(.41,.03,r)*.7;A c;}j bn(j w,y s){A j(1.-K(w)/s,ae(K(w)-s));}al(lpdmnd){y b=J(w,j(5),.9,3.),t,o,k,r;z c=dmnd2c(w);j u,v;u.r=M(w.r-.5);u.g=O(w.g,.4);r=K(u-j(0,.4))-(.18-.06*D(.4,1.,w.g));k=.25-.15*D(.9,.96,w.g)+.03*Z(D(.82,.86,w.g))+.07*D(.8,.2,w.g)+.07*Z(D(.35,.22,w.g))-.07*D(.22,.0,w.g);o=Q(w-j(.5,.5),j(k,.46));o=L(o,-Q(u,j(.15,.03))+.06);c=B(c,z(.6,.55,.55)-w.g*.3+b*.2,ae(o));c*=1.-.7*E(.0,.013,o);c*=1.-(r/.5-.1)*ae(o);t=L(r,w.g-.96);o=M(t-.02)-.03;o=L(o,w.g-1.+u.r*.5);o=L(o,w.g-.96);c=B(c,z(1,1,.9)-w.g*.55,E(-.01,.01,o));c=B(c,z(.2*b+.1),ae(t,.01));c*=1.-.2*E(.0,.05,t)*ae(o);v=bn(u=w-j(.5,.4),.02);c*=1.+C(111,80,70)*E(.03,.01,K(u));c*=1.-.5*E(.02,.01,K(u));c=B(c,C(111,66,44)*(v.r*1.5+.2),v.g);A F(c,ae(t-.03,.02));}Y lpdmnd_m(){F c=ag(af,P);j w=I(P);w.r=M(.5-w.r);y t=I(-aa.r),r=K(w-j(0,.4)),l=t*pow(L(0.,1.-r),4.)*c.a;if(t>.75)l+=D(.03,.01,M(I(w.g+w.r*.5+t*2.)-.45))*D(.1,.08,w.r);T=F(c.R*ak()+C(180,150,5)*l,1);}S(mtlfw10){y b=J(w,j(5),.9,3.,4);z c=B(C(44,14,16),C(93,63,63),b*b);A c;}z aS(j w){y e=3e-3,a=0.;j g=j(6),r=aL(w,g);for(int i=0;i<9;++i)a+=aA(M(aL(j(i%3-1,i/3-1)*e+w,g)-r));A z(w+r.rg/g,a);}S(mtlfw15){y b=J(w,j(3),.9,3.,4);z c=B(C(80,70,72),C(128,120,120),b*b);z v=aS(w);c*=B(.95,1.1,W(v.rg,j(6)));c=B(c,C(168,128,120),D(.5,1.,v.b)*b*.7);A c;}al(mtlfw15ow){y b=J(w,j(3),.9,3.,4);z c=B(C(80,70,72),C(128,120,120),b*b);z v=aS(w);y m=D(.5,1.,v.b);y r=D(.4,.2,K(.5-I(v.rg)));c*=B(.95,1.1,W(v.rg,j(6)))-2.*r*b*b;c=B(c,C(168,128,120),m*b*.7);A F(c,m*r);}Y mtlfw15ow_m(){F c=ag(af,P);T=F(c.R*ak()+E(.5,.125,I(P.g*.5+aa.r*.5))*c.a*.3,1);}S(mtlfb3){y b=J(w,j(5),.9,3.,4);z pt=aG(w,8.,.31);z c=B(C(66,58,55),C(118,107,105),b);y l=1.-.5*D(.034,.036,pt.r);l=B(l,1.4,E(.033,.004,pt.r));A c*l;}y bo(j w){y b=W(w,j(64)),f=0.,d=1e6;for(;f<11.;++f)d=bj(d,M(K(.5-M(w-aV(f)))-B(.36,.29,aW(f+.7)))-B(.015,.03,b),.01);A d*1e2;}z aT(j w){z s,p;for(int i=0;i<3;++i){p=z(w,0);p[i]+=1e-4;s[i]=bo(p.rg);}A z(a4(s.rg-s.b),s.b);}S(mtlt12f){y b=J(w,j(5),.9,3.,4),l;z c=B(C(51,46,43),C(165,147,143),b*b),d=aT(w);l=1.-.5*(d.g-d.r)*E(.5,3.,d.b)*D(1.,.0,d.b);A c*l*.8;}S(mtlt6f){y b=J(w,j(3),1.1,3.,4),l;z c=B(C(51,46,43),C(165,147,143),b*b),d=aT(w);l=1.-.5*(d.g-d.r)*E(.5,3.,d.b)*D(1.,.0,d.b);A c*l;}S(mtlbk03){y b=J(w,j(5),.9,3.,4);z c=B(C(36,35,33),C(56,54,52),b*b);A c;}S(gmtlbg6){y b=J(w,j(13),1.,3.,4);z c=B(C(36,35,31),C(132,132,132),b);A c;}S(glrgbk3b){y b=J(ba(w,5.,.02),j(5),1.,3.,5),n=W(w,j(13));j p=bc(w,j(8)),q=I(p),ao=p-q;z c=C(91,61,42)*(.8+.8*b*b);c=B(c,C(70,30,15)*(.8+.8*b*b),a2(q,.1).b*.3);c*=1.-Z(a2(q,.01+b*.05).b)*n*b*b;c*=1.+E(.4,.3,a2(q,.01+b*.07).b)*sqrt(b)*.3;c*=.9+.2*H(ao)*(1.-a2(q,.1).b);c*=.9+.4*pow(aC(w-H(ao/8.),j(5),.6,2.,4),4.);A c;}S(gblks15){y b=J(w,j(5),.9,3.,4),t=aC(w+sin(w.gr*am*4.)*.01,j(7),.5,3.,5),n=W(w+sin(w.gr*am*4.)*.05,j(9)),ao,e;z pt=aG(w,4.,.1+n*t*.05),c;j d=aF(pt.r);ao=H(I(pt.gb));c=C(91,67,61)*(.8+b*b*.8);c+=E(.6,.3,n)*D(.3,.9,b*t)*.2;c*=1.-E(.5,.4,n)*D(.5,.7,t)*.1;c=B(c,C(86,74,78),E(.5,.1,b)*E(.7,.3,ao)*.7);c=B(c,C(105,90,70),E(.3,.1,t)*E(.3,.3,ao)*.3);e=E(.015,.005+.015*n,pt.r)+E(.4,.1,n*t)*.4;c*=1.-b*D(.015,.05,pt.r)*.7;c*=1.+e*b*(d.g-.5)*.7;c*=.9+.2*ao;c*=.9+.2*a8(W(w-pt.gr,j(5)));A c;}S(gtprst3){y b=J(w,j(13),.9,3.,4),n=W(w+sin(w.gr*am*4.)*.05,j(9));z c=B(C(56,48,49),C(100,50,40),.7*(n+b)*.5)*(.875+b*b);A c;}S(cable){y b=J(w,j(5),.9,3.,4),h=I(w.g*10.);z c=B(C(53,48,42),C(38,38,36),b);c*=.6+b*.8;c*=1.-.5*Z(E(.5,.5,h));c*=1.+.5*Z(E(.25,.25,h));c*=1.+.5*Z(E(.65,.35,h));A c;}S(bmtsprt){y b=J(w,j(7,3),.9,3.,4),h=w.g+b*.04,l=1.-.15;z c=B(C(59,48,40),C(110,108,102),b*b);l=B(l,.5,E(.34,.05,w.g));l=B(l,.5,D(.08,.05,M(w.g-.7)));l=B(l,.3,E(.7,.03,w.g));l=B(l,1.5,E(.01,.03,w.g));l=B(l,2.2,E(.89,.1,h));l=B(l,1.6,D(.07,.04,M(w.g-.44)));l=B(l,2.5,E(.5,.04,h));l=B(l,1.7,E(.18,.04,h));A c*l;}S(brdr11b){y b=J(w,j(5,3),.9,3.,4);z c=B(C(74,66,55),C(99,90,78),b*b);w.r*=2.;j p=a3(w,j(.5,.625),j(1.5,.625));y d=K(p-w),m=D(.22,.20,d),l=1.-.15*m;l=B(l,.5,D(.7,.9,w.g)*m);l=B(l,1.-aF(d).g*.5,E(.22,.04,d));l=B(l,.6,Z(E(.19,.05,d)));l=B(l,.5,D(.05,0.,w.g));l=B(l,.5,E(.26,.05,w.g));l=B(l,1.7,D(.93,1.,w.g));l=B(l,1.7,E(.23,.04,w.g));A c*l;}al(blt414k){y b=J(w,j(1,5),.4,3.,4);z c=B(C(56,49,43),C(142,136,136),b);w=.5-M(w-.5);w.g*=4.;y a=E(.0,.1,K(w-a3(w,j(.41,.5),j(.42,3.5)))),d=a5(w),l=1.-.7*L(0.,1.-d/.15);l*=1.-.8*D(.24,.31,O(d,w.g-.1));c+=C(80,80,20)*a;A F(c*B(l,2.7,a),a);}al(light5){y b=J(w,j(1,5),.4,3.,4);z c=B(C(56,49,43),C(142,136,136),b);w=.5-M(w-.5);w.g*=8.;y d=K(w-a3(w,j(.27,.3),j(.27,7.7))),a=E(.0,.17,d),l=1.-.5*E(.17,.07,d);c+=C(80,80,20)*a;A F(c*B(l,2.7,a),a);}al(lt2){j p=M(w-.5);y b=J(w,j(1),.4,3.,4),r=K(p),a=D(.37,.33,r)*(.5+2.*b),l=1.+.0*D(.08,.03,M(r-.41));z c=B(C(56,49,43),C(142,136,136),b);l=B(l,7.,D(.44,.1*b,r));l*=1.-.5*Z(E(.46,.04,r));l*=1.-.4*Z(E(.36,.04,r));A F(c*l,a);}al(icon){w.g-=.57;w.r=M(w.r-.48);y d=aE(w,j(.31,.12))/50.;d=L(d,-aE(w-j(0,.01),j(.28,.07))/120.);d=L(d,-Q(w-j(.0,.1),j(.22,.12)));d=L(d,-Q(w-j(.0,.1),j(.09,.31)));d=O(d,a9(w-j(.0,-.09),j(E(-.09,.32,w.g)*.04,.32)));d=O(d,a9(w-j(.11,-.21),j(E(-.07,.3,w.g)*.03,.15)));w.g+=.07;y b=K(w)-.47,m=ae(b);z c=1.-z(.7,1,1)*ae(L(.007-d,b+.04));A F(c*m,m);}al(q3bnr){w*=j(256,64);w.g+=2.;y d=aD(w-j(81,30),11.);d=L(d,w.r-80.);d=L(d,-aD(w-j(84,26),9.));d=O(d,Q(w-j(73,37),j(4,9))-4.);d=L(d,-Q(w-j(73,37),j(0,7))+1.);d=O(d,Q(w-j(91.5,47),j(4,19))-4.);d=L(d,-Q(w-j(91.5,47),j(0,17.5))+1.);d=O(d,Q(bk(w,111.)-j(105.+D(23.,50.,w.g)*3.,43),j(3.5,19)));d=O(d,Q(w-j(111,32),j(4,3)));d=O(d,Q(w-j(126,37),j(3,13)));d=O(d,Q(w-j(125.5+D(23.,50.,w.g)*10.,44),j(3.5,6)));d=O(d,Q(w-j(136.5-D(23.,50.,w.g)*9.,32),j(3.5,8)));d=O(d,Q(w-j(148.5,37),j(7,13)));d=L(d,-Q(w-j(155,33),j(6,3)));d=L(d,-Q(w-j(155,43),j(6,2)));d=O(d,Q(w-j(168,37),j(3.5,13)));d=O(d,Q(w-j(178.,37),j(3.5,13)));d=O(d,Q(w-j(188,37),j(3.5,13)));d=L(d,w.g-50.);A F(ae(d,.8),0,0,H(w*511.));}Y q3bnr_m(){z c=ag(af,P*2.).R*step(.5,I(aa.r*.5));c=B(c*ak(),z(.5,0,0),E(I(aa.r*2.),1./64.,I(P.g)));T=F(c+aP(Ref)*.25+ag(af,P+H(aa.rr)).a*.1,1);}Y beam(){j w=I(aQ(Pos.R,aR(Nor))/128.);w.r+=aa.r/33.;y b=J(w,j(7),.9,2.),f=I(Pos.b/128.-.375);T=F(2.*C(95,85,80)*f*f*f*f*B(1.,b,.5),0.);}Y flame(){j w=I(P),p=w;p.g+=p.g-aa.r;w.r+=sin(p.g*7.)*.2*w.g;y n=J(p+sin(p.gr*am*9.+j(0,aa.r*9.))*.015+W(p,j(5))*.1,j(13),.4,3.,4),b=Q(w-j(.5,.25),j(.05*Z(D(.4,.2,w.g)),.1)),m=Z(ae(b+n*.25,.35));T=D(.0,.4,m)*F(7,.5,.2,0);}Y Generic(){y l=dot(Nor,a4(z(2,0,8)));l=l*.4+.7;j w=aQ(Pos,aR(Nor));z c=z(.5);c*=bm(z(I(a1*aa.a+.25),1.,1.));T=F(c*l,1);}Y fixture(){F c=ag(af,P);T=F(c.R*B(ak(),z(1),c.a),1);}Y dmnd2cjp_m(){F c=ag(af,P);y r=K(I(P)-.5);y s=B(.4,8.,I(aa.r*1.5));T=F(c.R*ak()+C(240,130,5)*E(.1,.05,r/s)*D(.37,.32,r),1);}Y Lmapped(){z c=ag(af,P).R;T=F(c*ak(),1);}Y shiny(){F c=ag(af,P);c.R*=1.+c.a*aP(Ref);T=F(c.R*ak(),1);}Y timhel(){z d=a4(Pos-Cam.R);d.b=d.b*4.+2.;j w=a4(d).rg*2.;y b=J(w-aa.r*j(.1,.2),j(5),.5,2.,4);w.g*=1.5;y s=D(.3,1.,J(w-aa.r*j(.1,.18),j(5),.6,2.,4));T=F(z(b,0,0)+C(80,30,8)*s*s*2.,1);}Y Loading(){T=ag(af,(.5+P*127.)/128.,2.5);T.R*=.7+.3*W(P,.5/fwidth(P));}Y UI(){T=ag(af,P)*Clr;}";

// src/demo/data/shaders/vertex_shaders.glsl: 1761 => 1098 (62.4%)
const char g_vertex_shaders[] =
"#define c void\n"
"#define e location\n"
"#define f gl_Position\n"
"uniform mat4 MVP;uniform vec4 Cam;layout(e=0)in vec4 P;layout(e=1)in vec4 T;layout(e=2)in vec3 N;layout(e=3)in vec4 C;out vec3 Pos,Nor,Ref;out vec2 UV,LUV;out vec4 Clr;c Generic(){f=MVP*P;Pos=P.rgb;Nor=N;UV=T.rg;LUV=T.ba;Ref=normalize(reflect((P-Cam).rgb,N));}c d(){f=P;UV=P.rg*.5+.5;}c UI(){f=vec4(2.*P.r-1.,1.-2.*P.g,1,1);UV=T.rg;Clr=C;}c cmet52(){d();}c dmnd2c(){d();}c dmnd2cow(){d();}c dmnd2cjp(){d();}c dmnd2pnt(){d();}c lpdmnd(){d();}c ptrshn(){d();}c mtlfw10(){d();}c mtlfw15(){d();}c mtlfw15ow(){d();}c mtlfb3(){d();}c mtlt12f(){d();}c mtlt6f(){d();}c mtlbk03(){d();}c gmtlbg6(){d();}c glrgbk3b(){d();}c gblks15(){d();}c gtprst3(){d();}c bmtsprt(){d();}c cable(){d();}c brdr11b(){d();}c blt414k(){d();}c light5(){d();}c lt2(){d();}c icon(){d();}c q3bnr(){d();}c Loading(){d();}c Lmapped(){Generic();}c mtlfw15ow_m(){Generic();}c dmnd2cjp_m(){Generic();}c dmnd2pnt_m(){Generic();}c lpdmnd_m(){Generic();}c fixture(){Generic();}c beam(){Generic();}c flame(){Generic();}c q3bnr_m(){Generic();}c shiny(){Generic();}c timhel(){Generic();}";

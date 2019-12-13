#pragma once
// auto-generated, do not modify (see cook_shader.js)

// trim_newlines       : true
// consistent_floats   : false
// rename_ids          : true
// rename_vec_fields   : true
// rename_globals      : true
// min_macro_savings   : 8

// src/demo/data/shaders/fragment_shaders.glsl: 24247 => 10075 (41.6%)
const char g_fragment_shaders[] =
"#define j vec2\n"
"#define y float\n"
"#define z vec3\n"
"#define A return\n"
"#define B mix\n"
"#define F vec4\n"
"#define I fract\n"
"#define J max\n"
"#define K abs\n"
"#define M min\n"
"#define O length\n"
"#define T rgb\n"
"#define U FCol\n"
"#define Y void\n"
"#define Z Texture0\n"
"#define ac texture\n"
"#define ad Time\n"
"#define ag clamp\n"
"#define aF normalize\n"
"uniform F ad,Cam;uniform sampler2D Z,Texture1;in z Pos,Nor,Ref;in j UV,LUV;in F Clr;out F U;\n"
"#define aK(x)((x)*(x)*(3.-2.*(x)))\n"
"#define sqr(x)(x)*(x)\n"
"#define sat(x)ag(x,0.,1.)\n"
"#define C(r,g,b)(z(r,g,b)/255.)\n"
"y aL=3.1415927,bh=2.*aL,as=1.618034;j aM(y i){y G=1.324718;A I(.5+i/j(G,G*G));}y aN(y i){A I(.5+i*as);}y at(j v){A M(v.r,v.g);}y at(z v){A M(v.r,M(v.g,v.b));}y at(F v){A M(M(v.r,v.g),M(v.b,v.a));}y aq(j v){A J(v.r,v.g);}y aq(z v){A J(v.r,J(v.g,v.b));}y aq(F v){A J(J(v.r,v.g),J(v.b,v.a));}y a0(j v){A v.r+v.g;}y E(y aO,y aP,y x){A 1.-ag(K(x-aO)/aP,0.,1.);}y D(y a1,y aQ,y x){A ag((x-a1)/(aQ-a1),0.,1.);}j Q(y x){A j(sin(x),cos(x));}mat2 aR(y x){j v=Q(x);A mat2(v.g,v.r,-v.r,v.g);}y H(j p){z q=I(p.rgr*.09153);q+=dot(q,q.gbr+19.19);A I((q.r+q.g)*q.b);}y H(y p){p=I(p*.1031);p*=p+33.33;p*=p+p;A I(p);}z bi(y p){z W=I(z(p)*z(.1031,.1030,.0973));W+=dot(W,W.gbr+33.33);A I((W.rrg+W.gbb)*W.bgr);}j aS(j p){z W=I(z(p.rgr)*z(.1031,.1030,.0973));W+=dot(W,W.gbr+33.33);A I((W.rr+W.gb)*W.bg);}F bj(y p){F ak=I(F(p)*F(.1031,.1030,.0973,.1099));ak+=dot(ak,ak.abrg+33.33);A I((ak.rrgb+ak.gbba)*ak.bgar);}y R(y x,y p){A H(mod(x,p));}y N(y x){y i;A B(H(i=floor(x)),H(i+1.),aK(x-i));}y ae(y x,y p){y i;A B(R(i=floor(x),p),R(i+1.,p),x-i);}y R(j p,j s){A H(mod(p,s));}y ae(j p,j s){p*=s;j i=floor(p);p-=i;p*=p*(3.-2.*p);y aT=R(i+j(0,0),s);y aU=R(i+j(0,1),s);y aV=R(i+j(1,1),s);y aW=R(i+j(1,0),s);A B(B(aT,aW,p.r),B(aU,aV,p.r),p.g);}y L(j p,j ar,y au,y av,int aX){y a2=ae(p,ar),aw=1.,tw=1.;for(int i=0;i<aX;++i){p=I(p+as);ar*=av;aw*=au;a2+=ae(p,ar)*aw;tw+=aw;}A a2/tw;}y L(j p,j ar,y au,y av){A L(p,ar,au,av,4);}j ay(j p,j a,j b){j ab=b-a,ap=p-a;y t=ag(dot(ap,ab)/dot(ab,ab),0.,1.);A ab*t+a;}y P(j p,j b){j d=K(p)-b;A M(J(d.r,d.g),0.)+O(J(d,0.));}y az(j p,j b){A aq(K(p)-b);}y a3(j p,y r){A O(p)-r;}y a4(j p,j r){A(O(p/r)-1.)/M(r.r,r.g);}y aY(y a,y b,y k){y h=ag(.5+0.5*(b-a)/k,.0,1.);A B(b,a,h)-k*h*(1.-h);}j aZ(y x){j d=j(dFdx(x),dFdy(x));A d/J(O(d),1e-8);}y ah(y s,y d){A ag(1.-s/d,0.,1.);}y ah(y s){A ag(1.-s/fwidth(s),0.,1.);}j ba(j v,y m){A j(m-K(v.r-m),v.g);}z bc(j p,y Q,y bd){j X=floor(p*Q);p-=(X+.5)/Q;z e=z(-1,0,1);y S=R(X,j(Q))*.5;y al=R(X+e.rg,j(Q))*.5;y am=R(X+e.gb,j(Q))*.5;y an=R(X+e.bg,j(Q))*.5;y ao=R(X+e.gr,j(Q))*.5;y a5=R(X+e.rb,j(Q))*.5;y a6=R(X+e.bb,j(Q))*.5;y a7=R(X+e.br,j(Q))*.5;y a8=R(X+e.rr,j(Q))*.5;j[4]aa,l;if(mod((X.r+X.g),2.)<.5){l[0]=j(am-al,a5-S)+1.;l[1]=j(-am+an,a6-S)+1.;l[2]=j(-ao+an,-a7+S)+1.;l[3]=j(ao-al,-a8+S)+1.;aa[0]=j(am,S)+l[0]*j(-.5,.5);aa[1]=j(am,S)+l[1]*j(.5,.5);aa[2]=j(ao,S)+l[2]*j(.5,-.5);aa[3]=j(ao,S)+l[3]*j(-.5,-.5);}else{l[0]=j(-a5+S,am-al)+1.;l[1]=j(a6-S,am-an)+1.;l[2]=j(a7-S,-ao+an)+1.;l[3]=j(-a8+S,-ao+al)+1.;aa[0]=j(S,al)+l[0]*j(-.5,.5);aa[1]=j(S,an)+l[1]*j(.5,.5);aa[2]=j(S,an)+l[2]*j(.5,-.5);aa[3]=j(S,al)+l[3]*j(-.5,-.5);}y d=1e5;j a9=j(0);for(int i=0;i<4;i++){l[i]/=Q;y bx=az(p-aa[i]/Q,l[i]/2.-bd/Q);if(bx<d){d=bx;a9=X+aa[i];}}A z(d,a9);}j aA(j p,j aB){p*=aB;j n=floor(p),f=p-n,aC,g,o,r;y aD=8.0,d;for(int i=0;i<9;++i){g=j(i%3-1,i/3-1);o=aS(mod(n+g,aB));r=g+o-f;d=a0(K(r));if(d<aD){aD=d;aC=r;}}A aC;}y aE(z p){p=aF(p);z a=mod(degrees(atan(p,p.gbr)),360.);A ae(a.r/8.,45.)*D(.9,.0,K(p.b))+ae(a.g/8.,45.)*D(.7,.0,K(p.r));}j aG(z p,int ax){A(ax==0)?p.gb:(ax==1)?p.rb:p.rg;}int aH(z n){n=K(n)+z(.01,.02,.03);y m=aq(n);A(m==n.r)?0:(m==n.g)?1:2;}z be(z c){z T=ag(K(mod(c.r*6.+z(0,4,2),6.)-3.)-1.,0.,1.);T*=T*(3.-2.*T);A c.b*B(z(1.),T,c.g);}z ai(){z d=Cam.T-Pos;y b=L(d.rg/256.*aR(Cam.a),j(3),.7,3.,4),l=1.-D(14.,-6.,O(d.rg)-b*8.)*D(128.,48.,d.b)*step(.1,Nor.b);A ac(Texture1,LUV).T*2.*l;}\n"
"#define V(af)z af(j);Y af(){U=F(af(UV),1);}z af(j w)\n"
"#define aj(af)F af(j);Y af(){U=af(UV);}F af(j w)\n"
"V(cmet52){y b=L(w,j(5),.9,3.,4);z c=B(C(48,41,33),C(103,101,104),b);A c;}V(ptrshn){y b=L(w,j(3),.9,3.,4);z c=B(C(49,45,43),C(81,75,78),b*b);A c;}V(dmnd2c){y b=L(w,j(7),.9,3.);w.r*=-1.5;w.g+=w.r*.5;w.r=1.-w.r+w.g;w=I(w*28.);y f=sat(1.-O(.1-w));f*=D(.6,.2,O(.6-w));f*=D(.6,.8,O(.1-w));f*=D(.2,.6,b)*2.+1.;y l=1.-D(.2,b+2.,aq(K(w-.5)));A z((f+1.)*B(.21,.29,b*b)*l);}V(dmnd2cow){y b=L(w,j(7),.9,3.);z c=dmnd2c(w);y r=O(w-.5);c=B(c,c*C(70,61,53),D(.5,.2,r+b*b*b));A c;}V(dmnd2cjp){y b=L(w,j(7),.9,3.,4);z c=dmnd2c(w);y r=O(w-.5);y m=D(.46,.45,r);y l=1.5-1.5*D(.0,.3,r*r);l=B(l,2.5,E(.42,.07,r));l=B(l,3.5,E(.44,.05,r));l=B(l,2.6,E(.36,.03,r));y n=.3+.2*D(.35,.30,r);l*=1.-n*D(.3,.7,b);l*=1.-.3*sqr(D(.13,.05,r));l=B(l,2.5,D(.04,.01,r));l-=l*E(.03,.01,r)*.7;c=B(c,C(68,66,54)*l,m);c*=1.-sqr(E(.34,.02,r));c*=1.-sqr(E(.46,.03,r));c*=1.-E(.41,.03,r)*.7;A c;}aj(lpdmnd){y b=L(w,j(5),.9,3.),t,o;z c=dmnd2c(w);j u=w;u.g=M(u.g,.4);t=O(u-j(.5,.4))-(.18-.06*D(.4,1.,w.g));t=J(t,w.g-.96);o=K(t-.07+w.g*.04)-.07;o=J(o,w.g-1.02+K(u.r-.5)*.4);o=J(o,w.g-.96);c=B(c,z(.5,.45,.44)-w.g*.3+b*.4,ah(o));c*=1.-.8*E(.0,.015,o);o=K(t-.02)-.03;o=J(o,w.g-1.02+K(u.r-.5)*.4);o=J(o,w.g-.96);c=B(c,z(.9,.9,.83)-w.g*.3,E(-.01,.02,o));c=B(c,z(.2*b+.1),ah(t,.01));A F(c,ah(t+.05,.1));}Y lpdmnd_m(){F c=ac(Z,UV,-.5);j u=I(UV);u.r=K(.5-u.r);y l=D(.03,.01,K(I(u.g+u.r*.5-ad.r)-.1))*D(.12,.1,u.r)*D(.37,.3,K(u.g-.6)),r=O(u-j(0,.4));l+=I(.1-ad.r)*pow(J(0.,1.02-r),8.)*c.a;U=F(c.T*ai()+C(120,65,3)*l,1);}V(mtlfw10){y b=L(w,j(5),.9,3.,4);z c=B(C(44,14,16),C(93,63,63),b*b);A c;}z aI(j w){y e=3e-3,a=0.;j g=j(6),r=aA(w,g);for(int i=0;i<9;++i)a+=a0(K(aA(j(i%3-1,i/3-1)*e+w,g)-r));A z(w+r.rg/g,a);}V(mtlfw15){y b=L(w,j(3),.9,3.,4);z c=B(C(80,70,72),C(128,120,120),b*b);z v=aI(w);c*=B(.95,1.1,ae(v.rg,j(6)));c=B(c,C(168,128,120),D(.5,1.,v.b)*b*.7);A c;}aj(mtlfw15ow){y b=L(w,j(3),.9,3.,4);z c=B(C(80,70,72),C(128,120,120),b*b);z v=aI(w);y m=D(.5,1.,v.b);y r=D(.4,.2,O(.5-I(v.rg)));c*=B(.95,1.1,ae(v.rg,j(6)))-2.*r*b*b;c=B(c,C(168,128,120),m*b*.7);A F(c,m*r);}Y mtlfw15ow_m(){F c=ac(Z,UV,-.5);U=F(c.T*ai()+E(.5,.125,I(UV.g*.5+ad.r*.5))*c.a*.3,1);}V(mtlfb3){y b=L(w,j(5),.9,3.,4);z pt=bc(w,8.,.31);z c=B(C(66,58,55),C(118,107,105),b);y l=1.-.5*D(.034,.036,pt.r);l=B(l,1.4,E(.033,.004,pt.r));A c*l;}y bf(j w){y b=ae(w,j(64)),f=0.,d=1e6;for(;f<11.;++f)d=aY(d,K(O(.5-K(w-aM(f)))-B(.36,.29,aN(f+.7)))-B(.015,.03,b),.01);A d*1e2;}z aJ(j w){z s,p;for(int i=0;i<3;++i){p=z(w,0);p[i]+=1e-4;s[i]=bf(p.rg);}A z(aF(s.rg-s.b),s.b);}V(mtlt12f){y b=L(w,j(5),.9,3.,4),l;z c=B(C(51,46,43),C(165,147,143),b*b),d=aJ(w);l=1.-.5*(d.g-d.r)*E(.5,3.,d.b)*D(1.,.0,d.b);A c*l*.8;}V(mtlt6f){y b=L(w,j(3),1.1,3.,4),l;z c=B(C(51,46,43),C(165,147,143),b*b),d=aJ(w);l=1.-.5*(d.g-d.r)*E(.5,3.,d.b)*D(1.,.0,d.b);A c*l;}V(mtlbk03){y b=L(w,j(5),.9,3.,4);z c=B(C(36,35,33),C(56,54,52),b*b);A c;}V(cable){y b=L(w,j(5),.9,3.,4),h=I(w.g*10.);z c=B(C(53,48,42),C(38,38,36),b);c*=.6+b*.8;c*=1.-.5*sqr(E(.5,.5,h));c*=1.+.5*sqr(E(.25,.25,h));c*=1.+.5*sqr(E(.65,.35,h));A c;}V(bmtsprt){y b=L(w,j(7,3),.9,3.,4),h=w.g+b*.04,l=1.-.15;z c=B(C(59,48,40),C(110,108,102),b*b);l=B(l,.5,E(.34,.05,w.g));l=B(l,.5,D(.08,.05,K(w.g-.7)));l=B(l,.3,E(.7,.03,w.g));l=B(l,1.5,E(.01,.03,w.g));l=B(l,2.2,E(.89,.1,h));l=B(l,1.6,D(.07,.04,K(w.g-.44)));l=B(l,2.5,E(.5,.04,h));l=B(l,1.7,E(.18,.04,h));A c*l;}V(brdr11b){y b=L(w,j(5,3),.9,3.,4);z c=B(C(74,66,55),C(99,90,78),b*b);w.r*=2.;j p=ay(w,j(.5,.625),j(1.5,.625));y d=O(p-w),m=D(.22,.20,d),l=1.-.15*m;l=B(l,.5,D(.7,.9,w.g)*m);l=B(l,1.-aZ(d).g*.5,E(.22,.04,d));l=B(l,.6,sqr(E(.19,.05,d)));l=B(l,.5,D(.05,0.,w.g));l=B(l,.5,E(.26,.05,w.g));l=B(l,1.7,D(.93,1.,w.g));l=B(l,1.7,E(.23,.04,w.g));A c*l;}aj(blt414k){y b=L(w,j(1,5),.4,3.,4);z c=B(C(56,49,43),C(142,136,136),b);w=.5-K(w-.5);w.g*=4.;y a=E(.0,.1,O(w-ay(w,j(.41,.5),j(.42,3.5)))),d=at(w),l=1.-.7*J(0.,1.-d/.15);l*=1.-.8*D(.24,.31,M(d,w.g-.1));c+=C(80,80,20)*a;A F(c*B(l,2.7,a),a);}aj(light5){y b=L(w,j(1,5),.4,3.,4);z c=B(C(56,49,43),C(142,136,136),b);w=.5-K(w-.5);w.g*=8.;y d=O(w-ay(w,j(.27,.3),j(.27,7.7))),a=E(.0,.17,d),l=1.-.5*E(.17,.07,d);c+=C(80,80,20)*a;A F(c*B(l,2.7,a),a);}aj(lt2){j p=K(w-.5);y b=L(w,j(1),.4,3.,4),r=O(p),a=D(.37,.33,r)*(.5+2.*b),l=1.+.0*D(.08,.03,K(r-.41));z c=B(C(56,49,43),C(142,136,136),b);l=B(l,7.,D(.44,.1*b,r));l*=1.-.5*sqr(E(.46,.04,r));l*=1.-.4*sqr(E(.36,.04,r));A F(c*l,a);}aj(icon){w.g-=.57;w.r=K(w.r-.48);y d=a4(w,j(.31,.12))/50.;d=J(d,-a4(w-j(0,.01),j(.28,.07))/120.);d=J(d,-P(w-j(.0,.1),j(.22,.12)));d=J(d,-P(w-j(.0,.1),j(.09,.31)));d=M(d,az(w-j(.0,-.09),j(E(-.09,.32,w.g)*.04,.32)));d=M(d,az(w-j(.11,-.21),j(E(-.07,.3,w.g)*.03,.15)));w.g+=.07;y b=O(w)-.47,m=ah(b);z c=1.-z(.7,1,1)*ah(J(.007-d,b+.04));A F(c*m,m);}aj(q3bnr){w*=j(256,64);w.g+=2.;y d=a3(w-j(81,30),11.);d=J(d,w.r-80.);d=J(d,-a3(w-j(84,26),9.));d=M(d,P(w-j(73,37),j(4,9))-4.);d=J(d,-P(w-j(73,37),j(0,7))+1.);d=M(d,P(w-j(91.5,47),j(4,19))-4.);d=J(d,-P(w-j(91.5,47),j(0,17.5))+1.);d=M(d,P(ba(w,111.)-j(105.+D(23.,50.,w.g)*3.,43),j(3.5,19)));d=M(d,P(w-j(111,32),j(4,3)));d=M(d,P(w-j(126,37),j(3,13)));d=M(d,P(w-j(125.5+D(23.,50.,w.g)*10.,44),j(3.5,6)));d=M(d,P(w-j(136.5-D(23.,50.,w.g)*9.,32),j(3.5,8)));d=M(d,P(w-j(148.5,37),j(7,13)));d=J(d,-P(w-j(155,33),j(6,3)));d=J(d,-P(w-j(155,43),j(6,2)));d=M(d,P(w-j(168,37),j(3.5,13)));d=M(d,P(w-j(178.,37),j(3.5,13)));d=M(d,P(w-j(188,37),j(3.5,13)));d=J(d,w.g-50.);A F(ah(d,.8),0,0,H(w*511.));}Y q3bnr_m(){z c=ac(Z,UV*2.,-.5).T*step(.5,I(ad.r*.5));c=B(c*ai(),z(.5,0,0),E(I(ad.r*2.),1./64.,I(UV.g)));U=F(c+aE(Ref)*.25+ac(Z,UV+H(ad.rr)).a*.1,1);}Y beam(){j w=I(aG(Pos.T,aH(Nor))/128.);w.r+=ad.r/33.;y b=L(w,j(7),.9,2.),f=I(Pos.b/128.-.375);U=F(2.*C(95,85,80)*f*f*f*f*B(1.,b,.5),0.);}Y Generic(){y l=dot(Nor,aF(z(2,0,8)));l=l*.4+.7;j w=aG(Pos,aH(Nor));z c=z(.5);c*=be(z(I(as*ad.a+.25),1.,1.));U=F(c*l,1);}Y fixture(){F c=ac(Z,UV,-.5);U=F(c.T*B(ai(),z(1),c.a),1);}Y dmnd2cjp_m(){F c=ac(Z,UV,-.5);y r=O(I(UV)-.5);y s=B(.4,8.,I(ad.r*1.5));U=F(c.T*ai()+C(240,130,5)*E(.1,.05,r/s)*D(.37,.32,r),1);}Y Lmapped(){z c=ac(Z,UV,-.5).T;U=F(c*ai(),1);}Y shiny(){F c=ac(Z,UV,-.5);c.T*=1.+c.a*aE(Ref);U=F(c.T*ai(),1);}Y Loading(){U=ac(Z,(.5+UV*127.)/128.,2.5);U.T*=.7+.3*ae(UV,.5/fwidth(UV));}Y UI(){U=ac(Z,UV)*Clr;}";

// src/demo/data/shaders/vertex_shaders.glsl: 1536 => 942 (61.3%)
const char g_vertex_shaders[] =
"#define c void\n"
"#define e location\n"
"#define f gl_Position\n"
"uniform mat4 MVP;uniform vec4 Cam;layout(e=0)in vec4 P;layout(e=1)in vec4 T;layout(e=2)in vec3 N;layout(e=3)in vec4 C;out vec3 Pos,Nor,Ref;out vec2 UV,LUV;out vec4 Clr;c Generic(){f=MVP*P;Pos=P.rgb;Nor=N;UV=T.rg;LUV=T.ba;Ref=normalize(reflect((P-Cam).rgb,N));}c d(){f=P;UV=P.rg*.5+.5;}c UI(){f=vec4(2.*P.r-1.,1.-2.*P.g,1,1);UV=T.rg;Clr=C;}c cmet52(){d();}c dmnd2c(){d();}c dmnd2cow(){d();}c dmnd2cjp(){d();}c lpdmnd(){d();}c ptrshn(){d();}c mtlfw10(){d();}c mtlfw15(){d();}c mtlfw15ow(){d();}c mtlfb3(){d();}c mtlt12f(){d();}c mtlt6f(){d();}c mtlbk03(){d();}c bmtsprt(){d();}c cable(){d();}c brdr11b(){d();}c blt414k(){d();}c light5(){d();}c lt2(){d();}c icon(){d();}c q3bnr(){d();}c Loading(){d();}c Lmapped(){Generic();}c mtlfw15ow_m(){Generic();}c dmnd2cjp_m(){Generic();}c lpdmnd_m(){Generic();}c fixture(){Generic();}c beam(){Generic();}c q3bnr_m(){Generic();}c shiny(){Generic();}";

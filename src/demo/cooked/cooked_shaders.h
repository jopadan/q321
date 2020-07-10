#pragma once

// auto-generated, do not modify
static_assert(0xbf487584U == Demo::Shader::Version, "Shader definition mismatch, please recompile the shader compiler & shaders");

// src/demo/data/shaders/fragment_shaders.glsl: 80028 => 32632 (40.8%)
static constexpr char g_fragment_shaders[] =
"#define d vec2\n"
"#define h float\n"
"#define k vec3\n"
"#define l return\n"
"#define o mix\n"
"#define A abs\n"
"#define F vec4\n"
"#define G fract\n"
"#define M length\n"
"#define O min\n"
"#define P void\n"
"#define Q max\n"
"#define R UV\n"
"#define U Time\n"
"#define V if\n"
"#define Z int\n"
"#define ae xyz\n"
"#define af Texture0\n"
"#define ai floor\n"
"#define ak texture\n"
"#define a9 sqrt\n"
"#define aE normalize\n"
"#define b6(x)((x)*(x)*(3.-2.*(x)))\n"
"#define E(x)((x)*(x))\n"
"#define aV(x)dot(x,x)\n"
"#define Y(x)clamp(x,0.,1.)\n"
"#define n(r,g,b)(k(r,g,b)/255.)\n"
"#define a6(u)i(.5,.5,u)\n"
"#define I(a8)k a8(d);P a8(){K=F(a8(R),1);}k a8(d c)\n"
"#define al(a8)F a8(d);P a8(){K=a8(R);}F a8(d c)\n"
"#define bj(cb,c,cc){d p[3];h r[3];p[0]=c;p[1]=c+dFdx(c);p[2]=c+dFdy(c);for(Z m=0;m<3;++m)r[m]=cc;cb=k(cd(d(r[1],r[2])-r[0]),r[0]);}\n"
"#define b7(a8,ce)k a8(d p,d b8){p*=b8;d B=ai(p),T=p-B,b9,g,ad,r;h aW=8.,bk=aW,f;for(Z m=0;m<9;++m){g=d(m%3-1,m/3-1);ad=cf(mod(B+g,b8));r=g+ad-T;f=ce;V(f<aW){bk=aW;aW=f;b9=r;}else V(f<bk){bk=f;}}l k(b9,bk-aW);}\n"
"uniform F U,Cam;uniform sampler2D af,Texture1;in k Pos,Nor,WNor,Ref;in d R,LUV;in F Clr;out F K;h aH=3.1415927,bA=2.*aH,aX=1.618034;d bB(h m){h bu=1.324718;l G(.5+m/d(bu,bu*bu));}h aI(h m){l G(.5+m*aX);}h cg(h T){h m=ai(T);l o(aI(m),aI(m+1.),b6(T-m));}h bl(d u){l O(u.x,u.y);}h bl(k u){l O(u.x,O(u.y,u.z));}h bl(F u){l O(O(u.x,u.y),O(u.z,u.w));}h aJ(d u){l Q(u.x,u.y);}h aJ(k u){l Q(u.x,Q(u.y,u.z));}h aJ(F u){l Q(Q(u.x,u.y),Q(u.z,u.w));}h aN(d u){l u.x+u.y;}h aN(k u){l u.x+u.y+u.z;}h bC(h a,h b){l A(a)<A(b)?a:b;}h aY(h x,h s){l A(x)-s;}h bv(h x,h s){l sign(x)*Q(0.,A(x)-s);}d cd(d u){h v=dot(u,u);l v>0.?u/a9(v):u;}h i(h ch,h ci,h x){l 1.-Y(A(x-ch)/ci);}h j(h bD,h cj,h x){l Y((x-bD)/(cj-bD));}h i(h a,h b,h e,h x){l O(j(a,b,x),j(e,b,x));}d am(h x){l d(sin(x),cos(x));}mat2 aj(h x){d u=am(radians(x));l mat2(u.y,u.x,-u.x,u.y);}h aO(d p){l G(atan(p.y,p.x)/bA);}d b0(d p,h B){l p*aj(360./B*(ai(aO(p)*B+1.5)-1.));}d ac(d c,h p,h s){l c+sin(c.yx*aH*p)*s;}d ac(d c,h t,h p,h s){l c+sin(c.yx*aH*p+t)*s;}h bm(h u,h C){l C-A(u-C);}d bm(d u,h C){u.x=bm(u.x,C);l u;}h ck(h x,h p,h v,h S){l x-p*clamp(ai(x/p+.5),v,S);}d bE(d c,d s){c.x+=ai(c.y*s.y)*(.5/s.x);l G(c)*s;}k bF(d c,h r){l k(c-=clamp(c,r,1.-r),M(c)/r);}k bF(d c,d s,h r){s=s.yx/bl(s);c*=s;l k(c-=clamp(c,d(r),s-r),M(c)/r);}h ah(d p){k q=G(p.xyx*.09153);q+=dot(q,q.yzx+19.19);l G((q.x+q.y)*q.z);}h ah(h p){p=G(p*.1031);p*=p+33.33;p*=p+p;l G(p);}k cA(h p){k av=G(k(p)*k(.1031,.1030,.0973));av+=dot(av,av.yzx+33.33);l G((av.xxy+av.yzz)*av.zyx);}d cf(d p){k av=G(k(p.xyx)*k(.1031,.1030,.0973));av+=dot(av,av.yzx+33.33);l G((av.xx+av.yz)*av.zy);}F cl(h p){F a0=G(F(p)*F(.1031,.1030,.0973,.1099));a0+=dot(a0,a0.wzxy+33.33);l G((a0.xxyz+a0.yzzw)*a0.zywx);}F cl(d p){F a0=G(F(p.xyxy)*F(.1031,.1030,.0973,.1099));a0+=dot(a0,a0.wzxy+33.33);l G((a0.xxyz+a0.yzzw)*a0.zywx);}h an(h x,h p){l ah(mod(x,p));}h cm(h x){h m;l o(ah(m=ai(x)),ah(m+1.),b6(x-m));}h W(h x,h p){h m;l o(an(m=ai(x),p),an(m+1.,p),x-m);}h an(d p,d s){l ah(mod(p,s));}h W(d p,d s){p*=s;d m=ai(p);p-=m;p*=p*(3.-2.*p);h cn=an(m+d(0,0),s);h co=an(m+d(0,1),s);h cp=an(m+d(1,1),s);h cq=an(m+d(1,0),s);l o(o(cn,cq,p.x),o(co,cp,p.x),p.y);}h D(d p,d a1,h aZ,h bc,Z bd){h aF=W(p,a1),aA=1.,tw=1.;for(Z m=0;m<bd;++m){p=G(p+aX);a1*=bc;aA*=aZ;aF+=W(p,a1)*aA;tw+=aA;}l aF/tw;}h D(h p,h a1,h aZ,h bc,Z bd){h aF=W(p*a1,a1),aA=1.,tw=1.;for(Z m=0;m<bd;++m){p=G(p+aX);a1*=bc;aA*=aZ;aF+=W(p*a1,a1)*aA;tw+=aA;}l aF/tw;}h bG(d p,d a1,h aZ,h bc,Z bd){h aF=a6(W(p,a1)),aA=1.,tw=1.;for(Z m=0;m<bd;++m){p=G(p+aX);a1*=bc;aA*=aZ;aF+=a6(W(p,a1))*aA;tw+=aA;}l aF/tw;}d aK(d p,d a,d b){d ab=b-a,ap=p-a;h t=Y(dot(ap,ab)/dot(ab,ab));l ab*t+a;}h cr(d c,d f){l dot(c,aj(90.)*aE(f));}h N(d p,d b){d f=A(p)-b;l O(Q(f.x,f.y),0.)+M(Q(f,0.));}h be(d p,d b){l aJ(A(p)-b);}h X(d p,h r){l M(p)-r;}h aK(d p,d a,d b,h r){l X(p-aK(p,a,b),r);}h bf(d p,d r){l X(p/r,1.)/O(r.x,r.y);}h a2(h a,h b){l Q(a,-b);}h b1(h a,h b,h L){h S=Y(.5+0.5*(b-a)/L);l o(b,a,S)-L*S*(1.-S);}d b2(h x){d f=d(dFdx(x),dFdy(x));l f/Q(M(f),1e-8);}h H(h s,h f){l Y(1.-s/f);}h H(h s){l Y(1.-s/fwidth(s));}F bH(d c,h s){l F(c/=s,a9(Y(1.-aV(c))),M(c)-1.);}h cs(k B){h v=aN(B.yz)*.7;l pow(Y(v),4.)+v;}h bI(d c,h s){c/=s;c.y+=.06;c.x*=2.;l j(.3,.0,M(c));}k aL(k e,d c,h s){F b=bH(c,s);e*=1.+cs(b.ae)*H(b.w)*.5;e*=1.-E(bI(c,20.*s))*(1.-H(b.w))*.3;l e;}h bh(d c,h t){c.x=A(c.x);c.y-=.07;h f=bf(c,d(.31,.12-t*.02))/50.;f=Q(f,-bf(c-d(0,.01+.01*t),d(.28+t*.01,.07))/75.);f=Q(f,-N(c-d(0,.1),d(.22-.02*t,.12)));f=Q(f,-N(c-d(0,.1),d(.084-.012*t,.31)));f=O(f,be(c-d(0,-.09),d(i(-.09,.32,c.y)*(.04-.015*t),.32)));f=O(f,be(c-d(.11-.02*t,-.21+.01*t),d(i(-.07,.3,c.y)*(.03-.01*t),.15)));l f;}h ct(d c){h f=X(c-d(0,.17),.32);f=a2(f,X(c-d(0,.235),.27));f=a2(f,X(c-d(0,.5),.15));c.y-=.09;d s=d(.09,.52);h S=Y(-c.y/s.y);s*=.5;s.x*=j(1.05,.6,S)+E(j(.1,.02,S));c.y+=s.y;f=O(f,N(c,s));l f;}k bJ(d p,h am,h cu){k J=k(-1,0,1),r=k(1e5);d a3=ai(p*am),cB=J.yy;p-=(a3+.5)/am;h ao=.5*an(a3+J.yy,d(am)),aP=.5*an(a3+J.xy,d(am)),aQ=.5*an(a3+J.yz,d(am)),aR=.5*an(a3+J.zy,d(am)),aS=.5*an(a3+J.yx,d(am)),bK=.5*an(a3+J.xz,d(am)),bL=.5*an(a3+J.zz,d(am)),bM=.5*an(a3+J.zx,d(am)),bN=.5*an(a3+J.xx,d(am));d[4]aB,v;V(mod(a3.x+a3.y,2.)<.5){v[0]=1.+d(aS-aP,ao-bN);v[1]=1.+d(aR-aS,ao-bM);v[2]=1.+d(aQ-aP,bK-ao);v[3]=1.+d(aR-aQ,bL-ao);aB[0]=d(aS,ao);aB[1]=d(aS,ao);aB[2]=d(aQ,ao);aB[3]=d(aQ,ao);}else{v[0]=1.+d(ao-bN,aP-aS);v[1]=1.+d(bM-ao,aR-aS);v[2]=1.+d(ao-bK,aQ-aP);v[3]=1.+d(bL-ao,aQ-aR);aB[0]=d(ao,aP);aB[1]=d(ao,aR);aB[2]=d(ao,aP);aB[3]=d(ao,aR);}for(Z m=0;m<4;m++){aB[m]+=v[m]*(d(m&1,m/2)-.5);v[m]/=am;h bx=be(p-aB[m]/am,v[m]/2.-cu/am);V(bx<r.x)r=k(bx,a3+aB[m]);}l r;}b7(bn,aN(A(r)))b7(b3,M(r))h aG(k p,h s){p=aE(p);k a=G(degrees(atan(p,p.yzx))/360.);l W(a.x*s,s)*j(.9,.0,A(p.z))+W(a.y*s,s)*j(.7,.0,A(p.x));}h aG(k p){l aG(p,45);}d cv(k p,Z ax){l(ax==0)?p.yz:(ax==1)?p.xz:p.xy;}Z cw(k B){B=A(B)+k(.01,.02,.03);h C=aJ(B);l(C==B.x)?0:(C==B.y)?1:2;}k cx(k e){k rgb=Y(A(mod(e.x*6.+k(0,4,2),6.)-3.)-1.);rgb*=rgb*(3.-2.*rgb);l e.z*o(k(1.),rgb,e.y);}k a4(){k f=Cam.ae-Pos;h b=D(f.xy/256.*aj(Cam.w),d(3),.7,3.,4),v=1.-j(14.,-6.,M(f.xy)-b*8.)*j(128.,48.,f.z)*step(.1,Nor.z);l ak(Texture1,LUV).ae*2.*v;}I(_8){h b=D(c,d(5),.9,3.,4);k e=o(n(48,41,33),n(103,101,104),b);l e;}I(_9){h b=D(c,d(3),.9,3.,4);k e=o(n(49,45,43),n(81,75,78),b*b);l e;}I(_10){h b=D(c,d(7),.9,3.,4);c.x*=-1.5;c.y+=c.x*.5;c.x=1.-c.x+c.y;c=G(c*28.);h T=Y(1.-M(.1-c));T*=j(.6,.2,M(.6-c));T*=j(.6,.8,M(.1-c));T*=j(.2,.6,b)*2.+1.;h v=1.-j(.2,b+2.,aJ(A(c-.5)));l k((T+1.)*o(.21,.29,b*b)*v);}I(_11){h b=D(c,d(7),.9,3.,4),r=M(c-.5);k e=_10(c);e=o(e,e*n(70,61,53),j(.5,.2,r+b*b*b));l e;}h bO(d c,h s){h f=1e6,m=0.;for(;m<5.;++m){d p=d(0,-s)*aj(m*72.);f=O(f,M(c-aK(c,p,p*aj(144.))));}l f;}al(_12){k e=_11(c);c=G(c)-.5;h b=D(c,d(3),.9,3.,4),f=O(A(M(c)-.4),bO(c,.35));l F(e,H(f-.02+b*.02,.01));}P _13(){F e=ak(af,R);K=F(e.ae*a4()+n(111,55,0)*e.w*(sin(U.x*aH)*.5+.5),1);}I(_70){h b=D(c,d(7),.9,3.,4);k e=_10(c);h r=M(c-.5);h C=j(.46,.45,r);h v=1.5-1.5*j(.0,.3,r*r);v=o(v,2.5,i(.42,.07,r));v=o(v,3.5,i(.44,.05,r));v=o(v,2.6,i(.36,.03,r));h B=.3+.2*j(.35,.30,r);v*=1.-B*j(.3,.7,b);v*=1.-.3*E(j(.13,.05,r));v=o(v,2.5,j(.04,.01,r));v-=v*i(.03,.01,r)*.7;e=o(e,n(68,66,54)*v,C);e*=1.-E(i(.34,.02,r));e*=1.-E(i(.46,.03,r));e*=1.-i(.41,.03,r)*.7;l e;}d cy(d c,h s){l d(1.-M(c)/s,H(M(c)-s));}al(_72){h b=D(c,d(5),.9,3.,4),t,ad,L,r;k e=_10(c);d a5,u;a5.x=A(c.x-.5);a5.y=O(c.y,.4);r=M(a5-d(0,.4))-(.18-.06*j(.4,1.,c.y));L=.25-.15*j(.9,.96,c.y)+.03*E(j(.82,.86,c.y))+.07*j(.8,.2,c.y)+.07*E(j(.35,.22,c.y))-.07*j(.22,.0,c.y);ad=N(c-d(.5,.5),d(L,.46));ad=Q(ad,-N(a5,d(.15,.03))+.06);e=o(e,k(.6,.55,.55)-c.y*.3+b*.2,H(ad));e*=1.-.7*i(.0,.013,ad);e*=1.-(r/.5-.1)*H(ad);t=Q(r,c.y-.96);ad=A(t-.02)-.03;ad=Q(ad,c.y-1.+a5.x*.5);ad=Q(ad,c.y-.96);e=o(e,k(1,1,.9)-c.y*.55,i(-.01,.01,ad));e=o(e,k(.2*b+.1),H(t,.01));e*=1.-.2*i(.0,.05,t)*H(ad);u=cy(a5=c-d(.5,.4),.02);e*=1.+n(111,80,70)*i(.03,.01,M(a5));e*=1.-.5*i(.02,.01,M(a5));e=o(e,n(111,66,44)*(u.x*1.5+.2),u.y);l F(e,H(t-.03,.02));}P _73(){F e=ak(af,R);d c=G(R);c.x=A(.5-c.x);h t=G(-U.x),r=M(c-d(0,.4)),v=t*pow(Q(0.,1.-r),4.)*e.w;V(t>.75)v+=j(.03,.01,A(G(c.y+c.x*.5+t*2.)-.45))*j(.1,.08,c.x);K=F(e.ae*a4()+n(180,150,5)*v,1);}I(_14){h b=D(c,d(5),.9,3.,4);k e=o(n(44,14,16),n(93,63,63),b*b);l e;}k bP(d c){h J=3e-3,a=0.;d g=d(6),r=bn(c,g).xy;for(Z m=0;m<9;++m)a+=aN(A(bn(d(m%3-1,m/3-1)*J+c,g).xy-r));l k(c+r.xy/g,a);}I(_15){h b=D(c,d(3),.9,3.,4);k e=o(n(80,70,72),n(128,120,120),b*b);k u=bP(c);e*=o(.95,1.1,W(u.xy,d(6)));e=o(e,n(168,128,120),j(.5,1.,u.z)*b*.7);l e;}al(_16){h b=D(c,d(3),.9,3.,4);k e=o(n(80,70,72),n(128,120,120),b*b);k u=bP(c);h C=j(.5,1.,u.z);h r=j(.4,.2,M(.5-G(u.xy)));e*=o(.95,1.1,W(u.xy,d(6)))-2.*r*b*b;e=o(e,n(168,128,120),C*b*.7);l F(e,C*r);}P _17(){F e=ak(af,R);K=F(e.ae*a4()+i(.5,.125,G(R.y*.5+U.x*.5))*e.w*.3,1);}I(_18){h b=D(c,d(5),.9,3.,4);k pt=bJ(c,8.,.31);k e=o(n(66,58,55),n(118,107,105),b);h v=1.-.5*j(.034,.036,pt.x);v=o(v,1.4,i(.033,.004,pt.x));l e*v;}h cz(d c){h b=W(c,d(64)),T=0.,f=1e6;for(;T<11.;++T)f=b1(f,A(M(.5-A(c-bB(T)))-o(.36,.29,aI(T+.7)))-o(.015,.03,b),.01);l f*1e2;}k bQ(d c){k s,p;for(Z m=0;m<3;++m){p=k(c,0);p[m]+=1e-4;s[m]=cz(p.xy);}l k(aE(s.xy-s.z),s.z);}I(_19){h b=D(c,d(5),.9,3.,4),v;k e=o(n(51,46,43),n(165,147,143),b*b),f=bQ(c);v=1.-.5*(f.y-f.x)*i(.5,3.,f.z)*j(1.,.0,f."
"z);l e*v*.8;}I(_20){h b=D(c,d(3),1.1,3.,4),v;k e=o(n(51,46,43),n(165,147,143),b*b),f=bQ(c);v=1.-.5*(f.y-f.x)*i(.5,3.,f.z)*j(1.,.0,f.z);l e*v;}I(_21){h b=D(c,d(5),.9,3.,4),v=.18*(.7+b*b);k g;c=ac(c,13.,.007);bj(g,c,E(j(.3+b*.2,.9,D(p[m],d(23),.5,2.,4))));l k(v*(1.-g.y*g.z));}I(_46){h b=D(c,d(5),.9,3.,4);k e=o(n(77,55,53),n(62,48,48),W(c,d(128,13)))*(.7+b*b),g;c=ac(c,13.,.007);bj(g,c,E(j(.4+b*.4,.95,W(p[m],d(63,43)))));e*=j(1.3,.9,g.z);l k(e*(1.+g.y*g.z));}h bR(d c,d s){c.y=Q(c.y,0.);l bf(c,s);}k bo(k e,k b,d c,h S,h s){h y=(c.y-S)/s,p=1.-y*y;e*=1.-i(-1.,1.,y);V(p>0.)e=b*(p*(.8+.2*i(.5,.25,G(c.x/s))))*(.7+E(i(.2,.7,y)));l e;}k c0(d c,h B){l k(B*B*.4);}I(_47){c.x*=.5;h b=D(c*d(2,1),d(3,5),.9,3.,4),B=.75+b*b,t=c.y+.2*O(.4,i(.5,.33,G(c.x*4.))),c1=bR(c-d(.25,.62),d(3,2)/32.),bi=bR(c-d(.25,.55),d(3,2)/48.),r;k e=o(n(66,50,51),n(111,66,44),a9(i(.31,.01,c.y))),au;d p=c,q;p.x=G(p.x*4.);V(c.y>.3)e=aL(e,d(4.*A(p.x-.5)-1.6,G(c.y*16.)-.5),.07);r=A(p.x-.5);e*=1.-.3*j(.31,.32,c.y)*j(.87,.86,c.y)*(j(.035,.03,.5-r)+i(.48,.01,r)-i(.46,.02,r));e=o(e*B,c0(c,b),Q(j(.31,.3,c.y),H(bi)));e*=j(1.5,.7,c.y);V(c.y<.306)e*=1.-i(.3,.05,c.y)*H(-bi+10.,20.);e*=1.-i(.316,.004,c.y)*H(-bi);V(c.y<.1)e*=.0;q=c;q.y+=i(.1,.01,mod(q.x,.33))/2e2;e=bo(e,2.*b*n(93,84,79),c,.185,.015);e=bo(e,2.*b*n(138,77,48),c,.13,.025);e=bo(e,2.*b*n(112,71,51),c,.09,.015);e=bo(e,2.*b*n(138,77,48),q,.05,.015);p.x=A(G(c.x*6.-.5)-.5)/6.;e*=1.+.5*j(.04,.03,p.x)*i(.18,.03,p.y);r=be(p-d(0,.12),d(.03,.01));r=a2(r,be(p-d(0,.11),d(.01)));e*=1.-E(i(.0,.04,r));e=o(e,n(166,99,77)*2.*b*(.75+.5*E(i(.125,.01,c.y))),H(r));q=p;q.y-=.07;r=X(q,.03);e*=1.-E(i(.0,.07,r));e=o(e,n(127,83,72)*b*2.*j(.01,-.005,r),j(.005,.0,r));q.y-=.004;r=X(q,.015);e*=E(j(-.01,.01,r));q.y+=.013;r=X(q,.05);e+=n(67,38,30)*4.*a9(b)*E(i(-.02,.015,r)*i(.023,.02,c.y));r=a2(c1,bi);r=a2(r,(c.y-.3)*3e2);e*=1.-.5*i(-2.,17.,bi)*j(.26,.3,c.y);au=n(67,39,17)*B;au=o(au,k(B*.2),i(0.,4.,r)*b);au*=1.-.4*pow(i(.0,3.,r),4.);au+=(au+.6)*a9(b)*E(i(-6.,8.,r)*i(.66,.04,c.y))*H(r);V(c.y<.56)au=aL(au,d(24.*A(c.x-.25)-1.85,G(c.y*24.+.5)-.5),.15);e=o(e,_46(c),j(.85,.9,t)+step(c.y,1./256.));e*=1.+i(.88,.015,t)-E(i(.87,.03,t));l o(e,au,j(1.,.1,r));}k c2(k e,k L,d c,Z w,Z S){h b=D(c,d(w,S),.5,2.,2);e*=.9-.3*j(.15,.1,A(b-.5));l o(e,L,i(.5,.1,b));}I(_52){c=ac(c,9.,.005);Z m=0,v[]=Z[](13,43,17,47,23,59,27,63);h b=D(c,d(19),.7,2.,4);k e=o(n(40,50,60),n(46,33,27),b)*(.5+b);for(;m<8;m+=2)e=c2(e,o(n(145,140,137),n(132,123,116),b),c,v[m],v[m+1]);l e;}k c3(k e,k L,d c,Z w,Z S){h b=D(c,d(w,S),.5,2.,2);e*=1.-.15*E(j(.15,.1,A(b-.5)));l o(e,L,i(.5,.1,b));}I(_59){h b=D(c,d(13),.9,3.,4),B=D(c,d(7),.9,3.,4);k e=o(n(111,66,55),n(80,55,52),E(j(.8,.2,B)))*(.8+.8*b*b),L=e;c=ac(c,13.,.01);Z m=0,v[]=Z[](13,43,17,47,23,59,27,63);b=D(c,d(19),.7,2.,4);for(;m<6;m+=2)e=c3(e,L,c,v[m],v[m+1]);l e;}k c4(k e,k L,d c,Z w,Z S){h b=D(c,d(w,S),.5,2.,1);e*=.9-.3*E(j(.15,.1,A(b-.5)));l o(e,L,i(.5,.1,b));}I(_41){h b=D(c,d(3,29),.9,2.,4),t=.8+.8*b*b,f=A(c.y-.61),ad=j(.25,.24,f),C;k e=n(140,127,127),L=e;d p=c;e*=1.-.1*j(.85,.86,c.y);e=t*o(e,n(110,55,50),j(.33,.32,c.y));p.y+=p.x*.11+b*.007;p.y=G(p.y*9.)-.5;C=j(.0,.1,A(p.y)-.2);Z m=0,v[]=Z[](3,29,5,37,9,63,27,63);for(;m<6;m+=2)e=o(e,c4(e,L,c,v[m],v[m+1]),C*ad);e*=1.+t*ad*(+.6*i(.1,.1,p.y)-.7*i(-.25,.3,p.y)-.5*i(.2,.1,p.y));e=o(e,n(99,66,51)*t,i(-.15,.1,p.y)*ad);e*=1.+i(.36,.005,c.y)+i(.34,.005,c.y)+i(.865,.005,c.y)+i(.89,.01,c.y)-.5*E(i(.245,.01,f))-.7*E(i(.35,.01,c.y))-.5*E(i(.325,.02,c.y))-.8*E(i(.875,.02,c.y))-.3*E(i(.9,.02,c.y));e*=.3+a9(a6(c.x));l e;}k bS(k e,d p,h s,h C){s=bn(p,d(s)).z/s*1e2;e*=1.+.5*C*j(.9,.2,s)-.5*C*i(2.5,.5,.3,s);l e;}k bT(k e,d c,h c5){h b=D(c,d(4,9),.9,3.,4),t=.8+.8*b*b,a,f,C,s,L,m,u,r,z;k aM=o(n(133,100,88),n(133,100,100),b)*t;d p,q;p=q=c;q.x=A(q.x);f=X(p,.31);u=aO(q);C=j(.01,.0,f);e=o(e*j(.0,.05,f+c5),k(.13*t),C);e=bS(e,p,37.,j(.04,.02,A(f+.07)));a=u*22.;m=ai(a);s=a-m;L=j(.23,.22,A(u-.25))+aI(m)*j(.0,.1,q.y);f-=r=(f*.3+.005)*L;C=j(.0,.1,q.y)*H(A(f+.015)-.015);e=o(e,aM,i(-.005,.01,f));e=o(e,n(130,75,44)*t,i(-.02,.005,f)*j(.0,.1,q.y));e*=1.-.3*j(.025,.03,-f)-.5*j(.4,.5,A(s-.5))*C+.2*i(.5,.3,A(s-.5))*C-.5*i(-.015,.007,f)-.5*i(-.03,.007,f)-.5*i(-.1,.005,f+r)-.5*i(-.115,.005,f+r)-.5*i(-.125,.015,f+r)-.5*i(-.145,.005,f+r)+.9*i(-.11,.007,f+r)+.5*i(-.14,.005,f+r)-b*i(.225,.005,A(u-.25))*H(A(f+.015)-.015);a=u*72.;m=ai(a);s=a-m;L=step(.7,ah(m))*step(q.y,.0)*j(.02,.0,A(f+.02));e=o(e,k(aM*.6),L*j(.4,.3,A(s-.5)));e*=1.-.7*L*i(.4,.1,A(s-.5));l e;}k b4(d c){h b=D(c,d(4,9),.9,3.,4),t=.8+.8*b*b,a,f,C,s,L,m,u,r,z;k aM=o(n(133,100,88),n(133,100,100),b)*t,e=k(.1*t);d p,q;p.x=c.x-.5;p.y=Q(c.y-.2,0.)*1.89;u=atan(p.y,A(p.x))/aH;f=X(p,.48);L=j(.3,.31,u);f*=1.-.2*j(.3,.31,u)-.1*j(.43,.44,u);a=u*(u>.44?2.:u>.3?63.:31.);e=o(e,aM,j(.03,.01,A(f)));C=H(A(f-.01)-.02);m=ai(a);s=a-m;V(u>.33&&u<.44)s=G(s+ah(m)*.6-.3);e*=1.-.5*C*i(.307,.01,u)-t*C*i(.5,.1+L*.2,s)+b*C*i(.52,.2+L*.2,s);e*=1.-.9*i(-.015,.015,f)-.5*i(.0,.01,f)-.7*i(.03,.02,f)+i(.01,.015,f);q=p;q.y-=.5;q.x=A(q.x)+.6;f=X(q,1.13);C=j(.03,.02,A(f))*j(.5,.6,q.y);e=o(e,aM*Y(1.-A(f-.015)/.03),C);e*=1.-.5*C*i(.005,.01,f)+.5*C*i(.017,.005,f);q.x=A(c.x-.5)-.35;q.y=c.y*9./4.-2.1;f=X(q,.13)*10.;a=aO(q)*49.;m=ai(a);s=a-m;u=j(.85,.9,ah(m));for(Z aC=0;aC<2;++aC,f+=.3){e=o(e,aM*(b*.5+.2),j(.09,.03,A(f)));e*=1.+.7*E(i(.01,.05,f));}p.y=(c.y-.7)*9./4.;f=X(p,.43);a=atan(p.y,A(p.x))/aH;a=Q(a,-.48);r=a;m=ai(a*=23.);s=a-m;L=aI(m)*.2-.1*j(.0,.1,-f);u=j(.1,.2,A(s-.5)-L);f+=u*.007;r=(1.-u)*E(i(.5,.3,r))*j(.25,.05,A(s-.5));f-=.17*r;C=i(.04,.0,-.4,f);e=o(e,aM*(b*.4+.4),C);e=bS(e,p,31.,j(.1,.05,A(f+.15))*u);e*=o(1.,1.-i(.1,.2,.4,A(s-.5)-L),C*b);e*=1.-.7*E(i(.03,.03,f))-.7*E(i(.03,.03,f+.05))*u-.7*E(i(.0,.02,f+.05))*u-.3*j(.04,.06,-f)*u+.5*i(.02,.0,-.1,f)+i(.0,.01+.07*r,f)+i(.0,.01,f+.03)*u;p.y-=.05;e=bT(e,p,0.);l e;}I(_42){c.y=(c.y+8.)/9.;l b4(c);}I(_43){c.y=(c.y*4.+4.)/9.;l b4(c);}I(_44){V(c.y<.01)++c.y;c.y=c.y*4./9.;l b4(c);}I(_54){h b=D(c,d(5),.9,3.,4),t=bG(ac(c,4.,.01),d(7),.5,3.,5),B=W(ac(c,4.,.05),d(9)),aD,J;k pt=bJ(c,4.,.1+B*t*.05),e;d f=b2(pt.x);aD=ah(G(pt.yz));e=n(74,65,62)*(.8+.8*b*b);e+=i(.6,.3,B)*j(.3,.9,b*t)*.2;e*=1.-i(.5,.4,B)*j(.5,.7,t)*.1;e=o(e,n(86,74,78),i(.5,.1,b)*i(.7,.3,aD)*.7);e=o(e,n(105,90,70),i(.3,.1,t)*i(.3,.3,aD)*.3);J=i(.015,.005+.015*B,pt.x)+i(.4,.1,B*t)*.4;e*=1.-b*j(.015,.05,pt.x)*.7;e*=1.+J*b*(f.y-.5)*.7;e*=.9+.2*aD;e*=.9+.2*a6(W(c-pt.yx,d(5)));l e;}I(_45){k e=_54(c);c-=.5;e=bT(e,c*.9,.02);l e;}k aT(d c){c*=1.5;h b=D(ac(c,7.,.02),d(9),.7,3.,2),t=b,B=W(c,d(13)),a,s,f;k e=_54(c);d p;p.x=A(c.x-.75);p.y=Q(c.y-.58,0.)*1.15;a=atan(p.x,p.y)/aH;s=G(a*7.+.5);f=X(p,.45);f-=.06*j(.4,.33,c.y);f-=.05*j(.15,.07,A(s-.5))*step(.63,c.y);f=a2(f,c.y-.107);V(c.y<.6)f=a2(f,A(p.x-.493)-.113);f=a2(f,X(p,.6)+.044*j(.48,.43,c.y));e=o(e,n(144,125,115)*t,H(f-.1,.005));e*=1.-.3*i(.12,.11,.1,f)+.5*i(.1,.005+.015*B*B,f);l e;}I(_32){l aT(d(5,0)/6.+c*d(1,4)/6.);}I(_33){l aT(d(1,0)/6.+c*d(4)/6.);}I(_34){l aT(c*d(1,4)/6.);}I(_35){l aT(d(5,4)/6.+c*d(1,2)/6.);}I(_36){l aT(d(1,4)/6.+c*d(4,2)/6.);}I(_37){l aT(d(0,4)/6.+c*d(1,2)/6.);}I(_55){h b=D(c,d(13,1),.7,2.,3);k e=_54(c)*.7;e*=1.-E(j(.4,1.,b));l e;}k bU(d c,d s){h b=D(c,d(5),.9,3.,4),B=D(c,d(31,3),.5,3.,3),t=.75+b*b;d p=c;k e=_54(c);V(c.y<.38)e=o(n(92,43,15),n(66,44,33),j(.1,.05,c.y))*t*(.5+.5*j(.0,.35,c.y));e+=b*s.y*E(i(.32,s.x*.015,c.y))+.3*b*i(.34,.05,c.y);e*=1.-i(.38,.005+b*b*.03,c.y)+3.*i(.15,.2,c.y)*(B-.5);l e;}I(_56){h b=D(c,d(5),.9,3.,4),t=.75+b*b,f,ad,m;d p=c;k e=bU(c,d(1));p.x=mod(p.x,1./7.)-.07;p.y-=.21;f=X(d(.75*p.x,bv(p.y,.1)),.033);ad=H(f,.005);f=X(d(.75*p.x,bv(p.y+.005,.09)),.033);m=H(f+.015);e=o(e,n(83,81,66)*t,(ad-m)*j(.1,.3,c.y));e*=1.-j(.17,.25,c.y)*m;e+=E(i(.0,.015,f))*i(.32,.03,c.y);e*=1.+3.*pow(i(-.01,.03,f),4.)*i(.09,.03,c.y);f=X(d(.75*p.x,bv(p.y+.03,.1)),.033);e*=1.-H(f+.01,.02)*(1.-ad);V(c.y>.09&&c.y<.3)e=aL(e,d((A(p.x)-.035)*36.,G(c.y*36.)-.5),.1);l e;}d c6(d p){p.x=A(p.x);d q=p,u;q.y-=.5;h f=X(q,.35),J,e;u=q/.35;q.y+=.25;q.x-=.15;f=O(f,N(q,d(.09,.05))-.1);J=bf(q,d(.15,.1))/5e1;e=.1+dot(d(u.y,a9(Y(1.-aV(u)))),d(.3,.3));q.y+=.2;q.x=p.x;e=Q(e,Y(.4-M(q)));e+=.15*i(.0,.1,J)-.1*H(J+.12,.15);f=O(f,N(q,d(.15-j(-.15,.15,q.y)*.07,.03))-.09);e*=1.-j(.05,.25,q.x)*j(.2,.1,A(q.y+.12));q.y-=.06;e-=.5*H(bf(q,d(.05-j(-.1,.1,q.y)*.03,.06))/1e3+.03,.05);l d(Y(e),H(f,.02));}"
"I(_57){h b=D(c,d(9),.7,2.,4),t=.75+b*b;k e=bU(c,d(4,.3));d p=c,s;p.x=mod(p.x,.2);p-=.1;s=c6(p*5.);l o(e,o(k(.5,.4,.3),k(.95,.8,.55),t)*t*s.x,s.y);}I(_53){d p=bE(c,d(8)),q=G(p),u=ac(c,31.,.002),aD=p-q;h b=D(ac(c,5.,.02),d(7),1.,3.,4),t=.8+.8*b*b,B=W(c+bB(ah(aD)*64.),d(23)),C=D(c,d(9),.7,3.,4),f=D(u,d(63),.7,3.,4),r=D(u-d(0,.002),d(63),.7,3.,4),v=f-r,J=bF(q,.03+.03*a6(B)).z,S=ah(aD);k e=o(n(91,61,42),n(70,30,15),J*b);e=o(e,n(70,48,35),j(.5,.6,C))*t;e*=1.+v*(.1+B+i(.6,.1,C))*(1.-J)-t*j(.7,1.,J)*W(c,d(13))+.5*b*i(.3,.3,J);f=D(u,d(23),.5,2.,4);e*=1.-.2*j(.6,.7,f)*S+.3*i(.6,.05,f)*S*B;e*=.9+.2*S*(1.-J);e*=.9+.4*pow(bG(c-ah(aD/8.),d(5),.6,2.,4),4.);l e;}al(_28){h b=D(c-=.5,d(5),.9,3.,4),t=.75+b*b,B=W(ac(c,7.,.02),d(17)),r=M(c),L=r>.4?38.:r>.32?28.:16.,a=G(atan(c.y,c.x)/bA),m=ai(a*L),a7=A(A(r-.41-B*.002)*1e2-6.),C=j(1.5,1.4,a7),b5[]=h[](1.,3.,-.145,-1.,2.,.166),f,bV,s;d p=c;k e=n(78,68,63);e*=1.+.5*E(i(.49,.005+.015*B*B+.015*b,r));e=o(e,n(83,52,47)*(.6+.4*B*B),C)*t;e*=1.-.5*i(1.5,.5,a7)+b*i(1.,.5+.5*B,A(r-.418)*1e2-5.)-b*i(.5,.08,G(a*L+.5))*C+b*i(.5,.1,G(a*L+.55))*C;C=j(.34,.33,r);e=o(e*(1.-.5*C),n(83,52,47)*t,B*b*C);e=o(e,n(112,86,31)*t,C*E(i(.1,.15,.45,b)));e=o(e,n(77,66,77)*t,C*j(.5,.8,b)*.5);e*=1.-.7*i(.27,.34,.35,r);a7=r+B*.004;C=r>.21&&r<.31?1.:0.;e*=1.-i(.325,.005,a7)-i(.31,.005,a7)-b*E(i(.29,.005,a7))-b*E(i(.23,.01,a7))-.5*E(i(.21,.02,a7))+E(i(.3,.01,a7))*b+E(i(.22,.01,a7))*b-b*i(.5,.07,G(a*L+.5))*C;V(r<.23)m+=37.;V(r<.31)m+=73.;V(r<.31)m+=91.;e*=o(1.,.9+.2*aI(m),C);C=j(.01,.0,A(r-.411)-.039);m=ai(a*72.);p*=aj(m*5.);s=0.;f=1e6;Z aC=0;for(;aC<6;aC+=3){f=bC(f,bV=dot(p,aE(d(b5[aC],b5[aC+1])))+b5[aC+2]);s+=s+h(bV>0.);}V(s==3.)++m;else m+=66.*s;m=aI(m);e=o(e,t*n(90,80,75),C);e=o(e,t*n(127,111,88),m*b*C);e*=o(1.,.7+.6*ah(m),C);e*=1.-C*E(i(.0,.006,f))*b+C*E(i(.006,.006,A(f)))*b*.5;m=ai(a*4.);p=A(c*aj(m*90.+45.));f=1e6;for(aC=0;aC<2;++aC,p=A(p*aj(45.)))f=bC(f,A(M(p-d(0,.12))-.16));C=j(.21,.2,r);a7=aY(aY(f,.012),.001);e*=1.-j(.21,.2,r)*H(.012-f)+b*C*E(i(.005,.005,f))-.5*C*E(H(a7-.001,.001));l F(e,(1.-j(.21,.15,r)*H(.028-f,.02))*j(.07,.087,r));}al(_29){d p=G(R)-.5;h b=D(aj(U.x*333.)*p/(.8+.2*sin(U.x*61.)),d(53),.7,2.,4);F e=F(1.-b*k(0,.3,1),1),au=ak(af,(aj(U.x*30.)*p/(.8+.2*sin(U.x*1.26)))+.5);e.ae=o(e.ae,au.ae,au.w);au=ak(af,R);e.ae=o(e.ae,au.ae,au.w)*a4();l e;}h c7(d p){p=b0(p,8.);h f=X(p,.41);f=O(f,N((p-d(.34,0))*aj(45.),d(.1)));f=Q(f,p.x-.45);l f;}I(_30){d p=c-.5,q;h b=D(c,d(9),.7,2.,4),t=.8+.8*b*b,r=X(p,.41),f=c7(p),v=dFdy(f)/.004,C=H(f+.01,.007),a=aO(p),J,B,x,z;k e=_54(c),L=n(155,135,115)*t;e*=1.-(.5*-v+.5)*j(.03,.0,f);e=o(e,L,C);J=M(p)*9.;q.x=a*ai(J+1.)*3.;q.y=G(J);B=i(.5,.2,W(ac(c,7.,.03),d(41)));B=D(q,d(3,9),.5,2.,4)*i(.5,.5+.5*B,q.y);e=o(e,n(100,85,80)*a6(B)*b,H(r+.15,.02));q=p;q.x=A(p.x);J=Q(Q(f,cr(q,-d(.08,.4))),A(r+.06)-.09);z=N(q-d(0,.3),d(.01,.03));J=a2(J,z-.02);x=H(-J,.01);e*=1.+v*C*j(.02,.0,-f)*j(.01,.0,-r)+x*i(.035,.015,-r)+.5*x*i(.13,.01,-r)+.7*i(.08,.007,z)*(1.-x)-.7*x*E(i(.01,.04,-r))-.6*x*E(i(.13,.06,.03,-r))-.5*x*E(i(.12,.02,-r))*C-.9*E(i(.12,.15,.2,-r))*C-.5*E(i(.0,.05,J));e+=k(.8,.8,1)*pow(Y(1.-M(c-d(.41,.59))/.35),8.);q.x=a;q.y=j(.05,.12,-r);J=bn(q,d(37,1)).z;C=i(.085,.035,-r)*x;e*=1.+.5*C*i(.0,.2,J)-.3*C*i(.3,.3,J);J=N(p+d(0,.33),d(.01,.03))-.03;v=dFdy(J)/.004;e=o(e,L*(.4+.8*j(.25,.41,-p.y)),z=H(J,.01));e*=1.+.7*i(.005,.01,J)*v-.5*i(.0,.01,.05,J);J=N(q=p+d(0,.35),d(.01,.015))-.01;v=dFdy(J)/.004;e*=1.+.5*i(.005,.01,J)-.5*E(i(.0,.01,J));e+=k(1,.7,.5)*pow(Y(1.-M(q)/.11),8.);l e;}P _31(){k e=ak(af,R).ae*a4();d c=G(R)-.5,p=c;h t=mod(U.x*2.,7.),m=ai(t),f=1e6;V(m==0.)f=ct(p*2.4+d(0,.05));V(m==1.){p.x=ck(p.x,.1,-1.,1.);f=N(p,d(.02,.15))*2.;}V(m==2.){f=O(f,N(bm(p,.0)+d(.13-j(-.3,.3,c.y)*.17,0),d(.02,.15)));f=O(f,N(p+d(0,.07),d(.07,.02)))*2.;}V(m==4.)f=bh(p*1.8,.5);else f=aY(f,.005);K=F(e+H(f,.02)*G(-t)*k(.5,.05,.05),1);}I(_58){h b=D(c,d(13),.9,3.,4),B=D(c,d(7),.9,3.,4);k e=o(n(60,50,50),n(87,47,37),E(j(.7,.25,B)))*(.7+.8*b*b),g;c=ac(c,31.,.003);bj(g,c,a9(j(.0,.9,W(p[m],d(93)))));e*=1.-(g.y+.4)*E(b*g.z)*g.z;l e;}I(_62){h b=D(c,d(5),.9,3.,4);k e=n(67,64,63)*(.6+.5*b),g;c=ac(c,31.,.003);bj(g,c,a9(W(p[m],d(53,93))));e*=1.-.3*g.y*g.z*g.z;l e;}al(_22){c=ac(c,7.,.01);h b=D(c,d(9),.7,2.,4),B=D(c,d(13),.5,2.,4),C=j(.6,.9,D(ac(c,5.,.03),d(11),.6,2.,4));k e=n(127,70,55)*(.85+.3*b);e*=1.-.2*E(j(.3,.0,b*b))-.2*C-.3*j(.6,.77,B)+.3*j(.5,.9,b);e+=.5*E(j(.5,1.,D(c,d(17),1.,2.,3)));l F(e,1.-C);}P _24(){F e=ak(af,R);d c=G(R);c.y-=.2*U.x;h b=D(ac(c,7.,.02),d(5),.9,2.,4);K=F(o(n(25,10,8)*b,e.ae,e.w)*a4(),1);}I(_23){d p=c-.5;p=ac(p,17.,.007);p.x*=2.-c.y*1.5;h b=D(c,d(9),.7,2.,4),B=W(c,d(7)),f=M(p),s;k e=_22(c).ae;s=G(f*=13.);V(f<=6.){e*=1.-pow(j(6.,.5,f+b*b),6.);B=j(.3,.7,B);e*=1.-B*b*i(.4,.2,s)+B*b*i(.6,.4,s);}l e;}I(_25){c=ac(c,13.,.003);h b=D(c,d(7),.9,3.,4),B=D(c,d(5),.5,2.,4),t=.5+b;k e=n(80,38,34),u=b3(c,d(23));e=o(e,o(n(180,125,118),n(165,78,51),B),b*i(.0,.4+B*.4,u.z))*t;l e;}I(_26){h b=D(c,d(7),.9,3.,4),t=.8+.4*b,m,r=.7,v,C;k e,u=b3(c,d(23));d p=u.xy/r,q=c+u.xy/23.;m=ah(G(q)*3.3);e=o(n(155,55,55),n(200,166,155),j(.75,.45,q.y))*t;C=i(.5,.5,M(p));v=dot(d(-p.y,a9(Y(1.-aV(p)))),d(.6+m*.3,.3));e*=1.-b*.8*j(.5,.1,u.z)+b*C*v;e*=t*t*t*t;l e;}I(_27){h b=D(c,d(13),.9,3.,4),t=.4+b*b,B=a6(W(ac(c,12.,.02),d(48))),m,r,v,C;k e=n(60,50,46)*t,u=b3(c,d(17));m=ah(G(c+u.xy/17.));r=.4+.3*m;d p=u.xy/r;C=O(j(1.1,1.,M(p)),j(.0,.15,u.z));v=dot(d(-p.y,a9(Y(1.-aV(p)))),d(.1+m*.2,.3));e+=b*C*v*B;B=a6(D(ac(c,13.,.01),d(23,43),.5,2.,3));e*=1.+(1.-C)*i(.4,.4,B);l e;}I(_60){h b=D(c,d(7),.9,3.,4),B=D(c,d(3),.5,3.,4);k e=o(n(103,56,53),n(73,58,71),j(.1,.7,B))*(.75+b*b);l e;}I(_61){h b=D(c,d(13),.9,3.,4),B=W(ac(c,5.,.05),d(9)),f=a6(G(c.x*4.)),C=j(.1,.15,f)*j(1.,.99,c.y);k e=n(51,44,44);e=o(e,n(73,55,52),j(.2,.2,b)*B*C);e=o(e,n(69,60,66),j(.7,.1,b)*b*C);e=o(e,n(99,77,77),j(.1,.5,B)*B*C*b*b*.3);e*=.6+.3*b+.3*b*b;e*=1.+.9*E(i(.21,.02+.1*B,f+b*.05))*C*b;e*=1.-E(j(.49,.5,A(c.y-.5)));e*=1.-j(.05,.2,f)*j(.16,.1,f);e*=1.+i(.99,.007,c.y);l aL(e,d(f-.4,G(c.y*8.)-.5),.07);}k bW(d c,h s){h b=D(c,d(3,1.+s+s),.7,2.,4),f=a6(c.x),C;c.y*=2.;k e=o(n(71,60,58),n(110,88,77),j(.1,.05,f))*(.7+.6*b);e*=1.-j(.05,.0,c.x)*(1.-b*b);e*=1.+.5*i(.05,.02,c.x);d p=d(f-.35,G(c.y*s)-.5);F L=bH(p,.11);C=H(L.w);e*=1.-.7*bI(p,1.1)*(1.-C);e=o(e,(L.y>.0?n(128,105,88):n(200,111,66)*j(-.2,.7,L.z))*(.4+2.*b*pow(Y(aN(L.yz*.7)),4.))*(1.-.6*i(-.1,.4,L.y)),C);l e;}I(_38){l bW(c,4.);}I(_39){l _38(c.yx);}I(_40){l bW(c,1.);}I(_48){h b=D(c,d(40,5),.9,3.,4);k e=n(110,110,98)*(.8+.8*b*b);V(c.y<1./4.)e*=.5;e*=1.-.4*j(.4,.0,b)+.5*j(.02,.0,c.y)+.2*i(.24,.01,c.y);l e;}I(_49){d p=c,q;p.y*=22.;q=G(p);h b=D(c,d(3,23),1.,2.,6),B=D(c,d(3,33),.7,3.,4),aD=ah(p.y-q.y);k e=n(92,67,53)*(.8+.8*b*b);e*=1.-E(j(.1,.0,O(q.y,1.-q.y)))*b;e*=1.-.2*smoothstep(.3,.7,B);e*=.8+.3*b*aD;l e;}I(_50){h b=D(c,d(13),.9,3.,4),x=c.x*16./3.;k e=_49(c)*j(.15,.21,c.x);V(x<1.)e=n(59,48,49)*(.7+.6*b);e*=1.+.5*i(.05,.05,a6(x));l aL(e,d(A(c.x-3./32.)-.07,mod(c.y,.1)-.05),.004);}I(_51){d p=bE(c,d(6,4)),q=G(p),a5=q;h b=D(ac(c-=.5,5.,.03),d(13),.9,2.,3),B=W(c,d(73,7)),t=(.75+b*b)*(.8+.4*cg(c.x*93.)),r;k e=k(.25*t);a5.y+=a5.y*2.-.01-.03*B;r=M(a5-=clamp(a5,d(.49,.5),d(.51,3)));e*=1.-.7*b*E(j(.07,.03,A(r-.5)))+.5*b*i(.35,.1,r)*E(j(.2,.1,q.y))-.3*E(j(.8,1.,q.y))-.3*(j(.3,.1,q.y))*j(.4,.6,r)+.2*E(j(.5,.1,q.y))*j(.45,.4,r);l e;}I(_64){h b=D(c,d(5),.9,3.,4),S=G(c.y*10.);k e=o(n(53,48,42),n(38,38,36),b)*(.6+b*.8);e*=1.+.5*E(i(.25,.25,S))+.5*E(i(.65,.35,S))-.6*E(i(.5,.5,S));l e;}I(_63){h b=D(c,d(7,3),.9,3.,4),S=c.y+b*.04;k e=o(n(50,40,34),n(93,92,88),b*b);e*=1.+.9*j(.07,.04,A(c.y-.44))-.4*j(.08,.05,A(c.y-.7))-.5*i(.34,.05,c.y)-.3*i(.7,.04,c.y)+.7*i(.01,.03,c.y)+1.5*i(.89,.1,S)+1.3*i(.5,.04,S)+.9*i(.18,.04,S);l e;}I(_65){h b=D(c,d(5,3),.9,3.,4);k e=o(n(74,66,55),n(99,90,78),b*b);c.x*=2.;d p=aK(c,d(.5,.625),d(1.5,.625));h f=M(p-c),C=j(.22,.20,f),v=1.-.15*C-.5*j(.7,.9,c.y)*C-.3*(b2(f).y-.5)*i(.2,.03,f)-.3*E(i(.17,.03,f))-.5*j(.05,0.,c.y)-.3*i(.33,.05,c.y)+.7*j(.93,1.,c.y)+.7*i(.31,.04,c.y);l e*v;}al(_66){h b=D(c,d(1,5),.4,3.,4);k e=o(n(56,49,43),n(142,136,136),b);c=.5-A(c-.5);c.y*=4.;h a=i(.0,.1,M(c-aK(c,d(.41,.5),d(.42,3.5)))),f=bl(c),v=1.-.7*Q(0.,1.-f/.15);v*=1.-.8*j(.24,.31,O(f,c.y-.1));e+=n(80,80,20)*a;l F(e*o(v,2.7,a),a);}al(_69){h b=D(c,d(1,5),.4,3.,4);k e=o(n(56,49,43),n(142,"
"136,136),b);c=.5-A(c-.5);c.y*=8.;h f=M(c-aK(c,d(.27,.3),d(.27,7.7))),a=i(.0,.17,f),v=1.-.5*i(.17,.07,f);e+=n(80,80,20)*a;l F(e*o(v,2.7,a),a);}al(_67){d p=A(c-.5);h b=D(c,d(1),.4,3.,4),r=M(p),a=j(.37,.33,r)*(.5+2.*b),v=1.+.0*j(.08,.03,A(r-.41));k e=o(n(56,49,43),n(142,136,136),b);v=o(v,7.,j(.44,.1*b,r));v*=1.-.5*E(i(.46,.04,r));v*=1.-.4*E(i(.36,.04,r));l F(e*v,a);}al(_68){h b=D(c,d(5),.9,3.,4),f=b1(bO(c-=.5,.35),A(X(c,.4)),.02),a=pow(H(f-.02,.15),8.),ad=O(Q(N(c,d(.46)),-X(c,.51)),A(X(c,.44)));k e=n(76,62,47)*(.8+.8*b*b);e*=1.+(b+.5)*H(A(ad)-.01,.01);e*=1.-j(.1,.05,f)*H(X(c,.4));l F(e+1.*k(1,1,.3)*a,a);}al(_1){c-=d(.48,.5);h f=bh(c,0.),b=M(c)-.47;k e=1.-k(.5,1,1)*H(Q(.007-f,b+.04));l F(e,1)*H(b);}I(_2){c-=.5;d r=d(dFdx(c.x),dFdy(c.y));c/=r/aJ(r);c*=.8;c.y-=.03;h x=A(c.x),b=D(c,d(31,5),.7,2.,3),t=.8+.8*b*b,f=bh(c,1.),J=bh(c+d(0,.002),1.),v=(J-f)*5e2+.5;k e=k(.3*t,0,0)*H(f,.004);e*=1.-E(j(.0,.3,x))-.5*j(.1,.3,A(c.y-.1));e+=+t*.2*i(.0,.01-.01*x,f)*i(.1,.2,c.y)*j(.3,.2,x)*v+t*.5*j(.004,.0,f)*j(.07,.1,c.y)*i(.23,.1,x)*k(.9,.9,1)+t*.4*i(.005,.005,f)*j(.2,-.1,c.y)*j(.3,.2,x)*Y(-v);l e;}h bX(d c,h s,h m,h c8){m=(c.y-E(A(c.x-.5))*c8)*s-m;l 2.*i(.5,.4,m)*(G(m)-.5);}al(_78){h b=D(c,d(5,9),.9,3.,4),t=.8+.8*b*b,B=D(c,d(5,9),.9,3.,2),x=A(c.x-.5),f;k e=n(77,60,44)*t;d p=c*d(1,2)-d(.5,.7);e*=1.-.55*H(a2(X(p,.3),bh(aj(45.)*p*.8,0.)-.01));e*=1.+E(j(.6,.9,b))+i(.2,.5,c.y)*i(.2,.3,x)*bX(c,4.,.2,4.);for(h T=6.;T<9.;++T)e*=1.+i(.8,.5,c.y)*i(.2,.3,x)*bX(c,12.,T,1.);f=c.y-.81-E(Y(x*4.))*.09;e=o(e,n(82,66,60)*t,j(.0,.01,f));e*=1.-.5*(i(.01,.02,f))+.5*(i(.02,.01,f));f=.15*(1.-c.y);f=N(c-.5,d(.49)-f)+B*.1*a9(1.-c.y)-f;l F(e*E(H(f+.01,.05)),H(f));}al(_79){F e=ak(af,c);V(e.w<.5)discard;e.ae*=E(a4()*.5);l e;}F aU(k p,h s){p*=s/h(textureSize(af,0).x);k B=Nor*Nor;F e=F(0);for(Z m=0;m<3;++m,p=p.yzx)e+=ak(af,p.yz)*B[m];l e/aN(B);}F aU(h s){l aU(Pos,s);}P _80(){k B=Nor*Nor;K=aU(4.)*(Clr+.5*B.z*B.z*sign(Nor.z))*1.5;}P _81(){_80();}P _96(){K=aU(16.)*(aE(WNor).z*.5+.5)*F(1,.95,.9,1);K+=2.*pow(Y(aE(Nor).z),o(2.,8.,K.y))*E(K);}P _97(){K=F((aG(Ref,15.)*1.4+.3)*U.yzw,1);}P _98(){k r=Ref;h s=17.;V(U.y<1.){s=9.;mat2 a=aj(U.x*90.);r.xy*=a;r.yz*=a;}s=aG(r,s);K=F(E(j(.1,.9,s))*1.5*G(U.yzw)+.5*E(j(.9,1.,s)),0);}h c9(h b,h a,h T,h p){l(A(G(U.x*T+p-.25)-.5)*4.-1.)*a+b;}P _99(){k r=Ref;mat2 a=aj(U.x*90.);r.xy*=a;r.yz*=a;K=aG(r,22.)*Y(c9(-.3,1.3,.3,0.))*F(.3,.55,.25,0);}P _100(){k B=aE(Nor),p=Pos;p.z-=24.;h J=i((D(Pos.y/48.+U.x*7.4,13.,.6,2.,4)-.5)*.15,.03,G(j(-8.,32.,Pos.z)-U.x*1.3)-.5);K=F((aU(16.).ae*(B.z*.5+.5)*(.2+.8*j(4.5,6.5,M(p)))+J*J)*U.yzw*2.,1);}h bY(h e,h s,h x){h a=Q(fwidth(x)*2./s,1.);l i(e,s*a,x)/a;}P _82(){_80();k p=Pos,q;p.y=A(p.y);q=p-k(7,3.5,-21);q.z*=1.3;h r=M(q);K.ae*=1.+Y(p.z+30.)*j(4.,5.,M(p.xy))+.5*Y(p.z+15.)+.3*i(3.,.5,r)+.7*bY(-15.,.5,p.z)-bY(-14.5,.5,p.z)-j(3.,2.5,r)*(.6+.4*q.z/r);q=p-k(8,0,-23);q.z*=.7;r=M(q);K.ae*=1.-j(2.,1.,r)*(.6+.4*q.z/r);}al(_83){c*=d(256,64);c.y+=2.;h f=X(c-d(81,30),11.);f=Q(f,c.x-80.);f=Q(f,-X(c-d(84,26),9.));f=O(f,N(c-d(73,37),d(4,9))-4.);f=Q(f,-N(c-d(73,37),d(0,7))+1.);f=O(f,N(c-d(91.5,47),d(4,19))-4.);f=Q(f,-N(c-d(91.5,47),d(0,17.5))+1.);f=O(f,N(bm(c,111.)-d(105.+j(23.,50.,c.y)*3.,43),d(3.5,19)));f=O(f,N(c-d(111,32),d(4,3)));f=O(f,N(c-d(126,37),d(3,13)));f=O(f,N(c-d(125.5+j(23.,50.,c.y)*10.,44),d(3.5,6)));f=O(f,N(c-d(136.5-j(23.,50.,c.y)*9.,32),d(3.5,8)));f=O(f,N(c-d(148.5,37),d(7,13)));f=Q(f,-N(c-d(155,33),d(6,3)));f=Q(f,-N(c-d(155,43),d(6,2)));f=O(f,N(c-d(168,37),d(3.5,13)));f=O(f,N(c-d(178.,37),d(3.5,13)));f=O(f,N(c-d(188,37),d(3.5,13)));f=Q(f,c.y-50.);l F(H(f,.8),0,0,ah(c*511.));}P _84(){k e=ak(af,R*2.).ae*step(.5,G(U.x*.5));e=o(e*a4(),k(.5,0,0),i(G(U.x*2.),1./64.,G(R.y)));K=F(e+aG(Ref)*.25+ak(af,R+ah(U.xx)).w*.1,1);}P _85(){d c=G(R);c.x+=U.x/13.;h b=D(c,d(3,7),.9,2.,4),T=c.y;K=F(2.*n(95,85,80)*T*T*T*T*o(1.,b,.5),0.);}P _86(){K=F(aG(Ref)*n(133,111,111),0);}h star(d p,d e,h s){p-=e;h a=j(.3,.5,A(G(aO(p/=s)*8.+ah(e))-.5));l j(.9,.6,pow(aV(p),.0625)-a*a*.006);}P _87(){K=F(2,2,2,0)*pow(star(R,d(.5),1.),2.);}h bZ(d c,h s){d p=c;p.y+=p.y-U.x*s;c.x+=(cm(p.y*5.)-.5)*1.5*E(c.y);h B=D(ac(p,7.,.02),d(9),.7,2.,4),S=j(.9,.03,c.y),b=N(c-d(.5,.15),d(0,.3));l E(H(b+B*E(1.2-S)-.13,.15));}P ca(h s){d c=G(R);K=(bZ(c,s*.6)+bZ(c,s))*F(2.5,1,.35,0);}P _88(){ca(2.5);}P _89(){ca(1.);}P _0(){h v=dot(Nor,aE(k(2,0,8)));v=v*.4+.7;d c=cv(Pos,cw(Nor));k e=k(.5);e*=cx(k(G(aX*U.w+.25),1.,1.));K=F(e*v,1);}P _6(){F e=ak(af,R);K=F(e.ae*o(a4(),k(1),e.w),1);}P _71(){F e=ak(af,R);h r=M(G(R)-.5);h s=o(.4,8.,G(U.x*1.5));K=F(e.ae*a4()+n(240,130,5)*i(.1,.05,r/s)*j(.37,.32,r),1);}P _5(){k e=ak(af,R).ae;K=F(e*a4(),1);}P _7(){F e=ak(af,R);e.ae*=1.+e.w*aG(Ref);K=F(e.ae*a4(),1);}P _74(){K=F(0);}P _75(){k f=aE(Pos-Cam.ae);f.z=f.z*4.+2.;d c=aE(f).xy*2.;h b=j(.2,1.,D(c-U.x*d(.1,.2),d(5),.5,2.,6));c.y*=1.5;h s=j(.3,1.,D(c-U.x*d(.1,.18),d(5),.6,2.,6));K=F(k(b,0,0)+n(80,30,8)*s*s*2.,1);}P _76(){d c=ac(R/8.,U.x*.5,2.,.05);h b=D(c,d(7),.9,2.,4);k e=n(91,22,14)*(.2+1.6*b);e=o(e,n(144,44,0),i(.6,.2,D(c,d(3),.7,3.,4)));e=o(e,n(244,144,66)*b*2.,E(i(.55,.25,D(c,d(11),.5,2.,4))));K=F(e*Y(aJ(a4())),1);}P _77(){_76();}P _3(){K=ak(af,(.5+R*127.)/128.,2.5);K.ae*=.7+.3*W(R,.5/fwidth(R));}P _4(){K=ak(af,R)*Clr;}al(_90){c.y*=2.;h b=D(c,d(5),.9,2.,4),L=.5+b,t=.8+b*.4,f=c.y-1.05;k e=n(55,44,37)*t;d p=c;f=b1(f,N((c-d(.5,1.5))*aj(45.),d(.2))-.1,.3);f=Q(f,.03-p.y);e=o(e,aL(e,c-d(.5,1.5),.1),8.*b);p.x=O(p.x,1.-p.x);V(p.y>.5)p.y-=.5;e=o(e,aL(e,p-d(.22,.31),.04),2.*t);e*=1.+E(j(.5,1.,b))+b2(f).y*i(.0,.05,f)*(1.+11.*j(1.5,2.,c.y))*b+L*i(.93,.05,c.y)+L*i(.4,.05,c.y)+L*i(.1,.05,c.y)-.5*i(.97,.05,c.y)-.5*E(i(.7,.05,c.y))-.5*E(i(.2,.05,c.y))-.5*i(.66,.1,c.y)-.5*i(.45,.03,c.y)-.5*i(.15,.1,c.y)-i(.01,.03,c.y);l F(e,H(f,.03));}P _91(){K=ak(af,R);V(K.w<0.5)discard;K*=Clr*1.5+.3;}P _92(){d c=d(aO(Pos.xy),j(8.,128.,Pos.z));c.x=G(c.x*3.-U.x*2.2);c.y*=4.;h T=star(c,d(0,.3),1.)+star(c,d(1,.3),1.)+star(c,d(.5,.4),1.5);T*=T;K=F(T,T,T,0);}al(_93){h b=D(ac(c,5.,.03),d(7),.5,3.,2);l(b*1.4+.3)*F(1.2,.54,.06,0)+.5*i(.7,.2,b)*F(1,1,1,0);}P _94(){k p=Pos;p-=U.x*6.4*sign(p.z-72.);K=aU(p,8.);}I(_95){c=ac(c,5.,.02);h b=D(c,d(6),.8,2.,4),C=D(c,d(2),.6,2.,4),t=.8+.3*b*b;k e=o(n(36,33,30),n(168,177,168),.3+.7*C)*t;l e;}P _101(){d c=b0(R-.5,4.);K=F(1,1,0,1)*H(O(aY(M(c)-.4,.04),N(c,d(.25,.06))),.01);}P _102(){K=F(.4,.7,.3,1)*H(dot(A(R-.5),d(4,3)/5.)-.2,.01);}P _103(){d c=R;h f=N(c-d(.35,.5),d(.1,.4));c.y=mod(c.y-.06,.28)-.16;f=O(f,N(c-d(.51,0),d(.34,.04*j(.85,.7,c.x))));f=a2(f,N(c-d(.65,0),d(.02,1)));K=F(1,1,0,1)*H(f,.01);}P _104(){d c=R;c.x=mod(c.x,.33)-.16;h f=N(c-d(0,.52),d(.1,.4));f=a2(f,N(c-d(0,.65),d(.05,.23)));f=a2(f,A(c.y-.2)-.02);K=F(1,.5,0,1)*H(f,.01);}P _105(){d c=(R-d(.55,.45))*aj(-45.);h f=aK(c,d(-.4,0),d(.2,0),.1);f=Q(f,-.3-c.x);c.y=A(c.y);f=O(f,N(c+d(.37,0),d(.05,.005)));f=O(f,N(c+d(c.y+.1,-.18),d(.1,.05)));K=F(1,0,0,1)*H(f,.01);}P _106(){d c=(R-.5)*aj(45.);h f=N(c,d(.6,.03)),p=c.x*12.6+1.55,S=sin(p)*.15,q=a6(G(S));f=O(f,Q(aY(c.y-S,.05-.1*q)*(1.+q+q),A(c.x)-.6));K=F(0,1,0,1)*H(f,.01);}P _107(){d c=b0(R-.5,5.);h f=M(c)-.18,r=c.x-.33,S=.04*i(.0,.3,r);c.x-=.33;c*=aj(-15.);f=O(f,N(c,d(.04,2.*S)));f=O(f,N(c-d(0,S*sign(r)),d(.14,S)));K=F(.77,0,1,1)*H(f+.01,.01);}"
;

// src/demo/data/shaders/vertex_shaders.glsl: 4505 => 2201 (48.9%)
static constexpr char g_vertex_shaders[] =
"#define c void\n"
"#define f vec4\n"
"#define j gl_Position\n"
"#define l location\n"
"#define n normalize\n"
"uniform mat4 MVP,View,World;uniform f Time,Cam;layout(l=0)in f e;layout(l=1)in f k;layout(l=2)in vec3 h;layout(l=3)in f o;out vec3 Pos,Nor,WNor,Ref;out vec2 UV,LUV;out f Clr;c d(){j=e;UV=e.xy*.5+.5;}c m(float v,float A,float B){j+=A*MVP*f(h,0)*sin(6.28*(Time.x*B+dot(e.xyz/v,vec3(1))));}c _0(){j=MVP*e;Pos=e.xyz;Nor=h;UV=k.xy;LUV=k.zw;Clr=o;Ref=n(reflect((e-Cam).xyz,h));}c i(){_0();Pos=floor(h)/4.;Nor=fract(h)*4.-2.;Ref=n(reflect((e-Cam).xyz,Nor));float a=k.z,u=cos(a),s=sin(a);Nor.xy*=mat2(u,s,-s,u);}c _1(){d();}c _2(){d();}c _3(){d();}c _4(){j=f(2.*e.x-1.,1.-2.*e.y,1,1);UV=k.xy;Clr=o;}c _5(){_0();}c _6(){_0();}c _7(){_0();}c _8(){d();}c _9(){d();}c _10(){d();}c _11(){d();}c _12(){d();}c _13(){_0();}c _14(){d();}c _15(){d();}c _16(){d();}c _17(){_0();}c _18(){d();}c _19(){d();}c _20(){d();}c _21(){d();}c _22(){d();}c _23(){d();}c _24(){_0();}c _25(){d();}c _26(){d();}c _27(){d();}c _28(){d();}c _29(){_0();}c _30(){d();}c _31(){_0();}c _32(){d();}c _33(){d();}c _34(){d();}c _35(){d();}c _36(){d();}c _37(){d();}c _38(){d();}c _39(){d();}c _40(){d();}c _41(){d();}c _42(){d();}c _43(){d();}c _44(){d();}c _45(){d();}c _46(){d();}c _47(){d();}c _48(){d();}c _49(){d();}c _50(){d();}c _51(){d();}c _52(){d();}c _53(){d();}c _54(){d();}c _55(){d();}c _56(){d();}c _57(){d();}c _58(){d();}c _59(){d();}c _60(){d();}c _61(){d();}c _62(){d();}c _63(){d();}c _64(){d();}c _65(){d();}c _66(){d();}c _67(){d();}c _68(){d();}c _69(){d();}c _70(){d();}c _71(){_0();}c _72(){d();}c _73(){_0();}c _74(){_0();}c _75(){_0();}c _76(){_0();m(100.,3.,.1);}c _77(){_0();}c _78(){d();}c _79(){_0();m(30.,3.,.2);m(100.,3.,.7);}c _80(){i();}c _81(){i();}c _82(){i();}c _83(){d();}c _84(){_0();}c _85(){_0();}c _86(){i();}c _87(){_0();j+=MVP*f(Nor*mat3(View),0);}c _88(){_0();}c _89(){_0();}c _90(){d();}c _91(){_80();}c _92(){i();}c _93(){d();}c _94(){i();}c _95(){d();}c _96(){_0();WNor=n(mat3(World)*h);Ref=n(reflect((World*e-Cam).xyz,WNor));}c _97(){_96();}c _98(){_96();}c _99(){_96();j+=MVP*f(h+h,0);}c _100(){_96();}c _101(){d();}c _102(){d();}c _103(){d();}c _104(){d();}c _105(){d();}c _106(){d();}c _107(){d();}"
;

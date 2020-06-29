#pragma once

// auto-generated, do not modify
static_assert(0xe8b3ab4cU == Demo::Shader::Version, "Shader definition mismatch, please recompile the shader compiler & shaders");

// src/demo/data/shaders/fragment_shaders.glsl: 74659 => 30428 (40.8%)
static constexpr char g_fragment_shaders[] =
"#define d vec2\n"
"#define h float\n"
"#define k vec3\n"
"#define l return\n"
"#define o mix\n"
"#define C abs\n"
"#define F vec4\n"
"#define G fract\n"
"#define L length\n"
"#define M max\n"
"#define N min\n"
"#define Q void\n"
"#define S UV\n"
"#define Y if\n"
"#define ac int\n"
"#define ad xyz\n"
"#define ae Time\n"
"#define ah floor\n"
"#define ai Texture0\n"
"#define aj texture\n"
"#define a7 sqrt\n"
"#define aK normalize\n"
"#define b3(x)((x)*(x)*(3.-2.*(x)))\n"
"#define E(x)((x)*(x))\n"
"#define aR(x)dot(x,x)\n"
"#define W(x)clamp(x,0.,1.)\n"
"#define n(r,g,b)(k(r,g,b)/255.)\n"
"#define a5(u)i(.5,.5,u)\n"
"#define H(a6)k a6(d);Q a6(){O=F(a6(S),1);}k a6(d c)\n"
"#define an(a6)F a6(d);Q a6(){O=a6(S);}F a6(d c)\n"
"#define bc(ca,c,cb){d p[3];h r[3];p[0]=c;p[1]=c+dFdx(c);p[2]=c+dFdy(c);for(ac m=0;m<3;++m)r[m]=cb;ca=k(cc(d(r[1],r[2])-r[0]),r[0]);}\n"
"#define b4(a6,cd)k a6(d p,d b5){p*=b5;d B=ah(p),T=p-B,b6,g,X,r;h aS=8.,bd=aS,f;for(ac m=0;m<9;++m){g=d(m%3-1,m/3-1);X=ce(mod(B+g,b5));r=g+X-T;f=cd;Y(f<aS){bd=aS;aS=f;b6=r;}else Y(f<bd){bd=f;}}l k(b6,bd-aS);}\n"
"uniform F ae,Cam;uniform sampler2D ai,Texture1;in k Pos,Nor,WNor,Ref;in d S,LUV;in F Clr;out F O;h aD=3.1415927,b7=2.*aD,be=1.618034;d b8(h m){h bl=1.324718;l G(.5+m/d(bl,bl*bl));}h aE(h m){l G(.5+m*be);}h cf(h T){h m=ah(T);l o(aE(m),aE(m+1.),b3(T-m));}h bf(d u){l N(u.x,u.y);}h bf(k u){l N(u.x,N(u.y,u.z));}h bf(F u){l N(N(u.x,u.y),N(u.z,u.w));}h aC(d u){l M(u.x,u.y);}h aC(k u){l M(u.x,M(u.y,u.z));}h aC(F u){l M(M(u.x,u.y),M(u.z,u.w));}h aI(d u){l u.x+u.y;}h aI(k u){l u.x+u.y+u.z;}h b9(h a,h b){l C(a)<C(b)?a:b;}h bm(h x,h s){l C(x)-s;}h bn(h x,h s){l sign(x)*M(0.,C(x)-s);}d cc(d u){h v=dot(u,u);l v>0.?u/a7(v):u;}h i(h cg,h ch,h x){l 1.-W(C(x-cg)/ch);}h j(h bA,h ci,h x){l W((x-bA)/(ci-bA));}h i(h a,h b,h e,h x){l N(j(a,b,x),j(e,b,x));}d ak(h x){l d(sin(x),cos(x));}mat2 a3(h x){d u=ak(radians(x));l mat2(u.y,u.x,-u.x,u.y);}h aJ(d p){l G(atan(p.y,p.x)/b7);}d cj(d p,h B){l p*a3(360./B*(ah(aJ(p)*B+1.5)-1.));}d U(d c,h p,h s){l c+sin(c.yx*aD*p)*s;}d U(d c,h t,h p,h s){l c+sin(c.yx*aD*p+t)*s;}h bh(h u,h A){l A-C(u-A);}d bh(d u,h A){u.x=bh(u.x,A);l u;}h ck(h x,h p,h v,h R){l x-p*clamp(ah(x/p+.5),v,R);}d bB(d c,d s){c.x+=ah(c.y*s.y)*(.5/s.x);l G(c)*s;}k bC(d c,h r){l k(c-=clamp(c,r,1.-r),L(c)/r);}k bC(d c,d s,h r){s=s.yx/bf(s);c*=s;l k(c-=clamp(c,d(r),s-r),L(c)/r);}h af(d p){k q=G(p.xyx*.09153);q+=dot(q,q.yzx+19.19);l G((q.x+q.y)*q.z);}h af(h p){p=G(p*.1031);p*=p+33.33;p*=p+p;l G(p);}k c9(h p){k au=G(k(p)*k(.1031,.1030,.0973));au+=dot(au,au.yzx+33.33);l G((au.xxy+au.yzz)*au.zyx);}d ce(d p){k au=G(k(p.xyx)*k(.1031,.1030,.0973));au+=dot(au,au.yzx+33.33);l G((au.xx+au.yz)*au.zy);}F cl(h p){F av=G(F(p)*F(.1031,.1030,.0973,.1099));av+=dot(av,av.wzxy+33.33);l G((av.xxyz+av.yzzw)*av.zywx);}F cl(d p){F av=G(F(p.xyxy)*F(.1031,.1030,.0973,.1099));av+=dot(av,av.wzxy+33.33);l G((av.xxyz+av.yzzw)*av.zywx);}h al(h x,h p){l af(mod(x,p));}h cm(h x){h m;l o(af(m=ah(x)),af(m+1.),b3(x-m));}h Z(h x,h p){h m;l o(al(m=ah(x),p),al(m+1.,p),x-m);}h al(d p,d s){l af(mod(p,s));}h Z(d p,d s){p*=s;d m=ah(p);p-=m;p*=p*(3.-2.*p);h cn=al(m+d(0,0),s);h co=al(m+d(0,1),s);h cp=al(m+d(1,1),s);h cq=al(m+d(1,0),s);l o(o(cn,cq,p.x),o(co,cp,p.x),p.y);}h D(d p,d aF,h bo,h bu,ac bv){h aT=Z(p,aF),aG=1.,tw=1.;for(ac m=0;m<bv;++m){p=G(p+be);aF*=bu;aG*=bo;aT+=Z(p,aF)*aG;tw+=aG;}l aT/tw;}h bD(d p,d aF,h bo,h bu,ac bv){h aT=a5(Z(p,aF)),aG=1.,tw=1.;for(ac m=0;m<bv;++m){p=G(p+be);aF*=bu;aG*=bo;aT+=a5(Z(p,aF))*aG;tw+=aG;}l aT/tw;}d bi(d p,d a,d b){d ab=b-a,ap=p-a;h t=W(dot(ap,ab)/dot(ab,ab));l ab*t+a;}h cr(d c,d f){l dot(c,a3(90.)*aK(f));}h P(d p,d b){d f=C(p)-b;l N(M(f.x,f.y),0.)+L(M(f,0.));}h aU(d p,d b){l aC(C(p)-b);}h V(d p,h r){l L(p)-r;}h aV(d p,d r){l V(p/r,1.)/N(r.x,r.y);}h aA(h a,h b){l M(a,-b);}h bE(h a,h b,h K){h R=W(.5+0.5*(b-a)/K);l o(b,a,R)-K*R*(1.-R);}d bF(h x){d f=d(dFdx(x),dFdy(x));l f/M(L(f),1e-8);}h J(h s,h f){l W(1.-s/f);}h J(h s){l W(1.-s/fwidth(s));}F bG(d c,h s){l F(c/=s,a7(W(1.-aR(c))),L(c)-1.);}h cs(k B){h v=aI(B.yz)*.7;l pow(W(v),4.)+v;}h bH(d c,h s){c/=s;c.y+=.06;c.x*=2.;l j(.3,.0,L(c));}k aW(k e,d c,h s){F b=bG(c,s);e*=1.+cs(b.ad)*J(b.w)*.5;e*=1.-E(bH(c,20.*s))*(1.-J(b.w))*.3;l e;}h aX(d c,h t){c.x=C(c.x);c.y-=.07;h f=aV(c,d(.31,.12-t*.02))/50.;f=M(f,-aV(c-d(0,.01+.01*t),d(.28+t*.01,.07))/75.);f=M(f,-P(c-d(0,.1),d(.22-.02*t,.12)));f=M(f,-P(c-d(0,.1),d(.084-.012*t,.31)));f=N(f,aU(c-d(0,-.09),d(i(-.09,.32,c.y)*(.04-.015*t),.32)));f=N(f,aU(c-d(.11-.02*t,-.21+.01*t),d(i(-.07,.3,c.y)*(.03-.01*t),.15)));l f;}h ct(d c){h f=V(c-d(0,.17),.32);f=aA(f,V(c-d(0,.235),.27));f=aA(f,V(c-d(0,.5),.15));c.y-=.09;d s=d(.09,.52);h R=W(-c.y/s.y);s*=.5;s.x*=j(1.05,.6,R)+E(j(.1,.02,R));c.y+=s.y;f=N(f,P(c,s));l f;}k bI(d p,h ak,h cu){k I=k(-1,0,1),r=k(1e5);d a0=ah(p*ak),cA=I.yy;p-=(a0+.5)/ak;h am=.5*al(a0+I.yy,d(ak)),aL=.5*al(a0+I.xy,d(ak)),aM=.5*al(a0+I.yz,d(ak)),aN=.5*al(a0+I.zy,d(ak)),aO=.5*al(a0+I.yx,d(ak)),bJ=.5*al(a0+I.xz,d(ak)),bK=.5*al(a0+I.zz,d(ak)),bL=.5*al(a0+I.zx,d(ak)),bM=.5*al(a0+I.xx,d(ak));d[4]a8,v;Y(mod(a0.x+a0.y,2.)<.5){v[0]=1.+d(aO-aL,am-bM);v[1]=1.+d(aN-aO,am-bL);v[2]=1.+d(aM-aL,bJ-am);v[3]=1.+d(aN-aM,bK-am);a8[0]=d(aO,am);a8[1]=d(aO,am);a8[2]=d(aM,am);a8[3]=d(aM,am);}else{v[0]=1.+d(am-bM,aL-aO);v[1]=1.+d(bL-am,aN-aO);v[2]=1.+d(am-bJ,aM-aL);v[3]=1.+d(bK-am,aM-aN);a8[0]=d(am,aL);a8[1]=d(am,aN);a8[2]=d(am,aL);a8[3]=d(am,aN);}for(ac m=0;m<4;m++){a8[m]+=v[m]*(d(m&1,m/2)-.5);v[m]/=ak;h bx=aU(p-a8[m]/ak,v[m]/2.-cu/ak);Y(bx<r.x)r=k(bx,a0+a8[m]);}l r;}b4(bj,aI(C(r)))b4(b0,L(r))h aP(k p,h s){p=aK(p);k a=G(degrees(atan(p,p.yzx))/360.);l Z(a.x*s,s)*j(.9,.0,C(p.z))+Z(a.y*s,s)*j(.7,.0,C(p.x));}h aP(k p){l aP(p,45);}d cv(k p,ac ax){l(ax==0)?p.yz:(ax==1)?p.xz:p.xy;}ac cw(k B){B=C(B)+k(.01,.02,.03);h A=aC(B);l(A==B.x)?0:(A==B.y)?1:2;}k cx(k e){k rgb=W(C(mod(e.x*6.+k(0,4,2),6.)-3.)-1.);rgb*=rgb*(3.-2.*rgb);l e.z*o(k(1.),rgb,e.y);}k a1(){k f=Cam.ad-Pos;h b=D(f.xy/256.*a3(Cam.w),d(3),.7,3.,4),v=1.-j(14.,-6.,L(f.xy)-b*8.)*j(128.,48.,f.z)*step(.1,Nor.z);l aj(Texture1,LUV).ad*2.*v;}H(_8){h b=D(c,d(5),.9,3.,4);k e=o(n(48,41,33),n(103,101,104),b);l e;}H(_9){h b=D(c,d(3),.9,3.,4);k e=o(n(49,45,43),n(81,75,78),b*b);l e;}H(_10){h b=D(c,d(7),.9,3.,4);c.x*=-1.5;c.y+=c.x*.5;c.x=1.-c.x+c.y;c=G(c*28.);h T=W(1.-L(.1-c));T*=j(.6,.2,L(.6-c));T*=j(.6,.8,L(.1-c));T*=j(.2,.6,b)*2.+1.;h v=1.-j(.2,b+2.,aC(C(c-.5)));l k((T+1.)*o(.21,.29,b*b)*v);}H(_11){h b=D(c,d(7),.9,3.,4),r=L(c-.5);k e=_10(c);e=o(e,e*n(70,61,53),j(.5,.2,r+b*b*b));l e;}h bN(d c,h s){h f=1e6,m=0.;for(;m<5.;++m){d p=d(0,-s)*a3(m*72.);f=N(f,L(c-bi(c,p,p*a3(144.))));}l f;}an(_12){k e=_11(c);c=G(c)-.5;h b=D(c,d(3),.9,3.,4),f=N(C(L(c)-.4),bN(c,.35));l F(e,J(f-.02+b*.02,.01));}Q _13(){F e=aj(ai,S);O=F(e.ad*a1()+n(111,55,0)*e.w*(sin(ae.x*aD)*.5+.5),1);}H(_70){h b=D(c,d(7),.9,3.,4);k e=_10(c);h r=L(c-.5);h A=j(.46,.45,r);h v=1.5-1.5*j(.0,.3,r*r);v=o(v,2.5,i(.42,.07,r));v=o(v,3.5,i(.44,.05,r));v=o(v,2.6,i(.36,.03,r));h B=.3+.2*j(.35,.30,r);v*=1.-B*j(.3,.7,b);v*=1.-.3*E(j(.13,.05,r));v=o(v,2.5,j(.04,.01,r));v-=v*i(.03,.01,r)*.7;e=o(e,n(68,66,54)*v,A);e*=1.-E(i(.34,.02,r));e*=1.-E(i(.46,.03,r));e*=1.-i(.41,.03,r)*.7;l e;}d cy(d c,h s){l d(1.-L(c)/s,J(L(c)-s));}an(_72){h b=D(c,d(5),.9,3.,4),t,X,K,r;k e=_10(c);d a2,u;a2.x=C(c.x-.5);a2.y=N(c.y,.4);r=L(a2-d(0,.4))-(.18-.06*j(.4,1.,c.y));K=.25-.15*j(.9,.96,c.y)+.03*E(j(.82,.86,c.y))+.07*j(.8,.2,c.y)+.07*E(j(.35,.22,c.y))-.07*j(.22,.0,c.y);X=P(c-d(.5,.5),d(K,.46));X=M(X,-P(a2,d(.15,.03))+.06);e=o(e,k(.6,.55,.55)-c.y*.3+b*.2,J(X));e*=1.-.7*i(.0,.013,X);e*=1.-(r/.5-.1)*J(X);t=M(r,c.y-.96);X=C(t-.02)-.03;X=M(X,c.y-1.+a2.x*.5);X=M(X,c.y-.96);e=o(e,k(1,1,.9)-c.y*.55,i(-.01,.01,X));e=o(e,k(.2*b+.1),J(t,.01));e*=1.-.2*i(.0,.05,t)*J(X);u=cy(a2=c-d(.5,.4),.02);e*=1.+n(111,80,70)*i(.03,.01,L(a2));e*=1.-.5*i(.02,.01,L(a2));e=o(e,n(111,66,44)*(u.x*1.5+.2),u.y);l F(e,J(t-.03,.02));}Q _73(){F e=aj(ai,S);d c=G(S);c.x=C(.5-c.x);h t=G(-ae.x),r=L(c-d(0,.4)),v=t*pow(M(0.,1.-r),4.)*e.w;Y(t>.75)v+=j(.03,.01,C(G(c.y+c.x*.5+t*2.)-.45))*j(.1,.08,c.x);O=F(e.ad*a1()+n(180,150,5)*v,1);}H(_14){h b=D(c,d(5),.9,3.,4);k e=o(n(44,14,16),n(93,63,63),b*b);l e;}k bO(d c){h I=3e-3,a=0.;d g=d(6),r=bj(c,g).xy;for(ac m=0;m<9;++m)a+=aI(C(bj(d(m%3-1,m/3-1)*I+c,g).xy-r));l k(c+r.xy/g,a);}H(_15){h b=D(c,d(3),.9,3.,4);k e=o(n(80,70,72),n(128,120,120),b*b);k u=bO(c);e*=o(.95,1.1,Z(u.xy,d(6)));e=o(e,n(168,128,120),j(.5,1.,u.z)*b*.7);l e;}an(_16){h b=D(c,d(3),.9,3.,4);k e=o(n(80,70,72),n(128,120,120),b*b);k u=bO(c);h A=j(.5,1.,u.z);h r=j(.4,.2,L(.5-G(u.xy)));e*=o(.95,1.1,Z(u.xy,d(6)))-2.*r*b*b;e=o(e,n(168,128,120),A*b*.7);l F(e,A*r);}Q _17(){F e=aj(ai,S);O=F(e.ad*a1()+i(.5,.125,G(S.y*.5+ae.x*.5))*e.w*.3,1);}H(_18){h b=D(c,d(5),.9,3.,4);k pt=bI(c,8.,.31);k e=o(n(66,58,55),n(118,107,105),b);h v=1.-.5*j(.034,.036,pt.x);v=o(v,1.4,i(.033,.004,pt.x));l e*v;}h cz(d c){h b=Z(c,d(64)),T=0.,f=1e6;for(;T<11.;++T)f=bE(f,C(L(.5-C(c-b8(T)))-o(.36,.29,aE(T+.7)))-o(.015,.03,b),.01);l f*1e2;}k bP(d c){k s,p;for(ac m=0;m<3;++m){p=k(c,0);p[m]+=1e-4;s[m]=cz(p.xy);}l k(aK(s.xy-s.z),s.z);}H(_19){h b=D(c,d(5),.9,3.,4),v;k e=o(n(51,46,43),n(165,147,143),b*b),f=bP(c);v=1.-.5*(f.y-f.x)*i(.5,3.,f.z)*j(1.,.0,f.z);l e*v*.8;}H(_20){h b=D(c,d(3),1.1,3.,4),v;k e=o(n(51,46,43),n(165,147,143),b*b),f=bP(c);v=1.-.5*(f.y-f.x)*i(.5,3.,f.z)*j(1.,.0,f.z);l e*v;}H(_21){h b=D(c,d(5),.9,3.,4),v=.18*(.7+"
"b*b);k g;c=U(c,13.,.007);bc(g,c,E(j(.3+b*.2,.9,D(p[m],d(23),.5,2.,4))));l k(v*(1.-g.y*g.z));}H(_46){h b=D(c,d(5),.9,3.,4);k e=o(n(77,55,53),n(62,48,48),Z(c,d(128,13)))*(.7+b*b),g;c=U(c,13.,.007);bc(g,c,E(j(.4+b*.4,.95,Z(p[m],d(63,43)))));e*=j(1.3,.9,g.z);l k(e*(1.+g.y*g.z));}h bQ(d c,d s){c.y=M(c.y,0.);l aV(c,s);}k bk(k e,k b,d c,h R,h s){h y=(c.y-R)/s,p=1.-y*y;e*=1.-i(-1.,1.,y);Y(p>0.)e=b*(p*(.8+.2*i(.5,.25,G(c.x/s))))*(.7+E(i(.2,.7,y)));l e;}k c0(d c,h B){l k(B*B*.4);}H(_47){c.x*=.5;h b=D(c*d(2,1),d(3,5),.9,3.,4),B=.75+b*b,t=c.y+.2*N(.4,i(.5,.33,G(c.x*4.))),c1=bQ(c-d(.25,.62),d(3,2)/32.),aY=bQ(c-d(.25,.55),d(3,2)/48.),r;k e=o(n(66,50,51),n(111,66,44),a7(i(.31,.01,c.y))),ao;d p=c,q;p.x=G(p.x*4.);Y(c.y>.3)e=aW(e,d(4.*C(p.x-.5)-1.6,G(c.y*16.)-.5),.07);r=C(p.x-.5);e*=1.-.3*j(.31,.32,c.y)*j(.87,.86,c.y)*(j(.035,.03,.5-r)+i(.48,.01,r)-i(.46,.02,r));e=o(e*B,c0(c,b),M(j(.31,.3,c.y),J(aY)));e*=j(1.5,.7,c.y);Y(c.y<.306)e*=1.-i(.3,.05,c.y)*J(-aY+10.,20.);e*=1.-i(.316,.004,c.y)*J(-aY);Y(c.y<.1)e*=.0;q=c;q.y+=i(.1,.01,mod(q.x,.33))/2e2;e=bk(e,2.*b*n(93,84,79),c,.185,.015);e=bk(e,2.*b*n(138,77,48),c,.13,.025);e=bk(e,2.*b*n(112,71,51),c,.09,.015);e=bk(e,2.*b*n(138,77,48),q,.05,.015);p.x=C(G(c.x*6.-.5)-.5)/6.;e*=1.+.5*j(.04,.03,p.x)*i(.18,.03,p.y);r=aU(p-d(0,.12),d(.03,.01));r=aA(r,aU(p-d(0,.11),d(.01)));e*=1.-E(i(.0,.04,r));e=o(e,n(166,99,77)*2.*b*(.75+.5*E(i(.125,.01,c.y))),J(r));q=p;q.y-=.07;r=V(q,.03);e*=1.-E(i(.0,.07,r));e=o(e,n(127,83,72)*b*2.*j(.01,-.005,r),j(.005,.0,r));q.y-=.004;r=V(q,.015);e*=E(j(-.01,.01,r));q.y+=.013;r=V(q,.05);e+=n(67,38,30)*4.*a7(b)*E(i(-.02,.015,r)*i(.023,.02,c.y));r=aA(c1,aY);r=aA(r,(c.y-.3)*3e2);e*=1.-.5*i(-2.,17.,aY)*j(.26,.3,c.y);ao=n(67,39,17)*B;ao=o(ao,k(B*.2),i(0.,4.,r)*b);ao*=1.-.4*pow(i(.0,3.,r),4.);ao+=(ao+.6)*a7(b)*E(i(-6.,8.,r)*i(.66,.04,c.y))*J(r);Y(c.y<.56)ao=aW(ao,d(24.*C(c.x-.25)-1.85,G(c.y*24.+.5)-.5),.15);e=o(e,_46(c),j(.85,.9,t)+step(c.y,1./256.));e*=1.+i(.88,.015,t)-E(i(.87,.03,t));l o(e,ao,j(1.,.1,r));}k c2(k e,k K,d c,ac w,ac R){h b=D(c,d(w,R),.5,2.,2);e*=.9-.3*j(.15,.1,C(b-.5));l o(e,K,i(.5,.1,b));}H(_52){c=U(c,9.,.005);ac m=0,v[]=ac[](13,43,17,47,23,59,27,63);h b=D(c,d(19),.7,2.,4);k e=o(n(40,50,60),n(46,33,27),b)*(.5+b);for(;m<8;m+=2)e=c2(e,o(n(145,140,137),n(132,123,116),b),c,v[m],v[m+1]);l e;}k c3(k e,k K,d c,ac w,ac R){h b=D(c,d(w,R),.5,2.,2);e*=1.-.15*E(j(.15,.1,C(b-.5)));l o(e,K,i(.5,.1,b));}H(_59){h b=D(c,d(13),.9,3.,4),B=D(c,d(7),.9,3.,4);k e=o(n(111,66,55),n(80,55,52),E(j(.8,.2,B)))*(.8+.8*b*b),K=e;c=U(c,13.,.01);ac m=0,v[]=ac[](13,43,17,47,23,59,27,63);b=D(c,d(19),.7,2.,4);for(;m<6;m+=2)e=c3(e,K,c,v[m],v[m+1]);l e;}k c4(k e,k K,d c,ac w,ac R){h b=D(c,d(w,R),.5,2.,1);e*=.9-.3*E(j(.15,.1,C(b-.5)));l o(e,K,i(.5,.1,b));}H(_41){h b=D(c,d(3,29),.9,2.,4),t=.8+.8*b*b,f=C(c.y-.61),X=j(.25,.24,f),A;k e=n(140,127,127),K=e;d p=c;e*=1.-.1*j(.85,.86,c.y);e=t*o(e,n(110,55,50),j(.33,.32,c.y));p.y+=p.x*.11+b*.007;p.y=G(p.y*9.)-.5;A=j(.0,.1,C(p.y)-.2);ac m=0,v[]=ac[](3,29,5,37,9,63,27,63);for(;m<6;m+=2)e=o(e,c4(e,K,c,v[m],v[m+1]),A*X);e*=1.+t*X*(+.6*i(.1,.1,p.y)-.7*i(-.25,.3,p.y)-.5*i(.2,.1,p.y));e=o(e,n(99,66,51)*t,i(-.15,.1,p.y)*X);e*=1.+i(.36,.005,c.y)+i(.34,.005,c.y)+i(.865,.005,c.y)+i(.89,.01,c.y)-.5*E(i(.245,.01,f))-.7*E(i(.35,.01,c.y))-.5*E(i(.325,.02,c.y))-.8*E(i(.875,.02,c.y))-.3*E(i(.9,.02,c.y));e*=.3+a7(a5(c.x));l e;}k bR(k e,d p,h s,h A){s=bj(p,d(s)).z/s*1e2;e*=1.+.5*A*j(.9,.2,s)-.5*A*i(2.5,.5,.3,s);l e;}k bS(k e,d c,h c5){h b=D(c,d(4,9),.9,3.,4),t=.8+.8*b*b,a,f,A,s,K,m,u,r,z;k aH=o(n(133,100,88),n(133,100,100),b)*t;d p,q;p=q=c;q.x=C(q.x);f=V(p,.31);u=aJ(q);A=j(.01,.0,f);e=o(e*j(.0,.05,f+c5),k(.13*t),A);e=bR(e,p,37.,j(.04,.02,C(f+.07)));a=u*22.;m=ah(a);s=a-m;K=j(.23,.22,C(u-.25))+aE(m)*j(.0,.1,q.y);f-=r=(f*.3+.005)*K;A=j(.0,.1,q.y)*J(C(f+.015)-.015);e=o(e,aH,i(-.005,.01,f));e=o(e,n(130,75,44)*t,i(-.02,.005,f)*j(.0,.1,q.y));e*=1.-.3*j(.025,.03,-f)-.5*j(.4,.5,C(s-.5))*A+.2*i(.5,.3,C(s-.5))*A-.5*i(-.015,.007,f)-.5*i(-.03,.007,f)-.5*i(-.1,.005,f+r)-.5*i(-.115,.005,f+r)-.5*i(-.125,.015,f+r)-.5*i(-.145,.005,f+r)+.9*i(-.11,.007,f+r)+.5*i(-.14,.005,f+r)-b*i(.225,.005,C(u-.25))*J(C(f+.015)-.015);a=u*72.;m=ah(a);s=a-m;K=step(.7,af(m))*step(q.y,.0)*j(.02,.0,C(f+.02));e=o(e,k(aH*.6),K*j(.4,.3,C(s-.5)));e*=1.-.7*K*i(.4,.1,C(s-.5));l e;}k b1(d c){h b=D(c,d(4,9),.9,3.,4),t=.8+.8*b*b,a,f,A,s,K,m,u,r,z;k aH=o(n(133,100,88),n(133,100,100),b)*t,e=k(.1*t);d p,q;p.x=c.x-.5;p.y=M(c.y-.2,0.)*1.89;u=atan(p.y,C(p.x))/aD;f=V(p,.48);K=j(.3,.31,u);f*=1.-.2*j(.3,.31,u)-.1*j(.43,.44,u);a=u*(u>.44?2.:u>.3?63.:31.);e=o(e,aH,j(.03,.01,C(f)));A=J(C(f-.01)-.02);m=ah(a);s=a-m;Y(u>.33&&u<.44)s=G(s+af(m)*.6-.3);e*=1.-.5*A*i(.307,.01,u)-t*A*i(.5,.1+K*.2,s)+b*A*i(.52,.2+K*.2,s);e*=1.-.9*i(-.015,.015,f)-.5*i(.0,.01,f)-.7*i(.03,.02,f)+i(.01,.015,f);q=p;q.y-=.5;q.x=C(q.x)+.6;f=V(q,1.13);A=j(.03,.02,C(f))*j(.5,.6,q.y);e=o(e,aH*W(1.-C(f-.015)/.03),A);e*=1.-.5*A*i(.005,.01,f)+.5*A*i(.017,.005,f);q.x=C(c.x-.5)-.35;q.y=c.y*9./4.-2.1;f=V(q,.13)*10.;a=aJ(q)*49.;m=ah(a);s=a-m;u=j(.85,.9,af(m));for(ac a9=0;a9<2;++a9,f+=.3){e=o(e,aH*(b*.5+.2),j(.09,.03,C(f)));e*=1.+.7*E(i(.01,.05,f));}p.y=(c.y-.7)*9./4.;f=V(p,.43);a=atan(p.y,C(p.x))/aD;a=M(a,-.48);r=a;m=ah(a*=23.);s=a-m;K=aE(m)*.2-.1*j(.0,.1,-f);u=j(.1,.2,C(s-.5)-K);f+=u*.007;r=(1.-u)*E(i(.5,.3,r))*j(.25,.05,C(s-.5));f-=.17*r;A=i(.04,.0,-.4,f);e=o(e,aH*(b*.4+.4),A);e=bR(e,p,31.,j(.1,.05,C(f+.15))*u);e*=o(1.,1.-i(.1,.2,.4,C(s-.5)-K),A*b);e*=1.-.7*E(i(.03,.03,f))-.7*E(i(.03,.03,f+.05))*u-.7*E(i(.0,.02,f+.05))*u-.3*j(.04,.06,-f)*u+.5*i(.02,.0,-.1,f)+i(.0,.01+.07*r,f)+i(.0,.01,f+.03)*u;p.y-=.05;e=bS(e,p,0.);l e;}H(_42){c.y=(c.y+8.)/9.;l b1(c);}H(_43){c.y=(c.y*4.+4.)/9.;l b1(c);}H(_44){Y(c.y<.01)++c.y;c.y=c.y*4./9.;l b1(c);}H(_54){h b=D(c,d(5),.9,3.,4),t=bD(U(c,4.,.01),d(7),.5,3.,5),B=Z(U(c,4.,.05),d(9)),aB,I;k pt=bI(c,4.,.1+B*t*.05),e;d f=bF(pt.x);aB=af(G(pt.yz));e=n(74,65,62)*(.8+.8*b*b);e+=i(.6,.3,B)*j(.3,.9,b*t)*.2;e*=1.-i(.5,.4,B)*j(.5,.7,t)*.1;e=o(e,n(86,74,78),i(.5,.1,b)*i(.7,.3,aB)*.7);e=o(e,n(105,90,70),i(.3,.1,t)*i(.3,.3,aB)*.3);I=i(.015,.005+.015*B,pt.x)+i(.4,.1,B*t)*.4;e*=1.-b*j(.015,.05,pt.x)*.7;e*=1.+I*b*(f.y-.5)*.7;e*=.9+.2*aB;e*=.9+.2*a5(Z(c-pt.yx,d(5)));l e;}H(_45){k e=_54(c);c-=.5;e=bS(e,c*.9,.02);l e;}k aQ(d c){c*=1.5;h b=D(U(c,7.,.02),d(9),.7,3.,2),t=b,B=Z(c,d(13)),a,s,f;k e=_54(c);d p;p.x=C(c.x-.75);p.y=M(c.y-.58,0.)*1.15;a=atan(p.x,p.y)/aD;s=G(a*7.+.5);f=V(p,.45);f-=.06*j(.4,.33,c.y);f-=.05*j(.15,.07,C(s-.5))*step(.63,c.y);f=aA(f,c.y-.107);Y(c.y<.6)f=aA(f,C(p.x-.493)-.113);f=aA(f,V(p,.6)+.044*j(.48,.43,c.y));e=o(e,n(144,125,115)*t,J(f-.1,.005));e*=1.-.3*i(.12,.11,.1,f)+.5*i(.1,.005+.015*B*B,f);l e;}H(_32){l aQ(d(5,0)/6.+c*d(1,4)/6.);}H(_33){l aQ(d(1,0)/6.+c*d(4)/6.);}H(_34){l aQ(c*d(1,4)/6.);}H(_35){l aQ(d(5,4)/6.+c*d(1,2)/6.);}H(_36){l aQ(d(1,4)/6.+c*d(4,2)/6.);}H(_37){l aQ(d(0,4)/6.+c*d(1,2)/6.);}H(_55){h b=D(c,d(13,1),.7,2.,3);k e=_54(c)*.7;e*=1.-E(j(.4,1.,b));l e;}k bT(d c,d s){h b=D(c,d(5),.9,3.,4),B=D(c,d(31,3),.5,3.,3),t=.75+b*b;d p=c;k e=_54(c);Y(c.y<.38)e=o(n(92,43,15),n(66,44,33),j(.1,.05,c.y))*t*(.5+.5*j(.0,.35,c.y));e+=b*s.y*E(i(.32,s.x*.015,c.y))+.3*b*i(.34,.05,c.y);e*=1.-i(.38,.005+b*b*.03,c.y)+3.*i(.15,.2,c.y)*(B-.5);l e;}H(_56){h b=D(c,d(5),.9,3.,4),t=.75+b*b,f,X,m;d p=c;k e=bT(c,d(1));p.x=mod(p.x,1./7.)-.07;p.y-=.21;f=V(d(.75*p.x,bn(p.y,.1)),.033);X=J(f,.005);f=V(d(.75*p.x,bn(p.y+.005,.09)),.033);m=J(f+.015);e=o(e,n(83,81,66)*t,(X-m)*j(.1,.3,c.y));e*=1.-j(.17,.25,c.y)*m;e+=E(i(.0,.015,f))*i(.32,.03,c.y);e*=1.+3.*pow(i(-.01,.03,f),4.)*i(.09,.03,c.y);f=V(d(.75*p.x,bn(p.y+.03,.1)),.033);e*=1.-J(f+.01,.02)*(1.-X);Y(c.y>.09&&c.y<.3)e=aW(e,d((C(p.x)-.035)*36.,G(c.y*36.)-.5),.1);l e;}d c6(d p){p.x=C(p.x);d q=p,u;q.y-=.5;h f=V(q,.35),I,e;u=q/.35;q.y+=.25;q.x-=.15;f=N(f,P(q,d(.09,.05))-.1);I=aV(q,d(.15,.1))/5e1;e=.1+dot(d(u.y,a7(W(1.-aR(u)))),d(.3,.3));q.y+=.2;q.x=p.x;e=M(e,W(.4-L(q)));e+=.15*i(.0,.1,I)-.1*J(I+.12,.15);f=N(f,P(q,d(.15-j(-.15,.15,q.y)*.07,.03))-.09);e*=1.-j(.05,.25,q.x)*j(.2,.1,C(q.y+.12));q.y-=.06;e-=.5*J(aV(q,d(.05-j(-.1,.1,q.y)*.03,.06))/1e3+.03,.05);l d(W(e),J(f,.02));}H(_57){h b=D(c,d(9),.7,2.,4),t=.75+b*b;k e=bT(c,d(4,.3));d p=c,s;p.x=mod(p.x,.2);p-=.1;s=c6(p*5.);l o(e,o(k(.5,.4,.3),k(.95,.8,.55),t)*t*s.x,s.y);}H(_53){d p=bB(c,d(8)),q=G(p),u=U(c,3"
"1.,.002),aB=p-q;h b=D(U(c,5.,.02),d(7),1.,3.,4),t=.8+.8*b*b,B=Z(c+b8(af(aB)*64.),d(23)),A=D(c,d(9),.7,3.,4),f=D(u,d(63),.7,3.,4),r=D(u-d(0,.002),d(63),.7,3.,4),v=f-r,I=bC(q,.03+.03*a5(B)).z,R=af(aB);k e=o(n(91,61,42),n(70,30,15),I*b);e=o(e,n(70,48,35),j(.5,.6,A))*t;e*=1.+v*(.1+B+i(.6,.1,A))*(1.-I)-t*j(.7,1.,I)*Z(c,d(13))+.5*b*i(.3,.3,I);f=D(u,d(23),.5,2.,4);e*=1.-.2*j(.6,.7,f)*R+.3*i(.6,.05,f)*R*B;e*=.9+.2*R*(1.-I);e*=.9+.4*pow(bD(c-af(aB/8.),d(5),.6,2.,4),4.);l e;}an(_28){h b=D(c-=.5,d(5),.9,3.,4),t=.75+b*b,B=Z(U(c,7.,.02),d(17)),r=L(c),K=r>.4?38.:r>.32?28.:16.,a=G(atan(c.y,c.x)/b7),m=ah(a*K),a4=C(C(r-.41-B*.002)*1e2-6.),A=j(1.5,1.4,a4),b2[]=h[](1.,3.,-.145,-1.,2.,.166),f,bU,s;d p=c;k e=n(78,68,63);e*=1.+.5*E(i(.49,.005+.015*B*B+.015*b,r));e=o(e,n(83,52,47)*(.6+.4*B*B),A)*t;e*=1.-.5*i(1.5,.5,a4)+b*i(1.,.5+.5*B,C(r-.418)*1e2-5.)-b*i(.5,.08,G(a*K+.5))*A+b*i(.5,.1,G(a*K+.55))*A;A=j(.34,.33,r);e=o(e*(1.-.5*A),n(83,52,47)*t,B*b*A);e=o(e,n(112,86,31)*t,A*E(i(.1,.15,.45,b)));e=o(e,n(77,66,77)*t,A*j(.5,.8,b)*.5);e*=1.-.7*i(.27,.34,.35,r);a4=r+B*.004;A=r>.21&&r<.31?1.:0.;e*=1.-i(.325,.005,a4)-i(.31,.005,a4)-b*E(i(.29,.005,a4))-b*E(i(.23,.01,a4))-.5*E(i(.21,.02,a4))+E(i(.3,.01,a4))*b+E(i(.22,.01,a4))*b-b*i(.5,.07,G(a*K+.5))*A;Y(r<.23)m+=37.;Y(r<.31)m+=73.;Y(r<.31)m+=91.;e*=o(1.,.9+.2*aE(m),A);A=j(.01,.0,C(r-.411)-.039);m=ah(a*72.);p*=a3(m*5.);s=0.;f=1e6;ac a9=0;for(;a9<6;a9+=3){f=b9(f,bU=dot(p,aK(d(b2[a9],b2[a9+1])))+b2[a9+2]);s+=s+h(bU>0.);}Y(s==3.)++m;else m+=66.*s;m=aE(m);e=o(e,t*n(90,80,75),A);e=o(e,t*n(127,111,88),m*b*A);e*=o(1.,.7+.6*af(m),A);e*=1.-A*E(i(.0,.006,f))*b+A*E(i(.006,.006,C(f)))*b*.5;m=ah(a*4.);p=C(c*a3(m*90.+45.));f=1e6;for(a9=0;a9<2;++a9,p=C(p*a3(45.)))f=b9(f,C(L(p-d(0,.12))-.16));A=j(.21,.2,r);a4=bm(bm(f,.012),.001);e*=1.-j(.21,.2,r)*J(.012-f)+b*A*E(i(.005,.005,f))-.5*A*E(J(a4-.001,.001));l F(e,(1.-j(.21,.15,r)*J(.028-f,.02))*j(.07,.087,r));}an(_29){d p=G(S)-.5;h b=D(a3(ae.x*333.)*p/(.8+.2*sin(ae.x*61.)),d(53),.7,2.,4);F e=F(1.-b*k(0,.3,1),1),ao=aj(ai,(a3(ae.x*30.)*p/(.8+.2*sin(ae.x*1.26)))+.5);e.ad=o(e.ad,ao.ad,ao.w);ao=aj(ai,S);e.ad=o(e.ad,ao.ad,ao.w)*a1();l e;}h c7(d p){p=cj(p,8.);h f=V(p,.41);f=N(f,P((p-d(.34,0))*a3(45.),d(.1)));f=M(f,p.x-.45);l f;}H(_30){d p=c-.5,q;h b=D(c,d(9),.7,2.,4),t=.8+.8*b*b,r=V(p,.41),f=c7(p),v=dFdy(f)/.004,A=J(f+.01,.007),a=aJ(p),I,B,x,z;k e=_54(c),K=n(155,135,115)*t;e*=1.-(.5*-v+.5)*j(.03,.0,f);e=o(e,K,A);I=L(p)*9.;q.x=a*ah(I+1.)*3.;q.y=G(I);B=i(.5,.2,Z(U(c,7.,.03),d(41)));B=D(q,d(3,9),.5,2.,4)*i(.5,.5+.5*B,q.y);e=o(e,n(100,85,80)*a5(B)*b,J(r+.15,.02));q=p;q.x=C(p.x);I=M(M(f,cr(q,-d(.08,.4))),C(r+.06)-.09);z=P(q-d(0,.3),d(.01,.03));I=aA(I,z-.02);x=J(-I,.01);e*=1.+v*A*j(.02,.0,-f)*j(.01,.0,-r)+x*i(.035,.015,-r)+.5*x*i(.13,.01,-r)+.7*i(.08,.007,z)*(1.-x)-.7*x*E(i(.01,.04,-r))-.6*x*E(i(.13,.06,.03,-r))-.5*x*E(i(.12,.02,-r))*A-.9*E(i(.12,.15,.2,-r))*A-.5*E(i(.0,.05,I));e+=k(.8,.8,1)*pow(W(1.-L(c-d(.41,.59))/.35),8.);q.x=a;q.y=j(.05,.12,-r);I=bj(q,d(37,1)).z;A=i(.085,.035,-r)*x;e*=1.+.5*A*i(.0,.2,I)-.3*A*i(.3,.3,I);I=P(p+d(0,.33),d(.01,.03))-.03;v=dFdy(I)/.004;e=o(e,K*(.4+.8*j(.25,.41,-p.y)),z=J(I,.01));e*=1.+.7*i(.005,.01,I)*v-.5*i(.0,.01,.05,I);I=P(q=p+d(0,.35),d(.01,.015))-.01;v=dFdy(I)/.004;e*=1.+.5*i(.005,.01,I)-.5*E(i(.0,.01,I));e+=k(1,.7,.5)*pow(W(1.-L(q)/.11),8.);l e;}Q _31(){k e=aj(ai,S).ad*a1();d c=G(S)-.5,p=c;h t=mod(ae.x*2.,7.),m=ah(t),f=1e6;Y(m==0.)f=ct(p*2.4+d(0,.05));Y(m==1.){p.x=ck(p.x,.1,-1.,1.);f=P(p,d(.02,.15))*2.;}Y(m==2.){f=N(f,P(bh(p,.0)+d(.13-j(-.3,.3,c.y)*.17,0),d(.02,.15)));f=N(f,P(p+d(0,.07),d(.07,.02)))*2.;}Y(m==4.)f=aX(p*1.8,.5);else f=bm(f,.005);O=F(e+J(f,.02)*G(-t)*k(.5,.05,.05),1);}H(_58){h b=D(c,d(13),.9,3.,4),B=D(c,d(7),.9,3.,4);k e=o(n(60,50,50),n(87,47,37),E(j(.7,.25,B)))*(.7+.8*b*b),g;c=U(c,31.,.003);bc(g,c,a7(j(.0,.9,Z(p[m],d(93)))));e*=1.-(g.y+.4)*E(b*g.z)*g.z;l e;}H(_62){h b=D(c,d(5),.9,3.,4);k e=n(67,64,63)*(.6+.5*b),g;c=U(c,31.,.003);bc(g,c,a7(Z(p[m],d(53,93))));e*=1.-.3*g.y*g.z*g.z;l e;}an(_22){c=U(c,7.,.01);h b=D(c,d(9),.7,2.,4),B=D(c,d(13),.5,2.,4),A=j(.6,.9,D(U(c,5.,.03),d(11),.6,2.,4));k e=n(127,70,55)*(.85+.3*b);e*=1.-.2*E(j(.3,.0,b*b))-.2*A-.3*j(.6,.77,B)+.3*j(.5,.9,b);e+=.5*E(j(.5,1.,D(c,d(17),1.,2.,3)));l F(e,1.-A);}Q _24(){F e=aj(ai,S);d c=G(S);c.y-=.2*ae.x;h b=D(U(c,7.,.02),d(5),.9,2.,4);O=F(o(n(25,10,8)*b,e.ad,e.w)*a1(),1);}H(_23){d p=c-.5;p=U(p,17.,.007);p.x*=2.-c.y*1.5;h b=D(c,d(9),.7,2.,4),B=Z(c,d(7)),f=L(p),s;k e=_22(c).ad;s=G(f*=13.);Y(f<=6.){e*=1.-pow(j(6.,.5,f+b*b),6.);B=j(.3,.7,B);e*=1.-B*b*i(.4,.2,s)+B*b*i(.6,.4,s);}l e;}H(_25){c=U(c,13.,.003);h b=D(c,d(7),.9,3.,4),B=D(c,d(5),.5,2.,4),t=.5+b;k e=n(80,38,34),u=b0(c,d(23));e=o(e,o(n(180,125,118),n(165,78,51),B),b*i(.0,.4+B*.4,u.z))*t;l e;}H(_26){h b=D(c,d(7),.9,3.,4),t=.8+.4*b,m,r=.7,v,A;k e,u=b0(c,d(23));d p=u.xy/r,q=c+u.xy/23.;m=af(G(q)*3.3);e=o(n(155,55,55),n(200,166,155),j(.75,.45,q.y))*t;A=i(.5,.5,L(p));v=dot(d(-p.y,a7(W(1.-aR(p)))),d(.6+m*.3,.3));e*=1.-b*.8*j(.5,.1,u.z)+b*A*v;e*=t*t*t*t;l e;}H(_27){h b=D(c,d(13),.9,3.,4),t=.4+b*b,B=a5(Z(U(c,12.,.02),d(48))),m,r,v,A;k e=n(60,50,46)*t,u=b0(c,d(17));m=af(G(c+u.xy/17.));r=.4+.3*m;d p=u.xy/r;A=N(j(1.1,1.,L(p)),j(.0,.15,u.z));v=dot(d(-p.y,a7(W(1.-aR(p)))),d(.1+m*.2,.3));e+=b*A*v*B;B=a5(D(U(c,13.,.01),d(23,43),.5,2.,3));e*=1.+(1.-A)*i(.4,.4,B);l e;}H(_60){h b=D(c,d(7),.9,3.,4),B=D(c,d(3),.5,3.,4);k e=o(n(103,56,53),n(73,58,71),j(.1,.7,B))*(.75+b*b);l e;}H(_61){h b=D(c,d(13),.9,3.,4),B=Z(U(c,5.,.05),d(9)),f=a5(G(c.x*4.)),A=j(.1,.15,f)*j(1.,.99,c.y);k e=n(51,44,44);e=o(e,n(73,55,52),j(.2,.2,b)*B*A);e=o(e,n(69,60,66),j(.7,.1,b)*b*A);e=o(e,n(99,77,77),j(.1,.5,B)*B*A*b*b*.3);e*=.6+.3*b+.3*b*b;e*=1.+.9*E(i(.21,.02+.1*B,f+b*.05))*A*b;e*=1.-E(j(.49,.5,C(c.y-.5)));e*=1.-j(.05,.2,f)*j(.16,.1,f);e*=1.+i(.99,.007,c.y);l aW(e,d(f-.4,G(c.y*8.)-.5),.07);}k bV(d c,h s){h b=D(c,d(3,1.+s+s),.7,2.,4),f=a5(c.x),A;c.y*=2.;k e=o(n(71,60,58),n(110,88,77),j(.1,.05,f))*(.7+.6*b);e*=1.-j(.05,.0,c.x)*(1.-b*b);e*=1.+.5*i(.05,.02,c.x);d p=d(f-.35,G(c.y*s)-.5);F K=bG(p,.11);A=J(K.w);e*=1.-.7*bH(p,1.1)*(1.-A);e=o(e,(K.y>.0?n(128,105,88):n(200,111,66)*j(-.2,.7,K.z))*(.4+2.*b*pow(W(aI(K.yz*.7)),4.))*(1.-.6*i(-.1,.4,K.y)),A);l e;}H(_38){l bV(c,4.);}H(_39){l _38(c.yx);}H(_40){l bV(c,1.);}H(_48){h b=D(c,d(40,5),.9,3.,4);k e=n(110,110,98)*(.8+.8*b*b);Y(c.y<1./4.)e*=.5;e*=1.-.4*j(.4,.0,b)+.5*j(.02,.0,c.y)+.2*i(.24,.01,c.y);l e;}H(_49){d p=c,q;p.y*=22.;q=G(p);h b=D(c,d(3,23),1.,2.,6),B=D(c,d(3,33),.7,3.,4),aB=af(p.y-q.y);k e=n(92,67,53)*(.8+.8*b*b);e*=1.-E(j(.1,.0,N(q.y,1.-q.y)))*b;e*=1.-.2*smoothstep(.3,.7,B);e*=.8+.3*b*aB;l e;}H(_50){h b=D(c,d(13),.9,3.,4),x=c.x*16./3.;k e=_49(c)*j(.15,.21,c.x);Y(x<1.)e=n(59,48,49)*(.7+.6*b);e*=1.+.5*i(.05,.05,a5(x));l aW(e,d(C(c.x-3./32.)-.07,mod(c.y,.1)-.05),.004);}H(_51){d p=bB(c,d(6,4)),q=G(p),a2=q;h b=D(U(c-=.5,5.,.03),d(13),.9,2.,3),B=Z(c,d(73,7)),t=(.75+b*b)*(.8+.4*cf(c.x*93.)),r;k e=k(.25*t);a2.y+=a2.y*2.-.01-.03*B;r=L(a2-=clamp(a2,d(.49,.5),d(.51,3)));e*=1.-.7*b*E(j(.07,.03,C(r-.5)))+.5*b*i(.35,.1,r)*E(j(.2,.1,q.y))-.3*E(j(.8,1.,q.y))-.3*(j(.3,.1,q.y))*j(.4,.6,r)+.2*E(j(.5,.1,q.y))*j(.45,.4,r);l e;}H(_64){h b=D(c,d(5),.9,3.,4),R=G(c.y*10.);k e=o(n(53,48,42),n(38,38,36),b)*(.6+b*.8);e*=1.+.5*E(i(.25,.25,R))+.5*E(i(.65,.35,R))-.6*E(i(.5,.5,R));l e;}H(_63){h b=D(c,d(7,3),.9,3.,4),R=c.y+b*.04;k e=o(n(50,40,34),n(93,92,88),b*b);e*=1.+.9*j(.07,.04,C(c.y-.44))-.4*j(.08,.05,C(c.y-.7))-.5*i(.34,.05,c.y)-.3*i(.7,.04,c.y)+.7*i(.01,.03,c.y)+1.5*i(.89,.1,R)+1.3*i(.5,.04,R)+.9*i(.18,.04,R);l e;}H(_65){h b=D(c,d(5,3),.9,3.,4);k e=o(n(74,66,55),n(99,90,78),b*b);c.x*=2.;d p=bi(c,d(.5,.625),d(1.5,.625));h f=L(p-c),A=j(.22,.20,f),v=1.-.15*A-.5*j(.7,.9,c.y)*A-.3*(bF(f).y-.5)*i(.2,.03,f)-.3*E(i(.17,.03,f))-.5*j(.05,0.,c.y)-.3*i(.33,.05,c.y)+.7*j(.93,1.,c.y)+.7*i(.31,.04,c.y);l e*v;}an(_66){h b=D(c,d(1,5),.4,3.,4);k e=o(n(56,49,43),n(142,136,136),b);c=.5-C(c-.5);c.y*=4.;h a=i(.0,.1,L(c-bi(c,d(.41,.5),d(.42,3.5)))),f=bf(c),v=1.-.7*M(0.,1.-f/.15);v*=1.-.8*j(.24,.31,N(f,c.y-.1));e+=n(80,80,20)*a;l F(e*o(v,2.7,a),a);}an(_69){h b=D(c,d(1,5),.4,3.,4);k e=o(n(56,49,43),n(142,136,136),b);c=.5-C(c-.5);c.y*=8.;h f=L(c-bi(c,d(.27,.3),d(.27,7.7))),a=i(.0,.17,f),v=1.-.5*i(.17,.07,f);e+=n(80,80,20)*a;l F(e*o(v,2.7,a),a);}an(_67){d p=C(c-.5);h b=D(c,d(1),.4,3.,4),r=L(p),"
"a=j(.37,.33,r)*(.5+2.*b),v=1.+.0*j(.08,.03,C(r-.41));k e=o(n(56,49,43),n(142,136,136),b);v=o(v,7.,j(.44,.1*b,r));v*=1.-.5*E(i(.46,.04,r));v*=1.-.4*E(i(.36,.04,r));l F(e*v,a);}an(_68){h b=D(c,d(5),.9,3.,4),f=bE(bN(c-=.5,.35),C(V(c,.4)),.02),a=pow(J(f-.02,.15),8.),X=N(M(P(c,d(.46)),-V(c,.51)),C(V(c,.44)));k e=n(76,62,47)*(.8+.8*b*b);e*=1.+(b+.5)*J(C(X)-.01,.01);e*=1.-j(.1,.05,f)*J(V(c,.4));l F(e+1.*k(1,1,.3)*a,a);}an(_1){c-=d(.48,.5);h f=aX(c,0.),b=L(c)-.47;k e=1.-k(.5,1,1)*J(M(.007-f,b+.04));l F(e,1)*J(b);}H(_2){c-=.5;d r=d(dFdx(c.x),dFdy(c.y));c/=r/aC(r);c*=.8;c.y-=.03;h x=C(c.x),b=D(c,d(31,5),.7,2.,3),t=.8+.8*b*b,f=aX(c,1.),I=aX(c+d(0,.002),1.),v=(I-f)*5e2+.5;k e=k(.3*t,0,0)*J(f,.004);e*=1.-E(j(.0,.3,x))-.5*j(.1,.3,C(c.y-.1));e+=+t*.2*i(.0,.01-.01*x,f)*i(.1,.2,c.y)*j(.3,.2,x)*v+t*.5*j(.004,.0,f)*j(.07,.1,c.y)*i(.23,.1,x)*k(.9,.9,1)+t*.4*i(.005,.005,f)*j(.2,-.1,c.y)*j(.3,.2,x)*W(-v);l e;}h bW(d c,h s,h m,h c8){m=(c.y-E(C(c.x-.5))*c8)*s-m;l 2.*i(.5,.4,m)*(G(m)-.5);}an(_78){h b=D(c,d(5,9),.9,3.,4),t=.8+.8*b*b,B=D(c,d(5,9),.9,3.,2),x=C(c.x-.5),f;k e=n(77,60,44)*t;d p=c*d(1,2)-d(.5,.7);e*=1.-.55*J(aA(V(p,.3),aX(a3(45.)*p*.8,0.)-.01));e*=1.+E(j(.6,.9,b))+i(.2,.5,c.y)*i(.2,.3,x)*bW(c,4.,.2,4.);for(h T=6.;T<9.;++T)e*=1.+i(.8,.5,c.y)*i(.2,.3,x)*bW(c,12.,T,1.);f=c.y-.81-E(W(x*4.))*.09;e=o(e,n(82,66,60)*t,j(.0,.01,f));e*=1.-.5*(i(.01,.02,f))+.5*(i(.02,.01,f));f=.15*(1.-c.y);f=P(c-.5,d(.49)-f)+B*.1*a7(1.-c.y)-f;l F(e*E(J(f+.01,.05)),J(f));}an(_79){F e=aj(ai,c);Y(e.w<.5)discard;e.ad*=E(a1()*.5);l e;}F aZ(k p,h s){p*=s/h(textureSize(ai,0).x);k B=Nor*Nor;F e=F(0);for(ac m=0;m<3;++m,p=p.yzx)e+=aj(ai,p.yz)*B[m];l e/aI(B);}F aZ(h s){l aZ(Pos,s);}Q _80(){k B=Nor*Nor;O=aZ(4.)*(Clr+.5*B.z*B.z*sign(Nor.z))*1.5;}Q _81(){_80();}Q _94(){O=aZ(16.)*(WNor.z*.5+.5)*F(1,.95,.9,1);O+=2.*pow(W(Nor.z),o(2.,8.,O.y))*E(O);}Q _95(){O=F((aP(Ref,15.)*1.4+.3)*ae.yzw,1);}h bX(h e,h s,h x){h a=M(fwidth(x)*2./s,1.);l i(e,s*a,x)/a;}Q _82(){_80();k p=Pos,q;p.y=C(p.y);q=p-k(7,3.5,-21);q.z*=1.3;h r=L(q);O.ad*=1.+W(p.z+30.)*j(4.,5.,aC(p.xy))+.5*W(p.z+15.)+.3*i(3.,.5,r)+.7*bX(-15.,.5,p.z)-bX(-14.5,.5,p.z)-j(3.,2.5,r)*(.6+.4*q.z/r);q=p-k(8,0,-23);q.z*=.7;r=L(q);O.ad*=1.-j(2.,1.,r)*(.6+.4*q.z/r);}an(_83){c*=d(256,64);c.y+=2.;h f=V(c-d(81,30),11.);f=M(f,c.x-80.);f=M(f,-V(c-d(84,26),9.));f=N(f,P(c-d(73,37),d(4,9))-4.);f=M(f,-P(c-d(73,37),d(0,7))+1.);f=N(f,P(c-d(91.5,47),d(4,19))-4.);f=M(f,-P(c-d(91.5,47),d(0,17.5))+1.);f=N(f,P(bh(c,111.)-d(105.+j(23.,50.,c.y)*3.,43),d(3.5,19)));f=N(f,P(c-d(111,32),d(4,3)));f=N(f,P(c-d(126,37),d(3,13)));f=N(f,P(c-d(125.5+j(23.,50.,c.y)*10.,44),d(3.5,6)));f=N(f,P(c-d(136.5-j(23.,50.,c.y)*9.,32),d(3.5,8)));f=N(f,P(c-d(148.5,37),d(7,13)));f=M(f,-P(c-d(155,33),d(6,3)));f=M(f,-P(c-d(155,43),d(6,2)));f=N(f,P(c-d(168,37),d(3.5,13)));f=N(f,P(c-d(178.,37),d(3.5,13)));f=N(f,P(c-d(188,37),d(3.5,13)));f=M(f,c.y-50.);l F(J(f,.8),0,0,af(c*511.));}Q _84(){k e=aj(ai,S*2.).ad*step(.5,G(ae.x*.5));e=o(e*a1(),k(.5,0,0),i(G(ae.x*2.),1./64.,G(S.y)));O=F(e+aP(Ref)*.25+aj(ai,S+af(ae.xx)).w*.1,1);}Q _85(){d c=G(S);c.x+=ae.x/13.;h b=D(c,d(3,7),.9,2.,4),T=c.y;O=F(2.*n(95,85,80)*T*T*T*T*o(1.,b,.5),0.);}Q _86(){O=F(aP(Ref)*n(133,111,111),0);}h star(d p,d e,h s){p-=e;h a=j(.3,.5,C(G(aJ(p/=s)*8.+af(e))-.5));l j(.9,.6,pow(aR(p),.0625)-a*a*.006);}Q _87(){O=F(2,2,2,0)*pow(star(S,d(.5),1.),2.);}h bY(d c,h s){d p=c;p.y+=p.y-ae.x*s;c.x+=(cm(p.y*5.)-.5)*1.5*E(c.y);h B=D(U(p,7.,.02),d(9),.7,2.,4),R=j(.9,.03,c.y),b=P(c-d(.5,.15),d(0,.3));l E(J(b+B*E(1.2-R)-.13,.15));}Q bZ(h s){d c=G(S);O=(bY(c,s*.6)+bY(c,s))*F(2.5,1,.35,0);}Q _88(){bZ(2.5);}Q _89(){bZ(1.);}Q _0(){h v=dot(Nor,aK(k(2,0,8)));v=v*.4+.7;d c=cv(Pos,cw(Nor));k e=k(.5);e*=cx(k(G(be*ae.w+.25),1.,1.));O=F(e*v,1);}Q _6(){F e=aj(ai,S);O=F(e.ad*o(a1(),k(1),e.w),1);}Q _71(){F e=aj(ai,S);h r=L(G(S)-.5);h s=o(.4,8.,G(ae.x*1.5));O=F(e.ad*a1()+n(240,130,5)*i(.1,.05,r/s)*j(.37,.32,r),1);}Q _5(){k e=aj(ai,S).ad;O=F(e*a1(),1);}Q _7(){F e=aj(ai,S);e.ad*=1.+e.w*aP(Ref);O=F(e.ad*a1(),1);}Q _74(){O=F(0);}Q _75(){k f=aK(Pos-Cam.ad);f.z=f.z*4.+2.;d c=aK(f).xy*2.;h b=j(.2,1.,D(c-ae.x*d(.1,.2),d(5),.5,2.,6));c.y*=1.5;h s=j(.3,1.,D(c-ae.x*d(.1,.18),d(5),.6,2.,6));O=F(k(b,0,0)+n(80,30,8)*s*s*2.,1);}Q _76(){d c=U(S/8.,ae.x*.5,2.,.05);h b=D(c,d(7),.9,2.,4);k e=n(91,22,14)*(.2+1.6*b);e=o(e,n(144,44,0),i(.6,.2,D(c,d(3),.7,3.,4)));e=o(e,n(244,144,66)*b*2.,E(i(.55,.25,D(c,d(11),.5,2.,4))));O=F(e*W(aC(a1())),1);}Q _77(){_76();}Q _3(){O=aj(ai,(.5+S*127.)/128.,2.5);O.ad*=.7+.3*Z(S,.5/fwidth(S));}Q _4(){O=aj(ai,S)*Clr;}Q _90(){d c=d(aJ(Pos.xy),j(8.,128.,Pos.z));c.x=G(c.x*3.-ae.x*2.2);c.y*=4.;h T=star(c,d(0,.3),1.)+star(c,d(1,.3),1.)+star(c,d(.5,.4),1.5);T*=T;O=F(T,T,T,0);}an(_91){h b=D(U(c,5.,.03),d(7),.5,3.,2);l(b*1.4+.3)*F(1.2,.54,.06,0)+.5*i(.7,.2,b)*F(1,1,1,0);}Q _92(){k p=Pos;p-=ae.x*6.4*sign(p.z-72.);O=aZ(p,8.);}H(_93){c=U(c,5.,.02);h b=D(c,d(6),.8,2.,4),A=D(c,d(2),.6,2.,4),t=.8+.3*b*b;k e=o(n(36,33,30),n(168,177,168),.3+.7*A)*t;l e;}"
;

// src/demo/data/shaders/vertex_shaders.glsl: 4092 => 2013 (49.2%)
static constexpr char g_vertex_shaders[] =
"#define c void\n"
"#define f vec4\n"
"#define k gl_Position\n"
"#define l location\n"
"#define n normalize\n"
"uniform mat4 MVP,View,World;uniform f Time,Cam;layout(l=0)in f e;layout(l=1)in f j;layout(l=2)in vec3 h;layout(l=3)in f o;out vec3 Pos,Nor,WNor,Ref;out vec2 UV,LUV;out f Clr;c d(){k=e;UV=e.xy*.5+.5;}c m(float v,float A,float B){k+=A*MVP*f(h,0)*sin(6.28*(Time.x*B+dot(e.xyz/v,vec3(1))));}c _0(){k=MVP*e;Pos=e.xyz;Nor=h;UV=j.xy;LUV=j.zw;Clr=o;Ref=n(reflect((e-Cam).xyz,h));}c i(){_0();Pos=floor(h)/4.;Nor=fract(h)*4.-2.;Ref=n(reflect((e-Cam).xyz,Nor));float a=j.z,u=cos(a),s=sin(a);Nor.xy*=mat2(u,s,-s,u);}c _1(){d();}c _2(){d();}c _3(){d();}c _4(){k=f(2.*e.x-1.,1.-2.*e.y,1,1);UV=j.xy;Clr=o;}c _5(){_0();}c _6(){_0();}c _7(){_0();}c _8(){d();}c _9(){d();}c _10(){d();}c _11(){d();}c _12(){d();}c _13(){_0();}c _14(){d();}c _15(){d();}c _16(){d();}c _17(){_0();}c _18(){d();}c _19(){d();}c _20(){d();}c _21(){d();}c _22(){d();}c _23(){d();}c _24(){_0();}c _25(){d();}c _26(){d();}c _27(){d();}c _28(){d();}c _29(){_0();}c _30(){d();}c _31(){_0();}c _32(){d();}c _33(){d();}c _34(){d();}c _35(){d();}c _36(){d();}c _37(){d();}c _38(){d();}c _39(){d();}c _40(){d();}c _41(){d();}c _42(){d();}c _43(){d();}c _44(){d();}c _45(){d();}c _46(){d();}c _47(){d();}c _48(){d();}c _49(){d();}c _50(){d();}c _51(){d();}c _52(){d();}c _53(){d();}c _54(){d();}c _55(){d();}c _56(){d();}c _57(){d();}c _58(){d();}c _59(){d();}c _60(){d();}c _61(){d();}c _62(){d();}c _63(){d();}c _64(){d();}c _65(){d();}c _66(){d();}c _67(){d();}c _68(){d();}c _69(){d();}c _70(){d();}c _71(){_0();}c _72(){d();}c _73(){_0();}c _74(){_0();}c _75(){_0();}c _76(){_0();m(100.,3.,.1);}c _77(){_0();}c _78(){d();}c _79(){_0();m(30.,3.,.2);m(100.,3.,.7);}c _80(){i();}c _81(){i();}c _82(){i();}c _83(){d();}c _84(){_0();}c _85(){_0();}c _86(){i();}c _87(){_0();k+=MVP*f(Nor*mat3(View),0);}c _88(){_0();}c _89(){_0();}c _90(){i();}c _91(){d();}c _92(){i();}c _93(){d();}c _94(){_0();WNor=n(mat3(World)*h);Ref=n(reflect((World*e-Cam).xyz,WNor));}c _95(){_94();}"
;

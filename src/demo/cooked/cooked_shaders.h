#pragma once

// auto-generated, do not modify
static_assert(0x02923967U == Demo::Shader::Version, "Shader definition mismatch, please recompile the shader compiler & shaders");

// src/demo/data/shaders/fragment_shaders.glsl: 64177 => 26619 (41.5%)
static constexpr char g_fragment_shaders[] =
"#define e vec2\n"
"#define h float\n"
"#define k vec3\n"
"#define l return\n"
"#define n mix\n"
"#define A abs\n"
"#define F fract\n"
"#define G vec4\n"
"#define K max\n"
"#define L length\n"
"#define M min\n"
"#define O UV\n"
"#define P int\n"
"#define T xyz\n"
"#define U if\n"
"#define Z void\n"
"#define ac Time\n"
"#define aj Texture0\n"
"#define al texture\n"
"#define ao floor\n"
"#define a7 sqrt\n"
"#define aV normalize\n"
"#define bu(x)((x)*(x)*(3.-2.*(x)))\n"
"#define D(x)((x)*(x))\n"
"#define bv(x)dot(x,x)\n"
"#define ae(x)clamp(x,0.,1.)\n"
"#define o(r,g,b)(k(r,g,b)/255.)\n"
"#define aC(v)i(.5,.5,v)\n"
"#define H(a4)k a4(e);Z a4(){X=G(a4(O),1);}k a4(e c)\n"
"#define an(a4)G a4(e);Z a4(){X=a4(O);}G a4(e c)\n"
"#define aX(bW,c,bX){e p[3];h r[3];p[0]=c;p[1]=c+dFdx(c);p[2]=c+dFdy(c);for(P m=0;m<3;++m)r[m]=bX;bW=k(bY(e(r[1],r[2])-r[0]),r[0]);}\n"
"#define b0(a4,bZ)k a4(e p,e b1){p*=b1;e E=ao(p),S=p-E,b2,g,N,r;h aN=8.,aY=aN,f;for(P m=0;m<9;++m){g=e(m%3-1,m/3-1);N=ca(mod(E+g,b1));r=g+N-S;f=bZ;U(f<aN){aY=aN;aN=f;b2=r;}else U(f<aY){aY=f;}}l k(b2,aY-aN);}\n"
"uniform G ac,Cam;uniform sampler2D aj,Texture1;in k Pos,Nor,Ref;in e O,LUV;in G Clr;out G X;h aB=3.1415927,b3=2.*aB,aZ=1.618034;e cb(h m){h bi=1.324718;l F(.5+m/e(bi,bi*bi));}h aD(h m){l F(.5+m*aZ);}h cc(h S){h m=ao(S);l n(aD(m),aD(m+1.),bu(S-m));}h bc(e v){l M(v.x,v.y);}h bc(k v){l M(v.x,M(v.y,v.z));}h bc(G v){l M(M(v.x,v.y),M(v.z,v.w));}h aE(e v){l K(v.x,v.y);}h aE(k v){l K(v.x,K(v.y,v.z));}h aE(G v){l K(K(v.x,v.y),K(v.z,v.w));}h bd(e v){l v.x+v.y;}h b4(h a,h b){l A(a)<A(b)?a:b;}h b5(h x,h s){l A(x)-s;}h bj(h x,h s){l sign(x)*K(0.,A(x)-s);}e bY(e v){h u=dot(v,v);l u>0.?v/a7(u):v;}h i(h cd,h ce,h x){l 1.-ae(A(x-cd)/ce);}h j(h b6,h cf,h x){l ae((x-b6)/(cf-b6));}h i(h a,h b,h d,h x){l M(j(a,b,x),j(d,b,x));}e af(h x){l e(sin(x),cos(x));}mat2 a8(h x){e v=af(radians(x));l mat2(v.y,v.x,-v.x,v.y);}h b7(e p){l F(atan(p.y,p.x)/b3);}e Y(e c,h p,h s){l c+sin(c.yx*aB*p)*s;}e Y(e c,h t,h p,h s){l c+sin(c.yx*aB*p+t)*s;}h bk(h v,h C){l C-A(v-C);}e bk(e v,h C){v.x=bk(v.x,C);l v;}e b8(e c,e s){c.x+=ao(c.y*s.y)*(.5/s.x);l F(c)*s;}k aO(e c,h r){l k(c-=clamp(c,r,1.-r),L(c)/r);}k aO(e c,e s,h r){s=s.yx/bc(s);c*=s;l k(c-=clamp(c,e(r),s-r),L(c)/r);}h ak(e p){k q=F(p.xyx*.09153);q+=dot(q,q.yzx+19.19);l F((q.x+q.y)*q.z);}h ak(h p){p=F(p*.1031);p*=p+33.33;p*=p+p;l F(p);}k cz(h p){k au=F(k(p)*k(.1031,.1030,.0973));au+=dot(au,au.yzx+33.33);l F((au.xxy+au.yzz)*au.zyx);}e ca(e p){k au=F(k(p.xyx)*k(.1031,.1030,.0973));au+=dot(au,au.yzx+33.33);l F((au.xx+au.yz)*au.zy);}G cg(h p){G av=F(G(p)*G(.1031,.1030,.0973,.1099));av+=dot(av,av.wzxy+33.33);l F((av.xxyz+av.yzzw)*av.zywx);}G cg(e p){G av=F(G(p.xyxy)*G(.1031,.1030,.0973,.1099));av+=dot(av,av.wzxy+33.33);l F((av.xxyz+av.yzzw)*av.zywx);}h ah(h x,h p){l ak(mod(x,p));}h c0(h x){h m;l n(ak(m=ao(x)),ak(m+1.),bu(x-m));}h Q(h x,h p){h m;l n(ah(m=ao(x),p),ah(m+1.,p),x-m);}h ah(e p,e s){l ak(mod(p,s));}h Q(e p,e s){p*=s;e m=ao(p);p-=m;p*=p*(3.-2.*p);h ch=ah(m+e(0,0),s);h ci=ah(m+e(0,1),s);h cj=ah(m+e(1,1),s);h ck=ah(m+e(1,0),s);l n(n(ch,ck,p.x),n(ci,cj,p.x),p.y);}h B(e p,e a9,h aP,h aQ,P bl){h aR=Q(p,a9),aF=1.,tw=1.;for(P m=0;m<bl;++m){p=F(p+aZ);a9*=aQ;aF*=aP;aR+=Q(p,a9)*aF;tw+=aF;}l aR/tw;}h B(e p,e a9,h aP,h aQ){l B(p,a9,aP,aQ,4);}h b9(e p,e a9,h aP,h aQ,P bl){h aR=aC(Q(p,a9)),aF=1.,tw=1.;for(P m=0;m<bl;++m){p=F(p+aZ);a9*=aQ;aF*=aP;aR+=aC(Q(p,a9))*aF;tw+=aF;}l aR/tw;}e be(e p,e a,e b){e ab=b-a,ap=p-a;h t=ae(dot(ap,ab)/dot(ab,ab));l ab*t+a;}h R(e p,e b){e f=A(p)-b;l M(K(f.x,f.y),0.)+L(K(f,0.));}h aS(e p,e b){l aE(A(p)-b);}h V(e p,h r){l L(p)-r;}h aT(e p,e r){l V(p/r,1.)/M(r.x,r.y);}h aG(h a,h b){l K(a,-b);}h bA(h a,h b,h J){h ad=ae(.5+0.5*(b-a)/J);l n(b,a,ad)-J*ad*(1.-ad);}e bB(h x){e f=e(dFdx(x),dFdy(x));l f/K(L(f),1e-8);}h I(h s,h f){l ae(1.-s/f);}h I(h s){l ae(1.-s/fwidth(s));}G bC(e c,h s){l G(c/=s,a7(ae(1.-bv(c))),L(c)-1.);}h cl(k E){h u=bd(E.yz)*.7;l pow(ae(u),4.)+u;}h bD(e c,h s){c/=s;c.y+=.06;c.x*=2.;l j(.3,.0,L(c));}k aU(k d,e c,h s){G b=bC(c,s);d*=1.+cl(b.T)*I(b.w)*.5;d*=1.-D(bD(c,20.*s))*(1.-I(b.w))*.3;l d;}k bE(e p,h af,h cm){k W=k(-1,0,1),r=k(1e5);e a0=ao(p*af),c1=W.yy;p-=(a0+.5)/af;h ai=.5*ah(a0+W.yy,e(af)),aI=.5*ah(a0+W.xy,e(af)),aJ=.5*ah(a0+W.yz,e(af)),aK=.5*ah(a0+W.zy,e(af)),aL=.5*ah(a0+W.yx,e(af)),bF=.5*ah(a0+W.xz,e(af)),bG=.5*ah(a0+W.zz,e(af)),bH=.5*ah(a0+W.zx,e(af)),bI=.5*ah(a0+W.xx,e(af));e[4]a5,u;U(mod(a0.x+a0.y,2.)<.5){u[0]=1.+e(aL-aI,ai-bI);u[1]=1.+e(aK-aL,ai-bH);u[2]=1.+e(aJ-aI,bF-ai);u[3]=1.+e(aK-aJ,bG-ai);a5[0]=e(aL,ai);a5[1]=e(aL,ai);a5[2]=e(aJ,ai);a5[3]=e(aJ,ai);}else{u[0]=1.+e(ai-bI,aI-aL);u[1]=1.+e(bH-ai,aK-aL);u[2]=1.+e(ai-bF,aJ-aI);u[3]=1.+e(bG-ai,aJ-aK);a5[0]=e(ai,aI);a5[1]=e(ai,aK);a5[2]=e(ai,aI);a5[3]=e(ai,aK);}for(P m=0;m<4;m++){a5[m]+=u[m]*(e(m&1,m/2)-.5);u[m]/=af;h bx=aS(p-a5[m]/af,u[m]/2.-cm/af);U(bx<r.x)r=k(bx,a0+a5[m]);}l r;}b0(bm,bd(A(r)))b0(cn,L(r))h bJ(k p){p=aV(p);k a=mod(degrees(atan(p,p.yzx)),360.);l Q(a.x/8.,45.)*j(.9,.0,A(p.z))+Q(a.y/8.,45.)*j(.7,.0,A(p.x));}e bK(k p,P ax){l(ax==0)?p.yz:(ax==1)?p.xz:p.xy;}P bL(k E){E=A(E)+k(.01,.02,.03);h C=aE(E);l(C==E.x)?0:(C==E.y)?1:2;}k co(k d){k rgb=ae(A(mod(d.x*6.+k(0,4,2),6.)-3.)-1.);rgb*=rgb*(3.-2.*rgb);l d.z*n(k(1.),rgb,d.y);}k a2(){k f=Cam.T-Pos;h b=B(f.xy/256.*a8(Cam.w),e(3),.7,3.,4),u=1.-j(14.,-6.,L(f.xy)-b*8.)*j(128.,48.,f.z)*step(.1,Nor.z);l al(Texture1,LUV).T*2.*u;}H(_8){h b=B(c,e(5),.9,3.,4);k d=n(o(48,41,33),o(103,101,104),b);l d;}H(_9){h b=B(c,e(3),.9,3.,4);k d=n(o(49,45,43),o(81,75,78),b*b);l d;}H(_10){h b=B(c,e(7),.9,3.);c.x*=-1.5;c.y+=c.x*.5;c.x=1.-c.x+c.y;c=F(c*28.);h S=ae(1.-L(.1-c));S*=j(.6,.2,L(.6-c));S*=j(.6,.8,L(.1-c));S*=j(.2,.6,b)*2.+1.;h u=1.-j(.2,b+2.,aE(A(c-.5)));l k((S+1.)*n(.21,.29,b*b)*u);}H(_11){h b=B(c,e(7),.9,3.);k d=_10(c);h r=L(c-.5);d=n(d,d*o(70,61,53),j(.5,.2,r+b*b*b));l d;}h bM(e c,h s){h f=1e6,m=0.;for(;m<5.;++m){e p=e(0,-s)*a8(m*72.);f=M(f,L(c-be(c,p,p*a8(144.))));}l f;}an(_12){k d=_11(c);c=F(c)-.5;h b=B(c,e(3),.9,3.),f=M(A(L(c)-.4),bM(c,.35));l G(d,I(f-.02+b*.02,.01));}Z _13(){G d=al(aj,O);X=G(d.T*a2()+o(111,55,0)*d.w*(sin(ac.x*aB)*.5+.5),1);}H(_67){h b=B(c,e(7),.9,3.,4);k d=_10(c);h r=L(c-.5);h C=j(.46,.45,r);h u=1.5-1.5*j(.0,.3,r*r);u=n(u,2.5,i(.42,.07,r));u=n(u,3.5,i(.44,.05,r));u=n(u,2.6,i(.36,.03,r));h E=.3+.2*j(.35,.30,r);u*=1.-E*j(.3,.7,b);u*=1.-.3*D(j(.13,.05,r));u=n(u,2.5,j(.04,.01,r));u-=u*i(.03,.01,r)*.7;d=n(d,o(68,66,54)*u,C);d*=1.-D(i(.34,.02,r));d*=1.-D(i(.46,.03,r));d*=1.-i(.41,.03,r)*.7;l d;}e cp(e c,h s){l e(1.-L(c)/s,I(L(c)-s));}an(_69){h b=B(c,e(5),.9,3.),t,N,J,r;k d=_10(c);e a1,v;a1.x=A(c.x-.5);a1.y=M(c.y,.4);r=L(a1-e(0,.4))-(.18-.06*j(.4,1.,c.y));J=.25-.15*j(.9,.96,c.y)+.03*D(j(.82,.86,c.y))+.07*j(.8,.2,c.y)+.07*D(j(.35,.22,c.y))-.07*j(.22,.0,c.y);N=R(c-e(.5,.5),e(J,.46));N=K(N,-R(a1,e(.15,.03))+.06);d=n(d,k(.6,.55,.55)-c.y*.3+b*.2,I(N));d*=1.-.7*i(.0,.013,N);d*=1.-(r/.5-.1)*I(N);t=K(r,c.y-.96);N=A(t-.02)-.03;N=K(N,c.y-1.+a1.x*.5);N=K(N,c.y-.96);d=n(d,k(1,1,.9)-c.y*.55,i(-.01,.01,N));d=n(d,k(.2*b+.1),I(t,.01));d*=1.-.2*i(.0,.05,t)*I(N);v=cp(a1=c-e(.5,.4),.02);d*=1.+o(111,80,70)*i(.03,.01,L(a1));d*=1.-.5*i(.02,.01,L(a1));d=n(d,o(111,66,44)*(v.x*1.5+.2),v.y);l G(d,I(t-.03,.02));}Z _70(){G d=al(aj,O);e c=F(O);c.x=A(.5-c.x);h t=F(-ac.x),r=L(c-e(0,.4)),u=t*pow(K(0.,1.-r),4.)*d.w;U(t>.75)u+=j(.03,.01,A(F(c.y+c.x*.5+t*2.)-.45))*j(.1,.08,c.x);X=G(d.T*a2()+o(180,150,5)*u,1);}H(_14){h b=B(c,e(5),.9,3.,4);k d=n(o(44,14,16),o(93,63,63),b*b);l d;}k bN(e c){h W=3e-3,a=0.;e g=e(6),r=bm(c,g).xy;for(P m=0;m<9;++m)a+=bd(A(bm(e(m%3-1,m/3-1)*W+c,g).xy-r));l k(c+r.xy/g,a);}H(_15){h b=B(c,e(3),.9,3.,4);k d=n(o(80,70,72),o(128,120,120),b*b);k v=bN(c);d*=n(.95,1.1,Q(v.xy,e(6)));d=n(d,o(168,128,120),j(.5,1.,v.z)*b*.7);l d;}an(_16){h b=B(c,e(3),.9,3.,4);k d=n(o(80,70,72),o(128,120,120),b*b);k v=bN(c);h C=j(.5,1.,v.z);h r=j(.4,.2,L(.5-F(v.xy)));d*=n(.95,1.1,Q(v.xy,e(6)))-2.*r*b*b;d=n(d,o(168,128,120),C*b*.7);l G(d,C*r);}Z _17(){G d=al(aj,O);X=G(d.T*a2()+i(.5,.125,F(O.y*.5+ac.x*.5))*d.w*.3,1);}H(_18){h b=B(c,e(5),.9,3.,4);k pt=bE(c,8.,.31);k d=n(o(66,58,55),o(118,107,105),b);h u=1.-.5*j(.034,.036,pt.x);u=n(u,1.4,i(.033,.004,pt.x));l d*u;}h cq(e c){h b=Q(c,e(64)),S=0.,f=1e6;for(;S<11.;++S)f=bA(f,A(L(.5-A(c-cb(S)))-n(.36,.29,aD(S+.7)))-n(.015,.03,b),.01);l f*1e2;}k bO(e c){k s,p;for(P m=0;m<3;++m){p=k(c,0);p[m]+=1e-4;s[m]=cq(p.xy);}l k(aV(s.xy-s.z),s.z);}H(_19){h b=B(c,e(5),.9,3.,4),u;k d=n(o(51,46,43),o(165,147,143),b*b),f=bO(c);u=1.-.5*(f.y-f.x)*i(.5,3.,f.z)*j(1.,.0,f.z);l d*u*.8;}H(_20){h b=B(c,e(3),1.1,3.,4),u;k d=n(o(51,46,43),o(165,147,143),b*b),f=bO(c);u=1.-.5*(f.y-f.x)*i(.5,3.,f.z)*j(1.,.0,f.z);l d*u;}H(_21){h b=B(c,e(5),.9,3.,4),u=.18*(.7+b*b);k g;c=Y(c,13.,.007);aX(g,c,D(j(.3+b*.2,.9,B(p[m],e(23),.5,2.,4))));l k(u*(1.-g.y*g.z));}H(_43){h b=B(c,e(5),.9,3.,4);k d=n(o(77,55,53),o(62,48,48),Q(c,e(128,13)))*(.7+b*b),g;c=Y(c,13.,.007);aX(g,c,D(j(.4+b*.4,.95,Q(p[m],e(63,43)))));d*=j(1.3,.9,g.z);l k(d*(1.+g.y*g.z));}h bP(e c,e s){c.y=K(c.y,0.);l aT(c,s);}k bf(k d,k b,e c,h ad,h s){h y=(c.y-ad)/s,p=1.-y*y;d*=1.-i(-1.,1.,y);U(p>0.)d=b*(p*(.8+.2*i(.5,.25,F(c.x/s))))*(.7+D(i(.2,.7,y)));l d;}k cr(e c,h E){l k(E*E*.4);}H(_44){c.x*=.5;h b=B(c*e(2,1),e(3,5),.9,3.,4),E=.75+b*b,t=c.y+.2*M(.4,i(.5,.33,F(c.x*4.))),cs=bP(c-e(.25,.62),e(3,2)/32.),aW=bP(c-e(.25,.55),e(3,2)/48.),r;k d=n(o(66,50,51),o(111,66,44),a7(i(.31"
",.01,c.y))),am;e p=c,q;p.x=F(p.x*4.);U(c.y>.3)d=aU(d,e(4.*A(p.x-.5)-1.6,F(c.y*16.)-.5),.07);r=A(p.x-.5);d*=1.-.3*j(.31,.32,c.y)*j(.87,.86,c.y)*(j(.035,.03,.5-r)+i(.48,.01,r)-i(.46,.02,r));d=n(d*E,cr(c,b),K(j(.31,.3,c.y),I(aW)));d*=j(1.5,.7,c.y);U(c.y<.306)d*=1.-i(.3,.05,c.y)*I(-aW+10.,20.);d*=1.-i(.316,.004,c.y)*I(-aW);U(c.y<.1)d*=.0;q=c;q.y+=i(.1,.01,mod(q.x,.33))/2e2;d=bf(d,2.*b*o(93,84,79),c,.185,.015);d=bf(d,2.*b*o(138,77,48),c,.13,.025);d=bf(d,2.*b*o(112,71,51),c,.09,.015);d=bf(d,2.*b*o(138,77,48),q,.05,.015);p.x=A(F(c.x*6.-.5)-.5)/6.;d*=1.+.5*j(.04,.03,p.x)*i(.18,.03,p.y);r=aS(p-e(0,.12),e(.03,.01));r=aG(r,aS(p-e(0,.11),e(.01)));d*=1.-D(i(.0,.04,r));d=n(d,o(166,99,77)*2.*b*(.75+.5*D(i(.125,.01,c.y))),I(r));q=p;q.y-=.07;r=V(q,.03);d*=1.-D(i(.0,.07,r));d=n(d,o(127,83,72)*b*2.*j(.01,-.005,r),j(.005,.0,r));q.y-=.004;r=V(q,.015);d*=D(j(-.01,.01,r));q.y+=.013;r=V(q,.05);d+=o(67,38,30)*4.*a7(b)*D(i(-.02,.015,r)*i(.023,.02,c.y));r=aG(cs,aW);r=aG(r,(c.y-.3)*3e2);d*=1.-.5*i(-2.,17.,aW)*j(.26,.3,c.y);am=o(67,39,17)*E;am=n(am,k(E*.2),i(0.,4.,r)*b);am*=1.-.4*pow(i(.0,3.,r),4.);am+=(am+.6)*a7(b)*D(i(-6.,8.,r)*i(.66,.04,c.y))*I(r);U(c.y<.56)am=aU(am,e(24.*A(c.x-.25)-1.85,F(c.y*24.+.5)-.5),.15);d=n(d,_43(c),j(.85,.9,t)+step(c.y,1./256.));d*=1.+i(.88,.015,t)-D(i(.87,.03,t));l n(d,am,j(1.,.1,r));}k ct(k d,k J,e c,P w,P ad){h b=B(c,e(w,ad),.5,2.,2);d*=.9-.3*j(.15,.1,A(b-.5));l n(d,J,i(.5,.1,b));}H(_49){c=Y(c,9.,.005);P m=0,u[]=P[](13,43,17,47,23,59,27,63);h b=B(c,e(19),.7,2.,4);k d=n(o(40,50,60),o(46,33,27),b)*(.5+b);for(;m<8;m+=2)d=ct(d,n(o(145,140,137),o(132,123,116),b),c,u[m],u[m+1]);l d;}k cu(k d,k J,e c,P w,P ad){h b=B(c,e(w,ad),.5,2.,2);d*=1.-.15*D(j(.15,.1,A(b-.5)));l n(d,J,i(.5,.1,b));}H(_56){h b=B(c,e(13),.9,3.,4),E=B(c,e(7),.9,3.,4);k d=n(o(111,66,55),o(80,55,52),D(j(.8,.2,E)))*(.8+.8*b*b),J=d;c=Y(c,13.,.01);P m=0,u[]=P[](13,43,17,47,23,59,27,63);b=B(c,e(19),.7,2.,4);for(;m<6;m+=2)d=cu(d,J,c,u[m],u[m+1]);l d;}k cv(k d,k J,e c,P w,P ad){h b=B(c,e(w,ad),.5,2.,1);d*=.9-.3*D(j(.15,.1,A(b-.5)));l n(d,J,i(.5,.1,b));}H(_38){h b=B(c,e(3,29),.9,2.,4),t=.8+.8*b*b,f=A(c.y-.61),N=j(.25,.24,f),C;k d=o(140,127,127),J=d;e p=c;d*=1.-.1*j(.85,.86,c.y);d=t*n(d,o(110,55,50),j(.33,.32,c.y));p.y+=p.x*.11+b*.007;p.y=F(p.y*9.)-.5;C=j(.0,.1,A(p.y)-.2);P m=0,u[]=P[](3,29,5,37,9,63,27,63);for(;m<6;m+=2)d=n(d,cv(d,J,c,u[m],u[m+1]),C*N);d*=1.+t*N*(+.6*i(.1,.1,p.y)-.7*i(-.25,.3,p.y)-.5*i(.2,.1,p.y));d=n(d,o(99,66,51)*t,i(-.15,.1,p.y)*N);d*=1.+i(.36,.005,c.y)+i(.34,.005,c.y)+i(.865,.005,c.y)+i(.89,.01,c.y)-.5*D(i(.245,.01,f))-.7*D(i(.35,.01,c.y))-.5*D(i(.325,.02,c.y))-.8*D(i(.875,.02,c.y))-.3*D(i(.9,.02,c.y));d*=.3+a7(aC(c.x));l d;}k bQ(k d,e p,h s,h C){s=bm(p,e(s)).z/s*1e2;d*=1.+.5*C*j(.9,.2,s)-.5*C*i(2.5,.5,.3,s);l d;}k bR(k d,e c,h cw){h b=B(c,e(4,9),.9,3.,4),t=.8+.8*b*b,a,f,C,s,J,m,v,r,z;k aH=n(o(133,100,88),o(133,100,100),b)*t;e p,q;p=q=c;q.x=A(q.x);f=V(p,.31);v=b7(q);C=j(.01,.0,f);d=n(d*j(.0,.05,f+cw),k(.13*t),C);d=bQ(d,p,37.,j(.04,.02,A(f+.07)));a=v*22.;m=ao(a);s=a-m;J=j(.23,.22,A(v-.25))+aD(m)*j(.0,.1,q.y);f-=r=(f*.3+.005)*J;C=j(.0,.1,q.y)*I(A(f+.015)-.015);d=n(d,aH,i(-.005,.01,f));d=n(d,o(130,75,44)*t,i(-.02,.005,f)*j(.0,.1,q.y));d*=1.-.3*j(.025,.03,-f)-.5*j(.4,.5,A(s-.5))*C+.2*i(.5,.3,A(s-.5))*C-.5*i(-.015,.007,f)-.5*i(-.03,.007,f)-.5*i(-.1,.005,f+r)-.5*i(-.115,.005,f+r)-.5*i(-.125,.015,f+r)-.5*i(-.145,.005,f+r)+.9*i(-.11,.007,f+r)+.5*i(-.14,.005,f+r)-b*i(.225,.005,A(v-.25))*I(A(f+.015)-.015);a=v*72.;m=ao(a);s=a-m;J=step(.7,ak(m))*step(q.y,.0)*j(.02,.0,A(f+.02));d=n(d,k(aH*.6),J*j(.4,.3,A(s-.5)));d*=1.-.7*J*i(.4,.1,A(s-.5));l d;}k bn(e c){h b=B(c,e(4,9),.9,3.,4),t=.8+.8*b*b,a,f,C,s,J,m,v,r,z;k aH=n(o(133,100,88),o(133,100,100),b)*t,d=k(.1*t);e p,q;p.x=c.x-.5;p.y=K(c.y-.2,0.)*1.89;v=atan(p.y,A(p.x))/aB;f=V(p,.48);J=j(.3,.31,v);f*=1.-.2*j(.3,.31,v)-.1*j(.43,.44,v);a=v*(v>.44?2.:v>.3?63.:31.);d=n(d,aH,j(.03,.01,A(f)));C=I(A(f-.01)-.02);m=ao(a);s=a-m;U(v>.33&&v<.44)s=F(s+ak(m)*.6-.3);d*=1.-.5*C*i(.307,.01,v)-t*C*i(.5,.1+J*.2,s)+b*C*i(.52,.2+J*.2,s);d*=1.-.9*i(-.015,.015,f)-.5*i(.0,.01,f)-.7*i(.03,.02,f)+i(.01,.015,f);q=p;q.y-=.5;q.x=A(q.x)+.6;f=V(q,1.13);C=j(.03,.02,A(f))*j(.5,.6,q.y);d=n(d,aH*ae(1.-A(f-.015)/.03),C);d*=1.-.5*C*i(.005,.01,f)+.5*C*i(.017,.005,f);q.x=A(c.x-.5)-.35;q.y=c.y*9./4.-2.1;f=V(q,.13)*10.;a=b7(q)*49.;m=ao(a);s=a-m;v=j(.85,.9,ak(m));for(P a6=0;a6<2;++a6,f+=.3){d=n(d,aH*(b*.5+.2),j(.09,.03,A(f)));d*=1.+.7*D(i(.01,.05,f));}p.y=(c.y-.7)*9./4.;f=V(p,.43);a=atan(p.y,A(p.x))/aB;a=K(a,-.48);r=a;m=ao(a*=23.);s=a-m;J=aD(m)*.2-.1*j(.0,.1,-f);v=j(.1,.2,A(s-.5)-J);f+=v*.007;r=(1.-v)*D(i(.5,.3,r))*j(.25,.05,A(s-.5));f-=.17*r;C=i(.04,.0,-.4,f);d=n(d,aH*(b*.4+.4),C);d=bQ(d,p,31.,j(.1,.05,A(f+.15))*v);d*=n(1.,1.-i(.1,.2,.4,A(s-.5)-J),C*b);d*=1.-.7*D(i(.03,.03,f))-.7*D(i(.03,.03,f+.05))*v-.7*D(i(.0,.02,f+.05))*v-.3*j(.04,.06,-f)*v+.5*i(.02,.0,-.1,f)+i(.0,.01+.07*r,f)+i(.0,.01,f+.03)*v;p.y-=.05;d=bR(d,p,0.);l d;}H(_39){c.y=(c.y+8.)/9.;l bn(c);}H(_40){c.y=(c.y*4.+4.)/9.;l bn(c);}H(_41){U(c.y<.01)++c.y;c.y=c.y*4./9.;l bn(c);}H(_51){h b=B(c,e(5),.9,3.,4),t=b9(Y(c,4.,.01),e(7),.5,3.,5),E=Q(Y(c,4.,.05),e(9)),aA,W;k pt=bE(c,4.,.1+E*t*.05),d;e f=bB(pt.x);aA=ak(F(pt.yz));d=o(74,65,62)*(.8+.8*b*b);d+=i(.6,.3,E)*j(.3,.9,b*t)*.2;d*=1.-i(.5,.4,E)*j(.5,.7,t)*.1;d=n(d,o(86,74,78),i(.5,.1,b)*i(.7,.3,aA)*.7);d=n(d,o(105,90,70),i(.3,.1,t)*i(.3,.3,aA)*.3);W=i(.015,.005+.015*E,pt.x)+i(.4,.1,E*t)*.4;d*=1.-b*j(.015,.05,pt.x)*.7;d*=1.+W*b*(f.y-.5)*.7;d*=.9+.2*aA;d*=.9+.2*aC(Q(c-pt.yx,e(5)));l d;}H(_42){k d=_51(c);c-=.5;d=bR(d,c*.9,.02);l d;}k aM(e c){c*=1.5;h b=B(Y(c,7.,.02),e(9),.7,3.,2),t=b,E=Q(c,e(13)),a,s,f;k d=_51(c);e p;p.x=A(c.x-.75);p.y=K(c.y-.58,0.)*1.15;a=atan(p.x,p.y)/aB;s=F(a*7.+.5);f=V(p,.45);f-=.06*j(.4,.33,c.y);f-=.05*j(.15,.07,A(s-.5))*step(.63,c.y);f=aG(f,c.y-.107);U(c.y<.6)f=aG(f,A(p.x-.493)-.113);f=aG(f,V(p,.6)+.044*j(.48,.43,c.y));d=n(d,o(144,125,115)*t,I(f-.1,.005));d*=1.-.3*i(.12,.11,.1,f)+.5*i(.1,.005+.015*E*E,f);l d;}H(_29){l aM(e(5,0)/6.+c*e(1,4)/6.);}H(_30){l aM(e(1,0)/6.+c*e(4)/6.);}H(_31){l aM(c*e(1,4)/6.);}H(_32){l aM(e(5,4)/6.+c*e(1,2)/6.);}H(_33){l aM(e(1,4)/6.+c*e(4,2)/6.);}H(_34){l aM(e(0,4)/6.+c*e(1,2)/6.);}H(_52){h b=B(c,e(13,1),.7,2.,3);k d=_51(c)*.7;d*=1.-D(j(.4,1.,b));l d;}k bS(e c,e s){h b=B(c,e(5),.9,3.,4),E=B(c,e(31,3),.5,3.,3),t=.75+b*b;e p=c;k d=_51(c);U(c.y<.38)d=n(o(92,43,15),o(66,44,33),j(.1,.05,c.y))*t*(.5+.5*j(.0,.35,c.y));d+=b*s.y*D(i(.32,s.x*.015,c.y))+.3*b*i(.34,.05,c.y);d*=1.-i(.38,.005+b*b*.03,c.y)+3.*i(.15,.2,c.y)*(E-.5);l d;}H(_53){h b=B(c,e(5),.9,3.,4),t=.75+b*b,f,N,m;e p=c;k d=bS(c,e(1));p.x=mod(p.x,1./7.)-.07;p.y-=.21;f=V(e(.75*p.x,bj(p.y,.1)),.033);N=I(f,.005);f=V(e(.75*p.x,bj(p.y+.005,.09)),.033);m=I(f+.015);d=n(d,o(83,81,66)*t,(N-m)*j(.1,.3,c.y));d*=1.-j(.17,.25,c.y)*m;d+=D(i(.0,.015,f))*i(.32,.03,c.y);d*=1.+3.*pow(i(-.01,.03,f),4.)*i(.09,.03,c.y);f=V(e(.75*p.x,bj(p.y+.03,.1)),.033);d*=1.-I(f+.01,.02)*(1.-N);U(c.y>.09&&c.y<.3)d=aU(d,e((A(p.x)-.035)*36.,F(c.y*36.)-.5),.1);l d;}e cx(e p){p.x=A(p.x);e q=p,v;q.y-=.5;h f=V(q,.35),W,d;v=q/.35;q.y+=.25;q.x-=.15;f=M(f,R(q,e(.09,.05))-.1);W=aT(q,e(.15,.1))/5e1;d=.1+dot(e(v.y,a7(ae(1.-bv(v)))),e(.3,.3));q.y+=.2;q.x=p.x;d=K(d,ae(.4-L(q)));d+=.15*i(.0,.1,W)-.1*I(W+.12,.15);f=M(f,R(q,e(.15-j(-.15,.15,q.y)*.07,.03))-.09);d*=1.-j(.05,.25,q.x)*j(.2,.1,A(q.y+.12));q.y-=.06;d-=.5*I(aT(q,e(.05-j(-.1,.1,q.y)*.03,.06))/1e3+.03,.05);l e(ae(d),I(f,.02));}H(_54){h b=B(c,e(9),.7,2.,4),t=.75+b*b;k d=bS(c,e(4,.3));e p=c,s;p.x=mod(p.x,.2);p-=.1;s=cx(p*5.);l n(d,n(k(.5,.4,.3),k(.95,.8,.55),t)*t*s.x,s.y);}H(_50){h b=B(Y(c,5.,.02),e(5),1.,3.,5),E=Q(c,e(13));e p=b8(c,e(8)),q=F(p),aA=p-q;k d=o(91,61,42)*(.8+.8*b*b);d=n(d,o(70,30,15)*(.8+.8*b*b),aO(q,.1).z*.3);d*=1.-D(aO(q,.01+b*.05).z)*E*b*b;d*=1.+i(.4,.3,aO(q,.01+b*.07).z)*a7(b)*.3;d*=.9+.2*ak(aA)*(1.-aO(q,.1).z);d*=.9+.4*pow(b9(c-ak(aA/8.),e(5),.6,2.,4),4.);l d;}an(_27){h b=B(c-=.5,e(5),.9,3.,4),t=.75+b*b,E=Q(Y(c,7.,.02),e(17)),r=L(c),J=r>.4?38.:r>.32?28.:16.,a=F(atan(c.y,c.x)/b3),m=ao(a*J),a3=A(A(r-.41-E*.002)*1e2-6.),C=j(1.5,1.4,a3),bo[]=h[](1.,3.,-.145,-1.,2.,.166),f,bT,s;e p=c;k d=o(78,68,63);d*=1.+.5*D(i(.49,.005+.015*E*E+.015*b,r));d=n(d,o(83,52,47)*(.6+.4*E*E),C)*t;d*=1.-.5*i(1.5,.5,a3)+b*i(1.,.5+.5*E,A(r-.418)*1e2-5.)-b*i(.5,.08,F(a*J+.5))*C+b"
"*i(.5,.1,F(a*J+.55))*C;C=j(.34,.33,r);d=n(d*(1.-.5*C),o(83,52,47)*t,E*b*C);d=n(d,o(112,86,31)*t,C*D(i(.1,.15,.45,b)));d=n(d,o(77,66,77)*t,C*j(.5,.8,b)*.5);d*=1.-.7*i(.27,.34,.35,r);a3=r+E*.004;C=r>.21&&r<.31?1.:0.;d*=1.-i(.325,.005,a3)-i(.31,.005,a3)-b*D(i(.29,.005,a3))-b*D(i(.23,.01,a3))-.5*D(i(.21,.02,a3))+D(i(.3,.01,a3))*b+D(i(.22,.01,a3))*b-b*i(.5,.07,F(a*J+.5))*C;U(r<.23)m+=37.;U(r<.31)m+=73.;U(r<.31)m+=91.;d*=n(1.,.9+.2*aD(m),C);C=j(.01,.0,A(r-.411)-.039);m=ao(a*72.);p*=a8(m*5.);s=0.;f=1e6;P a6=0;for(;a6<6;a6+=3){f=b4(f,bT=dot(p,aV(e(bo[a6],bo[a6+1])))+bo[a6+2]);s+=s+h(bT>0.);}U(s==3.)++m;else m+=66.*s;m=aD(m);d=n(d,t*o(90,80,75),C);d=n(d,t*o(127,111,88),m*b*C);d*=n(1.,.7+.6*ak(m),C);d*=1.-C*D(i(.0,.006,f))*b+C*D(i(.006,.006,A(f)))*b*.5;m=ao(a*4.);p=A(c*a8(m*90.+45.));f=1e6;for(a6=0;a6<2;++a6,p=A(p*a8(45.)))f=b4(f,A(L(p-e(0,.12))-.16));C=j(.21,.2,r);a3=b5(b5(f,.012),.001);d*=1.-j(.21,.2,r)*I(.012-f)+b*C*D(i(.005,.005,f))-.5*C*D(I(a3-.001,.001));l G(d,(1.-j(.21,.15,r)*I(.028-f,.02))*j(.07,.087,r));}an(_28){e p=F(O)-.5;h b=B(a8(ac.x*333.)*p/(.8+.2*sin(ac.x*61.)),e(53),.7,2.,4);G d=G(1.-b*k(0,.3,1),1),am=al(aj,(a8(ac.x*30.)*p/(.8+.2*sin(ac.x*1.26)))+.5);d.T=n(d.T,am.T,am.w);am=al(aj,O);d.T=n(d.T,am.T,am.w)*a2();l d;}H(_55){h b=B(c,e(13),.9,3.,4),E=B(c,e(7),.9,3.,4);k d=n(o(60,50,50),o(87,47,37),D(j(.7,.25,E)))*(.7+.8*b*b),g;c=Y(c,31.,.003);aX(g,c,a7(j(.0,.9,Q(p[m],e(93)))));d*=1.-(g.y+.4)*D(b*g.z)*g.z;l d;}H(_59){h b=B(c,e(5),.9,3.,4);k d=o(67,64,63)*(.6+.5*b),g;c=Y(c,31.,.003);aX(g,c,a7(Q(p[m],e(53,93))));d*=1.-.3*g.y*g.z*g.z;l d;}an(_22){c=Y(c,7.,.01);h b=B(c,e(9),.7,2.,4),E=B(c,e(13),.5,2.,4),C=j(.6,.9,B(Y(c,5.,.03),e(11),.6,2.,4));k d=o(127,70,55)*(.85+.3*b);d*=1.-.2*C-.2*D(j(.3,.0,b*b))-.3*j(.6,.77,E)+.3*j(.5,.9,b);d+=.5*D(j(.5,1.,B(c,e(17),1.,2.,3)));l G(d,C);}Z _24(){G d=al(aj,O);e c=F(O);c.y-=.2*ac.x;h b=B(Y(c,7.,.02),e(5),.9,2.,4);X=G(n(d.T,o(25,10,8)*b,d.w)*a2(),1);}H(_23){e p=c-.5;p=Y(p,17.,.007);p.x*=2.-c.y*1.5;h b=B(c,e(9),.7,2.,4),E=Q(c,e(7)),f=L(p),s;k d=_22(c).T;s=F(f*=13.);U(f<=6.){d*=1.-pow(j(6.,.5,f+b*b),6.);E=j(.3,.8,E);d*=1.-E*b*D(i(.4,.3,s))+E*b*i(.6,.4,s);}l d;}H(_25){c=Y(c,13.,.003);h b=B(c,e(7),.9,3.,4),E=B(c,e(5),.5,2.,4),t=.5+b;k d=o(80,38,34),v=cn(c,e(23));d=n(d,n(o(180,125,118),o(165,78,51),E),b*i(.0,.4+E*.4,v.z))*t;l d;}H(_26){h b=B(c,e(13),.9,3.,4);k d=o(60,50,46)*(.875+b*b);l d;}H(_57){h b=B(c,e(7),.9,3.,4),E=B(c,e(3),.5,3.,4);k d=n(o(103,56,53),o(73,58,71),j(.1,.7,E))*(.75+b*b);l d;}H(_58){h b=B(c,e(13),.9,3.,4),E=Q(Y(c,5.,.05),e(9)),f=aC(F(c.x*4.)),C=j(.1,.15,f)*j(1.,.99,c.y);k d=o(51,44,44);d=n(d,o(73,55,52),j(.2,.2,b)*E*C);d=n(d,o(69,60,66),j(.7,.1,b)*b*C);d=n(d,o(99,77,77),j(.1,.5,E)*E*C*b*b*.3);d*=.6+.3*b+.3*b*b;d*=1.+.9*D(i(.21,.02+.1*E,f+b*.05))*C*b;d*=1.-D(j(.49,.5,A(c.y-.5)));d*=1.-j(.05,.2,f)*j(.16,.1,f);d*=1.+i(.99,.007,c.y);l aU(d,e(f-.4,F(c.y*8.)-.5),.07);}k bU(e c,h s){h b=B(c,e(3,1.+s+s),.7,2.,4),f=aC(c.x),C;c.y*=2.;k d=n(o(71,60,58),o(110,88,77),j(.1,.05,f))*(.7+.6*b);d*=1.-j(.05,.0,c.x)*(1.-b*b);d*=1.+.5*i(.05,.02,c.x);e p=e(f-.35,F(c.y*s)-.5);G J=bC(p,.11);C=I(J.w);d*=1.-.7*bD(p,1.1)*(1.-C);d=n(d,(J.y>.0?o(128,105,88):o(200,111,66)*j(-.2,.7,J.z))*(.4+2.*b*pow(ae(bd(J.yz*.7)),4.))*(1.-.6*i(-.1,.4,J.y)),C);l d;}H(_35){l bU(c,4.);}H(_36){l _35(c.yx);}H(_37){l bU(c,1.);}H(_45){h b=B(c,e(40,5),.9,3.,4);k d=o(110,110,98)*(.8+.8*b*b);U(c.y<1./4.)d*=.5;d*=1.-.4*j(.4,.0,b)+.5*j(.02,.0,c.y)+.2*i(.24,.01,c.y);l d;}H(_46){e p=c,q;p.y*=22.;q=F(p);h b=B(c,e(3,23),1.,2.,6),E=B(c,e(3,33),.7,3.,4),aA=ak(p.y-q.y);k d=o(92,67,53)*(.8+.8*b*b);d*=1.-D(j(.1,.0,M(q.y,1.-q.y)))*b;d*=1.-.2*smoothstep(.3,.7,E);d*=.8+.3*b*aA;l d;}H(_47){h b=B(c,e(13),.9,3.,4),x=c.x*16./3.;k d=_46(c)*j(.15,.21,c.x);U(x<1.)d=o(59,48,49)*(.7+.6*b);d*=1.+.5*i(.05,.05,aC(x));l aU(d,e(A(c.x-3./32.)-.07,mod(c.y,.1)-.05),.004);}H(_48){e p=b8(c,e(6,4)),q=F(p),a1=q;h b=B(Y(c-=.5,5.,.03),e(13),.9,2.,3),E=Q(c,e(73,7)),t=(.75+b*b)*(.8+.4*cc(c.x*93.)),r;k d=k(.25*t);a1.y+=a1.y*2.-.01-.03*E;r=L(a1-=clamp(a1,e(.49,.5),e(.51,3)));d*=1.-.7*b*D(j(.07,.03,A(r-.5)))+.5*b*i(.35,.1,r)*D(j(.2,.1,q.y))-.3*D(j(.8,1.,q.y))-.3*(j(.3,.1,q.y))*j(.4,.6,r)+.2*D(j(.5,.1,q.y))*j(.45,.4,r);l d;}H(_61){h b=B(c,e(5),.9,3.,4),ad=F(c.y*10.);k d=n(o(53,48,42),o(38,38,36),b);d*=.6+b*.8;d*=1.-.5*D(i(.5,.5,ad));d*=1.+.5*D(i(.25,.25,ad));d*=1.+.5*D(i(.65,.35,ad));l d;}H(_60){h b=B(c,e(7,3),.9,3.,4),ad=c.y+b*.04,u=1.-.15;k d=n(o(59,48,40),o(110,108,102),b*b);u=n(u,.5,i(.34,.05,c.y));u=n(u,.5,j(.08,.05,A(c.y-.7)));u=n(u,.3,i(.7,.03,c.y));u=n(u,1.5,i(.01,.03,c.y));u=n(u,2.2,i(.89,.1,ad));u=n(u,1.6,j(.07,.04,A(c.y-.44)));u=n(u,2.5,i(.5,.04,ad));u=n(u,1.7,i(.18,.04,ad));l d*u;}H(_62){h b=B(c,e(5,3),.9,3.,4);k d=n(o(74,66,55),o(99,90,78),b*b);c.x*=2.;e p=be(c,e(.5,.625),e(1.5,.625));h f=L(p-c),C=j(.22,.20,f),u=1.-.15*C;u=n(u,.5,j(.7,.9,c.y)*C);u=n(u,1.-bB(f).y*.5,i(.22,.04,f));u=n(u,.6,D(i(.19,.05,f)));u=n(u,.5,j(.05,0.,c.y));u=n(u,.5,i(.26,.05,c.y));u=n(u,1.7,j(.93,1.,c.y));u=n(u,1.7,i(.23,.04,c.y));l d*u;}an(_63){h b=B(c,e(1,5),.4,3.,4);k d=n(o(56,49,43),o(142,136,136),b);c=.5-A(c-.5);c.y*=4.;h a=i(.0,.1,L(c-be(c,e(.41,.5),e(.42,3.5)))),f=bc(c),u=1.-.7*K(0.,1.-f/.15);u*=1.-.8*j(.24,.31,M(f,c.y-.1));d+=o(80,80,20)*a;l G(d*n(u,2.7,a),a);}an(_66){h b=B(c,e(1,5),.4,3.,4);k d=n(o(56,49,43),o(142,136,136),b);c=.5-A(c-.5);c.y*=8.;h f=L(c-be(c,e(.27,.3),e(.27,7.7))),a=i(.0,.17,f),u=1.-.5*i(.17,.07,f);d+=o(80,80,20)*a;l G(d*n(u,2.7,a),a);}an(_64){e p=A(c-.5);h b=B(c,e(1),.4,3.,4),r=L(p),a=j(.37,.33,r)*(.5+2.*b),u=1.+.0*j(.08,.03,A(r-.41));k d=n(o(56,49,43),o(142,136,136),b);u=n(u,7.,j(.44,.1*b,r));u*=1.-.5*D(i(.46,.04,r));u*=1.-.4*D(i(.36,.04,r));l G(d*u,a);}an(_65){h b=B(c,e(5),.9,3.,4),f=bA(bM(c-=.5,.35),A(V(c,.4)),.02),a=pow(I(f-.02,.15),8.),N=M(K(R(c,e(.46)),-V(c,.51)),A(V(c,.44)));k d=o(76,62,47)*(.8+.8*b*b);d*=1.+(b+.5)*I(A(N)-.01,.01);d*=1.-j(.1,.05,f)*I(V(c,.4));l G(d+1.*k(1,1,.3)*a,a);}h bh(e c,h t){c.x=A(c.x);c.y-=.07;h f=aT(c,e(.31,.12-t*.02))/50.;f=K(f,-aT(c-e(0,.01+t*.01),e(.28,.07+t*.01))/50.);f=K(f,-R(c-e(.0,.1),e(.22-t*.02,.12)));f=K(f,-R(c-e(.0,.1),e(.084-t*.012,.31)));f=M(f,aS(c-e(.0,-.09),e(i(-.09,.32,c.y)*(.04-t*.015),.32)));f=M(f,aS(c-e(.11-t*.02,-.21),e(i(-.07,.3,c.y)*(.03-t*.01),.15)));l f;}an(_1){c-=e(.48,.5);h f=bh(c,0.),b=L(c)-.47;k d=1.-k(.5,1,1)*I(K(.007-f,b+.04));l G(d,1)*I(b);}H(_2){c-=.5;e r=e(dFdx(c.x),dFdy(c.y));c/=r/aE(r);c*=.8;c.y-=.03;h b=B(c,e(53,5),.7,2.,3),t=.8+.8*b*b,f=bh(c,1.),W=bh(c+e(0,.002),1.),u=(W-f)*5e2+.5;k d=k(.3*t,0,0)*I(f,.004);d*=1.-j(.1,.33,A(c.x))-.5*j(.1,.3,A(c.y-.1));d=d+.3*i(.0,.004,f)*i(.1,.2,c.y)*j(.0,.1,A(c.x-.05))*u+.5*i(.005,.005,f)*j(.2,-.1,c.y)*ae(-u);l d;}h bV(e c,h s,h m,h cy){m=(c.y-D(A(c.x-.5))*cy)*s-m;l 2.*i(.5,.4,m)*(F(m)-.5);}an(_75){h b=B(c,e(5,9),.9,3.,4),t=.8+.8*b*b,E=B(c,e(5,9),.9,3.,2),x=A(c.x-.5),f;k d=o(77,60,44)*t;e p=c*e(1,2)-e(.5,.7);d*=1.-.55*I(aG(V(p,.3),bh(a8(45.)*p*.8,0.)-.01));d*=1.+D(j(.6,.9,b))+i(.2,.5,c.y)*i(.2,.3,x)*bV(c,4.,.2,4.);for(h S=6.;S<9.;++S)d*=1.+i(.8,.5,c.y)*i(.2,.3,x)*bV(c,12.,S,1.);f=c.y-.81-D(ae(x*4.))*.09;d=n(d,o(82,66,60)*t,j(.0,.01,f));d*=1.-.5*(i(.01,.02,f))+.5*(i(.02,.01,f));f=.15*(1.-c.y);f=R(c-.5,e(.49)-f)+E*.1*a7(1.-c.y)-f;l G(d*D(I(f+.01,.05)),I(f));}an(_76){G d=al(aj,c);U(d.w<.5)discard;d.T*=D(a2()*.5);l d;}an(_77){c*=e(256,64);c.y+=2.;h f=V(c-e(81,30),11.);f=K(f,c.x-80.);f=K(f,-V(c-e(84,26),9.));f=M(f,R(c-e(73,37),e(4,9))-4.);f=K(f,-R(c-e(73,37),e(0,7))+1.);f=M(f,R(c-e(91.5,47),e(4,19))-4.);f=K(f,-R(c-e(91.5,47),e(0,17.5))+1.);f=M(f,R(bk(c,111.)-e(105.+j(23.,50.,c.y)*3.,43),e(3.5,19)));f=M(f,R(c-e(111,32),e(4,3)));f=M(f,R(c-e(126,37),e(3,13)));f=M(f,R(c-e(125.5+j(23.,50.,c.y)*10.,44),e(3.5,6)));f=M(f,R(c-e(136.5-j(23.,50.,c.y)*9.,32),e(3.5,8)));f=M(f,R(c-e(148.5,37),e(7,13)));f=K(f,-R(c-e(155,33),e(6,3)));f=K(f,-R(c-e(155,43),e(6,2)));f=M(f,R(c-e(168,37),e(3.5,13)));f=M(f,R(c-e(178.,37),e(3.5,13)));f=M(f,R(c-e(188,37),e(3.5,13)));f=K(f,c.y-50.);l G(I(f,.8),0,0,ak(c*511.));}Z _78(){k d=al(aj,O*2.).T*step(.5,F(ac.x*.5));d=n(d*a2(),k(.5,0,0),i(F(ac.x*2.),1./64.,F(O.y)));X=G(d+bJ(Ref)*.25+al(aj,O+ak(ac.xx)).w*.1,1);}Z _79(){e c=F(bK(Pos.T,bL(Nor))/128.);c.x+=ac.x/33.;h b=B(c,e(7),.9,2.),S=F(Pos.z/128.-.375);X=G(2.*o(95,85,80)*S*S*S*S*n(1.,b,.5),0.);}Z _80(){e c=F(O),p=c;p.y"
"+=p.y-ac.x;c.x+=sin(p.y*7.)*.2*c.y;h E=B(p+sin(p.yx*aB*9.+e(0,ac.x*9.))*.015+Q(p,e(5))*.1,e(13),.4,3.,4),b=R(c-e(.5,.25),e(.05*D(j(.4,.2,c.y)),.1)),C=D(I(b+E*.25,.35));X=j(.0,.4,C)*G(5,2,.7,0);}Z _0(){h u=dot(Nor,aV(k(2,0,8)));u=u*.4+.7;e c=bK(Pos,bL(Nor));k d=k(.5);d*=co(k(F(aZ*ac.w+.25),1.,1.));X=G(d*u,1);}Z _6(){G d=al(aj,O);X=G(d.T*n(a2(),k(1),d.w),1);}Z _68(){G d=al(aj,O);h r=L(F(O)-.5);h s=n(.4,8.,F(ac.x*1.5));X=G(d.T*a2()+o(240,130,5)*i(.1,.05,r/s)*j(.37,.32,r),1);}Z _5(){k d=al(aj,O).T;X=G(d*a2(),1);}Z _7(){G d=al(aj,O);d.T*=1.+d.w*bJ(Ref);X=G(d.T*a2(),1);}Z _71(){X=G(0);}Z _72(){k f=aV(Pos-Cam.T);f.z=f.z*4.+2.;e c=aV(f).xy*2.;h b=j(.2,1.,B(c-ac.x*e(.1,.2),e(5),.5,2.,6));c.y*=1.5;h s=j(.3,1.,B(c-ac.x*e(.1,.18),e(5),.6,2.,6));X=G(k(b,0,0)+o(80,30,8)*s*s*2.,1);}Z _73(){e c=Y(O/8.,ac.x*.5,2.,.05);h b=B(c,e(7),.9,2.,4);k d=o(91,22,14)*(.2+1.6*b);d=n(d,o(144,44,0),i(.6,.2,B(c,e(3),.7,3.,4)));d=n(d,o(244,144,66)*b*2.,D(i(.55,.25,B(c,e(11),.5,2.,4))));X=G(d*ae(aE(a2())),1);}Z _74(){_73();}Z _3(){X=al(aj,(.5+O*127.)/128.,2.5);X.T*=.7+.3*Q(O,.5/fwidth(O));}Z _4(){X=al(aj,O)*Clr;}"
;

// src/demo/data/shaders/vertex_shaders.glsl: 3154 => 1558 (49.4%)
static constexpr char g_vertex_shaders[] =
"#define c void\n"
"#define f vec4\n"
"#define h location\n"
"#define k gl_Position\n"
"uniform mat4 MVP;uniform f Time,Cam;layout(h=0)in f e;layout(h=1)in f i;layout(h=2)in vec3 j;layout(h=3)in f m;out vec3 Pos,Nor,Ref;out vec2 UV,LUV;out f Clr;c _0(){k=MVP*e;Pos=e.xyz;Nor=j;UV=i.xy;LUV=i.zw;Ref=normalize(reflect((e-Cam).xyz,j));}c d(){k=e;UV=e.xy*.5+.5;}c _4(){k=f(2.*e.x-1.,1.-2.*e.y,1,1);UV=i.xy;Clr=m;}c _8(){d();}c _10(){d();}c _11(){d();}c _67(){d();}c _12(){d();}c _69(){d();}c _9(){d();}c _14(){d();}c _15(){d();}c _16(){d();}c _18(){d();}c _19(){d();}c _20(){d();}c _21(){d();}c _49(){d();}c _50(){d();}c _51(){d();}c _52(){d();}c _53(){d();}c _54(){d();}c _55(){d();}c _59(){d();}c _56(){d();}c _38(){d();}c _39(){d();}c _40(){d();}c _41(){d();}c _42(){d();}c _29(){d();}c _30(){d();}c _31(){d();}c _32(){d();}c _33(){d();}c _34(){d();}c _22(){d();}c _23(){d();}c _25(){d();}c _26(){d();}c _27(){d();}c _57(){d();}c _58(){d();}c _35(){d();}c _36(){d();}c _37(){d();}c _43(){d();}c _44(){d();}c _45(){d();}c _46(){d();}c _47(){d();}c _48(){d();}c _60(){d();}c _61(){d();}c _62(){d();}c _63(){d();}c _66(){d();}c _64(){d();}c _65(){d();}c _1(){d();}c _2(){d();}c _75(){d();}c _77(){d();}c _3(){d();}c _5(){_0();}c _17(){_0();}c _68(){_0();}c _13(){_0();}c _70(){_0();}c _6(){_0();}c _79(){_0();}c _80(){_0();}c _78(){_0();}c _7(){_0();}c _28(){_0();}c _71(){_0();}c _72(){_0();}c _74(){_0();}c _24(){_0();}c l(float n,float o,float u){k+=o*MVP*f(j,0)*sin(6.28*(Time.x*u+dot(e.xyz/n,vec3(1))));}c _76(){_0();l(30.,3.,.2);l(100.,3.,.7);}c _73(){_0();l(100.,3.,.1);}"
;

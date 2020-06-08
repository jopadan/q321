#pragma once

// auto-generated, do not modify
static_assert(0xe4812a77U == Demo::Shader::Version, "Shader definition mismatch, please recompile the shader compiler & shaders");

// src/demo/data/shaders/fragment_shaders.glsl: 65642 => 27152 (41.4%)
static constexpr char g_fragment_shaders[] =
"#define e vec2\n"
"#define h float\n"
"#define k vec3\n"
"#define l return\n"
"#define n mix\n"
"#define A abs\n"
"#define F fract\n"
"#define G vec4\n"
"#define K length\n"
"#define L max\n"
"#define M min\n"
"#define O UV\n"
"#define Q int\n"
"#define T xyz\n"
"#define U if\n"
"#define ac void\n"
"#define ad Time\n"
"#define ak Texture0\n"
"#define al texture\n"
"#define ao floor\n"
"#define a2 sqrt\n"
"#define aT normalize\n"
"#define b0(x)((x)*(x)*(3.-2.*(x)))\n"
"#define E(x)((x)*(x))\n"
"#define aV(x)dot(x,x)\n"
"#define Y(x)clamp(x,0.,1.)\n"
"#define u(r,g,b)(k(r,g,b)/255.)\n"
"#define a8(v)i(.5,.5,v)\n"
"#define H(a5)k a5(e);ac a5(){Z=G(a5(O),1);}k a5(e c)\n"
"#define an(a5)G a5(e);ac a5(){Z=a5(O);}G a5(e c)\n"
"#define aW(bX,c,bY){e p[3];h r[3];p[0]=c;p[1]=c+dFdx(c);p[2]=c+dFdy(c);for(Q m=0;m<3;++m)r[m]=bY;bX=k(bZ(e(r[1],r[2])-r[0]),r[0]);}\n"
"#define b1(a5,ca)k a5(e p,e b2){p*=b2;e D=ao(p),S=p-D,b3,g,N,r;h aN=8.,aX=aN,f;for(Q m=0;m<9;++m){g=e(m%3-1,m/3-1);N=cb(mod(D+g,b2));r=g+N-S;f=ca;U(f<aN){aX=aN;aN=f;b3=r;}else U(f<aX){aX=f;}}l k(b3,aX-aN);}\n"
"uniform G ad,Cam;uniform sampler2D ak,Texture1;in k Pos,Nor,Ref;in e O,LUV;in G Clr;out G Z;h aB=3.1415927,b4=2.*aB,aY=1.618034;e cc(h m){h bh=1.324718;l F(.5+m/e(bh,bh*bh));}h aC(h m){l F(.5+m*aY);}h cd(h S){h m=ao(S);l n(aC(m),aC(m+1.),b0(S-m));}h aZ(e v){l M(v.x,v.y);}h aZ(k v){l M(v.x,M(v.y,v.z));}h aZ(G v){l M(M(v.x,v.y),M(v.z,v.w));}h aD(e v){l L(v.x,v.y);}h aD(k v){l L(v.x,L(v.y,v.z));}h aD(G v){l L(L(v.x,v.y),L(v.z,v.w));}h bc(e v){l v.x+v.y;}h b5(h a,h b){l A(a)<A(b)?a:b;}h b6(h x,h s){l A(x)-s;}h bi(h x,h s){l sign(x)*L(0.,A(x)-s);}e bZ(e v){h o=dot(v,v);l o>0.?v/a2(o):v;}h i(h ce,h cf,h x){l 1.-Y(A(x-ce)/cf);}h j(h b7,h cg,h x){l Y((x-b7)/(cg-b7));}h i(h a,h b,h d,h x){l M(j(a,b,x),j(d,b,x));}e ah(h x){l e(sin(x),cos(x));}mat2 a9(h x){e v=ah(radians(x));l mat2(v.y,v.x,-v.x,v.y);}h b8(e p){l F(atan(p.y,p.x)/b4);}e V(e c,h p,h s){l c+sin(c.yx*aB*p)*s;}e V(e c,h t,h p,h s){l c+sin(c.yx*aB*p+t)*s;}h bj(h v,h B){l B-A(v-B);}e bj(e v,h B){v.x=bj(v.x,B);l v;}e b9(e c,e s){c.x+=ao(c.y*s.y)*(.5/s.x);l F(c)*s;}k aO(e c,h r){l k(c-=clamp(c,r,1.-r),K(c)/r);}k aO(e c,e s,h r){s=s.yx/aZ(s);c*=s;l k(c-=clamp(c,e(r),s-r),K(c)/r);}h af(e p){k q=F(p.xyx*.09153);q+=dot(q,q.yzx+19.19);l F((q.x+q.y)*q.z);}h af(h p){p=F(p*.1031);p*=p+33.33;p*=p+p;l F(p);}k cz(h p){k au=F(k(p)*k(.1031,.1030,.0973));au+=dot(au,au.yzx+33.33);l F((au.xxy+au.yzz)*au.zyx);}e cb(e p){k au=F(k(p.xyx)*k(.1031,.1030,.0973));au+=dot(au,au.yzx+33.33);l F((au.xx+au.yz)*au.zy);}G ch(h p){G av=F(G(p)*G(.1031,.1030,.0973,.1099));av+=dot(av,av.wzxy+33.33);l F((av.xxyz+av.yzzw)*av.zywx);}G ch(e p){G av=F(G(p.xyxy)*G(.1031,.1030,.0973,.1099));av+=dot(av,av.wzxy+33.33);l F((av.xxyz+av.yzzw)*av.zywx);}h ai(h x,h p){l af(mod(x,p));}h c0(h x){h m;l n(af(m=ao(x)),af(m+1.),b0(x-m));}h P(h x,h p){h m;l n(ai(m=ao(x),p),ai(m+1.,p),x-m);}h ai(e p,e s){l af(mod(p,s));}h P(e p,e s){p*=s;e m=ao(p);p-=m;p*=p*(3.-2.*p);h ci=ai(m+e(0,0),s);h cj=ai(m+e(0,1),s);h ck=ai(m+e(1,1),s);h cl=ai(m+e(1,0),s);l n(n(ci,cl,p.x),n(cj,ck,p.x),p.y);}h C(e p,e aE,h bk,h bl,Q bm){h aP=P(p,aE),aF=1.,tw=1.;for(Q m=0;m<bm;++m){p=F(p+aY);aE*=bl;aF*=bk;aP+=P(p,aE)*aF;tw+=aF;}l aP/tw;}h bA(e p,e aE,h bk,h bl,Q bm){h aP=a8(P(p,aE)),aF=1.,tw=1.;for(Q m=0;m<bm;++m){p=F(p+aY);aE*=bl;aF*=bk;aP+=a8(P(p,aE))*aF;tw+=aF;}l aP/tw;}e bd(e p,e a,e b){e ab=b-a,ap=p-a;h t=Y(dot(ap,ab)/dot(ab,ab));l ab*t+a;}h R(e p,e b){e f=A(p)-b;l M(L(f.x,f.y),0.)+K(L(f,0.));}h aQ(e p,e b){l aD(A(p)-b);}h W(e p,h r){l K(p)-r;}h aR(e p,e r){l W(p/r,1.)/M(r.x,r.y);}h aG(h a,h b){l L(a,-b);}h bB(h a,h b,h J){h ae=Y(.5+0.5*(b-a)/J);l n(b,a,ae)-J*ae*(1.-ae);}e bC(h x){e f=e(dFdx(x),dFdy(x));l f/L(K(f),1e-8);}h I(h s,h f){l Y(1.-s/f);}h I(h s){l Y(1.-s/fwidth(s));}G bD(e c,h s){l G(c/=s,a2(Y(1.-aV(c))),K(c)-1.);}h cm(k D){h o=bc(D.yz)*.7;l pow(Y(o),4.)+o;}h bE(e c,h s){c/=s;c.y+=.06;c.x*=2.;l j(.3,.0,K(c));}k aS(k d,e c,h s){G b=bD(c,s);d*=1.+cm(b.T)*I(b.w)*.5;d*=1.-E(bE(c,20.*s))*(1.-I(b.w))*.3;l d;}k bF(e p,h ah,h cn){k X=k(-1,0,1),r=k(1e5);e a0=ao(p*ah),c1=X.yy;p-=(a0+.5)/ah;h aj=.5*ai(a0+X.yy,e(ah)),aI=.5*ai(a0+X.xy,e(ah)),aJ=.5*ai(a0+X.yz,e(ah)),aK=.5*ai(a0+X.zy,e(ah)),aL=.5*ai(a0+X.yx,e(ah)),bG=.5*ai(a0+X.xz,e(ah)),bH=.5*ai(a0+X.zz,e(ah)),bI=.5*ai(a0+X.zx,e(ah)),bJ=.5*ai(a0+X.xx,e(ah));e[4]a6,o;U(mod(a0.x+a0.y,2.)<.5){o[0]=1.+e(aL-aI,aj-bJ);o[1]=1.+e(aK-aL,aj-bI);o[2]=1.+e(aJ-aI,bG-aj);o[3]=1.+e(aK-aJ,bH-aj);a6[0]=e(aL,aj);a6[1]=e(aL,aj);a6[2]=e(aJ,aj);a6[3]=e(aJ,aj);}else{o[0]=1.+e(aj-bJ,aI-aL);o[1]=1.+e(bI-aj,aK-aL);o[2]=1.+e(aj-bG,aJ-aI);o[3]=1.+e(bH-aj,aJ-aK);a6[0]=e(aj,aI);a6[1]=e(aj,aK);a6[2]=e(aj,aI);a6[3]=e(aj,aK);}for(Q m=0;m<4;m++){a6[m]+=o[m]*(e(m&1,m/2)-.5);o[m]/=ah;h bx=aQ(p-a6[m]/ah,o[m]/2.-cn/ah);U(bx<r.x)r=k(bx,a0+a6[m]);}l r;}b1(bn,bc(A(r)))b1(bo,K(r))h bK(k p){p=aT(p);k a=mod(degrees(atan(p,p.yzx)),360.);l P(a.x/8.,45.)*j(.9,.0,A(p.z))+P(a.y/8.,45.)*j(.7,.0,A(p.x));}e bL(k p,Q ax){l(ax==0)?p.yz:(ax==1)?p.xz:p.xy;}Q bM(k D){D=A(D)+k(.01,.02,.03);h B=aD(D);l(B==D.x)?0:(B==D.y)?1:2;}k co(k d){k rgb=Y(A(mod(d.x*6.+k(0,4,2),6.)-3.)-1.);rgb*=rgb*(3.-2.*rgb);l d.z*n(k(1.),rgb,d.y);}k a3(){k f=Cam.T-Pos;h b=C(f.xy/256.*a9(Cam.w),e(3),.7,3.,4),o=1.-j(14.,-6.,K(f.xy)-b*8.)*j(128.,48.,f.z)*step(.1,Nor.z);l al(Texture1,LUV).T*2.*o;}H(_8){h b=C(c,e(5),.9,3.,4);k d=n(u(48,41,33),u(103,101,104),b);l d;}H(_9){h b=C(c,e(3),.9,3.,4);k d=n(u(49,45,43),u(81,75,78),b*b);l d;}H(_10){h b=C(c,e(7),.9,3.,4);c.x*=-1.5;c.y+=c.x*.5;c.x=1.-c.x+c.y;c=F(c*28.);h S=Y(1.-K(.1-c));S*=j(.6,.2,K(.6-c));S*=j(.6,.8,K(.1-c));S*=j(.2,.6,b)*2.+1.;h o=1.-j(.2,b+2.,aD(A(c-.5)));l k((S+1.)*n(.21,.29,b*b)*o);}H(_11){h b=C(c,e(7),.9,3.,4),r=K(c-.5);k d=_10(c);d=n(d,d*u(70,61,53),j(.5,.2,r+b*b*b));l d;}h bN(e c,h s){h f=1e6,m=0.;for(;m<5.;++m){e p=e(0,-s)*a9(m*72.);f=M(f,K(c-bd(c,p,p*a9(144.))));}l f;}an(_12){k d=_11(c);c=F(c)-.5;h b=C(c,e(3),.9,3.,4),f=M(A(K(c)-.4),bN(c,.35));l G(d,I(f-.02+b*.02,.01));}ac _13(){G d=al(ak,O);Z=G(d.T*a3()+u(111,55,0)*d.w*(sin(ad.x*aB)*.5+.5),1);}H(_68){h b=C(c,e(7),.9,3.,4);k d=_10(c);h r=K(c-.5);h B=j(.46,.45,r);h o=1.5-1.5*j(.0,.3,r*r);o=n(o,2.5,i(.42,.07,r));o=n(o,3.5,i(.44,.05,r));o=n(o,2.6,i(.36,.03,r));h D=.3+.2*j(.35,.30,r);o*=1.-D*j(.3,.7,b);o*=1.-.3*E(j(.13,.05,r));o=n(o,2.5,j(.04,.01,r));o-=o*i(.03,.01,r)*.7;d=n(d,u(68,66,54)*o,B);d*=1.-E(i(.34,.02,r));d*=1.-E(i(.46,.03,r));d*=1.-i(.41,.03,r)*.7;l d;}e cp(e c,h s){l e(1.-K(c)/s,I(K(c)-s));}an(_70){h b=C(c,e(5),.9,3.,4),t,N,J,r;k d=_10(c);e a1,v;a1.x=A(c.x-.5);a1.y=M(c.y,.4);r=K(a1-e(0,.4))-(.18-.06*j(.4,1.,c.y));J=.25-.15*j(.9,.96,c.y)+.03*E(j(.82,.86,c.y))+.07*j(.8,.2,c.y)+.07*E(j(.35,.22,c.y))-.07*j(.22,.0,c.y);N=R(c-e(.5,.5),e(J,.46));N=L(N,-R(a1,e(.15,.03))+.06);d=n(d,k(.6,.55,.55)-c.y*.3+b*.2,I(N));d*=1.-.7*i(.0,.013,N);d*=1.-(r/.5-.1)*I(N);t=L(r,c.y-.96);N=A(t-.02)-.03;N=L(N,c.y-1.+a1.x*.5);N=L(N,c.y-.96);d=n(d,k(1,1,.9)-c.y*.55,i(-.01,.01,N));d=n(d,k(.2*b+.1),I(t,.01));d*=1.-.2*i(.0,.05,t)*I(N);v=cp(a1=c-e(.5,.4),.02);d*=1.+u(111,80,70)*i(.03,.01,K(a1));d*=1.-.5*i(.02,.01,K(a1));d=n(d,u(111,66,44)*(v.x*1.5+.2),v.y);l G(d,I(t-.03,.02));}ac _71(){G d=al(ak,O);e c=F(O);c.x=A(.5-c.x);h t=F(-ad.x),r=K(c-e(0,.4)),o=t*pow(L(0.,1.-r),4.)*d.w;U(t>.75)o+=j(.03,.01,A(F(c.y+c.x*.5+t*2.)-.45))*j(.1,.08,c.x);Z=G(d.T*a3()+u(180,150,5)*o,1);}H(_14){h b=C(c,e(5),.9,3.,4);k d=n(u(44,14,16),u(93,63,63),b*b);l d;}k bO(e c){h X=3e-3,a=0.;e g=e(6),r=bn(c,g).xy;for(Q m=0;m<9;++m)a+=bc(A(bn(e(m%3-1,m/3-1)*X+c,g).xy-r));l k(c+r.xy/g,a);}H(_15){h b=C(c,e(3),.9,3.,4);k d=n(u(80,70,72),u(128,120,120),b*b);k v=bO(c);d*=n(.95,1.1,P(v.xy,e(6)));d=n(d,u(168,128,120),j(.5,1.,v.z)*b*.7);l d;}an(_16){h b=C(c,e(3),.9,3.,4);k d=n(u(80,70,72),u(128,120,120),b*b);k v=bO(c);h B=j(.5,1.,v.z);h r=j(.4,.2,K(.5-F(v.xy)));d*=n(.95,1.1,P(v.xy,e(6)))-2.*r*b*b;d=n(d,u(168,128,120),B*b*.7);l G(d,B*r);}ac _17(){G d=al(ak,O);Z=G(d.T*a3()+i(.5,.125,F(O.y*.5+ad.x*.5))*d.w*.3,1);}H(_18){h b=C(c,e(5),.9,3.,4);k pt=bF(c,8.,.31);k d=n(u(66,58,55),u(118,107,105),b);h o=1.-.5*j(.034,.036,pt.x);o=n(o,1.4,i(.033,.004,pt.x));l d*o;}h cq(e c){h b=P(c,e(64)),S=0.,f=1e6;for(;S<11.;++S)f=bB(f,A(K(.5-A(c-cc(S)))-n(.36,.29,aC(S+.7)))-n(.015,.03,b),.01);l f*1e2;}k bP(e c){k s,p;for(Q m=0;m<3;++m){p=k(c,0);p[m]+=1e-4;s[m]=cq(p.xy);}l k(aT(s.xy-s.z),s.z);}H(_19){h b=C(c,e(5),.9,3.,4),o;k d=n(u(51,46,43),u(165,147,143),b*b),f=bP(c);o=1.-.5*(f.y-f.x)*i(.5,3.,f.z)*j(1.,.0,f.z);l d*o*.8;}H(_20){h b=C(c,e(3),1.1,3.,4),o;k d=n(u(51,46,43),u(165,147,143),b*b),f=bP(c);o=1.-.5*(f.y-f.x)*i(.5,3.,f.z)*j(1.,.0,f.z);l d*o;}H(_21){h b=C(c,e(5),.9,3.,4),o=.18*(.7+b*b);k g;c=V(c,13.,.007);aW(g,c,E(j(.3+b*.2,.9,C(p[m],e(23),.5,2.,4))));l k(o*(1.-g.y*g.z));}H(_44){h b=C(c,e(5),.9,3.,4);k d=n(u(77,55,53),u(62,48,48),P(c,e(128,13)))*(.7+b*b),g;c=V(c,13.,.007);aW(g,c,E(j(.4+b*.4,.95,P(p[m],e(63,43)))));d*=j(1.3,.9,g.z);l k(d*(1.+g.y*g.z));}h bQ(e c,e s){c.y=L(c.y,0.);l aR(c,s);}k be(k d,k b,e c,h ae,h s){h y=(c.y-ae)/s,p=1.-y*y;d*=1.-i(-1.,1.,y);U(p>0.)d=b*(p*(.8+.2*i(.5,.25,F(c.x/s))))*(.7+E(i(.2,.7,y)));l d;}k cr(e c,h D){l k(D*D*.4);}H(_45){c.x*=.5;h b=C(c*e(2,1),e(3,5),.9,3.,4),D=.75+b*b,t=c.y+.2*M(.4,i(.5,.33,F(c.x*4.))),cs=bQ(c-e(.25,.62),e(3,2)/32.),aU=bQ(c-e(.25,.55),e(3,2)/48.),r;k d=n(u(66,50,51),u(111,66,44),a2(i(.31,.01,c.y))),am;e p=c,q;p.x=F(p.x*4.);U(c.y>."
"3)d=aS(d,e(4.*A(p.x-.5)-1.6,F(c.y*16.)-.5),.07);r=A(p.x-.5);d*=1.-.3*j(.31,.32,c.y)*j(.87,.86,c.y)*(j(.035,.03,.5-r)+i(.48,.01,r)-i(.46,.02,r));d=n(d*D,cr(c,b),L(j(.31,.3,c.y),I(aU)));d*=j(1.5,.7,c.y);U(c.y<.306)d*=1.-i(.3,.05,c.y)*I(-aU+10.,20.);d*=1.-i(.316,.004,c.y)*I(-aU);U(c.y<.1)d*=.0;q=c;q.y+=i(.1,.01,mod(q.x,.33))/2e2;d=be(d,2.*b*u(93,84,79),c,.185,.015);d=be(d,2.*b*u(138,77,48),c,.13,.025);d=be(d,2.*b*u(112,71,51),c,.09,.015);d=be(d,2.*b*u(138,77,48),q,.05,.015);p.x=A(F(c.x*6.-.5)-.5)/6.;d*=1.+.5*j(.04,.03,p.x)*i(.18,.03,p.y);r=aQ(p-e(0,.12),e(.03,.01));r=aG(r,aQ(p-e(0,.11),e(.01)));d*=1.-E(i(.0,.04,r));d=n(d,u(166,99,77)*2.*b*(.75+.5*E(i(.125,.01,c.y))),I(r));q=p;q.y-=.07;r=W(q,.03);d*=1.-E(i(.0,.07,r));d=n(d,u(127,83,72)*b*2.*j(.01,-.005,r),j(.005,.0,r));q.y-=.004;r=W(q,.015);d*=E(j(-.01,.01,r));q.y+=.013;r=W(q,.05);d+=u(67,38,30)*4.*a2(b)*E(i(-.02,.015,r)*i(.023,.02,c.y));r=aG(cs,aU);r=aG(r,(c.y-.3)*3e2);d*=1.-.5*i(-2.,17.,aU)*j(.26,.3,c.y);am=u(67,39,17)*D;am=n(am,k(D*.2),i(0.,4.,r)*b);am*=1.-.4*pow(i(.0,3.,r),4.);am+=(am+.6)*a2(b)*E(i(-6.,8.,r)*i(.66,.04,c.y))*I(r);U(c.y<.56)am=aS(am,e(24.*A(c.x-.25)-1.85,F(c.y*24.+.5)-.5),.15);d=n(d,_44(c),j(.85,.9,t)+step(c.y,1./256.));d*=1.+i(.88,.015,t)-E(i(.87,.03,t));l n(d,am,j(1.,.1,r));}k ct(k d,k J,e c,Q w,Q ae){h b=C(c,e(w,ae),.5,2.,2);d*=.9-.3*j(.15,.1,A(b-.5));l n(d,J,i(.5,.1,b));}H(_50){c=V(c,9.,.005);Q m=0,o[]=Q[](13,43,17,47,23,59,27,63);h b=C(c,e(19),.7,2.,4);k d=n(u(40,50,60),u(46,33,27),b)*(.5+b);for(;m<8;m+=2)d=ct(d,n(u(145,140,137),u(132,123,116),b),c,o[m],o[m+1]);l d;}k cu(k d,k J,e c,Q w,Q ae){h b=C(c,e(w,ae),.5,2.,2);d*=1.-.15*E(j(.15,.1,A(b-.5)));l n(d,J,i(.5,.1,b));}H(_57){h b=C(c,e(13),.9,3.,4),D=C(c,e(7),.9,3.,4);k d=n(u(111,66,55),u(80,55,52),E(j(.8,.2,D)))*(.8+.8*b*b),J=d;c=V(c,13.,.01);Q m=0,o[]=Q[](13,43,17,47,23,59,27,63);b=C(c,e(19),.7,2.,4);for(;m<6;m+=2)d=cu(d,J,c,o[m],o[m+1]);l d;}k cv(k d,k J,e c,Q w,Q ae){h b=C(c,e(w,ae),.5,2.,1);d*=.9-.3*E(j(.15,.1,A(b-.5)));l n(d,J,i(.5,.1,b));}H(_39){h b=C(c,e(3,29),.9,2.,4),t=.8+.8*b*b,f=A(c.y-.61),N=j(.25,.24,f),B;k d=u(140,127,127),J=d;e p=c;d*=1.-.1*j(.85,.86,c.y);d=t*n(d,u(110,55,50),j(.33,.32,c.y));p.y+=p.x*.11+b*.007;p.y=F(p.y*9.)-.5;B=j(.0,.1,A(p.y)-.2);Q m=0,o[]=Q[](3,29,5,37,9,63,27,63);for(;m<6;m+=2)d=n(d,cv(d,J,c,o[m],o[m+1]),B*N);d*=1.+t*N*(+.6*i(.1,.1,p.y)-.7*i(-.25,.3,p.y)-.5*i(.2,.1,p.y));d=n(d,u(99,66,51)*t,i(-.15,.1,p.y)*N);d*=1.+i(.36,.005,c.y)+i(.34,.005,c.y)+i(.865,.005,c.y)+i(.89,.01,c.y)-.5*E(i(.245,.01,f))-.7*E(i(.35,.01,c.y))-.5*E(i(.325,.02,c.y))-.8*E(i(.875,.02,c.y))-.3*E(i(.9,.02,c.y));d*=.3+a2(a8(c.x));l d;}k bR(k d,e p,h s,h B){s=bn(p,e(s)).z/s*1e2;d*=1.+.5*B*j(.9,.2,s)-.5*B*i(2.5,.5,.3,s);l d;}k bS(k d,e c,h cw){h b=C(c,e(4,9),.9,3.,4),t=.8+.8*b*b,a,f,B,s,J,m,v,r,z;k aH=n(u(133,100,88),u(133,100,100),b)*t;e p,q;p=q=c;q.x=A(q.x);f=W(p,.31);v=b8(q);B=j(.01,.0,f);d=n(d*j(.0,.05,f+cw),k(.13*t),B);d=bR(d,p,37.,j(.04,.02,A(f+.07)));a=v*22.;m=ao(a);s=a-m;J=j(.23,.22,A(v-.25))+aC(m)*j(.0,.1,q.y);f-=r=(f*.3+.005)*J;B=j(.0,.1,q.y)*I(A(f+.015)-.015);d=n(d,aH,i(-.005,.01,f));d=n(d,u(130,75,44)*t,i(-.02,.005,f)*j(.0,.1,q.y));d*=1.-.3*j(.025,.03,-f)-.5*j(.4,.5,A(s-.5))*B+.2*i(.5,.3,A(s-.5))*B-.5*i(-.015,.007,f)-.5*i(-.03,.007,f)-.5*i(-.1,.005,f+r)-.5*i(-.115,.005,f+r)-.5*i(-.125,.015,f+r)-.5*i(-.145,.005,f+r)+.9*i(-.11,.007,f+r)+.5*i(-.14,.005,f+r)-b*i(.225,.005,A(v-.25))*I(A(f+.015)-.015);a=v*72.;m=ao(a);s=a-m;J=step(.7,af(m))*step(q.y,.0)*j(.02,.0,A(f+.02));d=n(d,k(aH*.6),J*j(.4,.3,A(s-.5)));d*=1.-.7*J*i(.4,.1,A(s-.5));l d;}k bu(e c){h b=C(c,e(4,9),.9,3.,4),t=.8+.8*b*b,a,f,B,s,J,m,v,r,z;k aH=n(u(133,100,88),u(133,100,100),b)*t,d=k(.1*t);e p,q;p.x=c.x-.5;p.y=L(c.y-.2,0.)*1.89;v=atan(p.y,A(p.x))/aB;f=W(p,.48);J=j(.3,.31,v);f*=1.-.2*j(.3,.31,v)-.1*j(.43,.44,v);a=v*(v>.44?2.:v>.3?63.:31.);d=n(d,aH,j(.03,.01,A(f)));B=I(A(f-.01)-.02);m=ao(a);s=a-m;U(v>.33&&v<.44)s=F(s+af(m)*.6-.3);d*=1.-.5*B*i(.307,.01,v)-t*B*i(.5,.1+J*.2,s)+b*B*i(.52,.2+J*.2,s);d*=1.-.9*i(-.015,.015,f)-.5*i(.0,.01,f)-.7*i(.03,.02,f)+i(.01,.015,f);q=p;q.y-=.5;q.x=A(q.x)+.6;f=W(q,1.13);B=j(.03,.02,A(f))*j(.5,.6,q.y);d=n(d,aH*Y(1.-A(f-.015)/.03),B);d*=1.-.5*B*i(.005,.01,f)+.5*B*i(.017,.005,f);q.x=A(c.x-.5)-.35;q.y=c.y*9./4.-2.1;f=W(q,.13)*10.;a=b8(q)*49.;m=ao(a);s=a-m;v=j(.85,.9,af(m));for(Q a7=0;a7<2;++a7,f+=.3){d=n(d,aH*(b*.5+.2),j(.09,.03,A(f)));d*=1.+.7*E(i(.01,.05,f));}p.y=(c.y-.7)*9./4.;f=W(p,.43);a=atan(p.y,A(p.x))/aB;a=L(a,-.48);r=a;m=ao(a*=23.);s=a-m;J=aC(m)*.2-.1*j(.0,.1,-f);v=j(.1,.2,A(s-.5)-J);f+=v*.007;r=(1.-v)*E(i(.5,.3,r))*j(.25,.05,A(s-.5));f-=.17*r;B=i(.04,.0,-.4,f);d=n(d,aH*(b*.4+.4),B);d=bR(d,p,31.,j(.1,.05,A(f+.15))*v);d*=n(1.,1.-i(.1,.2,.4,A(s-.5)-J),B*b);d*=1.-.7*E(i(.03,.03,f))-.7*E(i(.03,.03,f+.05))*v-.7*E(i(.0,.02,f+.05))*v-.3*j(.04,.06,-f)*v+.5*i(.02,.0,-.1,f)+i(.0,.01+.07*r,f)+i(.0,.01,f+.03)*v;p.y-=.05;d=bS(d,p,0.);l d;}H(_40){c.y=(c.y+8.)/9.;l bu(c);}H(_41){c.y=(c.y*4.+4.)/9.;l bu(c);}H(_42){U(c.y<.01)++c.y;c.y=c.y*4./9.;l bu(c);}H(_52){h b=C(c,e(5),.9,3.,4),t=bA(V(c,4.,.01),e(7),.5,3.,5),D=P(V(c,4.,.05),e(9)),aA,X;k pt=bF(c,4.,.1+D*t*.05),d;e f=bC(pt.x);aA=af(F(pt.yz));d=u(74,65,62)*(.8+.8*b*b);d+=i(.6,.3,D)*j(.3,.9,b*t)*.2;d*=1.-i(.5,.4,D)*j(.5,.7,t)*.1;d=n(d,u(86,74,78),i(.5,.1,b)*i(.7,.3,aA)*.7);d=n(d,u(105,90,70),i(.3,.1,t)*i(.3,.3,aA)*.3);X=i(.015,.005+.015*D,pt.x)+i(.4,.1,D*t)*.4;d*=1.-b*j(.015,.05,pt.x)*.7;d*=1.+X*b*(f.y-.5)*.7;d*=.9+.2*aA;d*=.9+.2*a8(P(c-pt.yx,e(5)));l d;}H(_43){k d=_52(c);c-=.5;d=bS(d,c*.9,.02);l d;}k aM(e c){c*=1.5;h b=C(V(c,7.,.02),e(9),.7,3.,2),t=b,D=P(c,e(13)),a,s,f;k d=_52(c);e p;p.x=A(c.x-.75);p.y=L(c.y-.58,0.)*1.15;a=atan(p.x,p.y)/aB;s=F(a*7.+.5);f=W(p,.45);f-=.06*j(.4,.33,c.y);f-=.05*j(.15,.07,A(s-.5))*step(.63,c.y);f=aG(f,c.y-.107);U(c.y<.6)f=aG(f,A(p.x-.493)-.113);f=aG(f,W(p,.6)+.044*j(.48,.43,c.y));d=n(d,u(144,125,115)*t,I(f-.1,.005));d*=1.-.3*i(.12,.11,.1,f)+.5*i(.1,.005+.015*D*D,f);l d;}H(_30){l aM(e(5,0)/6.+c*e(1,4)/6.);}H(_31){l aM(e(1,0)/6.+c*e(4)/6.);}H(_32){l aM(c*e(1,4)/6.);}H(_33){l aM(e(5,4)/6.+c*e(1,2)/6.);}H(_34){l aM(e(1,4)/6.+c*e(4,2)/6.);}H(_35){l aM(e(0,4)/6.+c*e(1,2)/6.);}H(_53){h b=C(c,e(13,1),.7,2.,3);k d=_52(c)*.7;d*=1.-E(j(.4,1.,b));l d;}k bT(e c,e s){h b=C(c,e(5),.9,3.,4),D=C(c,e(31,3),.5,3.,3),t=.75+b*b;e p=c;k d=_52(c);U(c.y<.38)d=n(u(92,43,15),u(66,44,33),j(.1,.05,c.y))*t*(.5+.5*j(.0,.35,c.y));d+=b*s.y*E(i(.32,s.x*.015,c.y))+.3*b*i(.34,.05,c.y);d*=1.-i(.38,.005+b*b*.03,c.y)+3.*i(.15,.2,c.y)*(D-.5);l d;}H(_54){h b=C(c,e(5),.9,3.,4),t=.75+b*b,f,N,m;e p=c;k d=bT(c,e(1));p.x=mod(p.x,1./7.)-.07;p.y-=.21;f=W(e(.75*p.x,bi(p.y,.1)),.033);N=I(f,.005);f=W(e(.75*p.x,bi(p.y+.005,.09)),.033);m=I(f+.015);d=n(d,u(83,81,66)*t,(N-m)*j(.1,.3,c.y));d*=1.-j(.17,.25,c.y)*m;d+=E(i(.0,.015,f))*i(.32,.03,c.y);d*=1.+3.*pow(i(-.01,.03,f),4.)*i(.09,.03,c.y);f=W(e(.75*p.x,bi(p.y+.03,.1)),.033);d*=1.-I(f+.01,.02)*(1.-N);U(c.y>.09&&c.y<.3)d=aS(d,e((A(p.x)-.035)*36.,F(c.y*36.)-.5),.1);l d;}e cx(e p){p.x=A(p.x);e q=p,v;q.y-=.5;h f=W(q,.35),X,d;v=q/.35;q.y+=.25;q.x-=.15;f=M(f,R(q,e(.09,.05))-.1);X=aR(q,e(.15,.1))/5e1;d=.1+dot(e(v.y,a2(Y(1.-aV(v)))),e(.3,.3));q.y+=.2;q.x=p.x;d=L(d,Y(.4-K(q)));d+=.15*i(.0,.1,X)-.1*I(X+.12,.15);f=M(f,R(q,e(.15-j(-.15,.15,q.y)*.07,.03))-.09);d*=1.-j(.05,.25,q.x)*j(.2,.1,A(q.y+.12));q.y-=.06;d-=.5*I(aR(q,e(.05-j(-.1,.1,q.y)*.03,.06))/1e3+.03,.05);l e(Y(d),I(f,.02));}H(_55){h b=C(c,e(9),.7,2.,4),t=.75+b*b;k d=bT(c,e(4,.3));e p=c,s;p.x=mod(p.x,.2);p-=.1;s=cx(p*5.);l n(d,n(k(.5,.4,.3),k(.95,.8,.55),t)*t*s.x,s.y);}H(_51){h b=C(V(c,5.,.02),e(5),1.,3.,5),D=P(c,e(13));e p=b9(c,e(8)),q=F(p),aA=p-q;k d=u(91,61,42)*(.8+.8*b*b);d=n(d,u(70,30,15)*(.8+.8*b*b),aO(q,.1).z*.3);d*=1.-E(aO(q,.01+b*.05).z)*D*b*b;d*=1.+i(.4,.3,aO(q,.01+b*.07).z)*a2(b)*.3;d*=.9+.2*af(aA)*(1.-aO(q,.1).z);d*=.9+.4*pow(bA(c-af(aA/8.),e(5),.6,2.,4),4.);l d;}an(_28){h b=C(c-=.5,e(5),.9,3.,4),t=.75+b*b,D=P(V(c,7.,.02),e(17)),r=K(c),J=r>.4?38.:r>.32?28.:16.,a=F(atan(c.y,c.x)/b4),m=ao(a*J),a4=A(A(r-.41-D*.002)*1e2-6.),B=j(1.5,1.4,a4),bv[]=h[](1.,3.,-.145,-1.,2.,.166),f,bU,s;e p=c;k d=u(78,68,63);d*=1.+.5*E(i(.49,.005+.015*D*D+.015*b,r));d=n(d,u(83,52,47)*(.6+.4*D*D),B)*t;d*=1.-.5*i(1.5,.5,a4)+b*i(1.,.5+.5*D,A(r-.418)*1e2-5.)-b*i(.5,.08,F(a*J+.5))*B+b*i(.5,.1,F(a*J+.55))*B;B=j(.34,.33,r);d=n(d*(1.-"
".5*B),u(83,52,47)*t,D*b*B);d=n(d,u(112,86,31)*t,B*E(i(.1,.15,.45,b)));d=n(d,u(77,66,77)*t,B*j(.5,.8,b)*.5);d*=1.-.7*i(.27,.34,.35,r);a4=r+D*.004;B=r>.21&&r<.31?1.:0.;d*=1.-i(.325,.005,a4)-i(.31,.005,a4)-b*E(i(.29,.005,a4))-b*E(i(.23,.01,a4))-.5*E(i(.21,.02,a4))+E(i(.3,.01,a4))*b+E(i(.22,.01,a4))*b-b*i(.5,.07,F(a*J+.5))*B;U(r<.23)m+=37.;U(r<.31)m+=73.;U(r<.31)m+=91.;d*=n(1.,.9+.2*aC(m),B);B=j(.01,.0,A(r-.411)-.039);m=ao(a*72.);p*=a9(m*5.);s=0.;f=1e6;Q a7=0;for(;a7<6;a7+=3){f=b5(f,bU=dot(p,aT(e(bv[a7],bv[a7+1])))+bv[a7+2]);s+=s+h(bU>0.);}U(s==3.)++m;else m+=66.*s;m=aC(m);d=n(d,t*u(90,80,75),B);d=n(d,t*u(127,111,88),m*b*B);d*=n(1.,.7+.6*af(m),B);d*=1.-B*E(i(.0,.006,f))*b+B*E(i(.006,.006,A(f)))*b*.5;m=ao(a*4.);p=A(c*a9(m*90.+45.));f=1e6;for(a7=0;a7<2;++a7,p=A(p*a9(45.)))f=b5(f,A(K(p-e(0,.12))-.16));B=j(.21,.2,r);a4=b6(b6(f,.012),.001);d*=1.-j(.21,.2,r)*I(.012-f)+b*B*E(i(.005,.005,f))-.5*B*E(I(a4-.001,.001));l G(d,(1.-j(.21,.15,r)*I(.028-f,.02))*j(.07,.087,r));}an(_29){e p=F(O)-.5;h b=C(a9(ad.x*333.)*p/(.8+.2*sin(ad.x*61.)),e(53),.7,2.,4);G d=G(1.-b*k(0,.3,1),1),am=al(ak,(a9(ad.x*30.)*p/(.8+.2*sin(ad.x*1.26)))+.5);d.T=n(d.T,am.T,am.w);am=al(ak,O);d.T=n(d.T,am.T,am.w)*a3();l d;}H(_56){h b=C(c,e(13),.9,3.,4),D=C(c,e(7),.9,3.,4);k d=n(u(60,50,50),u(87,47,37),E(j(.7,.25,D)))*(.7+.8*b*b),g;c=V(c,31.,.003);aW(g,c,a2(j(.0,.9,P(p[m],e(93)))));d*=1.-(g.y+.4)*E(b*g.z)*g.z;l d;}H(_60){h b=C(c,e(5),.9,3.,4);k d=u(67,64,63)*(.6+.5*b),g;c=V(c,31.,.003);aW(g,c,a2(P(p[m],e(53,93))));d*=1.-.3*g.y*g.z*g.z;l d;}an(_22){c=V(c,7.,.01);h b=C(c,e(9),.7,2.,4),D=C(c,e(13),.5,2.,4),B=j(.6,.9,C(V(c,5.,.03),e(11),.6,2.,4));k d=u(127,70,55)*(.85+.3*b);d*=1.-.2*B-.2*E(j(.3,.0,b*b))-.3*j(.6,.77,D)+.3*j(.5,.9,b);d+=.5*E(j(.5,1.,C(c,e(17),1.,2.,3)));l G(d,B);}ac _24(){G d=al(ak,O);e c=F(O);c.y-=.2*ad.x;h b=C(V(c,7.,.02),e(5),.9,2.,4);Z=G(n(d.T,u(25,10,8)*b,d.w)*a3(),1);}H(_23){e p=c-.5;p=V(p,17.,.007);p.x*=2.-c.y*1.5;h b=C(c,e(9),.7,2.,4),D=P(c,e(7)),f=K(p),s;k d=_22(c).T;s=F(f*=13.);U(f<=6.){d*=1.-pow(j(6.,.5,f+b*b),6.);D=j(.3,.7,D);d*=1.-D*b*i(.4,.2,s)+D*b*i(.6,.4,s);}l d;}H(_25){c=V(c,13.,.003);h b=C(c,e(7),.9,3.,4),D=C(c,e(5),.5,2.,4),t=.5+b;k d=u(80,38,34),v=bo(c,e(23));d=n(d,n(u(180,125,118),u(165,78,51),D),b*i(.0,.4+D*.4,v.z))*t;l d;}H(_26){h b=C(c,e(7),.9,3.,4),t=.8+.4*b,m,r=.7,o,B;k d,v=bo(c,e(23));e p=v.xy/r,q=c+v.xy/23.;m=af(F(q)*3.3);d=n(u(155,55,55),u(200,166,155),j(.75,.45,q.y))*t;B=i(.5,.5,K(p));o=dot(e(-p.y,a2(Y(1.-aV(p)))),e(.6+m*.3,.3));d*=1.-b*.8*j(.5,.1,v.z)+b*B*o;d*=t*t*t*t;l d;}H(_27){h b=C(c,e(13),.9,3.,4),t=.4+b*b,D=a8(P(V(c,12.,.02),e(48))),m,r,o,B;k d=u(60,50,46)*t,v=bo(c,e(17));m=af(F(c+v.xy/17.));r=.4+.3*m;e p=v.xy/r;B=M(j(1.1,1.,K(p)),j(.0,.15,v.z));o=dot(e(-p.y,a2(Y(1.-aV(p)))),e(.1+m*.2,.3));d+=b*B*o*D;D=a8(C(V(c,13.,.01),e(23,43),.5,2.,3));d*=1.+(1.-B)*i(.4,.4,D);l d;}H(_58){h b=C(c,e(7),.9,3.,4),D=C(c,e(3),.5,3.,4);k d=n(u(103,56,53),u(73,58,71),j(.1,.7,D))*(.75+b*b);l d;}H(_59){h b=C(c,e(13),.9,3.,4),D=P(V(c,5.,.05),e(9)),f=a8(F(c.x*4.)),B=j(.1,.15,f)*j(1.,.99,c.y);k d=u(51,44,44);d=n(d,u(73,55,52),j(.2,.2,b)*D*B);d=n(d,u(69,60,66),j(.7,.1,b)*b*B);d=n(d,u(99,77,77),j(.1,.5,D)*D*B*b*b*.3);d*=.6+.3*b+.3*b*b;d*=1.+.9*E(i(.21,.02+.1*D,f+b*.05))*B*b;d*=1.-E(j(.49,.5,A(c.y-.5)));d*=1.-j(.05,.2,f)*j(.16,.1,f);d*=1.+i(.99,.007,c.y);l aS(d,e(f-.4,F(c.y*8.)-.5),.07);}k bV(e c,h s){h b=C(c,e(3,1.+s+s),.7,2.,4),f=a8(c.x),B;c.y*=2.;k d=n(u(71,60,58),u(110,88,77),j(.1,.05,f))*(.7+.6*b);d*=1.-j(.05,.0,c.x)*(1.-b*b);d*=1.+.5*i(.05,.02,c.x);e p=e(f-.35,F(c.y*s)-.5);G J=bD(p,.11);B=I(J.w);d*=1.-.7*bE(p,1.1)*(1.-B);d=n(d,(J.y>.0?u(128,105,88):u(200,111,66)*j(-.2,.7,J.z))*(.4+2.*b*pow(Y(bc(J.yz*.7)),4.))*(1.-.6*i(-.1,.4,J.y)),B);l d;}H(_36){l bV(c,4.);}H(_37){l _36(c.yx);}H(_38){l bV(c,1.);}H(_46){h b=C(c,e(40,5),.9,3.,4);k d=u(110,110,98)*(.8+.8*b*b);U(c.y<1./4.)d*=.5;d*=1.-.4*j(.4,.0,b)+.5*j(.02,.0,c.y)+.2*i(.24,.01,c.y);l d;}H(_47){e p=c,q;p.y*=22.;q=F(p);h b=C(c,e(3,23),1.,2.,6),D=C(c,e(3,33),.7,3.,4),aA=af(p.y-q.y);k d=u(92,67,53)*(.8+.8*b*b);d*=1.-E(j(.1,.0,M(q.y,1.-q.y)))*b;d*=1.-.2*smoothstep(.3,.7,D);d*=.8+.3*b*aA;l d;}H(_48){h b=C(c,e(13),.9,3.,4),x=c.x*16./3.;k d=_47(c)*j(.15,.21,c.x);U(x<1.)d=u(59,48,49)*(.7+.6*b);d*=1.+.5*i(.05,.05,a8(x));l aS(d,e(A(c.x-3./32.)-.07,mod(c.y,.1)-.05),.004);}H(_49){e p=b9(c,e(6,4)),q=F(p),a1=q;h b=C(V(c-=.5,5.,.03),e(13),.9,2.,3),D=P(c,e(73,7)),t=(.75+b*b)*(.8+.4*cd(c.x*93.)),r;k d=k(.25*t);a1.y+=a1.y*2.-.01-.03*D;r=K(a1-=clamp(a1,e(.49,.5),e(.51,3)));d*=1.-.7*b*E(j(.07,.03,A(r-.5)))+.5*b*i(.35,.1,r)*E(j(.2,.1,q.y))-.3*E(j(.8,1.,q.y))-.3*(j(.3,.1,q.y))*j(.4,.6,r)+.2*E(j(.5,.1,q.y))*j(.45,.4,r);l d;}H(_62){h b=C(c,e(5),.9,3.,4),ae=F(c.y*10.);k d=n(u(53,48,42),u(38,38,36),b);d*=.6+b*.8;d*=1.-.5*E(i(.5,.5,ae));d*=1.+.5*E(i(.25,.25,ae));d*=1.+.5*E(i(.65,.35,ae));l d;}H(_61){h b=C(c,e(7,3),.9,3.,4),ae=c.y+b*.04,o=1.-.15;k d=n(u(59,48,40),u(110,108,102),b*b);o=n(o,.5,i(.34,.05,c.y));o=n(o,.5,j(.08,.05,A(c.y-.7)));o=n(o,.3,i(.7,.03,c.y));o=n(o,1.5,i(.01,.03,c.y));o=n(o,2.2,i(.89,.1,ae));o=n(o,1.6,j(.07,.04,A(c.y-.44)));o=n(o,2.5,i(.5,.04,ae));o=n(o,1.7,i(.18,.04,ae));l d*o;}H(_63){h b=C(c,e(5,3),.9,3.,4);k d=n(u(74,66,55),u(99,90,78),b*b);c.x*=2.;e p=bd(c,e(.5,.625),e(1.5,.625));h f=K(p-c),B=j(.22,.20,f),o=1.-.15*B;o=n(o,.5,j(.7,.9,c.y)*B);o=n(o,1.-bC(f).y*.5,i(.22,.04,f));o=n(o,.6,E(i(.19,.05,f)));o=n(o,.5,j(.05,0.,c.y));o=n(o,.5,i(.26,.05,c.y));o=n(o,1.7,j(.93,1.,c.y));o=n(o,1.7,i(.23,.04,c.y));l d*o;}an(_64){h b=C(c,e(1,5),.4,3.,4);k d=n(u(56,49,43),u(142,136,136),b);c=.5-A(c-.5);c.y*=4.;h a=i(.0,.1,K(c-bd(c,e(.41,.5),e(.42,3.5)))),f=aZ(c),o=1.-.7*L(0.,1.-f/.15);o*=1.-.8*j(.24,.31,M(f,c.y-.1));d+=u(80,80,20)*a;l G(d*n(o,2.7,a),a);}an(_67){h b=C(c,e(1,5),.4,3.,4);k d=n(u(56,49,43),u(142,136,136),b);c=.5-A(c-.5);c.y*=8.;h f=K(c-bd(c,e(.27,.3),e(.27,7.7))),a=i(.0,.17,f),o=1.-.5*i(.17,.07,f);d+=u(80,80,20)*a;l G(d*n(o,2.7,a),a);}an(_65){e p=A(c-.5);h b=C(c,e(1),.4,3.,4),r=K(p),a=j(.37,.33,r)*(.5+2.*b),o=1.+.0*j(.08,.03,A(r-.41));k d=n(u(56,49,43),u(142,136,136),b);o=n(o,7.,j(.44,.1*b,r));o*=1.-.5*E(i(.46,.04,r));o*=1.-.4*E(i(.36,.04,r));l G(d*o,a);}an(_66){h b=C(c,e(5),.9,3.,4),f=bB(bN(c-=.5,.35),A(W(c,.4)),.02),a=pow(I(f-.02,.15),8.),N=M(L(R(c,e(.46)),-W(c,.51)),A(W(c,.44)));k d=u(76,62,47)*(.8+.8*b*b);d*=1.+(b+.5)*I(A(N)-.01,.01);d*=1.-j(.1,.05,f)*I(W(c,.4));l G(d+1.*k(1,1,.3)*a,a);}h bf(e c,h t){c.x=A(c.x);c.y-=.07;h f=aR(c,e(.31,.12-t*.02))/50.;f=L(f,-aR(c-e(0,.01+t*.01),e(.28,.07+t*.01))/50.);f=L(f,-R(c-e(.0,.1),e(.22-t*.02,.12)));f=L(f,-R(c-e(.0,.1),e(.084-t*.012,.31)));f=M(f,aQ(c-e(.0,-.09),e(i(-.09,.32,c.y)*(.04-t*.015),.32)));f=M(f,aQ(c-e(.11-t*.02,-.21),e(i(-.07,.3,c.y)*(.03-t*.01),.15)));l f;}an(_1){c-=e(.48,.5);h f=bf(c,0.),b=K(c)-.47;k d=1.-k(.5,1,1)*I(L(.007-f,b+.04));l G(d,1)*I(b);}H(_2){c-=.5;e r=e(dFdx(c.x),dFdy(c.y));c/=r/aD(r);c*=.8;c.y-=.03;h x=A(c.x),b=C(c,e(53,5),.7,2.,3),t=.8+.8*b*b,f=bf(c,1.),X=bf(c+e(0,.002),1.),o=(X-f)*5e2+.5;k d=k(.3*t,0,0)*I(f,.004);d*=1.-j(.1,.33,A(c.x))-.5*j(.1,.3,A(c.y-.1));d+=+.3*i(.0,.005-.01*x,f)*i(.1,.2,c.y)*j(.4,.2,x)*o+.5*j(.004,.0,f)*i(.13,.07,c.y)*i(.29,.07,x)*k(.9,.9,1)+.5*i(.005,.005,f)*j(.2,-.1,c.y)*Y(-o);l d;}h bW(e c,h s,h m,h cy){m=(c.y-E(A(c.x-.5))*cy)*s-m;l 2.*i(.5,.4,m)*(F(m)-.5);}an(_76){h b=C(c,e(5,9),.9,3.,4),t=.8+.8*b*b,D=C(c,e(5,9),.9,3.,2),x=A(c.x-.5),f;k d=u(77,60,44)*t;e p=c*e(1,2)-e(.5,.7);d*=1.-.55*I(aG(W(p,.3),bf(a9(45.)*p*.8,0.)-.01));d*=1.+E(j(.6,.9,b))+i(.2,.5,c.y)*i(.2,.3,x)*bW(c,4.,.2,4.);for(h S=6.;S<9.;++S)d*=1.+i(.8,.5,c.y)*i(.2,.3,x)*bW(c,12.,S,1.);f=c.y-.81-E(Y(x*4.))*.09;d=n(d,u(82,66,60)*t,j(.0,.01,f));d*=1.-.5*(i(.01,.02,f))+.5*(i(.02,.01,f));f=.15*(1.-c.y);f=R(c-.5,e(.49)-f)+D*.1*a2(1.-c.y)-f;l G(d*E(I(f+.01,.05)),I(f));}an(_77){G d=al(ak,c);U(d.w<.5)discard;d.T*=E(a3()*.5);l d;}an(_78){c*=e(256,64);c.y+=2.;h f=W(c-e(81,30),11.);f=L(f,c.x-80.);f=L(f,-W(c-e(84,26),9.));f=M(f,R(c-e(73,37),e(4,9))-4.);f=L(f,-R(c-e(73,37),e(0,7))+1.);f=M(f,R(c-e(91.5,47),e(4,19))-4.);f=L(f,-R(c-e(91.5,47),e(0,17.5))+1.);f=M(f,R(bj(c,111.)-e(105.+j(23.,50.,c.y)*3.,43),e(3.5,19)));f=M(f,R(c-e(111,32),e(4,3)));f=M(f,R(c-e(126,37),e(3,13)));f=M(f,R(c-e(125.5+j(23.,50.,c.y)*10.,44),e(3.5,6)));f=M(f,R(c-e(136.5-j(23.,50.,c.y)*9.,32),e(3.5,8)));f=M(f,R(c-e(148.5,3"
"7),e(7,13)));f=L(f,-R(c-e(155,33),e(6,3)));f=L(f,-R(c-e(155,43),e(6,2)));f=M(f,R(c-e(168,37),e(3.5,13)));f=M(f,R(c-e(178.,37),e(3.5,13)));f=M(f,R(c-e(188,37),e(3.5,13)));f=L(f,c.y-50.);l G(I(f,.8),0,0,af(c*511.));}ac _79(){k d=al(ak,O*2.).T*step(.5,F(ad.x*.5));d=n(d*a3(),k(.5,0,0),i(F(ad.x*2.),1./64.,F(O.y)));Z=G(d+bK(Ref)*.25+al(ak,O+af(ad.xx)).w*.1,1);}ac _80(){e c=F(bL(Pos.T,bM(Nor))/128.);c.x+=ad.x/33.;h b=C(c,e(7),.9,2.,4),S=F(Pos.z/128.-.375);Z=G(2.*u(95,85,80)*S*S*S*S*n(1.,b,.5),0.);}ac _81(){e c=F(O),p=c;p.y+=p.y-ad.x;c.x+=sin(p.y*7.)*.2*c.y;h D=C(p+sin(p.yx*aB*9.+e(0,ad.x*9.))*.015+P(p,e(5))*.1,e(13),.4,3.,4),b=R(c-e(.5,.25),e(.05*E(j(.4,.2,c.y)),.1)),B=E(I(b+D*.25,.35));Z=j(.0,.4,B)*G(5,2,.7,0);}ac _0(){h o=dot(Nor,aT(k(2,0,8)));o=o*.4+.7;e c=bL(Pos,bM(Nor));k d=k(.5);d*=co(k(F(aY*ad.w+.25),1.,1.));Z=G(d*o,1);}ac _6(){G d=al(ak,O);Z=G(d.T*n(a3(),k(1),d.w),1);}ac _69(){G d=al(ak,O);h r=K(F(O)-.5);h s=n(.4,8.,F(ad.x*1.5));Z=G(d.T*a3()+u(240,130,5)*i(.1,.05,r/s)*j(.37,.32,r),1);}ac _5(){k d=al(ak,O).T;Z=G(d*a3(),1);}ac _7(){G d=al(ak,O);d.T*=1.+d.w*bK(Ref);Z=G(d.T*a3(),1);}ac _72(){Z=G(0);}ac _73(){k f=aT(Pos-Cam.T);f.z=f.z*4.+2.;e c=aT(f).xy*2.;h b=j(.2,1.,C(c-ad.x*e(.1,.2),e(5),.5,2.,6));c.y*=1.5;h s=j(.3,1.,C(c-ad.x*e(.1,.18),e(5),.6,2.,6));Z=G(k(b,0,0)+u(80,30,8)*s*s*2.,1);}ac _74(){e c=V(O/8.,ad.x*.5,2.,.05);h b=C(c,e(7),.9,2.,4);k d=u(91,22,14)*(.2+1.6*b);d=n(d,u(144,44,0),i(.6,.2,C(c,e(3),.7,3.,4)));d=n(d,u(244,144,66)*b*2.,E(i(.55,.25,C(c,e(11),.5,2.,4))));Z=G(d*Y(aD(a3())),1);}ac _75(){_74();}ac _3(){Z=al(ak,(.5+O*127.)/128.,2.5);Z.T*=.7+.3*P(O,.5/fwidth(O));}ac _4(){Z=al(ak,O)*Clr;}"
;

// src/demo/data/shaders/vertex_shaders.glsl: 3173 => 1571 (49.5%)
static constexpr char g_vertex_shaders[] =
"#define c void\n"
"#define f vec4\n"
"#define h location\n"
"#define k gl_Position\n"
"uniform mat4 MVP;uniform f Time,Cam;layout(h=0)in f e;layout(h=1)in f i;layout(h=2)in vec3 j;layout(h=3)in f m;out vec3 Pos,Nor,Ref;out vec2 UV,LUV;out f Clr;c d(){k=e;UV=e.xy*.5+.5;}c l(float n,float o,float u){k+=o*MVP*f(j,0)*sin(6.28*(Time.x*u+dot(e.xyz/n,vec3(1))));}c _0(){k=MVP*e;Pos=e.xyz;Nor=j;UV=i.xy;LUV=i.zw;Ref=normalize(reflect((e-Cam).xyz,j));}c _1(){d();}c _2(){d();}c _3(){d();}c _4(){k=f(2.*e.x-1.,1.-2.*e.y,1,1);UV=i.xy;Clr=m;}c _5(){_0();}c _6(){_0();}c _7(){_0();}c _8(){d();}c _9(){d();}c _10(){d();}c _11(){d();}c _12(){d();}c _13(){_0();}c _14(){d();}c _15(){d();}c _16(){d();}c _17(){_0();}c _18(){d();}c _19(){d();}c _20(){d();}c _21(){d();}c _22(){d();}c _23(){d();}c _24(){_0();}c _25(){d();}c _26(){d();}c _27(){d();}c _28(){d();}c _29(){_0();}c _30(){d();}c _31(){d();}c _32(){d();}c _33(){d();}c _34(){d();}c _35(){d();}c _36(){d();}c _37(){d();}c _38(){d();}c _39(){d();}c _40(){d();}c _41(){d();}c _42(){d();}c _43(){d();}c _44(){d();}c _45(){d();}c _46(){d();}c _47(){d();}c _48(){d();}c _49(){d();}c _50(){d();}c _51(){d();}c _52(){d();}c _53(){d();}c _54(){d();}c _55(){d();}c _56(){d();}c _57(){d();}c _58(){d();}c _59(){d();}c _60(){d();}c _61(){d();}c _62(){d();}c _63(){d();}c _64(){d();}c _65(){d();}c _66(){d();}c _67(){d();}c _68(){d();}c _69(){_0();}c _70(){d();}c _71(){_0();}c _72(){_0();}c _73(){_0();}c _74(){_0();l(100.,3.,.1);}c _75(){_0();}c _76(){d();}c _77(){_0();l(30.,3.,.2);l(100.,3.,.7);}c _78(){d();}c _79(){_0();}c _80(){_0();}c _81(){_0();}"
;

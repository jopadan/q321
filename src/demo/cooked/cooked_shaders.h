#pragma once
// auto-generated, do not modify (see cook_shader.js)

// trim_newlines       : true
// consistent_floats   : false
// rename_ids          : true
// rename_vec_fields   : true
// rename_globals      : true
// min_macro_savings   : 8

// src/demo/data/shaders/fragment_shaders.glsl: 33987 => 15229 (44.8%)
const char g_fragment_shaders[] =
"#define w vec2\n"
"#define y float\n"
"#define z vec3\n"
"#define A return\n"
"#define B mix\n"
"#define I vec4\n"
"#define J fract\n"
"#define K abs\n"
"#define L length\n"
"#define O min\n"
"#define P max\n"
"#define R UV\n"
"#define T rgb\n"
"#define U FCol\n"
"#define X void\n"
"#define ac Time\n"
"#define ag Texture0\n"
"#define ah texture\n"
"#define aj int\n"
"#define a2 floor\n"
"#define aB normalize\n"
"uniform I ac,Cam;uniform sampler2D ag,Texture1;in z Pos,Nor,Ref;in w R,LUV;in I Clr;out I U;\n"
"#define bh(x)((x)*(x)*(3.-2.*(x)))\n"
"#define Q(x)(x)*(x)\n"
"#define bi(x)dot(x,x)\n"
"#define af(x)clamp(x,0.,1.)\n"
"#define D(r,g,b)(z(r,g,b)/255.)\n"
"y a1=3.1415927,b5=2.*a1,a7=1.618034;w bj(y i){y G=1.324718;A J(.5+i/w(G,G*G));}y bk(y i){A J(.5+i*a7);}y a8(w v){A O(v.r,v.g);}y a8(z v){A O(v.r,O(v.g,v.b));}y a8(I v){A O(O(v.r,v.g),O(v.b,v.a));}y as(w v){A P(v.r,v.g);}y as(z v){A P(v.r,P(v.g,v.b));}y as(I v){A P(P(v.r,v.g),P(v.b,v.a));}y a9(w v){A v.r+v.g;}w bl(w v){y l=dot(v,v);A l>0.?v/sqrt(l):v;}y E(y bm,y bn,y x){A 1.-af(K(x-bm)/bn);}y C(y aG,y bo,y x){A af((x-aG)/(bo-aG));}w Y(y x){A w(sin(x),cos(x));}mat2 aC(y x){w v=Y(radians(x));A mat2(v.g,v.r,-v.r,v.g);}w ai(w j,y p,y s){A j+sin(j.gr*a1*p)*s;}w ai(w j,y t,y p,y s){A j+sin(j.gr*a1*p+t)*s;}y aD(y v,y m){A m-K(v-m);}w aD(w v,y m){v.r=aD(v.r,m);A v;}w bp(w j,w s){j.r+=a2(j.g*s.g)*(.5/s.r);A J(j)*s;}z a3(w j,y r){A z(j-=clamp(j,r,1.-r),L(j)/r);}z a3(w j,w s,y r){s=s.gr/a8(s);j*=s;A z(j-=clamp(j,w(r),s-r),L(j)/r);}y H(w p){z q=J(p.rgr*.09153);q+=dot(q,q.gbr+19.19);A J((q.r+q.g)*q.b);}y H(y p){p=J(p*.1031);p*=p+33.33;p*=p+p;A J(p);}z b6(y p){z ad=J(z(p)*z(.1031,.1030,.0973));ad+=dot(ad,ad.gbr+33.33);A J((ad.rrg+ad.gbb)*ad.bgr);}w bq(w p){z ad=J(z(p.rgr)*z(.1031,.1030,.0973));ad+=dot(ad,ad.gbr+33.33);A J((ad.rr+ad.gb)*ad.bg);}I b7(y p){I at=J(I(p)*I(.1031,.1030,.0973,.1099));at+=dot(at,at.abrg+33.33);A J((at.rrgb+at.gbba)*at.bgar);}y Z(y x,y p){A H(mod(x,p));}y N(y x){y i;A B(H(i=a2(x)),H(i+1.),bh(x-i));}y W(y x,y p){y i;A B(Z(i=a2(x),p),Z(i+1.,p),x-i);}y Z(w p,w s){A H(mod(p,s));}y W(w p,w s){p*=s;w i=a2(p);p-=i;p*=p*(3.-2.*p);y bs=Z(i+w(0,0),s);y bt=Z(i+w(0,1),s);y bu=Z(i+w(1,1),s);y bw=Z(i+w(1,0),s);A B(B(bs,bw,p.r),B(bt,bu,p.r),p.g);}y F(w p,w al,y a4,y a5,aj aE){y a6=W(p,al),ar=1.,tw=1.;for(aj i=0;i<aE;++i){p=J(p+a7);al*=a5;ar*=a4;a6+=W(p,al)*ar;tw+=ar;}A a6/tw;}y F(w p,w al,y a4,y a5){A F(p,al,a4,a5,4);}\n"
"#define au(v)E(.5,.5,v)\n"
"y aH(w p,w al,y a4,y a5,aj aE){y a6=au(W(p,al)),ar=1.,tw=1.;for(aj i=0;i<aE;++i){p=J(p+a7);al*=a5;ar*=a4;a6+=au(W(p,al))*ar;tw+=ar;}A a6/tw;}w aA(w p,w a,w b){w ab=b-a,ap=p-a;y t=af(dot(ap,ab)/dot(ab,ab));A ab*t+a;}y S(w p,w b){w d=K(p)-b;A O(P(d.r,d.g),0.)+L(P(d,0.));}y aF(w p,w b){A as(K(p)-b);}y av(w p,y r){A L(p)-r;}y aI(w p,w r){A(L(p/r)-1.)/O(r.r,r.g);}y aJ(y a,y b,y k){y h=af(.5+0.5*(b-a)/k);A B(b,a,h)-k*h*(1.-h);}w aK(y x){w d=w(dFdx(x),dFdy(x));A d/P(L(d),1e-8);}y V(y s,y d){A af(1.-s/d);}y V(y s){A af(1.-s/fwidth(s));}\n"
"#define aL(by,j,bz){w p[3];y r[3];p[0]=j;p[1]=j+dFdx(j);p[2]=j+dFdy(j);for(aj i=0;i<3;++i)r[i]=bz;by=z(bl(w(r[1],r[2])-r[0]),r[0]);}\n"
"z aM(w p,y Y,y b0){z e=z(-1,0,1),r=z(1e5);w ae=a2(p*Y),b8=e.gg;p-=(ae+.5)/Y;y aa=.5*Z(ae+e.gg,w(Y));y aw=.5*Z(ae+e.rg,w(Y));y ay=.5*Z(ae+e.gb,w(Y));y az=.5*Z(ae+e.bg,w(Y));y a0=.5*Z(ae+e.gr,w(Y));y aN=.5*Z(ae+e.rb,w(Y));y aO=.5*Z(ae+e.bb,w(Y));y aP=.5*Z(ae+e.br,w(Y));y aQ=.5*Z(ae+e.rr,w(Y));w[4]ak,l;if(mod((ae.r+ae.g),2.)<.5){l[0]=1.+w(ay-aw,aN-aa);l[1]=1.+w(-ay+az,aO-aa);l[2]=1.+w(-a0+az,-aP+aa);l[3]=1.+w(a0-aw,-aQ+aa);ak[0]=w(ay,aa)+l[0]*w(-.5,.5);ak[1]=w(ay,aa)+l[1]*w(.5,.5);ak[2]=w(a0,aa)+l[2]*w(.5,-.5);ak[3]=w(a0,aa)+l[3]*w(-.5,-.5);}else{l[0]=1.+w(-aN+aa,ay-aw);l[1]=1.+w(aO-aa,ay-az);l[2]=1.+w(aP-aa,-a0+az);l[3]=1.+w(-aQ+aa,-a0+aw);ak[0]=w(aa,aw)+l[0]*w(-.5,.5);ak[1]=w(aa,az)+l[1]*w(.5,.5);ak[2]=w(aa,az)+l[2]*w(.5,-.5);ak[3]=w(aa,aw)+l[3]*w(-.5,-.5);}for(aj i=0;i<4;i++){l[i]/=Y;y bx=aF(p-ak[i]/Y,l[i]/2.-b0/Y);if(bx<r.r)r=z(bx,ae+ak[i]);}A r;}w aR(w p,w aS){p*=aS;w n=a2(p),f=p-n,aT,g,o,r;y aU=8.0,d;for(aj i=0;i<9;++i){g=w(i%3-1,i/3-1);o=bq(mod(n+g,aS));r=g+o-f;d=a9(K(r));if(d<aU){aU=d;aT=r;}}A aT;}y aV(z p){p=aB(p);z a=mod(degrees(atan(p,p.gbr)),360.);A W(a.r/8.,45.)*C(.9,.0,K(p.b))+W(a.g/8.,45.)*C(.7,.0,K(p.r));}w aW(z p,aj ax){A(ax==0)?p.gb:(ax==1)?p.rb:p.rg;}aj aX(z n){n=K(n)+z(.01,.02,.03);y m=as(n);A(m==n.r)?0:(m==n.g)?1:2;}z b1(z c){z T=af(K(mod(c.r*6.+z(0,4,2),6.)-3.)-1.);T*=T*(3.-2.*T);A c.b*B(z(1.),T,c.g);}z am(){z d=Cam.T-Pos;y b=F(d.rg/256.*aC(Cam.a),w(3),.7,3.,4),l=1.-C(14.,-6.,L(d.rg)-b*8.)*C(128.,48.,d.b)*step(.1,Nor.b);A ah(Texture1,LUV).T*3.*l;}\n"
"#define M(an)z an(w);X an(){U=I(an(R),1);}z an(w j)\n"
"#define ao(an)I an(w);X an(){U=an(R);}I an(w j)\n"
"M(cmet52){y b=F(j,w(5),.9,3.,4);z c=B(D(48,41,33),D(103,101,104),b);A c;}M(ptrshn){y b=F(j,w(3),.9,3.,4);z c=B(D(49,45,43),D(81,75,78),b*b);A c;}M(dmnd2c){y b=F(j,w(7),.9,3.);j.r*=-1.5;j.g+=j.r*.5;j.r=1.-j.r+j.g;j=J(j*28.);y f=af(1.-L(.1-j));f*=C(.6,.2,L(.6-j));f*=C(.6,.8,L(.1-j));f*=C(.2,.6,b)*2.+1.;y l=1.-C(.2,b+2.,as(K(j-.5)));A z((f+1.)*B(.21,.29,b*b)*l);}M(dmnd2cow){y b=F(j,w(7),.9,3.);z c=dmnd2c(j);y r=L(j-.5);c=B(c,c*D(70,61,53),C(.5,.2,r+b*b*b));A c;}y aY(w j,y s){y d=1e6,i=0.;for(;i<5.;++i){w p=w(0,-s)*aC(i*72.);d=O(d,L(j-aA(j,p,p*aC(144.))));}A d;}ao(dmnd2pnt){z c=dmnd2cow(j);j=J(j)-.5;y b=F(j,w(3),.9,3.),d=O(K(L(j)-.4),aY(j,.35));A I(c,V(d-.02+b*.02,.01));}X dmnd2pnt_m(){I c=ah(ag,R);U=I(c.T*am()+D(111,55,0)*c.a*(sin(ac.r*a1)*.5+.5),1);}M(dmnd2cjp){y b=F(j,w(7),.9,3.,4);z c=dmnd2c(j);y r=L(j-.5);y m=C(.46,.45,r);y l=1.5-1.5*C(.0,.3,r*r);l=B(l,2.5,E(.42,.07,r));l=B(l,3.5,E(.44,.05,r));l=B(l,2.6,E(.36,.03,r));y n=.3+.2*C(.35,.30,r);l*=1.-n*C(.3,.7,b);l*=1.-.3*Q(C(.13,.05,r));l=B(l,2.5,C(.04,.01,r));l-=l*E(.03,.01,r)*.7;c=B(c,D(68,66,54)*l,m);c*=1.-Q(E(.34,.02,r));c*=1.-Q(E(.46,.03,r));c*=1.-E(.41,.03,r)*.7;A c;}w b2(w j,y s){A w(1.-L(j)/s,V(L(j)-s));}ao(lpdmnd){y b=F(j,w(5),.9,3.),t,o,k,r;z c=dmnd2c(j);w u,v;u.r=K(j.r-.5);u.g=O(j.g,.4);r=L(u-w(0,.4))-(.18-.06*C(.4,1.,j.g));k=.25-.15*C(.9,.96,j.g)+.03*Q(C(.82,.86,j.g))+.07*C(.8,.2,j.g)+.07*Q(C(.35,.22,j.g))-.07*C(.22,.0,j.g);o=S(j-w(.5,.5),w(k,.46));o=P(o,-S(u,w(.15,.03))+.06);c=B(c,z(.6,.55,.55)-j.g*.3+b*.2,V(o));c*=1.-.7*E(.0,.013,o);c*=1.-(r/.5-.1)*V(o);t=P(r,j.g-.96);o=K(t-.02)-.03;o=P(o,j.g-1.+u.r*.5);o=P(o,j.g-.96);c=B(c,z(1,1,.9)-j.g*.55,E(-.01,.01,o));c=B(c,z(.2*b+.1),V(t,.01));c*=1.-.2*E(.0,.05,t)*V(o);v=b2(u=j-w(.5,.4),.02);c*=1.+D(111,80,70)*E(.03,.01,L(u));c*=1.-.5*E(.02,.01,L(u));c=B(c,D(111,66,44)*(v.r*1.5+.2),v.g);A I(c,V(t-.03,.02));}X lpdmnd_m(){I c=ah(ag,R);w j=J(R);j.r=K(.5-j.r);y t=J(-ac.r),r=L(j-w(0,.4)),l=t*pow(P(0.,1.-r),4.)*c.a;if(t>.75)l+=C(.03,.01,K(J(j.g+j.r*.5+t*2.)-.45))*C(.1,.08,j.r);U=I(c.T*am()+D(180,150,5)*l,1);}M(mtlfw10){y b=F(j,w(5),.9,3.,4);z c=B(D(44,14,16),D(93,63,63),b*b);A c;}z aZ(w j){y e=3e-3,a=0.;w g=w(6),r=aR(j,g);for(aj i=0;i<9;++i)a+=a9(K(aR(w(i%3-1,i/3-1)*e+j,g)-r));A z(j+r.rg/g,a);}M(mtlfw15){y b=F(j,w(3),.9,3.,4);z c=B(D(80,70,72),D(128,120,120),b*b);z v=aZ(j);c*=B(.95,1.1,W(v.rg,w(6)));c=B(c,D(168,128,120),C(.5,1.,v.b)*b*.7);A c;}ao(mtlfw15ow){y b=F(j,w(3),.9,3.,4);z c=B(D(80,70,72),D(128,120,120),b*b);z v=aZ(j);y m=C(.5,1.,v.b);y r=C(.4,.2,L(.5-J(v.rg)));c*=B(.95,1.1,W(v.rg,w(6)))-2.*r*b*b;c=B(c,D(168,128,120),m*b*.7);A I(c,m*r);}X mtlfw15ow_m(){I c=ah(ag,R);U=I(c.T*am()+E(.5,.125,J(R.g*.5+ac.r*.5))*c.a*.3,1);}M(mtlfb3){y b=F(j,w(5),.9,3.,4);z pt=aM(j,8.,.31);z c=B(D(66,58,55),D(118,107,105),b);y l=1.-.5*C(.034,.036,pt.r);l=B(l,1.4,E(.033,.004,pt.r));A c*l;}y b3(w j){y b=W(j,w(64)),f=0.,d=1e6;for(;f<11.;++f)d=aJ(d,K(L(.5-K(j-bj(f)))-B(.36,.29,bk(f+.7)))-B(.015,.03,b),.01);A d*1e2;}z ba(w j){z s,p;for(aj i=0;i<3;++i){p=z(j,0);p[i]+=1e-4;s[i]=b3(p.rg);}A z(aB(s.rg-s.b),s.b);}M(mtlt12f){y b=F(j,w(5),.9,3.,4),l;z c=B(D(51,46,43),D(165,147,143),b*b),d=ba(j);l=1.-.5*(d.g-d.r)*E(.5,3.,d.b)*C(1.,.0,d.b);A c*l*.8;}M(mtlt6f){y b=F(j,w(3),1.1,3.,4),l;z c=B(D(51,46,43),D(165,147,143),b*b),d=ba(j);l=1.-.5*(d.g-d.r)*E(.5,3.,d.b)*C(1.,.0,d.b);A c*l;}M(mtlbk03){y b=F(j,w(5),.9,3.,4),l=.18*(.7+b*b);z g;j=ai(j,13.,.007);aL(g,j,Q(C(.3+b*.2,.9,F(p[i],w(23),.5,2.,4))));A z(l*(1.-g.g*g.b));}M(gmtlbg6){y b=F(j,w(13),1.,3.,4);z c=B(D(36,35,31),D(132,132,132),b);A c;}M(glrgbk3b){y b=F(ai(j,5.,.02),w(5),1.,3.,5),n=W(j,w(13));w p=bp(j,w(8)),q=J(p),aq=p-q;z c=D(91,61,42)*(.8+.8*b*b);c=B(c,D(70,30,15)*(.8+.8*b*b),a3(q,.1).b*.3);c*=1.-Q(a3(q,.01+b*.05).b)*n*b*b;c*=1.+E(.4,.3,a3(q,.01+b*.07).b)*sqrt(b)*.3;c*=.9+.2*H(aq)*(1.-a3(q,.1).b);c*=.9+.4*pow(aH(j-H(aq/8.),w(5),.6,2.,4),4.);A c;}M(gblks15){y b=F(j,w(5),.9,3.,4),t=aH(ai(j,4.,.01),w(7),.5,3.,5),n=W(ai(j,4.,.05),w(9)),aq,e;z pt=aM(j,4.,.1+n*t*.05),c;w d=aK(pt.r);aq=H(J(pt.gb));c=D(74,65,62)*(.8+.8*b*b);c+=E(.6,.3,n)*C(.3,.9,b*t)*.2;c*=1.-E(.5,.4,n)*C(.5,.7,t)*.1;c=B(c,D(86,74,78),E(.5,.1,b)*E(.7,.3,aq)*.7);c=B(c,D(105,90,70),E(.3,.1,t)*E(.3,.3,aq)*.3);e=E(.015,.005+.015*n,pt.r)+E(.4,.1,n*t)*.4;c*=1.-b*C(.015,.05,pt.r)*.7;c*=1.+e*b*(d.g-.5)*.7;c*=.9+.2*aq;c*=.9+.2*au(W(j-pt.gr,w(5)));A c;}M(gtprst3){y b=F(j,w(13),.9,3.,4),n=F(j,w(7),.9,3.,4);z c=B(D(60,50,50),D(87,47,37),Q(C(.7,.25,n)))*(.7+.8*b*b),g;j=ai(j,31.,.003);aL(g,j,sqrt(C(.0,.9,W(p[i],w(93)))));c*=1.-(g.g+.4)*Q(b*g.b)*g.b;A c;}M(skcpthrt){y b=F(ai(j,7.,.01),w(9),.7,2.,4);z c=D(127,70,55)*(.85+.3*b);c*=1.-.2*Q(C(.2,.05,b*b));c*=1.+.3*C(.6,.9,b);c*=1.-.2*Q(E(.6,.3,F(ai(j,5.,.03),w(6),.6,2.,4)));A c;}M(gskull4){y b=F(j,w(13),.9,3.,4);z c=D(60,50,46)*(.875+b*b);A c;}M(gmtlspsld){y b=F(j,w(7),.9,3.,4),n=F(j,w(5),.9,3.,4);z c=B(D(103,56,53),D(73,58,71),smoothstep(.4,.5,n))*(.75+b*b);A c;}I bc(w j,y s){A I(j/=s,sqrt(af(1.-bi(j))),L(j)-1.);}y b4(z n){y l=a9(n.gb)*.7;A pow(af(l),4.)+l;}y bd(w j,y s){j/=s;j.g+=.06;j.r*=2.;A C(.3,.0,L(j));}z be(z c,w j,y s){I b=bc(j,s);c*=1.+b4(b.T)*V(b.a)*.5;c*=1.-Q(bd(j,20.*s))*(1.-V(b.a))*.3;A c;}M(gmtlsp4b){y b=F(j,w(13),.9,3.,4),n=W(ai(j,5.,.05),w(9)),d=au(J(j.r*4.)),m=C(.1,.15,d)*C(1.,.99,j.g);z c=D(51,44,44);c=B(c,D(73,55,52),C(.2,.2,b)*n*m);c=B(c,D(69,60,66),C(.7,.1,b)*b*m);c=B(c,D(99,77,77),C(.1,.5,n)*n*m*b*b*.3);c*=.6+.3*b+.3*b*b;c*=1.+.9*Q(E(.21,.02+.1*n,d+b*.05))*m*b;c*=1.-Q(C(.49,.5,K(j.g-.5)));c*=1.-C(.05,.2,d)*C(.16,.1,d);c*=1.+E(.99,.007,j.g);A be(c,w(d-.4,J(j.g*8.)-.5),.07);}z bf(w j,y s){y b=F(j,w(3,1.+s+s),.7,2.,4),d=au(j.r),m;j.g*=2.;z c=B(D(71,60,58),D(110,88,77),C(.1,.05,d))*(.7+.6*b);c*=1.-C(.05,.0,j.r)*(1.-b*b);c*=1.+.5*E(.05,.02,j.r);w p=w(d-.4,J(j.g*s)-.5);I k=bc(p,.1);m=V(k.a);c*=1.-.7*bd(p,1.)*(1.-m);c=B(c,D(128,105,88)*(.4+2.*b*pow(af(a9(k.gb*.7)),4.))*(1.-.5*E(-.1,.4,k.g)),m);A c;}M(gspbdrbb){A bf(j,4.);}M(gkarntwr4a){A gspbdrbb(j.gr);}M(gkarntwrst){A bf(j,1.);}M(gxstrtop4){y b=F(j,w(40,5),.9,3.,4);z c=D(110,110,98)*(.8+.8*b*b);if(j.g<1./4.)c*=.5;c*=1.-.4*C(.4,.0,b)+.5*C(.02,.0,j.g)+.2*E(.24,.01,j.g);A c;}M(gwdclg1a){w p=j,q;p.g*=22.;q=J(p);y b=F(j,w(3,23),1.,2.,6),n=F(j,w(3,33),.7,3.,4),aq=H(p.g-q.g);z c=D(92,67,53)*(.8+.8*b*b);c*=1.-Q(C(.1,.0,O(q.g,1.-q.g)))*b;c*=1.-.2*smoothstep(.3,.7,n);c*=.8+.3*b*aq;A c;}M(gwdclg1bd){y b=F(j,w(13),.9,3.,4),x=j.r*16./3.;z c=gwdclg1a(j)*C(.15,.21,j.r);if(x<1.)c=D(59,48,49)*(.7+.6*b);c*=1.+.5*E(.05,.05,au(x));A be(c,w(K(j.r-3./32.)-.07,mod(j.g,.1)-.05),.004);}M(cable){y b=F(j,w(5),.9,3.,4),h=J(j.g*10.);z c=B(D(53,48,42),D(38,38,36),b);c*=.6+b*.8;c*=1.-.5*Q(E(.5,.5,h));c*=1.+.5*Q(E(.25,.25,h));c*=1.+.5*Q(E(.65,.35,h));A c;}M(bmtsprt){y b=F(j,w(7,3),.9,3.,4),h=j.g+b*.04,l=1.-.15;z c=B(D(59,48,40),D(110,108,102),b*b);l=B(l,.5,E(.34,.05,j.g));l=B(l,.5,C(.08,.05,K(j.g-.7)));l=B(l,.3,E(.7,.03,j.g));l=B(l,1.5,E(.01,.03,j.g));l=B(l,2.2,E(.89,.1,h));l=B(l,1.6,C(.07,.04,K(j.g-.44)));l=B(l,2.5,E(.5,.04,h));l=B(l,1.7,E(.18,.04,h));A c*l;}M(brdr11b){y b=F(j,w(5,3),.9,3.,4);z c=B(D(74,66,55),D(99,90,78),b*b);j.r*=2.;w p=aA(j,w(.5,.625),w(1.5,.625));y d=L(p-j),m=C(.22,.20,d),l=1.-.15*m;l=B(l,.5,C(.7,.9,j.g)*m);l=B(l,1.-aK(d).g*.5,E(.22,.04,d));l=B(l,.6,Q(E(.19,.05,d)));l=B(l,.5,C(.05,0.,j.g));l=B(l,.5,E(.26,.05,j.g));l=B(l,1.7,C(.93,1.,j.g));l=B(l,1.7,E(.23,.04,j.g));A c*l;}ao(blt414k){y b=F(j,w(1,5),.4,3.,4);z c=B(D(56,49,43),D(142,136,136),b);j=.5-K(j-.5);j.g*=4.;y a=E(.0,.1,L(j-aA(j,w(.41,.5),w(.42,3.5)))),d=a8(j),l=1.-.7*P(0.,1.-d/.15);l*=1.-.8*C(.24,.31,O(d,j.g-.1));c+=D(80,80,20)*a;A I(c*B(l,2.7,a),a);}ao(light5){y b=F(j,w(1,5),.4,3.,4);z c=B(D(56,49,43),D(142,136,136),b);j=.5-K(j-.5);j.g*=8.;y d=L(j-aA(j,w(.27,.3),w(.27,7.7))),a=E(.0,.17,d),l=1.-.5*E(.17,.07,d);c+=D(80,80,20)*a;A I(c*B(l,2.7,a),a);}ao(lt2){w p=K(j-.5);y b=F(j,w(1),.4,3.,4),r=L(p),a=C(.37,.33,r)*(.5+2.*b),l=1.+.0*C(.08,.03,K(r-.41));z c=B(D(56,49,43),D(142,136,136),b);l=B(l,7.,C(.44,.1*b,r));l*=1.-.5*Q(E(.46,.04,r));l*=1.-.4*Q(E(.36,.04,r));A I(c*l,a);}ao(gpntgmlt1k){y b=F(j,w(5),.9,3.,4),d=aJ(aY(j-=.5,.35),K(av(j,.4)),.02),a=pow(V(d-.02,.15),8.),o=O(P(S(j,w(.46)),-av(j,.51)),K(av(j,.44)));z c=D(76,62,47)*(.8+.8*b*b);c*=1.+(b+.5)*V(K(o)-.01,.01);c*=1.-C(.1,.05,d)*V(av(j,.4));A I(c+1.*z(1,1,.3)*a,a);}ao(icon){j.g-=.57;j.r=K(j.r-.48);y d=aI(j,w(.31,.12))/50.;d=P(d,-aI(j-w(0,.01),w(.28,.07))/120.);d=P(d,-S(j-w(.0,.1),w(.22,.12)));d=P(d,-S(j-w(.0,.1),w(.09,.31)));d=O(d,aF(j-w(.0,-.09),w(E(-.09,.32,j.g)*.04,.32)));d=O(d,aF(j-w(.11,-.21),w(E(-.07,.3,j.g)*.03,.15)));j.g+=.07;y b=L(j)-.47,m=V(b);z c=1.-z(.7,1,1)*V(P(.007-d,b+.04));A I(c*m,m);}ao(q3bnr){j*=w(256,64);j.g+=2.;y d=av(j-w(81,30),11.);d=P(d,j.r-80.);d=P(d,-av(j-w(84,26),9.));d=O(d,S(j-w(73,37),w(4,9))-4.);d=P(d,-S(j-w(73,37),w(0,7))+1.);d=O(d,S(j-w(91.5,47),w(4,19))-4.);d=P(d,-S(j-w(91.5,47),w(0,17.5))+1.);d=O(d,S(aD(j,111.)-w(105.+C(23.,50.,j.g)*3.,43),w(3.5,19)));d=O(d,S(j-w(111,32),w(4,3)));d=O(d,S(j-w(126,37),w(3,13)));d=O(d,S(j-w(125.5+C(23.,50.,j.g)*10.,44),w(3.5,6)));d=O(d,S(j-w(136.5-C(23.,50.,j.g)*9.,32),w(3.5,8)));d=O(d,S(j-w(148.5,37),w(7,13)));d=P(d,-S(j-w(155,33),w(6,3)));d=P(d,-S(j-w(155,43),w(6,2)));d=O(d,S(j-w(168,37),w(3.5,13)));d=O(d,S(j-w(178.,37),w(3.5,13)));d=O(d,S(j-w(188,37),w(3.5,13)));d=P(d,j.g-50.);A I(V(d,.8),0,0,H(j*511.));}X q3bnr_m(){z c=ah(ag,R*2.).T*step(.5,J(ac.r*.5));c=B(c*am(),z(.5,0,0),E(J(ac.r*2.),1./64.,J(R.g)));U=I(c+aV(Ref)*.25+ah(ag,R+H(ac.rr)).a*.1,1);}X beam(){w j=J(aW(Pos.T,aX(Nor))/128.);j.r+=ac.r/33.;y b=F(j,w(7),.9,2.),f=J(Pos.b/128.-.375);U=I(2.*D(95,85,80)*f*f*f*f*B(1.,b,.5),0.);}X flame(){w j=J(R),p=j;p.g+=p.g-ac.r;j.r+=sin(p.g*7.)*.2*j.g;y n=F(p+sin(p.gr*a1*9.+w(0,ac.r*9.))*.015+W(p,w(5))*.1,w(13),.4,3.,4),b=S(j-w(.5,.25),w(.05*Q(C(.4,.2,j.g)),.1)),m=Q(V(b+n*.25,.35));U=C(.0,.4,m)*I(7,.5,.2,0);}X Generic(){y l=dot(Nor,aB(z(2,0,8)));l=l*.4+.7;w j=aW(Pos,aX(Nor));z c=z(.5);c*=b1(z(J(a7*ac.a+.25),1.,1.));U=I(c*l,1);}X fixture(){I c=ah(ag,R);U=I(c.T*B(am(),z(1),c.a),1);}X dmnd2cjp_m(){I c=ah(ag,R);y r=L(J(R)-.5);y s=B(.4,8.,J(ac.r*1.5));U=I(c.T*am()+D(240,130,5)*E(.1,.05,r/s)*C(.37,.32,r),1);}X Lmapped(){z c=ah(ag,R).T;U=I(c*am(),1);}X shiny(){I c=ah(ag,R);c.T*=1.+c.a*aV(Ref);U=I(c.T*am(),1);}X timhel(){z d=aB(Pos-Cam.T);d.b=d.b*4.+2.;w j=aB(d).rg*2.;y b=C(.2,1.,F(j-ac.r*w(.1,.2),w(5),.5,2.,6));j.g*=1.5;y s=C(.3,1.,F(j-ac.r*w(.1,.18),w(5),.6,2.,6));U=I(z(b,0,0)+D(80,30,8)*s*s*2.,1);}X lava(){w j=ai(R/8.,ac.r*.5,2.,.05);y b=F(j,w(7),.9,2.,4);z c=D(91,22,14)*(.2+1.6*b);c=B(c,D(144,44,0),E(.6,.2,F(j,w(3),.7,3.,4)));c=B(c,D(244,144,66)*b*2.,Q(E(.55,.25,F(j,w(11),.5,2.,4))));U=I(c*af(as(am())),1);}X lavaf(){lava();}X Loading(){U=ah(ag,(.5+R*127.)/128.,2.5);U.T*=.7+.3*W(R,.5/fwidth(R));}X UI(){U=ah(ag,R)*Clr;}";

// src/demo/data/shaders/vertex_shaders.glsl: 2233 => 1401 (62.7%)
const char g_vertex_shaders[] =
"#define c void\n"
"#define e location\n"
"#define f gl_Position\n"
"uniform mat4 MVP;uniform vec4 Time,Cam;layout(e=0)in vec4 P;layout(e=1)in vec4 T;layout(e=2)in vec3 N;layout(e=3)in vec4 C;out vec3 Pos,Nor,Ref;out vec2 UV,LUV;out vec4 Clr;c Generic(){f=MVP*P;Pos=P.rgb;Nor=N;UV=T.rg;LUV=T.ba;Ref=normalize(reflect((P-Cam).rgb,N));}c d(){f=P;UV=P.rg*.5+.5;}c UI(){f=vec4(2.*P.r-1.,1.-2.*P.g,1,1);UV=T.rg;Clr=C;}c cmet52(){d();}c dmnd2c(){d();}c dmnd2cow(){d();}c dmnd2cjp(){d();}c dmnd2pnt(){d();}c lpdmnd(){d();}c ptrshn(){d();}c mtlfw10(){d();}c mtlfw15(){d();}c mtlfw15ow(){d();}c mtlfb3(){d();}c mtlt12f(){d();}c mtlt6f(){d();}c mtlbk03(){d();}c gmtlbg6(){d();}c glrgbk3b(){d();}c gblks15(){d();}c gtprst3(){d();}c skcpthrt(){d();}c gskull4(){d();}c gmtlspsld(){d();}c gmtlsp4b(){d();}c gspbdrbb(){d();}c gkarntwr4a(){d();}c gkarntwrst(){d();}c gxstrtop4(){d();}c gwdclg1a(){d();}c gwdclg1bd(){d();}c bmtsprt(){d();}c cable(){d();}c brdr11b(){d();}c blt414k(){d();}c light5(){d();}c lt2(){d();}c gpntgmlt1k(){d();}c icon(){d();}c q3bnr(){d();}c Loading(){d();}c Lmapped(){Generic();}c mtlfw15ow_m(){Generic();}c dmnd2cjp_m(){Generic();}c dmnd2pnt_m(){Generic();}c lpdmnd_m(){Generic();}c fixture(){Generic();}c beam(){Generic();}c flame(){Generic();}c q3bnr_m(){Generic();}c shiny(){Generic();}c timhel(){Generic();}c lavaf(){Generic();}c lava(){Generic();f+=MVP[2]*sin(Time.r*.5+dot(P.rgb/1e2,vec3(1)))*4.;}";

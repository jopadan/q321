#pragma once

// auto-generated, do not modify
static_assert(0xf78dae4dU == Demo::Shader::Version, "Shader definition mismatch, please recompile the shader compiler & shaders");

// src/demo/data/shaders/fragment_shaders.glsl: 85973 => 36563 (42.5%)
static constexpr char g_fragment_shaders[] =
"#define d vec2\n"
"#define h float\n"
"#define k vec3\n"
"#define l return\n"
"#define o mix\n"
"#define ae abs\n"
"#define af vec4\n"
"#define aj fract\n"
"#define au void\n"
"#define av length\n"
"#define a0 xyz\n"
"#define a2 Time\n"
"#define a3 min\n"
"#define a4 max\n"
"#define be int\n"
"#define bj floor\n"
"#define bu sqrt\n"
"#define cf normalize\n"
"#define dk(x)((x)*(x)*(3.-2.*(x)))\n"
"#define ai(x)((x)*(x))\n"
"#define cx(x)dot(x,x)\n"
"#define bd(x)clamp(x,0.,1.)\n"
"#define n(r,g,b)(k(r,g,b)/255.)\n"
"#define b6(ac)i(.5,.5,ac)\n"
"#define an(b8)k b8(d);au b8(){al=af(b8(UV),1);}k b8(d c)\n"
"#define bi(b8)af b8(d);au b8(){al=b8(UV);}af b8(d c)\n"
"#define a6(x)texture(Texture0,x)\n"
"#define c6(ei,c,ej){d p[3];h r[3];p[0]=c;p[1]=c+dFdx(c);p[2]=c+dFdy(c);for(be m=0;m<3;++m)r[m]=ej;ei=k(ek(d(r[1],r[2])-r[0]),r[0]);}\n"
"#define dl(b8,el)k b8(d p,d dm){p*=dm;d u=bj(p),a8=p-u,dn,g,bf,r;h cy=8.,c7=cy,f;for(be m=0;m<9;++m){g=d(m%3-1,m/3-1);bf=dp(mod(u+g,dm));r=g+bf-a8;f=el;if(f<cy){c7=cy;cy=f;dn=r;}else if(f<c7){c7=f;}}l k(dn,c7-cy);}\n"
"uniform af a2,Cam,LightDir,LightColor,Ambient;uniform sampler2D Texture0,Texture1;in k Pos,Nor,WNor,Ref;in d UV,LUV;in af Clr;out af al;h cj=3.1415927,dq=2.*cj,cp=1.618034;d dr(h m){h de=1.324718;l aj(.5+m/d(de,de*de));}h ck(h m){l aj(.5+m*cp);}h em(h a8){h m=bj(a8);l o(ck(m),ck(m+1.),dk(a8-m));}h c8(d ac){l a3(ac.x,ac.y);}h c8(k ac){l a3(ac.x,a3(ac.y,ac.z));}h c8(af ac){l a3(a3(ac.x,ac.y),a3(ac.z,ac.w));}h cd(d ac){l a4(ac.x,ac.y);}h cd(k ac){l a4(ac.x,a4(ac.y,ac.z));}h cd(af ac){l a4(a4(ac.x,ac.y),a4(ac.z,ac.w));}h cl(d ac){l ac.x+ac.y;}h cl(k ac){l ac.x+ac.y+ac.z;}h ds(h a,h b){l ae(a)<ae(b)?a:b;}h cz(h x,h s){l ae(x)-s;}h df(h x,h s){l sign(x)*a4(0.,ae(x)-s);}d ek(d ac){h ad=dot(ac,ac);l ad>0.?ac/bu(ad):ac;}h i(h en,h eo,h x){l 1.-bd(ae(x-en)/eo);}h j(h dt,h ep,h x){l bd((x-dt)/(ep-dt));}h i(h a,h b,h e,h x){l a3(j(a,b,x),j(e,b,x));}d bl(h x){l d(sin(x),cos(x));}mat2 bh(h x){d ac=bl(radians(x));l mat2(ac.y,ac.x,-ac.x,ac.y);}h ch(d p){l aj(atan(p.y,p.x)/dq);}d c9(d p,h u){l p*bh(360./u*(bj(ch(p)*u+1.5)-1.));}d bc(d c,h p,h s){l c+sin(c.yx*cj*p)*s;}d bc(d c,h t,h p,h s){l c+sin(c.yx*cj*p+t)*s;}h da(h ac,h v){l v-ae(ac-v);}d da(d ac,h v){ac.x=da(ac.x,v);l ac;}h eq(h x,h p,h ad,h a5){l x-p*clamp(bj(x/p+.5),ad,a5);}d du(d c,d s){c.x+=bj(c.y*s.y)*(.5/s.x);l aj(c)*s;}k dv(d c,h r){l k(c-=clamp(c,r,1.-r),av(c)/r);}k dv(d c,d s,h r){s=s.yx/c8(s);c*=s;l k(c-=clamp(c,d(r),s-r),av(c)/r);}h bk(d p){k q=aj(p.xyx*.09153);q+=dot(q,q.yzx+19.19);l aj((q.x+q.y)*q.z);}h bk(h p){p=aj(p*.1031);p*=p+33.33;p*=p+p;l aj(p);}k fg(h p){k b1=aj(k(p)*k(.1031,.1030,.0973));b1+=dot(b1,b1.yzx+33.33);l aj((b1.xxy+b1.yzz)*b1.zyx);}d dp(d p){k b1=aj(k(p.xyx)*k(.1031,.1030,.0973));b1+=dot(b1,b1.yzx+33.33);l aj((b1.xx+b1.yz)*b1.zy);}af er(h p){af b2=aj(af(p)*af(.1031,.1030,.0973,.1099));b2+=dot(b2,b2.wzxy+33.33);l aj((b2.xxyz+b2.yzzw)*b2.zywx);}af er(d p){af b2=aj(af(p.xyxy)*af(.1031,.1030,.0973,.1099));b2+=dot(b2,b2.wzxy+33.33);l aj((b2.xxyz+b2.yzzw)*b2.zywx);}h bm(h x,h p){l bk(mod(x,p));}h c0(h x){h m;l o(bk(m=bj(x)),bk(m+1.),dk(x-m));}h a7(h x,h p){h m;l o(bm(m=bj(x),p),bm(m+1.,p),x-m);}h bm(d p,d s){l bk(mod(p,s));}h a7(d p,d s){p*=s;d m=bj(p);p-=m;p*=p*(3.-2.*p);h es=bm(m+d(0,0),s);h et=bm(m+d(0,1),s);h eu=bm(m+d(1,1),s);h ev=bm(m+d(1,0),s);l o(o(es,ev,p.x),o(et,eu,p.x),p.y);}h ah(d p,d b3,h c1,h c2,be c3){h ci=a7(p,b3),b9=1.,tw=1.;for(be m=0;m<c3;++m){p=aj(p+cp);b3*=c2;b9*=c1;ci+=a7(p,b3)*b9;tw+=b9;}l ci/tw;}h ah(h p,h b3,h c1,h c2,be c3){h ci=a7(p*b3,b3),b9=1.,tw=1.;for(be m=0;m<c3;++m){p=aj(p+cp);b3*=c2;b9*=c1;ci+=a7(p*b3,b3)*b9;tw+=b9;}l ci/tw;}h dw(d p,d b3,h c1,h c2,be c3){h ci=b6(a7(p,b3)),b9=1.,tw=1.;for(be m=0;m<c3;++m){p=aj(p+cp);b3*=c2;b9*=c1;ci+=b6(a7(p,b3))*b9;tw+=b9;}l ci/tw;}d cm(d p,d a,d b){d ab=b-a,ap=p-a;h t=bd(dot(ap,ab)/dot(ab,ab));l ab*t+a;}h ew(d c,d f){l dot(c,bh(90.)*cf(f));}h a1(d p,d b){d f=ae(p)-b;l a3(a4(f.x,f.y),0.)+av(a4(f,0.));}h c4(d p,d b){l cd(ae(p)-b);}h a9(d p,h r){l av(p)-r;}h cm(d p,d a,d b,h r){l a9(p-cm(p,a,b),r);}h cq(d p,d r){l a9(p/r,1.)/a3(r.x,r.y);}h b0(h a,h b){l a4(a,-b);}h dg(h a,h b,h ao){h a5=bd(.5+0.5*(b-a)/ao);l o(b,a,a5)-ao*a5*(1.-a5);}d db(h x){d f=d(dFdx(x),dFdy(x));l f/a4(av(f),1e-8);}h ak(h s,h f){l bd(1.-s/f);}h ak(h s){l bd(1.-s/fwidth(s));}af dx(d c,h s){l af(c/=s,bu(bd(1.-cx(c))),av(c)-1.);}h ex(k u){h ad=cl(u.yz)*.7;l pow(bd(ad),4.)+ad;}h dy(d c,h s){c/=s;c.y+=.06;c.x*=2.;l j(.3,.0,av(c));}k cn(k e,d c,h s){af b=dx(c,s);e*=1.+ex(b.a0)*ak(b.w)*.5;e*=1.-ai(dy(c,20.*s))*(1.-ak(b.w))*.3;l e;}h cr(d c,h t){c.x=ae(c.x);c.y-=.07;h f=cq(c,d(.31,.12-t*.02))/50.;f=a4(f,-cq(c-d(0,.01+.01*t),d(.28+t*.01,.07))/75.);f=a4(f,-a1(c-d(0,.1),d(.22-.02*t,.12)));f=a4(f,-a1(c-d(0,.1),d(.084-.012*t,.31)));f=a3(f,c4(c-d(0,-.09),d(i(-.09,.32,c.y)*(.04-.015*t),.32)));f=a3(f,c4(c-d(.11-.02*t,-.21+.01*t),d(i(-.07,.3,c.y)*(.03-.01*t),.15)));l f;}h ey(d c){h f=a9(c-d(0,.17),.32);f=b0(f,a9(c-d(0,.235),.27));f=b0(f,a9(c-d(0,.5),.15));c.y-=.09;d s=d(.09,.52);h a5=bd(-c.y/s.y);s*=.5;s.x*=j(1.05,.6,a5)+ai(j(.1,.02,a5));c.y+=s.y;f=a3(f,a1(c,s));l f;}k dz(d p,h bl,h ez){k am=k(-1,0,1),r=k(1e5);d b4=bj(p*bl),fh=am.yy;p-=(b4+.5)/bl;h bn=.5*bm(b4+am.yy,d(bl)),cs=.5*bm(b4+am.xy,d(bl)),ct=.5*bm(b4+am.yz,d(bl)),cu=.5*bm(b4+am.zy,d(bl)),cv=.5*bm(b4+am.yx,d(bl)),d0=.5*bm(b4+am.xz,d(bl)),d1=.5*bm(b4+am.zz,d(bl)),d2=.5*bm(b4+am.zx,d(bl)),d3=.5*bm(b4+am.xx,d(bl));d[4]ca,ad;if(mod(b4.x+b4.y,2.)<.5){ad[0]=1.+d(cv-cs,bn-d3);ad[1]=1.+d(cu-cv,bn-d2);ad[2]=1.+d(ct-cs,d0-bn);ad[3]=1.+d(cu-ct,d1-bn);ca[0]=d(cv,bn);ca[1]=d(cv,bn);ca[2]=d(ct,bn);ca[3]=d(ct,bn);}else{ad[0]=1.+d(bn-d3,cs-cv);ad[1]=1.+d(d2-bn,cu-cv);ad[2]=1.+d(bn-d0,ct-cs);ad[3]=1.+d(d1-bn,ct-cu);ca[0]=d(bn,cs);ca[1]=d(bn,cu);ca[2]=d(bn,cs);ca[3]=d(bn,cu);}for(be m=0;m<4;m++){ca[m]+=ad[m]*(d(m&1,m/2)-.5);ad[m]/=bl;h bx=c4(p-ca[m]/bl,ad[m]/2.-ez/bl);if(bx<r.x)r=k(bx,b4+ca[m]);}l r;}dl(dc,cl(ae(r)))dl(dh,av(r))h cb(k p,h s){p=cf(p);k a=aj(degrees(atan(p,p.yzx))/360.);l a7(a.x*s,s)*j(.9,.0,ae(p.z))+a7(a.y*s,s)*j(.7,.0,ae(p.x));}h cb(k p){l cb(p,45);}d e0(k p,be ax){l(ax==0)?p.yz:(ax==1)?p.xz:p.xy;}be e1(k u){u=ae(u)+k(.01,.02,.03);h v=cd(u);l(v==u.x)?0:(v==u.y)?1:2;}k e2(k e){k rgb=bd(ae(mod(e.x*6.+k(0,4,2),6.)-3.)-1.);rgb*=rgb*(3.-2.*rgb);l e.z*o(k(1.),rgb,e.y);}k bo(){k f=Cam.a0-Pos;h b=ah(f.xy/256.*bh(Cam.w),d(3),.7,3.,4),ad=1.-j(14.,-6.,av(f.xy)-b*8.)*j(128.,48.,f.z)*step(.1,Nor.z);l texture(Texture1,LUV).a0*2.*ad;}k e3(){l o(Ambient.a0,LightColor.a0,bd(dot(LightDir.a0,WNor)));}an(_9){h b=ah(c,d(5),.9,3.,4);k e=o(n(48,41,33),n(103,101,104),b);l e;}an(_10){h b=ah(c,d(3),.9,3.,4);k e=o(n(49,45,43),n(81,75,78),b*b);l e;}an(_11){h b=ah(c,d(7),.9,3.,4);c.x*=-1.5;c.y+=c.x*.5;c.x=1.-c.x+c.y;c=aj(c*28.);h a8=bd(1.-av(.1-c));a8*=j(.6,.2,av(.6-c));a8*=j(.6,.8,av(.1-c));a8*=j(.2,.6,b)*2.+1.;h ad=1.-j(.2,b+2.,cd(ae(c-.5)));l k((a8+1.)*o(.21,.29,b*b)*ad);}bi(_12){k e=a6(c).a0;h b=ah(c=bc(c,7.,.01),d(5),.7,3.,4),u=ah(c,d(7),.5,2.,4),r=av(c-=.5),a=ch(c),f=r+u*.8-.33;e=o(e,o(n(21,17,14),n(70,59,51),b),j(.5,.2,r+b*b*b));e*=j(.1,.11,f)+2.*pow(i(.4,.12,.1,f),8.);l af(e,1.-bu(j(.11,.06,f)));}au _13(){h b=ah(UV*.5+a2.x*d(9,5),d(7),.6,2.,4);b*=1.+.5*i(.5,.05,b);af e=a6(UV);al=af(o(n(66,111,155)*(.8+2.*b*b),e.a0*bo(),e.w),1);}h d4(d c,h s){h f=1e6,m=0.;for(;m<5.;++m){d p=d(0,-s)*bh(m*72.);f=a3(f,av(c-cm(c,p,p*bh(144.))));}l f;}an(_76){h b=ah(c,d(7),.9,3.,4);k e=a6(c).a0;h r=av(c-.5);h v=j(.46,.45,r);h ad=1.5-1.5*j(.0,.3,r*r);ad=o(ad,2.5,i(.42,.07,r));ad=o(ad,3.5,i(.44,.05,r));ad=o(ad,2.6,i(.36,.03,r));h u=.3+.2*j(.35,.30,r);ad*=1.-u*j(.3,.7,b);ad*=1.-.3*ai(j(.13,.05,r));ad=o(ad,2.5,j(.04,.01,r));ad-=ad*i(.03,.01,r)*.7;e=o(e,n(68,66,54)*ad,v);e*=1.-ai(i(.34,.02,r));e*=1.-ai(i(.46,.03,r));e*=1.-i(.41,.03,r)*.7;l e;}bi(_14){k e=_76(c);c=aj(c)-.5;h b=ah(c,d(3),.9,3.,4),f=a3(ae(av(c)-.4),d4(c,.35));l af(e,ak(f-.02+b*.02,.01));}au _15(){af e=a6(UV);al=af(e.a0*bo()+n(111,55,0)*e.w*(sin(a2.x*cj)*.5+.5),1);}d e4(d c,h s){l d(1.-av(c)/s,ak(av(c)-s));}bi(_78){h b=ah(c,d(5),.9,3.,4),t,bf,ao,r;k e=a6(c).a0;d b5,ac;b5.x=ae(c.x-.5);b5.y=a3(c.y,.4);r=av(b5-d(0,.4))-(.18-.06*j(.4,1.,c.y));ao=.25-.15*j(.9,.96,c.y)+.03*ai(j(.82,.86,c.y))+.07*j(.8,.2,c.y)+.07*ai(j(.35,.22,c.y))-.07*j(.22,.0,c.y);bf=a1(c-d(.5,.5),d(ao,.46));bf=a4(bf,-a1(b5,d(.15,.03))+.06);e=o(e,k(.6,.55,.55)-c.y*.3+b*.2,ak(bf));e*=1.-.7*i(.0,.013,bf);e*=1.-(r/.5-.1)*ak(bf);t=a4(r,c.y-.96);bf=ae(t-.02)-.03;bf=a4(bf,c.y-1.+b5.x*.5);bf=a4(bf,c.y-.96);e=o(e,k(1,1,.9)-c.y*.55,i(-.01,.01,bf));e=o(e,k(.2*b+.1),ak(t,.01));e*=1.-.2*i(.0,.05,t)*ak(bf);ac=e4(b5=c-d(.5,.4),.02);e*=1.+n(111,80,70)*i(.03,.01,av(b5));e*=1.-.5*i(.02,.01,av(b5));e=o(e,n(111,66,44)*(ac.x*1.5+.2),ac.y);l af(e,ak(t-.03,.02));}au _79(){af e=a6(UV);d c=aj(UV);c.x=ae(.5-c.x);h t=aj(-a2.x),r=av(c-d(0,.4)),ad=t*pow(a4(0.,1.-r),4.)*e.w;if(t>.75)ad+=j(.03,.01,ae(aj(c.y+c.x*.5+t*2.)-.45))*j(.1,.08,c.x);al=af(e.a0*bo()+n(180,150,5)*ad,1);}an(_16){h b=ah(c,d(5),.9,3.,4);k e=o(n(44,14,16),n(93,63,63),b*b);l e;}k d5(d c){h am=3e-3,a=0.;d g=d(6),r=dc(c,g).xy;for(be m=0;m<9;++m)a+=cl(ae(dc(d(m%3-1,m/3-1)*am+c,g).xy-r));l k(c+r.xy/g,a);}an(_17){h b=ah(c,d(3),.9,3.,4);k e=o(n(80,70,72),n(128,120,120),b*b);k ac=d5(c);e*=o(.95,1.1,a7(ac.xy,d(6)));e=o(e,n(168,128,120),j(.5,1.,ac.z)*b*.7);l e;}bi(_18){h b=ah(c,d(3),.9,3.,4);k"
" e=o(n(80,70,72),n(128,120,120),b*b);k ac=d5(c);h v=j(.5,1.,ac.z);h r=j(.4,.2,av(.5-aj(ac.xy)));e*=o(.95,1.1,a7(ac.xy,d(6)))-2.*r*b*b;e=o(e,n(168,128,120),v*b*.7);l af(e,v*r);}au _19(){af e=a6(UV);al=af(e.a0*bo()+i(.5,.125,aj(UV.y*.5+a2.x*.5))*e.w*.3,1);}an(_20){h b=ah(c,d(5),.9,3.,4);k pt=dz(c,8.,.31);k e=o(n(66,58,55),n(118,107,105),b);h ad=1.-.5*j(.034,.036,pt.x);ad=o(ad,1.4,i(.033,.004,pt.x));l e*ad;}h e5(d c){h b=a7(c,d(64)),a8=0.,f=1e6;for(;a8<11.;++a8)f=dg(f,ae(av(.5-ae(c-dr(a8)))-o(.36,.29,ck(a8+.7)))-o(.015,.03,b),.01);l f*1e2;}k d6(d c){k s,p;for(be m=0;m<3;++m){p=k(c,0);p[m]+=1e-4;s[m]=e5(p.xy);}l k(cf(s.xy-s.z),s.z);}an(_21){h b=ah(c,d(5),.9,3.,4),ad;k e=o(n(51,46,43),n(165,147,143),b*b),f=d6(c);ad=1.-.5*(f.y-f.x)*i(.5,3.,f.z)*j(1.,.0,f.z);l e*ad*.8;}an(_22){h b=ah(c,d(3),1.1,3.,4),ad;k e=o(n(51,46,43),n(165,147,143),b*b),f=d6(c);ad=1.-.5*(f.y-f.x)*i(.5,3.,f.z)*j(1.,.0,f.z);l e*ad;}an(_23){h b=ah(c,d(5),.9,3.,4),ad=.18*(.7+b*b);k g;c=bc(c,13.,.007);c6(g,c,ai(j(.3+b*.2,.9,ah(p[m],d(23),.5,2.,4))));l k(ad*(1.-g.y*g.z));}an(_48){h b=ah(c,d(5),.9,3.,4);k e=o(n(77,55,53),n(62,48,48),a7(c,d(128,13)))*(.7+b*b),g;c=bc(c,13.,.007);c6(g,c,ai(j(.4+b*.4,.95,a7(p[m],d(63,43)))));e*=j(1.3,.9,g.z);l k(e*(1.+g.y*g.z));}h d7(d c,d s){c.y=a4(c.y,0.);l cq(c,s);}k dd(k e,k b,d c,h a5,h s){h y=(c.y-a5)/s,p=1.-y*y;e*=1.-i(-1.,1.,y);if(p>0.)e=b*(p*(.8+.2*i(.5,.25,aj(c.x/s))))*(.7+ai(i(.2,.7,y)));l e;}k e6(d c,h u){l k(u*u*.4);}an(_49){c.x*=.5;h b=ah(c*d(2,1),d(3,5),.9,3.,4),u=.75+b*b,t=c.y+.2*a3(.4,i(.5,.33,aj(c.x*4.))),e7=d7(c-d(.25,.62),d(3,2)/32.),c5=d7(c-d(.25,.55),d(3,2)/48.),r;k e=o(n(66,50,51),n(111,66,44),bu(i(.31,.01,c.y))),bv;d p=c,q;p.x=aj(p.x*4.);if(c.y>.3)e=cn(e,d(4.*ae(p.x-.5)-1.6,aj(c.y*16.)-.5),.07);r=ae(p.x-.5);e*=1.-.3*j(.31,.32,c.y)*j(.87,.86,c.y)*(j(.035,.03,.5-r)+i(.48,.01,r)-i(.46,.02,r));e=o(e*u,e6(c,b),a4(j(.31,.3,c.y),ak(c5)));e*=j(1.5,.7,c.y);if(c.y<.306)e*=1.-i(.3,.05,c.y)*ak(-c5+10.,20.);e*=1.-i(.316,.004,c.y)*ak(-c5);if(c.y<.1)e*=.0;q=c;q.y+=i(.1,.01,mod(q.x,.33))/2e2;e=dd(e,2.*b*n(93,84,79),c,.185,.015);e=dd(e,2.*b*n(138,77,48),c,.13,.025);e=dd(e,2.*b*n(112,71,51),c,.09,.015);e=dd(e,2.*b*n(138,77,48),q,.05,.015);p.x=ae(aj(c.x*6.-.5)-.5)/6.;e*=1.+.5*j(.04,.03,p.x)*i(.18,.03,p.y);r=c4(p-d(0,.12),d(.03,.01));r=b0(r,c4(p-d(0,.11),d(.01)));e*=1.-ai(i(.0,.04,r));e=o(e,n(166,99,77)*2.*b*(.75+.5*ai(i(.125,.01,c.y))),ak(r));q=p;q.y-=.07;r=a9(q,.03);e*=1.-ai(i(.0,.07,r));e=o(e,n(127,83,72)*b*2.*j(.01,-.005,r),j(.005,.0,r));q.y-=.004;r=a9(q,.015);e*=ai(j(-.01,.01,r));q.y+=.013;r=a9(q,.05);e+=n(67,38,30)*4.*bu(b)*ai(i(-.02,.015,r)*i(.023,.02,c.y));r=b0(e7,c5);r=b0(r,(c.y-.3)*3e2);e*=1.-.5*i(-2.,17.,c5)*j(.26,.3,c.y);bv=n(67,39,17)*u;bv=o(bv,k(u*.2),i(0.,4.,r)*b);bv*=1.-.4*pow(i(.0,3.,r),4.);bv+=(bv+.6)*bu(b)*ai(i(-6.,8.,r)*i(.66,.04,c.y))*ak(r);if(c.y<.56)bv=cn(bv,d(24.*ae(c.x-.25)-1.85,aj(c.y*24.+.5)-.5),.15);e=o(e,_48(c),j(.85,.9,t)+step(c.y,1./256.));e*=1.+i(.88,.015,t)-ai(i(.87,.03,t));l o(e,bv,j(1.,.1,r));}k e8(k e,k ao,d c,be w,be a5){h b=ah(c,d(w,a5),.5,2.,2);e*=.9-.3*j(.15,.1,ae(b-.5));l o(e,ao,i(.5,.1,b));}an(_54){c=bc(c,9.,.005);be m=0,ad[]=be[](13,43,17,47,23,59,27,63);h b=ah(c,d(19),.7,2.,4);k e=o(n(40,50,60),n(46,33,27),b)*(.5+b);for(;m<8;m+=2)e=e8(e,o(n(145,140,137),n(132,123,116),b),c,ad[m],ad[m+1]);l e;}k e9(k e,k ao,d c,be w,be a5){h b=ah(c,d(w,a5),.5,2.,2);e*=1.-.15*ai(j(.15,.1,ae(b-.5)));l o(e,ao,i(.5,.1,b));}an(_65){h b=ah(c,d(13),.9,3.,4),u=ah(c,d(7),.9,3.,4);k e=o(n(111,66,55),n(80,55,52),ai(j(.8,.2,u)))*(.8+.8*b*b),ao=e;c=bc(c,13.,.01);be m=0,ad[]=be[](13,43,17,47,23,59,27,63);b=ah(c,d(19),.7,2.,4);for(;m<6;m+=2)e=e9(e,ao,c,ad[m],ad[m+1]);l e;}k fa(k e,k ao,d c,be w,be a5){h b=ah(c,d(w,a5),.5,2.,1);e*=.9-.3*ai(j(.15,.1,ae(b-.5)));l o(e,ao,i(.5,.1,b));}an(_43){h b=ah(c,d(3,29),.9,2.,4),t=.8+.8*b*b,f=ae(c.y-.61),bf=j(.25,.24,f),v;k e=n(140,127,127),ao=e;d p=c;e*=1.-.1*j(.85,.86,c.y);e=t*o(e,n(110,55,50),j(.33,.32,c.y));p.y+=p.x*.11+b*.007;p.y=aj(p.y*9.)-.5;v=j(.0,.1,ae(p.y)-.2);be m=0,ad[]=be[](3,29,5,37,9,63,27,63);for(;m<6;m+=2)e=o(e,fa(e,ao,c,ad[m],ad[m+1]),v*bf);e*=1.+t*bf*(+.6*i(.1,.1,p.y)-.7*i(-.25,.3,p.y)-.5*i(.2,.1,p.y));e=o(e,n(99,66,51)*t,i(-.15,.1,p.y)*bf);e*=1.+i(.36,.005,c.y)+i(.34,.005,c.y)+i(.865,.005,c.y)+i(.89,.01,c.y)-.5*ai(i(.245,.01,f))-.7*ai(i(.35,.01,c.y))-.5*ai(i(.325,.02,c.y))-.8*ai(i(.875,.02,c.y))-.3*ai(i(.9,.02,c.y));e*=.3+bu(b6(c.x));l e;}k d8(k e,d p,h s,h v){s=dc(p,d(s)).z/s*1e2;e*=1.+.5*v*j(.9,.2,s)-.5*v*i(2.5,.5,.3,s);l e;}k d9(k e,d c,h fb){h b=ah(c,d(4,9),.9,3.,4),t=.8+.8*b*b,a,f,v,s,ao,m,ac,r,z;k co=o(n(133,100,88),n(133,100,100),b)*t;d p,q;p=q=c;q.x=ae(q.x);f=a9(p,.31);ac=ch(q);v=j(.01,.0,f);e=o(e*j(.0,.05,f+fb),k(.13*t),v);e=d8(e,p,37.,j(.04,.02,ae(f+.07)));a=ac*22.;m=bj(a);s=a-m;ao=j(.23,.22,ae(ac-.25))+ck(m)*j(.0,.1,q.y);f-=r=(f*.3+.005)*ao;v=j(.0,.1,q.y)*ak(ae(f+.015)-.015);e=o(e,co,i(-.005,.01,f));e=o(e,n(130,75,44)*t,i(-.02,.005,f)*j(.0,.1,q.y));e*=1.-.3*j(.025,.03,-f)-.5*j(.4,.5,ae(s-.5))*v+.2*i(.5,.3,ae(s-.5))*v-.5*i(-.015,.007,f)-.5*i(-.03,.007,f)-.5*i(-.1,.005,f+r)-.5*i(-.115,.005,f+r)-.5*i(-.125,.015,f+r)-.5*i(-.145,.005,f+r)+.9*i(-.11,.007,f+r)+.5*i(-.14,.005,f+r)-b*i(.225,.005,ae(ac-.25))*ak(ae(f+.015)-.015);a=ac*72.;m=bj(a);s=a-m;ao=step(.7,bk(m))*step(q.y,.0)*j(.02,.0,ae(f+.02));e=o(e,k(co*.6),ao*j(.4,.3,ae(s-.5)));e*=1.-.7*ao*i(.4,.1,ae(s-.5));l e;}k di(d c){h b=ah(c,d(4,9),.9,3.,4),t=.8+.8*b*b,a,f,v,s,ao,m,ac,r,z;k co=o(n(133,100,88),n(133,100,100),b)*t,e=k(.1*t);d p,q;p.x=c.x-.5;p.y=a4(c.y-.2,0.)*1.89;ac=atan(p.y,ae(p.x))/cj;f=a9(p,.48);ao=j(.3,.31,ac);f*=1.-.2*j(.3,.31,ac)-.1*j(.43,.44,ac);a=ac*(ac>.44?2.:ac>.3?63.:31.);e=o(e,co,j(.03,.01,ae(f)));v=ak(ae(f-.01)-.02);m=bj(a);s=a-m;if(ac>.33&&ac<.44)s=aj(s+bk(m)*.6-.3);e*=1.-.5*v*i(.307,.01,ac)-t*v*i(.5,.1+ao*.2,s)+b*v*i(.52,.2+ao*.2,s);e*=1.-.9*i(-.015,.015,f)-.5*i(.0,.01,f)-.7*i(.03,.02,f)+i(.01,.015,f);q=p;q.y-=.5;q.x=ae(q.x)+.6;f=a9(q,1.13);v=j(.03,.02,ae(f))*j(.5,.6,q.y);e=o(e,co*bd(1.-ae(f-.015)/.03),v);e*=1.-.5*v*i(.005,.01,f)+.5*v*i(.017,.005,f);q.x=ae(c.x-.5)-.35;q.y=c.y*9./4.-2.1;f=a9(q,.13)*10.;a=ch(q)*49.;m=bj(a);s=a-m;ac=j(.85,.9,bk(m));for(be cc=0;cc<2;++cc,f+=.3){e=o(e,co*(b*.5+.2),j(.09,.03,ae(f)));e*=1.+.7*ai(i(.01,.05,f));}p.y=(c.y-.7)*9./4.;f=a9(p,.43);a=atan(p.y,ae(p.x))/cj;a=a4(a,-.48);r=a;m=bj(a*=23.);s=a-m;ao=ck(m)*.2-.1*j(.0,.1,-f);ac=j(.1,.2,ae(s-.5)-ao);f+=ac*.007;r=(1.-ac)*ai(i(.5,.3,r))*j(.25,.05,ae(s-.5));f-=.17*r;v=i(.04,.0,-.4,f);e=o(e,co*(b*.4+.4),v);e=d8(e,p,31.,j(.1,.05,ae(f+.15))*ac);e*=o(1.,1.-i(.1,.2,.4,ae(s-.5)-ao),v*b);e*=1.-.7*ai(i(.03,.03,f))-.7*ai(i(.03,.03,f+.05))*ac-.7*ai(i(.0,.02,f+.05))*ac-.3*j(.04,.06,-f)*ac+.5*i(.02,.0,-.1,f)+i(.0,.01+.07*r,f)+i(.0,.01,f+.03)*ac;p.y-=.05;e=d9(e,p,0.);l e;}an(_44){c.y=(c.y+8.)/9.;l di(c);}an(_45){c.y=(c.y*4.+4.)/9.;l di(c);}an(_46){if(c.y<.01)++c.y;c.y=c.y*4./9.;l di(c);}an(_60){h b=ah(c,d(5),.9,3.,4),t=dw(bc(c,4.,.01),d(7),.5,3.,5),u=a7(bc(c,4.,.05),d(9)),ce,am;k pt=dz(c,4.,.1+u*t*.05),e;d f=db(pt.x);ce=bk(aj(pt.yz));e=n(74,65,62)*(.8+.8*b*b);e+=i(.6,.3,u)*j(.3,.9,b*t)*.2;e*=1.-i(.5,.4,u)*j(.5,.7,t)*.1;e=o(e,n(86,74,78),i(.5,.1,b)*i(.7,.3,ce)*.7);e=o(e,n(105,90,70),i(.3,.1,t)*i(.3,.3,ce)*.3);am=i(.015,.005+.015*u,pt.x)+i(.4,.1,u*t)*.4;e*=1.-b*j(.015,.05,pt.x)*.7;e*=1.+am*b*(f.y-.5)*.7;e*=.9+.2*ce;e*=.9+.2*b6(a7(c-pt.yx,d(5)));l e;}an(_47){k e=a6(c).a0;c-=.5;e=d9(e,c*.9,.02);l e;}k cw(d c){c*=1.5;h b=ah(bc(c,7.,.02),d(9),.7,3.,2),t=b,u=a7(c,d(13)),a,s,f;k e=a6(c).a0;d p;p.x=ae(c.x-.75);p.y=a4(c.y-.58,0.)*1.15;a=atan(p.x,p.y)/cj;s=aj(a*7.+.5);f=a9(p,.45);f-=.06*j(.4,.33,c.y);f-=.05*j(.15,.07,ae(s-.5))*step(.63,c.y);f=b0(f,c.y-.107);if(c.y<.6)f=b0(f,ae(p.x-.493)-.113);f=b0(f,a9(p,.6)+.044*j(.48,.43,c.y));e=o(e,n(144,125,115)*t,ak(f-.1,.005));e*=1.-.3*i(.12,.11,.1,f)+.5*i(.1,.005+.015*u*u,f);l e;}an(_34){l cw(d(5,0)/6.+c*d(1,4)/6.);}an(_35){l cw(d(1,0)/6.+c*d(4)/6.);}an(_36){l cw(c*d(1,4)/6.);}an(_37){l cw(d(5,4)/6.+c*d(1,2)/6.);}an(_38){l cw(d(1,4)/6.+c*d(4,2)/6.);}an(_39){l cw(d(0,4)/6.+c*d(1,2)/6.);}an(_61){h b=ah(c,d(13,1),.7,2.,3);k e=a6(c).a0*.7;e*=1.-ai(j(.4,1.,b));l e;}k ea(d c,d s){h b=ah(c,d(5),.9,3.,4),u=ah(c,d(31,3),.5,3.,3),t=.75+b*b;d p=c;k e=a6(c).a0;if(c.y<.38)e=o(n(92,43,15),n(66,44,33),j(.1,.05,c.y))*t*(.5+.5*j(."
"0,.35,c.y));e+=b*s.y*ai(i(.32,s.x*.015,c.y))+.3*b*i(.34,.05,c.y);e*=1.-i(.38,.005+b*b*.03,c.y)+3.*i(.15,.2,c.y)*(u-.5);l e;}an(_62){h b=ah(c,d(5),.9,3.,4),t=.75+b*b,f,bf,m;d p=c;k e=ea(c,d(1));p.x=mod(p.x,1./7.)-.07;p.y-=.21;f=a9(d(.75*p.x,df(p.y,.1)),.033);bf=ak(f,.005);f=a9(d(.75*p.x,df(p.y+.005,.09)),.033);m=ak(f+.015);e=o(e,n(83,81,66)*t,(bf-m)*j(.1,.3,c.y));e*=1.-j(.17,.25,c.y)*m;e+=ai(i(.0,.015,f))*i(.32,.03,c.y);e*=1.+3.*pow(i(-.01,.03,f),4.)*i(.09,.03,c.y);f=a9(d(.75*p.x,df(p.y+.03,.1)),.033);e*=1.-ak(f+.01,.02)*(1.-bf);if(c.y>.09&&c.y<.3)e=cn(e,d((ae(p.x)-.035)*36.,aj(c.y*36.)-.5),.1);l e;}d fc(d p){p.x=ae(p.x);d q=p,ac;q.y-=.5;h f=a9(q,.35),am,e;ac=q/.35;q.y+=.25;q.x-=.15;f=a3(f,a1(q,d(.09,.05))-.1);am=cq(q,d(.15,.1))/5e1;e=.1+dot(d(ac.y,bu(bd(1.-cx(ac)))),d(.3,.3));q.y+=.2;q.x=p.x;e=a4(e,bd(.4-av(q)));e+=.15*i(.0,.1,am)-.1*ak(am+.12,.15);f=a3(f,a1(q,d(.15-j(-.15,.15,q.y)*.07,.03))-.09);e*=1.-j(.05,.25,q.x)*j(.2,.1,ae(q.y+.12));q.y-=.06;e-=.5*ak(cq(q,d(.05-j(-.1,.1,q.y)*.03,.06))/1e3+.03,.05);l d(bd(e),ak(f,.02));}an(_63){h b=ah(c,d(9),.7,2.,4),t=.75+b*b;k e=ea(c,d(4,.3));d p=c,s;p.x=mod(p.x,.2);p-=.1;s=fc(p*5.);l o(e,o(k(.5,.4,.3),k(.95,.8,.55),t)*t*s.x,s.y);}an(_55){c.y-=1./32.;d p=du(c.yx,d(8)),q=aj(p),ac=bc(c,31.,.002),ce=p-q;h b=ah(bc(c,5.,.02),d(7),1.,3.,4),t=.8+.8*b*b,u=a7(c+dr(bk(ce)*64.),d(23)),v=ah(c,d(9),.7,3.,4),f=ah(ac,d(63),.7,3.,4),r=ah(ac-d(0,.002),d(63),.7,3.,4),ad=f-r,am=dv(q,.03+.03*b6(u)).z,a5=bk(ce);k e=o(n(91,61,42),n(70,30,15),am*b);e=o(e,n(70,48,35),j(.5,.6,v))*t;e*=1.+ad*(.1+u+i(.6,.1,v))*(1.-am)-t*j(.7,1.,am)*a7(c,d(13))+.5*b*i(.3,.3,am);f=ah(ac,d(23),.5,2.,4);e*=1.-.2*j(.6,.7,f)*a5+.3*i(.6,.05,f)*a5*u;e*=.9+.2*a5*(1.-am);e*=.9+.4*pow(dw(c-bk(ce/8.),d(5),.6,2.,4),4.);l e;}bi(_56){k e=a6(c).a0;c=aj(c*2.+d(8,3)/32.);h u=a7(c,d(19)),v,r;d p=c-.5,q=d(3,17)*d(ch(p),av(p)+(u-.5)*.03),am;q.x+=bj(q.y)*cp;q.x*=bj(q.y);r=av(am=aj(q)-.5);v=i(.5,1.,4.5,q.y)*u;e*=1.-v*ai(i(.3,.2,r))*5.*am.y-v*j(.4,.5,r);e*=j(.9,1.2,q.y);l j(.5,1.1,q.y)*af(e,1);}au _57(){d p=UV-dp(a2.x*d(3,5));h b=ah(p,d(13),.6,2.,4);af e=a6(UV);al=af(o(b*b*k(3,.4,0),e.a0,e.w)*bo(),1);}bi(_58){k e=a6(c).a0;c=aj(c*2.+7./32.);h b=ah(c,d(5),.6,3.,4),r=av(c-.5)+b*b,v=j(.2,.6,r);l af(o(b*k(.5,.2,.0),e,v),v);}au _59(){af e=a6(UV);h b=ah(bc(UV-a2.x*d(1,3)/2e2,a2.x*.4,4.,.03),d(7),.6,3.,4);e.a0=o(b*n(99,9,5)+j(.78,1.5,b),e.a0,e.w);al=af((e.a0+(1.-e.w)*cb(Ref)*.2)*bo(),1);}bi(_30){h b=ah(c-=.5,d(5),.9,3.,4),t=.75+b*b,u=a7(bc(c,7.,.02),d(17)),r=av(c),ao=r>.4?38.:r>.32?28.:16.,a=aj(atan(c.y,c.x)/dq),m=bj(a*ao),b7=ae(ae(r-.41-u*.002)*1e2-6.),v=j(1.5,1.4,b7),dj[]=h[](1.,3.,-.145,-1.,2.,.166),f,eb,s;d p=c;k e=n(78,68,63);e*=1.+.5*ai(i(.49,.005+.015*u*u+.015*b,r));e=o(e,n(83,52,47)*(.6+.4*u*u),v)*t;e*=1.-.5*i(1.5,.5,b7)+b*i(1.,.5+.5*u,ae(r-.418)*1e2-5.)-b*i(.5,.08,aj(a*ao+.5))*v+b*i(.5,.1,aj(a*ao+.55))*v;v=j(.34,.33,r);e=o(e*(1.-.5*v),n(83,52,47)*t,u*b*v);e=o(e,n(112,86,31)*t,v*ai(i(.1,.15,.45,b)));e=o(e,n(77,66,77)*t,v*j(.5,.8,b)*.5);e*=1.-.7*i(.27,.34,.35,r);b7=r+u*.004;v=r>.21&&r<.31?1.:0.;e*=1.-i(.325,.005,b7)-i(.31,.005,b7)-b*ai(i(.29,.005,b7))-b*ai(i(.23,.01,b7))-.5*ai(i(.21,.02,b7))+ai(i(.3,.01,b7))*b+ai(i(.22,.01,b7))*b-b*i(.5,.07,aj(a*ao+.5))*v;if(r<.23)m+=37.;if(r<.31)m+=73.;if(r<.31)m+=91.;e*=o(1.,.9+.2*ck(m),v);v=j(.01,.0,ae(r-.411)-.039);m=bj(a*72.);p*=bh(m*5.);s=0.;f=1e6;be cc=0;for(;cc<6;cc+=3){f=ds(f,eb=dot(p,cf(d(dj[cc],dj[cc+1])))+dj[cc+2]);s+=s+h(eb>0.);}if(s==3.)++m;else m+=66.*s;m=ck(m);e=o(e,t*n(90,80,75),v);e=o(e,t*n(127,111,88),m*b*v);e*=o(1.,.7+.6*bk(m),v);e*=1.-v*ai(i(.0,.006,f))*b+v*ai(i(.006,.006,ae(f)))*b*.5;m=bj(a*4.);p=ae(c*bh(m*90.+45.));f=1e6;for(cc=0;cc<2;++cc,p=ae(p*bh(45.)))f=ds(f,ae(av(p-d(0,.12))-.16));v=j(.21,.2,r);b7=cz(cz(f,.012),.001);e*=1.-j(.21,.2,r)*ak(.012-f)+b*v*ai(i(.005,.005,f))-.5*v*ai(ak(b7-.001,.001));l af(e,(1.-j(.21,.15,r)*ak(.028-f,.02))*j(.07,.087,r));}bi(_31){d p=aj(UV)-.5;h b=ah(bh(a2.x*333.)*p/(.8+.2*sin(a2.x*61.)),d(53),.7,2.,4);af e=af(1.-b*k(0,.3,1),1),bv=a6((bh(a2.x*30.)*p/(.8+.2*sin(a2.x*1.26)))+.5);e.a0=o(e.a0,bv.a0,bv.w);bv=a6(UV);e.a0=o(e.a0,bv.a0,bv.w)*bo();l e;}h fd(d p){p=c9(p,8.);h f=a9(p,.41);f=a3(f,a1((p-d(.34,0))*bh(45.),d(.1)));f=a4(f,p.x-.45);l f;}an(_32){d p=c-.5,q;h b=ah(c,d(9),.7,2.,4),t=.8+.8*b*b,r=a9(p,.41),f=fd(p),ad=dFdy(f)/.004,v=ak(f+.01,.007),a=ch(p),am,u,x,z;k e=a6(c).a0,ao=n(155,135,115)*t;e*=1.-(.5*-ad+.5)*j(.03,.0,f);e=o(e,ao,v);am=av(p)*9.;q.x=a*bj(am+1.)*3.;q.y=aj(am);u=i(.5,.2,a7(bc(c,7.,.03),d(41)));u=ah(q,d(3,9),.5,2.,4)*i(.5,.5+.5*u,q.y);e=o(e,n(100,85,80)*b6(u)*b,ak(r+.15,.02));q=p;q.x=ae(p.x);am=a4(a4(f,ew(q,-d(.08,.4))),ae(r+.06)-.09);z=a1(q-d(0,.3),d(.01,.03));am=b0(am,z-.02);x=ak(-am,.01);e*=1.+ad*v*j(.02,.0,-f)*j(.01,.0,-r)+x*i(.035,.015,-r)+.5*x*i(.13,.01,-r)+.7*i(.08,.007,z)*(1.-x)-.7*x*ai(i(.01,.04,-r))-.6*x*ai(i(.13,.06,.03,-r))-.5*x*ai(i(.12,.02,-r))*v-.9*ai(i(.12,.15,.2,-r))*v-.5*ai(i(.0,.05,am));e+=k(.8,.8,1)*pow(bd(1.-av(c-d(.41,.59))/.35),8.);q.x=a;q.y=j(.05,.12,-r);am=dc(q,d(37,1)).z;v=i(.085,.035,-r)*x;e*=1.+.5*v*i(.0,.2,am)-.3*v*i(.3,.3,am);am=a1(p+d(0,.33),d(.01,.03))-.03;ad=dFdy(am)/.004;e=o(e,ao*(.4+.8*j(.25,.41,-p.y)),z=ak(am,.01));e*=1.+.7*i(.005,.01,am)*ad-.5*i(.0,.01,.05,am);am=a1(q=p+d(0,.35),d(.01,.015))-.01;ad=dFdy(am)/.004;e*=1.+.5*i(.005,.01,am)-.5*ai(i(.0,.01,am));e+=k(1,.7,.5)*pow(bd(1.-av(q)/.11),8.);l e;}au _33(){k e=a6(UV).a0*bo();d c=aj(UV)-.5,p=c;h t=mod(a2.x*2.,7.),m=bj(t),f=1e6;if(m==0.)f=ey(p*2.4+d(0,.05));if(m==1.){p.x=eq(p.x,.1,-1.,1.);f=a1(p,d(.02,.15))*2.;}if(m==2.){f=a3(f,a1(da(p,.0)+d(.13-j(-.3,.3,c.y)*.17,0),d(.02,.15)));f=a3(f,a1(p+d(0,.07),d(.07,.02)))*2.;}if(m==4.)f=cr(p*1.8,.5);else f=cz(f,.005);al=af(e+ak(f,.02)*aj(-t)*k(.5,.05,.05),1);}an(_64){h b=ah(c,d(13),.9,3.,4),u=ah(c,d(7),.9,3.,4);k e=o(n(60,50,50),n(87,47,37),ai(j(.7,.25,u)))*(.7+.8*b*b),g;c=bc(c,31.,.003);c6(g,c,bu(j(.0,.9,a7(p[m],d(93)))));e*=1.-(g.y+.4)*ai(b*g.z)*g.z;l e;}an(_68){h b=ah(c,d(5),.9,3.,4);k e=n(67,64,63)*(.6+.5*b),g;c=bc(c,31.,.003);c6(g,c,bu(a7(p[m],d(53,93))));e*=1.-.3*g.y*g.z*g.z;l e;}bi(_24){c=bc(c,7.,.01);h b=ah(c,d(9),.7,2.,4),u=ah(c,d(13),.5,2.,4),v=j(.6,.9,ah(bc(c,5.,.03),d(11),.6,2.,4));k e=n(127,70,55)*(.85+.3*b);e*=1.-.2*ai(j(.3,.0,b*b))-.2*v-.3*j(.6,.77,u)+.3*j(.5,.9,b);e+=.5*ai(j(.5,1.,ah(c,d(17),1.,2.,3)));l af(e,1.-v);}au _26(){af e=a6(UV);d c=aj(UV);c.y-=.2*a2.x;h b=ah(bc(c,7.,.02),d(5),.9,2.,4);al=af(o(n(25,10,8)*b,e.a0,e.w)*bo(),1);}an(_25){d p=c-.5;p=bc(p,17.,.007);p.x*=2.-c.y*1.5;h b=ah(c,d(9),.7,2.,4),u=a7(c,d(7)),f=av(p),s;k e=_24(c).a0;s=aj(f*=13.);if(f<=6.){e*=1.-pow(j(6.,.5,f+b*b),6.);u=j(.3,.7,u);e*=1.-u*b*i(.4,.2,s)+u*b*i(.6,.4,s);}l e;}an(_27){c=bc(c,13.,.003);h b=ah(c,d(7),.9,3.,4),u=ah(c,d(5),.5,2.,4),t=.5+b;k e=n(80,38,34),ac=dh(c,d(23));e=o(e,o(n(180,125,118),n(165,78,51),u),b*i(.0,.4+u*.4,ac.z))*t;l e;}an(_28){h b=ah(c,d(7),.9,3.,4),t=.8+.4*b,m,r=.7,ad,v;k e,ac=dh(c,d(23));d p=ac.xy/r,q=c+ac.xy/23.;m=bk(aj(q)*3.3);e=o(n(155,55,55),n(200,166,155),j(.75,.45,q.y))*t;v=i(.5,.5,av(p));ad=dot(d(-p.y,bu(bd(1.-cx(p)))),d(.6+m*.3,.3));e*=1.-b*.8*j(.5,.1,ac.z)+b*v*ad;e*=t*t*t*t;l e;}an(_29){h b=ah(c,d(13),.9,3.,4),t=.4+b*b,u=b6(a7(bc(c,12.,.02),d(48))),m,r,ad,v;k e=n(60,50,46)*t,ac=dh(c,d(17));m=bk(aj(c+ac.xy/17.));r=.4+.3*m;d p=ac.xy/r;v=a3(j(1.1,1.,av(p)),j(.0,.15,ac.z));ad=dot(d(-p.y,bu(bd(1.-cx(p)))),d(.1+m*.2,.3));e+=b*v*ad*u;u=b6(ah(bc(c,13.,.01),d(23,43),.5,2.,3));e*=1.+(1.-v)*i(.4,.4,u);l e;}an(_66){h b=ah(c,d(7),.9,3.,4),u=ah(c,d(3),.5,3.,4);k e=o(n(103,56,53),n(73,58,71),j(.1,.7,u))*(.75+b*b);l e;}an(_67){h b=ah(c,d(13),.9,3.,4),u=a7(bc(c,5.,.05),d(9)),f=b6(aj(c.x*4.)),v=j(.1,.15,f)*j(1.,.99,c.y);k e=n(51,44,44);e=o(e,n(73,55,52),j(.2,.2,b)*u*v);e=o(e,n(69,60,66),j(.7,.1,b)*b*v);e=o(e,n(99,77,77),j(.1,.5,u)*u*v*b*b*.3);e*=.6+.3*b+.3*b*b;e*=1.+.9*ai(i(.21,.02+.1*u,f+b*.05))*v*b;e*=1.-ai(j(.49,.5,ae(c.y-.5)));e*=1.-j(.05,.2,f)*j(.16,.1,f);e*=1.+i(.99,.007,c.y);l cn(e,d(f-.4,aj(c.y*8.)-.5),.07);}k ec(d c,h s){h b=ah(c,d(3,1.+s+s),.7,2.,4),f=b6(c.x),v;c.y*=2.;k e=o(n(71,60,58),n(110,88,77),j(.1,.05,f))*(.7+.6*b);e*=1.-j(.05,.0,c.x)*(1.-b*b);e*=1.+.5*i(.05,.02,c.x);d p=d(f-.35,aj(c.y*s)-.5);af ao=dx(p,.11);v=ak(ao.w);e*=1.-.7*dy(p,1.1)*(1.-v);e=o(e,(ao.y>.0?n(128,105,88):n(200,111,66)*j(-.2,.7,ao.z))*(.4+2.*b*pow(b"
"d(cl(ao.yz*.7)),4.))*(1.-.6*i(-.1,.4,ao.y)),v);l e;}an(_40){l ec(c,4.);}an(_41){l _40(c.yx);}an(_42){l ec(c,1.);}an(_50){h b=ah(c,d(40,5),.9,3.,4);k e=n(110,110,98)*(.8+.8*b*b);if(c.y<1./4.)e*=.5;e*=1.-.4*j(.4,.0,b)+.5*j(.02,.0,c.y)+.2*i(.24,.01,c.y);l e;}an(_51){d p=c,q;p.y*=22.;q=aj(p);h b=ah(c,d(3,23),1.,2.,6),u=ah(c,d(3,33),.7,3.,4),ce=bk(p.y-q.y);k e=n(92,67,53)*(.8+.8*b*b);e*=1.-ai(j(.1,.0,a3(q.y,1.-q.y)))*b;e*=1.-.2*smoothstep(.3,.7,u);e*=.8+.3*b*ce;l e;}an(_52){h b=ah(c,d(13),.9,3.,4),x=c.x*16./3.;k e=a6(c).a0*j(.15,.21,c.x);if(x<1.)e=n(59,48,49)*(.7+.6*b);e*=1.+.5*i(.05,.05,b6(x));l cn(e,d(ae(c.x-3./32.)-.07,mod(c.y,.1)-.05),.004);}an(_53){d p=du(c,d(6,4)),q=aj(p),b5=q;h b=ah(bc(c-=.5,5.,.03),d(13),.9,2.,3),u=a7(c,d(73,7)),t=(.75+b*b)*(.8+.4*em(c.x*93.)),r;k e=k(.25*t);b5.y+=b5.y*2.-.01-.03*u;r=av(b5-=clamp(b5,d(.49,.5),d(.51,3)));e*=1.-.7*b*ai(j(.07,.03,ae(r-.5)))+.5*b*i(.35,.1,r)*ai(j(.2,.1,q.y))-.3*ai(j(.8,1.,q.y))-.3*(j(.3,.1,q.y))*j(.4,.6,r)+.2*ai(j(.5,.1,q.y))*j(.45,.4,r);l e;}an(_70){h b=ah(c,d(5),.9,3.,4),a5=aj(c.y*10.);k e=o(n(53,48,42),n(38,38,36),b)*(.6+b*.8);e*=1.+.5*ai(i(.25,.25,a5))+.5*ai(i(.65,.35,a5))-.6*ai(i(.5,.5,a5));l e;}an(_69){h b=ah(c,d(7,3),.9,3.,4),a5=c.y+b*.04;k e=o(n(50,40,34),n(93,92,88),b*b);e*=1.+.9*j(.07,.04,ae(c.y-.44))-.4*j(.08,.05,ae(c.y-.7))-.5*i(.34,.05,c.y)-.3*i(.7,.04,c.y)+.7*i(.01,.03,c.y)+1.5*i(.89,.1,a5)+1.3*i(.5,.04,a5)+.9*i(.18,.04,a5);l e;}an(_71){h b=ah(c,d(5,3),.9,3.,4);k e=o(n(74,66,55),n(99,90,78),b*b);c.x*=2.;d p=cm(c,d(.5,.625),d(1.5,.625));h f=av(p-c),v=j(.22,.20,f),ad=1.-.15*v-.5*j(.7,.9,c.y)*v-.3*(db(f).y-.5)*i(.2,.03,f)-.3*ai(i(.17,.03,f))-.5*j(.05,0.,c.y)-.3*i(.33,.05,c.y)+.7*j(.93,1.,c.y)+.7*i(.31,.04,c.y);l e*ad;}bi(_72){h b=ah(c,d(1,5),.4,3.,4);k e=o(n(56,49,43),n(142,136,136),b);c=.5-ae(c-.5);c.y*=4.;h a=i(.0,.1,av(c-cm(c,d(.41,.5),d(.42,3.5)))),f=c8(c),ad=1.-.7*a4(0.,1.-f/.15);ad*=1.-.8*j(.24,.31,a3(f,c.y-.1));e+=n(80,80,20)*a;l af(e*o(ad,2.7,a),a);}bi(_75){h b=ah(c,d(1,5),.4,3.,4);k e=o(n(56,49,43),n(142,136,136),b);c=.5-ae(c-.5);c.y*=8.;h f=av(c-cm(c,d(.27,.3),d(.27,7.7))),a=i(.0,.17,f),ad=1.-.5*i(.17,.07,f);e+=n(80,80,20)*a;l af(e*o(ad,2.7,a),a);}bi(_73){d p=ae(c-.5);h b=ah(c,d(1),.4,3.,4),r=av(p),a=j(.37,.33,r)*(.5+2.*b),ad=1.+.0*j(.08,.03,ae(r-.41));k e=o(n(56,49,43),n(142,136,136),b);ad=o(ad,7.,j(.44,.1*b,r));ad*=1.-.5*ai(i(.46,.04,r));ad*=1.-.4*ai(i(.36,.04,r));l af(e*ad,a);}bi(_74){h b=ah(c,d(5),.9,3.,4),f=dg(d4(c-=.5,.35),ae(a9(c,.4)),.02),a=pow(ak(f-.02,.15),8.),bf=a3(a4(a1(c,d(.46)),-a9(c,.51)),ae(a9(c,.44)));k e=n(76,62,47)*(.8+.8*b*b);e*=1.+(b+.5)*ak(ae(bf)-.01,.01);e*=1.-j(.1,.05,f)*ak(a9(c,.4));l af(e+1.*k(1,1,.3)*a,a);}bi(_1){c-=d(.48,.5);h f=cr(c,0.),b=av(c)-.47;k e=1.-k(.5,1,1)*ak(a4(.007-f,b+.04));l af(e,1)*ak(b);}an(_2){c-=.5;d r=d(dFdx(c.x),dFdy(c.y));c/=r/cd(r);c*=.8;c.y-=.03;h x=ae(c.x),b=ah(c,d(31,5),.7,2.,3),t=.8+.8*b*b,f=cr(c,1.),am=cr(c+d(0,.002),1.),ad=(am-f)*5e2+.5;k e=k(.3*t,0,0)*ak(f,.004);e*=1.-ai(j(.0,.3,x))-.5*j(.1,.3,ae(c.y-.1));e+=+t*.2*i(.0,.01-.01*x,f)*i(.1,.2,c.y)*j(.3,.2,x)*ad+t*.5*j(.004,.0,f)*j(.07,.1,c.y)*i(.23,.1,x)*k(.9,.9,1)+t*.4*i(.005,.005,f)*j(.2,-.1,c.y)*j(.3,.2,x)*bd(-ad);l e;}au _3(){d c=UV-.5;d r=d(dFdx(c.x),dFdy(c.y));c/=r/cd(r);c/=a2.yz;h u=a7(c,d(7))*.8+.6,f=a9(c,.48),v=ak(f,.005),m=ak(cq(c,d(.42,.47)),.03);k e=n(144,88,66)*u;v*=1.-m*.5;e*=1.-m;e*=1.-2.*bu(i(.0,.45,c.y))+4.*(c.y+.5)+.5*i(.0,.01,f)*c.x;al=af(e*v,v);}h ed(d c,h s,h m,h fe){m=(c.y-ai(ae(c.x-.5))*fe)*s-m;l 2.*i(.5,.4,m)*(aj(m)-.5);}bi(_84){h b=ah(c,d(5,9),.9,3.,4),t=.8+.8*b*b,u=ah(c,d(5,9),.9,3.,2),x=ae(c.x-.5),f;k e=n(77,60,44)*t;d p=c*d(1,2)-d(.5,.7);e*=1.-.55*ak(b0(a9(p,.3),cr(bh(45.)*p*.8,0.)-.01));e*=1.+ai(j(.6,.9,b))+i(.2,.5,c.y)*i(.2,.3,x)*ed(c,4.,.2,4.);for(h a8=6.;a8<9.;++a8)e*=1.+i(.8,.5,c.y)*i(.2,.3,x)*ed(c,12.,a8,1.);f=c.y-.81-ai(bd(x*4.))*.09;e=o(e,n(82,66,60)*t,j(.0,.01,f));e*=1.-.5*(i(.01,.02,f))+.5*(i(.02,.01,f));f=.15*(1.-c.y);f=a1(c-.5,d(.49)-f)+u*.1*bu(1.-c.y)-f;l af(e*ai(ak(f+.01,.05)),ak(f));}bi(_85){af e=a6(c);if(e.w<.5)discard;e.a0*=ai(bo()*.5);l e;}af cg(k p,k u,h s){p*=s/h(textureSize(Texture0,0).x);u*=u;af e=af(0);for(be m=0;m<3;++m,p=p.yzx)e+=a6(p.yz)*u[m];l e/cl(u);}af cg(k p,h s){l cg(p,Nor,s);}af cg(h s){l cg(Pos,s);}au _86(){h u=cf(Nor).z;al=cg(4.)*1.5*(.5*u*u*u*u*sign(u)+Clr);}au _87(){_86();}au _104(){al=cg(16.);al.a0+=pow(bd(cf(Nor).z),o(2.,8.,al.y))*ai(al.a0);al.a0*=e3()*k(1,.95,.9);}au _105(){al=af((cb(Ref,15.)*1.4+.3)*a2.yzw,1);}au _106(){k r=Ref;h s=17.;if(a2.y<1.){s=9.;mat2 a=bh(a2.x*90.);r.xy*=a;r.yz*=a;}s=cb(r,s);al=af(ai(j(.1,.9,s))*1.5*aj(a2.yzw)+.5*ai(j(.9,1.,s)),0);}au _107(){k r=Ref;r.xz*=bh(a2.x*9.);al=af(cb(r));}au _108(){d c=d(Pos.x/24.-.5,av(Pos.yz));al=a7(c,d(3))*j(1.,.9,c.x)*af(.25,0,0,0);}h ff(h b,h a,h a8,h p){l(ae(aj(a2.x*a8+p-.25)-.5)*4.-1.)*a+b;}au _109(){k r=Ref;mat2 a=bh(a2.x*90.);r.xy*=a;r.yz*=a;al=cb(r,22.)*bd(ff(-.3,1.3,.3,0.))*af(.3,.55,.25,0);}an(_110){h b=ah(c,d(7),.5,2.,4),t=.8+.8*b*b,u=a7(c,d(2));l o(n(5,77,55),n(8,122,188),j(.5,.1,u))*ai(1.-u)*t*2.*(1.+i(.2,.05,b*b));}au _111(){k p=Pos-k(4.5,0,2),r=Ref,u=Nor;r.xz*=bh(a2.x*9.);p.xy*=bh(a2.x*33.);u.xy*=bh(a2.x*33.);al=cg(p-a2.x*16.,u,16.)+cb(r);}au _112(){k u=cf(Nor),p=Pos;p.z-=24.;h am=i((ah(Pos.y/48.+a2.x*7.4,13.,.6,2.,4)-.5)*.15,.03,aj(j(-8.,32.,Pos.z)-a2.x*1.3)-.5);al=af((cg(16.).a0*(u.z*.5+.5)*(.2+.8*j(4.5,6.5,av(p)))+am*am)*a2.yzw*2.,1);}h ee(h e,h s,h x){h a=a4(fwidth(x)*2./s,1.);l i(e,s*a,x)/a;}au _88(){_86();k p=Pos,q;p.y=ae(p.y);q=p-k(7,3.5,-21);q.z*=1.3;h r=av(q);al.a0*=1.+bd(p.z+30.)*j(4.,5.,av(p.xy))+.5*bd(p.z+15.)+.3*i(3.,.5,r)+.7*ee(-15.,.5,p.z)-ee(-14.5,.5,p.z)-j(3.,2.5,r)*(.6+.4*q.z/r);q=p-k(8,0,-23);q.z*=.7;r=av(q);al.a0*=1.-j(2.,1.,r)*(.6+.4*q.z/r);}h ef(d c){c*=d(256,64);h f=a9(c-d(81,30),11.);f=a4(f,c.x-80.);f=a4(f,-a9(c-d(84,26),9.));f=a3(f,a1(c-d(73,37),d(4,9))-4.);f=a4(f,-a1(c-d(73,37),d(0,7))+1.);f=a3(f,a1(c-d(91.5,47),d(4,19))-4.);f=a4(f,-a1(c-d(91.5,47),d(0,17.5))+1.);f=a3(f,a1(da(c,111.)-d(105.+j(23.,50.,c.y)*3.,43),d(3.5,19)));f=a3(f,a1(c-d(111,32),d(6,3)));f=a3(f,a1(c-d(126,37),d(3,13)));f=a3(f,a1(c-d(125.5+j(23.,50.,c.y)*10.,44),d(3.5,6)));f=a3(f,a1(c-d(136.5-j(23.,50.,c.y)*9.,32),d(3.5,8)));f=a3(f,a1(c-d(148.5,37),d(7,13)));f=a4(f,-a1(c-d(155,33),d(6,3)));f=a4(f,-a1(c-d(155,43),d(6,2)));f=a3(f,a1(c-d(168,37),d(3.5,13)));f=a3(f,a1(c-d(178.,37),d(3.5,13)));f=a3(f,a1(c-d(188,37),d(3.5,13)));l a4(f,c.y-50.);}bi(_89){l af(ak(ef(c),.8),0,0,bk(c*511.));}au _90(){k e=a6(UV*2.).a0*step(.5,aj(a2.x*.5));e=o(e*bo(),k(.5,0,0),i(aj(a2.x*2.),1./64.,aj(UV.y)));al=af(e+cb(Ref)*.25+a6(UV+bk(a2.xx)).w*.1,1);}an(_91){h f=ef(c);l k(db(f)*bh(90.)*.5+.5,1.-1.4*ae(f));}bi(_92){c-=.5;d r=d(dFdx(c.x),dFdy(c.y));c/=r/cd(r);c*=.5;c.y=(c.y-.16)*7.;if(cd(ae(c-d(0,.15))/d(.77,1))>.4)l af(0);h u=bk(c*133.7+a2.x),ao=1./48.,s=pow(1.2,ao),ad=0.,m;c/=o(1.,s,u);for(m=u*ao;m<1.;m+=ao){c.x+=(c0(a2.x*.37)-.5)*ao/48.;c.y+=(c0(a2.x*.21)-.5)*ao/32.;r=c/=s;r.y-=m*.15;r.x*=1.+r.y*.15;af e=a6(r+.5);d g=e.xy*2.;r=sign(--g)*r*d(133,33)+a2.x*4.;g*=g;ad+=e.z*(1.-m)*ao*((c0(r.x)*g.x+c0(r.y)*g.y)/cl(g)*.7+.3);}l ad*af(32,16,4,0);}au _93(){d c=aj(UV);c.x+=a2.x/13.;h b=ah(c,d(3,7),.9,2.,4),a8=c.y;al=af(2.*n(95,85,80)*a8*a8*a8*a8*o(1.,b,.5),0.);}au _94(){al=af(cb(Ref)*n(133,111,111),0);}h star(d p,d e,h s){p-=e;h a=j(.3,.5,ae(aj(ch(p/=s)*8.+bk(e))-.5));l j(.9,.6,pow(cx(p),.0625)-a*a*.006);}au _95(){al=af(2,2,2,0)*pow(star(UV,d(.5),1.),2.);}h eg(d c,h s){d p=c;p.y+=p.y-a2.x*s;c.x+=(c0(p.y*5.)-.5)*1.5*ai(c.y);h u=ah(bc(p,7.,.02),d(9),.7,2.,4),a5=j(.9,.03,c.y),b=a1(c-d(.5,.15),d(0,.3));l ai(ak(b+u*ai(1.2-a5)-.13,.15));}au eh(h s){d c=aj(UV);al=(eg(c,s*.6)+eg(c,s))*af(2.5,1,.35,0);}au _96(){eh(2.5);}au _97(){eh(1.);}au _0(){h ad=dot(Nor,cf(k(2,0,8)));ad=ad*.4+.7;d c=e0(Pos,e1(Nor));k e=k(.5);e*=e2(k(aj(cp*a2.w+.25),1.,1.));al=af(e*ad,1);}au _7(){af e=a6(UV);al=af(e.a0*o(bo(),k(1),e.w),1);}au _77(){af e=a6(UV);h r=av(aj(UV)-.5);h s=o(.4,8.,aj(a2.x*1.5));al=af(e.a0*bo()+n(240,130,5)*i(.1,.05,r/s)*j(.37,.32,r),1);}au _6(){k e=a6(UV).a0;al=af(e*bo(),1);}au _8(){af e=a6(UV);e.a0*=1.+e.w*cb(Ref);al=af(e.a0*bo(),1);}au _80(){al=af(0);}au _81(){k f=cf(Pos-Cam.a0);f.z=f.z*4.+2.;d c=cf(f).xy*2.;h b=j(.2,1.,ah(c-a2.x*d(.1,.2),d(5),.5,2.,6));c.y*=1.5;h s=j(.3,1.,ah(c-a2.x*d("
".1,.18),d(5),.6,2.,6));al=af(k(b,0,0)+n(80,30,8)*s*s*2.,1);}au _82(){d c=bc(UV/8.,a2.x*.5,2.,.05);h b=ah(c,d(7),.9,2.,4);k e=n(91,22,14)*(.2+1.6*b);e=o(e,n(144,44,0),i(.6,.2,ah(c,d(3),.7,3.,4)));e=o(e,n(244,144,66)*b*2.,ai(i(.55,.25,ah(c,d(11),.5,2.,4))));al=af(e*bd(cd(bo())),1);}au _83(){_82();}au _4(){al=texture(Texture0,(.5+UV*127.)/128.,2.5);al.a0*=.7+.3*a7(UV,.5/fwidth(UV));}au _5(){al=a6(UV)*Clr;}bi(_98){c.y*=2.;h b=ah(c,d(5),.9,2.,4),ao=.5+b,t=.8+b*.4,f=c.y-1.05;k e=n(55,44,37)*t;d p=c;f=dg(f,a1((c-d(.5,1.5))*bh(45.),d(.2))-.1,.3);f=a4(f,.03-p.y);e=o(e,cn(e,c-d(.5,1.5),.1),8.*b);p.x=a3(p.x,1.-p.x);if(p.y>.5)p.y-=.5;e=o(e,cn(e,p-d(.22,.31),.04),2.*t);e*=1.+ai(j(.5,1.,b))+db(f).y*i(.0,.05,f)*(1.+11.*j(1.5,2.,c.y))*b+ao*i(.93,.05,c.y)+ao*i(.4,.05,c.y)+ao*i(.1,.05,c.y)-.5*i(.97,.05,c.y)-.5*ai(i(.7,.05,c.y))-.5*ai(i(.2,.05,c.y))-.5*i(.66,.1,c.y)-.5*i(.45,.03,c.y)-.5*i(.15,.1,c.y)-i(.01,.03,c.y);l af(e,ak(f,.03));}au _99(){al=a6(UV);if(al.w<0.5)discard;al*=Clr*1.5+.3;}au _100(){d c=d(ch(Pos.xy),j(8.,128.,Pos.z));c.x=aj(c.x*3.-a2.x*2.2);c.y*=4.;h a8=star(c,d(0,.3),1.)+star(c,d(1,.3),1.)+star(c,d(.5,.4),1.5);a8*=a8;al=af(a8,a8,a8,0);}bi(_101){h b=ah(bc(c,5.,.03),d(7),.5,3.,2);l(b*1.4+.3)*af(1.2,.54,.06,0)+.5*i(.7,.2,b)*af(1,1,1,0);}au _102(){k p=Pos;p-=a2.x*6.4*sign(p.z-72.);al=cg(p,8.);}an(_103){c=bc(c,5.,.02);h b=ah(c,d(6),.8,2.,4),v=ah(c,d(2),.6,2.,4),t=.8+.6*b*b;k e=o(n(36,33,30),n(168,177,168),.3+.7*v)*t;e*=1.+.2*j(.4,.6,v)-.2*i(.3,.1,v);l e;}au _113(){d c=c9(UV-.5,4.);al=af(1,1,0,1)*ak(a3(cz(av(c)-.4,.04),a1(c,d(.25,.06))),.01);}au _114(){al=af(.4,.7,.3,1)*ak(dot(ae(UV-.5),d(4,3)/5.)-.2,.01);}au _115(){d c=UV-.5;c.x=ae(c.x);h w=.15*bu(j(-.32,-.29,c.y))+.05*j(-.3,-.12,c.y)+.1*bu(j(-.12,.07,c.y))+.14*step(.07,c.y)-.1*ai(j(.07,.31,c.y)),f=b0(a1(c,d(w,.3)),a9(c-d(0,.777),.5));al=af(1,1,0,1)*ak(f-.01,.01);}au _116(){d c=UV;h f=a1(c-d(.35,.5),d(.1,.4));c.y=mod(c.y-.06,.28)-.16;f=a3(f,a1(c-d(.51,0),d(.34,.04*j(.85,.7,c.x))));f=b0(f,a1(c-d(.65,0),d(.02,1)));al=af(1,1,0,1)*ak(f,.01);}au _117(){d c=UV;c.x=mod(c.x,.33)-.16;h f=a1(c-d(0,.52),d(.1,.4));f=b0(f,a1(c-d(0,.65),d(.05,.23)));f=b0(f,ae(c.y-.2)-.02);al=af(1,.5,0,1)*ak(f,.01);}au _118(){d c=(UV-d(.55,.45))*bh(-45.);h f=cm(c,d(-.4,0),d(.2,0),.1);f=a4(f,-.3-c.x);c.y=ae(c.y);f=a3(f,a1(c+d(.37,0),d(.05,.005)));f=a3(f,a1(c+d(c.y+.1,-.18),d(.1,.05)));al=af(1,0,0,1)*ak(f,.01);}au _119(){d c=(UV-.5)*bh(45.);h f=a1(c,d(.6,.03)),p=c.x*12.6+1.55,a5=sin(p)*.15,q=b6(aj(a5));f=a3(f,a4(cz(c.y-a5,.05-.1*q)*(1.+q+q),ae(c.x)-.6));al=af(0,1,0,1)*ak(f,.01);}au _120(){d c=c9(UV-.5,5.);h f=av(c)-.18,r=c.x-.33,a5=.04*i(.0,.3,r);c.x-=.33;c*=bh(-15.);f=a3(f,a1(c,d(.04,2.*a5)));f=a3(f,a1(c-d(0,a5*sign(r)),d(.14,a5)));al=af(.77,0,1,1)*ak(f+.01,.01);}au _121(){d c=UV-.5;h f=cr(c+d(0,.05),0.)-.01;f=a3(f,a1(c9(c*bh(45.),4.)-d(.45,.0),d(.11,.02)));al=af(0,.88,.95,1)*ak(f,.01);}"
;

// src/demo/data/shaders/vertex_shaders.glsl: 4963 => 2417 (48.7%)
static constexpr char g_vertex_shaders[] =
"#define c void\n"
"#define f vec4\n"
"#define j gl_Position\n"
"#define l location\n"
"#define n normalize\n"
"uniform mat4 MVP,View,World;uniform f Time,Cam;layout(l=0)in f e;layout(l=1)in f k;layout(l=2)in vec3 h;layout(l=3)in f o;out vec3 Pos,Nor,WNor,Ref;out vec2 UV,LUV;out f Clr;c d(){j=e;UV=e.xy*.5+.5;}c m(float v,float ac,float ad){j+=ac*MVP*f(h,0)*sin(6.28*(Time.x*ad+dot(e.xyz/v,vec3(1))));}c _0(){j=MVP*e;Pos=e.xyz;Nor=h;UV=k.xy;LUV=k.zw;Clr=o;Ref=n(reflect((e-Cam).xyz,h));}c i(){_0();Pos=floor(h)/4.;Nor=fract(h)*4.-2.;Ref=n(reflect((e-Cam).xyz,Nor));float a=k.z,u=cos(a),s=sin(a);Nor.xy*=mat2(u,s,-s,u);}c _1(){d();}c _2(){d();}c _3(){d();}c _4(){d();}c _5(){j=f(e.xy,1,1);UV=k.xy;Clr=o;Clr.xyz*=Clr.w;}c _6(){_0();}c _7(){_0();}c _8(){_0();}c _9(){d();}c _10(){d();}c _11(){d();}c _12(){d();}c _13(){_0();}c _14(){d();}c _15(){_0();}c _16(){d();}c _17(){d();}c _18(){d();}c _19(){_0();}c _20(){d();}c _21(){d();}c _22(){d();}c _23(){d();}c _24(){d();}c _25(){d();}c _26(){_0();}c _27(){d();}c _28(){d();}c _29(){d();}c _30(){d();}c _31(){_0();}c _32(){d();}c _33(){_0();}c _34(){d();}c _35(){d();}c _36(){d();}c _37(){d();}c _38(){d();}c _39(){d();}c _40(){d();}c _41(){d();}c _42(){d();}c _43(){d();}c _44(){d();}c _45(){d();}c _46(){d();}c _47(){d();}c _48(){d();}c _49(){d();}c _50(){d();}c _51(){d();}c _52(){d();}c _53(){d();}c _54(){d();}c _55(){d();}c _56(){d();}c _57(){_0();}c _58(){d();}c _59(){_0();}c _60(){d();}c _61(){d();}c _62(){d();}c _63(){d();}c _64(){d();}c _65(){d();}c _66(){d();}c _67(){d();}c _68(){d();}c _69(){d();}c _70(){d();}c _71(){d();}c _72(){d();}c _73(){d();}c _74(){d();}c _75(){d();}c _76(){d();}c _77(){_0();}c _78(){d();}c _79(){_0();}c _80(){_0();}c _81(){_0();}c _82(){_0();m(100.,3.,.1);}c _83(){_0();}c _84(){d();}c _85(){_0();m(30.,3.,.2);m(100.,3.,.7);}c _86(){i();}c _87(){i();}c _88(){i();}c _89(){d();}c _90(){_0();}c _91(){d();}c _92(){d();}c _93(){_0();}c _94(){i();}c _95(){_0();j+=MVP*f(Nor*mat3(View),0);}c _96(){_0();}c _97(){_0();}c _98(){d();}c _99(){_86();}c _100(){i();}c _101(){d();}c _102(){i();}c _103(){d();}c _104(){_0();WNor=n(mat3(World)*h);Ref=n(reflect((World*e-Cam).xyz,WNor));}c _105(){_104();}c _106(){_104();}c _107(){_104();}c _108(){_104();}c _109(){_104();j+=MVP*f(h+h,0);}c _110(){d();}c _111(){_104();}c _112(){_104();}c _113(){d();}c _114(){d();}c _115(){d();}c _116(){d();}c _117(){d();}c _118(){d();}c _119(){d();}c _120(){d();}c _121(){d();}"
;

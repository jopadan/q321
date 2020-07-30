#pragma once

// auto-generated, do not modify
static_assert(0xe6b55f00U == Demo::Shader::Version, "Shader definition mismatch, please recompile the shader compiler & shaders");

// src/demo/data/shaders/fragment_shaders.glsl: 84055 => 35697 (42.5%)
static constexpr char g_fragment_shaders[] =
"#define d vec2\n"
"#define h float\n"
"#define k vec3\n"
"#define l return\n"
"#define o mix\n"
"#define af abs\n"
"#define ah vec4\n"
"#define aj fract\n"
"#define ao void\n"
"#define au length\n"
"#define a1 min\n"
"#define a2 max\n"
"#define a3 Time\n"
"#define a7 xyz\n"
"#define bd int\n"
"#define bh Texture0\n"
"#define bi texture\n"
"#define bl floor\n"
"#define b0 sqrt\n"
"#define cf normalize\n"
"#define dk(x)((x)*(x)*(3.-2.*(x)))\n"
"#define ai(x)((x)*(x))\n"
"#define cw(x)dot(x,x)\n"
"#define bc(x)clamp(x,0.,1.)\n"
"#define n(r,g,b)(k(r,g,b)/255.)\n"
"#define b7(u)i(.5,.5,u)\n"
"#define am(b9)k b9(d);ao b9(){al=ah(b9(UV),1);}k b9(d c)\n"
"#define bj(b9)ah b9(d);ao b9(){al=b9(UV);}ah b9(d c)\n"
"#define c6(eh,c,ei){d p[3];h r[3];p[0]=c;p[1]=c+dFdx(c);p[2]=c+dFdy(c);for(bd m=0;m<3;++m)r[m]=ei;eh=k(ej(d(r[1],r[2])-r[0]),r[0]);}\n"
"#define dl(b9,ek)k b9(d p,d dm){p*=dm;d v=bl(p),a5=p-v,dn,g,be,r;h cx=8.,c7=cx,f;for(bd m=0;m<9;++m){g=d(m%3-1,m/3-1);be=dp(mod(v+g,dm));r=g+be-a5;f=ek;if(f<cx){c7=cx;cx=f;dn=r;}else if(f<c7){c7=f;}}l k(dn,c7-cx);}\n"
"uniform ah a3,Cam;uniform sampler2D bh,Texture1;in k Pos,Nor,WNor,Ref;in d UV,LUV;in ah Clr;out ah al;h cj=3.1415927,dq=2.*cj,cy=1.618034;d dr(h m){h de=1.324718;l aj(.5+m/d(de,de*de));}h ck(h m){l aj(.5+m*cy);}h el(h a5){h m=bl(a5);l o(ck(m),ck(m+1.),dk(a5-m));}h c8(d u){l a1(u.x,u.y);}h c8(k u){l a1(u.x,a1(u.y,u.z));}h c8(ah u){l a1(a1(u.x,u.y),a1(u.z,u.w));}h cl(d u){l a2(u.x,u.y);}h cl(k u){l a2(u.x,a2(u.y,u.z));}h cl(ah u){l a2(a2(u.x,u.y),a2(u.z,u.w));}h cp(d u){l u.x+u.y;}h cp(k u){l u.x+u.y+u.z;}h ds(h a,h b){l af(a)<af(b)?a:b;}h cz(h x,h s){l af(x)-s;}h df(h x,h s){l sign(x)*a2(0.,af(x)-s);}d ej(d u){h ad=dot(u,u);l ad>0.?u/b0(ad):u;}h i(h em,h en,h x){l 1.-bc(af(x-em)/en);}h j(h dt,h eo,h x){l bc((x-dt)/(eo-dt));}h i(h a,h b,h e,h x){l a1(j(a,b,x),j(e,b,x));}d bm(h x){l d(sin(x),cos(x));}mat2 bf(h x){d u=bm(radians(x));l mat2(u.y,u.x,-u.x,u.y);}h ch(d p){l aj(atan(p.y,p.x)/dq);}d c9(d p,h v){l p*bf(360./v*(bl(ch(p)*v+1.5)-1.));}d a8(d c,h p,h s){l c+sin(c.yx*cj*p)*s;}d a8(d c,h t,h p,h s){l c+sin(c.yx*cj*p+t)*s;}h da(h u,h ac){l ac-af(u-ac);}d da(d u,h ac){u.x=da(u.x,ac);l u;}h ep(h x,h p,h ad,h a4){l x-p*clamp(bl(x/p+.5),ad,a4);}d du(d c,d s){c.x+=bl(c.y*s.y)*(.5/s.x);l aj(c)*s;}k dv(d c,h r){l k(c-=clamp(c,r,1.-r),au(c)/r);}k dv(d c,d s,h r){s=s.yx/c8(s);c*=s;l k(c-=clamp(c,d(r),s-r),au(c)/r);}h bk(d p){k q=aj(p.xyx*.09153);q+=dot(q,q.yzx+19.19);l aj((q.x+q.y)*q.z);}h bk(h p){p=aj(p*.1031);p*=p+33.33;p*=p+p;l aj(p);}k ff(h p){k b2=aj(k(p)*k(.1031,.1030,.0973));b2+=dot(b2,b2.yzx+33.33);l aj((b2.xxy+b2.yzz)*b2.zyx);}d dp(d p){k b2=aj(k(p.xyx)*k(.1031,.1030,.0973));b2+=dot(b2,b2.yzx+33.33);l aj((b2.xx+b2.yz)*b2.zy);}ah eq(h p){ah b3=aj(ah(p)*ah(.1031,.1030,.0973,.1099));b3+=dot(b3,b3.wzxy+33.33);l aj((b3.xxyz+b3.yzzw)*b3.zywx);}ah eq(d p){ah b3=aj(ah(p.xyxy)*ah(.1031,.1030,.0973,.1099));b3+=dot(b3,b3.wzxy+33.33);l aj((b3.xxyz+b3.yzzw)*b3.zywx);}h bn(h x,h p){l bk(mod(x,p));}h er(h x){h m;l o(bk(m=bl(x)),bk(m+1.),dk(x-m));}h a6(h x,h p){h m;l o(bn(m=bl(x),p),bn(m+1.,p),x-m);}h bn(d p,d s){l bk(mod(p,s));}h a6(d p,d s){p*=s;d m=bl(p);p-=m;p*=p*(3.-2.*p);h es=bn(m+d(0,0),s);h et=bn(m+d(0,1),s);h eu=bn(m+d(1,1),s);h ev=bn(m+d(1,0),s);l o(o(es,ev,p.x),o(et,eu,p.x),p.y);}h ae(d p,d b4,h c0,h c1,bd c2){h ci=a6(p,b4),ca=1.,tw=1.;for(bd m=0;m<c2;++m){p=aj(p+cy);b4*=c1;ca*=c0;ci+=a6(p,b4)*ca;tw+=ca;}l ci/tw;}h ae(h p,h b4,h c0,h c1,bd c2){h ci=a6(p*b4,b4),ca=1.,tw=1.;for(bd m=0;m<c2;++m){p=aj(p+cy);b4*=c1;ca*=c0;ci+=a6(p*b4,b4)*ca;tw+=ca;}l ci/tw;}h dw(d p,d b4,h c0,h c1,bd c2){h ci=b7(a6(p,b4)),ca=1.,tw=1.;for(bd m=0;m<c2;++m){p=aj(p+cy);b4*=c1;ca*=c0;ci+=b7(a6(p,b4))*ca;tw+=ca;}l ci/tw;}d cm(d p,d a,d b){d ab=b-a,ap=p-a;h t=bc(dot(ap,ab)/dot(ab,ab));l ab*t+a;}h ew(d c,d f){l dot(c,bf(90.)*cf(f));}h av(d p,d b){d f=af(p)-b;l a1(a2(f.x,f.y),0.)+au(a2(f,0.));}h c3(d p,d b){l cl(af(p)-b);}h a9(d p,h r){l au(p)-r;}h cm(d p,d a,d b,h r){l a9(p-cm(p,a,b),r);}h c4(d p,d r){l a9(p/r,1.)/a1(r.x,r.y);}h b1(h a,h b){l a2(a,-b);}h dg(h a,h b,h a0){h a4=bc(.5+0.5*(b-a)/a0);l o(b,a,a4)-a0*a4*(1.-a4);}d dh(h x){d f=d(dFdx(x),dFdy(x));l f/a2(au(f),1e-8);}h ak(h s,h f){l bc(1.-s/f);}h ak(h s){l bc(1.-s/fwidth(s));}ah dx(d c,h s){l ah(c/=s,b0(bc(1.-cw(c))),au(c)-1.);}h ex(k v){h ad=cp(v.yz)*.7;l pow(bc(ad),4.)+ad;}h dy(d c,h s){c/=s;c.y+=.06;c.x*=2.;l j(.3,.0,au(c));}k cn(k e,d c,h s){ah b=dx(c,s);e*=1.+ex(b.a7)*ak(b.w)*.5;e*=1.-ai(dy(c,20.*s))*(1.-ak(b.w))*.3;l e;}h cq(d c,h t){c.x=af(c.x);c.y-=.07;h f=c4(c,d(.31,.12-t*.02))/50.;f=a2(f,-c4(c-d(0,.01+.01*t),d(.28+t*.01,.07))/75.);f=a2(f,-av(c-d(0,.1),d(.22-.02*t,.12)));f=a2(f,-av(c-d(0,.1),d(.084-.012*t,.31)));f=a1(f,c3(c-d(0,-.09),d(i(-.09,.32,c.y)*(.04-.015*t),.32)));f=a1(f,c3(c-d(.11-.02*t,-.21+.01*t),d(i(-.07,.3,c.y)*(.03-.01*t),.15)));l f;}h ey(d c){h f=a9(c-d(0,.17),.32);f=b1(f,a9(c-d(0,.235),.27));f=b1(f,a9(c-d(0,.5),.15));c.y-=.09;d s=d(.09,.52);h a4=bc(-c.y/s.y);s*=.5;s.x*=j(1.05,.6,a4)+ai(j(.1,.02,a4));c.y+=s.y;f=a1(f,av(c,s));l f;}k dz(d p,h bm,h ez){k an=k(-1,0,1),r=k(1e5);d b5=bl(p*bm),fg=an.yy;p-=(b5+.5)/bm;h bo=.5*bn(b5+an.yy,d(bm)),cr=.5*bn(b5+an.xy,d(bm)),cs=.5*bn(b5+an.yz,d(bm)),ct=.5*bn(b5+an.zy,d(bm)),cu=.5*bn(b5+an.yx,d(bm)),d0=.5*bn(b5+an.xz,d(bm)),d1=.5*bn(b5+an.zz,d(bm)),d2=.5*bn(b5+an.zx,d(bm)),d3=.5*bn(b5+an.xx,d(bm));d[4]cb,ad;if(mod(b5.x+b5.y,2.)<.5){ad[0]=1.+d(cu-cr,bo-d3);ad[1]=1.+d(ct-cu,bo-d2);ad[2]=1.+d(cs-cr,d0-bo);ad[3]=1.+d(ct-cs,d1-bo);cb[0]=d(cu,bo);cb[1]=d(cu,bo);cb[2]=d(cs,bo);cb[3]=d(cs,bo);}else{ad[0]=1.+d(bo-d3,cr-cu);ad[1]=1.+d(d2-bo,ct-cu);ad[2]=1.+d(bo-d0,cs-cr);ad[3]=1.+d(d1-bo,cs-ct);cb[0]=d(bo,cr);cb[1]=d(bo,ct);cb[2]=d(bo,cr);cb[3]=d(bo,ct);}for(bd m=0;m<4;m++){cb[m]+=ad[m]*(d(m&1,m/2)-.5);ad[m]/=bm;h bx=c3(p-cb[m]/bm,ad[m]/2.-ez/bm);if(bx<r.x)r=k(bx,b5+cb[m]);}l r;}dl(db,cp(af(r)))dl(dc,au(r))h cc(k p,h s){p=cf(p);k a=aj(degrees(atan(p,p.yzx))/360.);l a6(a.x*s,s)*j(.9,.0,af(p.z))+a6(a.y*s,s)*j(.7,.0,af(p.x));}h cc(k p){l cc(p,45);}d e0(k p,bd ax){l(ax==0)?p.yz:(ax==1)?p.xz:p.xy;}bd e1(k v){v=af(v)+k(.01,.02,.03);h ac=cl(v);l(ac==v.x)?0:(ac==v.y)?1:2;}k e2(k e){k rgb=bc(af(mod(e.x*6.+k(0,4,2),6.)-3.)-1.);rgb*=rgb*(3.-2.*rgb);l e.z*o(k(1.),rgb,e.y);}k bu(){k f=Cam.a7-Pos;h b=ae(f.xy/256.*bf(Cam.w),d(3),.7,3.,4),ad=1.-j(14.,-6.,au(f.xy)-b*8.)*j(128.,48.,f.z)*step(.1,Nor.z);l bi(Texture1,LUV).a7*2.*ad;}am(_8){h b=ae(c,d(5),.9,3.,4);k e=o(n(48,41,33),n(103,101,104),b);l e;}am(_9){h b=ae(c,d(3),.9,3.,4);k e=o(n(49,45,43),n(81,75,78),b*b);l e;}am(_10){h b=ae(c,d(7),.9,3.,4);c.x*=-1.5;c.y+=c.x*.5;c.x=1.-c.x+c.y;c=aj(c*28.);h a5=bc(1.-au(.1-c));a5*=j(.6,.2,au(.6-c));a5*=j(.6,.8,au(.1-c));a5*=j(.2,.6,b)*2.+1.;h ad=1.-j(.2,b+2.,cl(af(c-.5)));l k((a5+1.)*o(.21,.29,b*b)*ad);}bj(_11){k e=_10(c);h b=ae(c=a8(c,7.,.01),d(5),.7,3.,4),v=ae(c,d(7),.5,2.,4),r=au(c-=.5),a=ch(c),f=r+v*.8-.33;e=o(e,o(n(21,17,14),n(70,59,51),b),j(.5,.2,r+b*b*b));e*=j(.1,.11,f)+2.*pow(i(.4,.12,.1,f),8.);l ah(e,1.-b0(j(.11,.06,f)));}ao _12(){h b=ae(UV*.5+a3.x*d(9,5),d(7),.6,2.,4);b*=1.+.5*i(.5,.05,b);ah e=bi(bh,UV);al=ah(o(n(66,111,155)*(.8+2.*b*b),e.a7*bu(),e.w),1);}h d4(d c,h s){h f=1e6,m=0.;for(;m<5.;++m){d p=d(0,-s)*bf(m*72.);f=a1(f,au(c-cm(c,p,p*bf(144.))));}l f;}am(_75){h b=ae(c,d(7),.9,3.,4);k e=_10(c);h r=au(c-.5);h ac=j(.46,.45,r);h ad=1.5-1.5*j(.0,.3,r*r);ad=o(ad,2.5,i(.42,.07,r));ad=o(ad,3.5,i(.44,.05,r));ad=o(ad,2.6,i(.36,.03,r));h v=.3+.2*j(.35,.30,r);ad*=1.-v*j(.3,.7,b);ad*=1.-.3*ai(j(.13,.05,r));ad=o(ad,2.5,j(.04,.01,r));ad-=ad*i(.03,.01,r)*.7;e=o(e,n(68,66,54)*ad,ac);e*=1.-ai(i(.34,.02,r));e*=1.-ai(i(.46,.03,r));e*=1.-i(.41,.03,r)*.7;l e;}bj(_13){k e=_75(c);c=aj(c)-.5;h b=ae(c,d(3),.9,3.,4),f=a1(af(au(c)-.4),d4(c,.35));l ah(e,ak(f-.02+b*.02,.01));}ao _14(){ah e=bi(bh,UV);al=ah(e.a7*bu()+n(111,55,0)*e.w*(sin(a3.x*cj)*.5+.5),1);}d e3(d c,h s){l d(1.-au(c)/s,ak(au(c)-s));}bj(_77){h b=ae(c,d(5),.9,3.,4),t,be,a0,r;k e=_10(c);d b6,u;b6.x=af(c.x-.5);b6.y=a1(c.y,.4);r=au(b6-d(0,.4))-(.18-.06*j(.4,1.,c.y));a0=.25-.15*j(.9,.96,c.y)+.03*ai(j(.82,.86,c.y))+.07*j(.8,.2,c.y)+.07*ai(j(.35,.22,c.y))-.07*j(.22,.0,c.y);be=av(c-d(.5,.5),d(a0,.46));be=a2(be,-av(b6,d(.15,.03))+.06);e=o(e,k(.6,.55,.55)-c.y*.3+b*.2,ak(be));e*=1.-.7*i(.0,.013,be);e*=1.-(r/.5-.1)*ak(be);t=a2(r,c.y-.96);be=af(t-.02)-.03;be=a2(be,c.y-1.+b6.x*.5);be=a2(be,c.y-.96);e=o(e,k(1,1,.9)-c.y*.55,i(-.01,.01,be));e=o(e,k(.2*b+.1),ak(t,.01));e*=1.-.2*i(.0,.05,t)*ak(be);u=e3(b6=c-d(.5,.4),.02);e*=1.+n(111,80,70)*i(.03,.01,au(b6));e*=1.-.5*i(.02,.01,au(b6));e=o(e,n(111,66,44)*(u.x*1.5+.2),u.y);l ah(e,ak(t-.03,.02));}ao _78(){ah e=bi(bh,UV);d c=aj(UV);c.x=af(.5-c.x);h t=aj(-a3.x),r=au(c-d(0,.4)),ad=t*pow(a2(0.,1.-r),4.)*e.w;if(t>.75)ad+=j(.03,.01,af(aj(c.y+c.x*.5+t*2.)-.45))*j(.1,.08,c.x);al=ah(e.a7*bu()+n(180,150,5)*ad,1);}am(_15){h b=ae(c,d(5),.9,3.,4);k e=o(n(44,14,16),n(93,63,63),b*b);l e;}k d5(d c){h an=3e-3,a=0.;d g=d(6),r=db(c,g).xy;for(bd m=0;m<9;++m)a+=cp(af(db(d(m%3-1,m/3-1)*an+c,g).xy-r));l k(c+r.xy/g,a);}am(_16){h b=ae(c,d(3),.9,3.,4);k e=o(n(80,70,72),n(128,120,120),b*b);k u=d5(c);e*=o(.95,1.1,a6(u.xy,d(6)));e=o(e,n(168,128,120),j(.5,1.,u.z)*b*.7);l e;}bj(_17){h b=ae(c,d(3),.9,3.,4);k e=o(n(80,70,72),n(128,120,120),b*b);k u=d5(c);h ac=j(.5,1.,u.z);h r=j(.4,.2,au(.5-aj(u.xy)));e*=o(.95,1.1,a6(u.xy,d(6)))-2.*r*b*b;e=o(e,n(168,12"
"8,120),ac*b*.7);l ah(e,ac*r);}ao _18(){ah e=bi(bh,UV);al=ah(e.a7*bu()+i(.5,.125,aj(UV.y*.5+a3.x*.5))*e.w*.3,1);}am(_19){h b=ae(c,d(5),.9,3.,4);k pt=dz(c,8.,.31);k e=o(n(66,58,55),n(118,107,105),b);h ad=1.-.5*j(.034,.036,pt.x);ad=o(ad,1.4,i(.033,.004,pt.x));l e*ad;}h e4(d c){h b=a6(c,d(64)),a5=0.,f=1e6;for(;a5<11.;++a5)f=dg(f,af(au(.5-af(c-dr(a5)))-o(.36,.29,ck(a5+.7)))-o(.015,.03,b),.01);l f*1e2;}k d6(d c){k s,p;for(bd m=0;m<3;++m){p=k(c,0);p[m]+=1e-4;s[m]=e4(p.xy);}l k(cf(s.xy-s.z),s.z);}am(_20){h b=ae(c,d(5),.9,3.,4),ad;k e=o(n(51,46,43),n(165,147,143),b*b),f=d6(c);ad=1.-.5*(f.y-f.x)*i(.5,3.,f.z)*j(1.,.0,f.z);l e*ad*.8;}am(_21){h b=ae(c,d(3),1.1,3.,4),ad;k e=o(n(51,46,43),n(165,147,143),b*b),f=d6(c);ad=1.-.5*(f.y-f.x)*i(.5,3.,f.z)*j(1.,.0,f.z);l e*ad;}am(_22){h b=ae(c,d(5),.9,3.,4),ad=.18*(.7+b*b);k g;c=a8(c,13.,.007);c6(g,c,ai(j(.3+b*.2,.9,ae(p[m],d(23),.5,2.,4))));l k(ad*(1.-g.y*g.z));}am(_47){h b=ae(c,d(5),.9,3.,4);k e=o(n(77,55,53),n(62,48,48),a6(c,d(128,13)))*(.7+b*b),g;c=a8(c,13.,.007);c6(g,c,ai(j(.4+b*.4,.95,a6(p[m],d(63,43)))));e*=j(1.3,.9,g.z);l k(e*(1.+g.y*g.z));}h d7(d c,d s){c.y=a2(c.y,0.);l c4(c,s);}k dd(k e,k b,d c,h a4,h s){h y=(c.y-a4)/s,p=1.-y*y;e*=1.-i(-1.,1.,y);if(p>0.)e=b*(p*(.8+.2*i(.5,.25,aj(c.x/s))))*(.7+ai(i(.2,.7,y)));l e;}k e5(d c,h v){l k(v*v*.4);}am(_48){c.x*=.5;h b=ae(c*d(2,1),d(3,5),.9,3.,4),v=.75+b*b,t=c.y+.2*a1(.4,i(.5,.33,aj(c.x*4.))),e6=d7(c-d(.25,.62),d(3,2)/32.),c5=d7(c-d(.25,.55),d(3,2)/48.),r;k e=o(n(66,50,51),n(111,66,44),b0(i(.31,.01,c.y))),bv;d p=c,q;p.x=aj(p.x*4.);if(c.y>.3)e=cn(e,d(4.*af(p.x-.5)-1.6,aj(c.y*16.)-.5),.07);r=af(p.x-.5);e*=1.-.3*j(.31,.32,c.y)*j(.87,.86,c.y)*(j(.035,.03,.5-r)+i(.48,.01,r)-i(.46,.02,r));e=o(e*v,e5(c,b),a2(j(.31,.3,c.y),ak(c5)));e*=j(1.5,.7,c.y);if(c.y<.306)e*=1.-i(.3,.05,c.y)*ak(-c5+10.,20.);e*=1.-i(.316,.004,c.y)*ak(-c5);if(c.y<.1)e*=.0;q=c;q.y+=i(.1,.01,mod(q.x,.33))/2e2;e=dd(e,2.*b*n(93,84,79),c,.185,.015);e=dd(e,2.*b*n(138,77,48),c,.13,.025);e=dd(e,2.*b*n(112,71,51),c,.09,.015);e=dd(e,2.*b*n(138,77,48),q,.05,.015);p.x=af(aj(c.x*6.-.5)-.5)/6.;e*=1.+.5*j(.04,.03,p.x)*i(.18,.03,p.y);r=c3(p-d(0,.12),d(.03,.01));r=b1(r,c3(p-d(0,.11),d(.01)));e*=1.-ai(i(.0,.04,r));e=o(e,n(166,99,77)*2.*b*(.75+.5*ai(i(.125,.01,c.y))),ak(r));q=p;q.y-=.07;r=a9(q,.03);e*=1.-ai(i(.0,.07,r));e=o(e,n(127,83,72)*b*2.*j(.01,-.005,r),j(.005,.0,r));q.y-=.004;r=a9(q,.015);e*=ai(j(-.01,.01,r));q.y+=.013;r=a9(q,.05);e+=n(67,38,30)*4.*b0(b)*ai(i(-.02,.015,r)*i(.023,.02,c.y));r=b1(e6,c5);r=b1(r,(c.y-.3)*3e2);e*=1.-.5*i(-2.,17.,c5)*j(.26,.3,c.y);bv=n(67,39,17)*v;bv=o(bv,k(v*.2),i(0.,4.,r)*b);bv*=1.-.4*pow(i(.0,3.,r),4.);bv+=(bv+.6)*b0(b)*ai(i(-6.,8.,r)*i(.66,.04,c.y))*ak(r);if(c.y<.56)bv=cn(bv,d(24.*af(c.x-.25)-1.85,aj(c.y*24.+.5)-.5),.15);e=o(e,_47(c),j(.85,.9,t)+step(c.y,1./256.));e*=1.+i(.88,.015,t)-ai(i(.87,.03,t));l o(e,bv,j(1.,.1,r));}k e7(k e,k a0,d c,bd w,bd a4){h b=ae(c,d(w,a4),.5,2.,2);e*=.9-.3*j(.15,.1,af(b-.5));l o(e,a0,i(.5,.1,b));}am(_53){c=a8(c,9.,.005);bd m=0,ad[]=bd[](13,43,17,47,23,59,27,63);h b=ae(c,d(19),.7,2.,4);k e=o(n(40,50,60),n(46,33,27),b)*(.5+b);for(;m<8;m+=2)e=e7(e,o(n(145,140,137),n(132,123,116),b),c,ad[m],ad[m+1]);l e;}k e8(k e,k a0,d c,bd w,bd a4){h b=ae(c,d(w,a4),.5,2.,2);e*=1.-.15*ai(j(.15,.1,af(b-.5)));l o(e,a0,i(.5,.1,b));}am(_64){h b=ae(c,d(13),.9,3.,4),v=ae(c,d(7),.9,3.,4);k e=o(n(111,66,55),n(80,55,52),ai(j(.8,.2,v)))*(.8+.8*b*b),a0=e;c=a8(c,13.,.01);bd m=0,ad[]=bd[](13,43,17,47,23,59,27,63);b=ae(c,d(19),.7,2.,4);for(;m<6;m+=2)e=e8(e,a0,c,ad[m],ad[m+1]);l e;}k e9(k e,k a0,d c,bd w,bd a4){h b=ae(c,d(w,a4),.5,2.,1);e*=.9-.3*ai(j(.15,.1,af(b-.5)));l o(e,a0,i(.5,.1,b));}am(_42){h b=ae(c,d(3,29),.9,2.,4),t=.8+.8*b*b,f=af(c.y-.61),be=j(.25,.24,f),ac;k e=n(140,127,127),a0=e;d p=c;e*=1.-.1*j(.85,.86,c.y);e=t*o(e,n(110,55,50),j(.33,.32,c.y));p.y+=p.x*.11+b*.007;p.y=aj(p.y*9.)-.5;ac=j(.0,.1,af(p.y)-.2);bd m=0,ad[]=bd[](3,29,5,37,9,63,27,63);for(;m<6;m+=2)e=o(e,e9(e,a0,c,ad[m],ad[m+1]),ac*be);e*=1.+t*be*(+.6*i(.1,.1,p.y)-.7*i(-.25,.3,p.y)-.5*i(.2,.1,p.y));e=o(e,n(99,66,51)*t,i(-.15,.1,p.y)*be);e*=1.+i(.36,.005,c.y)+i(.34,.005,c.y)+i(.865,.005,c.y)+i(.89,.01,c.y)-.5*ai(i(.245,.01,f))-.7*ai(i(.35,.01,c.y))-.5*ai(i(.325,.02,c.y))-.8*ai(i(.875,.02,c.y))-.3*ai(i(.9,.02,c.y));e*=.3+b0(b7(c.x));l e;}k d8(k e,d p,h s,h ac){s=db(p,d(s)).z/s*1e2;e*=1.+.5*ac*j(.9,.2,s)-.5*ac*i(2.5,.5,.3,s);l e;}k d9(k e,d c,h fa){h b=ae(c,d(4,9),.9,3.,4),t=.8+.8*b*b,a,f,ac,s,a0,m,u,r,z;k co=o(n(133,100,88),n(133,100,100),b)*t;d p,q;p=q=c;q.x=af(q.x);f=a9(p,.31);u=ch(q);ac=j(.01,.0,f);e=o(e*j(.0,.05,f+fa),k(.13*t),ac);e=d8(e,p,37.,j(.04,.02,af(f+.07)));a=u*22.;m=bl(a);s=a-m;a0=j(.23,.22,af(u-.25))+ck(m)*j(.0,.1,q.y);f-=r=(f*.3+.005)*a0;ac=j(.0,.1,q.y)*ak(af(f+.015)-.015);e=o(e,co,i(-.005,.01,f));e=o(e,n(130,75,44)*t,i(-.02,.005,f)*j(.0,.1,q.y));e*=1.-.3*j(.025,.03,-f)-.5*j(.4,.5,af(s-.5))*ac+.2*i(.5,.3,af(s-.5))*ac-.5*i(-.015,.007,f)-.5*i(-.03,.007,f)-.5*i(-.1,.005,f+r)-.5*i(-.115,.005,f+r)-.5*i(-.125,.015,f+r)-.5*i(-.145,.005,f+r)+.9*i(-.11,.007,f+r)+.5*i(-.14,.005,f+r)-b*i(.225,.005,af(u-.25))*ak(af(f+.015)-.015);a=u*72.;m=bl(a);s=a-m;a0=step(.7,bk(m))*step(q.y,.0)*j(.02,.0,af(f+.02));e=o(e,k(co*.6),a0*j(.4,.3,af(s-.5)));e*=1.-.7*a0*i(.4,.1,af(s-.5));l e;}k di(d c){h b=ae(c,d(4,9),.9,3.,4),t=.8+.8*b*b,a,f,ac,s,a0,m,u,r,z;k co=o(n(133,100,88),n(133,100,100),b)*t,e=k(.1*t);d p,q;p.x=c.x-.5;p.y=a2(c.y-.2,0.)*1.89;u=atan(p.y,af(p.x))/cj;f=a9(p,.48);a0=j(.3,.31,u);f*=1.-.2*j(.3,.31,u)-.1*j(.43,.44,u);a=u*(u>.44?2.:u>.3?63.:31.);e=o(e,co,j(.03,.01,af(f)));ac=ak(af(f-.01)-.02);m=bl(a);s=a-m;if(u>.33&&u<.44)s=aj(s+bk(m)*.6-.3);e*=1.-.5*ac*i(.307,.01,u)-t*ac*i(.5,.1+a0*.2,s)+b*ac*i(.52,.2+a0*.2,s);e*=1.-.9*i(-.015,.015,f)-.5*i(.0,.01,f)-.7*i(.03,.02,f)+i(.01,.015,f);q=p;q.y-=.5;q.x=af(q.x)+.6;f=a9(q,1.13);ac=j(.03,.02,af(f))*j(.5,.6,q.y);e=o(e,co*bc(1.-af(f-.015)/.03),ac);e*=1.-.5*ac*i(.005,.01,f)+.5*ac*i(.017,.005,f);q.x=af(c.x-.5)-.35;q.y=c.y*9./4.-2.1;f=a9(q,.13)*10.;a=ch(q)*49.;m=bl(a);s=a-m;u=j(.85,.9,bk(m));for(bd cd=0;cd<2;++cd,f+=.3){e=o(e,co*(b*.5+.2),j(.09,.03,af(f)));e*=1.+.7*ai(i(.01,.05,f));}p.y=(c.y-.7)*9./4.;f=a9(p,.43);a=atan(p.y,af(p.x))/cj;a=a2(a,-.48);r=a;m=bl(a*=23.);s=a-m;a0=ck(m)*.2-.1*j(.0,.1,-f);u=j(.1,.2,af(s-.5)-a0);f+=u*.007;r=(1.-u)*ai(i(.5,.3,r))*j(.25,.05,af(s-.5));f-=.17*r;ac=i(.04,.0,-.4,f);e=o(e,co*(b*.4+.4),ac);e=d8(e,p,31.,j(.1,.05,af(f+.15))*u);e*=o(1.,1.-i(.1,.2,.4,af(s-.5)-a0),ac*b);e*=1.-.7*ai(i(.03,.03,f))-.7*ai(i(.03,.03,f+.05))*u-.7*ai(i(.0,.02,f+.05))*u-.3*j(.04,.06,-f)*u+.5*i(.02,.0,-.1,f)+i(.0,.01+.07*r,f)+i(.0,.01,f+.03)*u;p.y-=.05;e=d9(e,p,0.);l e;}am(_43){c.y=(c.y+8.)/9.;l di(c);}am(_44){c.y=(c.y*4.+4.)/9.;l di(c);}am(_45){if(c.y<.01)++c.y;c.y=c.y*4./9.;l di(c);}am(_59){h b=ae(c,d(5),.9,3.,4),t=dw(a8(c,4.,.01),d(7),.5,3.,5),v=a6(a8(c,4.,.05),d(9)),ce,an;k pt=dz(c,4.,.1+v*t*.05),e;d f=dh(pt.x);ce=bk(aj(pt.yz));e=n(74,65,62)*(.8+.8*b*b);e+=i(.6,.3,v)*j(.3,.9,b*t)*.2;e*=1.-i(.5,.4,v)*j(.5,.7,t)*.1;e=o(e,n(86,74,78),i(.5,.1,b)*i(.7,.3,ce)*.7);e=o(e,n(105,90,70),i(.3,.1,t)*i(.3,.3,ce)*.3);an=i(.015,.005+.015*v,pt.x)+i(.4,.1,v*t)*.4;e*=1.-b*j(.015,.05,pt.x)*.7;e*=1.+an*b*(f.y-.5)*.7;e*=.9+.2*ce;e*=.9+.2*b7(a6(c-pt.yx,d(5)));l e;}am(_46){k e=_59(c);c-=.5;e=d9(e,c*.9,.02);l e;}k cv(d c){c*=1.5;h b=ae(a8(c,7.,.02),d(9),.7,3.,2),t=b,v=a6(c,d(13)),a,s,f;k e=_59(c);d p;p.x=af(c.x-.75);p.y=a2(c.y-.58,0.)*1.15;a=atan(p.x,p.y)/cj;s=aj(a*7.+.5);f=a9(p,.45);f-=.06*j(.4,.33,c.y);f-=.05*j(.15,.07,af(s-.5))*step(.63,c.y);f=b1(f,c.y-.107);if(c.y<.6)f=b1(f,af(p.x-.493)-.113);f=b1(f,a9(p,.6)+.044*j(.48,.43,c.y));e=o(e,n(144,125,115)*t,ak(f-.1,.005));e*=1.-.3*i(.12,.11,.1,f)+.5*i(.1,.005+.015*v*v,f);l e;}am(_33){l cv(d(5,0)/6.+c*d(1,4)/6.);}am(_34){l cv(d(1,0)/6.+c*d(4)/6.);}am(_35){l cv(c*d(1,4)/6.);}am(_36){l cv(d(5,4)/6.+c*d(1,2)/6.);}am(_37){l cv(d(1,4)/6.+c*d(4,2)/6.);}am(_38){l cv(d(0,4)/6.+c*d(1,2)/6.);}am(_60){h b=ae(c,d(13,1),.7,2.,3);k e=_59(c)*.7;e*=1.-ai(j(.4,1.,b));l e;}k ea(d c,d s){h b=ae(c,d(5),.9,3.,4),v=ae(c,d(31,3),.5,3.,3),t=.75+b*b;d p=c;k e=_59(c);if(c.y<.38)e=o(n(92,43,15),n(66,44,33),j(.1,.05,c.y))*t*(.5+.5*j(.0,.35,c.y));e+=b*s.y*ai(i(.32,s.x*.015,c.y))+.3*b*i(.34,.05,c.y);e*=1.-i(.38,.005+b*b*.03,c.y)+3.*i(.15,.2,c.y)*(v-.5);l e;}am(_61){h b=ae(c,d(5),.9,3.,4"
"),t=.75+b*b,f,be,m;d p=c;k e=ea(c,d(1));p.x=mod(p.x,1./7.)-.07;p.y-=.21;f=a9(d(.75*p.x,df(p.y,.1)),.033);be=ak(f,.005);f=a9(d(.75*p.x,df(p.y+.005,.09)),.033);m=ak(f+.015);e=o(e,n(83,81,66)*t,(be-m)*j(.1,.3,c.y));e*=1.-j(.17,.25,c.y)*m;e+=ai(i(.0,.015,f))*i(.32,.03,c.y);e*=1.+3.*pow(i(-.01,.03,f),4.)*i(.09,.03,c.y);f=a9(d(.75*p.x,df(p.y+.03,.1)),.033);e*=1.-ak(f+.01,.02)*(1.-be);if(c.y>.09&&c.y<.3)e=cn(e,d((af(p.x)-.035)*36.,aj(c.y*36.)-.5),.1);l e;}d fb(d p){p.x=af(p.x);d q=p,u;q.y-=.5;h f=a9(q,.35),an,e;u=q/.35;q.y+=.25;q.x-=.15;f=a1(f,av(q,d(.09,.05))-.1);an=c4(q,d(.15,.1))/5e1;e=.1+dot(d(u.y,b0(bc(1.-cw(u)))),d(.3,.3));q.y+=.2;q.x=p.x;e=a2(e,bc(.4-au(q)));e+=.15*i(.0,.1,an)-.1*ak(an+.12,.15);f=a1(f,av(q,d(.15-j(-.15,.15,q.y)*.07,.03))-.09);e*=1.-j(.05,.25,q.x)*j(.2,.1,af(q.y+.12));q.y-=.06;e-=.5*ak(c4(q,d(.05-j(-.1,.1,q.y)*.03,.06))/1e3+.03,.05);l d(bc(e),ak(f,.02));}am(_62){h b=ae(c,d(9),.7,2.,4),t=.75+b*b;k e=ea(c,d(4,.3));d p=c,s;p.x=mod(p.x,.2);p-=.1;s=fb(p*5.);l o(e,o(k(.5,.4,.3),k(.95,.8,.55),t)*t*s.x,s.y);}am(_54){c.y-=1./32.;d p=du(c.yx,d(8)),q=aj(p),u=a8(c,31.,.002),ce=p-q;h b=ae(a8(c,5.,.02),d(7),1.,3.,4),t=.8+.8*b*b,v=a6(c+dr(bk(ce)*64.),d(23)),ac=ae(c,d(9),.7,3.,4),f=ae(u,d(63),.7,3.,4),r=ae(u-d(0,.002),d(63),.7,3.,4),ad=f-r,an=dv(q,.03+.03*b7(v)).z,a4=bk(ce);k e=o(n(91,61,42),n(70,30,15),an*b);e=o(e,n(70,48,35),j(.5,.6,ac))*t;e*=1.+ad*(.1+v+i(.6,.1,ac))*(1.-an)-t*j(.7,1.,an)*a6(c,d(13))+.5*b*i(.3,.3,an);f=ae(u,d(23),.5,2.,4);e*=1.-.2*j(.6,.7,f)*a4+.3*i(.6,.05,f)*a4*v;e*=.9+.2*a4*(1.-an);e*=.9+.4*pow(dw(c-bk(ce/8.),d(5),.6,2.,4),4.);l e;}bj(_55){k e=_54(c);c=aj(c*2.+d(8,3)/32.);d p=c-.5,q=d(ch(p),au(p)),g=d(19);k u=dc(q,g);d w=q*g+u.xy;h v=a6(p,d(19)),ac=i(.9,2.,5.5,w.y),ad=u.y*2.;e*=1.-ac*i(.05,.2,u.z)*v+ac*i(.4,.3,u.z)*bc(ad);e*=1.-j(2.,1.5,o(q.y*g.y,w.y,v));l ai(j(.2,2.,q.y*g.y))*ah(e,1);}ao _56(){d p=UV-dp(a3.x*d(3,5));h b=ae(p,d(13),.6,2.,4);ah e=bi(bh,UV);al=ah(o(b*b*k(3,.4,0),e.a7,e.w)*bu(),1);}bj(_57){k e=_54(c);c=aj(c*2.+7./32.);h b=ae(c,d(5),.6,3.,4),r=au(c-.5)+b*b,ac=j(.2,.6,r);l ah(o(b*k(.5,.2,.0),e,ac),ac);}ao _58(){ah e=bi(bh,UV);h b=ae(a8(UV-a3.x*d(1,3)/2e2,a3.x*.05,4.,.05),d(7),.6,3.,4);e.a7=o(b*b*n(199,19,9)+j(.78,1.5,b),e.a7,e.w);al=ah((e.a7+(1.-e.w)*cc(Ref)*.2)*bu(),1);}bj(_29){h b=ae(c-=.5,d(5),.9,3.,4),t=.75+b*b,v=a6(a8(c,7.,.02),d(17)),r=au(c),a0=r>.4?38.:r>.32?28.:16.,a=aj(atan(c.y,c.x)/dq),m=bl(a*a0),b8=af(af(r-.41-v*.002)*1e2-6.),ac=j(1.5,1.4,b8),dj[]=h[](1.,3.,-.145,-1.,2.,.166),f,eb,s;d p=c;k e=n(78,68,63);e*=1.+.5*ai(i(.49,.005+.015*v*v+.015*b,r));e=o(e,n(83,52,47)*(.6+.4*v*v),ac)*t;e*=1.-.5*i(1.5,.5,b8)+b*i(1.,.5+.5*v,af(r-.418)*1e2-5.)-b*i(.5,.08,aj(a*a0+.5))*ac+b*i(.5,.1,aj(a*a0+.55))*ac;ac=j(.34,.33,r);e=o(e*(1.-.5*ac),n(83,52,47)*t,v*b*ac);e=o(e,n(112,86,31)*t,ac*ai(i(.1,.15,.45,b)));e=o(e,n(77,66,77)*t,ac*j(.5,.8,b)*.5);e*=1.-.7*i(.27,.34,.35,r);b8=r+v*.004;ac=r>.21&&r<.31?1.:0.;e*=1.-i(.325,.005,b8)-i(.31,.005,b8)-b*ai(i(.29,.005,b8))-b*ai(i(.23,.01,b8))-.5*ai(i(.21,.02,b8))+ai(i(.3,.01,b8))*b+ai(i(.22,.01,b8))*b-b*i(.5,.07,aj(a*a0+.5))*ac;if(r<.23)m+=37.;if(r<.31)m+=73.;if(r<.31)m+=91.;e*=o(1.,.9+.2*ck(m),ac);ac=j(.01,.0,af(r-.411)-.039);m=bl(a*72.);p*=bf(m*5.);s=0.;f=1e6;bd cd=0;for(;cd<6;cd+=3){f=ds(f,eb=dot(p,cf(d(dj[cd],dj[cd+1])))+dj[cd+2]);s+=s+h(eb>0.);}if(s==3.)++m;else m+=66.*s;m=ck(m);e=o(e,t*n(90,80,75),ac);e=o(e,t*n(127,111,88),m*b*ac);e*=o(1.,.7+.6*bk(m),ac);e*=1.-ac*ai(i(.0,.006,f))*b+ac*ai(i(.006,.006,af(f)))*b*.5;m=bl(a*4.);p=af(c*bf(m*90.+45.));f=1e6;for(cd=0;cd<2;++cd,p=af(p*bf(45.)))f=ds(f,af(au(p-d(0,.12))-.16));ac=j(.21,.2,r);b8=cz(cz(f,.012),.001);e*=1.-j(.21,.2,r)*ak(.012-f)+b*ac*ai(i(.005,.005,f))-.5*ac*ai(ak(b8-.001,.001));l ah(e,(1.-j(.21,.15,r)*ak(.028-f,.02))*j(.07,.087,r));}bj(_30){d p=aj(UV)-.5;h b=ae(bf(a3.x*333.)*p/(.8+.2*sin(a3.x*61.)),d(53),.7,2.,4);ah e=ah(1.-b*k(0,.3,1),1),bv=bi(bh,(bf(a3.x*30.)*p/(.8+.2*sin(a3.x*1.26)))+.5);e.a7=o(e.a7,bv.a7,bv.w);bv=bi(bh,UV);e.a7=o(e.a7,bv.a7,bv.w)*bu();l e;}h fc(d p){p=c9(p,8.);h f=a9(p,.41);f=a1(f,av((p-d(.34,0))*bf(45.),d(.1)));f=a2(f,p.x-.45);l f;}am(_31){d p=c-.5,q;h b=ae(c,d(9),.7,2.,4),t=.8+.8*b*b,r=a9(p,.41),f=fc(p),ad=dFdy(f)/.004,ac=ak(f+.01,.007),a=ch(p),an,v,x,z;k e=_59(c),a0=n(155,135,115)*t;e*=1.-(.5*-ad+.5)*j(.03,.0,f);e=o(e,a0,ac);an=au(p)*9.;q.x=a*bl(an+1.)*3.;q.y=aj(an);v=i(.5,.2,a6(a8(c,7.,.03),d(41)));v=ae(q,d(3,9),.5,2.,4)*i(.5,.5+.5*v,q.y);e=o(e,n(100,85,80)*b7(v)*b,ak(r+.15,.02));q=p;q.x=af(p.x);an=a2(a2(f,ew(q,-d(.08,.4))),af(r+.06)-.09);z=av(q-d(0,.3),d(.01,.03));an=b1(an,z-.02);x=ak(-an,.01);e*=1.+ad*ac*j(.02,.0,-f)*j(.01,.0,-r)+x*i(.035,.015,-r)+.5*x*i(.13,.01,-r)+.7*i(.08,.007,z)*(1.-x)-.7*x*ai(i(.01,.04,-r))-.6*x*ai(i(.13,.06,.03,-r))-.5*x*ai(i(.12,.02,-r))*ac-.9*ai(i(.12,.15,.2,-r))*ac-.5*ai(i(.0,.05,an));e+=k(.8,.8,1)*pow(bc(1.-au(c-d(.41,.59))/.35),8.);q.x=a;q.y=j(.05,.12,-r);an=db(q,d(37,1)).z;ac=i(.085,.035,-r)*x;e*=1.+.5*ac*i(.0,.2,an)-.3*ac*i(.3,.3,an);an=av(p+d(0,.33),d(.01,.03))-.03;ad=dFdy(an)/.004;e=o(e,a0*(.4+.8*j(.25,.41,-p.y)),z=ak(an,.01));e*=1.+.7*i(.005,.01,an)*ad-.5*i(.0,.01,.05,an);an=av(q=p+d(0,.35),d(.01,.015))-.01;ad=dFdy(an)/.004;e*=1.+.5*i(.005,.01,an)-.5*ai(i(.0,.01,an));e+=k(1,.7,.5)*pow(bc(1.-au(q)/.11),8.);l e;}ao _32(){k e=bi(bh,UV).a7*bu();d c=aj(UV)-.5,p=c;h t=mod(a3.x*2.,7.),m=bl(t),f=1e6;if(m==0.)f=ey(p*2.4+d(0,.05));if(m==1.){p.x=ep(p.x,.1,-1.,1.);f=av(p,d(.02,.15))*2.;}if(m==2.){f=a1(f,av(da(p,.0)+d(.13-j(-.3,.3,c.y)*.17,0),d(.02,.15)));f=a1(f,av(p+d(0,.07),d(.07,.02)))*2.;}if(m==4.)f=cq(p*1.8,.5);else f=cz(f,.005);al=ah(e+ak(f,.02)*aj(-t)*k(.5,.05,.05),1);}am(_63){h b=ae(c,d(13),.9,3.,4),v=ae(c,d(7),.9,3.,4);k e=o(n(60,50,50),n(87,47,37),ai(j(.7,.25,v)))*(.7+.8*b*b),g;c=a8(c,31.,.003);c6(g,c,b0(j(.0,.9,a6(p[m],d(93)))));e*=1.-(g.y+.4)*ai(b*g.z)*g.z;l e;}am(_67){h b=ae(c,d(5),.9,3.,4);k e=n(67,64,63)*(.6+.5*b),g;c=a8(c,31.,.003);c6(g,c,b0(a6(p[m],d(53,93))));e*=1.-.3*g.y*g.z*g.z;l e;}bj(_23){c=a8(c,7.,.01);h b=ae(c,d(9),.7,2.,4),v=ae(c,d(13),.5,2.,4),ac=j(.6,.9,ae(a8(c,5.,.03),d(11),.6,2.,4));k e=n(127,70,55)*(.85+.3*b);e*=1.-.2*ai(j(.3,.0,b*b))-.2*ac-.3*j(.6,.77,v)+.3*j(.5,.9,b);e+=.5*ai(j(.5,1.,ae(c,d(17),1.,2.,3)));l ah(e,1.-ac);}ao _25(){ah e=bi(bh,UV);d c=aj(UV);c.y-=.2*a3.x;h b=ae(a8(c,7.,.02),d(5),.9,2.,4);al=ah(o(n(25,10,8)*b,e.a7,e.w)*bu(),1);}am(_24){d p=c-.5;p=a8(p,17.,.007);p.x*=2.-c.y*1.5;h b=ae(c,d(9),.7,2.,4),v=a6(c,d(7)),f=au(p),s;k e=_23(c).a7;s=aj(f*=13.);if(f<=6.){e*=1.-pow(j(6.,.5,f+b*b),6.);v=j(.3,.7,v);e*=1.-v*b*i(.4,.2,s)+v*b*i(.6,.4,s);}l e;}am(_26){c=a8(c,13.,.003);h b=ae(c,d(7),.9,3.,4),v=ae(c,d(5),.5,2.,4),t=.5+b;k e=n(80,38,34),u=dc(c,d(23));e=o(e,o(n(180,125,118),n(165,78,51),v),b*i(.0,.4+v*.4,u.z))*t;l e;}am(_27){h b=ae(c,d(7),.9,3.,4),t=.8+.4*b,m,r=.7,ad,ac;k e,u=dc(c,d(23));d p=u.xy/r,q=c+u.xy/23.;m=bk(aj(q)*3.3);e=o(n(155,55,55),n(200,166,155),j(.75,.45,q.y))*t;ac=i(.5,.5,au(p));ad=dot(d(-p.y,b0(bc(1.-cw(p)))),d(.6+m*.3,.3));e*=1.-b*.8*j(.5,.1,u.z)+b*ac*ad;e*=t*t*t*t;l e;}am(_28){h b=ae(c,d(13),.9,3.,4),t=.4+b*b,v=b7(a6(a8(c,12.,.02),d(48))),m,r,ad,ac;k e=n(60,50,46)*t,u=dc(c,d(17));m=bk(aj(c+u.xy/17.));r=.4+.3*m;d p=u.xy/r;ac=a1(j(1.1,1.,au(p)),j(.0,.15,u.z));ad=dot(d(-p.y,b0(bc(1.-cw(p)))),d(.1+m*.2,.3));e+=b*ac*ad*v;v=b7(ae(a8(c,13.,.01),d(23,43),.5,2.,3));e*=1.+(1.-ac)*i(.4,.4,v);l e;}am(_65){h b=ae(c,d(7),.9,3.,4),v=ae(c,d(3),.5,3.,4);k e=o(n(103,56,53),n(73,58,71),j(.1,.7,v))*(.75+b*b);l e;}am(_66){h b=ae(c,d(13),.9,3.,4),v=a6(a8(c,5.,.05),d(9)),f=b7(aj(c.x*4.)),ac=j(.1,.15,f)*j(1.,.99,c.y);k e=n(51,44,44);e=o(e,n(73,55,52),j(.2,.2,b)*v*ac);e=o(e,n(69,60,66),j(.7,.1,b)*b*ac);e=o(e,n(99,77,77),j(.1,.5,v)*v*ac*b*b*.3);e*=.6+.3*b+.3*b*b;e*=1.+.9*ai(i(.21,.02+.1*v,f+b*.05))*ac*b;e*=1.-ai(j(.49,.5,af(c.y-.5)));e*=1.-j(.05,.2,f)*j(.16,.1,f);e*=1.+i(.99,.007,c.y);l cn(e,d(f-.4,aj(c.y*8.)-.5),.07);}k ec(d c,h s){h b=ae(c,d(3,1.+s+s),.7,2.,4),f=b7(c.x),ac;c.y*=2.;k e=o(n(71,60,58),n(110,88,77),j(.1,.05,f))*(.7+.6*b);e*=1.-j(.05,.0,c.x)*(1.-b*b);e*=1.+.5*i(.05,.02,c.x);d p=d(f-.35,aj(c.y*s)-.5);ah a0=dx(p,.11);ac=ak(a0.w);e*=1.-.7*dy(p,1.1)*(1.-ac);e=o(e,(a0.y>.0?n(128,105,88):n(200,111,66)*j(-.2,.7,a0.z))*(.4+2.*b*pow(bc(cp(a0.yz*.7)),4.))*(1.-.6*i(-.1,.4,a0.y)),ac);l e;}am(_39){l ec(c,4.);}am(_40){l _39(c.yx);}am(_41){l e"
"c(c,1.);}am(_49){h b=ae(c,d(40,5),.9,3.,4);k e=n(110,110,98)*(.8+.8*b*b);if(c.y<1./4.)e*=.5;e*=1.-.4*j(.4,.0,b)+.5*j(.02,.0,c.y)+.2*i(.24,.01,c.y);l e;}am(_50){d p=c,q;p.y*=22.;q=aj(p);h b=ae(c,d(3,23),1.,2.,6),v=ae(c,d(3,33),.7,3.,4),ce=bk(p.y-q.y);k e=n(92,67,53)*(.8+.8*b*b);e*=1.-ai(j(.1,.0,a1(q.y,1.-q.y)))*b;e*=1.-.2*smoothstep(.3,.7,v);e*=.8+.3*b*ce;l e;}am(_51){h b=ae(c,d(13),.9,3.,4),x=c.x*16./3.;k e=_50(c)*j(.15,.21,c.x);if(x<1.)e=n(59,48,49)*(.7+.6*b);e*=1.+.5*i(.05,.05,b7(x));l cn(e,d(af(c.x-3./32.)-.07,mod(c.y,.1)-.05),.004);}am(_52){d p=du(c,d(6,4)),q=aj(p),b6=q;h b=ae(a8(c-=.5,5.,.03),d(13),.9,2.,3),v=a6(c,d(73,7)),t=(.75+b*b)*(.8+.4*el(c.x*93.)),r;k e=k(.25*t);b6.y+=b6.y*2.-.01-.03*v;r=au(b6-=clamp(b6,d(.49,.5),d(.51,3)));e*=1.-.7*b*ai(j(.07,.03,af(r-.5)))+.5*b*i(.35,.1,r)*ai(j(.2,.1,q.y))-.3*ai(j(.8,1.,q.y))-.3*(j(.3,.1,q.y))*j(.4,.6,r)+.2*ai(j(.5,.1,q.y))*j(.45,.4,r);l e;}am(_69){h b=ae(c,d(5),.9,3.,4),a4=aj(c.y*10.);k e=o(n(53,48,42),n(38,38,36),b)*(.6+b*.8);e*=1.+.5*ai(i(.25,.25,a4))+.5*ai(i(.65,.35,a4))-.6*ai(i(.5,.5,a4));l e;}am(_68){h b=ae(c,d(7,3),.9,3.,4),a4=c.y+b*.04;k e=o(n(50,40,34),n(93,92,88),b*b);e*=1.+.9*j(.07,.04,af(c.y-.44))-.4*j(.08,.05,af(c.y-.7))-.5*i(.34,.05,c.y)-.3*i(.7,.04,c.y)+.7*i(.01,.03,c.y)+1.5*i(.89,.1,a4)+1.3*i(.5,.04,a4)+.9*i(.18,.04,a4);l e;}am(_70){h b=ae(c,d(5,3),.9,3.,4);k e=o(n(74,66,55),n(99,90,78),b*b);c.x*=2.;d p=cm(c,d(.5,.625),d(1.5,.625));h f=au(p-c),ac=j(.22,.20,f),ad=1.-.15*ac-.5*j(.7,.9,c.y)*ac-.3*(dh(f).y-.5)*i(.2,.03,f)-.3*ai(i(.17,.03,f))-.5*j(.05,0.,c.y)-.3*i(.33,.05,c.y)+.7*j(.93,1.,c.y)+.7*i(.31,.04,c.y);l e*ad;}bj(_71){h b=ae(c,d(1,5),.4,3.,4);k e=o(n(56,49,43),n(142,136,136),b);c=.5-af(c-.5);c.y*=4.;h a=i(.0,.1,au(c-cm(c,d(.41,.5),d(.42,3.5)))),f=c8(c),ad=1.-.7*a2(0.,1.-f/.15);ad*=1.-.8*j(.24,.31,a1(f,c.y-.1));e+=n(80,80,20)*a;l ah(e*o(ad,2.7,a),a);}bj(_74){h b=ae(c,d(1,5),.4,3.,4);k e=o(n(56,49,43),n(142,136,136),b);c=.5-af(c-.5);c.y*=8.;h f=au(c-cm(c,d(.27,.3),d(.27,7.7))),a=i(.0,.17,f),ad=1.-.5*i(.17,.07,f);e+=n(80,80,20)*a;l ah(e*o(ad,2.7,a),a);}bj(_72){d p=af(c-.5);h b=ae(c,d(1),.4,3.,4),r=au(p),a=j(.37,.33,r)*(.5+2.*b),ad=1.+.0*j(.08,.03,af(r-.41));k e=o(n(56,49,43),n(142,136,136),b);ad=o(ad,7.,j(.44,.1*b,r));ad*=1.-.5*ai(i(.46,.04,r));ad*=1.-.4*ai(i(.36,.04,r));l ah(e*ad,a);}bj(_73){h b=ae(c,d(5),.9,3.,4),f=dg(d4(c-=.5,.35),af(a9(c,.4)),.02),a=pow(ak(f-.02,.15),8.),be=a1(a2(av(c,d(.46)),-a9(c,.51)),af(a9(c,.44)));k e=n(76,62,47)*(.8+.8*b*b);e*=1.+(b+.5)*ak(af(be)-.01,.01);e*=1.-j(.1,.05,f)*ak(a9(c,.4));l ah(e+1.*k(1,1,.3)*a,a);}bj(_1){c-=d(.48,.5);h f=cq(c,0.),b=au(c)-.47;k e=1.-k(.5,1,1)*ak(a2(.007-f,b+.04));l ah(e,1)*ak(b);}am(_2){c-=.5;d r=d(dFdx(c.x),dFdy(c.y));c/=r/cl(r);c*=.8;c.y-=.03;h x=af(c.x),b=ae(c,d(31,5),.7,2.,3),t=.8+.8*b*b,f=cq(c,1.),an=cq(c+d(0,.002),1.),ad=(an-f)*5e2+.5;k e=k(.3*t,0,0)*ak(f,.004);e*=1.-ai(j(.0,.3,x))-.5*j(.1,.3,af(c.y-.1));e+=+t*.2*i(.0,.01-.01*x,f)*i(.1,.2,c.y)*j(.3,.2,x)*ad+t*.5*j(.004,.0,f)*j(.07,.1,c.y)*i(.23,.1,x)*k(.9,.9,1)+t*.4*i(.005,.005,f)*j(.2,-.1,c.y)*j(.3,.2,x)*bc(-ad);l e;}h ed(d c,h s,h m,h fd){m=(c.y-ai(af(c.x-.5))*fd)*s-m;l 2.*i(.5,.4,m)*(aj(m)-.5);}bj(_83){h b=ae(c,d(5,9),.9,3.,4),t=.8+.8*b*b,v=ae(c,d(5,9),.9,3.,2),x=af(c.x-.5),f;k e=n(77,60,44)*t;d p=c*d(1,2)-d(.5,.7);e*=1.-.55*ak(b1(a9(p,.3),cq(bf(45.)*p*.8,0.)-.01));e*=1.+ai(j(.6,.9,b))+i(.2,.5,c.y)*i(.2,.3,x)*ed(c,4.,.2,4.);for(h a5=6.;a5<9.;++a5)e*=1.+i(.8,.5,c.y)*i(.2,.3,x)*ed(c,12.,a5,1.);f=c.y-.81-ai(bc(x*4.))*.09;e=o(e,n(82,66,60)*t,j(.0,.01,f));e*=1.-.5*(i(.01,.02,f))+.5*(i(.02,.01,f));f=.15*(1.-c.y);f=av(c-.5,d(.49)-f)+v*.1*b0(1.-c.y)-f;l ah(e*ai(ak(f+.01,.05)),ak(f));}bj(_84){ah e=bi(bh,c);if(e.w<.5)discard;e.a7*=ai(bu()*.5);l e;}ah cg(k p,k v,h s){p*=s/h(textureSize(bh,0).x);v*=v;ah e=ah(0);for(bd m=0;m<3;++m,p=p.yzx)e+=bi(bh,p.yz)*v[m];l e/cp(v);}ah cg(k p,h s){l cg(p,Nor,s);}ah cg(h s){l cg(Pos,s);}ao _85(){k v=Nor*Nor;al=cg(4.)*(Clr+.5*v.z*v.z*sign(Nor.z))*1.5;}ao _86(){_85();}ao _101(){al=cg(16.)*(cf(WNor).z*.5+.5)*ah(1,.95,.9,1);al+=2.*pow(bc(cf(Nor).z),o(2.,8.,al.y))*ai(al);}ao _102(){al=ah((cc(Ref,15.)*1.4+.3)*a3.yzw,1);}ao _103(){k r=Ref;h s=17.;if(a3.y<1.){s=9.;mat2 a=bf(a3.x*90.);r.xy*=a;r.yz*=a;}s=cc(r,s);al=ah(ai(j(.1,.9,s))*1.5*aj(a3.yzw)+.5*ai(j(.9,1.,s)),0);}ao _104(){k r=Ref;r.xz*=bf(a3.x*9.);al=ah(cc(r));}ao _105(){d c=d(Pos.x/24.-.5,au(Pos.yz));al=a6(c,d(3))*j(1.,.9,c.x)*ah(.25,0,0,0);}h fe(h b,h a,h a5,h p){l(af(aj(a3.x*a5+p-.25)-.5)*4.-1.)*a+b;}ao _106(){k r=Ref;mat2 a=bf(a3.x*90.);r.xy*=a;r.yz*=a;al=cc(r,22.)*bc(fe(-.3,1.3,.3,0.))*ah(.3,.55,.25,0);}am(_107){h b=ae(c,d(7),.5,2.,4),t=.8+.8*b*b,v=a6(c,d(2));l o(n(5,77,55),n(8,122,188),j(.5,.1,v))*ai(1.-v)*t*2.*(1.+i(.2,.05,b*b));}ao _108(){k p=Pos-k(4.5,0,2),r=Ref,v=Nor;r.xz*=bf(a3.x*9.);p.xy*=bf(a3.x*33.);v.xy*=bf(a3.x*33.);al=cg(p-a3.x*16.,v,16.)+cc(r);}ao _109(){k v=cf(Nor),p=Pos;p.z-=24.;h an=i((ae(Pos.y/48.+a3.x*7.4,13.,.6,2.,4)-.5)*.15,.03,aj(j(-8.,32.,Pos.z)-a3.x*1.3)-.5);al=ah((cg(16.).a7*(v.z*.5+.5)*(.2+.8*j(4.5,6.5,au(p)))+an*an)*a3.yzw*2.,1);}h ee(h e,h s,h x){h a=a2(fwidth(x)*2./s,1.);l i(e,s*a,x)/a;}ao _87(){_85();k p=Pos,q;p.y=af(p.y);q=p-k(7,3.5,-21);q.z*=1.3;h r=au(q);al.a7*=1.+bc(p.z+30.)*j(4.,5.,au(p.xy))+.5*bc(p.z+15.)+.3*i(3.,.5,r)+.7*ee(-15.,.5,p.z)-ee(-14.5,.5,p.z)-j(3.,2.5,r)*(.6+.4*q.z/r);q=p-k(8,0,-23);q.z*=.7;r=au(q);al.a7*=1.-j(2.,1.,r)*(.6+.4*q.z/r);}bj(_88){c*=d(256,64);c.y+=2.;h f=a9(c-d(81,30),11.);f=a2(f,c.x-80.);f=a2(f,-a9(c-d(84,26),9.));f=a1(f,av(c-d(73,37),d(4,9))-4.);f=a2(f,-av(c-d(73,37),d(0,7))+1.);f=a1(f,av(c-d(91.5,47),d(4,19))-4.);f=a2(f,-av(c-d(91.5,47),d(0,17.5))+1.);f=a1(f,av(da(c,111.)-d(105.+j(23.,50.,c.y)*3.,43),d(3.5,19)));f=a1(f,av(c-d(111,32),d(4,3)));f=a1(f,av(c-d(126,37),d(3,13)));f=a1(f,av(c-d(125.5+j(23.,50.,c.y)*10.,44),d(3.5,6)));f=a1(f,av(c-d(136.5-j(23.,50.,c.y)*9.,32),d(3.5,8)));f=a1(f,av(c-d(148.5,37),d(7,13)));f=a2(f,-av(c-d(155,33),d(6,3)));f=a2(f,-av(c-d(155,43),d(6,2)));f=a1(f,av(c-d(168,37),d(3.5,13)));f=a1(f,av(c-d(178.,37),d(3.5,13)));f=a1(f,av(c-d(188,37),d(3.5,13)));f=a2(f,c.y-50.);l ah(ak(f,.8),0,0,bk(c*511.));}ao _89(){k e=bi(bh,UV*2.).a7*step(.5,aj(a3.x*.5));e=o(e*bu(),k(.5,0,0),i(aj(a3.x*2.),1./64.,aj(UV.y)));al=ah(e+cc(Ref)*.25+bi(bh,UV+bk(a3.xx)).w*.1,1);}ao _90(){d c=aj(UV);c.x+=a3.x/13.;h b=ae(c,d(3,7),.9,2.,4),a5=c.y;al=ah(2.*n(95,85,80)*a5*a5*a5*a5*o(1.,b,.5),0.);}ao _91(){al=ah(cc(Ref)*n(133,111,111),0);}h star(d p,d e,h s){p-=e;h a=j(.3,.5,af(aj(ch(p/=s)*8.+bk(e))-.5));l j(.9,.6,pow(cw(p),.0625)-a*a*.006);}ao _92(){al=ah(2,2,2,0)*pow(star(UV,d(.5),1.),2.);}h ef(d c,h s){d p=c;p.y+=p.y-a3.x*s;c.x+=(er(p.y*5.)-.5)*1.5*ai(c.y);h v=ae(a8(p,7.,.02),d(9),.7,2.,4),a4=j(.9,.03,c.y),b=av(c-d(.5,.15),d(0,.3));l ai(ak(b+v*ai(1.2-a4)-.13,.15));}ao eg(h s){d c=aj(UV);al=(ef(c,s*.6)+ef(c,s))*ah(2.5,1,.35,0);}ao _93(){eg(2.5);}ao _94(){eg(1.);}ao _0(){h ad=dot(Nor,cf(k(2,0,8)));ad=ad*.4+.7;d c=e0(Pos,e1(Nor));k e=k(.5);e*=e2(k(aj(cy*a3.w+.25),1.,1.));al=ah(e*ad,1);}ao _6(){ah e=bi(bh,UV);al=ah(e.a7*o(bu(),k(1),e.w),1);}ao _76(){ah e=bi(bh,UV);h r=au(aj(UV)-.5);h s=o(.4,8.,aj(a3.x*1.5));al=ah(e.a7*bu()+n(240,130,5)*i(.1,.05,r/s)*j(.37,.32,r),1);}ao _5(){k e=bi(bh,UV).a7;al=ah(e*bu(),1);}ao _7(){ah e=bi(bh,UV);e.a7*=1.+e.w*cc(Ref);al=ah(e.a7*bu(),1);}ao _79(){al=ah(0);}ao _80(){k f=cf(Pos-Cam.a7);f.z=f.z*4.+2.;d c=cf(f).xy*2.;h b=j(.2,1.,ae(c-a3.x*d(.1,.2),d(5),.5,2.,6));c.y*=1.5;h s=j(.3,1.,ae(c-a3.x*d(.1,.18),d(5),.6,2.,6));al=ah(k(b,0,0)+n(80,30,8)*s*s*2.,1);}ao _81(){d c=a8(UV/8.,a3.x*.5,2.,.05);h b=ae(c,d(7),.9,2.,4);k e=n(91,22,14)*(.2+1.6*b);e=o(e,n(144,44,0),i(.6,.2,ae(c,d(3),.7,3.,4)));e=o(e,n(244,144,66)*b*2.,ai(i(.55,.25,ae(c,d(11),.5,2.,4))));al=ah(e*bc(cl(bu())),1);}ao _82(){_81();}ao _3(){al=bi(bh,(.5+UV*127.)/128.,2.5);al.a7*=.7+.3*a6(UV,.5/fwidth(UV));}ao _4(){al=bi(bh,UV)*Clr;}bj(_95){c.y*=2.;h b=ae(c,d(5),.9,2.,4),a0=.5+b,t=.8+b*.4,f=c.y-1.05;k e=n(55,44,37)*t;d p=c;f=dg(f,av((c-d(.5,1.5))*bf(45.),d(.2))-.1,.3);f=a2(f,.03-p.y);e=o(e,cn(e,c-d(.5,1.5),.1),8.*b);p.x=a1(p.x,1.-p.x);if(p.y>.5)p.y-=.5;e=o(e,cn(e,p-d(.22,.31),.04),2.*t);e*=1.+ai(j(.5,1.,b))+dh(f).y*i(.0,.05,f)*(1.+11.*j(1.5,2.,c.y))*b+a0*i(.93,.05,c.y)+a0*i(.4,.05,c.y)+a0*i(.1,.05,c.y)-.5*i(.97,.05,c.y)-.5*ai(i(.7,.05,c.y))-.5*ai(i(.2,.05,c"
".y))-.5*i(.66,.1,c.y)-.5*i(.45,.03,c.y)-.5*i(.15,.1,c.y)-i(.01,.03,c.y);l ah(e,ak(f,.03));}ao _96(){al=bi(bh,UV);if(al.w<0.5)discard;al*=Clr*1.5+.3;}ao _97(){d c=d(ch(Pos.xy),j(8.,128.,Pos.z));c.x=aj(c.x*3.-a3.x*2.2);c.y*=4.;h a5=star(c,d(0,.3),1.)+star(c,d(1,.3),1.)+star(c,d(.5,.4),1.5);a5*=a5;al=ah(a5,a5,a5,0);}bj(_98){h b=ae(a8(c,5.,.03),d(7),.5,3.,2);l(b*1.4+.3)*ah(1.2,.54,.06,0)+.5*i(.7,.2,b)*ah(1,1,1,0);}ao _99(){k p=Pos;p-=a3.x*6.4*sign(p.z-72.);al=cg(p,8.);}am(_100){c=a8(c,5.,.02);h b=ae(c,d(6),.8,2.,4),ac=ae(c,d(2),.6,2.,4),t=.8+.3*b*b;k e=o(n(36,33,30),n(168,177,168),.3+.7*ac)*t;l e;}ao _110(){d c=c9(UV-.5,4.);al=ah(1,1,0,1)*ak(a1(cz(au(c)-.4,.04),av(c,d(.25,.06))),.01);}ao _111(){al=ah(.4,.7,.3,1)*ak(dot(af(UV-.5),d(4,3)/5.)-.2,.01);}ao _112(){d c=UV-.5;c.x=af(c.x);h w=.15*b0(j(-.32,-.29,c.y))+.05*j(-.3,-.12,c.y)+.1*b0(j(-.12,.07,c.y))+.14*step(.07,c.y)-.1*ai(j(.07,.31,c.y)),f=b1(av(c,d(w,.3)),a9(c-d(0,.777),.5));al=ah(1,1,0,1)*ak(f-.01,.01);}ao _113(){d c=UV;h f=av(c-d(.35,.5),d(.1,.4));c.y=mod(c.y-.06,.28)-.16;f=a1(f,av(c-d(.51,0),d(.34,.04*j(.85,.7,c.x))));f=b1(f,av(c-d(.65,0),d(.02,1)));al=ah(1,1,0,1)*ak(f,.01);}ao _114(){d c=UV;c.x=mod(c.x,.33)-.16;h f=av(c-d(0,.52),d(.1,.4));f=b1(f,av(c-d(0,.65),d(.05,.23)));f=b1(f,af(c.y-.2)-.02);al=ah(1,.5,0,1)*ak(f,.01);}ao _115(){d c=(UV-d(.55,.45))*bf(-45.);h f=cm(c,d(-.4,0),d(.2,0),.1);f=a2(f,-.3-c.x);c.y=af(c.y);f=a1(f,av(c+d(.37,0),d(.05,.005)));f=a1(f,av(c+d(c.y+.1,-.18),d(.1,.05)));al=ah(1,0,0,1)*ak(f,.01);}ao _116(){d c=(UV-.5)*bf(45.);h f=av(c,d(.6,.03)),p=c.x*12.6+1.55,a4=sin(p)*.15,q=b7(aj(a4));f=a1(f,a2(cz(c.y-a4,.05-.1*q)*(1.+q+q),af(c.x)-.6));al=ah(0,1,0,1)*ak(f,.01);}ao _117(){d c=c9(UV-.5,5.);h f=au(c)-.18,r=c.x-.33,a4=.04*i(.0,.3,r);c.x-=.33;c*=bf(-15.);f=a1(f,av(c,d(.04,2.*a4)));f=a1(f,av(c-d(0,a4*sign(r)),d(.14,a4)));al=ah(.77,0,1,1)*ak(f+.01,.01);}ao _118(){d c=UV-.5;h f=cq(c+d(0,.05),0.)-.01;f=a1(f,av(c9(c*bf(45.),4.)-d(.45,.0),d(.11,.02)));al=ah(0,.88,.95,1)*ak(f,.01);}"
;

// src/demo/data/shaders/vertex_shaders.glsl: 4853 => 2375 (48.9%)
static constexpr char g_vertex_shaders[] =
"#define c void\n"
"#define f vec4\n"
"#define j gl_Position\n"
"#define l location\n"
"#define n normalize\n"
"uniform mat4 MVP,View,World;uniform f Time,Cam;layout(l=0)in f e;layout(l=1)in f k;layout(l=2)in vec3 h;layout(l=3)in f o;out vec3 Pos,Nor,WNor,Ref;out vec2 UV,LUV;out f Clr;c d(){j=e;UV=e.xy*.5+.5;}c m(float v,float ac,float ad){j+=ac*MVP*f(h,0)*sin(6.28*(Time.x*ad+dot(e.xyz/v,vec3(1))));}c _0(){j=MVP*e;Pos=e.xyz;Nor=h;UV=k.xy;LUV=k.zw;Clr=o;Ref=n(reflect((e-Cam).xyz,h));}c i(){_0();Pos=floor(h)/4.;Nor=fract(h)*4.-2.;Ref=n(reflect((e-Cam).xyz,Nor));float a=k.z,u=cos(a),s=sin(a);Nor.xy*=mat2(u,s,-s,u);}c _1(){d();}c _2(){d();}c _3(){d();}c _4(){j=f(2.*e.x-1.,1.-2.*e.y,1,1);UV=k.xy;Clr=o;}c _5(){_0();}c _6(){_0();}c _7(){_0();}c _8(){d();}c _9(){d();}c _10(){d();}c _11(){d();}c _12(){_0();}c _13(){d();}c _14(){_0();}c _15(){d();}c _16(){d();}c _17(){d();}c _18(){_0();}c _19(){d();}c _20(){d();}c _21(){d();}c _22(){d();}c _23(){d();}c _24(){d();}c _25(){_0();}c _26(){d();}c _27(){d();}c _28(){d();}c _29(){d();}c _30(){_0();}c _31(){d();}c _32(){_0();}c _33(){d();}c _34(){d();}c _35(){d();}c _36(){d();}c _37(){d();}c _38(){d();}c _39(){d();}c _40(){d();}c _41(){d();}c _42(){d();}c _43(){d();}c _44(){d();}c _45(){d();}c _46(){d();}c _47(){d();}c _48(){d();}c _49(){d();}c _50(){d();}c _51(){d();}c _52(){d();}c _53(){d();}c _54(){d();}c _55(){d();}c _56(){_0();}c _57(){d();}c _58(){_0();}c _59(){d();}c _60(){d();}c _61(){d();}c _62(){d();}c _63(){d();}c _64(){d();}c _65(){d();}c _66(){d();}c _67(){d();}c _68(){d();}c _69(){d();}c _70(){d();}c _71(){d();}c _72(){d();}c _73(){d();}c _74(){d();}c _75(){d();}c _76(){_0();}c _77(){d();}c _78(){_0();}c _79(){_0();}c _80(){_0();}c _81(){_0();m(100.,3.,.1);}c _82(){_0();}c _83(){d();}c _84(){_0();m(30.,3.,.2);m(100.,3.,.7);}c _85(){i();}c _86(){i();}c _87(){i();}c _88(){d();}c _89(){_0();}c _90(){_0();}c _91(){i();}c _92(){_0();j+=MVP*f(Nor*mat3(View),0);}c _93(){_0();}c _94(){_0();}c _95(){d();}c _96(){_85();}c _97(){i();}c _98(){d();}c _99(){i();}c _100(){d();}c _101(){_0();WNor=n(mat3(World)*h);Ref=n(reflect((World*e-Cam).xyz,WNor));}c _102(){_101();}c _103(){_101();}c _104(){_101();}c _105(){_101();}c _106(){_101();j+=MVP*f(h+h,0);}c _107(){d();}c _108(){_101();}c _109(){_101();}c _110(){d();}c _111(){d();}c _112(){d();}c _113(){d();}c _114(){d();}c _115(){d();}c _116(){d();}c _117(){d();}c _118(){d();}"
;

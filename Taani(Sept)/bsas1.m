m=load('bsasinput.txt');
length(m);
p=m;
s = strcat(s1,s2)
ford=[7 3 1 5 9 6 8 4 2 10 15 13 14 11 12]
[chhhh h]=min(ford);
n=length(ford);
t=1.4;
q=2;
m=1;
c=[ford(1)];
c2=zeros(15);
c2(1)=ford(1);
c2;
cr=[p(c,1) p(c,2)];

for i=2:n
    dc=[];
    a=ford(i);
    x=p(a,1);
    y= p(a,2);    
    for j=1:m
        u=(cr(j,1)-x)*(cr(j,1)-x);
        v=(cr(j,2)-y)*(cr(j,2)-y);
        w=u+v;
        w=sqrt(w);
        dc=[dc w];         
    end
    
     [t1 cl_number]=min(dc);
     if (t1>t) && (m<q)
         m=m+1;
         c=[c a]
         c2(m)=a;
         cr=[cr;x y];
     else
         egg=x+cr(cl_number,1);
         egg=egg/2;
         cr(cl_number,1)=egg;
         
         egg=y+cr(cl_number,2);
         egg=egg/2;
         cr(cl_number,2)=egg;
         fprintf('%d belongs to cluster %d\n',a,cl_number);
         c2(cl_number,i)=a;
         c2;
         
         
     end
   
    
end
c2

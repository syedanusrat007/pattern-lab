fid=fopen('input.txt','r');

t1=str2num(fgets(fid));
xin=[];
yin=[];
cin=[];


for(i=1:t1)
    t=fgets(fid);
    s=regexp(t,' ','split');
    xin=[xin str2num(char(s(1)))];
     yin=[yin str2num(char(s(2)))];
      cin=[cin s(3)];
    
end


w=[1 1 0];

t=0;
c1x=[];
c1y=[];
c2x=[];
c2y=[];
while(1)
    y1=[];
    y2=[];
     y3=[];
      for(i=1:t1) %t1=15  %xin=x cor, yin=y cord,cin=class
    %a=numel(y1)
    tf=strcmp(cin(i),'B');
        if(tf==1)
        c2x=[c2x xin(i)];
        c2y=[c2y yin(i)];
        del=1;% mane equal
    elseif(tf==0)
        c1x=[c1x xin(i)];
        c1y=[c1y yin(i)];
        del=-1;
    end
    x=[xin(i);yin(i);1];
    
    r=w*x*del;
    if(r>=0)
        y1=[y1 xin(i)];
        y2=[y2 yin(i)];
         y3=[y3 cin(i)];
    end
      end
      a=numel(y1); %size/length
      num=[0;0;0];
   for(i=1:a)
       tf=strcmp(y3(i),'B');
    if(tf==1)
        del=1;% mane equal
    else
        del=-1;
    end
    as=del.*[y1(i);y2(i);1];
    num=num+as;
    
   end
   num
       
   wt=transpose(w);
   wt1=wt-(0.7.*num);
  
   
   
   b=transpose(wt1);
   w=b;
  
   t=t+1;
   a=numel(y1)
   if(a==0)
       w
         

scatter(c1x,c1y,'o');
hold on
scatter(c2x,c2y,'x');
hold on
x=[-20 20]
y1=-(w(3)+w(1)*x(1))/w(2);
y2=-(w(3)+w(1)*x(2))/w(2);

y=[y1 y2]
plot(x,y)
hold on 
grid on

       break;
   end
end

      
   
  
 
        
    

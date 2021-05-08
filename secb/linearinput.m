fid=fopen('input.txt','r');
t=fgets(fid);
t1=str2num(char(t));
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
FID = fopen('in.txt','r');
sentence = fgets(FID);
sport = [];
nsport = [];
scount= 0;
ncount = 0;
test = str2num(fgets(FID));

for i=1:test
    s = fgets(FID);
    type = cellstr(fgets(FID));
    strcmp(type,'Sports');
    ss= regexp(s,' ','split');
    kk ='Sports';
    if( strcmp(type,kk)==1)
        scount = scount+1;
        for j=1:size(ss,2)-1
            sport= [ sport , lower(ss(j))];
           
        end
    else
        ncount=  ncount+1;
        for j=1:size(ss,2)-1
            nsport= [ nsport , lower(ss(j))];
        end
    end
end

ps = scount /(scount+ncount);
pn = ncount /(scount+ncount);
sen = regexp(sentence,' ','split');
uniq= 0;
temp = [ sport nsport ];
for i = 1: size(temp,2)
    if( strcmp( temp(i),'-1' )==1 )
        continue
    end
    uniq = uniq+1;
    
    for j=i+1 : size(temp,2)
        if(strcmp(temp(i),temp(j))==1)
            temp(j)={'-1'};
        end
    end
end

tots = size( sport,2 );
totn = size( nsport,2 );


for i=1:size(sen,2)
    txt = lower(sen(i));
    
   
    counts =1;
    countn = 1;
    for j=1:size(sport,2)
        if(strcmp( txt, cellstr(sport(j)) ) ==1 )
            counts = counts+1;
        end
    end
    
    for j=1:size(nsport,2)
        if(strcmp( txt, cellstr(nsport(j)) ) ==1 )
            countn = countn+1;
        end
    end
    ps = ps * ( counts / (tots + uniq) );
    pn = pn * ( countn / (totn+ uniq) );
end


if(ps>pn)
        disp('sport')
else
       disp('Not sport')
end


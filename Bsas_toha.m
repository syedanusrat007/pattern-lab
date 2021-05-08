fid = fopen('in.txt','r');
n = fscanf(fid,'%d',1);
inp = [];
order = [];
for i=1:1:n
    x =fscanf(fid,'%d',1);
    y= fscanf(fid,'%d',1);
    inp= [ inp ; x y ];
end

for i=1:1:n
    o =fscanf(fid,'%d',1);
    order = [order o];
end
theta  =fscanf(fid,'%f',1);
q = fscanf(fid,'%d',1);

m = 1;
cluster = zeros(n,n);
csize = zeros(1,n);
csize
cluster(1,1) = order(1);
csize(1) = 1;
avg =  zeros(n,2);
avg(1,1) = inp( order(1),1);
avg(1,2) = inp( order(1),2);
for i = 2:1:n
    min = 10000000000;
    indx = 1;
    for j = 1 : 1:m
        dist = sqrt( ( inp(order(i),1)- avg(j,1) ) * ( inp(order(i),1)- avg(j,1) ) +  ( inp(order(i),2)- avg(j,2) ) * ( inp(order(i),2)- avg(j,2) ) );
        if dist < min
            min = dist;
            indx = j;
        end
    end
    
    if min > theta && m < q
        m = m+1;
        avg(m,1) = inp( order(i),1);
        avg(m,2) = inp(order(i),2);
        csize(m) = 1;
        cluster(m,1) = order(i);
    else
        sz = csize(indx);
        csize(indx) = sz+1;
        cluster(indx,sz+1) = order(i);
        avg(indx,1) = ( avg(indx,1) *sz + inp(i,1) )/ (sz+1);
        avg(indx,2) = ( avg(indx,2) *sz + inp(i,2) )/ (sz+1);
    end
end
cluster



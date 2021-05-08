fid=fopen('string_in.txt','r');
s1=fgets(fid)
t1=str2num(fgets(fid))

cin=[];


for(i=1:t1)
    t=fgets(fid);
    s=regexp(t,' ','split');
  
      
str2=s1;
str1=s;
weight_insert=1;
weight_delete=1;
weight_replace
m = numel(str2);
n = numel(str1);
v1 = zeros(m+1, 1, 'double');
v2 = zeros(m+1, 1, 'double');
v = zeros(m+1, n+1, 'double');
v1 = (0:m)'*weight_insert; 
v(:,1) = v1;
for i = 1:n
    v2(1) = v1(1) + weight_delete;
    for j = 2:m+1
        if  isequal(str1(i),str2(j-1))
            v2(j) = v1(j-1);
        else
            v2(j) = min(min(v1(j-1)+weight_replace,v1(j)+weight_delete), v2(j-1)+weight_insert); 
        end
    end
    v1 = v2;
    v(:,i+1) = v1;
end
V = v2(m+1)

v = v';
i = n+1;
j = m+1;
sp='_';
str1(i) = cellstr(sp);
str1(2:i) = str1(1:n);
str1(1) = cellstr(sp);
str2(j) = cellstr(sp);
str2(2:j) = str2(1:m);
str2(1) = cellstr(sp);
k = 0;
hold on;
while((i>0)&&(j>0))
    k = k+1;
    if(str1(i) == str2(j))
        Path(1,k) = str1(i);
        Path(2,k) = '|';
        Path(3,k) = str2(j);
        i = i-1;
        j = j-1;
        plot(i,j,'o');
    else
        if((i>1)&&(j>1))
            if(v(i-1,j-1) == min(min(v(i-1,j-1), v(i,j-1)), v(i-1,j)))
                Path(1,k) = str1(i); 
                Path(2,k) = ':';
                Path(3,k) = str2(j);
                i = i-1;
                j = j-1;
                 plot(i,j,'*');
            elseif(v(i-1,j) == min(min(v(i-1,j-1), v(i,j-1)), v(i-1,j)))
                Path(1,k) = str1(i); 
                Path(2,k) = ' ';
                Path(3,k) = '_';
                i = i-1;
                 plot(i,j,'#');
            elseif(v(i,j-1) == min(min(v(i-1,j-1), v(i,j-1)), v(i-1,j)))
                Path(1,k) = '_'; 
                Path(2,k) = ' ';
                Path(3,k) = str2(j);
                j = j-1;
                 plot(i,j,'-');
            end
        elseif(i==1)
            Path(1,k) = '_';
            Path(2,k) = ' ';
            Path(3,k) = str2(j);
            j = j-1;
             plot(i,j,'+');
        elseif(j==1)
            Path(1,k) = str1(i); 
            Path(2,k) = ' ';
            Path(3,k) = '_';
            i = i-1;
             plot(i,j,'/');
        end
    end
end
hold off;
Path = Path(:,end-1:-1:1)
      
    
end




str2='pqrwingcipal';
str1='principle';
weight_insert=1;
weight_delete=1;
weight_replace
m = numel(str2);
n = numel(str1);
v1 = zeros(m+1, 1, 'double');
v2 = zeros(m+1, 1, 'double');
v = zeros(m+1, n+1, 'double');
v1 = (0:m)'*weight_insert; 
v(:,1) = v1;
for i = 1:n
    v2(1) = v1(1) + weight_delete;
    for j = 2:m+1
        if (str1(i) == str2(j-1))
            v2(j) = v1(j-1);
        else
            v2(j) = min(min(v1(j-1)+weight_replace,v1(j)+weight_delete), v2(j-1)+weight_insert); 
        end
    end
    v1 = v2;
    v(:,i+1) = v1;
end
V = v2(m+1)

v = v';
i = n+1;
j = m+1;
str1(i) = '_'; 
str1(2:i) = str1(1:n);
str1(1) = '_';
str2(j) = '_';
str2(2:j) = str2(1:m);
str2(1) = '_';
k = 0;
hold on;
while((i>0)&&(j>0))
    k = k+1;
    if(str1(i) == str2(j))
        Path(1,k) = str1(i);
        Path(2,k) = '|';
        Path(3,k) = str2(j);
        i = i-1;
        j = j-1;
        plot(i,j,'o');
    else
        if((i>1)&&(j>1))
            if(v(i-1,j-1) == min(min(v(i-1,j-1), v(i,j-1)), v(i-1,j)))
                Path(1,k) = str1(i); 
                Path(2,k) = ':';
                Path(3,k) = str2(j);
                i = i-1;
                j = j-1;
                 plot(i,j,'*');
            elseif(v(i-1,j) == min(min(v(i-1,j-1), v(i,j-1)), v(i-1,j)))
                Path(1,k) = str1(i); 
                Path(2,k) = ' ';
                Path(3,k) = '_';
                i = i-1;
                 plot(i,j,'#');
            elseif(v(i,j-1) == min(min(v(i-1,j-1), v(i,j-1)), v(i-1,j)))
                Path(1,k) = '_'; 
                Path(2,k) = ' ';
                Path(3,k) = str2(j);
                j = j-1;
                 plot(i,j,'-');
            end
        elseif(i==1)
            Path(1,k) = '_';
            Path(2,k) = ' ';
            Path(3,k) = str2(j);
            j = j-1;
             plot(i,j,'+');
        elseif(j==1)
            Path(1,k) = str1(i); 
            Path(2,k) = ' ';
            Path(3,k) = '_';
            i = i-1;
             plot(i,j,'/');
        end
    end
end
hold off;
Path = Path(:,end-1:-1:1)

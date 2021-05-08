fid = fopen('input.txt', 'r');
n1 = fgets(fid);
n = str2num(n1);
A = [];
B = [];
for i = 1 : n
    a = fgets(fid);
    b = regexp(a, ' ', 'split' );
    x = str2double(b(1));
    y = str2double(b(2));
    if(strcmp(b(3), 'B') == 1)
        B = [B; x y];
    elseif(strcmp(b(3), 'A') == 1)
        A = [A; x y];
    end 
end

w = [1;1;0];
r = 0.7;

Y = [];
nl = length(Y);
while(n1 ~= 0)
   
    na = length(A);
    sum = [0 0 0];
    for i = 1 : na
        v = (-1) * [A(i*2-1) A(i*2) 1] * w;
        if(v >= 0)
            Y = [Y; A(i*2-1) A(i*2) 1];
            s1 = (-1) * [A(i*2-1) A(i*2) 1];
            sum = sum + s1;
        end        
    end
    
    nb = length(B);
    for i = 1 : nb
        v = (1) * [B(i*2-1) B(i*2) 1] * w;
        if(v >= 0)
            Y = [Y; B(i*2-1) B(i*2) 1];
            s1 = (1) * [B(i*2-1) B(i*2) 1];
            sum = sum + s1;
        end        
    end
        
    ny = length(Y);
    transpose(w)
    sum
    w = transpose(w) - r * sum;
    w = transpose(w);
    
  nl = length(Y);  
  errcount = nl
end

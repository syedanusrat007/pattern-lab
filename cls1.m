
for i= 1:100
    sum=0;
    for j = 1:i-1
        if (mod(i,j)==0)
            sum=sum+j;
             
        end
    end
    if (sum==i)
       disp(sum);
    end
end

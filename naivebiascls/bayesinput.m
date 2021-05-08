FID = fopen('in.txt','r');
sentence = fgets(FID);

test = str2num(fgets(FID));

for i=1:test
    s = fgets(FID);
    type = cellstr(fgets(FID));
   
    ss= regexp(s,' ','split');
  ss
end



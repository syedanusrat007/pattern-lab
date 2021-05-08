


value=[]

fid=fopen('perceptron.txt');
tline = fgetl(fid);
tlines = cell(0,1);


while ischar(tline)
    tlines{end+1,1} = tline;
    
    tline = fgetl(fid);
  
    
end


  value=[tlines]
fclose(fid);

p=.7
w=[1 1 0]
wT= transpose(w)
value3=[]

C = cellstr(value)

%value4=
%A_cell = cellstr(str2num(value));
%value3=[cellfun(@str2num,value(1:2),'un',0).']






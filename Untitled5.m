readImage = imread('1.png');
[x,y,z]= size(readImage);
A=[];
A=reshape(readImage,[x*y,z]);
csvwrite('E:\MIST\L-4 T-2\CSE-444 pattern sessional\Data\dataset.csv',A);
A=[];
readImage = imread('ColorMacro.jpg');
[x,y,z]= size(readImage);
A=reshape(readImage,[x*y,z]);
csvwrite('ColorMacro.csv',A);


B=[];
readImage = imread('colorblind.jpg');
[x,y,z]= size(readImage);
B=reshape(readImage,[x*y,z]);
csvwrite('colorblind.csv',B);


C=[];
readImage = imread('fabric.png');
[x,y,z]= size(readImage);
C=reshape(readImage,[x*y,z]);
csvwrite('fabric.csv',C);

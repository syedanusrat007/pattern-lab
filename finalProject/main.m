clear;

X=[];

%Number of clusters

K = 3; % number of clusters

readImage = imread('ColorMacro.jpg');
[x,y,z]= size(readImage); 
A=[];
A=reshape(readImage,[x*y,z]);

%X=shuffle_row(A);

%csvwrite('data.csv',A);
X=A;
centroids=[];
max_iterations = 10;
centroids = kMeansInitCentroids(X, K);

for i=1:max_iterations
  indices = findClosestCentroids(X, centroids);
  centroids = computeCentroids(X, indices, K);
end

indices    % kon data point ta kon cluster e portese
centroids  % oi cluster er certer point er value koto

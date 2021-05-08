function [I]=shuffle_row(A)

v = [1 2 1
4 5 4
4 8 6
5 10 7
125 130 127;
140 138 135;
112 141 120;
2 4 6;
6 4 8;
8 1 7;
110 115 120;
130 133 125;
140 130 135];

%b = v(randperm(size(v,1)),:);
%b
I=A(randperm(size(A,1)),randperm(size(A,2)),:);
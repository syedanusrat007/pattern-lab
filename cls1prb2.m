 for i= 1:5
     for j = 1:i
         fprintf('*');
     end
      fprintf('\n');
 end
 
 x1=1;
 y1=1.5;
 plot(x1,y1,'*');
 x2=1.1;
 y2=1.4;
 plot(x1,y1,'*',x2,y2,'*');
 
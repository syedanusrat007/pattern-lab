fid=fopen('in.txt','r');
t=fgets(fid);
s=regexp(t,' ','split');

x=[];
for(i=1:length(s)-1)
    x=[x s(i)];
end

    spam=[];
    notspam=[];
    all=[];
    n=str2num(fgets(fid));
    count=0;
    for(i=1:n)
        
        t=fgets(fid);
         s=regexp(t,' ','split');
            for(i=1:length(s)-1)
                all=[all s(i)];
            end
        t1=fgets(fid);
        s=regexp(t1,' ','split');
        if(strcmp(s(1),'Spam'))
            s=regexp(t,' ','split');
            for(i=1:length(s)-1)
                spam=[spam s(i)];
            end
        else  s=regexp(t,' ','split');
                    for(i=1:length(s)-1)
                notspam=[notspam s(i)];
            end
                    
            
        end
        
        
    end
    spam;
    notspam;
    all;
   uniall=unique(all);
   
   
   l=length(uniall)
   l2=length(notspam)
   
  l1=length(spam)
  %prob of spam
  c=0;
  p=1;
  length(x);
  for(i=1:length(x))
     
      for(j=1:length(spam))
          if(strcmp(x(i),spam(j)))
              c=c+1;
          end
      end
      c=c+1;
      l1=length(spam)+l;
      
      ans=c/l1;
      p=p*ans;
      c=0;
      
          
         
  end
 
  
  %prob of not  spam
  c1=0;
  p1=1;
  length(x);
  for(i=1:length(x))
     
      for(j=1:length(notspam))
          if(strcmp(x(i),notspam(j)))
              c1=c1+1;
          end
      end
      c1=c1+1;
      l1=length(notspam)+l;
      
      ans1=c1/l1;
      p1=p1*ans1;
      c1=0;
      
          
         
  end
  
   p=p*(4/6)
  p1=p1*(2/6)
 
  if(p>p1)
    fprintf('the text belongs to spam class');
else
    
     fprintf('the text belongs to not spam class');
     
end
    
 
  
          
      
  
        
   




        
        
        
    



    

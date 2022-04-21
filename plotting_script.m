%set(0,'DefaultFigureWindowStyle','docked')
x = 0:.01:1;
for j = 1:6
   up = upwind_FD(0,1,.01,.005,.1*j,1); 
   subplot(2,2,1);
   plot(x,up); hold on;
   xlabel('x'); ylabel('u(x,t)');title('upwind');
   
   lw = lw_FD(0,1,.01,.005,.1*j,1); 
   subplot(2,2,2);
   plot(x,lw); hold on;
   xlabel('x'); ylabel('u(x,t)');title('lax wendroff');

   lf = lf_FD(0,1,.01,.005,.1*j,1); 
   subplot(2,2,3);
   plot(x,lf); hold on;
   xlabel('x'); ylabel('u(x,t)');title('lax friedrichs');

   beam = beamwarm_FD(0,1,.01,.005,.1*j,1); 
   subplot(2,2,4);
   plot(x,beam); hold on;
   xlabel('x'); ylabel('u(x,t)');title('beam warming');
end
    
    

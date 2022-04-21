function [u] = advection_lf(a,b,dx,dt,max_t,c)
    space = (a:dx:b);
    time = (0:dt:max_t);
    nu = (c*dt)/dx;
    
    %smooth initial conditions
    u_0 = @(x)(exp(-100*(0.3-x)^2));

    uprev = arrayfun(u_0, space);
    u = 0*uprev;
    
    for n=1:length(time)  
        for j=2:length(u)-1
            u(j) = 0.5*(uprev(j+1)+uprev(j-1))-0.5*nu*(uprev(j+1)-uprev(j-1));
            u(1) = uprev(end);
            u(end) = uprev(1);
        end 
        uprev = u;
    end
end

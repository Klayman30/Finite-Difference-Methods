function [u] = advection_beamwarm(a,b,dx,dt,max_t,c)
    space = (a:dx:b);
    time = (0:dt:max_t);
    nu = (c*dt)/dx;
    
    %smooth initial conditions
    u_0 = @(x)(exp(-100*(0.3-x)^2));

    uprev = arrayfun(u_0, space);
    u = 0*uprev;
    
    for n=1:length(time)
        for j=3:length(u)
            if c > 0
                u(1) = uprev(end);
                u(2) = uprev(2) -  0.5*nu*(3*uprev(2)-4*uprev(1)+uprev(end)) + 0.5*nu*nu*(uprev(2)-2*uprev(1)+uprev(end));
                u(j) = uprev(j) - 0.5*nu*(3*uprev(j)-4*uprev(j-1)+uprev(j-2)) + 0.5*nu*nu*(uprev(j)-2*uprev(j-1)+uprev(j-2));
                u(end-1) = uprev(end-1) - 0.5*nu*(3*uprev(end-1)-4*uprev(end-2)+uprev(end-3)) + 0.5*nu*nu*(uprev(end-1)-2*uprev(end-2)+uprev(end-3));
                u(end) = uprev(1);
            else
                u(1) = uprev(end);
                u(2) = uprev(2) + 0.5*nu*(3*uprev(2)-4*uprev(3)+uprev(4)) +0.5*nu*nu*(uprev(2)-2*uprev(3)+uprev(4));
                u(j) = uprev(j) + 0.5*nu*(3*uprev(j)-4*uprev(j+1)+uprev(j+2)) +0.5*nu*nu*(uprev(j)-2*uprev(j+1)+uprev(j+2));
                u(end-1) = uprev(end-1) + 0.5*nu*(3*uprev(end-1)-4*uprev(end)+uprev(1)) +0.5*nu*nu*(uprev(end-1)-2*uprev(end)+uprev(1));
                u(end) = uprev(1);
            end
            
        end 
        uprev = u;
    end
end


    xy = load('input.txt');
    n = size(xy); n = n(1);
    q = 2; th = 1.4;
    order = [7, 3, 1, 5, 9, 6, 8, 4, 2, 10, 15, 13, 14, 11, 12];
    cluster = zeros(1,n);
    cluster(1) = 1;
    m = 1;
    for i=2:n
        curx = xy(order(i), 1);
        cury = xy(order(i), 2);
        dmin = 1000; c = 0;
        for j=1:m
            sumx = 0; sumy = 0; cnt = 0;
            for k=1:n
                if cluster(k) == j
                    cnt = cnt + 1;
                    sumx = sumx + xy(order(k), 1);
                    sumy = sumy + xy(order(k), 2);
                end
            end
            avgx = sumx / cnt; avgy = sumy / cnt;
            d = sqrt((curx-avgx)*(curx-avgx) + (cury-avgy)*(cury-avgy));
            if d <= dmin
                dmin = d; c = j;
            end
        end
        if dmin > th && m < q
            m = m + 1;
            cluster(i) = m;
        else
            cluster(i) = c;
        end
    end
    order
    cluster

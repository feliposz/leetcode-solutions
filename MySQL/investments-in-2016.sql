select round(sum(tiv_2016), 2) as tiv_2016 
from insurance i
where tiv_2015 in ( select tiv_2015 from insurance i2 where i2.pid <> i.pid )
and (lat, lon) not in ( select lat, lon from insurance i2 where i2.pid <> i.pid )
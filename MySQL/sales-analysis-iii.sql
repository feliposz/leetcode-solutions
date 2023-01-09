# Write your MySQL query statement below
select product_id, product_name
from Product p
where p.product_id in 
    ( select product_id 
        from Sales s
        where s.sale_date between '2019-01-01' and '2019-03-31' )
and p.product_id not in 
    ( select product_id 
        from Sales s
        where s.sale_date not between '2019-01-01' and '2019-03-31' )

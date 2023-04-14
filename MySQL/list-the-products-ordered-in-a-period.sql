# Write your MySQL query statement below
select p.product_name, sum(o.unit) unit
from orders o
join products p
on o.product_id = p.product_id
where month(o.order_date) = 2
group by p.product_name
having sum(o.unit) >= 100
# Write your MySQL query statement below
select customer_number 
from Orders
group by customer_number
having count(order_number) = (
        select max(cnt) as max_cnt
        from (select count(order_number) cnt
                from Orders
                group by customer_number) x
    )
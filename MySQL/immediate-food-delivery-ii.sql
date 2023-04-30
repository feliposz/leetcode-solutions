with customer_first as (
    select customer_id,
        min(order_date) as first_order,
        min(if(order_date=customer_pref_delivery_date,order_date,null)) as first_immediate_order
    from delivery
    group by customer_id
)
select round(count(if(first_order=first_immediate_order,1,null)) / count(*) * 100, 2) as immediate_percentage
from customer_first
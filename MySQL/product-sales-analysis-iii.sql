select product_id, first_year, quantity, price
from (
select product_id, year, quantity, price, min(year) over (partition by product_id) as first_year
from sales
join product
using (product_id)
) x
where year = first_year
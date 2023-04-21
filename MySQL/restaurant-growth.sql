select visited_on, amount, average_amount
from (
  select visited_on, 
    count(*) over (order by visited_on rows between 6 preceding and current row) days,
    sum(amount) over (order by visited_on rows between 6 preceding and current row) amount,
    round(avg(amount) over (order by visited_on rows between 6 preceding and current row), 2) average_amount
  from (
    select visited_on, sum(amount) amount from customer group by visited_on
  ) total_amount
  group by visited_on
) x
where days > 6
order by 1
# Write your MySQL query statement below
select person_name
from (
  select person_name, acc_weight, lead(acc_weight) over () next_acc_weight
  from (
      select person_name, 
        sum(weight) over (
          order by turn 
          range between unbounded preceding and current row
        ) acc_weight
      from queue
      order by turn
    ) x
  ) y
where acc_weight <= 1000
and (next_acc_weight is null or next_acc_weight > 1000)

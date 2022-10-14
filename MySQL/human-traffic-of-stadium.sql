# Write your MySQL query statement below
select id, visit_date, people
from (
select id, 
    visit_date, 
    people,
    LAG(id) over (order by id) prev_id,
    LAG(id,2) over (order by id) prev2_id,
    LEAD(id) over (order by id) next_id,
    LEAD(id,2) over (order by id) next2_id
from Stadium
where people >= 100
) x
where (id-2 = prev2_id and id-1 = prev_id) or
      (id+1 = next_id and id+2 = next2_id) or
      (id-1 = prev_id and id+1 = next_id)
order by visit_date
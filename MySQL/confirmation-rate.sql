# Write your MySQL query statement below
select s.user_id, round(coalesce(sum(case when c.action = 'confirmed' then 1 else 0 end), 0) / count(s.user_id), 2) confirmation_rate
from signups s
left join confirmations c
on c.user_id = s.user_id
group by s.user_id
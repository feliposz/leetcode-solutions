# Write your MySQL query statement below
select user_id, max(time_stamp) last_stamp          
from Logins
where time_stamp >= '2020-01-01' and time_stamp < '2021-01-01'
group by user_id
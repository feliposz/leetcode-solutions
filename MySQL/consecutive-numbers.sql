# Write your MySQL query statement below
select distinct a.num as ConsecutiveNums
from Logs a 
join Logs b on a.id = b.id + 1 and a.num = b.num
join Logs c on b.id = c.id + 1 and b.num = c.num
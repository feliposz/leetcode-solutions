# Write your MySQL query statement below
select a.id
from Weather a join Weather b
on a.recordDate = date_add(b.recordDate, interval 1 day)
where a.temperature > b.temperature